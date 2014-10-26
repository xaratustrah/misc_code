#include <iostream>
#include <cstring>

using namespace std;

int main (int argc, char * argv[])
{
  for (int i = 0; i < argc ; i++)
    {
      cout << (argv[i]) << endl;
      if(!strcmp(argv[i],"asd")) cout << endl << endl << "bingo!" << endl << endl;
    }
  return 0;
}
