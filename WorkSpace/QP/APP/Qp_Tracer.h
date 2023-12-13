/*
 * Qp_Tracer.h
 *
 *  Created on: Dec 13, 2023
 *      Author: A409296
 */

#ifndef QP_TRACER_H_
#define QP_TRACER_H_
#include "BSP_QP.hpp"
#include "Modules.h"
#include <cstdarg> /* open argument list support */

#define TRACE_BUFFER_SIZE 100

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


#ifdef Q_SPY
/// @def Utility for sending debug trace messages anywhere in the application
#define TRACE(format, ...) InterfaceTrace(format, ##__VA_ARGS__)

#define TRACE_MODULE(module, format, ...)  InterfaceTraceModule(QS_MODULES_START+1+module, format, ##__VA_ARGS__)
#define TRACE_BUTTON_BLINK(format, ...) TRACE_MODULE(MODULE_BUTTON_BLINK,format,  ##__VA_ARGS__)
/// @def Utility for sending debug trace messages from private methods without
/// ME parameter
/// @deprecated No longer needed since filter has gone away
#define TRACE_THIS(format, ...) InterfaceTrace(format, ##__VA_ARGS__)
#else  // Q_SPY not defined

/// @def Utility for sending debug trace messages in HSMs and AOs
#define TRACE(format, ...) ((void)0)
/// @def Utility for sending debug trace messages from private methods without
/// ME parameter
/// @deprecated No longer needed since filter has gone away
#define TRACE_THIS(format, ...) ((void)0)

#endif

void vTrace(unsigned int user, const char* string, va_list args);
void InterfaceTrace(const char* string, ...);
void InterfaceTraceModule(int module, const char* string, ...);



#ifdef __cplusplus
 }
#endif /* __cplusplus */


#endif /* QP_TRACER_H_ */
