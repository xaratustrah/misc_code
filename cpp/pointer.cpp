#include "class.cpp"
#include <iostream>
using namespace std;

int main()
{
     int* elements = new int [42];
     delete [] elements;
     elements = NULL;
     int * number = new int(12312);
     delete number;
     number = NULL;

     person *p = new person();
     p->test = 12;
     delete p;
     p = NULL;

     return 0;
}
