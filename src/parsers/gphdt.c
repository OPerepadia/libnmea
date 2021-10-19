#include "../nmea/parser_types.h"
#include "gphdt.h"
#include "parse.h"

int
init(nmea_parser_s *parser)
{
	/* Declare what sentence type to parse */
	NMEA_PARSER_TYPE(parser, NMEA_GPHDT);
	NMEA_PARSER_PREFIX(parser, "GPHDT");
	return 0;
}

int
allocate_data(nmea_parser_s *parser)
{
	parser->data = malloc(sizeof (nmea_gphdt_s));
	if (NULL == parser->data) {
		return -1;
	}

	return 0;
}

int
set_default(nmea_parser_s *parser)
{
	memset(parser->data, 0, sizeof (nmea_gphdt_s));
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
	nmea_gphdt_s *data = (nmea_gphdt_s *) parser->data;

	switch (val_index) {
	case NMEA_GPHDT_HEADING:
		/* Parse heading */
		data->heading = strtod(value, NULL);
		break;
	case NMEA_GPHDT_HEADING_TRUE:
		/* Parse heading True flag */
		if (value[0] == 'T') {
			data->headingTrue = 1;
		}
		else {
			data->headingTrue = 0;
		}

	default:
		break;
	}

	return 0;
}
