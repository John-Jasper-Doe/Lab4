//#include <iostream>
//#include <stdint.h>

#include "print_ip.h"

/* -------------------------------------------------------------------------- */
int main() 
{
  print_ip(char(-1));
  std::cout << "" << std::endl;

  print_ip(short(0));
  std::cout << "" << std::endl;

  print_ip(int(2130706433));
  std::cout << "" << std::endl;

  print_ip(long(8875824491850138409));
  std::cout << "" << std::endl;

  print_ip(std::string {"192.168.200.10"});
  std::cout << "" << std::endl;

  print_ip(std::vector<char>{char(192), char(168), char(0), char(1)});
  std::cout << "" << std::endl;

  print_ip(std::list<char>{char(192), char(255), char(0), char(-1)});
  std::cout << "" << std::endl;
  //  std::tuple;

  return 0;
}
