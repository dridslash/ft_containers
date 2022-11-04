/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:01:31 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/11/04 18:55:21 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "vector.hpp"
// equal algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::equal
#include <vector>       // std::vector

template<typename T>
    void print(T n, typename ft::enable_if<!ft::is_integral<T>::value, T>::type* = 0){
        std::cout << "hello1\n";
    }

    void print(int  n){
        std::cout << "hello2\n";
}
   

class test{
  public:
  int var;
  test(){/*std::cout<<"we constructed\n";*/}
  test(int i):var(i){/*std::cout<<"constructed\n";*/};
  ~test(){/*std::cout<<"destruct\n";*/}
  operator int() { return var;}
  bool operator() (const std::string& s1, const std::string& s2) const {return(s1 == s2);}
  bool operator() (int a , int b) const {return(a == b);}
};

//b-/ -------------------------------------------------------------------------------------------------------------------


bool mypredicate (int i, int j) {
  return (i==j);
}

bool l(int a, int b){
    return (a == b);
}

template<class function>
void utilise_funtion(function f, int a, int b){
    if (f(a,b)){
        std::cout<<"equal\n";
    }
}

bool mycomp (char c1, char c2)
{ return std::tolower(c1)<std::tolower(c2); }



int main () {
    try{
    //std::vector<int> v(4,10);
    ft::vector<int> v2;
    std::vector<int> v;

    //  std::cout<<"----v2_size-->"<<v2.size()<<std::endl;
    // std::cout<<"----v2_cap_-->"<<v2.capacity()<<std::endl;

    // std::cout<<"----v_size-->"<<v.size()<<std::endl;
    // std::cout<<"----v_cap_-->"<<v.capacity()<<std::endl;
    
    std::cout<<"--------------------------------------------------------------\n";
    
    // v.reserve(64);
    // v2.reserve(64);
    //std::cout<<"----v2-->"<<v2.size()<<std::endl;
    //std::cout<<"----v2_cap_-->"<<v2.capacity()<<std::endl;
    //v2.reserve(0);
    //std::cout<<"----v2-->"<<v2.size()<<std::endl;
    //std::cout<<"----v2_cap_-->"<<v2.capacity()<<std::endl;
    //v2.reserve(64);
    //std::cout<<"----v2-->"<<v2.size()<<std::endl;
    //std::cout<<"----v2_cap_-->"<<v2.capacity()<<std::endl;
    // std::cout<<"----v2-->"<<*(v2.begin())<<std::endl;
   //std::cout<<"----v-->"<<v.size()<<std::endl;
   // std::cout<<"----v_cap_-->"<<v.capacity()<<std::endl;
    // std::cout<<"----v-->"<<v.size()<<std::endl;

    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(1000);

    v.push_back(10);
    v.push_back(20);
    v.push_back(20);
    
    std::cout<<"----v2_size-->"<<v2.size()<<std::endl;
    std::cout<<"----v2_cap_-->"<<v2.capacity()<<std::endl;

    std::cout<<"----v_size-->"<<v.size()<<std::endl;
    std::cout<<"----v_cap_-->"<<v.capacity()<<std::endl;
    
    
    // v2.push_back(100);
    // v2.push_back(200);
    // v.swap(v2);
    // ft::vector<int>::iterator it = v2.begin();
    // ft::vector<int>::iterator end = v2.end();

    // ft::vector<int>::iterator it = v2.begin();
    // ft::vector<int>::iterator end = v2.end();

    
    // if (it != end) {
    //   std::cout<<"----v2-->"<<*(it)<<std::endl;
    // }
    
    //  std::cout<<"----v2-->"<<v2.at(0)<<std::endl;
    //  std::cout<<"----v2-->"<<v2.at(1)<<std::endl;
    
    // if (it != end) {
    //   std::cout<<"----v2-->"<<*(it)<<std::endl;
    // }
    
    for(ft::vector<int>::iterator it = v2.begin(); it != v2.end();++it)
    {
      //ft::vector<int>::iterator it2;
      //it2 = it;
      std::cout<<"----v2-->"<<*(it)<<std::endl;
     // std::cout<<"----v2-->"<<*(end)<<std::endl;
    }
    //for(int i = 0 ; i < v2.size() ; i++)
     // std::cout<<"----v2-->"<<v2.at(i)<<std::endl;
   // std::cout<<"----v2-->"<<v2.at(0)<<std::endl;
    // std::cout<<"----v2-->"<<v2.size()<<std::endl;
    // std::cout<<"----v-->"<<v.size()<<std::endl;
    // for(int i = 0 ; i < v2.size() ; i++)
    //    std::cout<<"----v-->"<<v2.at(i)<<std::endl;
    // std::cout<<v.max_size()<<std::endl;
    // std::cout<<v2.max_size()<<std::endl;
  //   ft::vector<int> v2;
  //   //v2.push_back(10);
  //   // v2.erase(v2.begin());
  //   // std::cout<<"size-v2->"<<v2.size()<<std::endl;
  //   std::cout<<"capacity--v2->"<<v2.capacity()<<std::endl;
  //   std::cout<<"size-->"<<v.size()<<std::endl;
  //   std::cout<<"capacity-->"<<v.capacity()<<std::endl;

  //   std::cout<<"//r-/////////////////////////////////////////////////////\n";
  //   // v2.end();
  //   // std::cout<<"before\n";
  //   // v.assign (5,10);
  //   std::vector<test>::iterator it;
  //   v.push_back(10);
  //   v.push_back(20);
  //   v.push_back(30);
  //   v.push_back(40);
  //   v.push_back(50);
  //   // v.erase(v.begin());
  //   std::cout<<"size-->"<<v.size()<<std::endl;
  //   std::cout<<"empty-->"<<(v2.empty() ? "true\n" : "false\n");
  //   std::cout<<"capacity-->"<<v.capacity()<<"\n";
  //   // v.clear();
  //   std::vector<test>::iterator it2 = v.erase(v.begin(),v.begin());
  //   for(it = v.begin(); it != v.end(); it++)
  //   std::cout<<*it<<std::endl;

  // std::cout<<"-----------------------------------------\n";
  // std::cout<<"---FORM_EARSED-->\n";
  //   while(it2 != v.end()){
  //   std::cout<<*it2<<std::endl;
  //   it2++;
  //   }
    
  //   std::cout<<"empty-->"<<(v.empty() ? "true\n" : "false\n");
  //   std::cout<<"capacity-->"<<v.capacity()<<"\n";
  //   std::cout<<"size-->"<<v.size()<<std::endl;
    // std::cout<<v.at(6)<<"\n";
    }catch(std::exception e){
        std::cout<<e.what()<<std::endl;
    }
    // std::cout<<v.capacity()<<"\n";
    // std::cout<<v.size()<<"\n";
    // for(std::vector<test>::iterator it = v.begin(); it != v.end();it++){
    //     std::cout << *it << "\n";
    // }
    // ft::vector<int> vec;
    // std::cout<<t(10,10)<<std::endl;
    // bool (*p)(int,int) = l;
    // utilise_funtion(t,10,10);
    // std::vector<int>vec;
    // std::vector<int>::iterator it = vec.begin();
    // print(it);
    // std::cout<<ft::is_integral<int>::value<<std::endl;
    // print(a);
    //   std::cout << std::boolalpha << std::endl;
  
//   std::cout << "std::is_integral<int>::value: " << std::is_integral<int>::value << std::endl;
//   std::cout << "ft::is_integral<int>::value: " << ft::is_integral<int>::value << std::endl;
  
//   std::cout << "std::is_integral<double>::value: " << std::is_integral<double>::value << std::endl;
//   std::cout << "ft::is_integral<double>::value: " << ft::is_integral<double>::value << std::endl;
  
//   std::cout << std::endl;
//   char foo[]="aparrra";
//   char bar[]="aparrra";


//   std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

//   std::cout << "Using default comparison (operator<): ";
//   std::cout << ((std::lexicographical_compare(foo,foo+7,bar,bar+7)) ? "true\n" : "false\n");
//   std::cout << "Using default comparison (operator<)--->FT: ";
//    std::cout << ((ft::lexicographical_compare(foo,foo+7,bar,bar+7)) ? "true\n" : "false\n");
//   std::cout << '\n';

//   std::cout << "Using mycomp as comparison object: ";
//   std::cout << ((std::lexicographical_compare(foo,foo+7,bar,bar+7,mycomp)) ? "true\n" : "false\n");
//   std::cout << "Using default comparison (operator<)--->FT: ";
//   std::cout << ((ft::lexicographical_compare(foo,foo+7,bar,bar+7,mycomp)) ? "true\n" : "false\n");
//   int myints[] = {20,40,60,80,100};               //   myints: 20 40 60 80 100
//   std::vector<int>myvector;                
//   myvector.push_back(20);
//   myvector.push_back(40);
//   myvector.push_back(60);
//   myvector.push_back(80);
//   myvector.push_back(100);
//     if (ft::equal(myvector.begin(),myvector.end(),myints,t))
//         std::cout<<"equal"<<std::endl;
//     else
//         std::cout<<"not equal"<<std::endl;
  // using default comparison:
//   if ( ft::equal (myvector.begin(), myvector.end(), myints) )
//     std::cout << "The contents of both sequences are equal.\n";
//   else
//     std::cout << "The contents of both sequences differ.\n";

//   myvector[3]=81;                                 // myvector: 20 40 60 81 100

//   // using predicate comparison:
//   if ( ft::equal (myvector.begin(), myvector.end(), myints, mypredicate) )
//     std::cout << "The contents of both sequences are equal.\n";
//   else
//     std::cout << "The contents of both sequences differ.\n";

  return 0;
}