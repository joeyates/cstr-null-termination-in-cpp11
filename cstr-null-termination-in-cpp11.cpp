#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main(int argc, char *argv[]) {
  string buildFromChars;
  buildFromChars.push_back('c');
  cout << "built from characters: " << strlen(buildFromChars.c_str()) << endl;

  string fromCharPointer = "Hello World";
  cout << "from char *: " << strlen(fromCharPointer.c_str()) << endl;

  return 0;
}

