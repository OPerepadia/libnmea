#ifndef INC_NMEA_HRP_H
#define INC_NMEA_HRP_H

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <nmea.h>

typedef struct {
	nmea_s base;

	double heading;
	double roll;
	double pitch;
	double headingSD;
	double rollSD;
	double pitchSD;
	uint8_t numSat;
	uint8_t modeIndicator;
	
} nmea_hrp_s;

/* Value indexes */
#define NMEA_HRP_TIME				0
#define NMEA_HRP_DATE				1
#define NMEA_HRP_HEADING			2
#define NMEA_HRP_ROLL				3
#define NMEA_HRP_PITCH				4
#define NMEA_HRP_HEADING_SD			5
#define NMEA_HRP_ROLL_SD			6
#define NMEA_HRP_PITCH_SD			7
#define NMEA_HRP_NUM_SAT			8
#define NMEA_HRP_MODE_INDICATOR		9

/*
	0: No attitude available
	1: Heading, Pitch with float ambiguities
	2: Heading, Pitch with fixed ambiguities
	3: Heading, Pitch, Roll with float ambiguities
	4: Heading, Pitch, Roll with fixed ambiguities
	5: Heading, Pitch from velocity (dead-reckoning)
*/
enum HRPModeIndicators
{
	NMEA_HRP_MODE_NO_FIX = 0,
	NMEA_HRP_MODE_HEADING_PITCH_FLOAT,
	NMEA_HRP_MODE_HEADING_PITCH_FIXED,
	NMEA_HRP_MODE_HEADING_PITCH_ROLL_FLOAT,
	NMEA_HRP_MODE_HEADING_PITCH_ROLL_FIXED,
	NMEA_HRP_MODE_HEADING_PITCH_FROM_VELOCITY
};

#endif  /* INC_NMEA_HRP_H */
