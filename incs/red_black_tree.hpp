/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:24:48 by mda-silv          #+#    #+#             */
/*   Updated: 2022/01/11 14:37:48 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

#include <iostream>
#include "utils.hpp"
#include "reverse_iterator.hpp"
#include "iterator.hpp"
#include "iterator_traits.hpp"
#include "rbt_iter.hpp"

# define BLACK 1
# define RED 0
/* Red-Black tree is a self-balancing binary search tree in which each node 
contains an extra bit for denoting the color of the node, either red or black.*/

namespace ft {
    // data structure that represents a node in the tree
    template <class T>
    struct node {
        typedef T value_type;

        value_type  data; // holds the key
        bool        color; //  BLACK OR RED
        node        *right; // pointer to right child
        node        *left;  // pointer to left;
        node        *parent; // pointer to the parent
        
        // Default Constructor
        node() : data(0), color(BLACK), right(nullptr), left(nullptr), parent(nullptr) {}

        // Constructor
        node( value_type dt) : data(dt), color(BLACK) {
            right = left = parent = nullptr;
        }   
    };
    
    
    // template

    template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
    class red_black_tree {
        public :
            // ############# Member Types #############
            typedef T                                           value_type;
            typedef typename Alloc::pointer                     pointer;
            typedef typename Alloc::const_pointer               const_pointer;
            typedef typename Alloc::reference                   reference;
            typedef typename Alloc::const_reference             const_reference;
            typedef struct node<value_type>                     node;
            typedef node*                                       node_pointer;
            typedef Compare                                     value_compare;
            typedef ft::red_black_tree_iterator<node_pointer, pointer>		iterator;
		    typedef ft::red_black_tree_iterator<node_pointer, const_pointer>	const_iterator;
            typedef typename ft::reverse_iterator<iterator> reverse_iterator;
            typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
            typedef typename Alloc::template rebind<node>::other allocator_type;
            typedef size_t size_type;
            
            // ############# Member Function #############
            // Default Constructor
            red_black_tree(value_compare _comp, allocator_type _alloc) : _root(nullptr),
                        _end(), _alloc(_alloc), _comp(_comp), _size(0) 
            {
                _end = _alloc.allocate(1);
			    _alloc.construct(_end, value_type());                    
            }
            
            // Copy constructor
            red_black_tree( const red_black_tree& cmp ) : _root(nullptr), _end(nullptr), 
                        _alloc(cmp._alloc), _comp(cmp._comp), _size(cmp._size) 
            {
                _end = _alloc.allocate(1);
			    _alloc.construct(_end, value_type());
            }
            // Destructor
            ~red_black_tree() {
                if (_end != NULL) {
                    clear();
                    _alloc.destroy(_end);
                    _alloc.deallocate(_end, 1);
                }
            }

            red_black_tree operator=(red_black_tree& cmp ) {
                if (this == &cmp)
                    return (*cmp);
                if (this != &cmp ) {
                    clear();
                    value_compare() = cmp.value_cmp();
                    _alloc = cmp._alloc;
                    iterator it = cmp.begin();
                    while(it != cmp.end()) {
                        insert(*it++);
                    }
                }
            }
            // ###################  Iterators  ###################
            iterator begin() { 
                return _root != nullptr ? iterator(minimum(_root)) : iterator(_end);
            }
            
            const_iterator begin() const { 
                return (_root != nullptr ? const_iterator(minimum(_root)) : const_iterator(_end));
            }

            iterator end() {
                if (empty())
				    return begin();
                return iterator(_end);
            }

            const_iterator end() const {
                if (empty())
				    return begin();
                return const_iterator(_end);
            }

            reverse_iterator rbegin()
		    {
			    return reverse_iterator(this->end());
		    }

		    const_reverse_iterator rbegin() const
		    {
			    return const_reverse_iterator(this->end());
		    }

		    reverse_iterator rend()
		    {   
                if (empty())
				    return rbegin();
			    return reverse_iterator(this->begin());
		    }
		
		    const_reverse_iterator rend() const
		    {
                if (empty())
				    return rbegin();
			    return const_reverse_iterator(this->begin());
		    }

