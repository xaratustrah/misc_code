#include <string>

using namespace std;

#ifndef __PERSON_H__
#define __PERSON_H__

class Person
{
	string name, prename, street, city;
	unsigned int postalCode;
public:
	Person();
	Person( string name, string prename );
	Person( string name, string prename, string street, string city, unsigned int postalCode );
	string GetName();
	void SetName( string name );
	string GetPrename();
	void SetPrename( string prename );
	string GetStreet();
	void SetStreet( string street );
	string GetCity();
	void SetCity( string city );
	unsigned int GetPostalCode();
	void SetPostalCode( unsigned int postalCode );
	void virtual print();
};

#endif
