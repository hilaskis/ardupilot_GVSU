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
    // put your initialisation code here
    // this will be called once at start-up
}
#endif

#ifdef USERHOOK_FASTLOOP
void Copter::userhook_FastLoop()
{
    // put your 100Hz code here
    //copter.gcs_send_message(MSG_PHASE_OFFSET);

    const Compass* comp = copter.ahrs.get_compass();
    float heading = comp->calculate_heading(copter.ahrs.get_dcm_matrix());
    //gcs_send_text_P(SEVERITY_HIGH, PSTR("In the user fast loop"));

}
#endif

#ifdef USERHOOK_50HZLOOP
void Copter::userhook_50Hz()
{
    // put your 50Hz code here
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
    // put your 3.3Hz code here
}
#endif

#ifdef USERHOOK_SUPERSLOWLOOP
void Copter::userhook_SuperSlowLoop()
{
    // put your 1Hz code here
    float testBear (180.0);
    float testMag (25.0);
	
	// Call the function to log the bearing information.
    Log_Write_Bearing(testBear, testMag);

}
#endif
