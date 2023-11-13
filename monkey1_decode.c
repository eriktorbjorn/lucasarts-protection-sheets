#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int upper, lower, place;
	int var100, var296, var298, var299, local0;

	int remap[] = { 6, 13, 3, 12, 7, 9, 2, 5, 8 };

	int string37[] = {
		204, 152, 218, 166, 121,  60, 184,
		145, 196, 161, 56,  201,  86, 176,
		173, 219, 185, 215, 182, 148, 95,
		213, 124, 179, 160, 193, 129, 113,
		188, 203, 107, 167,  62, 133, 174,
		126,  88,  74, 164, 199, 189, 115,
		162, 108, 217, 186,  73, 198, 146,
		197,  57, 211, 150,  79, 205, 183,
		220, 143, 178,  61, 159, 103, 207,
		 58, 187, 122, 168, 200, 175, 191,
		109,  71, 137, 156,   0, 206, 190,
		 93, 172,  53, 149, 216,  36, 118,
		163, 180,  67, 140, 210,  59,  98,
		154,  91, 202, 165,  78, 214, 147,
		181, 212, 195, 105,  45, 158, 135
	};

	if (argc != 4) {
		printf("Usage: %s upper-face lower-face place\n\n", argv[0]);

		printf("Pirate faces\n\n");
		printf("0 Sideburns        3 Skull             6 Monkey\n");
		printf("1 Nightcap         4 Brown-skinned     7 Masked\n");
		printf("2 Redhead          5 Scarred           8 Zombie\n");

		printf("Places\n\n");
		printf("0 Antigua          3 Montserrat        6 Tortuga\n");
		printf("1 Barbados         4 Nebraska\n");
		printf("2 Jamaica          5 St. Kitts\n");
		return EXIT_FAILURE;
	}

	upper = atoi(argv[1]);
	lower = atoi(argv[2]);
	place = atoi(argv[3]);

	if (upper < 0 || upper > 8) {
		printf("Invalid upper-face value %d, expected 0-8\n", upper);
		return EXIT_FAILURE;
	}

	if (lower < 0 || lower > 8) {
		printf("Invalid lower-face value %d, expected 0-8\n", lower);
		return EXIT_FAILURE;
	}

	if (place < 0 || place > 6) {
		printf("Invalid place value %d, expected 0-6\n", place);
		return EXIT_FAILURE;
	}

	var298 = remap[upper];
	var299 = remap[lower];

	var296 = var298 - var299;
	if (var296 < 0)
		var296 += 15;

	var296 += (2 * place);
	if (var296 < 0)
		var296 += 15;

	if (var296 >= 15)
		var296 -= 15;

	local0 = 7 * var296 + place;
	var100 = string37[local0];

	local0 = var100 + 1506;

	printf("%d\n", local0);
	return EXIT_SUCCESS;
}
