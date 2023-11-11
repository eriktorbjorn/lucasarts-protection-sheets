/*
 * Based on EGA Loom room-69-201.dmp
 *
 * 1 = Throw
 * 2 = Beat
 * 3 = Treadle
 * 4 = Rest
 *
 * 1 = object 879 (staff)
 * 2 = object 881 (sheep)
 * 3 = object 883 (spinning-wheel)
 * 4 = object 882 (anvil)
 * 5 = object 880 (goblet)
 * 6 = object 884 (soundwave)
 *
 * Local[7] = guild, 1-6
 * Local[8] = thread, 1-4
 *
 * The sequence is stored in Var[87] - Var[90]
 */

#include "loom_decoder.h"
#include "util.h"

void decode(int *sequence, int guild, int thread) {
	int local4, local6;

	local4 = (3 * guild) + thread + 29;
	adjust_if(&local4, thread >= 3, -2);
	adjust_if(&local4, guild < 5, 3);
	adjust_while_ge(&local4, 12, -9);

	sequence[2] = local4;

	local4 += (thread + guild + 26);
	adjust_if(&local4, guild > 7, -5);   // Can't happen?
	adjust_while_ge(&local4, 8, -7);
	local4 += 19;
	local6 = sequence[2];
	adjust_if(&local4, local4 <= local6, local6);
	adjust_while_ge(&local4, 12, -12);

	sequence[3] = local4;

	local4 += (guild + 3 * thread + 14);
	adjust_if(&local4, guild < 10, guild);  // Always true?
	adjust_while_ge(&local4, 10, -5);
	local6 = sequence[3];
	if (local4 != local6) {
		local6 = sequence[2];
		local4 += local6;
	}
	local4 += 23;
	adjust_while_ge(&local4, 12, -12);

	sequence[1] = local4;

	local4 += (guild + 3 * thread + 13);
	adjust_if(&local4, thread > 7, 6);    // Can't happen?
	adjust_while_ge(&local4, 17, -8);
	local6 = sequence[1];
	if (local4 > local6) {
		local6 = sequence[3];
		local4 += local6;
	}
	local4 += 14;
	adjust_while_ge(&local4, 12, -12);

	sequence[0] = local4;
}
