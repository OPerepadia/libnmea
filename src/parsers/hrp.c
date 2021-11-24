#include "../nmea/parser_types.h"
#include "hrp.h"
#include "parse.h"

int
init(nmea_parser_s *parser)
{
	/* Declare what sentence type to parse */
	NMEA_PARSER_TYPE(parser, NMEA_HRP);
	NMEA_PARSER_PREFIX(parser, "GPHRP");
	return 0;
}

int
allocate_data(nmea_parser_s *parser)
{
	parser->data = malloc(sizeof (nmea_hrp_s));
	if (NULL == parser->data) {
		return -1;
	}

	return 0;
}

int
set_default(nmea_parser_s *parser)
{
	memset(parser->data, 0, sizeof (nmea_hrp_s));
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
	nmea_hrp_s *data = (nmea_hrp_s *) parser->data;

	switch (val_index) {
	case NMEA_HRP_HEADING:
		data->heading = strtod(value, NULL);
		break;
	case NMEA_HRP_ROLL:
		data->roll = strtod(value, NULL);
		break;
	case NMEA_HRP_PITCH:
		data->pitch = strtod(value, NULL);
		break;
	case NMEA_HRP_HEADING_SD:
		data->headingSD = strtod(value, NULL);
		break;
	case NMEA_HRP_ROLL_SD:
		data->rollSD = strtod(value, NULL);
		break;
	case NMEA_HRP_PITCH_SD:
		data->pitchSD = strtod(value, NULL);
		break;
	case NMEA_HRP_NUM_SAT:
		data->numSat = atoi(value);
		break;
	case NMEA_HRP_MODE_INDICATOR:
		data->modeIndicator = atoi(value);
		break;

	default:
		break;
	}

	return 0;
}
