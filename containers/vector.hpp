/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 23:24:25 by mda-silv          #+#    #+#             */
/*   Updated: 2022/01/11 17:14:50 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "../incs/reverse_iterator.hpp"
#include "../incs/compare.hpp"
#include "../incs/enable_if.hpp"
#include "../incs/is_integral.hpp"
#include "../incs/iterator.hpp"
#include "../incs/iterator_traits.hpp"
#include "../incs/pair.hpp"
#include "../incs/utils.hpp"

#include <memory> // allocator
#include <iterator>
#include <cstddef>
#include <cstring>
#include <functional>
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <iostream>

// Reference https://en.cppreference.com/w/cpp/container/vector
namespace ft {
    template < class T, class Alloc = std::allocator<T> >
    class vector {
        // Member types
        public:
            typedef T                                           value_type;
            typedef Alloc                                       allocator_type;
            typedef typename Alloc::reference                   reference;
            typedef typename Alloc::const_reference             const_reference;
            typedef typename Alloc::pointer                     pointer;
            typedef typename Alloc::const_pointer               const_pointer;
            typedef ft::random_access<value_type>               iterator;
            typedef ft::random_access<value_type const>         const_iterator;
            typedef ft::reverse_iterator<iterator>              reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;
            typedef std::ptrdiff_t                              difference_type;
            typedef std::size_t                                 size_type;
        
        // Member functions
            // default constructor
            explicit vector( const allocator_type& alloc = allocator_type())
                : _alloc(alloc), _begin(NULL), _size(0), _capacity(0) {
                }
            
            // fill constructor, constructs a container with n elements. Each element is a copy of val.
            explicit vector(size_type n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type()) : _alloc(alloc) 
            {
                if (n > _alloc.max_size())
                    throw std::length_error("vector");
                _begin = _alloc.allocate( n );
                _capacity = n;
                for (size_type i = 0; i < n; i++) 
                    _alloc.construct(_begin + i, val);
                _size = n;
            }
            // range constructor 
            template< class InputIterator >
            vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
                typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL)
                : _alloc(alloc)
            {
                size_type aux = ft_distance(first, last);
                if (aux > _alloc.max_size())
                    throw std::length_error("vector");
                _begin = _alloc.allocate( aux );
                _capacity = aux;
                for (pointer i = _begin; first != last; i++, _size++) {
                    _alloc.constuctor(i, *first);
                    ++first;
                }
            }
            // Copy constructor
            vector (const vector& x) 
			{
                size_type n = x.size();
                pointer pos, pos_copy = x._begin;
                _begin = pos = _alloc.allocate(n);
                _size = n;
                _capacity = x.capacity();
                for (size_type i = 0; i < n; i++, pos++, pos_copy++){
                    _alloc.construct(pos, *(pos_copy));
                }
                //*this = x;
				//this->insert(this->begin(), x.begin(), x.end());
            }
            
            // Destructor 
            ~vector()
            {
                if (_begin != NULL) {
                    clear();
                    for (iterator it = begin(); it != end(); ++it )
                       _alloc.destroy(&(*it));
                    this->_alloc.deallocate(this->_begin, this->_capacity);
                    _size = 0;
                }
            }
            // Assignes new contents to the container, replacint its current contents,
            // and modifying its size accorddingly
            vector& operator=(const vector& x ) {
                if (this != &x) {
                    clear();
                    _alloc.deallocate(_begin, capacity());
                    _alloc = x.alloc;
                    _size = x.size();
                    _capacity = x.capacity();
                    _begin = _alloc.allocate(x.capacity());
                    for (size_type i = 0; i < x.size(); i++)
					    this->_alloc.construct(&this->_begin[i], x._begin[i]);
                    //reserve(x._size);
                    //assign(x.begin(), x.end());
                }
                return ( *this );
            }

            // ###################  Elements Access ###################
            reference at( size_type pos ) { 
                return !(pos < size()) ? throw std::out_of_range("vector") : (*(_begin + pos)); 
            };

            const_reference at( size_type pos ) const  {
                return !(pos < size()) ? throw std::out_of_range("vector") : (*(_begin + pos));
            };
            
            reference operator[](size_type pos) { return (*(_begin + pos )); }
            
            const_reference operator[](size_type pos ) const { return (*(_begin + pos )); }

            reference front() { return (*_begin); }
            
            const_reference front() const { return (*_begin); }
            // Access last element
            reference back() { return (*(_begin + (_size - 1))); }
            
            const_reference back() const { return (*(_begin + (_size - 1))); }
            
            // ###################  Iterators  ###################
            iterator begin() { return (iterator(_begin)); }

            const_iterator begin() const { return const_iterator(this->_begin);}

            iterator end() { return (empty() ? begin() : iterator(this->_begin + size() ));  }
            
            const_iterator end() const { return (empty() ? begin() :const_iterator(this->_begin + size())); }

            reverse_iterator rbegin() {  return (empty() ? rend() : reverse_iterator(this->_begin + _size)); }
            
            const_reverse_iterator rbegin() const { return (empty() ? rend() : const_reverse_iterator(this->_begin + _size )); }

            reverse_iterator rend() { return (reverse_iterator( this->_begin )); }
            
            const_reverse_iterator rend() const { return const_reverse_iterator( this->_begin ); }
            
            // ###################  Capacity  ###################
            bool empty() const { return (size() == 0); }
            
            size_type	size() const { return ( _size ); } 
            
            size_type max_size() const { return ( _alloc.max_size()); }

            size_type capacity() const { return ( _capacity); }

            // Request that the vector capacity be least enough to contain n elements.
            void reserve( size_type new_cap ) {
                if (new_cap > max_size())
                    throw std::length_error("vector");
                else if (new_cap > _capacity ) {
                    size_type   aux         = 0;
                    value_type* new_vec     = _alloc.allocate(new_cap);
                    pointer     end = _begin + _size;
                    pointer     aux_begin = _begin;
                    while(_begin != end) {
                        _alloc.construct(&new_vec[aux], *_begin++);
                        ++aux;
                    }
                    for(size_t i = 0; i < _size; i++)
                        _alloc.destroy(aux_begin + i);
                    _alloc.deallocate(aux_begin, _capacity);
                    _begin    = new_vec;
                    _capacity = new_cap;
                }
            } 
            
            //###################  Modifiers  ###################  
            //Replace the contents with copies of those in the range[ first, last]
            template< class InputIterator >
            void assign(InputIterator first,
			    	InputIterator last,
			    	typename ft::enable_if<!ft::is_integral<InputIterator>::value,
			    		InputIterator>::type* = NULL)
            {   
                size_type aux = static_cast<size_type>(ft::distance(first, last));
                if (aux >= 0 )
                {
                    clear();
                    reserve(aux);
                    insert(begin(), first, last);
                } 
            }
            
           void					assign(size_type n, const value_type& val)
		    {
				clear();
				if (n == 0)
					return ;
                else {
                    reserve(n);
                    insert(begin(), n, val);
                }
			}

            // Adds a new element at the end of vector.
            void push_back( const value_type& val ) {
                if (_size == _capacity)
                    reserve (_size == 0 ? 1 : _capacity * 2);
                _alloc.construct(&_begin[_size], val);
                _size++;
            }
            
            // Removes the last element of the container
            void pop_back() {
                _alloc.destroy(&back());
                _size--;
            }
            
            // single element
            iterator insert(iterator pos, const value_type& val) {
                pointer ret_pos = NULL;
                pointer tmp = _begin + _size;
                size_type len = pos.get() - _begin;
                size_type new_size = size();
                if (_capacity == _size)
                    reserve(new_size > 0 ? capacity() * 2 : 1);
                ret_pos = _begin + len;
                if (new_size > 0) {
                    for(pointer i = tmp; i >= ret_pos; i--)
                        _alloc.construct(i + 1, *i);
                }
                _alloc.construct(ret_pos, val);
                _size++;
                return (iterator(ret_pos));
            }

            // Fill
            // Inserts count copies of the value before pos
            void insert(iterator pos, size_type n, const value_type& val) {
                if (n != 0) {
                    pointer ret_pos = NULL;
                    pointer tmp = _begin + _size -1;
                    size_type len = pos.get() - _begin;
                    size_type new_size = size();

                    if ( n + _size > _capacity ) 
                        reserve(std::max(new_size + n, capacity() * 2));
                    ret_pos = _begin + len;
                    if ( new_size > 0 )
                        for (pointer i = tmp; i >= ret_pos; i--)
                           _alloc.construct(i + n, *i);
                    for (size_type i = 0; i < n; i++ )
                        _alloc.construct( ret_pos + i, val );
                    _size += n;
                }
            }

            // range
            // Inserts elements from rang[first, last] before position.
            template < class InputIterator >
            void insert( iterator pos, InputIterator first, InputIterator last, 
                        typename ft::enable_if<!ft::is_integral<InputIterator>::value,
                            InputIterator>::type* = NULL) 
            {
                if (first != last ) {
                    size_type aux = static_cast<size_type>(ft::distance(first, last));
                    //difference_type	distance = ft::distance(first, last);
                    pointer tmp = _begin + _size;
                    pointer ret_pos = NULL;
                    pointer new_beg = _alloc.allocate(aux);
                    // pointer new_end = new_beg;
                    size_type new_size = this->_size;
                    size_type len_pos = pos._ptr - _begin;
                    //iterator aux2 = new_beg;

                    //while( distance--) {
                     //   _alloc.construct(&*aux2++, *first++);
                    //}
//
                    if ( _size + aux > _capacity )
                       reserve( std::max(capacity() + aux, capacity() * 2));
                    ret_pos = _begin + len_pos;
                    if (new_size > 0 ) 
                       for ( pointer i = tmp - 1; i >= ret_pos; i-- )
                            _alloc.construct(i + aux, *i);
                    for (size_type i = 0; i < aux; i++) {
                        if ( i < new_size - len_pos ) {
                            _alloc.destroy(ret_pos + i);
                            _alloc.construct(ret_pos + i, *(new_beg + i ));
                        }
                        else
                            _alloc.construct(ret_pos + i, *(new_beg + i ));
                    }
                    _size += aux;
                    for (size_type i = 0; i < aux; i++)
                        _alloc.destroy(new_beg + i);
                    _alloc.deallocate(new_beg, aux);
                }
                
            };
            // resizes the container so that it contains n elements
            // n new size of the container
            // val the value to initialize the new elements with
            void resize( size_type n, value_type val = value_type()) {
                size_type aux = n;
                size_type i = 0;
                if (n > _alloc.max_size())
                    throw std::length_error("vector");
                // if the currenct size is greater than n, the conteiner is reduced to it first n elements
                else if (n < _size) {
                    while (aux < _size)
					{
						aux++;
                        i++;
						_alloc.destroy(&_begin[i]);
					}
                    _size = n;
                }
                else {
                    reserve(n);
                    insert(end(), n - _size, val);
                }
            }
            
            iterator erase( iterator pos ) {
                pointer tmp = _begin + _capacity;
                pointer position = pos._ptr;
                size_type s = static_cast<size_type>((tmp - &*pos - 1) * sizeof(value_type)) ;
                _alloc.destroy(&*pos);
                std::memmove(position, position + 1, s);
                _size--;
                return(iterator(position)); 
            }

            iterator    erase( iterator first, iterator last ) {
                pointer tmp = _begin + _capacity;
                difference_type distance = ft::distance(first, last);
                pointer first_aux = first._ptr;
                size_type s = static_cast<size_type>((tmp - last._ptr) * sizeof(value_type));
                
                if (first_aux != last._ptr) {
                    for(iterator it = first_aux; it + distance != end(); it++)
                        _alloc.destroy(&*(it + distance));
                    std::memmove(first_aux, last._ptr, s);
                }
                _size -= distance;
                return (iterator(first_aux)); 
            }
            
            void swap( vector & other ) {
                if ( this != &other ) {
                    pointer tmp = _begin;
                    _begin = other._begin;
                    other._begin = tmp;

                    size_type tmp_n = _size;
                    _size = other._size;
                    other._size = tmp_n;

                    tmp_n = _capacity;
                    _capacity = other._capacity;
                    other._capacity = tmp_n;
                }
            } 
            
            void    clear() {
			    while(!empty())
                    pop_back();
			}
            
            allocator_type  get_allocator() const { return (_alloc); }
            
        private:
            allocator_type  _alloc;
            pointer         _begin;
            size_type       _size;
            size_type       _capacity;
    };
    // ########################## Non-member functions ##########################
    
    template <class T, class Alloc>
    bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return (lhs.size() != rhs.size() ? 0 : equal(lhs.begin(), lhs.begin(), rhs.begin()));
    };
  	
    template <class T, class Alloc>
    bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return(!(lhs == rhs)); };
	
    template <class T, class Alloc>
    bool operator<(vector<T,Alloc> const &lhs, vector<T,Alloc> const &rhs) { 
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    };
    
    template <class T, class Alloc>
    bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(rhs < lhs)); };
	
    template <class T, class Alloc>
    bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (rhs < lhs ); };
	
    template<class T, class Alloc>
	bool
	operator>=(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs)
	{
        
		return !(lhs < rhs);
	}

    template <class T, class Alloc>
    void swap(vector<T,Alloc>& lhs, vector<T,Alloc>& rhs) { lhs.swap(rhs); }
}

#endif