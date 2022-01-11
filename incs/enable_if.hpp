#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

// reference https://www.cplusplus.com/reference/type_traits/enable_if/?kw=enable_if

namespace ft {
    template<bool B, class T = void> 
    struct enable_if {};
	template<class T> struct enable_if<true, T> { typedef T type; };

    //template<bool Cond, class T = void> 
    //struct enable_if {};
    //template<class T> 
    //struct enable_if<true, T> { typedef T type; };
}

#endif