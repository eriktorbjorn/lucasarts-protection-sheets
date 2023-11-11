/*
 * Based on Zak McKracken (v2) script-110.dmp
 *
 * The correct sequence is stored in Var[139] through Var[143]
 * Var[242] is the column, 1-7
 * Var[241] is the row, 1-30
 * Var[243] is the section, 1-7
 */

#include "decoder.h"
#include "util.h"

void decode(int *sequence, int section, int row, int column) {
	int var;

	var = (23 * section) + (2 * row) + column;
	adjust_if(&var, column >= 3, -2);
	var += row;
	adjust_if(&var, row < 5, 3);
	var += 12;
	adjust_while_ge(&var, 12, -9);

	sequence[2] = var;

	var += (row + column + 19);	
	adjust_if(&var, row > 7, -3);
	var += 7;
	adjust_while_ge(&var, 8, -7);
	var += 19;
	adjust_if(&var, var <= sequence[2], sequence[2]);
	adjust_while_ge(&var, 12, -12);

	sequence[3] = var;

	var += (row + 2 * column + 14);
	adjust_if(&var, row < 10, row);
	adjust_while_ge(&var, 10, -5);
	adjust_if(&var, var != sequence[3], sequence[2]);
	var += 23;
	adjust_while_ge(&var, 12, -12);

	sequence[1] = var;

	var += (row + 3 * column + 11);
	adjust_if(&var, column > 7, 6);
	adjust_while_ge(&var, 17, -8);
	adjust_if(&var, var > sequence[1], sequence[3]);
	var += 14;
	adjust_while_ge(&var, 12, -12);

	sequence[0] = var;
}
