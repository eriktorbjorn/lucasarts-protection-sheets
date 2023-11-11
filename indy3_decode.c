#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "decoder.h"

int main(int argc, char *argv[]) {
	int group, row, column;
	int i;
	int sequence[4];

	if (argc != 4) {
		fprintf(stderr, "Usage: %s group row column\n", argv[0]);
		return 1;
	}

	group = atoi(argv[1]);
	row = 1 + toupper(argv[2][0]) - 'A';
	column = atoi(argv[3]);

	if (group < 1 || group > 4) {
		fprintf(stderr, "Group must be 1-4\n");
		return 1;
	}

	if (row < 1 || row > 26) {
		fprintf(stderr, "Row must be A-Z\n");
		return 1;
	}

	if (column < 1 || column > 7) {
		fprintf(stderr, "Column must be 1-7\n");
		return 1;
	}

	decode(sequence, group, row, column);

	for (i = 0; i <= 3; i++) {
		printf("%d ", sequence[i] + 1);
	}

	printf("\n");
	return 0;
}
	
