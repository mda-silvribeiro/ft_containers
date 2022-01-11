#include <iostream>
#include <algorithm>
#include <vector>
#include "../containers/vector.hpp"
void first_test( void ) {

    std::vector<int> vector;
    ft::vector<int> myvector;

    // set some content in the vector:
    for (int i=0; i<10; i++) vector.push_back(i);
    for (int i=0; i<10; i++) myvector.push_back(i);

    std::cout << "(std)size: " << (int) vector.size() << '\n';
    std::cout << "(std)capacity: " << (int) vector.capacity() << '\n';
    std::cout << "(ft)size: " << (int) myvector.size() << '\n';
    std::cout << "(ft)capacity: " << (int) myvector.capacity() << '\n';
    std::cout << "after vector.reserve(30)" << std::endl;
    vector.reserve(30);
    myvector.reserve(30);

    std::cout << "(std)size: " << (int) vector.size() << '\n';
    std::cout << "(std)capacity: " << (int) vector.capacity() << '\n';
    std::cout << "(ft)size: " << (int) myvector.size() << '\n';
    std::cout << "(ft)capacity: " << (int) myvector.capacity() << "\n\n\n";
}



int main( void ) {
    // Member Functions
    std::cout << "####  Vector Test ####" << std::endl;
    std::vector<int> cpp;
    std::vector<int> cpp_copy;
    ft::vector<int> my;
    ft::vector<int> my_copy;

    // Modifiers 
    for (int i = 0; i < 5; i++) {
        cpp.push_back(i * 5);
        my.push_back(i * 5);
        cpp_copy.push_back(i * 3);
        my_copy.push_back(i * 3);
    }
    first_test();
    std::cout << "\n####  <vector> : at & operator[] ####\n" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "cpp[ " << i << " ] : " << cpp[i] << std::endl;
        std::cout << "cpp.at( " << i << " ) = " << i << std::endl;
        cpp.at(i) = i;
        std::cout << "cpp.at( " << i << " ) : " << cpp.at(i) << std::endl;
    }

    std::cout << "\n####  my_vector : at & operator[] ####\n" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "my[ " << i << " ] : " << my[i] << std::endl;
        std::cout << "my.at( " << i << " ) = " << i << std::endl;
        my.at(i) = i;
        std::cout << "my.at( " << i << " ) : " << my.at(i) << std::endl;
    }

    std::cout << "\n####  <vector> : swap ####\n" << std::endl;
    cpp.swap(cpp_copy);
    for (int i = 0; i < 5; i++) {
        std::cout << "cpp[ " << i << " ] : " << cpp[i] << std::endl;
    }

    std::cout << "\n####  my_vector : swap  ####\n" << std::endl;
    my.swap(my_copy);
    for (int i = 0; i < 5; i++) {
        std::cout << "cpp[ " << i << " ] : " << my[i] << std::endl;
    }

    std::cout << "\n####  <vector> : ####" << std::endl;
    std::cout << "-> size(), max_size(), capacity(), pop_back(), clear(), front(), resize() <-\n" << std::endl;
    std::cout << "cpp.size()                            : " << cpp.size() << std::endl;
    std::cout << "cpp.max_size()                        : " << cpp.max_size() << std::endl;
    std::cout << "cpp.capacity()                        : " << cpp.capacity() << std::endl;
    std::cout << "before cpp.pop_back()                 : " << cpp.at(cpp.size() - 1) << std::endl;
    cpp.pop_back();
    std::cout << "after cpp.pop_back()                  : " << cpp.at(cpp.size() - 1) << std::endl;
    std::cout << "before clear() > cpp_copy.empty       : " << cpp_copy.empty() << std::endl;
    cpp_copy.clear();
    std::cout << "after clear() > cpp_copy.empty        : " << cpp_copy.empty() << std::endl;
    std::cout << "before cpp.front()                    : " << cpp.at(0) << std::endl;
    cpp.front() = 1;
    std::cout << "after cpp.front()                     : " << cpp.at(0) << std::endl;
    cpp.push_back(5);
    cpp.resize(5);
    cpp.resize(8, 100);
    cpp.resize(12);
    std::cout << "resize                                :";
    for (size_t i = 0; i < cpp.size(); i++)
        std::cout << ' ' << cpp[i];
    std::cout << '\n';
    cpp.erase(cpp.begin()+5, cpp.end());
    std::cout << "cpp.erase(cpp.begin()+5, cpp.end())   :" ;
    for (size_t i = 0; i < cpp.size(); i++)
        std::cout << ' ' << cpp[i];
    std::cout << " " << std::endl;
    std::vector<int>::iterator it;
    it = cpp.begin();
    it = cpp.insert ( it , 200 );
    cpp.insert (it,2,300);
    std::cout << "cpp.insert(it, 2, 300)                :" ;
    for (size_t i = 0; i < cpp.size(); i++)
        std::cout << ' ' << cpp[i];
    std::cout << " " << std::endl;
    cpp.assign (7,100);
    std::cout << "cpp.assign(7, 100)                    :" ;
    for (size_t i = 0; i < cpp.size(); i++)
        std::cout << ' ' << cpp[i];
    std::cout << " " << std::endl;
    cpp.front() = 20;
    cpp.back() = 42;
    std::cout << "my.front()                            : " << cpp.front() << std::endl;
    std::cout << "my.back()                             : " << cpp.back() <<  std::endl;
    std::cout << "cpp.front() = 20 , cpp.back() = 42    :" ;
    for (size_t i = 0; i < cpp.size(); i++)
        std::cout << ' ' << cpp[i];
    std::cout << " " << std::endl;
    std::cout << "Reserve Test" << std::endl;
    std::cout << "################# cpp.begin() ################# " << std::endl;
    std::cout << "cpp contains:";
    for (std::vector<int>::iterator it = cpp.begin() ; it != cpp.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';

    std::cout << "################# cpp.end() ################# " << std::endl;
    std::cout << "cpp contains:";
    for (std::vector<int>::iterator it = cpp.begin() ; it != cpp.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    std::cout << "################# cpp.rbegin() ################# " << std::endl;
    std::vector<int>::reverse_iterator rit = cpp.rbegin();
    int i=0;
    for (; rit!= cpp.rend(); ++rit)
        *rit = ++i;
    std::cout << "cpp contains:";
    for (std::vector<int>::iterator it = cpp.begin(); it != cpp.end(); ++it)
        std::cout << ' ' << *it;

    std::cout << '\n';
    std::cout << "################# cpp.rend() ################# " << std::endl;
    rit = cpp.rbegin();
    i = 8;
    for (rit = cpp.rbegin(); rit!= cpp.rend(); ++rit)
      *rit = --i;
    std::cout << "cpp contains:";
    for (std::vector<int>::iterator it = cpp.begin(); it != cpp.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';




    std::cout << "\n####  my_vector : ####" << std::endl;
    first_test();
    std::cout << "-> size(), max_size(), capacity(), pop_back(), clear() <-\n" << std::endl;
    std::cout << "my.size()                             : " << my.size() << std::endl;
    std::cout << "my.max_size()                         : " << my.max_size() << std::endl;
    std::cout << "my.capacity()                         : " << my.capacity() << std::endl;
    std::cout << "before my.pop_back()                  : " << my.at(my.size() - 1) << std::endl;
    my.pop_back();
    std::cout << "after my.pop_back()                   : " << my.at(my.size() -1 ) << std::endl;
    std::cout << "before clear() > my_copy.empty        : " << my_copy.empty() << std::endl;
    my_copy.clear();
    std::cout << "after clear() > my_copy.empty         : " << my_copy.empty() << std::endl;
    std::cout << "before my.front()                     : " << my.at(0) << std::endl;
    my.front() = 1;
    std::cout << "after my.front()                      : " << my.at(0) << std::endl;
    my.push_back(5);
    my.resize(5);
    my.resize(8, 100);
    my.resize(12);
    std::cout << "resize                                :";
    for (size_t i = 0; i < my.size(); i++)
         std::cout << ' ' << my[i];
    std::cout << ' ' << std::endl;
    my.erase(my.begin()+5, my.end());
    std::cout << "cpp.erase(my.begin()+5, cpp.end())    :" ;
    for (size_t i = 0; i < my.size(); i++)
        std::cout << ' ' << my[i];
    std::cout << '\n';
    my.insert (my.insert ( my.begin() , 200 ), 2 ,300);
    std::cout << "my.insert(it, 2, 300)                 :" ;
    for (size_t i = 0; i < my.size(); i++)
        std::cout << ' ' << my[i];
    std::cout << " " << std::endl;
    my.assign(7,100);
    std::cout << "my.assign(7, 100)                     :" ;
    for (size_t i = 0; i < my.size(); i++)
        std::cout << ' ' << my[i];
    std::cout << " " << std::endl;
    my.front() = 20;
    my.back() = 42;
    std::cout << "my.front()                            : " << my.front() << std::endl;
    std::cout << "my.back()                             : " << my.back() <<  std::endl;
    std::cout << "my contains                           :" ;
    for (size_t i = 0; i < my.size(); i++)
       std::cout << ' ' << my[i];
    std::cout << " " << std::endl;
    std::cout << "Reserve Test" << std::endl;

    std::cout << "################# my.begin() ################# " << std::endl;
    std::cout << "my contains:";
    for (ft::vector<int>::iterator my_it = my.begin() ; my_it != my.end(); ++my_it)
      std::cout << ' ' << *my_it;
    std::cout << '\n';

    std::cout << "################# my.end() ################# " << std::endl;
    std::cout << "my contains:";
    for (ft::vector<int>::iterator my_it2 = my.begin() ; my_it2 != my.end(); ++my_it2)
        std::cout << ' ' << *my_it2;
    std::cout << '\n';

    std::cout << "################# my.rbegin() ################# " << std::endl;
    ft::vector<int>::reverse_iterator rit2 = my.rbegin();
    i=0;
    for (; rit2 != my.rend(); ++rit2)
        *rit2 = ++i;
    std::cout << "cpp contains:";
    for (ft::vector<int>::iterator my_it3 = my.begin(); my_it3 != my.end(); ++my_it3)
        std::cout << ' ' << *my_it3;
    std::cout << '\n';
 
    std::cout << "################# my.rend() ################# " << std::endl;
    rit2 = my.rbegin();
    i = 8;
    for (rit2 = my.rbegin(); rit2 != my.rend(); ++rit2)
      *rit2 = --i;
    std::cout << "cpp contains:";
    for (ft::vector<int>::iterator it4 = my.begin(); it4 != my.end(); ++it4)
      std::cout << ' ' << *it4;
    std::cout << '\n';
   
};