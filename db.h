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

int complete(char *task);
int uncomplete(char *task);

int writeTask(Task *t);
Task readTask(char *t);

void printTask(Task *t);
