/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:30:34 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/11/03 19:02:44 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

class base{
    public:
    base(){}
    virtual ~base(){}
};

class Derived : public base{
    public:
    Derived(){}
    ~Derived(){}
};

// typedef struct p t_l{
//   int x;  
// };

class kl{
public:
  class l{
    public:
    l();
    
  }; 
};

kl::l::l(){
    std::cout<<"con\n";
}

class p{
    public:
  struct tag_one{};
  p();
  p(tag_one){std::cout<<"using tag\n";}
};


class cl{
    public:
    // int k = 10;
    void print(){std::cout<<"hello\n";}
    void print2(){std::cout<<"hellso\n";}
};

template<class T>struct tag_int_normal{};

template<class T>struct tag_int_normal<T*>{};

template<class T>struct tag_int_normal<const T*>{};

template<typename T> void print(T value_type){
  std::cout<<value_type<<"\n";
}

// void pr(){std::cout<<"pr\n";}

template<class T> class tag_test{
  public:
  struct tq{};
  tag_test(){}
  tag_test(tq){std::cout<<"dqwd rvalue \n";}
    tag_test(tag_int_normal<T>){std::cout<<"tag_normal rvalue \n";}
    tag_test(tag_int_normal<T*>){std::cout<<"tag_normal pointer lvalue\n";}
    tag_test(tag_int_normal<const T*>){std::cout<<"tag_normal pointer const lvalue\n";}
    tag_test(tag_int_normal<T&>){std::cout<<"tag_normal pointer lvalue reference\n";}
};

int main(){
  // std::cout<<::a<<std::endl;
  //int a = 10;
  //struct tag_int_normal<int&> t;
    //tag_test<int> p(t);
   // std::cout<<std::is_integral<int>::value <<std::endl;
    // print(25);
    // cl l;
    // int cl::*pt = &cl::k;
    // void (cl::*p[2])() = {&cl::print,&cl::print2};
    // (l.*p[1])();
    // void (*py)() = pr;
    // std::cout<<l.k<<"\n";
    // py();
   // p kl((p::tag_one()));
    // t_p name;
    // name.x = 100;
    // std::cout<<name.x<<"\n";
    // base *b = new base();
    // Derived *d1 = dynamic_cast<Derived*>(b);
    // if (d1)
    //     std::cout<<"suitable conversion\n";

    //     // char ca = 'a';
    //     using namespace std;
    // int* a = new int(90);
    // const char *c = "hello";
    // char* chr = reinterpret_cast<char*>(a);
    // cout << *a << endl;
    // cout << *chr << endl;
    // cout << a << endl;
    // cout << chr << endl;
    // std::cout<<*c<<"\n";
     //int *kl = (int*)(&ca);
     //kl = static_cast<int*>(&ca);
    //  std::vector<int> v1;
    //  v1.push_back(10);
    //  v1.push_back(20);
    //  v1.push_back(30);
    //  v1.push_back(40);
    // std::vector<int> v2(v1.begin(), v1.end());
    //  for(int i = 0; i < v2.size(); i++){
    //     std::cout<<v2[i]<<"\n";
    //  }
}