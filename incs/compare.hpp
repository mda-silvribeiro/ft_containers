/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 00:05:34 by mda-silv          #+#    #+#             */
/*   Updated: 2022/01/05 02:06:05 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPARE_HPP
# define COMPARE_HPP

// reference 
// https://www.cplusplus.com/reference/algorithm/equal/?kw=equal
// https://en.cppreference.com/w/cpp/algorithm/equal
// https://www.cplusplus.com/reference/algorithm/lexicographical_compare/
// https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare
// https://en.cppreference.com/w/cpp/iterator/distance

#include "iterator_traits.hpp"
#include <iterator>

namespace ft {
    // Equality (1)
    template <class InputIterator1, class InputIterator2>
    bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
    {
        while (first1!=last1) {
            if (!(*first1 == *first2))
                return (false);
            ++first1; ++first2;
        }   
        return (true);
    };
    // Predicate
    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool equal (InputIterator1 first1, InputIterator1 last1, 
                    InputIterator2 first2, BinaryPredicate pred) 
    {
         while (first1!=last1) {
            if (!pred(*first1,*first2))
                return (false);
            ++first1; ++first2;
        }   
        return (true);                 
    };
    

    template<class InputIterator1, class InputIterator2>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
	while (first1 != last1) {
		if (first2 == last2 || *first2 < *first1)
			return (false);
		else if (*first1 < *first2)
			return (true);
		++first1;
		++first2;
	}
	    return (first2 != last2);
    }

    // Default 
   // template <class InputIterator1, class InputIterator2>
   // bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
   //                             InputIterator2 first2, InputIterator2 last2) 
   // {
   //     std::cout << *first1 << *last1 << std::endl;
   //     std::cout << *first2 << *last2 << std::endl;
   //     while (first1!=last1) {
   //           if (first2==last2 || *first2 < *first1) 
   //               return (false);
   //          else if (*first1 < *first2) 
   //               return (true);
   //           first1++; 
   //           first2++;
   //      }
   //     return (first2!=last2);
   // };


    // Custom 
    // template <class InputIterator1, class InputIterator2, class Compare>
    // bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
    //                                 InputIterator2 first2, InputIterator2 last2,
    //                                 Compare comp)
    // {
    //     while (first1!=last1)
    //     {
    //         if (first2==last2 || comp(*first2, *first1))
    //             return (false);
    //         else if (comp(*first1, *first2)) 
    //             return (true);
    //         ++first1; 
    //         ++first2;
    //     }
    //     return (first2!=last2);
    // };

    // Distance 
    template<class It>
    typename ft::iterator_traits<It>::difference_type 
        distance(It first, It last, std::input_iterator_tag)
    {
        typename std::iterator_traits<It>::difference_type result = 0;
        while (first != last) {
            ++first;
            ++result;
        }
        return result;
    }
    
    //template<class It>
    //typename ft::iterator_traits<It>::difference_type 
     //   distance(It first, It last, std::random_access_iterator_tag)
    //{
      //  return last - first;
    //}
    
    // namespace detail
    
    template<class It>
    typename ft::iterator_traits<It>::difference_type distance(It first, It last)
    {
        return ft::distance(first, last,
                                   typename std::iterator_traits<It>::iterator_category());
    }
        
    }

#endif