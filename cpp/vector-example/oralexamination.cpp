#include <string>
using namespace std;


#include <iostream>


#include "oralexamination.h"

OralExamination::OralExamination()
{
	oralGrade = 0;
}

OralExamination::OralExamination( string title) : Examination( title )
{
	oralGrade = 0;
}

float OralExamination::GetOralGrade()
{
	return oralGrade;
}

void OralExamination::SetOralGrade( float oralGrade )
{
	this->oralGrade = oralGrade;
}

