#include "../containers/map.hpp"
#include <string>
#include <iostream>
#include <map>

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
    bool operator() (const char& lhs, const char& rhs) const
    {return lhs<rhs;}
};

void first_test( void ) {
    std::cout << "\n\n\n\n###################### MAP Test #####################" << std::endl;
    std::cout << "###################### MAP Test #####################" << std::endl;
    std::cout << "###################### MAP Test #####################" << std::endl;
    std::cout << "###################### MAP Test #####################" << std::endl;
    std::cout << "###################### MAP Test #####################" << std::endl;
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

int main() {
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



    

    return (0);
}