/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:01:31 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/11/22 18:12:55 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// equal algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::equal
#include <vector>       // std::vector

#include "vector.hpp"

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

// class B;

// class A{
//   public:
//   A(){}
//   ~A(){}
//   void print(B b);
// };

// class B{
//   private:
//   int a;
//   public:
//   friend void A::print(B p);
//   B():a(20){}
//   ~B(){}
// };

// void A::print(B p){std::cout<<p.a<<"s\n";}

// class a{
//   public:
//   int *p;
//   a(){p = (int*)malloc(sizeof(int));std::cout<<"created\n";}
//   ~a(){free(p);std::cout<<"deleted\n";}
// };

int main () {

    ft::vector<int> myvector (3,100);
  ft::vector<int>::iterator it;

  it = myvector.begin();
  // it = myvector.insert ( it , 200 );

  myvector.insert (it,2,300);

  // "it" no longer valid, get a new one:
  it = myvector.begin();

  // ft::vector<int> anothervector (2,400);
  // myvector.insert (it+2,anothervector.begin(),anothervector.end());

  // int myarray [] = { 501,502,503 };
  // myvector.insert (myvector.begin(), myarray, myarray+3);

  // std::cout << "myvector contains:";
  // for (it=myvector.begin(); it<myvector.end(); it++)
  //   std::cout << ' ' << *it;
  // std::cout << '\n';
  
//   std::string str, ft_str;
//         /*
//          * var to store the size and the capacity
//          */
//         ft::vector<std::string>::size_type s, ft_s;
//         ft::vector<std::string>::size_type c, ft_c;
//         std::vector<std::string>::iterator b1, b2;
//         /*
//          * bool to store the comparison
//          */
//         bool cond;

//         /*---------------------------------- test 1: equal size vectors ----------------------*/
//         {
//             std::vector<std::string> v(200, "hello");
//             std::vector<std::string> v1(200, "string");
//             ft::vector<std::string> ft_v(200, "hello");
//             ft::vector<std::string> ft_v1(200, "string");

//             b1 = v.begin();
//             b2 = v1.begin();

//             swap(v, v1);
//             swap(ft_v, ft_v1);

//             s = v.size();
//             ft_s = ft_v.size();
//             c = v.capacity();
//             ft_c = ft_v.capacity();
//             for (size_t i = 0; i < v.size(); ++i)
//                 str += v[i];
//             for (size_t i = 0; i < ft_v.size(); ++i)
//                 ft_str += ft_v[i];
//             cond = ((str == ft_str) && (s == ft_s) && (c == ft_c));
//             cond = (cond && ((&*b2) == (&(*ft_v.begin()))));
//             cond = (cond && ((&*b1) == (&(*ft_v1.begin()))));
//         }
        /*--------------------------------------------------------------------------------------------*/
        /*---------------------------------- test 2: lhs > rhs ----------------------*/
        // {
            // std::vector<std::string> v(200, "hello");
            // std::vector<std::string> v1(50, "string");
            // ft::vector<std::string> ft_v(200, "hello");
            // ft::vector<std::string> ft_v1(50, "string");

            // b1 = ft_v.begin();
            // b2 = ft_v1.begin();

            // swap(v, v1);
            // swap(ft_v, ft_v1);

            // s = v.size();
            // ft_s = ft_v.size();
            // c = v.capacity();
            // ft_c = ft_v.capacity();
            // for (size_t i = 0; i < v.size(); ++i)
            //     str += v[i];
            // for (size_t i = 0; i < ft_v.size(); ++i)
            //     ft_str += ft_v[i];

            // cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));
            // cond = (cond && ((&*b2) == (&(*ft_v.begin()))));
            // cond = (cond && ((&*b1) == (&(*ft_v1.begin()))));
        // }
        /*--------------------------------------------------------------------------------------------*/
        /*---------------------------------- test 2: lhs < rhs ----------------------*/
        // {
            // std::vector<std::string> v(50, "hello");
            // std::vector<std::string> v1(200, "string");
            // ft::vector<std::string> ft_v(50, "hello");
            // ft::vector<std::string> ft_v1(200, "string");

            // b1 = ft_v.begin();
            // b2 = ft_v1.begin();

            // swap(v, v1);
            // swap(ft_v, ft_v1);

            // s = v.size();
            // ft_s = ft_v.size();
            // c = v.capacity();
            // ft_c = ft_v.capacity();
            // for (size_t i = 0; i < v.size(); ++i)
            //     str += v[i];
            // for (size_t i = 0; i < ft_v.size(); ++i)
            //     ft_str += ft_v[i];

            // cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));
            // cond = (cond && ((&*b2) == (&(*ft_v.begin()))));
            // cond = (cond && ((&*b1) == (&(*ft_v1.begin()))));
        // }
        /*--------------------------------------------------------------------------------------------*/
        //EQUAL(cond);  


  
    // B p;
    // print(p);
    // try{
    //std::vector<int> v(4,10);
    // ft::vector<int> v2(5,10);
    // ft::vector<int> v(100, 100);
    // // // v.reserve(100);
    // ft::vector<int> v2;
    // v2.assign(v.begin(),v.end());
    // std::cout << v2.capacity() << std::endl;
    // v2.erase(v2.begin() + 13, v2.end() - 11);
    // std::cout << v2.capacity() << std::endl;
    // std::cout<<"before--//after_push_back--v_size-->"<<v.size()<<std::endl;
    // std::cout<<"before----//after_push_back--v_cap_-->"<<v.capacity()<<std::endl;

    // v2.reserve(100);
    // v2.push_back(10);
    // v2.push_back(20);
    // v2.push_back(40);
    // v2.push_back(30);
    // v2.push_back(50);
    // v2.push_back(60);
    // v2.push_back(11);

    // v.push_back(10);
    // v.push_back(20);
    // v.push_back(30);
    // v.push_back(40);
    // v.push_back(50);
    // v.push_back(60);
    // v.assign(5,10);

    // std::sort(v2.begin(), v2.end());
    
//     std::cout<<"--------------------------------------------------------------\n\n";
//     std::cout<<"before----//after_push_back--v2_size-->"<<v2.size()<<std::endl;
//     std::cout<<"before----//after_push_back--v2_cap_-->"<<v2.capacity()<<std::endl;
//     // std::cout<<"--assign happend--\n\n";
//     // ft::vector<int>::iterator first = v2.begin();
//     // ft::vector<int>::iterator last = v2.end();
//     // while(first != last){
//     //   std::cout<<(*first)<<std::endl;
//     //   ++first;
//     // }
//   //   std::vector<int>::reverse_iterator rv1 = v.rbegin();
//   //   std::vector<int>::reverse_iterator rv1_last = v.rend();
//   //   ft::vector<int>::reverse_iterator rv = v2.rbegin();
//   //   ft::vector<int>::const_reverse_iterator rv_last = v2.rend();
//   //   std::cout<<(rv1[1])<<std::endl;
//   //   std::cout<<(rv[1])<<std::endl;
//   //   std::cout<<"---------------------\n\n";
//   //   while(rv != rv_last){
//   //     std::cout<<(*rv)<<std::endl;
//   //     rv++;
//   //   }
//   // std::cout<<"|||||||||||||||||||||||||||\n";
//   //   while(rv1 != rv1_last){
//   //     std::cout<<(*rv1)<<std::endl;
//   //     rv1++;
//   //   }
//     // std::cout<<it<<std::endl;
//     // for(ft::vector<int>::iterator it = v.begin(); it != v.end();++it)
//     // {
//     //   std::cout<<"----v2-->"<<*(it)<<std::endl;
//     // }
//     // std::cout<<"--copy happend--\n\n";
//     // std::cout<<"--before erase pos happend--\n\n";
//     // for(std::vector<int>::iterator it = v.begin(); it != v.end();++it)
//     // {
//     std::cout<<"---------------------------------------------------------\n\n\n";
//     // // //   //ft::vector<int>::iterator it2;
//     // // //   //it2 = it;
//     //   std::cout<<"----v-->"<<*(it)<<std::endl;
//     // // //  // std::cout<<"----v2-->"<<*(end)<<std::endl;
//     // for(ft::vector<int>::iterator it = v2.begin(); it != v2.end();++it)
//     // {
//     //   std::cout<<"----v2-->"<<*(it)<<std::endl;
//     // }
//     // }
//     // std::cout<<"--swap  happend--\n\n";
//     // v2.swap(v);
//     // v.resize(3);
//     // v2.resize(3);
//     // v2.resize(7);
//     // v.assign(v2.begin(),v2.begin() + 2);
//     // std::cout<<v.size()<<"\n";
//     //  std::vector<int>::iterator it2 = v.erase(v.begin(), v.begin() + 2);
//     //  std::cout<<"iterator return-v---->"<<*it2<<"\n";
//     // v2.insert(v2.begin(),v.begin(),v.end());
//     // it2 = v.insert(v.begin(),4);
//     // std::cout<<v.begin() + i<<std::endl;
//     //  std::vector<int>::iterator it2 = v.insert(v.begin() + 2,500);
//     // v2.insert(v2.begin(),37,88);
//     std::cout<<"-------------spliiiiiit-------------\n";
//     // ft::vector<int>::iterator it3 = v2.erase(v2.begin(), v2.begin() + 2);
//     // for(std::vector<int>::iterator it = it2; it != v.end();++it)
//     // {
//     //   std::cout<<"----v-->"<<*(it)<<std::endl;
//     // }
//     // std::cout<<"iterator return-v2---->"<<*it3<<"\n";
//      std::cout<<"--------------------------------------------------------\n\n";
//     // v.reserve(20);
//     // v.assign(3,10);
//     // std::cout<<v2.end() - v2.begin()<<std::endl;
//     // int i = 0;
//     // ft::vector<int>::iterator first = v2.begin();
//     // ft::vector<int>::iterator last = v2.end();
//     // while(first != last){
//     //   i++;
//     //   first++;
//     // }
//     // v2.assign(v.begin() ,v.end());
//     // v2.assign(6,10);
//     // v.push_back(10);
//     // v.push_back(20);
//     // v.push_back(1000);
//     // ft::vector<int> v2(v.begin(),v.end());
    
//     // std::cout<<*(v2.begin())<<"\n";
//     // std::cout<<*(v2.end())<<"\n";
//     // ft::vector<int> v(v2.begin(),v2.end());
//     //  std::cout<<"----v2_size-->"<<v2.size()<<std::endl;
//     // std::cout<<"----v2_cap_-->"<<v2.capacity()<<std::endl;

//     // std::cout<<"----v_size-->"<<v.size()<<std::endl;
//     // std::cout<<"----v_cap_-->"<<v.capacity()<<std::endl;
    
//     std::cout<<"--------------------------------------------------------------\n";
    
//     // v.reserve(64);
//     // v2.reserve(64);
//     //std::cout<<"----v2-->"<<v2.size()<<std::endl;
//     //std::cout<<"----v2_cap_-->"<<v2.capacity()<<std::endl;
//     //v2.reserve(0);
//     //std::cout<<"----v2-->"<<v2.size()<<std::endl;
//     //std::cout<<"----v2_cap_-->"<<v2.capacity()<<std::endl;
//     //v2.reserve(64);
//     //std::cout<<"----v2-->"<<v2.size()<<std::endl;
//     //std::cout<<"----v2_cap_-->"<<v2.capacity()<<std::endl;
//     // std::cout<<"----v2-->"<<*(v2.begin())<<std::endl;
//    //std::cout<<"----v-->"<<v.size()<<std::endl;
//    // std::cout<<"----v_cap_-->"<<v.capacity()<<std::endl;
//     // std::cout<<"----v-->"<<v.size()<<std::endl;

    

//     // v.push_back(10);
//     // v.push_back(20);
//     // v.push_back(20);
    
//     // v2.erase(v2.begin());
    
//     // std::vector<int>::iterator hl = v.insert(v.begin(),12);

//     std::cout<<"----v_size-->"<<v.size()<<std::endl;
//     std::cout<<"----v_cap_-->"<<v.capacity()<<std::endl<<"\n";

//     std::cout<<"----v2_size-->"<<v2.size()<<std::endl;
//     std::cout<<"----v2_cap_-->"<<v2.capacity()<<std::endl;

//     std::cout<<"--------------------------------------------------------------\n\n";
    
//     // std::cout<<"---------------->hl--->"<<(*hl)<<std::endl;

//     // std::cout<<"----v_size-->"<<v.size()<<std::endl;
//     // std::cout<<"----v_cap_-->"<<v.capacity()<<std::endl;
    
    
//     // v2.push_back(100);
//     // v2.push_back(200);
//     // v.swap(v2);
//     // ft::vector<int>::iterator it = v2.begin();
//     // ft::vector<int>::iterator end = v2.end();

//     // ft::vector<int>::iterator it = v2.begin();
//     // ft::vector<int>::iterator end = v2.end();

    
//     // if (it != end) {
//     //   std::cout<<"----v2-->"<<*(it)<<std::endl;
//     // }
    
//     //  std::cout<<"----v2-->"<<v2.at(0)<<std::endl;
//     //  std::cout<<"----v2-->"<<v2.at(1)<<std::endl;
    
//     // if (it != end) {
//     //   std::cout<<"----v2-->"<<*(it)<<std::endl;
//     // }
//     // v.erase(v.begin());
//     // v2.erase(v2.begin());
//     for(std::vector<int>::iterator it = v.begin(); it != v.end();++it)
//     {
//     // //   //ft::vector<int>::iterator it2;
//     // //   //it2 = it;
//       std::cout<<"----v-->"<<*(it)<<std::endl;
//     // //  // std::cout<<"----v2-->"<<*(end)<<std::endl;
//     }
//   std::cout<<"--------------------------------------------------------\n\n";
//     for(ft::vector<int>::iterator it = v2.begin(); it != v2.end();++it)
//     {
//       std::cout<<"----v2-->"<<*(it)<<std::endl;
//     }
//     //for(int i = 0 ; i < v2.size() ; i++)
//      // std::cout<<"----v2-->"<<v2.at(i)<<std::endl;
//    // std::cout<<"----v2-->"<<v2.at(0)<<std::endl;
//     // std::cout<<"----v2-->"<<v2.size()<<std::endl;
//     // std::cout<<"----v-->"<<v.size()<<std::endl;
//     // for(int i = 0 ; i < v2.size() ; i++)
//     //    std::cout<<"----v-->"<<v2.at(i)<<std::endl;
//     // std::cout<<v.max_size()<<std::endl;
//     // std::cout<<v2.max_size()<<std::endl;
//   //   ft::vector<int> v2;
//   //   //v2.push_back(10);
//   //   // v2.erase(v2.begin());
//   //   // std::cout<<"size-v2->"<<v2.size()<<std::endl;
//   //   std::cout<<"capacity--v2->"<<v2.capacity()<<std::endl;
//   //   std::cout<<"size-->"<<v.size()<<std::endl;
//   //   std::cout<<"capacity-->"<<v.capacity()<<std::endl;

//   //   std::cout<<"//r-/////////////////////////////////////////////////////\n";
//   //   // v2.end();
//   //   // std::cout<<"before\n";
//   //   // v.assign (5,10);
//   //   std::vector<test>::iterator it;
//   //   v.push_back(10);
//   //   v.push_back(20);
//   //   v.push_back(30);
//   //   v.push_back(40);
//   //   v.push_back(50);
//   //   // v.erase(v.begin());
//   //   std::cout<<"size-->"<<v.size()<<std::endl;
//   //   std::cout<<"empty-->"<<(v2.empty() ? "true\n" : "false\n");
//   //   std::cout<<"capacity-->"<<v.capacity()<<"\n";
//   //   // v.clear();
//   //   std::vector<test>::iterator it2 = v.erase(v.begin(),v.begin());
//   //   for(it = v.begin(); it != v.end(); it++)
//   //   std::cout<<*it<<std::endl;

//   // std::cout<<"-----------------------------------------\n";
//   // std::cout<<"---FORM_EARSED-->\n";
//   //   while(it2 != v.end()){
//   //   std::cout<<*it2<<std::endl;
//   //   it2++;
//   //   }
    
//   //   std::cout<<"empty-->"<<(v.empty() ? "true\n" : "false\n");
//   //   std::cout<<"capacity-->"<<v.capacity()<<"\n";
//   //   std::cout<<"size-->"<<v.size()<<std::endl;
//     // std::cout<<v.at(6)<<"\n";
//     // }catch(std::exception e){
//     //     std::cout<<e.what()<<std::endl;
//     // }
//     // std::cout<<v.capacity()<<"\n";
//     // std::cout<<v.size()<<"\n";
//     // for(std::vector<test>::iterator it = v.begin(); it != v.end();it++){
//     //     std::cout << *it << "\n";
//     // }
//     // ft::vector<int> vec;
//     // std::cout<<t(10,10)<<std::endl;
//     // bool (*p)(int,int) = l;
//     // utilise_funtion(t,10,10);
//     // std::vector<int>vec;
//     // std::vector<int>::iterator it = vec.begin();
//     // print(it);
//     // std::cout<<ft::is_integral<int>::value<<std::endl;
//     // print(a);
//     //   std::cout << std::boolalpha << std::endl;
  
// //   std::cout << "std::is_integral<int>::value: " << std::is_integral<int>::value << std::endl;
// //   std::cout << "ft::is_integral<int>::value: " << ft::is_integral<int>::value << std::endl;
  
// //   std::cout << "std::is_integral<double>::value: " << std::is_integral<double>::value << std::endl;
// //   std::cout << "ft::is_integral<double>::value: " << ft::is_integral<double>::value << std::endl;
  
// //   std::cout << std::endl;
// //   char foo[]="aparrra";
// //   char bar[]="aparrra";


// //   std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

// //   std::cout << "Using default comparison (operator<): ";
// //   std::cout << ((std::lexicographical_compare(foo,foo+7,bar,bar+7)) ? "true\n" : "false\n");
// //   std::cout << "Using default comparison (operator<)--->FT: ";
// //    std::cout << ((ft::lexicographical_compare(foo,foo+7,bar,bar+7)) ? "true\n" : "false\n");
// //   std::cout << '\n';

// //   std::cout << "Using mycomp as comparison object: ";
// //   std::cout << ((std::lexicographical_compare(foo,foo+7,bar,bar+7,mycomp)) ? "true\n" : "false\n");
// //   std::cout << "Using default comparison (operator<)--->FT: ";
// //   std::cout << ((ft::lexicographical_compare(foo,foo+7,bar,bar+7,mycomp)) ? "true\n" : "false\n");
// //   int myints[] = {20,40,60,80,100};               //   myints: 20 40 60 80 100
// //   std::vector<int>myvector;                
// //   myvector.push_back(20);
// //   myvector.push_back(40);
// //   myvector.push_back(60);
// //   myvector.push_back(80);
// //   myvector.push_back(100);
// //     if (ft::equal(myvector.begin(),myvector.end(),myints,t))
// //         std::cout<<"equal"<<std::endl;
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