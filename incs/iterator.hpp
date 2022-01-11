/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:15:23 by mda-silv          #+#    #+#             */
/*   Updated: 2021/12/15 23:28:22 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <cstddef> // ptrdiff_t => signed integer type returned when subtracting two pointers
// #Reference https://www.cplusplus.com/reference/iterator/iterator/

namespace ft {
    template <typename Category, typename T, typename Distance = ptrdiff_t, typename Pointer = T*, typename Reference = T& > 
    // iterator::iterator_category, iterator::value_type, iterator::difference_type, iterator::pointer, iterator::reference                  
   
    struct iterator {
        typedef T         value_type;
        typedef Distance  difference_type;
        typedef Pointer   pointer;
        typedef Reference reference;
        typedef Category  iterator_category;
    };
}

#endif