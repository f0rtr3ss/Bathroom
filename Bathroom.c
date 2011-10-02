#include "Bathroom.h"
#include "queue.h"

int main(int argc, char** argv)
{
	sqlite* pdb;
	Queue waiting;
	Student current, next;
	
	Initialize(&pdb);
	
	/*
	 * More stuffz here, codez etc.
	 * 
	 * 0) Get ID
	 * 1) Validate ID
	 * 2) UpdateDB
	 * 3) Process queue
	 * 4) Accept input
	 * 
	 */
	
	Cleanup(pdb);
	return 0;
}

/*
 * Bathroom functions
 */

int Initialize(sqlite** ppdb, )
{
	int status;
	char* errormsg;
	
	status = sqlite3_open_v2(DBNAME, ppdb, DBFLAGS, NULL)
	if(status != SQLITE_OK)
	{
		sqlite3_errmsg(*ppdb);
		sqlite3_close(*ppdb);
		return -status;
	}
	
	return 0;
}

int Cleanup(sqlite* db)
{
	sqlite3_close(db);
}

/*
 * Member Functions for Bathroom.h specific structures
 */

/* Needs work, LOTS of work! :P */
int LoadStudent(Student* stud, int id)
{
	/* We assume here that the student DOES exist, we have just tested this right? */
	
}

/* Done */
int NewStudent(Student* stud, int id, const char* first, const char* last)
{
	Name* namep;
	
	if((stud = malloc(sizeof(Student))) == NULL)
		return -ENOMEM;
	
	namep = NewName(strlen(first), strlen(last));
	
	if(namep == NULL)
		return -ENOMEM;
	
	strcpy(namep->first, first);
	strcpy(namep->last, last);
	
	stud->name = *namep;
	ReleaseName(&namep);
	
	stud->id = id;
	memset(&stud->last_trip, 0, sizeof(date));
	stud->remaining = MAXTRIPS;
	
	return 0;
}

/* Done */
Name* NewName(int first, int last)
{
	Name* namep;
	
	if(first < 0 || last < 0)
		return NULL;
	
	namep->first = malloc(first * sizeof(char));
	namep->last = malloc(last * sizeof(char));
	
	if(namep->first == NULL || namep->last == NULL)
	{
		if(namep->first != NULL)
		{
			free(namep->first);
			namep->first = NULL;
		}
		
		if(namep->last != NULL)
		{
			free(namep->last);
			namep->last = NULL;
		}
		
		return NULL;
	}
	
	return namep;
}

/* Done */
void ReleaseName(Name** namepp)
{
	free(*(namepp)->first);
	*(namepp)->first = NULL;
	free(*(namepp)->last);
	*(namepp)->last = NULL;
	*namepp = NULL;
}

/* Done */
void ReleaseStudent(Student** stud)
{
	Name* namep = &(*(stud)->name);
	ReleaseName(&namep);
	memset(*stud, 0, sizeof(Student));
	free(*stud);
	*stud = NULL;
}
