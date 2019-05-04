#ifndef PRINT_IP_H_
#define PRINT_IP_H_

#include <type_traits>
#include <iostream>
#include <utility>
#include <list>
#include <vector>


/** @brief IP in integral form.
 *  @tparam T - integral type.
 *  @param value[in] - ip-address value presented in the integral form. */
template<typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
output_ip(const T value)
{
  using unsigned_t = typename std::make_unsigned<T>::type;
  const size_t num_bytes = sizeof(T);

  for (size_t i = 0; i < num_bytes; ++i) {
    if (i != 0)
      std::cout << '.';

    unsigned offset = ((num_bytes - 1) - i) * 8;
    std::cout << ((value & (static_cast<unsigned_t>(0xFF) << offset))
                  >> offset);
  }
}

/** @brief IP in string form.
 *  @tparam T - 'std::string' type.
 *  @param str[in] - the ip-address value is represented as 'std::string'. */
template <typename T>
typename std::enable_if<std::is_same<std::string, T>::value, void>::type
output_ip(const T &str)
{
  std::cout << str;
}

/** @brief IP in container view.
 *  @tparam T - container type (vector/list).
 *  @param container[in] - ip-address value represented as a container. */
template<typename T>
typename std::enable_if<
  std::is_same<std::vector<typename T::value_type>, T>::value ||
  std::is_same<std::list<typename T::value_type>, T>::value, void>::type
output_ip(const T &container)
{
  for (auto it = container.begin(); it != container.end(); ++it) {
    if (it != container.begin())
      std::cout << '.';

    output_ip(*it);
  }
}

/** @brief Print argument as ip address.
 *  @tparam T - integral type or container or string types.
 *  @param value[in] - value that will be printed as ip-address. */
template<typename T>
void print_ip(T &&value)
{
  output_ip(std::forward<T>(value));
}


#endif /* PRINT_IP_H_ */
