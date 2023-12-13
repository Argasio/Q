/*
 * Signals.hpp
 *
 *  Created on: Dec 13, 2023
 *      Author: A409296
 */

#ifndef SIGNALS_HPP_
#define SIGNALS_HPP_

#include "qpcpp.hpp"             // QP/C++ real-time embedded framework
namespace APP
{
enum Signals :QP::QSignal
{
    DUMMY_SIG = QP::Q_USER_SIG,



    MAX_PUB_SIG,  // the last published signal

	TIMEOUT_SIG,
    MAX_SIG       // the last signal
};

}

#endif /* SIGNALS_HPP_ */
