#ifndef INC_NMEA_GPHDT_H
#define INC_NMEA_GPHDT_H

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <nmea.h>

typedef struct {
	nmea_s base;
	double heading;
	uint8_t headingTrue;
} nmea_gphdt_s;

/* Value indexes */
#define NMEA_GPHDT_HEADING			0
#define NMEA_GPHDT_HEADING_TRUE		1

#endif  /* INC_NMEA_GPHDT_H */
