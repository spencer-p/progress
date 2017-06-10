/*
 * db.h
 */

#include <stdbool.h>

//Structure for a log item
typedef struct {
	int day;
	char message[140]; //tweet length
} Log;

//Structure for a single task
typedef struct {
	char name[32];

	int streak; //days consecutively completed

	bool active;

	int logc; //total amount of log items
	Log *logs;
} Task;

void complete(char *name, char *message);
void uncomplete(char *name);
void start(char *name);
void stop(char *name);
void addTask(char *name);
void removeTask(char *name);

//read and write tasks
int writeTask(Task *t);
Task *readTask(char *n);

//clean it up
void freeTask(Task *t);

//Task overview
void printTask(Task *t);

//Most recent n log items (0 for all)
void printLog(Task *t, int n);
