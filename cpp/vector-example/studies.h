#include <string>

using namespace std;

#include "masterexamination.h"
#include "vector.h"

#ifndef __STUDIES_H__
#define __STUDIES_H__

class Studies
{
	Vector<OralExamination> *oralExams;
	Vector<WrittenExamination> *writtenExams;
	string title;
public:
	Studies();
	Studies( string title );
	~Studies();
	void AddOralExamination( OralExamination* exam );
	void AddWrittenExamination( WrittenExamination* exam );
	float GetGPA();  // Grade Point Average
	void save( char * fileName );
	string GetTitle();
	void SetTitle( string title );
};

#endif