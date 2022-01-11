#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
#include <string>
#include <map>
#include <set>
#include "../containers/vector.hpp"
#include "../containers/stack.hpp"
#include "../containers/map.hpp"
#include "../containers/set.hpp"
# include "../srcs/main_test.hpp"

/* FOREGROUND */
# define RST  "\x1B[0m"
# define COLOR_RED  "\x1B[31m"
# define COLOR_GREEN  "\x1B[32m"
# define COLOR_BLUE  "\x1B[34m"
# define COLOR "\033[0m"

# define FRED(x) COLOR_RED x RST
# define FGREEN(x) COLOR_GREEN x RST
# define FBLUE(x) COLOR_BLUE x RST

# define BOLD(x) "\x1B[1m" x RST
# define UNDL(x) "\x1B[4m" x RST

void firstvec_test( void ) {

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

void vector_test() {
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
    firstvec_test();
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
    firstvec_test();
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
   
}

void stack_test() {
    // ####### my Stacks #######
    std::deque<int> mydeque(3, 100);
    ft::vector<int> myvector(2, 200);
    ft::stack<int> first1;
    first1.push(5);
    ft::stack<int> thrid1;
    ft::stack<int, std::deque<int> > second1(mydeque);
    ft::stack<int, ft::vector<int> > third1;
    ft::stack<int, ft::vector<int> > fourth1(myvector);
    std::cout << "\n\n\n\n ########### My Stacks ###########" << std::endl;
    std::cout << "########### My Stacks ###########" << std::endl;
    std::cout << "########### My Stacks ###########" << std::endl;
   std::cout << "########### My Stacks ###########" << std::endl;
   std::cout << " Constructor, Destructor, Push, Empty, size" << std::endl;
   std::cout << "size of first:        " << first1.size() << std::endl;
   std::cout << "size of second:       " << second1.size() << std::endl;
   std::cout << "size of third:        " << third1.size() << std::endl;
   std::cout << "size of fourth:       " << fourth1.size() << std::endl;
   std::cout << "third1 is empty?:     " << third1.empty() << std::endl;
   std::cout << "first1 is empty?:     " << first1.empty() << std::endl;
   std::cout << "\n         top             " << std::endl;
   std::cout << "fourth1 before fourth1.top() = 42 : " << fourth1.top();
   fourth1.top() = 42;
   std::cout << "\nfourth1 afterfourth1.top() = 42 : " << fourth1.top();
   std::cout << "\n         pop            " << std::endl;
   std::cout << "fourth1 before fourth.1pop(): " << fourth1.top();
   fourth1.pop();
   std::cout << "\nfourth1 after fourth1.pop() : " << fourth1.top();


    // ####### cpp stacks #######
    std::deque<int> cppdeque(3, 100);
    std::vector<int> cppvector(2, 200);

    std::stack<int> first;
    first.push(5);
    std::stack<int, std::deque<int> > second(cppdeque);
    std::stack<int, std::vector<int> > third;
    std::stack<int, std::vector<int> > fourth(cppvector);

    std::cout << " \n\n########### Cpp Stacks ###########" << std::endl;
    std::cout << " Constructor, Destructor, Push, Empty, size" << std::endl;
    std::cout << "size of first:        " << first.size() << std::endl;
    std::cout << "size of second:       " << second.size() << std::endl;
    std::cout << "size of third:        " << third.size() << std::endl;
    std::cout << "size of fourth:       " << fourth.size() << std::endl;
    std::cout << "third is empty?:      " << third.empty() << std::endl;
    std::cout << "first is empty?:      " << first.empty() << std::endl;

    std::cout << "\n         top             " << std::endl;
    std::cout << "fourth1 before fourth.top() = 42 : " << fourth.top();
    fourth.top() = 42;
    std::cout << "\nfourth1 afterfourth.top() = 42 : " << fourth.top();
 
    std::cout << "\n         pop            " << std::endl;
    std::cout << "fourth before fourth.pop(): " << fourth.top();
    fourth.pop();
    std::cout << "\nfourth after fourth.pop() : " << fourth.top();

    std::cout << "\n\nNon-member function overloads \n" << std::endl;

    std::cout << "fourth == fourth " << std::endl;
    fourth == fourth ? std::cout << "Yes" : std::cout << "No";
    std::cout << "\n\n";
    std::cout << "fourth1 == fourth1 " << std::endl;
    fourth1 == fourth1 ? std::cout << "Yes" : std::cout << "No";
    std::cout << "\n\n";

    std::cout << "third == fourth " << std::endl;
    third == fourth ? std::cout << "Yes" : std::cout << "No";
    std::cout << "\n\n";
    std::cout << "third1 == fourth1 " << std::endl;
    third1 == fourth1 ? std::cout << "Yes" : std::cout << "No";
    std::cout << "\n\n";

    std::cout << "fourth != fourth " << std::endl;
    fourth != fourth ? std::cout << "Yes" : std::cout << "No";
    std::cout << "\n\n";
    std::cout << "fourth1 != fourth1 " << std::endl;
    fourth1 != fourth1 ? std::cout << "Yes" : std::cout << "No";
    std::cout << "\n\n";

    std::cout << "third != fourth " << std::endl;
    third != fourth ? std::cout << "Yes" : std::cout << "No";
    std::cout << "\n\n";
    std::cout << "third1 != fourth1 " << std::endl;
    third1 != fourth1 ? std::cout << "Yes" : std::cout << "No";
    std::cout << "\n\n";

    std::cout << "fourth < fourth " << std::endl;
    fourth < fourth ? std::cout << "Yes" : std::cout << "No";
    std::cout << "\n\n";
    std::cout << "fourth1 < fourth1 " << std::endl;
    first1 < first1 ? std::cout << "Yes" : std::cout << "No";
    std::cout << "\n\n";

    std::cout << "third < fourth " << std::endl;
    third < fourth ? std::cout << "Yes" : std::cout << "No";
    std::cout << "\n\n";
    std::cout << "third1 < fourth1 " << std::endl;
    thrid1 < fourth1 ? std::cout << "Yes" : std::cout << "No";
    std::cout << "\n\n";

   std::cout << "fourth <= fourth " << std::endl;
   fourth <= fourth ? std::cout << "Yes" : std::cout << "No";
   std::cout << "\n\n";
   std::cout << "fourth1 <= fourth1 " << std::endl;
   fourth1 <= fourth1 ? std::cout << "Yes" : std::cout << "No";
   std::cout << "\n\n";

   std::cout << "third <= fourth " << std::endl;
   third <= fourth ? std::cout << "Yes" : std::cout << "No";
   std::cout << "\n\n";
   std::cout << "third1 <= fourth1 " << std::endl;
   third1 <= fourth1 ? std::cout << "Yes" : std::cout << "No";
   std::cout << "\n\n";

   std::cout << "fourth > fourth " << std::endl;
   fourth > fourth ? std::cout << "Yes" : std::cout << "No";
   std::cout << "\n\n";
   std::cout << "fourth1 > fourth1 " << std::endl;
   fourth1 > fourth1 ? std::cout << "Yes" : std::cout << "No";
   std::cout << "\n\n";

   std::cout << "third > fourth " << std::endl;
   third > fourth ? std::cout << "Yes" : std::cout << "No";
   std::cout << "\n\n";
   std::cout << "third1 > fourth1 " << std::endl;
   third1 > fourth1 ? std::cout << "Yes" : std::cout << "No";
   std::cout << "\n\n";

    std::cout << "fourth >= fourth " << std::endl;
    fourth >= fourth ? std::cout << "Yes" : std::cout << "No";
    std::cout << "\n\n";
    std::cout << "fourth1 >= fourth1 " << std::endl;
    thrid1 >= thrid1 ? std::cout << "Yes" : std::cout << "No";
    std::cout << "\n\n";

    std::cout << "third >= fourth " << std::endl;
    third >= fourth ? std::cout << "Yes" : std::cout << "No";
    std::cout << "\n\n";
    std::cout << "third1 >= fourth1 " << std::endl;
    thrid1 >= fourth1 ? std::cout << "Yes" : std::cout << "No";
    std::cout << "\n\n";
}

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
    bool operator() (const char& lhs, const char& rhs) const
    {return lhs<rhs;}
};

