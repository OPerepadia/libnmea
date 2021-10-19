#ifndef INC_NMEA_RBP_H
#define INC_NMEA_RBP_H

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <nmea.h>

typedef struct {
	nmea_s base;
	double posNorth;
	double posEast;
	double posUp;
	int numSat;
	uint8_t fixType;
	
} nmea_rbp_s;

/* Value indexes */
#define NMEA_RBP_TIME				0
#define NMEA_RBP_DATE				1
#define NMEA_RBP_POS_NORTH			2
#define NMEA_RBP_POS_EAST			3
#define NMEA_RBP_POS_UP				4
#define NMEA_RBP_NUM_SAT			5
#define NMEA_RBP_FIX_TYPE			6

#endif  /* INC_NMEA_RBP_H */
