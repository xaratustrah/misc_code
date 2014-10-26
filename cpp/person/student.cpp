#include <iostream>
#include "student.h"

Student::Student()
{
	number++;
}

Student::Student( string name, string prename ):Person( name, prename )
{
	number++;
}

Student::Student( string name, string prename, string street, string city, unsigned int postalCode )
		:Person( name, prename, street, city, postalCode )
{
	number++;
}

unsigned int Student::number = 0;

unsigned int Student::GetNumber()
{
	return number;
}

void Student::print()
{
	cout << "Student ( " << number << " )"<< endl;
	Person::print();

