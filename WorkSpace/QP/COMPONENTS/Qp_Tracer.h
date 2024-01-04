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



int __io_putchar(int ch);
void vTrace(unsigned int user, const char* string, va_list args);
void InterfaceTrace(const char* string, ...);
void InterfaceTraceModule(int module, const char* string, ...);



#ifdef __cplusplus
 }
#endif /* __cplusplus */


#endif /* QP_TRACER_H_ */
