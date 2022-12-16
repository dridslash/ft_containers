/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:57:25 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/12/15 18:36:11 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AVL_Tree.hpp"
#include "Pair.hpp"
#include <vector>
#include <map>
#include "map.hpp"

// void flow_of_BST(){
// 	AVL_Tree<int,std::string> obj;
	
// 	int choice,key;
//    std::string val;
// 	do{
// 		if (std::cin.eof()){
// 			std::cin.clear();
// 			std::cin.ignore(std::numeric_limits<std::streamsize>::max());
// 			break;
// 		}
// 		std::cout <<"what is your choice ?\n\n";
// 		std::cout<<"1--Insert Node in tree\n";
// 		std::cout<<"2--Search in tree for a Node\n";
// 		std::cout<<"3--Delete Node in tree\n";
// 		std::cout<<"4--Print values in BST tree\n";
// 		std::cout<<"5--Height of tree\n";
// 		std::cout<<"6--Clear\n";
// 		std::cout<<"0--EXIT\n";
// 		std::cout<<"\n======================================\n";
// 		std::cin>>choice;
// 		tree_node<int,std::string> *new_node = new tree_node<int,std::string>();
// 		switch(choice){
// 			case 0:
// 				break;
// 			case 1:
// 			{
// 				std::cout<<"Insert\n";
// 				std::cout<<"insert a key and a value of tree node to Insert it in BST\n";
//             	std::cin>>key;
// 				std::cin>>val;
// 				new_node->pr.first = key;
//             	new_node->pr.second = val;
// 				obj.root = obj.Recursive_insert(obj.root, new_node);
// 				// std::cout<<new_node->pr.first<<std::endl;
// 				// std::cout<<new_node->pr.second<<std::endl;
// 			}
// 				break;
// 			case 2:
// 			{
// 				std::cout<<"Search\n";
// 				std::cout<<"Insert a value to search in tree\n";
// 				std::cin >> key;
// 				new_node = obj.Recursive_Search(obj.root,key);
// 				if (new_node)
// 				{
// 					std::cout<<"key found---->"<<new_node->pr.first<<std::endl;
// 					std::cout<<"value found---->"<<new_node->pr.second<<std::endl;
// 				}
// 				else
// 					std::cout<<"key not found"<<std::endl;
// 			}
// 				break;
// 			case 3:
// 			{
// 				std::cout<<"Delete\n";
// 				std::cin >> key;
// 				obj.root= obj.delete_node(obj.root , key);
// 			}
// 				break;
// 			case 4:
//             {
// 				std::cout<<"Print\n";
// 				obj.print2D(obj.root,5);
// 				// obj.BFS_print(obj.root);
// 				// obj.DFS_print(obj.root);
//             }
// 				break;
// 			case 5:
// 			{
// 				// std::cout<<"Height\n\n\n\n";
// 				// int h = obj.balance_factor(obj.root);
// 				// std::cout<<"height of tree is ---->"<<h<<std::endl<<std::endl;
// 			}
// 				break;
// 			case 6:
// 				std::cout<<"Clear\n";
// 				std::system("clear");
// 				break;
// 		}
// 	}while(choice != 0);
// }

// class one{
// 	private:
// 	friend class mat;
// 	std::string name;
// 	public:
// 	one(){}
// 	void print(){std::cout<<"one\n";}
// 	int operator()(int a){return a;}
// };

// class mat{
// 	public:
// 	mat(){}
// 	void print2(one i){one &o = i;i.name = "pp";}
// };

// template<class T1, class key_compare = std::less<T1> > class test_comp{
// 	public:
// 	key_compare comp;
// 	test_comp(){}
// 	void print_p(T1 a, T1 b){
// 		if (comp(a,b)){
// 			std::cout<<a << " less" <<std::endl;
// 		}
// 		else{
// 			std::cout<<a << " greater" <<std::endl;
// 		}
// 	}
// };

