//$file${.::AO_ButtonBlink.cpp} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
//
// Model: ButtonBlink.qm
// File:  ${.::AO_ButtonBlink.cpp}
//
// This code has been generated by QM 5.3.0 <www.state-machine.com/qm>.
// DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
//
// SPDX-License-Identifier: GPL-3.0-or-later
//
// This generated code is open source software: you can redistribute it under
// the terms of the GNU General Public License as published by the Free
// Software Foundation.
//
// This code is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// more details.
//
// NOTE:
// Alternatively, this generated code may be distributed under the terms
// of Quantum Leaps commercial licenses, which expressly supersede the GNU
// General Public License and are specifically designed for licensees
// interested in retaining the proprietary status of their code.
//
// Contact information:
// <www.state-machine.com/licensing>
// <info@state-machine.com>
//
//$endhead${.::AO_ButtonBlink.cpp} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

#include "AO_ButtonBlink.hpp"
using namespace QP;
using namespace APP;


// opaque pointer to the Blinky active object --------------------------------
//$skip${QP_VERSION} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
// Check for the minimum required QP version
#if (QP_VERSION < 730U) || (QP_VERSION != ((QP_RELEASE^4294967295U) % 0x3E8U))
#error qpcpp version 7.3.0 or higher required
#endif
//$endskip${QP_VERSION} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//$define${AOs::ButtonBlink} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

//${AOs::ButtonBlink} ........................................................

//${AOs::ButtonBlink::ButtonBlink} ...........................................
ButtonBlink::ButtonBlink(ButtonBlinkInit_t& _init)
  : QActive(Q_STATE_CAST(&ButtonBlink::initial)),
    m_timeEvt(this, TIMEOUT_SIG, 0U),
    init(_init)

{}

//${AOs::ButtonBlink::SM} ....................................................
Q_STATE_DEF(ButtonBlink, initial) {
    //${AOs::ButtonBlink::SM::initial}
    // arm the private time event to expire in 1/2s
    // and periodically every 1/2 second
    m_timeEvt.armX( BSP::TICKS_PER_SEC,
                    BSP::TICKS_PER_SEC);
    (void)e; // unused parameter

    QS_FUN_DICTIONARY(&ButtonBlink::off);
    QS_FUN_DICTIONARY(&ButtonBlink::on);

    return tran(&off);
}

//${AOs::ButtonBlink::SM::off} ...............................................
Q_STATE_DEF(ButtonBlink, off) {
    QP::QState status_;
    switch (e->sig) {
        //${AOs::ButtonBlink::SM::off}
        case Q_ENTRY_SIG: {
            init.ledHandler->LedControl(LedHandler::Colors_t::Red, 0);
            status_ = Q_RET_HANDLED;
            break;
        }
        //${AOs::ButtonBlink::SM::off::TIMEOUT}
        case TIMEOUT_SIG: {
            status_ = tran(&on);
            break;
        }
        default: {
            status_ = super(&top);
            break;
        }
    }
    return status_;
}

//${AOs::ButtonBlink::SM::on} ................................................
Q_STATE_DEF(ButtonBlink, on) {
    QP::QState status_;
    switch (e->sig) {
        //${AOs::ButtonBlink::SM::on}
        case Q_ENTRY_SIG: {
            init.ledHandler->LedControl(LedHandler::Colors_t::Red, 1);
            status_ = Q_RET_HANDLED;
            break;
        }
        //${AOs::ButtonBlink::SM::on::TIMEOUT}
        case TIMEOUT_SIG: {
            status_ = tran(&off);
            break;
        }
        default: {
            status_ = super(&top);
            break;
        }
    }
    return status_;
}
//$enddef${AOs::ButtonBlink} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

