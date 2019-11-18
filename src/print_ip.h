/**
 ******************************************************************************
 * @file    print_ip.h
 * @author  Maxim <aveter@bk.ru>
 * @date    18/11/2019
 * @brief   Template functions for printed
 ******************************************************************************
 */


#ifndef PRINT_IP_H_
#define PRINT_IP_H_


#include <type_traits>
#include <iostream>
#include <utility>
#include <list>
#include <vector>
#include <algorithm>
#include <tuple>


using namespace std::literals;


/**
 * @brief   Is not tuple type
 * @tparam  T - input type
 *
 * @details For any types other than "typle"
 */
template<typename T>
struct is_tuple : std::false_type {};


/**
 * @brief   Is tuple type
 * @tparam  T - input type
 *
 * @details This variadic templates for tuple.
 */
template<typename... T>
struct is_tuple<std::tuple<T...>> : std::true_type {};


/**
 * @brief   Is const tuple type
 * @tparam  T - input type
 *
 * @details This variadic templates for const tuple.
 */
template<typename... T>
struct is_tuple<const std::tuple<T...>> : std::true_type {};


/**
 * @brief   Print tuple
 * @tparam  TUPLE_TYPE - type of tuple
 * @tparam  SIZE - the number of parameters in the tuple
 *
 * @details A common template for outputting a tuple to the console.
 */
template<class TUPLE_TYPE, size_t... SIZE>
void print_tuple(const TUPLE_TYPE &value, std::index_sequence<SIZE...>) {
  (..., (std::cout << (SIZE == 0 ? "" : ".") << std::get<SIZE>(value)));
}

/**
 * @brief   Print tuple
 * @tparam  TUPLE_TYPE - type of tuple
 *
 * @details Initial function to enter template recursion.
 */
template<class... T>
void print_tuple(const std::tuple<T...>& value) {
  print_tuple(value, std::make_index_sequence<sizeof...(T)>());
}


/**
 * @brief   Output IP addres
 * @tparam  T - type of input
 * @param   [in] value - input data
 *
 * @details Template function for displaying heterogeneous values. The template
 *          is generated depending on the input data.
 */
template<typename T>
auto output_ip(T &&value) {
  if constexpr (std::is_integral_v<T>) { /* such as the char, short, int and etc ... */
    using unsigned_t = typename std::make_unsigned<T>::type;
    const size_t num_bytes = sizeof(T);

    for (size_t i = 0; i < num_bytes; ++i) {
      unsigned offset = ((num_bytes - 1) - i) * 8;
      std::cout << (i != 0 ? "."s : ""s) << ((value & (static_cast<unsigned_t>(0xFF) << offset)) >> offset);
    }
  }
  else if constexpr (is_tuple<T>::value) { /* ... for tuple ... */
    print_tuple(value);
  }
  else if constexpr (std::is_same<std::vector<typename T::value_type>, T>::value ||
                     std::is_same<std::list<typename T::value_type>, T>::value) { /* ... vector and list ... */
    std::for_each(std::begin(value), std::end(value), [&value](typename T::value_type &i) {
      std::cout << (((*std::begin(value)) == i) ? ""s : "."s);
      output_ip(std::move(i));
    });
  }
  else { /* ... other ... (std::string) */
    std::cout << value;
  }
}


#endif /* PRINT_IP_H_ */
