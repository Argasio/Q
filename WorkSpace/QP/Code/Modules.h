/*
 * Modules.h
 *
 *  Created on: Dec 13, 2023
 *      Author: A409296
 */

#ifndef MODULES_H_
#define MODULES_H_


enum Modules
{
	MODULE_BUTTON_BLINK,

	MODULE_MAX,
};
#ifdef Q_SPY
enum AppRecords { // application-specific trace records
    QS_MODULES_START = QP::QS_USER+1,
	QS_MODULE_BUTTON_BLINK,
	QS_MODULES_END = QS_MODULES_START+MODULE_MAX,
    PAUSED_STAT,
    CONTEXT_SW,
};
#endif
#endif /* MODULES_H_ */
