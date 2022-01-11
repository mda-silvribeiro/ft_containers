#include <iostream>
#include <set>
#include "../containers/set.hpp"

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

bool fncomp (int lhs, int rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs<rhs;}
};

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

int main( void ) {
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



}