void first_test( void ) {
  std::cout << "###################### Map Test #####################" << std::endl;
    // empty cpp
    std::map<char,int> first;
    first['a']=10;
    first['b']=30;
    first['c']=50;
    first['d']=70;
    std::map<char,int> second(first.begin(),first.end());
    std::map<char,int> third (second);
    std::map<char,int,classcomp> fourth;                 // class as Compare
    bool(*fn_pt)(char,char) = fncomp;
    std::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare    

    ft::map<char,int> myfirst;
    myfirst['a']=10;
    myfirst['b']=30;
    myfirst['c']=50;
    myfirst['d']=70;
    ft::map<char,int> mysecond(myfirst.begin(), myfirst.end());
    ft::map<char,int> mythird (mysecond);
    ft::map<char,int,classcomp> myfourth;                 // class as Compare
    bool(*fn_pt1)(char,char) = fncomp;
    ft::map<char,int,bool(*)(char,char)> myfifth (fn_pt1); // function pointer as Compare    

    
    std::cout << "###################### Constructor/Destructor #####################" << std::endl;
    std::cout << "                              std vs ft" << std::endl;
    std::cout << "Size of first                                         std : " << first.size() << " vs ft : " << myfirst.size() << std::endl;
    std::cout << "Size of second(first.begin(), first.end())            std : " << second.size() << " vs ft : " << mysecond.size() << std::endl;
    std::cout << "Size of thrid(second)                                 std : " << third.size() << " vs ft : " << mythird.size() << std::endl;
    std::cout << "class as Compare of fourth                            std : " << fourth.size() << " vs ft : " << myfourth.size() << std::endl;
    std::cout << "function pointer as Compare of fifth                  std : " << fifth.size() << " vs ft : " << myfifth.size() << std::endl;

}

void second_test( void ) {
    std::cout << "###################### Assignment operator with maps #####################" << std::endl;
    std::map<char,int> first;
    std::map<char,int> second;
    ft::map<char,int> myfirst;
    ft::map<char,int> mysecond;
    std::cout << "first['x']=8;\nfirst['y']=16;\nfirst['z']=32;" << std::endl;
    first['x']=8;
    first['y']=16;
    first['z']=32;

    myfirst['x']=8;
    myfirst['y']=16;
    myfirst['z']=32;
    std::cout << "second = first;\nfirst = std::map<char,int>();" << std::endl;
    second=first;                // second now contains 3 ints
    first=std::map<char,int>();  // and first is now empty
    mysecond=myfirst;
    myfirst = ft::map<char, int>();
    std::cout << "                              std vs ft" << std::endl;
    std::cout << "Size of first                 std : " << first.size() << " vs ft : " << myfirst.size() << std::endl;
    std::cout << "Size of second                std : " << second.size() << " vs ft : " << mysecond.size() << std::endl;
}

void third_test( void ) {
    std::cout << "###################### Iterators #####################" << std::endl;
    std::cout << "###################### begin/end #####################" << std::endl;
    std::map<char,int> map;
    ft::map<char,int> mymap;
    map['b'] = 100;
    map['a'] = 200;
    map['c'] = 300;
    mymap['b'] = 100;
    mymap['a'] = 200;
    mymap['c'] = 300;
    ft::map<char,int>::iterator myit=mymap.begin();
    std::cout << "ft::map<char,int>::iterator myit=mymap.begin(); " << std::endl;
    std::cout << " myit != mymap.end())" << std::endl;
    // show content:
    std::cout << "                  std vs ft" << std::endl;
    for (std::map<char,int>::iterator it=map.begin(); it!=map.end(); ++it) {
        std::cout <<"std : " << it->first << " => " << it->second;
        if (myit != mymap.end())
            std::cout << "      ft: " <<  myit->first << " => " << myit->second << std::endl;
            myit++;
    }
    std::cout << "\n###################### rbegin/rend #####################" << std::endl;
    std::map<char,int>::reverse_iterator rit;
    ft::map<char,int>::reverse_iterator myrit;
    myrit = mymap.rbegin();
    std::cout << "ft::map<char,int>::reverse_iterator myrit; " << std::endl;
    std::cout << "myrit != mymap.rend()" << std::endl;
    // show content:
    std::cout << "                  std vs ft" << std::endl;
    for (rit=map.rbegin(); rit!=map.rend(); ++rit) {
        std::cout <<"std : " << rit->first << " => " << rit->second;
        if (myrit != mymap.rend())
            std::cout << "      ft: " <<  myrit->first << " => " << myrit->second << std::endl;
            myrit++;
    }
    std::cout << "\n###################### empty/erase #####################" << std::endl;
    std::cout << "while (!map.empty() && !mymap.empty())\nmap.erase(map.begin());" << std::endl;
    std::cout << "                  std vs ft" << std::endl;
    while (!map.empty() && !mymap.empty())
    {
        std::cout << " std:  " << map.begin()->first << " => " << map.begin()->second;
        std::cout << "      ft: " <<  mymap.begin()->first << " => " << mymap.begin()->second << std::endl;
        map.erase(map.begin());
        mymap.erase(mymap.begin());
  }
}

