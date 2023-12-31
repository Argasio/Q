//$file${.::AO_ButtonPressHandler.hpp} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
//
// Model: ButtonPressHandler.qm
// File:  ${.::AO_ButtonPressHandler.hpp}
//
// This code has been generated by QM 6.1.0 <www.state-machine.com/qm>.
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
//$endhead${.::AO_ButtonPressHandler.hpp} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#ifndef AO_BUTTONHANDLER_H
#define AO_BUTTONHANDLER_H
#include "qpcpp.hpp" // QP/C++ framework API
#include "Signals.hpp"
#include "BSP_QP.hpp"
#include "../../COMPONENTS/LedHandler.hpp"

enum AO_ButtonPressHandlerEvt_t
{
    ShortPress,
    LongPress,

};
// Callbacks
void AO_ButtonPressHandlerCallback(AO_ButtonPressHandlerEvt_t evt, QP::QActive* caller);
///@brief init struct for button blink AO
typedef struct ButtonPressHandlerInit_t
{
    MCAL::iGpio* pin;
}ButtonPressHandlerInit_t;
// ask QM to declare the Blinky class ----------------------------------------
//$declare${AOs::ButtonPressHandler} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
namespace AO {

//${AOs::ButtonPressHandler} .................................................
class ButtonPressHandler : public QP::QActive {
private:
    QP::QTimeEvt m_timeEvt;

public:
    ButtonPressHandlerInit_t init;

public:
    ButtonPressHandler(ButtonPressHandlerInit_t _init);
    void ButtonEvent(
        QP::QActive* sender,
        std::uint8_t level);

protected:
    Q_STATE_DECL(initial);
    Q_STATE_DECL(buttonSensitiveState);
    Q_STATE_DECL(idle);
    Q_STATE_DECL(firstPress);
    Q_STATE_DECL(longPress);
}; // class ButtonPressHandler

} // namespace AO
//$enddecl${AOs::ButtonPressHandler} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


#endif // BSP_HPP
