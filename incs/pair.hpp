/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 22:37:36 by mda-silv          #+#    #+#             */
/*   Updated: 2022/01/09 22:16:18 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

// Reference 
// https://en.cppreference.com/w/cpp/utility/pair
// https://www.cplusplus.com/reference/utility/pair/?kw=pair

namespace ft {
    template <class T1, class T2> 
    class pair
    {
    public: 
        typedef T1 first_type;
        typedef T2 second_type;
        
        first_type first;
        second_type second;
        // Member functions
        pair() : first(), second() {}
        template< class U, class V >
        pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {}
        pair (const first_type& a, const second_type& b ) : first(a), second(b) {}
        // assigns the contents
        pair& operator=( pair const& pr) {
            first = pr.first; 
            second = pr.second; 
            return (*this);
        };    
    };
    //  Non-member functions
    template< class T1, class T2 >
    ft::pair<T1, T2> make_pair (T1 x, T2 y) { return (pair<T1, T2>(x, y));} 

    // Relational operator
    template <class T1, class T2>
    bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { 
        return (lhs.first == rhs.first && lhs.second == rhs.second); 
    }
	
    template <class T1, class T2>
    bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(lhs == rhs); }
    
    template <class T1, class T2>
    bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { 
        return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
    }
    
    template <class T1, class T2>
    bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(rhs < lhs); }
    
    template <class T1, class T2>
    bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (rhs<lhs);}
    
    template <class T1, class T2>
    bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(lhs<rhs); }
}

#endif