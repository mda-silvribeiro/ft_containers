/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 00:03:00 by mda-silv          #+#    #+#             */
/*   Updated: 2022/01/08 22:00:48 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

// Reference 
// https://www.cplusplus.com/reference/type_traits/integral_constant/?kw=integral_constant
// https://www.cplusplus.com/reference/type_traits/is_integral/?kw=is_integral

// fundamental integral types
// bool
// char
// char16_t C++11
// char32_t C++11
// wchar_t
// signed char
// short int
// int
// long int
// long long int
// unsigned char
// unsigned short int
// unsigned int
// unsigned long int
// unsigned long long int

namespace ft {
    template<class T, bool v>
	struct integral_constant
	{
		static const bool value = v;
		typedef T value_type;
		typedef integral_constant type;
		operator value_type() const { return value; }
	};
	
	template <class T> struct is_integral: public ft::integral_constant<T, false> {};
	template <> struct is_integral<bool>: public ft::integral_constant<bool, true> {};
	template <> struct is_integral<char>: public ft::integral_constant<bool, true> {};
	template <> struct is_integral<signed char>: public integral_constant<bool, true> {};
	template <> struct is_integral<unsigned char>: public integral_constant<bool, true> {};
	template <> struct is_integral<wchar_t>: public integral_constant<bool, true> {};
	template <> struct is_integral<short>: public integral_constant<bool, true> {};
	template <> struct is_integral<unsigned short>: public integral_constant<bool, true> {};
	template <> struct is_integral<int>: public integral_constant<bool, true> {};
	template <> struct is_integral<unsigned int>: public integral_constant<bool, true> {};
	template <> struct is_integral<long>: public integral_constant<bool, true> {};
	template <> struct is_integral<unsigned long>: public integral_constant<bool, true> {};
	template <> struct is_integral<long long>: public integral_constant<bool, true> {};
	template <> struct is_integral<unsigned long long>: public integral_constant<bool, true> {};
}

#endif