#include <iostream>
#include <string>
#include <string.h>

int main(int argc, char *argv[]) {
  std::string s = "Hello World";
  std::cout << strlen(s.c_str()) << std::endl;

  return 0;
}

