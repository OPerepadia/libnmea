#ifndef INC_NMEA_RBD_H
#define INC_NMEA_RBD_H

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <nmea.h>

typedef struct {
	nmea_s base;
	double azimuth;
	double elevation;
	int numSat;
	uint8_t fixType;
	
} nmea_rbd_s;

/* Value indexes */
#define NMEA_RBD_TIME				0
#define NMEA_RBD_DATE				1
#define NMEA_RBD_AZIMUTH			2
#define NMEA_RBD_ELEVATION			3
#define NMEA_RBD_NUM_SAT			4
#define NMEA_RBD_FIX_TYPE			5

#endif  /* INC_NMEA_RBD_H */
