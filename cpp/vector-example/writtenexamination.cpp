#include <string>
using namespace std;

#include "writtenexamination.h"

WrittenExamination::WrittenExamination()
{
	writtenGrade = 0;
}

WrittenExamination::WrittenExamination( string title) : Examination( title )
{
	writtenGrade = 0;
}

float WrittenExamination::GetWrittenGrade()
{
	return writtenGrade;
}

void WrittenExamination::SetWrittenGrade( float writtenGrade )
{
	this->writtenGrade = writtenGrade;
}
