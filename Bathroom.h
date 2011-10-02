#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

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

int NewStudent(int, const char*, const char*);
Name* NewName(int, int);

