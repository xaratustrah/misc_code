#include <string>


#include<iostream>

using namespace std;

#include "examination.h"

Examination::Examination()
{
	title = "";
	grade = 0;
}

Examination::Examination( string title )
{
	this->title = title; 
	grade = 0;
}

string Examination::GetTitle()
{
	return title;
}

void Examination::SetTitle( string title )
{
	this->title = title;
}

float Examination::GetGrade()
{
cout << "getgrade examination" << endl;
	return grade;
}

void Examination::SetGrade( float grade )
{
	this->grade = grade;
}