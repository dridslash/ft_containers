/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:58:17 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/12/15 17:37:31 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CONT_MAP__HPP
#define _CONT_MAP__HPP

#include "AVL_Tree.hpp"
#include <iostream>
#include "Pair.hpp"
#include "Map_iterator.hpp"
#include "struct_utils.hpp"

namespace ft{
    template<class Key , class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
    class map{
    public:
      typedef Key                                                                                                                                                  key_type;
      typedef T                                                                                                                                                    mapped_type;
      typedef ft::pair<const key_type, mapped_type>                                                                                                                value_type;
      typedef Compare                                                                                                                                              key_compare;
      class value_compare : public std::binary_function<value_type, value_type, bool>{
        friend class map;
          protected:
            Compare comp;
            value_compare(key_compare c) : comp(c){} 
          public:
            bool operator() (const value_type& x, const value_type& y)const{
                return comp(x.first , y.first);
            }
      };
      typedef Allocator                                                                                                                                            allocator_type;
      typedef typename allocator_type::reference                                                                                                                   reference;
      typedef typename allocator_type::const_reference                                                                                                             const_reference;
      typedef typename allocator_type::pointer                                                                                                                     pointer;
      typedef typename allocator_type::const_pointer                                                                                                               const_pointer;
      typedef typename allocator_type::size_type                                                                                                                   size_type;
      typedef typename allocator_type::difference_type                                                                                                             difference_type;
      typedef AVL_Tree<key_type,mapped_type,allocator_type,key_compare, size_type>                                                                                 Node_type;
      typedef BI_Iterator<key_type, mapped_type, allocator_type, key_compare ,value_type, size_type, Node_type , tree_node<key_type, mapped_type> >                iterator;
      typedef BI_Iterator<key_type, mapped_type, allocator_type, key_compare , const value_type, size_type,const Node_type , tree_node<key_type, mapped_type> >    const_iterator;
      typedef BI_Reverse_iterator<iterator>                                                                                                                        reverse_iterator;
      typedef BI_Reverse_iterator<const_iterator>                                                                                                                  const_reverse_iterator;
          
          explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):_allocator(alloc),_tree(Node_type()){(void)comp;}

