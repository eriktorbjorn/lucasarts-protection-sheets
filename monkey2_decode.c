#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int part1, part2, recipe, amount1, amount2;
	int var551, local0;

	int string42[] = {
		11, 47, 23, 25, 32, 24, 49,
		37, 24, 30, 39, 26, 29, 42,
		34, 45, 26, 50, 15, 52, 22,
		27, 15, 60, 15, 42, 50, 23,
		24, 26, 38, 48, 48, 30, 58,
		16, 15, 53, 34, 26, 21, 11,
		28, 46, 32, 44, 30, 57, 31,
		27, 51, 12, 36, 28, 47, 42,
		13, 56, 57, 26, 27, 55, 32,
		33, 56, 58, 11, 60, 27, 15,
		30, 34, 32, 16, 48, 60, 19,
		56, 14, 12, 44, 33, 17, 34,
		39, 25, 28, 19, 54, 21, 48,
		16, 38, 24, 50, 22, 34, 42,
		11, 32, 17, 31, 60, 37, 20
	};

	int string44[] = {
		52, 34, 48, 31, 29, 47, 34,
		22, 38, 46, 20, 12, 51, 26,
		25, 51, 17, 39, 54, 20, 17,
		48, 60, 24, 52, 50, 57, 25,
		29, 18, 17, 23, 11, 49, 55,
		16, 40, 50, 45, 57, 13, 48,
		43, 22, 54, 30, 16, 13, 17,
		12, 15, 13, 19, 22, 34, 21,
		36, 16, 12, 20, 11, 23, 27,
		54, 47, 35, 56, 36, 21, 15,
		47, 39, 44, 19, 22, 41, 21,
		16, 12, 45, 34, 50, 36, 22,
		58, 46, 31, 12, 54, 44, 20,
		22, 44, 37, 38, 38, 51, 57,
		41, 48, 23, 48, 16, 47, 59
	};

	if (argc != 4) {
		printf("Usage: %s first-ingredient second-ingredient recipe\n\n", argv[0]);
		printf("First ingredients\n\n");
		printf("0 Sprinkles of MSG        5 Ounces body odor        10 Deadly toadstools\n");
		printf("1 Breath mints            6 Bloated ticks           11 Liver cubes\n");
		printf("2 Dead cats               7 Grave digger's socks    12 Hair balls\n");
		printf("3 Rhinoceros toenails     8 Sprigs of poison oak    13 Globs of bat wax\n");
		printf("4 Duck feet               9 Bushels of okra         14 Crab scalps\n\n");

		printf("Second ingredients\n\n");
		printf("0 Gobs of spit            5 Spider lungs            10 Serv. of fruit cocktail\n");
		printf("1 Wads of pre-chewed gum  6 Boxes of voodoo helper  11 Cheese squigglies\n");
		printf("2 Owl pellets             7 Used hankies            12 Peg leg polish\n");
		printf("3 Drops of skunk extract  8 Mugs of grog            13 Fishtails\n");
		printf("4 Pig feet                9 CC's of snake sweat     14 Shark lips\n\n");

		printf("Recipes\n\n");
		printf("0 Worms                   3 Warts                    6 Peg leg rot\n");
		printf("1 Gout                    4 Trench mouth\n");
		printf("2 Scurvy                  5 Tattoo rash\n");

		return EXIT_FAILURE;
	}

	part1 = atoi(argv[1]);
	part2 = atoi(argv[2]);
	recipe = atoi(argv[3]);

	if (part1 < 0 || part1 > 14) {
		printf("Invalid first-ingredient value %d, expected 0-14\n", part1);
		return EXIT_FAILURE;
	}

	if (part2 < 0 || part2 > 14) {
		printf("Invalid second-ingredient value %d, expected 0-14\n", part2);
		return EXIT_FAILURE;
	}

	if (recipe < 0 || recipe > 6) {
		printf("Invalid recipe value %d, expected 0-6\n", recipe);
		return EXIT_FAILURE;
	}

	/*
	 * The game never picks ingredient 5 as the first one. Perhaps it was
	 * too difficult to illustrate?
	 */

	var551 = part2 - part1;
	if (var551 < 0)
		var551 += 15;

	var551 += (2 * recipe);
	if (var551 < 0)
		var551 += 15;

	if (var551 >= 15)
		var551 -= 15;

	local0 = 7 * var551 + recipe;

	amount1 = string42[local0];
	amount2 = string44[local0];

	printf("%d/%d\n", amount1, amount2);
	return EXIT_SUCCESS;
}
