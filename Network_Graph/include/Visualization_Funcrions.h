#ifndef VISUALIZATION_FUNCTIONS_H
#define VISUALIZATION_FUNCTIONS_H

#include <stdarg.h>

static int spaceCounter = 0;

enum colors {deflt, red, blue, yellow, green, magenta};

int printColorMessage(enum colors messageColorin, const char* format, ...)
{
	int i;
	for (i = 0; i < spaceCounter; i++) {
		printf("-");
	}
	switch (messageColorin) {
	case red:
		printf("\033[1;31m");
		break;
	case blue:
		printf("\033[1;34m");
		break;
	case yellow:
		printf("\033[1;33m");
		break;
	case green:
		printf("\033[1;32m");
		break;
	case magenta:
		printf("\033[1;35m");
		break;
	default:
		printf("\033[0m");
		break;
	}
	va_list arg;
	int done = 0;

	va_start(arg, format);
	done = vfprintf(stdout, format, arg, 0);
	va_end(arg);
	printf("\033[0m");
	return done;
}
#endif