void fourth_test( void ) {
    std::cout << "\n###################### empty #####################" << std::endl;
    int i;
    std::map<int,int> map;
    ft::map<int,int> mymap;

    if (map.max_size()>1000)
    {
        for (i=0; i<1000; i++) map[i]=0;
        std::cout << "The map contains 1000 elements.\n";
    }
    else std::cout << "The map could not hold 1000 elements.\n";
    std::cout << "                  std vs ft" << std::endl;
    if (mymap.max_size()>1000)
    {
        for (i=0; i<1000; i++) mymap[i]=0;
        std::cout << "The map contains 1000 elements.\n";
    }
    else std::cout << "The map could not hold 1000 elements.\n";

}

void fifth_test( void ) {
    std::cout << "\n###################### Element access:[] #####################" << std::endl;
    std::map<char,std::string> map;
    ft::map<char,std::string> mymap;

    map['a']="an element";
    map['b']="another element";
    map['c']=map['b'];

    mymap['a']="an element";
    mymap['b']="another element";
    mymap['c']=mymap['b'];
    std::cout << "                  std vs ft" << std::endl;
    std::cout << "map['a'] std          : " << map['a'] << " vs ft: " << mymap['a'] << std::endl;
    std::cout << "map['b'] std          : " << map['b'] << " vs ft: " << mymap['b'] << std::endl;
    std::cout << "map['c'] std          : " << map['c'] << " vs ft: " << mymap['c'] << std::endl;
    std::cout << "map['d'] std          : " << map['d'] << " vs ft: " << mymap['d'] << std::endl;

    std::cout << "map now contains std  : " << map.size() << " vs ft: " << mymap.size() << std::endl;
}

void sixth_test( void ) {
    std::cout << "\n###################### modifiers #####################" << std::endl;
    std::cout << "                          insert " << std::endl;
    std::map<char,int> map;
    ft::map<char,int> mymap;
    std::cout << "std::map<char,int> map;\nmap.insert ( std::pair<char,int>('a',100) );\nmap.insert ( std::pair<char,int>('z',200) );" << std::endl;

    // first insert function version (single parameter):
    map.insert ( std::pair<char,int>('a',100) );
    map.insert ( std::pair<char,int>('z',200) );
    mymap.insert ( ft::pair<char,int>('a',100) );
    mymap.insert ( ft::pair<char,int>('z',200) );

    std::pair<std::map<char,int>::iterator,bool> ret;
    ret = map.insert ( std::pair<char,int>('z',500) );

    ft::pair<ft::map<char,int>::iterator,bool> myret;
    myret = mymap.insert( ft::pair<char,int>('z',500) );

    if (ret.second==false) {
      std::cout << "element 'z' already existed";
      std::cout << " with a value of " << ret.first->second << '\n';
    }
    std::cout << "                  std vs ft" << std::endl;
    if (myret.second==false) {
      std::cout << "element 'z' already existed";
      std::cout << " with a value of " << myret.first->second << '\n';
    }

    // second insert function version (with hint position):
    std::map<char,int>::iterator it = map.begin();
    map.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
    map.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting
    ft::map<char,int>::iterator myit = mymap.begin();
    mymap.insert (myit, ft::pair<char,int>('b',300));
    mymap.insert (myit, ft::pair<char,int>('c',400));

    // third insert function version (range insertion):
    std::map<char,int> anothermap;
    anothermap.insert(map.begin(),map.find('c'));

    ft::map<char,int> myanothermap;
    myanothermap.insert(mymap.begin(),mymap.find('c'));

    // showing contents:
    std::cout << "mymap contains:\n";
    std::cout << "                  std vs ft" << std::endl;
    for (it=map.begin(); it!=map.end(); ++it) {
      std::cout << "std : " << it->first << " => " << it->second;
      if (myit != mymap.end()) {
          std::cout << "       ft: " << myit->first << " => " << myit->second << std::endl;
          myit++;
      }
    }

    std::cout << "anothermap contains:\n";
    std::cout << "                  std vs ft" << std::endl;
    myit = myanothermap.begin();
    for (it=anothermap.begin(); it!=anothermap.end(); ++it) {
      std::cout << "std : " << it->first << " => " << it->second;
      if (myit != myanothermap.end()) {
          std::cout << "       ft: " << myit->first << " => " << myit->second << std::endl;
          myit++;
      }
    }
    
}

