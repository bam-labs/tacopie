// MIT License
//
// Copyright (c) 2016-2017 Simon Ninon <simon.ninon@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include <cstdint>
#include <stdexcept>
#include <string>

namespace tacopie {

class tacopie_error : public std::runtime_error {
public:
  //! ctor & dtor
  tacopie_error(const std::string& what, const std::string& file, std::size_t line);
  ~tacopie_error(void) = default;

  //! copy ctor & assignment operator
  tacopie_error(const tacopie_error&) = default;
  tacopie_error& operator=(const tacopie_error&) = default;

public:
  //! get location of the error
  const std::string& get_file(void) const;
  std::size_t get_line(void) const;

private:
  //! location of the error
  std::string m_file;
  std::size_t m_line;
};

} //! tacopie

//! macro for convenience
#define __TACOPIE_THROW(level, what)                          \
  {                                                           \
    __TACOPIE_LOG(level, (what));                             \
    throw tacopie::tacopie_error((what), __FILE__, __LINE__); \
  }
