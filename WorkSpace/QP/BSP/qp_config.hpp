/*
 * qp_config.hpp
 *
 *  Created on: Dec 1, 2023
 *      Author: A409296
 */


//============================================================================
// QP configuration file example
// Last updated for version: 7.3.0
// Last updated on: 2023-09-02
//
//                   Q u a n t u m  L e a P s
//                   ------------------------
//                   Modern Embedded Software
//
// Copyright (C) 2005 Quantum Leaps, LLC. All rights reserved.
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
// <www.state-machine.com>
// <info@state-machine.com>
//============================================================================
#ifndef QP_CONFIG_HPP_
#define QP_CONFIG_HPP_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


#define configMAX_PRIORITIES 5
// NOTE:
// The QP configuration takes effect only when the macro QP_CONFIG
// is defined on the command-line to the compiler for all QP source files.

#define QF_MAX_ACTIVE   configMAX_PRIORITIES
namespace BSP{
constexpr std::uint32_t TICKS_PER_SEC {1000U};
}
#define Q_SPY


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif // QP_CONFIG_HPP_