void seventh_test( void ) {
    std::cout << "                           swap " << std::endl;
    std::map<char,int> foo,bar;
    ft::map<char,int> myfoo,mybar;
    std::cout << "std::map<char,int> foo,bar;\nfoo['x']=100;\nfoo['y']=200;" << std::endl;

    foo['x']=100;
    foo['y']=200;
    myfoo['x']=100;
    myfoo['y']=200;
    std::cout << "bar['a']=11;\nbar['b']=22;\nbar['c']=33;" << std::endl;
    bar['a']=11;
    bar['b']=22;
    bar['c']=33;
    mybar['a']=11;
    mybar['b']=22;
    mybar['c']=33;
    std::cout << "foo.swap(bar)" << std::endl;
    foo.swap(bar);
    myfoo.swap(mybar);

    ft::map<char,int>::iterator myit = myfoo.begin();
    std::cout << "foo contains:\n";
    std::cout << "                  std vs ft" << std::endl;
    for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it) {
        std::cout <<"std : " << it->first << " => " << it->second;
        if (myit != myfoo.end()) {
            std::cout <<"           ft : " << myit->first << " => " << myit->second << std::endl;
            myit++;
        }
    }

    myit = mybar.begin();
    std::cout << "bar contains:\n";
    std::cout << "                  std vs ft" << std::endl;
    for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it) {
        std::cout <<"std : " << it->first << " => " << it->second;
        if (myit != mybar.end()) {
            std::cout <<"           ft : " << myit->first << " => " << myit->second << std::endl;
            myit++;
        }
    }
    std::cout << "                  clear" << std::endl;
    std::cout << "                  std vs ft" << std::endl;
    mybar.clear();
    myfoo.clear();
    bar.clear();
    foo.clear();
    std::cout << "bar is empty ?    std : " << bar.empty() << " vs ft : " << mybar.empty() << std::endl;
    std::cout << "foo is empty ?    std : " << foo.empty() << " vs ft : " << myfoo.empty() << std::endl;
    std::cout << "                  after inserting values." << std::endl;
    foo['x']=100;
    myfoo['x']=100;
    bar['a']=11;
    mybar['a']=11;
    std::cout << "bar is empty ?    std : " << bar.empty() << " vs ft : " << mybar.empty() << std::endl;
    std::cout << "foo is empty ?    std : " << foo.empty() << " vs ft : " << myfoo.empty() << std::endl;
}

void eighth_test( void ) {
    std::cout << "\n###################### Key_comp #####################" << std::endl;
    std::map<char,int> map;
    ft::map<char,int> mymap;

    std::map<char,int>::key_compare comp = map.key_comp();
    ft::map<char,int>::key_compare mycomp = mymap.key_comp();

    map['a']=100;
    map['b']=200;
    map['c']=300;
    mymap['a']=100;
    mymap['b']=200;
    mymap['c']=300;

    std::cout << "mymap contains:\n";

    char highest = map.rbegin()->first; 
    char myhighest = mymap.rbegin()->first;    // key value of last element

    std::map<char,int>::iterator it = map.begin();
    ft::map<char,int>::iterator myit = mymap.begin();
    while ( comp((*it++).first, highest) ) {
        std::cout << it->first << " => " << it->second << '\n';
    }
    std::cout << "                  std vs ft" << std::endl;
    while ( mycomp((*myit++).first, myhighest) ) {
        std::cout << myit->first << " => " << myit->second << '\n';
    }
    std::cout << '\n';
}

void ninth_test( void ) {
    std::cout << "\n###################### value_comp #####################" << std::endl;
    std::map<char,int> map;
    ft::map<char,int> mymap;
    map['x']=1001;
    map['y']=2002;
    map['z']=3003;
    mymap['x']=1001;
    mymap['y']=2002;
    mymap['z']=3003;

    std::cout << "map contains:\n";

    std::pair<char,int> highest = *map.rbegin();
    ft::pair<char,int> myhighest = *mymap.rbegin();          // last element

    std::map<char,int>::iterator it = map.begin();
    ft::map<char,int>::iterator myit = mymap.begin();
    
    while ( map.value_comp()(*it++, highest) ) {
         std::cout << it->first << " => " << it->second << '\n';
    }
    std::cout << "                  std vs ft" << std::endl;
    while ( mymap.value_comp()(*myit++, myhighest) ) {
         std::cout << myit->first << " => " << myit->second << '\n';
    }

}

void tenth_test( void ) {
    std::cout << "\n###################### find #####################" << std::endl;
    std::map<char,int> map;
    std::map<char,int>::iterator it;
    ft::map<char,int> mymap;
    ft::map<char,int>::iterator myit;
    std::cout << "map['a']=50;\nmap['b']=100;\nmap['c']=150;\nmap['d']=200;" << std::endl;
    map['a']=50;
    map['b']=100;
    map['c']=150;
    map['d']=200;
    mymap['a']=50;
    mymap['b']=100;
    mymap['c']=150;
    mymap['d']=200;
    std::cout << "it = map.find('b');\nif (it != map.end())\n  map.erase (it);" << std::endl;
    it = map.find('b');
    myit = mymap.find('b');
    if (it != map.end())
        map.erase (it);
    if (myit != mymap.end())
        mymap.erase (myit);

    // print content:
    std::cout << "                  std vs ft" << std::endl;
    std::cout << "elements in mymap:" << '\n';
    std::cout << "a =>              std : " << map.find('a')->second << " vs ft : " << mymap.find('a')->second << std::endl;
    std::cout << "c =>              std : " << map.find('c')->second << " vs ft : " << mymap.find('c')->second << std::endl;
    std::cout << "d =>              std : " << map.find('d')->second << " vs ft : " << mymap.find('d')->second << std::endl;
    std::cout << "\n###################### count #####################" << std::endl;
    std::cout << "                  std vs ft" << std::endl;
    char c;
    for (c='a'; c<'e'; c++)
    {
        std::cout << c;
        if (map.count(c)>0)
            std::cout << " is an element of map.\n";
        else 
            std::cout << " is not an element of map.\n";
        std::cout << c;
        if (mymap.count(c)>0)
            std::cout << " is an element of mymap.\n";
        else 
            std::cout << " is not an element of mymap.\n";
    }

}

