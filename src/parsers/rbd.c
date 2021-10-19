#include "../nmea/parser_types.h"
#include "rbd.h"
#include "parse.h"

int
init(nmea_parser_s *parser)
{
	/* Declare what sentence type to parse */
	NMEA_PARSER_TYPE(parser, NMEA_RBD);
	NMEA_PARSER_PREFIX(parser, "GPRBD");
	return 0;
}

int
allocate_data(nmea_parser_s *parser)
{
	parser->data = malloc(sizeof (nmea_rbd_s));
	if (NULL == parser->data) {
		return -1;
	}

	return 0;
}

int
set_default(nmea_parser_s *parser)
{
	memset(parser->data, 0, sizeof (nmea_rbd_s));
	return 0;
}

int
free_data(nmea_s *data)
{
	free(data);
	return 0;
}

int
parse(nmea_parser_s *parser, char *value, int val_index)
{
	nmea_rbd_s *data = (nmea_rbd_s *) parser->data;

	switch (val_index) {
	case NMEA_RBD_AZIMUTH:
		data->azimuth = strtod(value, NULL);
		break;
	case NMEA_RBD_ELEVATION:
		data->elevation = strtod(value, NULL);
		break;
	case NMEA_RBD_NUM_SAT:
		data->numSat = atoi(value);
		break;
	case NMEA_RBD_FIX_TYPE:
		data->fixType = atoi(value);
		break;

	default:
		break;
	}

	return 0;
}
