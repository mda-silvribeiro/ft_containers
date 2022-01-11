/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:04:53 by mda-silv          #+#    #+#             */
/*   Updated: 2022/01/10 23:05:29 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

#include <iterator>
#include <cstddef> // ptrdiff_t => signed integer type returned when subtracting two pointers

// #Reference https://www.cplusplus.com/reference/iterator/iterator_traits/

//Iterator traits
//Traits class defining properties of iterators.
//Standard algorithms determine certain properties of the iterators 
//passed to them and the range they represent by using the members of
// the corresponding iterator_traits instantiation.
// For every iterator type, a corresponding specialization of iterator_traits
// class template shall be defined, with at least the following member types defined:

namespace ft {
    // Generic definition
    template <class Iterator> 
    struct iterator_traits {
    public:
        typedef typename    Iterator::difference_type       difference_type;    //  Type to express the result of subtracting one iterator from another.
        typedef typename    Iterator::value_type            value_type;         //  The type of the element the iterator can point to.
        typedef typename    Iterator::pointer               pointer;            //  The type of a pointer to an element the iterator can point to. 
        typedef typename    Iterator::reference             reference;          //  The type of a reference to an element the iterator can point to.
        typedef typename    Iterator::iterator_category     iterator_category;  //  The iterator category.
    };
    //  Specialized for pointers (T*)
    template <class T> 
    struct iterator_traits<T*> {
    public:
        typedef ptrdiff_t   difference_type;  
        typedef T   value_type;       
        typedef T*  pointer;          
        typedef T&  reference;        
        typedef std::random_access_iterator_tag  iterator_category;
    };
    // pointers to const (const T*)
    template <class T>
    struct iterator_traits<const T*> {
    public:
        typedef ptrdiff_t   difference_type;  
        typedef T   value_type;       
        typedef T   const*  pointer;          
        typedef T   const&  reference;        
        typedef std::random_access_iterator_tag  iterator_category;

    };
}
# endif