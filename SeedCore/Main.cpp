#include "Common.h"
void initialize();

void main()
{
    initialize();
    while (!halt)
    {
        Tick();
    }
}

void initialize()
{
    // Init Timing
    g_Timer.startTimer();
}

void Tick()
{
    
}