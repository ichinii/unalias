#ifndef UNALIAS_HPP
#define UNALIAS_HPP

#define COUNTER_READ_CRUMB( TAG, RANK, ACC ) counter_crumb( TAG(), constant_index< RANK >(), constant_index< ACC >() )
#define COUNTER_READ( TAG ) COUNTER_READ_CRUMB( TAG, 1, COUNTER_READ_CRUMB( TAG, 2, COUNTER_READ_CRUMB( TAG, 4, COUNTER_READ_CRUMB( TAG, 8, \
    COUNTER_READ_CRUMB( TAG, 16, COUNTER_READ_CRUMB( TAG, 32, COUNTER_READ_CRUMB( TAG, 64, COUNTER_READ_CRUMB( TAG, 128, 0 ) ) ) ) ) ) ) )
 
#define COUNTER_INC( TAG ) \
constant_index< COUNTER_READ( TAG ) + 1 > \
constexpr counter_crumb( TAG, constant_index< ( COUNTER_READ( TAG ) + 1 ) & ~ COUNTER_READ( TAG ) >, \
          					constant_index< ( COUNTER_READ( TAG ) + 1 ) & COUNTER_READ( TAG ) > ) { return {}; }
 
#define COUNTER_LINK_NAMESPACE( NS ) using NS::counter_crumb;
 
#include <utility>
 
template< std::size_t n >
struct constant_index : std::integral_constant< std::size_t, n > {};
 
template< typename id, std::size_t rank, std::size_t acc >
constexpr constant_index< acc > counter_crumb( id, constant_index< rank >, constant_index< acc > ) { return {}; } // found by ADL via constant_index

/* 
 * The above code is complete madness posted by Potatoswatter on stackoverflow.com
 * https://stackoverflow.com/questions/6166337/does-c-support-compile-time-counters
 */

#include <type_traits>

template <typename T, std::size_t>
struct unalias_fundamental {
  T value;

  unalias_fundamental(T value) : value(value) {}

  operator T() { return value; }

  // TODO: add all kinds of operators
};

template <typename T, std::size_t>
struct unalias_not_fundamental : T {};

template <typename T, std::size_t I>
struct unalias {
  using type = std::conditional_t< std::is_fundamental_v<T>,
    unalias_fundamental<T, I>,
    unalias_not_fundamental<T, I>>;
};

template <typename T, std::size_t I>
using unalias_t = typename unalias<T, I>::type;

template <typename T>
struct unalias_counter {};

#define UNALIAS(T) \
  unalias_t< T, COUNTER_READ(unalias_counter< T >) >; \
  COUNTER_INC(unalias_counter< T >)

#endif
