#include "../nmea/parser_types.h"
#include "rbp.h"
#include "parse.h"

int
init(nmea_parser_s *parser)
{
	/* Declare what sentence type to parse */
	NMEA_PARSER_TYPE(parser, NMEA_RBP);
	NMEA_PARSER_PREFIX(parser, "RBP");
	return 0;
}

int
allocate_data(nmea_parser_s *parser)
{
	parser->data = malloc(sizeof (nmea_rbp_s));
	if (NULL == parser->data) {
		return -1;
	}

	return 0;
}

int
set_default(nmea_parser_s *parser)
{
	memset(parser->data, 0, sizeof (nmea_rbp_s));
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
	nmea_rbp_s *data = (nmea_rbp_s *) parser->data;

	switch (val_index) {
	case NMEA_RBP_POS_NORTH:
		data->posNorth = strtod(value, NULL);
		break;
	case NMEA_RBP_POS_EAST:
		data->posEast = strtod(value, NULL);
		break;
	case NMEA_RBP_POS_UP:
		data->posUp = strtod(value, NULL);
		break;
	case NMEA_RBP_NUM_SAT:
		data->numSat = atoi(value);
		break;
	case NMEA_RBP_FIX_TYPE:
		data->fixType = atoi(value);
		break;

	default:
		break;
	}

	return 0;
}
