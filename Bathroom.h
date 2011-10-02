#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite.h>
#include <errno.h>

#define MAXTRIPS 5
#define DBNAME ".bathroom.db"
#define DBFLAGS SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE

struct personname {
	char* first;
	char*  last;
};

struct date {
	unsigned int day;
	unsigned int month;
	unsigned int year;
};

typedef struct personame Name;

struct student {
	int id;
	Name name;
	unsigned char remaining;
	date last_trip;
};

typedef struct student Student;
typedef Student QueueEntry;

Initialize(sqlite3*, );
Cleanup(sqlite3*
int LoadStudent(Student*, int);
int NewStudent(Student*, int, const char*, const char*);
Name* NewName(int, int);
int ReleaseName(Name**);
int ReleaseStudent(Student**);