void eleventh_test() {
    std::cout << "\n###################### lower_bound/upper_bound #####################" << std::endl;
    std::map<char,int> map;
    std::map<char,int>::iterator itlow,itup;
    ft::map<char,int> mymap;
    ft::map<char,int>::iterator myitlow, myitup;
    std::cout << "map['a']=20;\nmap['b']=40;\nmap['c']=60;\nmap['d']=80;\nmap['e']=100;" << std::endl;
    map['a']=20;
    map['b']=40;
    map['c']=60;
    map['d']=80;
    map['e']=100;
    mymap['a']=20;
    mymap['b']=40;
    mymap['c']=60;
    mymap['d']=80;
    mymap['e']=100;

    std::cout << "itlow=map.lower_bound ('b');\nitup=map.upper_bound ('d'); " << std::endl;
    itlow=map.lower_bound ('b');  // itlow points to b
    itup=map.upper_bound ('d'); 
    myitlow=mymap.lower_bound ('b');  // itlow points to b
    myitup=mymap.upper_bound ('d');   // itup points to e (not d!)
    std::cout << " before :" << std::endl,
    std::cout << "                  std vs ft" << std::endl;
    ft::map<char,int>::iterator myit=mymap.begin();
    for (std::map<char,int>::iterator it=map.begin(); it!=map.end(); ++it) {
      std::cout << "std : " << it->first << " => " << it->second;
      if (myit!=mymap.end()){
        std::cout << "          ft : " << myit->first << " => " << myit->second << std::endl;
        myit++;
      }
    }

    std::cout << "\n\nmap.erase(itlow,itup);\n" << std::endl;
    map.erase(itlow,itup);        // erases [itlow,itup)
    mymap.erase(myitlow, myitup); 
    // print content:
    std::cout << " after:" << std::endl,
    std::cout << "                  std vs ft" << std::endl;
    myit=mymap.begin();
    for (std::map<char,int>::iterator it=map.begin(); it!=map.end(); ++it) {
      std::cout << "std : " << it->first << " => " << it->second;
      if (myit!=mymap.end()){
        std::cout << "          ft : " << myit->first << " => " << myit->second << std::endl;
        myit++;
      }
    }
}

void twelfth_test() {
    std::map<char,int> map;
    ft::map<char,int> mymap;

    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;
    map['a']=10;
    map['b']=20;
    map['c']=30;

    std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
    ret = map.equal_range('b');
    ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> myret;
    myret = mymap.equal_range('b');

    std::cout << "lower bound points to: \n";
    std::cout << ret.first->first << " => " << ret.first->second << '\n';
    std::cout << "                  std vs ft" << std::endl;
    std::cout << myret.first->first << " => " << myret.first->second << '\n';

    std::cout << "upper bound points to: \n";
    std::cout << ret.second->first << " => " << ret.second->second << '\n';
    std::cout << "                  std vs ft" << std::endl;
    std::cout << myret.second->first << " => " << myret.second->second << '\n';
}

void last_test( void ) {
    int psize;
    int mypsize;
    std::map<char,int> map;
    std::pair<const char,int>* p;
    ft::map<char,int> mymap;
    ft::pair<const char,int>* myp;

    // allocate an array of 5 elements using mymap's allocator:
    p=map.get_allocator().allocate(5);
    myp=mymap.get_allocator().allocate(5);
    
    // assign some values to array
    psize = sizeof(std::map<char,int>::value_type)*5;
    mypsize = sizeof(ft::map<char,int>::value_type)*5;

    std::cout << "(std)The allocated array has a size of " << psize << " bytes.\n";
    std::cout << "(ft)The allocated array has a size of " << mypsize << " bytes.\n";
    map.get_allocator().deallocate(p,5);
    mymap.get_allocator().deallocate(myp,5);

}

bool fncomp (int lhs, int rhs) {return lhs<rhs;}

void test_one( void ) {
  std::cout << "\n###################### Member Types ######################" << std::endl;
  std::set<int> first;
  ft::set<int> myfirst;                          // empty set of ints

  int myints[]= {10,20,30,40,50};
  std::set<int> second (myints,myints+5);
  ft::set<int> mysecond (myints,myints+5);        // range

  std::set<int> third (second);                  // a copy of second
  ft::set<int> mythird (mysecond);
    
  std::set<int> fourth (second.begin(), second.end());  // iterator ctor.
  ft::set<int> myfourth (mysecond.begin(), mysecond.end());

  std::set<int,classcomp> fifth;                 // class as Compare
  ft::set<int,classcomp> myfifth;

  bool(*fn_pt)(int,int) = fncomp;
  std::set<int,bool(*)(int,int)> sixth (fn_pt);  // function pointer as Compare
  ft::set<int,bool(*)(int,int)> mysixth (fn_pt);
}

void test_two() {
  int myints[]={ 12,82,37,64,15 };
  std::cout << "\nint myints[]={ 12,82,37,64,15 };\nstd::set<int> first (myints,myints+5);\n";
  std::set<int> first (myints,myints+5);   // set with 5 ints
  std::set<int> second;                   // empty set
  ft::set<int> myfirst (myints,myints+5);
  ft::set<int> mysecond;
  std::cout << "std::set<int> second;\nsecond = first; \nfirst = std::set<int>();" << std::endl;               

  second = first;                          // now second contains the 5 ints
  first = std::set<int>();                 // and first is empty
  mysecond = myfirst;                          // now second contains the 5 ints
  myfirst = ft::set<int>();
  
  std::cout << "\033[1;34mSize of first           std : " << int (first.size()) << " vs ft : " << int(myfirst.size()) << std::endl;
  std::cout << "Size of second          std : " << int (second.size()) << " vs ft : " << int(mysecond.size())<< std::endl;
  if (first.size() == myfirst.size() && second.size() == mysecond.size())
    std::cout << FGREEN("Test operator=[ PASSED ]")COLOR << std::endl;
  else
    std::cout << FRED("Test operator= [ FAILED ]")COLOR << std::endl;
}

void test_tree( void ) {
  std::cout << "###################### Begin/End ######################\n" << std::endl;
  int myints[] = {75,23,65,42,13};
  size_t ret = 0;
  std::cout << "std::set<int> myset (myints,myints+5);" << std::endl;
  std::set<int> set (myints,myints+5);
  ft::set<int> myset (myints,myints+5);

  std::cout << "set contains:\n";
  ft::set<int>::iterator myit=myset.begin();
  std::cout << "for (std::set<int>::iterator it=set.begin(); it!=set.end(); ++it) {" << std::endl;
  std::cout << "std::cout << ' ' << *it;" << std::endl;
  for (std::set<int>::iterator it=set.begin(); it!=set.end(); ++it) {
    std::cout << "\033[1;34m "  << *it;
    if (*it == *myit)
      ret++;
    if (myit!=myset.end()) {
      std::cout << " " << *myit << COLOR;
      myit++;
    }
  } 
  std::cout << '\n';
  if (ret == set.size())
    std::cout << FGREEN("Test begin/end[ PASSED ]")COLOR << std::endl;
  else
    std::cout << FRED("Test begin/end[ FAILED ]")COLOR << std::endl;
}

