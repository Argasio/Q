/*
 * BSP_Tracer_Required.h
 *
 *  Created on: Dec 13, 2023
 *      Author: A409296
 */

#ifndef BSP_TRACER_REQUIRED_H_
#define BSP_TRACER_REQUIRED_H_

#include "qp_config.hpp"

//
//
//#ifdef Q_SPY
///// @def Utility for sending debug trace messages anywhere in the application
//#define TRACE(format, ...) InterfaceTrace(format, ##__VA_ARGS__)
//
///// @def Utility for sending debug trace messages from private methods without
///// ME parameter
///// @deprecated No longer needed since filter has gone away
//#define TRACE_THIS(format, ...) InterfaceTrace(format, ##__VA_ARGS__)
//
//#else  // Q_SPY not defined
//
///// @def Utility for sending debug trace messages in HSMs and AOs
//#define TRACE(format, ...) ((void)0)
///// @def Utility for sending debug trace messages from private methods without
///// ME parameter
///// @deprecated No longer needed since filter has gone away
//#define TRACE_THIS(format, ...) ((void)0)
//
//#endif

#endif /* BSP_TRACER_REQUIRED_H_ */
