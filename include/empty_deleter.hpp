// Copyright 2020 Your Name <your_email>


#ifndef BOOST_LOG_UTILITY_EMPTY_DELETER_HPP_INCLUDED_
#define BOOST_LOG_UTILITY_EMPTY_DELETER_HPP_INCLUDED_
#include <boost/log/detail/config.hpp>
#ifdef BOOST_LOG_HAS_PRAGMA_ONCE
#pragma once
#endif
namespace boost {
BOOST_LOG_OPEN_NAMESPACE
//! A function object that does nothing and can be used as an empty deleter for \c shared_ptr
struct empty_deleter
{
  //! Function object result type
  typedef void result_type;
  /*!
   * Does nothing
   */
  void operator() (const volatile void*) const {}
};
BOOST_LOG_CLOSE_NAMESPACE // namespace log
} // namespace boost
#endif // INCLUDE_HEADER_HPP_