void test_four( void ) {
  std::cout << "###################### Rbegin/Rend ######################\n" << std::endl;
  int myints[] = {75,23,65,42,13};
  size_t ret = 0;
  std::cout << "std::set<int> myset (myints,myints+5);" << std::endl;
  std::set<int> set (myints,myints+5);
  ft::set<int> myset (myints,myints+5);

  std::cout << "set contains:\n";
  ft::set<int>::reverse_iterator rmyit=myset.rbegin();
  std::set<int>::reverse_iterator rit;
  std::cout << "for (std::set<int>::reverse_iterator rit=set.rbegin(); rit!=set.rend(); ++rit) {" << std::endl;
  std::cout << "std::cout << ' ' << *rit;" << std::endl;
  for (rit =set.rbegin(); rit!=set.rend(); ++rit) {
    std::cout << "\033[1;34m " << *rit;
    if (*rit == *rmyit)
      ret++;
    if (rmyit!=myset.rend()) {
      std::cout << ' ' << *rmyit;
      rmyit++;
    }
  } 
  std::cout << '\n';
  if (ret == set.size())
    std::cout << FGREEN("Test Rbegin/Rend[ PASSED ]")COLOR << std::endl;
  else
    std::cout << FRED("Test Rbegin/Rend [ FAILED ]")COLOR << std::endl;
}

void test_five( void ) {
  std::cout << "###################### Capacity ######################\n" << std::endl;
  std::set<int> set;
  ft::set<int> myset;
  std::cout << "\033[1;34mbefore insert set.size() std : " << set.size() << " vs ft : " << myset.size() << std::endl; 
  set.insert(20);
  set.insert(30);
  set.insert(10);
  myset.insert(20);
  myset.insert(30);
  myset.insert(10);
  std::cout << "\033[1;34mafter insert set.size() std : " << set.size() << " vs ft : " << myset.size() << std::endl; 

  std::cout << COLOR << "while (!set.empty())\nstd::cout << ' ' << *set.begin();\nset.erase(myset.begin());" << std::endl;
  while (!set.empty())
  {
    std::cout << "\033[1;34m " << *set.begin();
    set.erase(set.begin());
    if (!myset.empty()) {
      std::cout << "\033[1;34m " << *myset.begin();
      myset.erase(myset.begin());
    }

  }
  std::cout << '\n' << std::endl;
  int i;
  if (set.max_size()>1000)
  {
    for (i=0; i<1000; i++) set.insert(i);
    std::cout << "\033[1;34mThe set contains 1000 elements.\n";
  }
  else std::cout << "\033[1;34mThe set could not hold 1000 elements.\n";
  if (myset.max_size()>1000)
  {
    for (i=0; i<1000; i++) myset.insert(i);
    std::cout << "\033[1;34mThe myset contains 1000 elements.\n";
  }
  else std::cout << "\033[1;34mThe myset could not hold 1000 elements.\n";
  myset.clear();
  set.clear();
  if (set.empty() && myset.empty())
    std::cout << FGREEN("Test size/empty/erase/max_size/clear[ PASSED ]")COLOR << std::endl;
  else
    std::cout << FRED("Test size/empty/erase/max_size/clear [ FAILED ]")COLOR << std::endl;
  std::cout << '\n';
}

void test_six() {
  std::cout << "\n###################### Insert ######################\n" << std::endl;
  std::set<int> set;
  std::set<int>::iterator it;
  std::pair<std::set<int>::iterator,bool> ret;

  ft::set<int> myset;
  ft::set<int>::iterator myit;
  ft::pair<ft::set<int>::iterator,bool> myret;

  // set some initial values:
  std::cout << "for (int i=1; i<=5; ++i) {\nmyset.insert(i*10);\nset.insert(i*10);}\n" << std::endl;
  for (int i=1; i<=5; ++i) { // set: 10 20 30 40 50
    myset.insert(i*10); 
    set.insert(i*10); 
  } 
  
  std::cout << "ret = set.insert(20);\nif (ret.second==false) it=ret.first;\n" << std::endl;
  ret = set.insert(20);               // no new element inserted
  myret = myset.insert(20);

  if (ret.second==false) it=ret.first;  // "it" now points to element 20
  if (myret.second==false) myit=myret.first;
  
  std::cout << "set.insert (it,25);\nset.insert (it,24);\nset.insert (it,26);\n" << std::endl;

  set.insert (it,25);                 // max efficiency inserting
  set.insert (it,24);                 // max efficiency inserting
  set.insert (it,26);                 // no max efficiency inserting
  myset.insert (myit,25);
  myset.insert (myit,24);
  myset.insert (myit,26);

  int myints[]= {5,10,15};              // 10 already in set, not inserted
  std::cout << "int myints[]= {5,10,15};\nset.insert (myints,myints+3);\n" << std::endl;
  set.insert (myints,myints+3);
  myset.insert (myints,myints+3);

  std::cout << "myset contains:\n";
  std::cout << "myit = myset.begin();\nfor (it=set.begin(); it!=set.end(); ++it) {\nstd::cout << " " << *it;";
  std::cout << "if (myit!=myset.end()) {\nstd::cout << ' ' << *myit;\nmyit++;\n} "<< std::endl;
  
  myit = myset.begin();
  for (it=set.begin(); it!=set.end(); ++it) {
    std::cout << "\033[1;34m " << *it;
    if (myit!=myset.end()) {
      std::cout << ' ' << *myit;
      myit++;
    }
  }

  std::cout << '\n';
  if (set.size() && myset.size())
    std::cout << FGREEN("Test insert[ PASSED ]")COLOR << std::endl;
  else
    std::cout << FRED("Test insert [ FAILED ]")COLOR << std::endl;
}