            // ###################  Capacity  ###################
            size_type size() const { return this->_size; }

            size_type max_size() const { return this->_alloc.max_size(); }          
            
            bool empty() const { return this->_size == 0; }

            //###################  Modifiers  ###################
            // insert the key to the tree in its appropriate position
	        // and fix the tree
            void insert(value_type data = value_type()) {
                // Ordinary Binary Search Insertion
                // if new node is a root node, simply return
                if ( _root == nullptr ) {
                    _root = _alloc.allocate(1);
			        _alloc.construct(_root, data);
                    _root->parent = _end;
                    _end->left = _root;
                    _size++;
                    return ;
                }
                if (find(data) != nullptr)
                    return ;
                _end->left = nullptr;
                _root->parent = nullptr;
                node_pointer new_node = _alloc.allocate(1);
			    _alloc.construct(new_node, data);
                node_pointer parent = nullptr;
                node_pointer node_r = _root;
                // y is parent of x
                while(node_r != nullptr) {
                    parent = node_r;
                    node_r = (_comp(new_node->data, node_r->data)) ? node_r->left : node_r->right;
                    new_node->parent = parent;
                } 
                if (_comp(new_node->data, parent->data))
                    parent->left = new_node;
                else
                    parent->right = new_node;
                new_node->color = RED; // new node must be red
                // Fix the tree
                fixInsert(new_node);
			    _end->left = _root;
			    _root->parent = _end;
			    _size++;
            }


            value_compare value_comp() const{ return _comp; }
                        
            node_pointer find(const value_type& data) const {
                node_pointer aux = _root;
                while ( aux != nullptr ) { 
                    if (!_comp(aux->data, data) && !_comp(data, aux->data))
                        break;
                    aux = _comp(aux->data, data) ? aux->right : aux->left;
                }
                return aux;
            }

            iterator lower_bound( const value_type& value) {
                node_pointer result = _end;
                node_pointer node_r = _root;
                while(node_r != nullptr) {
                    if (!_comp(node_r->data, value)) {
                        result = node_r;
                        node_r = node_r->left;
                    }
                    else
                        node_r =node_r->right;
                }
                return iterator(result);
            }

            const_iterator lower_bound (const value_type& value) const
		    {
			    node_pointer result = _end;
			    node_pointer node_r = _root;
			    while (node_r != nullptr)
			    {
				    if (!_comp(node_r->data, value))
				    {
					    result = node_r;
					    node_r = node_r->left;
				    }
				    else
					    node_r = node_r->right;
			    }
			    return const_iterator(result);
		    }

            iterator upper_bound (const value_type& _value)
		    {
			    node_pointer result = _end;
			    node_pointer node_r = _root;
			    while (node_r != nullptr)
			    {
				    if (_comp(_value, node_r->data))
				    {
					    result = node_r;
					    node_r = node_r->left;
				    }
				    else
					    node_r = node_r->right;
			    }
			    return iterator(result);
		    }

		    const_iterator upper_bound (const value_type& _value) const
		    {
		    	node_pointer result = _end;
			    node_pointer node_r = _root;
			    while (node_r != nullptr)
			    {
				    if (comp(_value, node_r->data))
				    {
					    result = node_r;
					    node_r = node_r->left;
				    }
				    else
					    node_r = node_r->right;
			    }
			    return const_iterator(result);
		    }
            
            void erase(value_type data = value_type()) {
                node_pointer target;
                node_pointer x;
                if (!_root || (target = find(data)) == nullptr)
                    return ;
                _end->left = nullptr;
                _root->parent = nullptr;
                node_pointer y = target;
                bool deleted_col = y->color;
                if (target->left == nullptr) {
                    x = target->right;
                    shift(target, target->right);
                    _alloc.destroy(target);
                    _alloc.deallocate(target, 1);
                }
                else if (target->right == nullptr) {
                    x = target->left;
                    shift(target, target->left);
                    _alloc.destroy(target);
                    _alloc.deallocate(target, 1);
                }
                else
                {
                    y = minimum(target->right);
                    deleted_col = y->color;
                    x = y->right;
                    if (y->parent != nullptr && y->parent != target) {
                        shift(y, y->right);
                        y->right = target->right;
                        y->right->parent = y;
                    }
                    shift(target, y);
                    y->left = target->left;
                    y->left->parent = y;
                    y->color = target->color;
                    _alloc.destroy(target);
                    _alloc.deallocate(target, 1);
                }
                if (deleted_col == BLACK && x != nullptr)
                    fixdel(x);
                if (_root != nullptr )
                {
                    _end->left = _root;
                    _root->parent = _end;
                }
                _size--;
            }

