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
#include <units/isq/dimensions/angular_velocity.h>
#include <units/quantity.h>
#include <units/symbol_text.h>
// IWYU pragma: end_exports

#include <units/generic/angle.h>
#include <units/isq/si/time.h>
#include <units/unit.h>

namespace units::isq::si {

struct radian_per_second : named_unit<radian_per_second, basic_symbol_text{"ω", "w"}, no_prefix> {};

struct dim_angular_velocity :
    isq::dim_angular_velocity<dim_angular_velocity, radian_per_second, dim_angle<>, dim_time> {};

template<UnitOf<dim_angular_velocity> U, Representation Rep = double>
using angular_velocity = quantity<dim_angular_velocity, U, Rep>;

#ifndef UNITS_NO_LITERALS

inline namespace literals {

// rad / s
constexpr auto operator"" _q_rad_per_s(unsigned long long l)
{
  gsl_ExpectsAudit(std::in_range<std::int64_t>(l));
  return angular_velocity<radian_per_second, std::int64_t>(static_cast<std::int64_t>(l));
}
constexpr auto operator"" _q_rad_per_s(long double l) { return angular_velocity<radian_per_second, long double>(l); }

}  // namespace literals

#endif  // UNITS_NO_LITERALS

}  // namespace units::isq::si

#ifndef UNITS_NO_ALIASES

namespace units::aliases::isq::si::inline angular_velocity {

template<Representation Rep = double>
using rad_per_s = units::isq::si::angular_velocity<units::isq::si::radian_per_second, Rep>;

}  // namespace units::aliases::isq::si::inline angular_velocity

#endif  // UNITS_NO_ALIASES
