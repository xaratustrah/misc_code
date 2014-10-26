#include <string>

using namespace std;

#include "examination.h"

#ifndef __WRITTENEXAMINATION_H__
#define __WRITTENEXAMINATION_H__

class WrittenExamination : virtual public Examination
{
protected:
	float writtenGrade;
public:
	WrittenExamination();
	WrittenExamination( string title );
	float GetWrittenGrade();
	void SetWrittenGrade( float writtenGrade );
};

#endif