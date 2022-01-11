/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:31:57 by mda-silv          #+#    #+#             */
/*   Updated: 2022/01/11 16:31:57 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"
/* Stacks are a type of container adaptor, specifically designed to operate in a
LIFO context (last-in first-out), where elements are inserted and extracted only
from one end of the container. */

namespace ft {
    template <class T, class Container = ft::vector<T> >
	class stack{
        // ########### Member Types ###########
    public:
            typedef T value_type;
            typedef Container container_type;
            typedef std::size_t size_type;
            // ########### Member Functions ###########
            // Constructor
            explicit stack( const container_type& ctnr = container_type()) : c(ctnr) { 
            }
            // Element Access
            value_type& top() { return (c.back()); }
            const value_type& top() const { return (c.back()); }
            
            // Capacity
            bool empty() const { return (c.empty()); }
            size_type size() const { return(c.size()); }
            // Modifiers
            void push ( const value_type& val) { c.push_back(val); }
            void pop() { c.pop_back(); }
        
            //  Member Objects
            
            template <typename U, typename C>
	        friend bool operator==(const stack<U, C>& lhs, const stack<U, C>& rhs);
	        template <typename U, typename C>
	        friend bool operator!=(const stack<U, C>& lhs, const stack<U, C>& rhs);
	        template <typename U, typename C>
	        friend bool operator<(const stack<U, C>& lhs, const stack<U, C>& rhs);
	        template <typename U, typename C>
	        friend bool operator<=(const stack<U, C>& lhs, const stack<U, C>& rhs);
	        template <typename U, typename C>
	        friend bool operator>(const stack<U, C>& lhs, const stack<U, C>& rhs);
	        template <typename U, typename C>
	        friend bool operator>=(const stack<U, C>& lhs, const stack<U, C>& rhs);
    
    protected :
        container_type c;
    };
    // ################ Non-member function overloads ################
    template <typename T, typename Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)	{ return (lhs.c == rhs.c); }
	template <typename T, typename Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)	{ return (lhs.c != rhs.c); }
	template <typename T, typename Container>
	bool operator< (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)	{ return (lhs.c < rhs.c); }
	template <typename T, typename Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)	{ return (lhs.c <= rhs.c); }
	template <typename T, typename Container>
	bool operator> (const stack<T,Container>& lhs, const stack<T,Container>& rhs)	{ return (lhs.c > rhs.c); }
	template <class T, class Container>
	bool operator>=(ft::stack<T,Container> const& lhs, ft::stack<T,Container> const& rhs)	{ return (lhs.c >= rhs.c); } 
}

#endif