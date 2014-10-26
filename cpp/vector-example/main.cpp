#include "masterexamination.h"
#include "vector.h"
#include "studies.h"

int main()
{
	Studies ETiT( "ETiT" );


	WrittenExamination *mathe = new WrittenExamination( "Mathe I + II" );
	mathe->SetWrittenGrade( 1.3f );
	ETiT.AddWrittenExamination( mathe );
	mathe = NULL;

	WrittenExamination *informatik = new WrittenExamination( "Informatik III" );
	informatik->SetWrittenGrade( 1.0f );
	ETiT.AddWrittenExamination( informatik );
	informatik = NULL;

	OralExamination *signalProcessing = new OralExamination( "Signalverarbeitung" );
	signalProcessing->SetOralGrade( 2.3f );
	ETiT.AddOralExamination( signalProcessing );
	signalProcessing = NULL;

	ETiT.save( "ETiT.txt" );

	cout << "Durchschnitt: " << ETiT.GetGPA() << endl;


	return 0;
}