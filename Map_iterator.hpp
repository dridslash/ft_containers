/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:36:04 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/12/14 09:41:24 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAP_ITERATOR_
#define __MAP_ITERATOR_

#include "AVL_Tree.hpp"
#include "Pair.hpp"
#include <iostream>


   //p- /////////////---Iterator_TRAITS----/////////////
namespace ft{
   
    template<class Iterator>
    struct iterator_traits_map{
       typedef typename Iterator::value_type           value_type;
       typedef typename Iterator::difference_type      difference_type;
       typedef typename Iterator::pointer              pointer;
       typedef typename Iterator::reference            reference;
       typedef typename Iterator::iterator_category    iterator_category;
    };
    
    template<class T>
    struct iterator_traits_map<T*>{
       typedef T                                value_type;
       typedef std::ptrdiff_t                   difference_type;
       typedef T*                               pointer;
       typedef T&                               reference;
       typedef std::bidirectional_iterator_tag  iterator_category;
    };

    template<class T>
    struct iterator_traits_map<const T*>{
       typedef T                                value_type;
       typedef std::ptrdiff_t                   difference_type;
       typedef const T*                         pointer;
       typedef const T&                         reference;
       typedef std::bidirectional_iterator_tag  iterator_category;
    };

   //p- ///////////////////////////END/////////////////////////////////

   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   //b- ---------------------------CLASS_BIDIRECTIONAL_ITERATOR-----------------------------//
   template<class key, class maped_value, class Allocator , class key_compare, class key_mapped_pair, class size_type,class Node_type, class tree_node>
   class BI_Iterator{
      public:
         typedef  typename iterator_traits_map<key_mapped_pair*>::value_type           value_type;
         typedef  typename iterator_traits_map<key_mapped_pair*>::pointer              pointer;
         typedef  typename iterator_traits_map<key_mapped_pair*>::reference            reference;
         typedef  typename iterator_traits_map<key_mapped_pair*>::difference_type      difference_type;
         typedef  typename iterator_traits_map<key_mapped_pair*>::iterator_category     iterator_category;

   //b- --------------------------CONSTRUCTORS/DES --------------------------------///
         
         typedef tree_node* node_ptr;
         typedef Node_type* avl_tree;
         typedef ft::pair<const key,maped_value>* it_pair;
         key_compare comp;

         
         BI_Iterator():_this_node(nullptr), _tree_object(nullptr), _iterator_pair(nullptr),_dummy_node(nullptr){}
         
         BI_Iterator(node_ptr node, avl_tree _tree, it_pair pr, node_ptr dummy):_this_node(node),_tree_object(_tree), _iterator_pair(pr),_dummy_node(dummy){}
      
         BI_Iterator(const BI_Iterator& it){_this_node = it._this_node;_tree_object = it._tree_object;_iterator_pair = it._iterator_pair;_dummy_node = it._dummy_node;}

         ~BI_Iterator(){}

         operator BI_Iterator<key,  maped_value, Allocator, key_compare, const key_mapped_pair, size_type, const Node_type , tree_node>(){
            return (BI_Iterator<key,  maped_value, Allocator, key_compare, const key_mapped_pair, size_type, const Node_type , tree_node>(_this_node,_tree_object,_iterator_pair,_dummy_node));}

         
   //b- /////////////////________MEMBER_____FUNCTIONS___________///////////////////////
         
         BI_Iterator& operator=(const BI_Iterator& it){_this_node = it._this_node;_tree_object = it._tree_object;_iterator_pair = it._iterator_pair;_dummy_node = it._dummy_node; return ((*this));}
         
         reference operator*()const{return *(_iterator_pair);}

         node_ptr base()const{return (_this_node);}

         pointer operator->()const{return &(this->operator*());}
         
         BI_Iterator operator++(int){
            BI_Iterator tmp(*this);
            ++(*this);
            return (tmp);
         }

         BI_Iterator& operator++(){
            if (!_this_node && _dummy_node->right_node && _tree_object){
               _this_node = _dummy_node;
               _iterator_pair = _this_node->pr;
            }
             else if (_this_node && _this_node->right_node && _tree_object){
               _this_node = _tree_object->min_node_value(_this_node->right_node);
               _iterator_pair = _this_node->pr;
                return (*this);
            }
            else{
               if (_tree_object){
               node_ptr parent = _tree_object->Get_parent_of_node(_tree_object->root,_this_node,nullptr);
               while(parent && comp(parent->pr->first , _this_node->pr->first)){
                  parent = _tree_object->Get_parent_of_node(_tree_object->root,parent,nullptr);
               }
               if (!parent){
                  _this_node = nullptr;
                   _iterator_pair = nullptr;
                   _dummy_node = nullptr;
               }else{
               _this_node = parent;
               _iterator_pair = _this_node->pr;
               _dummy_node = nullptr;
               }
               }
            }
            return (*this);
         }
         
         BI_Iterator operator--(int){
            BI_Iterator tmp(*this);
            --(*this);
            return (tmp);
         }

