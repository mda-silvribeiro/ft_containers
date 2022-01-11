/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:59:28 by mda-silv          #+#    #+#             */
/*   Updated: 2022/01/11 14:28:17 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "../incs/enable_if.hpp"
#include "../incs/is_integral.hpp"
#include "../incs/utils.hpp"
#include "../incs/iterator.hpp"
#include "../incs/iterator_traits.hpp"
#include "../incs/red_black_tree.hpp"
#include "../incs/pair.hpp"
#include "../incs/reverse_iterator.hpp"

namespace ft {
    template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< pair<const Key,T> > >
    class map {
        public :
            // ################# Member types #################
            typedef Key key_type; // map::key_type
            typedef T mapped_type; // // map::mapped_type
            typedef pair< const key_type, mapped_type> value_type;  // map::allocator_type
            typedef Compare key_compare; // map::key_compare
            
            //Returns a comparison object that can be used to compare two elements to get
            // whether the key of the first one goes before the second.
            // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
            class value_compare : std::binary_function<value_type, value_type, bool>
            {
                friend class map;
                protected:
                    Compare comp;
                    value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
                public:
                    typedef bool result_type;
                    typedef value_type first_argument_type;
                    typedef value_type second_argument_type;
                    result_type operator() (const value_type& x, const value_type& y) const
                    {
                      return comp(x.first, y.first);
                    }
            };
            
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef typename ft::node<value_type> node;
            typedef typename ft::red_black_tree<value_type, value_compare, allocator_type> rbtree;
            typedef node* node_ptr;
            typedef red_black_tree_iterator<node_ptr, pointer> iterator;
            typedef red_black_tree_iterator<node_ptr, const_pointer> const_iterator;
            typedef typename ft::reverse_iterator<iterator> reverse_iterator;
            typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
            typedef typename iterator_traits<iterator>::difference_type difference_type;
            typedef size_t size_type;
            
            // Member functions
            // empty (1)
            explicit map (const key_compare& comp = key_compare(),
                            const allocator_type& alloc = allocator_type()) :
                            _rbtree(value_compare(comp), alloc), _alloc(alloc), _comp(comp) { }    
            
            // range (2)	
            template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
                    const allocator_type& alloc = allocator_type()) : _rbtree(value_compare(comp), alloc),  _alloc(alloc), _comp(comp)
		    {
			    this->insert(first, last);
		    }
		
            //copy (3)	
            map (const map& x) : _rbtree(x._rbtree),  _alloc(x._alloc), _comp(x._comp)
		    {
			    *this = x;
		    }

            ~map() { }

            map& operator=( const map& cmp ) {
                if (this == &cmp)
                    return (*this);
                if (this != &cmp) {
                    clear();
                    _alloc = cmp._alloc;
                    _comp = cmp._comp;
                    insert(cmp.begin(), cmp.end());
                }
                return (*this);
            }

            allocator_type get_allocator() const {
                return _alloc;
            }

            // Element access
            mapped_type& operator[] (const key_type& key) {
                iterator it = find(key);
                // If k matches the key of an element in the container,
                // the function returns a reference to its mapped value.
                if (it == end())
                    return insert(value_type(key, mapped_type())).first->second;
				return it->second;
                // If k does not match the key of any element in the container,
                // the function inserts a new element with that key and returns
                // a reference to its mapped value.
                // return (*((insert(make_pair(key, mapped_type()))).first)).second;
            }
            

            // Iterators
            iterator begin() { return iterator(_rbtree.begin()); }
            const_iterator begin() const { return const_iterator(_rbtree.begin()); }
            iterator end() { return iterator(_rbtree.end()); }
            const_iterator end() const { return const_iterator(_rbtree.end()); }
            reverse_iterator rbegin() { return reverse_iterator( end()); }
            const_reverse_iterator rbegin() const { return (const_reverse_iterator(end())); }
            reverse_iterator rend() { return (reverse_iterator(begin())); }
            const_reverse_iterator rend() const { return (const_reverse_iterator(begin())); }

            // Capacity
            bool empty() const { return size() == 0; }
            size_type size() const { return this->_rbtree.size(); }
            size_type max_size() const
		    {
			    return (std::min<size_type>(this->_alloc.max_size(),
                                    std::numeric_limits<difference_type>::max()));
		    }

            // Modifiers
            void clear()
            {
			    _rbtree.clear();
		    }
            // insert
            // single element (1)	
            pair<iterator,bool> insert(const value_type& val) {
                iterator ret = find(val.first);
                //set to true if a new element was inserted
                if (ret == end()) {
                    _rbtree.insert(val);
                    ret = find(val.first);
                    return (pair<iterator, bool>(ret, true));
                }
                // or false if an equivalent key already existed.
                return (pair<iterator, bool>(ret, false));
            }
            // with hint (2)
            // hint (pos) -> iterator, used as a suggestion as to where to start the search
            iterator insert (iterator pos, const value_type& val) {
                pos = find(val.first);
                // Returns an iterator to the inserted element
                if (pos != end())
                    return(pos);
                insert(val);
                // or to the element that prevented the insertion
                return ( find(val.first) );
            }
            
            // range (3)
            // Inserts elements from range [first, last). 	
            template <class InputIterator>
            void insert (InputIterator first, InputIterator last,
                            typename enable_if<!is_integral<InputIterator>::value, bool>::type = 0)
            {
                  
				if (first == last)
					return ;
				for (; first != last; first++)
				    insert(*first);
            }

            // erase
            // Removes the element at pos
            void erase(iterator pos) {
                if (find((*pos).first) != end())
                    _rbtree.erase(*pos);
            }
            
            // Removes the element (if one exists) with the key equivalent to key.
            size_type erase(const key_type& k) {
                iterator aux = find(k);
                // ret Number of elements removed (0 or 1).
                if (aux != end()) {
                    erase(aux);
                    return (1);
                }
                return (0);
            }
            // range
            void erase (iterator first, iterator last) {
                for (; first != last;)
					erase(first++);
            }
            
            // Exchanges the content of the container by the content of other.
            void swap( map& other ) {
                _rbtree.swap(other._rbtree);
                std::swap(_comp, other._comp);
                std::swap(_alloc, other._alloc);
            }

            // Lookup
            iterator find (const key_type& k) {
                node_ptr ret = _rbtree.find(ft::make_pair(k, mapped_type()));
                // An iterator to the element, if an element with specified key 
                // is found, or map::end otherwise.
                return (ret == nullptr ? this->end() : iterator(ret));   
            }
            
            const_iterator find (const key_type& k) const {
                node_ptr ret = _rbtree.find(ft::make_pair(k, mapped_type()));
                return (ret == nullptr ? end() : const_iterator(ret));  
            }
            // Searches the container for elements with a key equivalent to k 
            // and returns the number of matches.
            size_type count( const Key& key ) const {
                // Because all elements in a map container are unique, the function
                // can only return 1 (if the element is found) or zero (otherwise).
                return  (find(key) != end());
            }
            // Get range of equal elements
            pair<const_iterator,const_iterator> equal_range(const key_type& k) const {
                return pair<const_iterator,const_iterator>(lower_bound(k), upper_bound(k));
            }
            
            pair<iterator,iterator>             equal_range(const key_type& k) {
                return pair<iterator,iterator>(lower_bound(k), upper_bound(k));
            }
            
            // Iterator pointing to the first element that is not less than key.
            // If no such element is found, a past-the-end iterator (see end()) is returned.
            iterator lower_bound(const key_type& k) {
                return _rbtree.lower_bound(make_pair(k, mapped_type()));
            }
            
            const_iterator lower_bound(const key_type& k) const {
                return _rbtree.lower_bound(make_pair(k, mapped_type()));
            }
            
            // Returns an iterator pointing to the first element that is greater than key.
            iterator upper_bound(const key_type& k)
		    {
			    return _rbtree.upper_bound(make_pair(k, mapped_type()));
		    }

		    const_iterator upper_bound(const key_type& k) const
		    {
			    return _rbtree.upper_bound(make_pair(k, mapped_type()));
		    }

            // Observers
            key_compare key_comp() const { return _comp; }

            value_compare value_comp() const { return value_compare(_comp); }

        private:
            rbtree _rbtree;
            allocator_type _alloc;
            key_compare _comp;   
    };
    // Non-member functions
    template <typename T, typename Alloc>
	bool operator== (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)	{ return (lhs.size() == rhs.size() && equal(lhs.begin(), lhs.end(), rhs.begin())); }
	template <typename T, typename Alloc>
	bool operator!= (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)	{ return (!(lhs == rhs)); }
	template <typename T, typename Alloc>
	bool operator< (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)	{ return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }
	template <typename T, typename Alloc>
	bool operator<= (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)	{ return (!(rhs < lhs)); }
	template <typename T, typename Alloc>
	bool operator> (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)	{ return (rhs < lhs); }
	template <typename T, typename Alloc>
	bool operator>= (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)	{ return (!(lhs < rhs)); }
	template <typename T, typename Alloc>
	void swap (map<T,Alloc>& x, map<T,Alloc>& y)						{ x.swap(y); }
}

#endif