            // find the node with the minimum key
            node_pointer minimum(node_pointer nd) const {
                while ( nd->left != nullptr )
                    nd = nd->left;
                return (nd);
            }

            // find the node with the maximum key
            node_pointer maximum(node_pointer nd ) const {
                while (nd->right != nullptr )
                    nd = nd->right;
                return (nd);
            }
            // find the successor of a given node
            node_pointer successor(node_pointer nd) {
                // if the right subtree is not null,
		        // the successor is the leftmost node in the right subtree
                if ( nd->right != nullptr ) 
                    return minimum(nd->right);
                node_pointer ret = nd->parent;
                while ( ret != nullptr && nd == ret->right)
                {
                    // else it is the lowest ancestor of x whose
		            // left child is also an ancestor of x.
                    nd = ret;
                    ret = ret->parent;
                }
                return (ret);
            }
            // find the predecessor of a given node
            // if the left subtree is not null,
		    // the predecessor is the rightmost node in the 
		    // left subtree
            node_pointer predecessor(node_pointer nd) {
                if (nd->left != nullptr)
                    return (maximum(nd->left));
                node_pointer ret = nd->parent;
                while (ret != nullptr && nd == ret->left) {
                    nd = ret;
                    ret = ret->parent;
                }
                return (ret);
            }
            
            // rotate left at node x
            void leftRotate(node_pointer x) {
                node_pointer y = x->right;
                x->right = y->left;
                if ( y->left != nullptr )
                    y->left->parent = x;
                y->parent = x->parent;
                if ( x->parent == nullptr )
                    _root = y;
                else if ( x == x->parent->left )
                    x->parent->left = y;
                else
                    x->parent->right = y;
                y->left = x;
                x->parent = y;
            }

            // rotate right at node x
            void rightRotate( node_pointer x ) {
                node_pointer y = x->left;
                x->left = y->right;
                if ( y->right != nullptr )
                    y->right->parent = x;
                y->parent = x->parent;
                if (x->parent == nullptr)
                    _root = y;
                else if ( x == x->parent->right )
                    x->parent->right = y;
                else
                    x->parent->left = y;
                y->right = x;
                x->parent = y;
            }       
            
            // fix the red-black tree
            void fixInsert( node_pointer nd) {
                while(nd->parent != nullptr && nd->parent->color == RED) {
                    node_pointer u;
                    if(nd->parent == nd->parent->parent->left) {
                        // Parent is red and Uncle node is red too.
                        // In this case, we flip the color of nodes Parent, Uncle, and Grandparent.
                        // That means, P becomes black, U becomes black and, G becomes red.
                        u = nd->parent->parent->right;
                        if ( u != nullptr && u->color == RED ) {
                            nd->parent->color = BLACK;
                            u->color = BLACK;
                            nd->parent->parent->color = RED;
                            nd = nd->parent->parent;
                        }
                        else {
                            // Parent is right child of Grandparent and node is left child of Parent.
                            // In this case, we first do the right-rotation at Parent 
                            if ( nd == nd->parent->right) {
                                nd = nd->parent;
                                leftRotate(nd);
                            }
                            // Parent is right child of Grandparent and node is right child of Parent.
                            //  We first perform the left-rotation at Grandparent that makes Grandparent 
                            // the new sibling of node. Next, we change the color of Sibling to red and 
                            // Parent to black.
                            nd->parent->color = BLACK;
                            nd->parent->parent->color = RED;
                            rightRotate(nd->parent->parent);
                            break ;
                        }
                    }
                    else
                    {
                        u = nd->parent->parent->left;
                        if (u != nullptr && u->color == RED) {
                            nd->parent->color = BLACK;
                            u->color = BLACK;
                            nd->parent->parent->color = RED;
                            nd = nd->parent->parent;
                        }
                        else {
                            if ( nd == nd->parent->left ) {
                                nd = nd->parent;
                                rightRotate(nd);
                            }
                            nd->parent->color = BLACK;
                            nd->parent->parent->color = RED;
                            leftRotate(nd->parent->parent);
                            break ;
                        }
                    }
                }
                _root->color = BLACK;
            }