// //be- ----flow_BST-----

struct classcomp
{
    bool operator()(const char &lhs, const char &rhs) const
    {
        return lhs > rhs;
    }
};

template <typename Iter1, typename Iter2>
bool compareMaps(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2)
{
    for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
        if (first1->first != first2->first || first1->second != first2->second)
            return false;
    return true;
}


// template<class T> class Person{

// 	public:
// 	Person(){std::cout<<"dqwd\n";}
// 	~Person(){}
	
// 	protected:
// 	std::string name;
// };


// template<class T = int>
// class body : public Person<T>{

// 	public:
// 	body(const std::string& n){this->name = n;}
// 	body(){}
// 	~body(){}
// 	body(body& b){
// 		this->name = b.name;
// 	}
// 	void operator()(void){std::cout<<this->name<<std::endl;}
// };


int main(){

		 std::map<int, std::string> mp;

		 mp.insert(std::make_pair(20,"s"));
		 mp.insert(std::make_pair(10,"s"));
		 mp.insert(std::make_pair(15,"s"));
		 mp.insert(std::make_pair(90,"s"));
		 mp.insert(std::make_pair(100,"s"));
		 mp.insert(std::make_pair(60,"s"));
		 mp.insert(std::make_pair(65,"s"));
		 mp.insert(std::make_pair(50,"s"));
		 mp.insert(std::make_pair(200,"s"));
        
		 ft::map<int, std::string> mp2(mp.begin(),mp.end());
		
		mp2.print_with_2D();
		
		// ft_m.print_with_2D();
		// ft::map<int, std::string>::iterator it = ft_m.begin();
		// while(it != ft_m.end()){
		// 	std::cout<<it->first<<" "<<std::endl;
		// 	it++;
		// }
        // std::map<int, std::string> const c_m(m.begin(), m.end());
        // ft::map<int, std::string> const c_ft_m(ft_m.begin(), ft_m.end());
		// std::cout<<"upper bound of 15 is \n";
      	// std::cout<<m.upper_bound(15)->first<< std::endl;
		// std::cout<<ft_m.upper_bound(15)->first<< std::endl;

		std::map<int,std::string>::iterator it = mp.begin();

		while(it != mp.end()){
			std::cout<<it->first<<std::endl;
			it++;
		}
		
		std::cout<<"----------------------------------------\n\n"; 
		
		// std::cout<<"upper bound of 65 is \n";
		// std::cout<<"----------------------------------------\n\n";
		
		std::cout<<mp.upper_bound(22)->first<< std::endl;
		std::cout<<mp2.upper_bound(22)->first<< std::endl;
		// std::cout<<ft_m.upper_bound(65)->first<< std::endl;

		// std::cout<<"upper bound of 63 is \n";
		// std::cout<<"----------------------------------------\n\n";

		// std::cout<<m.upper_bound(63)->first<< std::endl;
		// std::cout<<ft_m.upper_bound(63)->first<< std::endl;
		
		// std::cout<<"upper bound of 120 is \n";
		// std::cout<<"----------------------------------------\n\n";
		
		// std::cout<<m.upper_bound(120)->first<< std::endl;
		// std::cout<<ft_m.upper_bound(120)->first<< std::endl;
		
		// std::cout<<"upper bound of 70 is \n";
		// std::cout<<"----------------------------------------\n\n";

		// std::cout<<m.upper_bound(70)->first<< std::endl;
		// std::cout<<ft_m.upper_bound(70)->first<< std::endl;
		
		// std::cout<<"upper bound of 150 is \n";
		// std::cout<<"----------------------------------------\n\n";
		
		// std::cout<<m.upper_bound(150)->first<< std::endl;
		// std::cout<<ft_m.upper_bound(150)->first<< std::endl;
     	// m.upper_bound(65)->first == ft_m.upper_bound(65)->first;
     	// m.upper_bound(63)->first == ft_m.upper_bound(63)->first;
     	// m.upper_bound(120)->first == ft_m.upper_bound(120)->first;
     	// m.upper_bound(70)->first == ft_m.upper_bound(70)->first;
     	// m.upper_bound(150)->first == ft_m.upper_bound(150)->first;

        // cond = (/*cond &&*/(c_m.upper_bound(15)->first == c_ft_m.upper_bound(15)->first));
        // cond = (/*cond &&*/(c_m.upper_bound(65)->first == c_ft_m.upper_bound(65)->first));
        // cond = (/*cond &&*/(c_m.upper_bound(63)->first == c_ft_m.upper_bound(63)->first));
        // cond = (/*cond &&*/(c_m.upper_bound(120)->first == c_ft_m.upper_bound(120)->first));
        // cond = (/*cond &&*/(c_m.upper_bound(70)->first == c_ft_m.upper_bound(70)->first));
        // cond = (/*cond &&*/(c_m.upper_bound(150)->first == c_ft_m.upper_bound(150)->first));


		
        // std::cout<<m.lower_bound(65)->first<<std::endl;
		// std::cout<<ft_m.lower_bound(65)->first<<std::endl;
        // std::cout<<m.lower_bound(63)->first<<std::endl;
		// std::cout<<ft_m.lower_bound(63)->first<<std::endl;
        // std::cout<<m.lower_bound(120)->first<<std::endl;
		// std::cout<<ft_m.lower_bound(120)->first<<std::endl;
        // std::cout<<m.lower_bound(70)->first<<std::endl;
		// std::cout<<ft_m.lower_bound(70)->first<<std::endl;
	// body<> b("l");
	// b();
	//  std::map<int, int, classcomp> mp;  // class as Compare
	// std::map<int , int> mp;
	
	// mp.insert(std::make_pair(0,"h00ello"));
	// mp.insert(std::make_pair(10,2));
	// mp.insert(std::make_pair(5,2));
	// mp.insert(std::make_pair(15,2));
	// mp.insert(std::make_pair(12,2));
	// mp.insert(std::make_pair(11,2));
	// mp.insert(std::make_pair(13,2));
	// mp.insert(std::make_pair(18,2));

	// if (compareMaps(mp.begin(), mp.end(), mp2.begin(), mp2.end())){
	// }
	// // mp[7] = 80;
	// std::map<char , int> mpo(mp.begin(), mp.end());
	// mpo['z'] = 900;
	// // mp = mpo;
	//  ft::map<int , int > mp2(mp.begin(), mp.end());
	// // mp2.swap(mpo);

	// std::cout<<"--------------mpo---------\n";

	// ft::map<int,int>::iterator mp2_it = mp2.begin();
	// ft::map<int,int>::const_iterator cmp2_it = mp2.begin();

	// if (cmp2_it == mp2_it){
	// 	std::cout<<"e\n";
	// }
	// while(mpo_it != mpo.end()){
	// 	std::cout<<mpo_it->first<<"'\\\\\'"<<mpo_it->second<<std::endl;
	// 	++mpo_it;
	// }

	// std::map<int,int>::reverse_iterator r = mp.rbegin();
	// std::map<int,int>::reverse_iterator r2 = mp.rend();
	// --r;
	// --r;
	// ++r;
	// std::cout<<r->first<<" "<<r->second<<std::endl;
	// --r;
	// std::cout<<r2->first<<" "<<r2->second<<std::endl;
	// std::cout<<r2->first<<" "<<r2->second<<std::endl;

	// std::cout<<rot2->first<<" "<<rot2->second<<std::endl;
	// while(r != mp.rend()){
	// 	// std::cout<<"dora\n";
	// 	std::cout<<r->first<<" "<<r->second<<std::endl;
	// 	r++;
	// 	// break;
	// }

	std::cout<<"==================================\n";

	// ft::map<int,int>::reverse_iterator rot = mp2.rend();
	// rot++;
	// --rot;
	// ++rot;
	// ft::map<int,int>::reverse_iterator rot2 = mp2.rend();
	// --mp2.begin();
	// std::cout<<rot->first<<" "<<rot->second<<std::endl;
	// rot++;
	// --rot;
	// std::cout<<rot->first<<" "<<rot->second<<std::endl;

	// std::cout<<rot2->first<<" "<<rot2->second<<std::endl;
	// while(rot != mp2.rend()){
	// 	// std::cout<<"dora\n";
	// 	std::cout<<rot->first<<" "<<rot->second<<std::endl;
	// 	rot++;
	// }

	std::cout <<"------------------------------\n";
	// mp2 = mpo;
	// mp.insert(std::make_pair(18,"hello"));
	// mp.insert(std::make_pair(10,"hello"));
	// mp.insert(std::make_pair(11,"hesllo"));
	// mp.insert(std::make_pair(13,"hellfo"));

	// std::cout<<mp.count(100)<< std::endl;
	// if (mp.empty()){
	// 	std::cout<<"org map is empty"<<std::endl;
	// }
	// ++it;
	// std::cout<<(it)->first << "////" << (it)->second << std::endl;
	// ++it;
	// std::cout<<(it)->first << "////" << (it)->second << std::endl;
	// ++it;
	// std::cout<<(it)->first << "////" << (it)->second << std::endl;
	// --it;
	// --it;
	// --it;
	// --it = std::make_pair(9,"dqd");
	// std::cout<<(it)->first << "////" << (it)->second << std::endl;
	// mp.clear();
	// std::cout<<(it)->first << "////" << (it)->second << std::endl;
	// std::cout<<mp2.size() << std::endl;
	// std::cout<<mp.erase(1)<< std::endl;
	// std::cout<<mp.erase(122)<< std::endl;
	// mp.erase(mp.begin(), ++mp.begin());
	// std::cout<<mp.size() <<std::endl;
	// std::map<char , int >::const_iterator it = mp.begin();
	// (*it).second = 22;
	// std::pair<std::map<int, std::string>::iterator, bool> p = mp.insert(std::make_pair(10,"ten"));
	// std::cout<<p.first->first<<" "<<p.second<<std::endl;
	// std::map<int, std::string>::iterator ins = mp.insert(mp.begin(), std::make_pair(11,"eleven"));
	// std::cout<<ins->first<<std::endl;
	// mp.insert(mp.begin(), mp.end());
	// std::map<int, std::string>::iterator it = mp.begin();
	// while (it != mp.end()){
	// 	std::cout<<(it)->first << "////" << (it)->second << std::endl;
	// 	it++;
	// }
	// std::map<int,std::string>::key_compare mcop = mp.key_comp();
	// if (mp.value_comp()(*(mp.begin()),*(--mp.end()))){
	// 	std::cout<<mp.begin()->first<<":::"<<mp.begin()->second<<std::endl;
	// }
	std::cout<<"-----------------------------------\n"<<std::endl;
	

	// ft::map<int, std::string>::iterator m_rit = mp2.end();
	// --m_rit;
	// ++m_rit;
	// ++m_rit;
	// ++m_rit;
	// ++m_rit;
	// std::cout<<(m_rit)->first << std::endl;
	// if (mp2.empty()){
	// 	std::cout<<"made map is empty"<<std::endl;
	// }
	// ++myit;
	// mp2.clear();
	// std::cout<<(myit)->first << "////" << (myit)->second << std::endl;
	// ++myit;
	// std::cout<<(myit)->first << "////" << (myit)->second << std::endl;
	// ++myit;
	// std::cout<<(myit)->first << "////" << (myit)->second << std::endl;
	// --myit;
	// --myit;
	// std::cout<<(myit)->first << "////" << (myit)->second << std::endl;

	
	// std::cout<<mp2.erase(122)<< std::endl;
	// mp2.erase(mp2.begin(), (++mp2.begin()));
	// std::cout<<mp2.size() << std::endl;
	// ft::pair<ft::map<int, std::string>::iterator, bool> p2 = mp2.insert(ft::make_pair(10,"ten"));
	// std::cout<<p2.first->first<<" "<<p2.second<<std::endl;
	// ft::map<int, std::string>::iterator ins2 = mp2.insert(mp2.begin(), ft::make_pair(11,"eleven"));
	// std::cout<<ins2->first<<std::endl;
	// mp2.insert(mp.begin(), mp.end());
	// const ft::map<char , int >::iterator myit = mp2.begin();
	// std::cout<<myit->first<<" "<<myit->second<<std::endl;

	// int myints[] = {12, 82, 37, 64, 15};
    // ft::map<int, int> m;
	// int i = 0;
	// while(i < 4){
    //     m.insert(ft::make_pair(myints[i], i));
	// 	i++;
	// }
    // for (size_t i = 0; i < 5; ++i)
    //     m.insert(ft::make_pair(myints[i], i));

	// ft::map<int, char> my_m;
    //     for (int i = 0; i < 1e2; i++)
    //         my_m.insert(ft::make_pair(i, 'A'));

    //     ft::map<int, char>::reverse_iterator my_rit2(my_m.end());
    //     ft::map<int, char>::const_reverse_iterator c_it, c_ob(my_m.end());
    //     c_it = my_rit2;
	// 	std::cout<<c_it->first<< "\\\\" <<my_rit2->first<< "\\\\" <<c_ob->first<<std::endl;
	// 	if (my_rit2->first == c_it->first && my_rit2->first == c_ob->first){
	// 		std::cout<<"ll\n";
	// 	}
				
	// mp2.insert(mp2.begin(),ft::make_pair(100,100));
	// mp2['a'] = 700;
	// mp2[10] = 700;
	// (*myit).second = 22;
	// myit++;
	// std::cout<<myit->first << std::endl;
	// while (myit != mp2.end()){
	// 	std::cout<<myit->first << "////" << myit->second << std::endl;
	// 	myit++;
	// }
	std::cout<<"--------------------------------------------------\n";
	//  ft::map<int,int> mymap;
  	//  ft::map<int,int>::iterator itlow,itup;

  	// 	mymap[1]=20;
  	// 	mymap[2]=40;
  	// 	mymap[4]=60;
  	// 	mymap[5]=80;
  	// 	mymap[6]=100;

  	// itlow = mymap.lower_bound(3);
	// itup =  mymap.upper_bound (5);
	// std::cout<<itlow->first << "\\\\" << itlow->second << std::endl;
	// std::cout<<itup->first << "\\\\" << itup->second << std::endl;

	std::cout<<"=========================================================\n";

// 	std::map<char,int> foo,bar;
//   foo['a']=100;
//   foo['b']=200;
//   bar['a']=10;
//   bar['z']=1000;

  // foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
//   if (foo==bar) std::cout << "foo and bar are equal\n";
//   if (foo!=bar) std::cout << "foo and bar are not equal\n";
//   if (foo< bar) std::cout << "foo is less than bar\n";
//   if (foo> bar) std::cout << "foo is greater than bar\n";
//   if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
//   if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
  
	// ft::map<int,int> m;
  	// ft::map<int,int>::iterator itlow2,itup2;

  	// 	m[1]=20;
  	// 	m[2]=40;
  	// 	m[4]=60;
  	// 	m[5]=80;
  	// 	m[6]=100;

  	// itlow2 = m.lower_bound(3);
	// itup2 =  m.upper_bound(5);
	// std::cout<<itlow2->first << "\\\\" << itlow2->second << std::endl;
	// std::cout<<itup2->first << "\\\\" << itup2->second << std::endl;
	
	// if (m == mymap)
	// 	std::cout<<"equal\n";

// 	ft::map<char,int> mymap;

//   mymap['v']=10;
//   mymap['b']=20;
//   mymap['c']=30;

//   ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
//   ret = mymap.equal_range('v');

//   std::cout << "lower bound points to: ";
//   std::cout << ret.first->first << " => " << ret.first->second << '\n';

//   std::cout << "upper bound points to: ";
//   std::cout << ret.second->first << " => " << ret.second->second << '\n';
	// ft::map<int,std::string>::key_compare mcop2 = mp2.key_comp();
	// if (mp2.value_comp()(*(mp2.begin()), *(--mp2.end()))){
	// 	std::cout<<mp2.begin()->first<<":::"<<mp2.begin()->second<<std::endl;
	// }
	// ++myit;
	// std::cout<<(myit)->first << "////" << (myit)->second << std::endl;
	// ++myit;
	// std::cout<<(myit)->first << "////" << (myit)->second << std::endl;
	// ++myit;
	// std::cout<<(myit)->first << "////" << (myit)->second << std::endl;
	// std::cout<<(--it)->first<<std::endl;
	// std::map<int , std::string>::const_iterator m_it = mp.begin();
	// std::cout<<(m_it--)->first << std::endl;
	// std::cout<<(m_it++)->first << std::endl;
	// std::cout<<(m_it++)->first << std::endl;
	// std::cout<<(m_it--)->first << std::endl;
	// std::cout<<(m_it++)->first << std::endl;
	// std::cout<<(m_it++)->first << std::endl;
	// std::cout<<(m_it++)->first << std::endl;
	// std::cout<<(m_it++)->first << std::endl;
	// std::cout<<(m_it++)->first << std::endl;
	// std::cout<<(m_it)->first << std::endl;
	// std::cout<<(m_it--)->first << std::endl;
	// std::cout<<(m_it)->first << std::endl;
	// int j = 10;
	// ft::map<int, int> mp(10,20);
	// test_comp<int> t;
	// int a = 10;
	// int b = 5;
	// t.print_p(a,b);
	// std::map<int, std::string> m;
//    flow_of_BST();
	// std::vector<int> vec(4,5);
	// for(auto v : vec)
		// std::cout<<v<<std::endl;
	// std::map<std::string,int> mp;
	// mp.insert(std::make_pair("hello",10));
	// mp.insert(std::make_pair("jj",20));
	// std::map<std::string,int,std::greater<std::string>> mp2(mp.begin(),mp.end());
	// for(auto m : mp2)
	// 	std::cout<<m.first<<std::endl;
   //ft::pair<int,std::string> my_pair = ft::make_pair(10,"hello");
   //ft::pair<int, std::string> s_p = my_pair;
   //std::cout<<s_p.first<<std::endl;
}

// // map::lower_bound/upper_bound
// #include <iostream>
// #include <map>

// int main ()
// {
//   std::map<char,int> mymap;
//   std::map<char,int>::iterator itlow,itup;

//   mymap['a']=20;
//   mymap['b']=40;
//   mymap['c']=60;
//   mymap['d']=80;
//   mymap['e']=100;

//   itlow=mymap.lower_bound ('b');  // itlow points to b
//   itup=mymap.upper_bound ('e');   // itup points to e (not d!)

//   mymap.erase(itlow,itup);        // erases [itlow,itup)

//   // print content:
//   for (std::map<char,int>::iterator it=mymap.begin(); it != mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

//   return 0;
// }



// int main ()
// {
//   std::map<char,int> mymap;

//   mymap['x']=1001;
//   mymap['y']=2002;
//   mymap['z']=3003;

//   std::cout << "mymap contains:\n";

//   std::pair<char,int> highest = *mymap.rbegin();          // last element

//   std::map<char,int>::iterator it = mymap.begin();
//   do {
//     std::cout << it->first << " => " << it->second << '\n';
//   } while ( mymap.value_comp()(*it++, highest) );

//   return 0;
// }