#include "../containers/stack.hpp"
#include "../containers/vector.hpp"
#include <stack>
#include <deque>
#include <vector>
#include <iostream>
#include <algorithm>


int main( void ) {

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