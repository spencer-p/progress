/*
 * progress.c
 * The main program
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "db.h"

int main(int argc, char *argv[]) {
	if (argc < 3 && strcmp(argv[1], "help") != 0) {
		printf("%s [verb] [task]\n", argv[0]);
		return 1;
	}

	if (strcmp(argv[1], "help") == 0) {
		printf("%s [verb] [task]\n", argv[0]);
		printf("\tadd remove complete uncomplete show log\n");
		return 0;
	}
	else if (strcmp(argv[1], "add") == 0) {
		addTask(argv[2]);
	}
	else if (strcmp(argv[1], "remove") == 0) {
		removeTask(argv[2]);
	}
	else if (strcmp(argv[1], "complete") == 0) {
		char *message = "";
		if  (argc > 3) {
			message = argv[3];
		}
		complete(argv[2], message);
	}
	else if (strcmp(argv[1], "uncomplete") == 0) {
		uncomplete(argv[2]);
	}
	else if (strcmp(argv[1], "show") == 0) {
		Task *t = readTask(argv[2]);
		printTask(t);
		printLog(t, 3);
		freeTask(t);
	}
	else if (strcmp(argv[1], "log") == 0) {
		Task *t = readTask(argv[2]);
		int n = 3;
		if (argc > 3) {
			n = atoi(argv[3]);
		}
		printLog(t, n);
		freeTask(t);
	}
	/*if (argc == -1) {
		Task t;
		if (strcmp(argv[1], "read") == 0) {
			Task t = readTask("progress");
		}
		else if (strcmp(argv[1], "write") == 0) {
			strncpy(t.name, "progress", sizeof(t.name)/sizeof(t.name[0]));
			t.streak = 5;
			t.logc = 1;
			t.logs = malloc(sizeof(Log));
			t.logs[0].day = 17085;
			strncpy(t.logs[0].message, "did a thing today", sizeof(t.logs[0].message)/sizeof(t.logs[0].message[0]));
			writeTask(&t);
		}
		printTask(&t);
		printLog(&t, 0);
		free(t.logs);
	}*/
}
