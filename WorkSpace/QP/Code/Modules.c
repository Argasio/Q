/*
 * Modules.c
 *
 *  Created on: Dec 14, 2023
 *      Author: A409296
 */

#include "Modules.h"

char Modules_NamesTable[MODULE_MAX][35] ={
        FOREACH_MODULE(STR_MODULE)
};



