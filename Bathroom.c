#include "Bathroom.h"
#include "queue.h"

int main(int argc, char** argv)
{
	
}

int AddStudent()
{
	
}

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
}

Name* NewName(int first, int last)
{
	if(first < 0 || last < 0)
		return NULL;
	
	
}

void ReleaseName(Name** namepp)
{
	free(*(namepp)->first);
	*(namepp)->first = NULL;
	free(*(namepp)->last);
	*(namepp)->last = NULL;
	*namepp = NULL;
}
