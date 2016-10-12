/*
 * db.h
 */

//Structure for a log item
typedef struct {
	int day;
	char message[140]; //tweet length
} Log;

//Structure for a single task
typedef struct {
	char name[32];

	int streak; //days consecutively completed

	int logc; //total amount of log items
	Log *logs;
} Task;

void complete(char *name, char *message);
void uncomplete(char *name);
void addTask(char *name);
void removeTask(char *name);

int writeTask(Task *t);
Task readTask(char *n);

//Task overview
void printTask(Task *t);

//Most recent n log items (0 for all)
void printLog(Task *t, int n);
