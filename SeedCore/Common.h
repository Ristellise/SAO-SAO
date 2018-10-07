#pragma once
#ifndef _Commons
#include "timer.h"
CStopWatch g_Timer;
const unsigned char target_Tick = 100;
const unsigned int target_Rate = 1000 / target_Tick;
bool halt = false;
#endif // !1
