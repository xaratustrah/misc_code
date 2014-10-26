#include <iostream>
#include <string>

using namespace std;

#include "oralexamination.h"
#include "writtenexamination.h"

#ifndef __MASTEREXAMINATION_H__
#define __MASTEREXAMINATION_H__

class MasterExamination : public OralExamination, public WrittenExamination
{
protected:
	float grade;
public:
	MasterExamination();
	MasterExamination( string title );
	void print();
	float GetGrade();
	void CalculateGrade();
};

#endif