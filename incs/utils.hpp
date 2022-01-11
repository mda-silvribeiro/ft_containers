/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 01:51:07 by mda-silv          #+#    #+#             */
/*   Updated: 2022/01/11 17:25:22 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include "../incs/iterator.hpp"
#include "../incs/iterator_traits.hpp"

namespace ft {
    template< typename U >
    class random_access  {
        public :
            // Members types
            typedef U iter_value;
            typedef U								value_type;
		    typedef value_type&						reference;
		    typedef value_type*						pointer;
		    typedef value_type const&				const_reference;
		    typedef value_type const*				const_pointer;

		    typedef typename std::ptrdiff_t			difference_type;
		    typedef std::random_access_iterator_tag	iterator_category;

            pointer _ptr;
        
            // typedef U iter_value;
            // typedef typename    iterator_traits<U>::difference_type      difference_type; 
            // typedef typename    iterator_traits<U>::value_type           value_type;      
            // typedef typename    iterator_traits<U>::pointer              pointer;         
            // typedef typename    iterator_traits<U>::reference            reference;       
            // typedef             std::random_access_iterator_tag              iterator_category;
            
            random_access() : _ptr(NULL) {}
            random_access( pointer iter ) : _ptr(iter){}
            random_access( random_access const& rhs ) : _ptr(rhs._ptr) { }
            ~random_access( void ) {}

            // Members Functions
            // Operators
            template< class T >
            random_access& operator=( const random_access<T>& rhs ) {
                if ( this == &rhs )
                    return ( *this );
                this->_ptr = rhs.base();
                return *this;
            }

            random_access& operator++() { this->_ptr++; return (*this); }

            random_access operator++(int) { 
                random_access tmp(*this);
                _ptr++;
                return (tmp);
            }

            random_access& operator--() { this->_ptr--; return (*this); }

            random_access operator--(int) { 
                random_access tmp(*this);
                _ptr--;
                return (tmp);
            }

            random_access operator+( difference_type n ) const {
                random_access aux(*this);
                aux += n;
                return ( aux );
            }

            random_access& operator+=(difference_type i ) {
                this->_ptr += i;
                return ( *this );
            }

            random_access operator-(difference_type i ) const { return (*this + (-i)); }
            random_access operator-=(difference_type i ) { 
                this->_ptr -= i;
                return ( *this );
            }
            reference operator[](int i ) const{ return (this->_ptr[i]);}
            reference operator*() const { return *this->_ptr; }
            pointer operator->() { return this->_ptr; }
            pointer get(){return this->_ptr;}

            // Relational Operators
            operator random_access<value_type const>() const
		    {
			    return random_access<value_type const>(_ptr);
		    }    

		    bool operator==(random_access const& rhs) const { return (_ptr == rhs._ptr); }
    
		    template<typename iterator, typename iterator2>
		    friend bool operator==(ft::random_access<iterator> const& lhs, ft::random_access<iterator2> const& rhs);
    
		    bool operator!=(random_access const& rhs) const { return _ptr != rhs._ptr; }
    
		    template<typename iterator, typename iterator2>
		    friend bool operator!=(ft::random_access<iterator> const& lhs, ft::random_access<iterator2> const& rhs);
    
		    bool operator<(random_access const& rhs) const { return _ptr < rhs._ptr; }
    
		    template<typename iterator, typename iterator2>
		    friend bool operator<(ft::random_access<iterator> const& lhs, ft::random_access<iterator2> const& rhs);
    
		    bool operator>(random_access const& rhs) const { return _ptr > rhs._ptr; }
    
		    template<typename iterator, typename iterator2>
		    friend bool
		    operator>(ft::random_access<iterator> const& lhs, ft::random_access<iterator2> const& rhs);
    
		    bool operator<=(random_access const& rhs) const { return _ptr <= rhs._ptr; }
    
		    template<typename iterator, typename iterator2>
		    friend bool operator<=(ft::random_access<iterator> const& lhs, ft::random_access<iterator2> const& rhs);
    
		    bool operator>=(random_access const& rhs) const { return _ptr >= rhs._ptr; }
    
		    template<typename iterator, typename iterator2>
		    friend bool operator>=(ft::random_access<iterator> const& lhs, ft::random_access<iterator2> const& rhs);

        };
            // Non-members functions overloads
             //  Compares the underlying iterators
            template <class Iterator, class Iterator2>
            bool operator==(const ft::random_access<Iterator>& lhs, const ft::random_access<Iterator2>& rhs) { return (lhs.base() == rhs.base()); }

            template <class Iterator, class Iterator2>
            bool operator!=(const ft::random_access<Iterator>& lhs, const ft::random_access<Iterator2>& rhs) { return (lhs.base() != rhs.base()); }

            template <class Iterator, class Iterator2>
            bool operator<(const ft::random_access<Iterator>& lhs, const ft::random_access<Iterator2>& rhs) { return (lhs.base() < rhs.base()); }

            template <class Iterator, class Iterator2>
            bool operator<=(const ft::random_access<Iterator>& lhs, const ft::random_access<Iterator2>& rhs) { return (lhs.base() <= rhs.base()); }

            template <class Iterator, class Iterator2>
            bool operator>(const ft::random_access<Iterator>& lhs, const ft::random_access<Iterator2>& rhs) { return (lhs.base() > rhs.base()); }

            template <class Iterator, class Iterator2>
            bool operator>=(const ft::random_access<Iterator>& lhs, const ft::random_access<Iterator2>& rhs) { return (lhs.base() >= rhs.base()); }

        template<class iterator>
	    ft::random_access<iterator>
	    operator+(typename ft::random_access<iterator>::difference_type n,
	    			ft::random_access<iterator> const& rhs) { return rhs.base() + n.base(); }
        
        template<class iterator>
	    ft::random_access<iterator>
	    operator-(typename ft::random_access<iterator>::difference_type n,
	    			ft::random_access<iterator> const& rhs) { return n.base() - rhs.base() ; }
};

#endif