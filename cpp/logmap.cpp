// Logistic map function plot with ROOT
// xaratustra 11.AUG.2010
// 
// first login to root (period at the beginning of the line!):
// 
// . rootlogin pro
// 
// then compile with:
// g++ `root-config --cflags --ldflags --libs --glibs` -o logmap logmap.cpp
// change values of the LogMapGen like this to see how logistic map function works:
//     LogMapGen (0.2, 2.9);
//     LogMapGen (0.2, 3.1);
//     LogMapGen (0.2, 4.0);
// 
//     Or use different seed values.
// have fun!

#include <TGClient.h>
#include <TApplication.h>
#include <TGraph.h>

Double_t x[100], y[100];
void LogMapGen (double, double);

int 
main (int argc, char **argv)
{

    // Instanz der Applikation
    TApplication meineApp ("App", &argc, argv);

    // Hier rechne dich blau!
    LogMapGen (0.2, 4.0);

    // objekt fuers Zeichnen
    TGraph *gr = new TGraph (100, x, y);

    gr->SetLineColor (2);
    gr->SetMarkerColor (4);
    gr->SetMarkerSize (0.5);
    gr->SetMarkerStyle (21);
    gr->SetTitle ("Logistic map function");
    gr->Draw ("ALP");

    // und los
    meineApp.Run ();
    return 0;
}

void
LogMapGen (double seed, double a)
{
    // Calculates the logistic map function
    double xprev = seed;

    for (int i = 0; i < 100; i++) {
	x[i] = i;
	xprev = a * xprev * (1 - xprev);
	y[i] = xprev;
    }
    return;
}
