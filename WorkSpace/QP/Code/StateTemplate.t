/*
 * StateTemplate.c
 *
 *  Created on: Nov 30, 2023
 *      Author: A409296
 */


typedef enum STATEMACHINE_StateId_t
{
	STATEMACHINE_StateId_Max,
};

typedef enum STATEMACHINE_StateOutput_t
{
	STATEMACHINE_StateOutput_Stable,
	STATEMACHINE_StateOutput_Exit,
};

typedef enum STATEMACHINE_StatePhase_t
{
	STATEMACHINE_StatePhase_Entry,
	STATEMACHINE_StatePhase_Active,
	STATEMACHINE_StatePhase_Exit,

};

typedef enum STATEMACHINE_EventId_t{
	STATEMACHINE_EventId_Entry,
	STATEMACHINE_EventId_Exit,

};

typedef struct STATEMACHINE_Event_t
{
	STATEMACHINE_EventId_t id;
}STATEMACHINE_Event_t;

typedef struct STATEMACHINE_InternalStatus_t
{
	STATEMACHINE_StateId_t currentState;
	STATEMACHINE_StateId_t nextState;
	STATEMACHINE_StatePhase_t statePhase;
}STATEMACHINE_InternalStatus_t;

STATEMACHINE_StateOutput_t STATEMACHINE_StateFun_Max(STATEMACHINE_Event_t* evt)
{
	if(STATEMACHINE_StatePhase_Entry == STATEMACHINE_InternalStatus.statePhase)
	{

	// perform entry action

	}

	// process events and perform transition actions



	return STATEMACHINE_StateOutput_Ok;
}

void STATEMACHINE_WaitForEvent(STATEMACHINE_Event_t* evt)
{
	evt = NULL;
}

STATEMACHINE_StateOutput_t STATEMACHINE_StateDispatch(STATEMACHINE_Event_t* evt)
{
	STATEMACHINE_StateOutput_t res;
	switch(STATEMACHINE_InternalStatus.currentState)
	{
		case STATEMACHINE_StateId_Max :
		{

			res = STATEMACHINE_StateFun_Max(evt);
			break;
		}
	}
}



STATEMACHINE_InternalStatus_t STATEMACHINE_InternalStatus;

STATEMACHINE_StateOutput_t STATEMACHINE_Run()
{
	STATEMACHINE_StateOutput_t res;
	STATEMACHINE_Event_t evt;
	STATEMACHINE_WaitForEvent(&evt);
	res = STATEMACHINE_StateDispatch(&evt);
	if(res == STATEMACHINE_StateOutput_Exit)
	{
		STATEMACHINE_Event_t transition;
		transition.id = STATEMACHINE_EventId_Exit;
		STATEMACHINE_StateDispatch(&transition);
		STATEMACHINE_InternalStatus.currentState = STATEMACHINE_InternalStatus.nextState;
		transition.id = STATEMACHINE_EventId_Entry;
		STATEMACHINE_StateDispatch(&transition);
	}
	else
	{

	}

}


