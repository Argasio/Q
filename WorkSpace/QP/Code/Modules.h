/*
 * Modules.h
 *
 *  Created on: Dec 13, 2023
 *      Author: A409296
 *      @Note: this file must be included always after qpcpp.hpp
 */

#ifndef MODULES_H_
#define MODULES_H_

#define FOREACH_MODULE(MACRO) \
    MACRO(MODULE_NONE)\
    MACRO(MODULE_BUTTON_BLINK)\
    MACRO(MODULE_BUTTON_PRESS_HANDLER)\


#define ENUM_MODULE(MODULE) MODULE,
#define STR_MODULE(MODULE) [MODULE] = #MODULE,
#define QS_MODULE(MODULE) QS_##MODULE = MODULE+QS_MODULES_START,
#define QS_MODULE_REGISTER(MODULE) (QS_USR_DICTIONARY(QS_##MODULE));

enum Modules
{
    FOREACH_MODULE( ENUM_MODULE)
   MODULE_MAX
};


extern char Modules_NamesTable[MODULE_MAX][35];
//
#ifdef Q_SPY

enum AppRecords { // application-specific trace records
    QS_MODULES_START = 		 QP::QS_USER+1,
    FOREACH_MODULE(QS_MODULE)
	QS_MODULES_END = 		 QS_MODULES_START+MODULE_MAX,

};
#endif

#endif /* MODULES_H_ */
