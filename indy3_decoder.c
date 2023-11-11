/*
 * Based on Indiana Jones and the Last Crusade (Mac) room-92-205.dmp
 *
 * The correct sequence is stored in Var[99] through Var[102]
 * Var[103] is the row, 1-26
 * Var[104] is the row, 1-6
 * Var[105] is the group, 1-4
 */

#include "decoder.h"
#include "util.h"

void decode(int *sequence, int section, int row, int column) {
	int var;

	var = 17 * section + (3 * row) + column + 12;
	adjust_if(&var, column >= 3, -2);
	adjust_if(&var, row < 5, 3);
	adjust_while_ge(&var, 12, -9);

	sequence[2] = var;

	var += (column + row + 26);
	adjust_if(&var, row > 7, -5);
	adjust_while_ge(&var, 8, -7);
	var += 19;
	adjust_if(&var, var <= sequence[2], sequence[2]);
	adjust_while_ge(&var, 12, -12);

	sequence[3] = var;

	var += (3 * column + row + 14);
	adjust_if(&var, row < 10, row);
	adjust_while_ge(&var, 10, -5);
	adjust_if(&var, var != sequence[3], sequence[2]);
	var += 23;
	adjust_while_ge(&var, 12, -12);

	sequence[1] = var;

	var += (3 * column + row + 13);
	adjust_if(&var, column > 7, 6);  // Should never happen
	adjust_while_ge(&var, 17, -8);
	adjust_if(&var, var > sequence[1], sequence[3]);
	var += 14;
	adjust_while_ge(&var, 12, -12);

	sequence[0] = var;
}
