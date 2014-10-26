#include <iostream>
#include <fstream>
using namespace std;

typedef struct datapoint {
    double re;
    double im;
};

int print(datapoint * blah){

  cout << "Hallo Welt!" << endl;
  cout << blah->re << endl;
  cout << blah->im << endl;
}

int main() {
    datapoint data[2];
    data[0].re = 2.0;
    data[0].im = 3.0;
    data[1].re = 4.0;
    data[1].im = 5.0;

    cout << sizeof data << endl;

    ofstream out("numbers", ios::out | ios::binary);
    if (!out) {
        cout << "Cannot open file.";
        return 1;
    }

    out.write((char *) &data, sizeof data);

    out.close();

    datapoint x2[2];

    ifstream in("numbers", ios::in | ios::binary);
    if (!in) {
        cout << "Cannot open file.";
        return 1;
    }
    in.read((char *) &x2, sizeof x2);

    // see how many bytes have been read
    cout << in.gcount() << " bytes read\n";

    //XSfor (int i = 0; i < 2; i++) // show values read from file
      //      cout << x2[i].re << " " << x2[i].im << endl;
      print(x2);

    in.close();

    return 0;
}

