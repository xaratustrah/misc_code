#include "person.h"

#ifndef __STUDENT_H__
#define __STUDENT_H__

class Student : virtual public Person
{
	static unsigned int number;
public:
	Student();
	Student( string name, string prename );
	Student( string name, string prename, string street, string city, unsigned int postalCode);
	unsigned int GetNumber();
	void print();
};

#endif
