#ifndef MAIN_TEST_HPP
# define MAIN_TEST_HPP

# include <iostream>	// std::cout
# include <string>		// std::string
# include <typeinfo>	// std::typeid
# include <stdlib.h>	// EXIT_FAILURE, EXIT_SUCCESS, rand(), srand()
# include <deque>		// std::deque
# include <list>		// std::list

#if 0 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
    namespace ft = std;
#else
    #include "../containers/vector.hpp"
    #include "../containers/stack.hpp"
    #include "../containers/map.hpp"
    #include "../containers/set.hpp"
#endif

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};



# endif