/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 22:21:51 by mda-silv          #+#    #+#             */
/*   Updated: 2022/01/09 20:11:43 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "iterator.hpp"

// References
// https://www.cplusplus.com/reference/iterator/reverse_iterator/
// https://en.cppreference.com/w/cpp/iterator/reverse_iterator
// https://en.cppreference.com/w/cpp/iterator/reverse_iterator/reverse_iterator
// I don't use the model bidirectional_iterator because it's since C++20

namespace ft {
    template <class Iter> 
    class reverse_iterator {
        // Member Types until C++20
        public:
            typedef Iter iterator_type;
            typedef typename iterator_traits<Iter>::iterator_category   iterator_category;
            typedef typename iterator_traits<Iter>::value_type          value_type;
            typedef typename iterator_traits<Iter>::difference_type     difference_type;
            typedef typename iterator_traits<Iter>::pointer             pointer;
            typedef typename iterator_traits<Iter>::reference           reference;

        // Member Functions (until C++17)
            // the internal base iterator is value-initialized
            reverse_iterator() : current(iterator_type()) {}
            explicit reverse_iterator( iterator_type x ) : current(x){};
            // Copy / type-cast constructor
            template< class U>
            reverse_iterator( const reverse_iterator<U>& rev_it ) : current(rev_it.base()){}
            ~reverse_iterator(){}

            iterator_type base() const { return current; }
            //  Assignement
            template< class U >
            reverse_iterator& operator=( const reverse_iterator<U>& other ) { 
                if (this == &other )
                    return *this;
                current = other.current;
                return *this;
            }
            // Deference iterator
            // return a reference or pointer to the element previous to current
            reference operator*() const { iterator_type tmp = current; return (*--tmp);}
            pointer operator->() const {return &(operator*());}
            // Deference iterator with offset
            reference operator[]( difference_type n ) const { return (current[-n - 1]);  }

            // Advances or Decrements the iterator
            // Pre-increments or pre decrements by one respectively
            reverse_iterator& operator++() {--current; return *this;}
            reverse_iterator& operator--() {current; return *this;}

            // Post-increments or Post-decrements by one respectively
            reverse_iterator operator++(int) { reverse_iterator<Iter> temp(*this); --current; return(temp); }
            reverse_iterator operator--(int) { reverse_iterator<Iter> temp(*this); ++current; return(temp); }

            //  Returns an iterator which is advanced by n or -n positions respectively
            reverse_iterator operator+(difference_type n ) const { return reverse_iterator(current - n);}
            reverse_iterator operator-(difference_type n ) const { return reverse_iterator(current + n);}

            // Advances the iterator by n or -n positions respectively
            reverse_iterator& operator+=( difference_type n ) { current -= n; return (*this);}
            reverse_iterator& operator-=( difference_type n ) { current += n; return (*this);}

        protected :
        //  Member Object
            Iter current;
        };

    // Non-members functions overloads
    //  Compares the underlying iterators
    template <class Iterator>
    bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.base() == rhs.base()); }
    
    template <class Iterator>
    bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.base() != rhs.base()); }
    
    template <class Iterator>
    bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.base() > rhs.base()); }
    
    template <class Iterator>
    bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.base() >= rhs.base()); }
	
    template <class Iterator>
    bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.base() <  rhs.base()); }
	
    template <class Iterator>
    bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.base() <= rhs.base()); }

    template< class Iterator >
    reverse_iterator<Iterator> operator+( typename reverse_iterator<Iterator>::difference_type n, 
                                            const reverse_iterator<Iterator>& rev_it ) { return (reverse_iterator<Iterator>(rev_it.base() - n)); }
    
    template< class Iterator >
    typename reverse_iterator<Iterator>::diferrence_type operator-( 
                        const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (rhs.base() - lhs.base()); }
}

#endif