          template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):_allocator(alloc), _tree(Node_type()){
              (void)comp;
              insert(first, last);
          }
          
            map (const map& x){
                clear();
                insert(x.begin(), x.end());
            }

          ~map(){
              clear();
          }
        
        iterator begin(){
          if (!_tree.root){
            return (iterator());
          }
          return (iterator(_tree.min_node_value(_tree.root),&(_tree), _tree.min_node_value(_tree.root)->pr,nullptr));
        }
        
        const_iterator begin() const{
            if (!_tree.root){
            return (const_iterator(nullptr,&(_tree),nullptr,nullptr));
          }
          return (const_iterator(_tree.min_node_value(_tree.root),&(_tree), _tree.min_node_value(_tree.root)->pr,nullptr));
        }
        
        iterator end(){
          if (!_tree.root){
            return (iterator());
          }
          return (iterator(nullptr,&(_tree), nullptr,_tree.max_node_value(_tree.root)));
        }

        const_iterator end() const{
          if (!_tree.root){
            return (const_iterator());
          }
          return (const_iterator(nullptr,&(_tree), nullptr,_tree.max_node_value(_tree.root)));
        }

        size_type size()const{
           return (_tree.get_size());
        }

        void clear(){
          _tree.Destroy_map();
          //_m_size = 0;
        }

        size_type count(const key_type& k)const{
            if (_tree.Recursive_Search(_tree.root, k)){
                return (1);
            }
            return (0);
        }

        bool empty()const{
            return (size() == 0);
        }

        void erase(iterator position){
           tree_node<key_type,mapped_type>* r = _tree.Recursive_Search(_tree.root,position->first);
           if (r)
            _tree.root = _tree.delete_node(_tree.root, position->first);
        }

        void BFS(){
          _tree.BFS_print(_tree.root);
        }

        size_type erase(const key_type& k){
          tree_node<key_type,mapped_type>* r = _tree.Recursive_Search(_tree.root,k);
           if (r){
          _tree.root = _tree.delete_node(_tree.root,k);
          return (1);
           }
           return (0);
          // size_type clone_size = _m_size;
          // if (clone_size == _m_size)
          //   return (0);
        }

        void erase (iterator first, iterator last){
          map tmp;
          tmp.insert(first, last);
          for (iterator it = tmp.begin(); it != tmp.end(); it++){
            _tree.root = _tree.delete_node(_tree.root, it->first);
          }
        }

        iterator find(const key_type& k){
          tree_node<key_type,mapped_type>* r = _tree.Recursive_Search(_tree.root,k);
          if (r)
            return (iterator(r,&(_tree), r->pr,nullptr));
          else
            return (iterator());
        }
      
        const_iterator find (const key_type& k) const{
          tree_node<key_type,mapped_type>* r = _tree.Recursive_Search(_tree.root,k);
          if (r)
            return (const_iterator(r,&(_tree), r->pr,nullptr));
          else
            return (const_iterator());
        }

        allocator_type get_allocator()const{
          return (_allocator);
        }

        ft::pair<iterator,bool> insert(const value_type& val){
          if (!_tree.Recursive_Search(_tree.root, val.first)){
              _tree.root = _tree.Recursive_insert(_tree.root, _tree.construct_map(val.first,val.second));
              return (ft::make_pair(iterator(_tree.Recursive_Search(_tree.root,val.first), &(_tree), _tree.Recursive_Search(_tree.root,val.first)->pr,nullptr),true));
          }
          return (ft::make_pair(iterator(_tree.Recursive_Search(_tree.root,val.first), &(_tree), _tree.Recursive_Search(_tree.root,val.first)->pr,nullptr),false));
        }

        iterator insert (iterator position, const value_type& val){
          (void)position;
          _tree.root = _tree.Recursive_insert(_tree.root, _tree.construct_map(val.first,val.second));
          return (iterator(_tree.Recursive_Search(_tree.root,val.first),&(_tree), _tree.Recursive_Search(_tree.root,val.first)->pr,nullptr));
        }

        template <class InputIterator>
          void insert (InputIterator first, InputIterator last,
            typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = nullptr){
            while(first != last){
                _tree.root = _tree.Recursive_insert(_tree.root, _tree.construct_map(first->first,first->second));
                first++;
            }
        }

        key_compare key_comp()const{
           return (key_compare());
        }

        iterator lower_bound (const key_type& k){
          
          iterator it = find(k);
          if (it != end())
            return (it);
          it = begin();
          while(it != end()){
            if (it->first >= k)
              break;
              it++;
          }
          return (it);
          
        //  tree_node<key_type,mapped_type>* r = _tree.lower_bound(_tree.root, k);
          
        //   if (!r)
        //       return (iterator(end()));
        //     return (iterator(r, &(_tree), r->pr,nullptr));
        }

        const_iterator lower_bound (const key_type& k) const{
          
          const_iterator it = find(k);
          if (it != end())
            return (it);
          it = begin();
          while(it != end()){
            if (it->first >= k)
              break;
              it++;
          }
          return (it);

          // tree_node<key_type,mapped_type>* r = _tree.lower_bound(_tree.root, k);
          
          // if (!r)
          //     return (const_iterator(end()));
          //   return (const_iterator(r, &(_tree), r->pr,nullptr));
        }

        void print_with_2D(){
            _tree.print2D(_tree.root,5);
        }

        size_type max_size()const{
            return (_allocator.max_size());
        }

        reverse_iterator rbegin(){
           return (reverse_iterator(end()));
        }

        const_reverse_iterator rbegin() const{
            return (const_reverse_iterator(end()));
        }

        reverse_iterator rend(){
          return (reverse_iterator(begin()));
        }

        const_reverse_iterator rend() const{
          return (const_reverse_iterator(begin()));
        }

        void swap (map& x){
          Node_type tmp_tree = _tree;
          _tree = x._tree;
          x._tree = tmp_tree;
          
        }

        iterator upper_bound (const key_type& k){
          // iterator it = begin();
          // while(it != end()){
          //   if (it->first > k)
          //     break;
          //     it++;
          // }
          // return (it);

          tree_node<key_type,mapped_type>* r = _tree.upper_bound(_tree.root, k);
          if (r)
            return (iterator(r,&(_tree), r->pr,nullptr));
          return (iterator());
        }
        
        const_iterator upper_bound (const key_type& k) const{
        //  const_iterator it = begin();
        //   while(it != end()){
        //     if (it->first > k)
        //       break;
        //       it++;
        //   }
        //   return (it);
        tree_node<key_type,mapped_type>* r = _tree.upper_bound(_tree.root, k);
          if (r)
            return (const_iterator(r,&(_tree), r->pr,nullptr));
          return (const_iterator());
        }
        
        ft::pair<iterator,iterator> equal_range (const key_type& k){
            return (ft::make_pair(lower_bound(k), upper_bound(k)));
        }
        ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const{
            return (ft::make_pair(lower_bound(k), upper_bound(k)));
        }
        

        value_compare value_comp()const{
            return (value_compare(key_comp()));
        }

        mapped_type& operator[](const key_type& k){
            if (_tree.Recursive_Search(_tree.root, k)){
                return ((*(_tree.Recursive_Search(_tree.root, k)->pr)).second);
            }
            return ((this->insert(ft::make_pair(k,mapped_type())).first)->second);
        }

        map& operator=(const map& x){
            clear();
            insert(x.begin(), x.end());
            return (*this);
        }

      template <class K, class T2, class Comp, class Alloc> 
        friend bool operator==(const map<K,T2,Comp,Alloc>& lhs, const map<K,T2,Comp,Alloc>& rhs){
        if (lhs.size() == rhs.size()){
            return(ft::map_equal(lhs.begin(),lhs.end(),rhs.begin()));
        }
        return(false);
    }
    	
    template <class K, class T2, class Comp, class Alloc>
      friend bool operator!=(const map<K,T2,Comp,Alloc>& lhs, const map<K,T2,Comp,Alloc>& rhs){
        if (lhs.size() == rhs.size())
        return(!ft::equal(lhs.begin(),lhs.end(),rhs.begin()));
        return (true);
    }

    template <class K, class T2, class Comp, class Alloc>
      friend bool operator<(const map<K,T2,Comp,Alloc>& lhs, const map<K,T2,Comp,Alloc>& rhs){
        if (lhs.size() < rhs.size())
            return (true);
        else
            return(ft::lexicographical_compare_map(lhs.begin(),lhs.end(),rhs.begin(),rhs.end()));
        return (false);
    }

    template <class K, class T2, class Comp, class Alloc>
      friend bool operator<=(const map<K,T2,Comp,Alloc>& lhs, const map<K,T2,Comp,Alloc>& rhs){
        return (!(rhs < lhs));
    }

    template <class K, class T2, class Comp, class Alloc>
      friend bool operator>(const map<K,T2,Comp,Alloc>& lhs, const map<K,T2,Comp,Alloc>& rhs){
        return (rhs < lhs);
    }

    template <class K, class T2, class Comp, class Alloc>
      friend bool operator>=(const map<K,T2,Comp,Alloc>& lhs, const map<K,T2,Comp,Alloc>& rhs){
        return (!(lhs < rhs));
    }

    template <class K, class T2, class Comp, class Alloc> 
    friend void swap (const map<K,T2,Comp,Alloc>& x, const map<K,T2,Comp,Alloc>& y){
        x.swap(y);
    }


    private:
      allocator_type      _allocator;
      // size_type           _m_size;
      Node_type           _tree;
    };
}

#endif