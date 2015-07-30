/// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-

#include "Copter.h"

// Function that is responsible for logging the absolute bearing message.
void Copter::Log_Write_Bearing(float newAbs, float newMag)
{
    struct log_BEARING pkt = {
        LOG_PACKET_HEADER_INIT(LOG_ABS_BEAR_MSG),
        absBearing  : newAbs,
        mag         : newMag,
    };

    DataFlash.WriteBlock(&pkt, sizeof(pkt));
}

#ifdef USERHOOK_INIT
void Copter::userhook_init()
{
}
#endif

#ifdef USERHOOK_FASTLOOP
void Copter::userhook_FastLoop()
{

}
#endif

#ifdef USERHOOK_50HZLOOP
void Copter::userhook_50Hz()
{

}
#endif

#ifdef USERHOOK_MEDIUMLOOP
void Copter::userhook_MediumLoop()
{
    // put your 10Hz code here
}
#endif

#ifdef USERHOOK_SLOWLOOP
void Copter::userhook_SlowLoop()
{


}
#endif

#ifdef USERHOOK_SUPERSLOWLOOP
//1Hz loop code
void Copter::userhook_SuperSlowLoop()
{
    // Send a heartbeat packet over the serial connection with the pi.
    // This was added to minimize an issue where the firmware was sometimes
    // not detecting the connection to the pi
    copter.gcs[2].send_pi_heartbeat();
    Log_Write_Bearing(testBear, testMag);

}
#endif
