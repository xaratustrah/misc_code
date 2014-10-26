#include <iostream>
#include <fstream>
using namespace std;

int width = 3;

struct datapoint {
  double re;
  double im;
};

int PrintSingle(struct datapoint * tmp){
  cout << tmp->re << endl << tmp->im << endl;
  cout << "Structure size is: " << sizeof(*tmp) << endl;
  cout << "Pointer size is: " << sizeof(tmp) << endl;
}

int PrintArray(datapoint tmp[], int array_width){
  // cout << "Array size is: " << sizeof(tmp) << endl;
  // cout << "Pointer size is: " << sizeof(tmp) << endl;
  for (int i = 0; i < array_width; i++) cout << tmp[i].re << " +j " << tmp[i].im << endl;
}

int main() {

  // datapoint x1[3];
  datapoint * x1;
  x1 = (datapoint *) malloc (width * sizeof(datapoint));

  x1[0].re = 2.0;
  x1[0].im = 3.0;
  x1[1].re = 4.0;
  x1[1].im = 5.0;
  x1[2].re = 6.0;
  x1[2].im = 7.0;

  PrintArray(&x1[0], width); // same as PrintArray(x1);

  datapoint x2;
  x2.re = 4.0;
  x2.im = 6.0;

  // PrintSingle(&x2);

  // datapoint *x3[2];
  // x3[0]->re = 2.1;
  // x3[0]->im = 3.1;
  // x3[1]->re = 4.1;
  // x3[1]->im = 5.1;

  struct datapoint *x4;
  x4 = &x2;
  x4->re = 4.1;
  x4->im = 6.1;
  // PrintSingle(x4);
  // cout << sizeof(x3);
  return 0;
}
