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

// IWYU pragma: begin_exports
#include <units/quantity.h>
#include <units/reference.h>
#include <units/symbol_text.h>
// IWYU pragma: end_exports

#include <units/isq/si/prefixes.h>

namespace units {

struct radian : named_unit<radian, "rad", isq::si::prefix> {};

template<Unit U = radian>
struct dim_angle : base_dimension<"A", U> {};

template<typename T>
concept Angle = QuantityOfT<T, dim_angle>;

template<UnitOf<dim_angle<>> U, Representation Rep = double>
using angle = quantity<dim_angle<>, U, Rep>;

#ifndef UNITS_NO_LITERALS

inline namespace literals {

// rad
constexpr auto operator"" _q_rad(unsigned long long l)
{
  gsl_ExpectsAudit(std::in_range<std::int64_t>(l));
  return angle<radian, std::int64_t>(static_cast<std::int64_t>(l));
}
constexpr auto operator"" _q_rad(long double l) { return angle<radian, long double>(l); }

}  // namespace literals

#endif  // UNITS_NO_LITERALS

#ifndef UNITS_NO_REFERENCES

namespace angle_references {

inline constexpr auto rad = reference<dim_angle<>, radian>{};

}  // namespace angle_references

namespace references {

using namespace angle_references;

}  // namespace references

#endif  // UNITS_NO_REFERENCES

}  // namespace units
