#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "decoder.h"

int main(int argc, char *argv[]) {
	int section, row, column;
	int i;
	int sequence[4];

	if (argc != 4) {
		fprintf(stderr, "Usage: %s section row column\n", argv[0]);
		return 1;
	}

	section = atoi(argv[1]);
	column = 1 + toupper(argv[2][0]) - 'A';
	row = atoi(argv[3]);

	if (section < 1 || section > 7) {
		fprintf(stderr, "Section must be 1-7\n");
		return 1;
	}

	if (column < 1 || column > 9) {
		fprintf(stderr, "Column must be A-I\n");
		return 1;
	}

	if (row < 1 || row > 37) {
		fprintf(stderr, "Row must be 1-37\n");
		return 1;
	}

	decode(sequence, section, row, column);

	for (i = 0; i <= 3; i++) {
		printf("%d ", sequence[i] + 1);
	}

	printf("\n");
	return 0;
}
	
