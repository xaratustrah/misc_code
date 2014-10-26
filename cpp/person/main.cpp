#include "person.h"
#include "student.h"

int main ()
{
	Student stud( "Holler", "Hans", "Kastanienallee 2", "Berlin", 10332 );
	stud.print();

	Person person( "Pils", "Peter", "Alte Brauerei 71", "Hamburg", 99827 );
	person.print();

	Student student2( "Kranich", "Kurt", "Hohlweg 42", "Regensburg", 69153 );
	student2.print();
	return 0;
}
