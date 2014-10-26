#include "studies.h"
#include <fstream>

Studies::Studies()
{
	title = "";
	oralExams = new Vector<OralExamination>();
	writtenExams = new Vector<WrittenExamination>();
}

Studies::Studies( string title )
{
	this->title = title;
	oralExams = new Vector<OralExamination>();
	writtenExams = new Vector<WrittenExamination>();
}

Studies::~Studies()
{
	delete oralExams;
	delete writtenExams;
}

void Studies::AddOralExamination( OralExamination* exam )
{
	oralExams->Add( exam );
}

void Studies::AddWrittenExamination( WrittenExamination* exam )
{
	writtenExams->Add( exam );
}

float Studies::GetGPA()
{
	int count = 0;
	float sum = 0;
	int length = oralExams->Length();
	for( int i = 0; i < length; i++ )
	{
		OralExamination *tmp = oralExams->Get( i );
		sum += tmp->GetOralGrade();
		count++;
	}

	length = writtenExams->Length();
	for( i = 0; i < length; i ++ )
	{
		WrittenExamination *tmp = writtenExams->Get( i ) ;
		sum += tmp->GetWrittenGrade();
		count++;
	}

	if( ( count > 0 ) && ( sum > 0 ) )
		return ( sum / ( float )count );
	else
		return 0;
}

void Studies::save( char * fileName )
{
	ofstream file ( fileName );
	if( file.is_open() )
	{

		file << "Studiengang " << title << endl << endl;

		file << "Mündliche Prüfungen: \n";

		int length = oralExams->Length();
		for( int i = 0; i < length; i++ )
		{
			OralExamination *tmp = oralExams->Get( i );
			file << " -  " << tmp->GetTitle() << " :  " << tmp->GetOralGrade() << endl;
		}

		file << "Schriftliche Prüfungen: \n";

		length = writtenExams->Length();
		for( i = 0; i < length; i ++ )
		{
			WrittenExamination *tmp = writtenExams->Get( i ) ;
			file << " -  " << tmp->GetTitle() << " :  " << tmp->GetWrittenGrade() << endl;
		}

	    file << "-----------------------------------\n";
		file << "Durchschnitt: " << this->GetGPA() << endl;
		file.close();
	}
}

string Studies::GetTitle()
{
	return title;
}

void Studies::SetTitle( string title )
{
	this->title = title;
}