         BI_Iterator operator--(){
            if (!_this_node && _dummy_node && _tree_object){
               _this_node = _dummy_node;
               _iterator_pair = _this_node->pr;
            }
            else if (_this_node && _this_node->left_node && _tree_object){
               _this_node = _tree_object->max_node_value(_this_node->left_node);
               _iterator_pair = _this_node->pr;
               return (*this);
            }
            else{
               if (_tree_object){
               node_ptr parent = _tree_object->Get_parent_of_node(_tree_object->root,_this_node,nullptr);
               while(parent && comp(_this_node->pr->first , parent->pr->first)){
                  parent = _tree_object->Get_parent_of_node(_tree_object->root,parent,nullptr);
               }
               if (!parent){
                  _this_node = nullptr;
                   _iterator_pair = nullptr;
                   _dummy_node = nullptr;
               }
               else{
                   _this_node = parent;
                  _iterator_pair = _this_node->pr;
                  _dummy_node = nullptr;
               }
               }
            }
            return (*this);
         }


   //b- ------------______GENERIC_FUNCTIONS_________-------------//////////

         template <class Iter, class Iter2>
             friend bool operator==(const Iter& lhs, const Iter2& rhs){
              //if (!lhs.base() && !rhs.base())
              //   return true;
               //if (lhs.base() && rhs.base())
                  return (lhs.base() == rhs.base());
               //return false;
               }
         template <class Iter, class Iter2>
            friend bool operator!=(const Iter& lhs, const Iter2& rhs){return (!(lhs.base() == rhs.base()));}

         private:
            node_ptr _this_node;
            avl_tree _tree_object;
            it_pair  _iterator_pair;
            node_ptr _dummy_node;
   };
   
   //r-///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   //r-///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   
//    //y- ----------------------------CLASS-_REVERSE_ITERATOR_-----------------------------//
    
     template<class BI_Iterator> class BI_Reverse_iterator{
      public:
         typedef  typename iterator_traits_map<BI_Iterator>::value_type                             value_type;
         typedef  BI_Iterator                                                                       iterator_type;
         typedef  typename iterator_traits_map<BI_Iterator>::pointer                                pointer;
         typedef  typename iterator_traits_map<BI_Iterator>::reference                              reference;
         typedef  typename iterator_traits_map<BI_Iterator>::difference_type                        difference_type;
         typedef  typename iterator_traits_map<BI_Iterator>::iterator_category                      iterator_category;

//    //y- --------------------------CONSTRUCTORS/DES --------------------------------///
         
         
         BI_Reverse_iterator():current(){}

         explicit BI_Reverse_iterator (iterator_type it):current(it){}
         
         template <class Iter>
            BI_Reverse_iterator(const BI_Reverse_iterator<Iter>& rev_it){current = rev_it.base();}
         
         ~BI_Reverse_iterator(){}

         
//    //y- /////////////////________MEMBER_____FUNCTIONS___________///////////////////////
         
         
         iterator_type base()const{return (current);}

         reference operator*(){BI_Reverse_iterator b_tmp(*this);b_tmp.current--; return *(b_tmp.current);}

         // reference operator[] (difference_type n) const{return *(current - 1 - n);}

         pointer operator->(){return &(this->operator*());}
         
         // Reverse_iterator& operator+=(difference_type n){current -= n ; return (*this);}

      //   Reverse_iterator& operator-=(difference_type n){current += n ; return (*this);}

         // Reverse_iterator operator-(difference_type n ){return Reverse_iterator(current + n);}

         // Reverse_iterator operator+(difference_type n ){return Reverse_iterator(current - n);}

         BI_Reverse_iterator operator++(int){BI_Reverse_iterator tmp (*this); --(current); return (tmp);}

         BI_Reverse_iterator& operator++(){--(current); return (*this);}
         
         BI_Reverse_iterator operator--(int){BI_Reverse_iterator tmp(*this); ++(current); return (tmp);}

         BI_Reverse_iterator operator--(){++(current); return (*this);}


//    //y- -------------______GENERIC_FUNCTIONS_________-------------//////////
         
         // template <class T>
         //    friend difference_type operator-(const Reverse_iterator<T>& lhs, const Reverse_iterator<T>& rhs){
         //     return (static_cast<difference_type>(rhs.base() - lhs.base()));
         // }

         // template <class T>
         //    friend Reverse_iterator operator+(difference_type n,const Reverse_iterator<T>& rev_it){
         //       return (Reverse_iterator(rev_it.base() - n));
         // }

         // template <class T>
         //    friend difference_type operator+(const Reverse_iterator<T>& lhs, const Reverse_iterator<T>& rhs){
         //     return (static_cast<difference_type>(rhs.base() + lhs.base()));
         // }
         
         template <class Iter>
            bool operator==(const BI_Reverse_iterator<Iter>& rhs){return (current == rhs.base());}
         template <class Iter>
            bool operator!=(const BI_Reverse_iterator<Iter>& rhs){return !(current == rhs.base());}
         // template <class Iter>
         //    bool operator<(const Reverse_iterator<Iter>& rhs){return (current > rhs.base());}
         // template <class Iter>
         //    bool operator<=(const Reverse_iterator<Iter>& rhs){return (current >= rhs.base());}
         // template <class Iter>
         //    bool operator>(const Reverse_iterator<Iter>& rhs){return (current < rhs.base());}
         // template <class Iter>
         //    bool operator>=(const Reverse_iterator<Iter>& rhs){return (current <= rhs.base());}

          protected:
            BI_Iterator current;
   };
}
#endif