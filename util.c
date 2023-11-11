#include "util.h"

void adjust_if(int *value, int condition, int delta) {
	if (condition)
		*value += delta;
}

void adjust_while_ge(int *value, int max, int delta) {
	do {
		*value += delta;
	} while (*value >= max);
}
