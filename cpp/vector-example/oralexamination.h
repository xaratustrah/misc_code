#include <string>

using namespace std;

#include "examination.h"

#ifndef __ORALEXAMINATION_H__
#define __ORALEXAMINATION_H__

class OralExamination : virtual public Examination
{
protected:
	float oralGrade;
public:
	OralExamination();
	OralExamination( string title );
	float GetOralGrade();
	void SetOralGrade( float oralGrade );
};

#endif