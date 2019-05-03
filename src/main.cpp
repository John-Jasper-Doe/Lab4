//#include <iostream>
//#include <stdint.h>

#include "print_ip.h"

/* -------------------------------------------------------------------------- */
int main() 
{
  print_ip(char(-1));
  print_ip(short(0));
  print_ip(int(2130706433));
  print_ip(long(8875824491850138409));
//  std::string;
//  std::vector;
//  std::list;
//  std::tuple;

  return 0;
}
