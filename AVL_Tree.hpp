/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVL_Tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:40:11 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/12/15 17:10:15 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AVL_TREE___HPP
#define __AVL_TREE___HPP


#include <iostream>
#include "Pair.hpp"

#define GBL_SP 5


 template<class T1, class T2> class tree_node{
    public:
    ft::pair<const T1, T2> *pr;
    tree_node<T1,T2>* left_node;
    tree_node<T1,T2>* right_node;
    tree_node<T1,T2>* parent_node;
    int height;
    
    tree_node(){
        pr = nullptr;
        left_node = nullptr;
        right_node = nullptr;
        parent_node = nullptr;
        height = 0;
    }
    
    tree_node(ft::pair<T1,T2>& p):pr(p){
        left_node = nullptr;
        right_node = nullptr;
        parent_node = nullptr;
        height = 0;
    }
};

template<class key, class maped_value, class Allocator , class key_compare , class size_type> class AVL_Tree{
    public:
    typedef Allocator allocator_type_pair;
	typedef typename Allocator::template rebind<tree_node<key,maped_value> >::other allocator_type_node;
	allocator_type_node alloc_node;
	allocator_type_pair alloc_pair;
    tree_node<key,maped_value> *root;
    size_type size;
    key_compare comp;
    
    AVL_Tree();

    
    tree_node<key,maped_value>* Recursive_insert(tree_node<key,maped_value>* r, tree_node<key,maped_value>* new_node);
    void BFS_print(tree_node<key,maped_value>* r);
	void DFS_print(tree_node<key,maped_value>* r);
    tree_node<key,maped_value>* Get_parent_of_node(tree_node<key,maped_value>* r, tree_node<key,maped_value>* node, tree_node<key,maped_value>* parent_tmp)const;
	void print_given_level(tree_node<key,maped_value>*r , int level);
    void print2D(tree_node<key,maped_value>* r, int space);
	int height_tree(tree_node<key,maped_value>* r);
	tree_node<key,maped_value>* Recursive_Search(tree_node<key,maped_value>* r, key val)const;
	tree_node<key,maped_value>* delete_node(tree_node<key,maped_value> *r , key val);
	tree_node<key,maped_value>* min_node_value(tree_node<key,maped_value>* r)const;
    tree_node<key,maped_value>* max_node_value(tree_node<key,maped_value>* r)const;
	int balance_factor(tree_node<key,maped_value>* r);
    tree_node<key,maped_value>* Left_Rotate(tree_node<key,maped_value>* r);
	tree_node<key,maped_value>* Right_Rotate(tree_node<key,maped_value>* r);
	tree_node<key,maped_value>* Balance_insert(tree_node<key,maped_value>* r,tree_node<key,maped_value>* new_node);
	tree_node<key,maped_value>* Balance_delete(tree_node<key,maped_value>* r);
    tree_node<key,maped_value>* construct_map(key k , maped_value m_v);
    void  Destroy_map();
    tree_node<key,maped_value>* lower_bound(tree_node<key,maped_value>* r, key k)const;
    tree_node<key,maped_value>* upper_bound(tree_node<key,maped_value>* r, key k)const;
    size_type get_size()const;
};

#include "AVL_Tree.tpp"

#endif