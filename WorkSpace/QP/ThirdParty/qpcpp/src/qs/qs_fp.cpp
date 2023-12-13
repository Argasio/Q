//$file${src::qs::qs_fp.cpp} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
//
// Model: qpcpp.qm
// File:  ${src::qs::qs_fp.cpp}
//
// This code has been generated by QM 5.3.0 <www.state-machine.com/qm>.
// DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
//
// This code is covered by the following QP license:
// License #    : LicenseRef-QL-dual
// Issued to    : Any user of the QP/C++ real-time embedded framework
// Framework(s) : qpcpp
// Support ends : 2024-12-31
// License scope:
//
// Copyright (C) 2005 Quantum Leaps, LLC <state-machine.com>.
//
//                    Q u a n t u m  L e a P s
//                    ------------------------
//                    Modern Embedded Software
//
// SPDX-License-Identifier: GPL-3.0-or-later OR LicenseRef-QL-commercial
//
// This software is dual-licensed under the terms of the open source GNU
// General Public License version 3 (or any later version), or alternatively,
// under the terms of one of the closed source Quantum Leaps commercial
// licenses.
//
// The terms of the open source GNU General Public License version 3
// can be found at: <www.gnu.org/licenses/gpl-3.0>
//
// The terms of the closed source Quantum Leaps commercial licenses
// can be found at: <www.state-machine.com/licensing>
//
// Redistributions in source code must retain this top-level comment block.
// Plagiarizing this software to sidestep the license obligations is illegal.
//
// Contact information:
// <www.state-machine.com/licensing>
// <info@state-machine.com>
//
//$endhead${src::qs::qs_fp.cpp} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#define QP_IMPL           // this is QF/QK implementation
#include "qs_port.hpp"    // QS port
#include "qs_pkg.hpp"     // QS package-scope internal interface

//============================================================================
//! @cond INTERNAL

namespace QP {
namespace QS {

//${QS::QS-tx-fp::f32_fmt_} ..................................................
void f32_fmt_(
    std::uint8_t format,
    float32_t f) noexcept
{
    union F32Rep {
        float32_t      f;
        std::uint32_t  u;
    } fu32; // the internal binary representation
    std::uint8_t chksum  = priv_.chksum;  // put in a temporary (register)
    std::uint8_t * const buf = priv_.buf; // put in a temporary (register)
    QSCtr   head    = priv_.head;    // put in a temporary (register)
    QSCtr const end = priv_.end;     // put in a temporary (register)

    fu32.f = f; // assign the binary representation

    priv_.used = (priv_.used + 5U); // 5 bytes about to be added
    QS_INSERT_ESC_BYTE_(format)  // insert the format byte

    for (std::uint_fast8_t i = 4U; i != 0U; --i) {
        format = static_cast<std::uint8_t>(fu32.u);
        QS_INSERT_ESC_BYTE_(format)
        fu32.u >>= 8U;
    }

    priv_.head   = head;    // save the head
    priv_.chksum = chksum;  // save the checksum
}

//${QS::QS-tx-fp::f64_fmt_} ..................................................
void f64_fmt_(
    std::uint8_t format,
    float64_t d) noexcept
{
    union F64Rep {
        float64_t     d;
        std::uint32_t u[2];
    } fu64;  // the internal binary representation
    std::uint8_t chksum  = priv_.chksum;
    std::uint8_t * const buf = priv_.buf;
    QSCtr   head    = priv_.head;
    QSCtr const end = priv_.end;
    std::uint32_t i;
    // static constant untion to detect endianness of the machine
    static union U32Rep {
        std::uint32_t u32;
        std::uint8_t  u8;
    } const endian = { 1U };

    fu64.d = d;  // assign the binary representation

    // is this a big-endian machine?
    if (endian.u8 == 0U) {
        // swap fu64.u[0] <-> fu64.u[1]...
        i = fu64.u[0];
        fu64.u[0] = fu64.u[1];
        fu64.u[1] = i;
    }

    priv_.used = (priv_.used + 9U); // 9 bytes about to be added
    QS_INSERT_ESC_BYTE_(format)  // insert the format byte

    // output 4 bytes from fu64.u[0]...
    for (i = 4U; i != 0U; --i) {
        QS_INSERT_ESC_BYTE_(static_cast<std::uint8_t>(fu64.u[0]))
        fu64.u[0] >>= 8U;
    }

    // output 4 bytes from fu64.u[1]...
    for (i = 4U; i != 0U; --i) {
        QS_INSERT_ESC_BYTE_(static_cast<std::uint8_t>(fu64.u[1]))
        fu64.u[1] >>= 8U;
    }

    priv_.head   = head;   // update the head
    priv_.chksum = chksum; // update the checksum
}

} // namespace QS
} // namespace QP

//! @endcond