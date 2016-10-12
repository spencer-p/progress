/*
 * db.c
 * Functions for managing the data, abstracted
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "db.h"

int complete(char *task);
int uncomplete(char *task);

int days(char *task);
int getday();

int writeTask(Task *t);
Task readTask(char *t);

//Read and write the logs of an existing task
int writeLog(Task *t);
int readLog(Task *t);


int getday() {
	return (int) time(NULL)/(60*60*24);
}

int writeTask(Task *t) {
	FILE *f = fopen("file", "w");
	if (f == NULL) { return 0; }

	//fseek(f, 0, SEEK_END); //TODO learn why
	fwrite(t, sizeof(*t), 1, f);
	writeLog(t);
	fclose(f);
}

Task readTask(char *t) {
	FILE *f = fopen("file", "r");
	Task new;
	if (f == NULL) { perror("Unable to read task"); return new; }

	fread(new.name, sizeof(char), 32, f);
	fread(&new.streak, sizeof(int), 1, f);
	fread(&new.logc, sizeof(int), 1, f);
	readLog(&new);

	fclose(f);
	return new;
}

int readLog(Task *t) {
	t->logs = malloc(sizeof(Log)*t->logc);

	FILE *f = fopen("file.log", "r");
	if (f == NULL) { perror("Unable to read log"); return 0; }

	for (int i = 0; i < t->logc; i++) {
		fread(&t->logs[i].day, sizeof(int), 1, f);
		fread(t->logs[i].message, sizeof(char), 140, f);
	}

	fclose(f);
	return 1; //success
}

int writeLog(Task *t) {
	FILE *f = fopen("file.log", "w");
	if (f == NULL) { perror("Unable to write log"); return 0; }

	for (int i = 0; i < t->logc; i++) {
		fwrite(&t->logs[i].day, sizeof(int), 1, f);
		fwrite(t->logs[i].message, sizeof(char), 140, f);
	}

	fclose(f);
	return 1; //success
}

void printTask(Task *t) {
	printf("Task:\t%s\nStreak:\t%d\nLogc:\t%d\n", t->name, t->streak, t->logc);
	for (int i = 0; i < t->logc; i++) {
		printf("%d %s\n", t->logs[i].day, t->logs[i].message);
	}
}
