// The MIT License (MIT)
//
// Copyright (c) 2018 Mateusz Pusz
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

#include <units/base_dimensions.h>
#include <units/quantity.h>

namespace std::experimental::units {

  struct current : make_dimension_t<exp<base_dim_current, 1>> {};
  template<> struct downcasting_traits<downcast_from<current>> : downcast_to<current> {};

  template<typename T>
  concept bool Current = Quantity<T> && std::same_as<typename T::dimension, current>;

  struct ampere : unit<current> {};
  template<> struct downcasting_traits<downcast_from<ampere>> : downcast_to<ampere> {};

  inline namespace literals {

    // A
    constexpr auto operator""A(unsigned long long l) { return quantity<ampere, std::int64_t>(l); }
    constexpr auto operator""A(long double l) { return quantity<ampere, long double>(l); }

  }

}  // namespace std::experimental::units