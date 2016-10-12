/*
 * progress.c
 * The main program
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "db.h"

int main(int argc, char *argv[]) {
	if (argc > 1) {
		Task t;
		if (strcmp(argv[1], "read") == 0) {
			Task t = readTask("THIS SHIT DOESN'T MATTER YET");
		}
		else if (strcmp(argv[1], "write") == 0) {
			strncpy(t.name, "progress", sizeof(t.name)/sizeof(t.name[0]));
			t.streak = 5;
			t.logc = 1;
			t.logs = malloc(sizeof(Log));
			t.logs[0].day = 4;
			strncpy(t.logs[0].message, "did a thing today", sizeof(t.logs[0].message)/sizeof(t.logs[0].message[0]));
			writeTask(&t);
		}
		printTask(&t);
	}
}
