/*
 * BSP_DebugTrace.h
 *	@brief Grups project specific trace macros and joind various tracing methods used in the project
 *  Created on: Dec 14, 2023
 *      Author: A409296
 */

#ifndef BSP_DEBUGTRACE_H_
#define BSP_DEBUGTRACE_H_
#include "BSP_ConditionalCompile.h"
#include "Qp_Tracer.h"
#include "TRACER.h"


#if defined(Q_SPY) && (USE_TRACER)
#if TRACER_USE_QSPY
#	define TRACE(format, ...)  					TracerPrint( format, ##__VA_ARGS__)
#	define TRACE_MODULE(module, format, ...)    TracerPrintWithLabel((module), format, ##__VA_ARGS__)
#else
#	define TRACE(format, ...) \
       do{\
		   InterfaceTrace(format, ##__VA_ARGS__);\
		   TracerPrint( format, ##__VA_ARGS__);\
       }while(0)

#	define TRACE_MODULE(module, format, ...)  \
       do{\
		   InterfaceTraceModule((QS_MODULES_START+module), format, ##__VA_ARGS__);\
		   TracerPrintWithLabel((module), format, ##__VA_ARGS__);\
       }while(0)
#endif

#elif defined(Q_SPY)
/// @def Utility for sending debug trace messages anywhere in the application
#	define TRACE(format, ...) InterfaceTrace(format, ##__VA_ARGS__)
#	define TRACE_MODULE(module, format, ...)  InterfaceTraceModule(QS_MODULES_START+1+module, format, ##__VA_ARGS__)

#elif (USE_TRACER)

#	define TRACE(format, ...) InterfaceTrace(format, ##__VA_ARGS__)
#	define TRACE_MODULE(module, format, ...)  TracerPrintWithLabel(Modules_NamesTable[module], format, ##__VA_ARGS__)

#else  // Q_SPY not defined

/// @def Utility for sending debug trace messages in HSMs and AOs
#	define TRACE(format, ...) ((void)0)
/// @def Utility for sending debug trace messages from module
#	define TRACE_MODULE(module, format, ...) ((void)0)

#endif


#define TRACE_BUTTON_BLINK(format, ...) TRACE_MODULE(MODULE_BUTTON_BLINK,format,  ##__VA_ARGS__)


#endif /* BSP_DEBUGTRACE_H_ */
