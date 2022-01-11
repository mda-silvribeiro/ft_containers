#ifndef RBT_ITER_HPP
# define RBT_ITER_HPP

#include <iostream>
# include "iterator_traits.hpp"
# include "iterator.hpp"

namespace ft {
    //rbtree iterator
    template<class It, class T>
    class red_black_tree_iterator : public iterator<std::bidirectional_iterator_tag, typename iterator_traits<T>::value_type>
    {
    public:
        typedef It                                      iterator_type;
        typedef typename iterator_traits<T>::pointer    pointer;
        typedef typename iterator_traits<T>::reference  reference;
        typedef std::bidirectional_iterator_tag         iterator_category;
        typedef std::ptrdiff_t                         difference_type;

        red_black_tree_iterator() : _it() { }
        red_black_tree_iterator(iterator_type it) : _it(it) { }
        template<class Iter, class U>
        red_black_tree_iterator(const red_black_tree_iterator<Iter, U>& cmp) : _it(cmp.base()) { }
        ~red_black_tree_iterator() { };

            // Operation functions overloading
        template<class Iter, class U>
        red_black_tree_iterator& operator=(const red_black_tree_iterator<Iter, U>& cmp ) {
            _it = cmp.base(); 
            return (*this);
        }
                    
        reference operator*() const { return _it->data; }

        pointer operator->() const { return &(operator*()); }

        red_black_tree_iterator& operator++() {
            _it = successor(_it);
            return (*this);
        }

        red_black_tree_iterator operator++(int) {
            red_black_tree_iterator aux(*this);
            _it = successor(_it);
            return (aux);
        }

        red_black_tree_iterator& operator--() {
            _it = predecessor(_it);
            return (*this);
        }

        red_black_tree_iterator operator--(int) {
            red_black_tree_iterator aux(*this);
            _it = predecessor(_it);
            return (aux);
        }

        iterator_type base() const { return (_it); }

        template< class I, class Te>
        bool operator==(const red_black_tree_iterator<Te, I>& iter) { return _it == iter.base(); }
                
        template <class I, class Te>
        bool operator!=(const red_black_tree_iterator<Te, I>& iter ) { return _it != iter.base(); }
                
    private:
        iterator_type _it;
                    
        iterator_type minimum( iterator_type it ) const {
            while (it->left != nullptr )
                it = it->left;
            return (it);
        }

        iterator_type maximum( iterator_type it ) const {
            while ( it->right != nullptr )
                it = it->right;
            return (it);
        }
                    
        iterator_type successor( iterator_type it ) {
            if (it->right != nullptr)
                return (minimum(it->right));
            iterator_type y = it->parent;
            while (y != nullptr && it == y->right) {
                it = y;
                y = y->parent;
            }
            return (y);
        }

        iterator_type predecessor( iterator_type it ) {
            if ( it->left != nullptr )
                return (maximum(it->left));
            iterator_type y = it->parent;
            while( y == nullptr && it == y->left ) {
                it = y;
                y = y->parent;
            }
            return (y);
        }
    };
}

#endif