void test_seven( void ) {
  std::cout << "\n###################### swap ######################\n" << std::endl;
  int myints[]={12,75,10,32,20,25};
  std::set<int> first (myints,myints+3);     // 10,12,75
  std::set<int> second (myints+3,myints+6);  // 20,25,32
  ft::set<int> myfirst (myints,myints+3);   
  ft::set<int> mysecond (myints+3,myints+6); 

  myfirst.swap(mysecond);
  myfirst.swap(mysecond);

  std::cout << "\033[1;34mfirst contains:";
  for (std::set<int>::iterator it=first.begin(); it!=first.end(); ++it)
    std::cout << ' '  << *it;
  std::cout << '\n';
  std::cout << " std vs ft : " << std::endl;
  std::cout << "myfirst contains:";
  for (ft::set<int>::iterator myit=myfirst.begin(); myit!=myfirst.end(); ++myit)
    std::cout << "\033[1;34m " << *myit;
  std::cout << '\n';

  std::cout << "second contains:";
  for (std::set<int>::iterator it=second.begin(); it!=second.end(); ++it)
    std::cout << "\033[1;34m " << *it;
  std::cout << '\n';
  std::cout << " std vs ft : " << std::endl;
  std::cout << "mysecond contains:";
  for (ft::set<int>::iterator myit=mysecond.begin(); myit!=mysecond.end(); ++myit)
    std::cout << "\033[1;34m " << *myit;
  std::cout << '\n';
  std::set<int>::iterator it=first.begin();
  ft::set<int>::iterator myit=myfirst.begin();
  std::set<int>::iterator it2=second.begin();
  ft::set<int>::iterator myit2=mysecond.begin();

  if (*myit == *it && *it2 == *myit2)
    std::cout << FGREEN("Test swap[ PASSED ]")COLOR << std::endl;
  else
    std::cout << FRED("Test swap[ FAILED ]")COLOR << std::endl;

}

void test_eight() {
  std::cout << "\n###################### Key_comp ######################\n" << std::endl;
  std::set<int> set;
  ft::set<int> myset;
  int highest;
  int myhighest;

  std::set<int>::key_compare comp = set.key_comp();
  ft::set<int>::key_compare mycomp = myset.key_comp();

  for (int i=0; i<=5; i++) {
    set.insert(i);
    myset.insert(i);
  }

  std::cout << "myset contains:\n";

  highest=*set.rbegin();
  myhighest=*myset.rbegin();

  std::set<int>::iterator it=set.begin();
  ft::set<int>::iterator myit=myset.begin();
  while ( comp(*(++it),highest) ) {
    std::cout << ' ' << *it;
  }
  std::cout << "\nstd vs ft : " << std::endl;
  while ( mycomp(*(++myit),myhighest) ) {
    std::cout << ' ' << *myit;
  }
  std::cout << '\n';
  if (*myit == *it)
    std::cout << FGREEN("Test Key_value [ PASSED ]")COLOR << std::endl;
  else
    std::cout << FRED("Test Key_value[ FAILED ]")COLOR << std::endl;
}

void test_nine() {
  std::cout << "\n###################### value_comp ######################\n" << std::endl;
  std::set<int> set;
  ft::set<int> myset;
  int highest;
  int myhighest;

  std::set<int>::value_compare comp = set.value_comp();
  ft::set<int>::value_compare mycomp = myset.value_comp();

  for (int i=0; i<=5; i++) {
    set.insert(i);
    myset.insert(i);
  }

  std::cout << "myset contains:\n";

  highest=*set.rbegin();
  myhighest=*myset.rbegin();

  std::set<int>::iterator it=set.begin();
  ft::set<int>::iterator myit=myset.begin();
  
  while ( comp(*(++it),highest) ) {
    std::cout << ' ' << *it;
  }
  std::cout << "\nstd vs ft : " << std::endl;
  while ( mycomp(*(++myit),myhighest) ) {
    std::cout << ' ' << *myit;
  }
  std::cout << '\n';
  if (*myit == *it)
    std::cout << FGREEN("Test value_comp [ PASSED ]")COLOR << std::endl;
  else
    std::cout << FRED("Test value_comp[ FAILED ]")COLOR << std::endl;
}

