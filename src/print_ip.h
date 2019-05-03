#ifndef PRINT_IP_H_
#define PRINT_IP_H_

#include <type_traits>
#include <iostream>
#include <utility>



template<typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
output_ip(const T value)
{
  const size_t num_bytes = sizeof(T);

  for (size_t i = 0; i < num_bytes; ++i) {
    if (i != 0)
      std::cout << '.';

    unsigned offset = ((num_bytes - 1) - i) * 8;
    unsigned long o = (value & (static_cast<T>(0xFF) << offset)) >> offset;
    std::cout << o;
  }

  std::cout << "" << std::endl;
}


template<typename T>
void print_ip(T &&value) {
  output_ip(std::forward<T>(value));
}


#endif /* PRINT_IP_H_ */