            void fixdel(node_pointer x) {
                node_pointer s;
                while (x != _root && x->color == BLACK) {
                    if ( x != nullptr && x == x->parent->left) {
                        s = x->parent->right;
                        if (s != nullptr && s->color == RED) {
                            // (1) In this case, we switch the colors of S and x.
                            // parent and then perform the left rotation on x.parent.
                            s->color = BLACK;
                            x->parent->color = RED;
                            leftRotate(x->parent);
                            s = x->parent->right;
                        }
                        // (2) x ’s sibling S is black, and both of S’s children are black.
                        if (s != nullptr && s->color == BLACK && s->left->color == BLACK
                            && s->right->color == BLACK) {
                            //The color of x’s parent can be red or black. We switch 
                            // the color of S to red. If the color of x’ parent is red, 
                            // we change its color to black and this becomes the terminal case.
                            s->color = RED;
                            x = x->parent;            
                        }
                        else
                        {
                            // x ’s sibling S is black, S’s left child is red, and S’s right child is black.
                            if (s->right->color == BLACK) {
                                s->left->color = BLACK;
                                s->color = RED;
                                rightRotate(s);
                            }
                            // x ’s sibling S is black, and S’s right child is red.
                            // This is a terminal case. We change the color of S’s 
                            // right child to black, x’s parent to black and perform 
                            // the left rotation x’ parent node. This way we remove
                            // the extra black node on x.
                            s->color = x->parent->color;
                            x->parent->color = BLACK;
                            s->right->color = BLACK;
                            leftRotate(x->parent);
                            x = _root;      
                        }
                    } else {
                        s = x->parent->left;
                        if ( s != nullptr && s->color == BLACK ) {
                            s->color = BLACK;
                            x->parent->color = RED;
                            rightRotate(x->parent);
                            s = x->parent->left;
                        }
                        if ( s != nullptr && s->color == BLACK && s->right->color == BLACK
                            && s->left->color == BLACK) {
                            s->color = RED;
                            x = x->parent;
                        }
                        else {
                            if ( s->left->color == BLACK ) {
                                s->right->color = BLACK;
                                s->color = RED;
                                leftRotate(s);
                            }
                            s->color = x->parent->color;
                            x->parent->color = BLACK;
                            s->left->color = BLACK;
                            rightRotate(x->parent);
                            x = _root;
                        }
                    }
                }
                x->color = BLACK;   
            }            


            
            void shift( node_pointer x, node_pointer y) {
                if (x->parent == nullptr )
                    _root = y;
                else if ( x == x->parent->left )
                    x->parent->left = y;
                else
                    x->parent->right = y;
                if ( y != nullptr )
                    y->parent = x->parent;
            }
            
            void destroy(node_pointer x) {
                if (x != nullptr )
                {
                    destroy(x->left);
                    destroy(x->right);
                    _alloc.destroy(x);
                    _alloc.deallocate(x, 1);
                }
            }
            
            void swap(red_black_tree& cmp) {
			    std::swap(this->_root, cmp._root);
			    std::swap(this->_end, cmp._end);
			    std::swap(this->_alloc , cmp._alloc);
			    std::swap(this->_comp, cmp._comp);
			    std::swap(this->_size, cmp._size);
		    }

		    void clear() {
			    destroy(this->_root);
			    _root = nullptr;
			    _size = 0;
		    }

        private:
            node_pointer    _root;
            node_pointer    _end;
            allocator_type  _alloc;
            value_compare   _comp;
            size_type       _size;
    };
    
     
}

#endif