void test_ten ()
{
  std::cout << "\n###################### Find ######################\n" << std::endl;
  std::set<int> set;
  std::set<int>::iterator it;
  ft::set<int> myset;
  ft::set<int>::iterator myit;

  // set some initial values:
  for (int i=1; i<=5; i++) {    // set: 10 20 30 40 50
    myset.insert(i*10);
    set.insert(i*10);
  }

  it=set.find(20);
  myit=myset.find(20);
  set.erase(it);
  myset.erase(myit);
  myset.erase(myset.find(40));
  set.erase(set.find(40));

  std::cout << "myset contains:\n";
  for (it=set.begin(); it!=set.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  std::cout << "std vs ft : " << std::endl;
  for (myit=myset.begin(); myit!=myset.end(); ++myit)
    std::cout << ' ' << *myit;
  std::cout << '\n';
  if (*(set.find(30)) == *(myset.find(30)))
    std::cout << FGREEN("Test find [ PASSED ]")COLOR << std::endl;
  else
    std::cout << FRED("Test find[ FAILED ]")COLOR << std::endl;

}

void test_eleven() {
  std::cout << "\n###################### Count ######################\n" << std::endl;
  std::set<int> set;
  std::set<int> myset;

  // set some initial values:
  for (int i=1; i<5; ++i) {    // set: 3 6 9 12
    set.insert(i*3);
    myset.insert(i*3);
  }
  size_t ret = 0;
  for (int i=0; i<10; ++i)
  {
    if (set.count(i) == myset.count(i))
      ret++;
    std::cout << i;
    if (set.count(i)!=0)
      std::cout << " is an element of myset.\n";
    else
      std::cout << " is not an element of myset.\n";
    std::cout << "std vs ft : " << std::endl;
    std::cout << i;
    if (myset.count(i)!=0)
      std::cout << " is an element of myset.\n\n";
    else
      std::cout << " is not an element of myset.\n\n";
  }
  if (ret == 10)
    std::cout << FGREEN("Test find [ PASSED ]")COLOR << std::endl;
  else
    std::cout << FRED("Test find[ FAILED ]")COLOR << std::endl;
  
}

void test_twelve() {
  std::cout << "\n###################### lower_bound/upper_bound ######################\n" << std::endl;
  std::set<int> set;
  std::set<int>::iterator itlow,itup;
  ft::set<int> myset;
  ft::set<int>::iterator myitlow, myitup;

  for (int i=1; i<10; i++) { // 10 20 30 40 50 60 70 80 90
    myset.insert(i*10);
    set.insert(i*10);
  }

  itlow=set.lower_bound (30);                //       ^
  itup=set.upper_bound (60);                 //                   ^
  myitlow=myset.lower_bound (30);
  myitup=myset.upper_bound (60);

  std::cout << "before myset contains:\n";
  for (std::set<int>::iterator it=set.begin(); it!=set.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  std::cout << "std vs ft : " << std::endl;
  for (ft::set<int>::iterator myit=myset.begin(); myit!=myset.end(); ++myit)
    std::cout << ' ' << *myit;
  std::cout << '\n';

  set.erase(itlow,itup);                     // 10 20 70 80 90
  myset.erase(myitlow,myitup);

  std::cout << "\nafter myset contains:\n";
  for (std::set<int>::iterator it=set.begin(); it!=set.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  std::cout << "std vs ft : " << std::endl;
  for (ft::set<int>::iterator myit=myset.begin(); myit!=myset.end(); ++myit)
    std::cout << ' ' << *myit;
  std::cout << '\n';
  if (set.size() == myset.size())
    std::cout << FGREEN("Test lower_bound/upper_bound [ PASSED ]")COLOR << std::endl;
  else
    std::cout << FRED("Test lower_bound/upper_bound[ FAILED ]")COLOR << std::endl;
}

void test_thirteen() {
  std::cout << "\n###################### Equal Range ######################\n" << std::endl;
  std::set<int> set;
  ft::set<int> myset;

  for (int i=1; i<=5; i++) {  // myset: 10 20 30 40 50
    set.insert(i*10); 
    myset.insert(i*10); 
  }

  std::pair<std::set<int>::const_iterator,std::set<int>::const_iterator> ret;
  ft::pair<ft::set<int>::const_iterator,ft::set<int>::const_iterator> myret;
  ret = set.equal_range(30);
  myret = myset.equal_range(30);

  std::cout << "the lower bound points to: " << *ret.first << '\n';
  std::cout << "the upper bound points to: " << *ret.second << '\n';
  std::cout << "std vs ft : " << std::endl;
  std::cout << "the lower bound points to: " << *myret.first << '\n';
  std::cout << "the upper bound points to: " << *myret.second << '\n';
  if (*ret.first == *myret.first && *ret.second == *myret.second)
    std::cout << FGREEN("Test Equal Range [ PASSED ]")COLOR << std::endl;
  else
    std::cout << FRED("Test Equal Range [ FAILED ]")COLOR << std::endl;
}

void subject_test (const int aux) {
  std::cout << "\n###################### Subject Test ######################\n" << std::endl;
    srand(aux);

    ft::vector<std::string> vector_str;
    ft::vector<int> vector_int;
    ft::stack<int> stack_int;
    ft::vector<Buffer> vector_buffer;
    ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
    ft::map<int, int> map_int;

    for (int i = 0; i < COUNT; i++)
    {
      vector_buffer.push_back(Buffer());
    }

    for (int i = 0; i < COUNT; i++)
    {
      const int idx = rand() % COUNT;
      vector_buffer[idx].idx = 5;
    }
    ft::vector<Buffer>().swap(vector_buffer);

    try
    {
      for (int i = 0; i < COUNT; i++)
      {
        const int idx = rand() % COUNT;
        vector_buffer.at(idx);
        std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
      }
    }
    catch(const std::exception& e)
    {
      //NORMAL ! :P
    }
    
    for (int i = 0; i < COUNT; ++i)
    {
      map_int.insert(ft::make_pair(rand(), rand()));
    }

    int sum = 0;
    for (int i = 0; i < 10000; i++)
    {
      int access = rand();
      sum += map_int[access];
    }
    std::cout << "should be constant with the same seed: " << sum << std::endl;

    {
      ft::map<int, int> copy = map_int;
    }
    MutantStack<char> iterable_stack;
    for (char letter = 'a'; letter <= 'z'; letter++)
      iterable_stack.push(letter);
    for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
    {
      std::cout << *it;
    }
    std::cout << std::endl;
}

int main( int argc, char** argv ) {
    if (argc != 2)
	  {
		  std::cerr << "Usage: ./test seed" << std::endl;
		  std::cerr << "Provide a seed please" << std::endl;
		  std::cerr << "Count value:" << COUNT << std::endl;
		  return 1;
	  }
    const int seed = atoi(argv[1]);
    vector_test();
    stack_test();
    first_test();
    second_test();
    third_test();
    fourth_test();
    fifth_test();
    sixth_test();
    seventh_test();
    eighth_test();
    ninth_test();
    tenth_test();
    eleventh_test();
    twelfth_test();
    last_test();
    std::cout << FGREEN("\n\n\n\n\n###################### Set Tests ######################") << std::endl; 
    std::cout << FGREEN("###################### Set Tests ######################") << std::endl; 
    std::cout << FGREEN("###################### Set Tests ######################") << std::endl; 
    std::cout << FGREEN("###################### Set Tests ######################") << std::endl; 
    test_one();
    test_two();
    std::cout << "\n###################### Iterators Tests ######################" << std::endl;
    test_tree();
    test_four();
    std::cout << "\n###################### Capacity ######################\n" << std::endl;
    test_five();
    std::cout << "\n###################### Modifiers ######################\n" << std::endl;
    test_six();
    test_seven();
    std::cout << "\n###################### Observes ######################\n" << std::endl;
    test_eight();
    test_nine();
    std::cout << "\n###################### Operations ######################\n" << std::endl;
    test_ten();
    test_eleven();
    test_twelve();
    test_thirteen();
    subject_test(seed);
    return (0);
};