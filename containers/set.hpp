#ifndef SET_HPP
# define SET_HPP

#include "../incs/red_black_tree.hpp"
#include "../incs/rbt_iter.hpp"
#include "../incs/reverse_iterator.hpp"
#include "../incs/iterator.hpp"
#include "../incs/iterator_traits.hpp"
#include "../incs/compare.hpp"
#include "../incs/pair.hpp"
#include "../incs/enable_if.hpp"
#include "../incs/is_integral.hpp"

namespace ft {
    // set::key_type/value_type  set::key_compare/value_compare   set::allocator_type
    template < class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
    class set {
        // ############################ Member types ############################
    public:
        typedef T                                   value_type;
        typedef T                                   key_type;
        typedef Compare                             value_compare;
        typedef Compare                             key_compare;
        typedef Alloc                               allocator_type;
        typedef typename allocator_type::reference  reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef typename ft::red_black_tree<value_type, value_compare, allocator_type> rbtree;
        typedef typename ft::node<value_type> node;
        typedef node* nodePtr;
        typedef red_black_tree_iterator<nodePtr, pointer> iterator;
        typedef red_black_tree_iterator<nodePtr, const_pointer> const_iterator;
        typedef typename ft::reverse_iterator<iterator> reverse_iterator;
        typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
        typedef typename iterator_traits<iterator>::difference_type difference_type;
        typedef size_t size_type;
        // ############################ Member Function ############################
        // empty (1)	
        explicit set (const key_compare& comp = key_compare(),
                      const allocator_type& alloc = allocator_type()) : 
                      _rbtree(value_compare(comp), alloc),
                      _alloc(alloc), _comp(comp) {        
        
        }
        //range (2)	
        template <class InputIterator>
        set (InputIterator first, InputIterator last,
               const key_compare& comp = key_compare(),
               const allocator_type& alloc = allocator_type()) : 
               _rbtree(value_compare(comp), alloc), _alloc(alloc), _comp(comp) {
                   insert(first, last);
        }

        //copy (3)	
        set (const set& x) :  
        _rbtree(value_compare(x._comp), x._alloc),  _alloc(x._alloc), _comp(x._comp) {
            *this = x;
        }

        ~set() { }
        set& operator=(const set& x) {
            if (this == &x)
                return (*this);
            if (this != &x) {
                clear();
                _alloc = x._alloc;
                _comp = x._comp;
                insert(x.begin(), x.end());
            }
            return (*this);
        }

        allocator_type get_allocator() const {
            return _alloc;
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
            iterator ret = find(val);
            //set to true if a new element was inserted
            if (ret == end()) {
                _rbtree.insert(val);
                ret = find(val);
                return (pair<iterator, bool>(ret, true));
            }
            //  or false if an equivalent key already existed.
            return (pair<iterator, bool>(ret, false));
        }
        // with hint (2)
        // hint (pos) -> iterator, used as a suggestion as to where to start the search
        iterator insert (iterator pos, const value_type& val) {
            pos = find(val);
            // Returns an iterator to the inserted element
            if (pos != end())
                return(pos);
            insert(val);
            // or to the element that prevented the insertion
            return ( find(val) );
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
            if (find(*pos) != end())
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
        void swap( set& other ) {
            _rbtree.swap(other._rbtree);
            std::swap(_comp, other._comp);
            std::swap(_alloc, other._alloc);
        }

        // Lookup
        iterator find (const value_type& k) {
            nodePtr ret = _rbtree.find(k);
            // An iterator to the element, if an element with specified key 
            // is found, or set::end otherwise.
            return (ret == nullptr ? this->end() : iterator(ret));   
        }
        
        const_iterator find (const value_type& k) const {
            nodePtr ret = _rbtree.find(k);
            return (ret == nullptr ? end() : const_iterator(ret));  
        }

        // Searches the container for elements with a key equivalent to k 
        // and returns the number of matches.
        size_type count( const value_type& key ) const {
            // Because all elements in a set container are unique, the function
            // can only return 1 (if the element is found) or zero (otherwise).
            return  (find(key) != end());
        }
        // Get range of equal elements
        pair<const_iterator,const_iterator> equal_range(const value_type& k) const {
            return pair<const_iterator,const_iterator>(lower_bound(k), upper_bound(k));
        }
            
        pair<iterator,iterator> equal_range(const value_type& k) {
            return pair<iterator,iterator>(lower_bound(k), upper_bound(k));
        }

        // Iterator pointing to the first element that is not less than key.
        // If no such element is found, a past-the-end iterator (see end()) is returned.
        iterator lower_bound(const value_type& k) {
            return _rbtree.lower_bound(k);
        }
        
        const_iterator lower_bound(const value_type& k) const {
            return _rbtree.lower_bound(k);
        }
        
        // Returns an iterator pointing to the first element that is greater than key.
        iterator upper_bound(const value_type& k)
		{
		    return _rbtree.upper_bound(k);
		}
		const_iterator upper_bound(const value_type& k) const
		{
		    return _rbtree.upper_bound(k);
		}

        key_compare key_comp() const { return (_comp); }

        value_compare value_comp() const { return (_comp); }


    private:
        rbtree _rbtree;
        allocator_type _alloc;
        key_compare _comp;
    };
    // Non-member functions
    template <typename T, typename Alloc>
	bool operator== (const set<T,Alloc>& lhs, const set<T,Alloc>& rhs)	{ return (lhs.size() == rhs.size() && equal(lhs.begin(), lhs.end(), rhs.begin())); }
	template <typename T, typename Alloc>
	bool operator!= (const set<T,Alloc>& lhs, const set<T,Alloc>& rhs)	{ return (!(lhs == rhs)); }
	template <typename T, typename Alloc>
	bool operator< (const set<T,Alloc>& lhs, const set<T,Alloc>& rhs)	{ return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }
	template <typename T, typename Alloc>
	bool operator<= (const set<T,Alloc>& lhs, const set<T,Alloc>& rhs)	{ return (!(rhs < lhs)); }
	template <typename T, typename Alloc>
	bool operator> (const set<T,Alloc>& lhs, const set<T,Alloc>& rhs)	{ return (rhs < lhs); }
	template <typename T, typename Alloc>
	bool operator>= (const set<T,Alloc>& lhs, const set<T,Alloc>& rhs)	{ return (!(lhs < rhs)); }
	template <typename T, typename Alloc>
	void swap (set<T,Alloc>& x, set<T,Alloc>& y)						{ x.swap(y); }
}


#endif