#include <iostream>
using namespace std;

class tx
{
public:
  void show(char *);
};

void tx::show (char* msg)
{
  cout << msg << endl;
}

int main()
{
  char * msg = "test";
  tx *trans = new tx ();
  trans->show(msg);
  delete trans;	
  return 0;
}
