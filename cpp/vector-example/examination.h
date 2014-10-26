#include <string>

using namespace std;

#ifndef __EXAMINATION_H__
#define __EXAMINATION_H__

class Examination
{
	float grade;
protected:
	string title;
public:
	Examination();
	Examination( string title );
	string GetTitle();
	void SetTitle( string title );
	float virtual GetGrade();
	void virtual SetGrade( float grade );
};

#endif