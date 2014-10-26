#include <iostream>
#include "person.h"

Person::Person()
{
	name = "";
	prename = "";
	street = "";
	city = "";
	postalCode = 0;
}

Person::Person( string name, string prename )
{
	this->name = name;
	this->prename = prename;
	street = "";
	city = "";
	postalCode = 0;
}

Person::Person( string name, string prename, string street, string city, unsigned int postalCode )
{
	this->name = name;
	this->prename = prename;
	this->street = street;
	this->city = city;
	this->postalCode = postalCode;
}

string Person::GetName()
{
	return name;
}

void Person::SetName( string name )
{
	this->name = name;
}

string Person::GetPrename()
{
	return prename;
}

void Person::SetPrename( string prename )
{
	this->prename = prename;
}

string Person::GetStreet()
{
	return street;
}

void Person::SetStreet( string street )
{
	this->street = street;
}

string Person::GetCity()
{
	return city;
}

void Person::SetCity( string city )
{
	this->city = city;
}

unsigned int Person::GetPostalCode()
{
	return postalCode;
}

void Person::SetPostalCode( unsigned int postalCode )
{
	this->postalCode = postalCode;
}

void Person::print()
{
	cout << "Name, Prename: " << name << ", " << prename << endl;
	cout << "Street       : " << street << endl;
	if( postalCode == 0 )
		cout << "City         : " << city << endl;
	else
		cout << "City         : " << postalCode << " " << city << endl;
	cout << endl;
}
