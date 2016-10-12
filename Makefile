progress: progress.c db.c db.h
	cc -std=c99 progress.c db.c db.h -o progress

debug: progress.c db.c db.h
	cc -std=c99 -g progress.c db.c db.h -o progress
