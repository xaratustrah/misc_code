//////////////////////////////////////////////////////////////////////////////////////////////////////////
// ROOT Hello code										        //
// compile with											        //
// 												        //
// g++ -o root_hello root_hello.cpp `root-config --cflags --libs` -I/opt/local/include -L/opt/local/lib //
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// some lines

#Include <stdio.h>
#include <TRandom1.h>

int main(void) {

     TRandom1* myrand = new TRandom1();

     for(int i=0;i<10;++i) {
	  printf("%g\n", myrand->Gaus(5,1));
	  printf("hello\n");
     }
     return 0;
}
