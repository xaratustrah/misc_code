#include "examination.h"

#ifndef __EXAMINATIONHOLDER_H__
#define __EXAMINATIONHOLDER_H__

class ExaminationHolder
{
	Examination exam;
public:
	Examination GetExamination();
	void SetExamination( Examination exam );
};

#endif