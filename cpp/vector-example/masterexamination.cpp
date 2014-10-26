#include <string>

using namespace std;

#include "masterexamination.h"

MasterExamination::MasterExamination()
{
	grade = 0;
}

MasterExamination::MasterExamination( string title ) : Examination( title )
{
	grade = 0;
}

void MasterExamination::print()
{
	cout << "Title: " << title << endl;
}

void MasterExamination::CalculateGrade()
{
	if( ( oralGrade + writtenGrade ) > 0 )
		grade = ( oralGrade + writtenGrade ) / 2;
	else
		grade = 0;
}

float MasterExamination::GetGrade()
{
	CalculateGrade();
	return grade;
}
