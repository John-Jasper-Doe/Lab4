/**
 ******************************************************************************
 * @file    main.cpp
 * @author  Maxim <aveter@bk.ru>
 * @date    04/05/2019
 * @brief   The main project file is "Print IP".
 ******************************************************************************
 */


#include "print_ip.h"


/**
 * @brief Main function / entry point.
 */
int main()
{
  output_ip(char(-1));
  std::cout << "" << std::endl;

  output_ip(short(0));
  std::cout << "" << std::endl;

  output_ip(int(2130706433));
  std::cout << "" << std::endl;

  output_ip(long(8875824491850138409));
  std::cout << "" << std::endl;

  output_ip(std::string{"192.168.200.10"});
  std::cout << "" << std::endl;

  /* void output_ip(const std::string &str) */
  output_ip(static_cast<const std::string>("192.168.200.11"));
  std::cout << "" << std::endl;

  output_ip(std::vector<char>{char(192), char(168), char(0), char(1)});
  std::cout << "" << std::endl;

  output_ip(std::list<char>{char(192), char(255), char(0), char(-1)});
  std::cout << "" << std::endl;

  return 0;
}
