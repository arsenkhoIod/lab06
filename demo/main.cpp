#include <csignal>
#include <empty_deleter.hpp>
#include <hash_calculator.hpp>
#include <iostream>
#include <settings_of_logging.hpp>
#include <thread>
#include <vector>


void calculation(){
  BOOST_LOG_TRIVIAL(trace) << "Opened new Thread";
  hash_calculator calc;
  calc.calculate_hash();
}

void stop_calculation([[maybe_unused]] int exit_param) {
  hash_calculator::close_threads = true;
}

int main(int argc, char* argv[]) {
  std::signal(SIGINT, stop_calculation); //функция запускается при ctrl C
  //SIGINT,
  std::srand(std::time(nullptr));
  logging_init();
  unsigned number_of_threads = 0;
  try {
    manage_params(argc, argv, number_of_threads);
  } catch (const std::invalid_argument &error) {
    std::cout << error.what();
    return -1;
  }
  std::vector<std::thread> threads;
  for (unsigned i = 0; i < number_of_threads; ++i)
    threads.emplace_back(std::thread(calculation));
  for (auto& thread : threads) thread.join();
  safe_exit();
  return 0;
}