/*
 * Qp_Tracer.c
 *
 *  Created on: Dec 13, 2023
 *      Author: A409296
 */

#include "../COMPONENTS/Qp_Tracer.h"

#include <cstdio>


//Trace
void vTrace(unsigned int user, const char* string, va_list args)
{
    char vsbuf[TRACE_BUFFER_SIZE];
    char *p = vsbuf;
    vsnprintf (p, TRACE_BUFFER_SIZE, string, args);

    // Send String using QSPY User message #1 for driver traces
    QS_BEGIN_ID(QP::QS_USER + user, 0U)
       QS_STR(p);
    QS_END()
}

void InterfaceTrace(const char* string, ...)
{
    // Trace if filter allows
    char vsbuf[TRACE_BUFFER_SIZE];

    va_list args;
    va_start(args, string);
    vsnprintf(vsbuf, TRACE_BUFFER_SIZE, string, args);
    va_end(args);

    // Send String using QSPY User level 0 interface layer message
    QS_BEGIN_ID(QP::QS_USER, 0U)
    QS_STR(vsbuf);
    QS_END()
}

void InterfaceTraceModule(int module, const char* string, ...)
{
    // Trace if filter allows
    char vsbuf[TRACE_BUFFER_SIZE];


    va_list args;
    va_start(args, string);
    vsnprintf(vsbuf, TRACE_BUFFER_SIZE, string, args);
    va_end(args);

    // Send String using QSPY User level 0 interface layer message
    QS_BEGIN_ID(module, 0U)
    QS_STR(vsbuf);
    QS_END()
}
