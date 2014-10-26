#include <iostream>
using namespace std;

int multip (const int & x, int & y){

cout << "x= " << x << ",y= " << y << endl;
y = x*x;
cout << "x= " << x << ",y= " << y << endl;
return 1;
}


int main(){

int x = 3;
int y;
cout << "x= " << x << ",y= " << y << endl;
multip(x,y);
cout << "x= " << x << ",y= " << y << endl;
return 1;

}
