/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVL_Tree.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:55:49 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/12/16 09:58:41 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template <class key, class maped_value, class Allocator,  class key_compare , class size_type>
AVL_Tree<key, maped_value , Allocator, key_compare , size_type>::AVL_Tree():root(nullptr),size(0){}


template <class key, class maped_value, class Allocator,  class key_compare , class size_type>
void  AVL_Tree<key, maped_value , Allocator, key_compare , size_type>::Destroy_map(){
		while(root && size > 0){
        	root = delete_node(root,root->pr->first);
    	}
}


template <class key, class maped_value, class Allocator,  class key_compare , class size_type>
size_type AVL_Tree<key, maped_value , Allocator, key_compare , size_type>::get_size()const{
	return (size);
}


template <class key, class maped_value, class Allocator,  class key_compare , class size_type>
tree_node<key,maped_value>* AVL_Tree<key, maped_value , Allocator, key_compare , size_type>::Left_Rotate(tree_node<key,maped_value>* r){
	tree_node<key,maped_value>* node_rt1 = r->right_node;
	tree_node<key,maped_value>* get_left_child  = node_rt1->left_node;

	//be- Left Rotate operation

	node_rt1->left_node = r;
	r->right_node = get_left_child;
	
	r->height = 1 + std::max(height_tree(r->left_node),height_tree(r->right_node));
	node_rt1->height = 1 + std::max(height_tree(node_rt1->left_node),height_tree(node_rt1->right_node));

	return (node_rt1);
}



template <class key, class maped_value, class Allocator,  class key_compare , class size_type>
tree_node<key,maped_value>* AVL_Tree<key, maped_value , Allocator, key_compare , size_type>::Right_Rotate(tree_node<key,maped_value>* r){
	tree_node<key,maped_value>* node_rt1 = r->left_node;
	tree_node<key,maped_value>* get_right_child  = node_rt1->right_node;

	//be- Right Rotate operation

	node_rt1->right_node = r;
	r->left_node = get_right_child;

	r->height = 1 + std::max(height_tree(r->left_node),height_tree(r->right_node));
	node_rt1->height = 1 + std::max(height_tree(node_rt1->left_node),height_tree(node_rt1->right_node));

	return (node_rt1);
}

template <class key, class maped_value, class Allocator,  class key_compare , class size_type>
int AVL_Tree<key, maped_value , Allocator, key_compare , size_type>::balance_factor(tree_node<key,maped_value>* r){
	if (!r)
		return (-1);
	return (height_tree(r->left_node) - height_tree(r->right_node));
}

template <class key, class maped_value, class Allocator,  class key_compare , class size_type>
tree_node<key,maped_value>* AVL_Tree<key, maped_value , Allocator, key_compare , size_type>::min_node_value(tree_node<key,maped_value>* r)const{
	tree_node<key,maped_value>* current_node = r;
	while(current_node->left_node)
		current_node = current_node->left_node;
	return(current_node);
}


template <class key, class maped_value, class Allocator,  class key_compare , class size_type>
tree_node<key,maped_value>* AVL_Tree<key, maped_value , Allocator, key_compare , size_type>::max_node_value(tree_node<key,maped_value>* r)const{
	tree_node<key,maped_value>* current_node = r;
	while(current_node->right_node)
		current_node = current_node->right_node;
	return(current_node);
}


template <class key, class maped_value, class Allocator,  class key_compare , class size_type>
tree_node<key,maped_value>* AVL_Tree<key, maped_value , Allocator, key_compare , size_type>::Balance_delete(tree_node<key,maped_value>* r){
	
	int bf = balance_factor(r);
		
		//g- Left Left imbalance

		if (bf == 2 && balance_factor(r->left_node) >= 0){
			return (Right_Rotate(r));
		}
		//g- Left Right imbalance
		else if (bf == 2 && balance_factor(r->left_node) == -1){
			r->left_node = Left_Rotate(r->left_node);
			return (Right_Rotate(r));
		}
		//g- Right Right imbalance
		else if (bf == -2 && balance_factor(r->right_node) <= 0){
			return (Left_Rotate(r));
		}
		//g- Right Left imbalance
		else if (bf == -2 && balance_factor(r->right_node) == 1){
			r->right_node = Right_Rotate(r->right_node);
			return (Left_Rotate(r));
		}
    return (r);
}

template <class key, class maped_value, class Allocator,  class key_compare , class size_type>
tree_node<key,maped_value>* AVL_Tree<key, maped_value , Allocator, key_compare , size_type>::delete_node(tree_node<key,maped_value> *r , key val){
	if (!r)
		return (r);
	else if (comp(val, r->pr->first)){ // val < r->pr.first
		r->left_node = delete_node(r->left_node, val);	
	}
	else if (comp(r->pr->first, val)){ // val > r->pr.first
		r->right_node = delete_node(r->right_node,val);
	}
	else{

		//y- node have a left child or no child
		if (!(r->right_node)){
			tree_node<key,maped_value>* tmp;
			if (r->left_node)
				tmp = r->left_node;
			else
				tmp = NULL;
			
			alloc_pair.destroy(r->pr);
			alloc_pair.deallocate(r->pr,1);
			alloc_node.destroy(r);
			alloc_node.deallocate(r,1);
			size--;
			return (tmp);
		}
		//y- node have a right child or no child
		else if (!(r->left_node)){
			tree_node<key,maped_value>* tmp;
			if (r->right_node)
				tmp = r->right_node;
			else
				tmp = NULL;

			alloc_pair.destroy(r->pr);
			alloc_pair.deallocate(r->pr,1);
			alloc_node.destroy(r);
			alloc_node.deallocate(r,1);
			size--;
			return (tmp);
		}
		else{
			tree_node<key,maped_value>* tmp = min_node_value(r->right_node);
			alloc_pair.destroy(r->pr);
			alloc_pair.construct(r->pr, ft::make_pair(tmp->pr->first, tmp->pr->second));
			r->right_node = delete_node(r->right_node, tmp->pr->first);
		}
	}
	r->height = 1 + std::max(height_tree(r->left_node),height_tree(r->right_node));
	return (Balance_delete(r));
}

template <class key, class maped_value, class Allocator,  class key_compare , class size_type>
tree_node<key,maped_value>* AVL_Tree<key, maped_value , Allocator, key_compare , size_type>::Recursive_Search(tree_node<key,maped_value>* r, key val)const{
	if (!r)
		return (r);
	if (comp(val, r->pr->first)) // v < r->pr.first
		return (Recursive_Search(r->left_node,val));
	else if (comp(r->pr->first, val)) // v > r->pr.first
		return (Recursive_Search(r->right_node,val));
	else
		return (r);
}

template <class key, class maped_value, class Allocator,  class key_compare , class size_type>
int AVL_Tree<key, maped_value , Allocator, key_compare , size_type>::height_tree(tree_node<key,maped_value>* r){
	if (!r)
		return (0);

	return (r->height);
}

template <class key, class maped_value, class Allocator,  class key_compare , class size_type>
tree_node<key,maped_value>* AVL_Tree<key, maped_value , Allocator, key_compare , size_type>::Balance_insert(tree_node<key,maped_value>* r,tree_node<key,maped_value>* new_node){
     int bf = balance_factor(r);
	
	//b- Left Left imbalance
	if (bf > 1 && comp(new_node->pr->first, r->left_node->pr->first)){//- new_node->pr.first < r->left_node->pr.first
		return (Right_Rotate(r));
	}
	//b- Right Right imbalance
	else if (bf < -1 && comp(r->right_node->pr->first, new_node->pr->first)){//- new_node->pr.first > r->right_node->pr.first
		return (Left_Rotate(r));
	}
	//b- Left Right imbalance
	else if (bf > 1 && comp(r->left_node->pr->first, new_node->pr->first)){//- new_node->pr.first > r->left_node->pr.first
		r->left_node = Left_Rotate(r->left_node);
		return (Right_Rotate(r));
	}
	//b- Right Left imbalance
	else if (bf < -1 && comp(new_node->pr->first,r->right_node->pr->first)){//- new_node->pr.first < r->left_node->pr.first
		r->right_node = Right_Rotate(r->right_node);
		return (Left_Rotate(r));
	}
    return (r);
}

template <class key, class maped_value, class Allocator,  class key_compare , class size_type>
tree_node<key,maped_value>* AVL_Tree<key, maped_value , Allocator, key_compare , size_type>::Recursive_insert(tree_node<key,maped_value>* r, tree_node<key,maped_value>* new_node){
    if (!r){
        r = new_node;
        size++;
		return (r);    
    }
    else if (comp(new_node->pr->first, r->pr->first)){//-  new_node->pr.first < r->pr.first
		r->left_node = Recursive_insert(r->left_node, new_node);
    }
    else if (comp(r->pr->first, new_node->pr->first)){//-  new_node->pr.first > r->pr.first
        r->right_node = Recursive_insert(r->right_node,new_node);
    }
	else{
		alloc_pair.destroy(new_node->pr);
		alloc_node.destroy(new_node);
		alloc_pair.deallocate(new_node->pr,1);
		alloc_node.deallocate(new_node,1);
		return (r);
	}
	r->height = 1 + std::max(height_tree(r->left_node),height_tree(r->right_node));
    return (Balance_insert(r,new_node));
}

template <class key, class maped_value, class Allocator,  class key_compare , class size_type>
void AVL_Tree<key, maped_value , Allocator, key_compare , size_type>::print2D(tree_node<key,maped_value>* r, int space){
    if (!r)
        return;
    space = space + GBL_SP;
    print2D(r->right_node, space);
    std::cout<<std::endl;
    for(int i = GBL_SP ; i < space; i++)
        std::cout<<" ";
    std::cout<<r->pr->first<<std::endl;
    print2D(r->left_node, space);
    
}

template <class key, class maped_value, class Allocator,  class key_compare , class size_type>
void AVL_Tree<key, maped_value , Allocator, key_compare , size_type>::print_given_level(tree_node<key,maped_value>* r , int level){
	if (!r)
		return;
	else if (level == 0)
		std::cout<<r->pr->first<<std::endl;
	else{
		print_given_level(r->left_node, level - 1);
		print_given_level(r->right_node, level - 1);
	}
}

template <class key, class maped_value, class Allocator,  class key_compare , class size_type>
void AVL_Tree<key, maped_value , Allocator, key_compare , size_type>::BFS_print(tree_node<key,maped_value>* r){
	for(int i = 0; i <= height_tree(r) ; i++)
		print_given_level(r, i);
}

template <class key, class maped_value, class Allocator,  class key_compare , class size_type>
void AVL_Tree<key, maped_value , Allocator, key_compare , size_type>::DFS_print(tree_node<key,maped_value>* r){
	if (!r)
		return;
	DFS_print(r->left_node);
	std::cout<<r->pr->first<<std::endl;
	DFS_print(r->right_node);
}


template <class key, class maped_value, class Allocator,  class key_compare , class size_type>
    tree_node<key,maped_value>* AVL_Tree<key, maped_value , Allocator, key_compare , size_type>::construct_map(key k , maped_value m_v){
		
		tree_node<key,maped_value>* node = alloc_node.allocate(1);
		alloc_node.construct(node, tree_node<key,maped_value>());
		node->left_node = nullptr;
		node->pr = alloc_pair.allocate(1);
		node->height = 1;
		alloc_pair.construct(node->pr, ft::make_pair(k, m_v));
		node->right_node = nullptr;
		return (node);
}

template <class key, class maped_value, class Allocator,  class key_compare , class size_type>
	tree_node<key,maped_value>* AVL_Tree<key, maped_value , Allocator, key_compare , size_type>::Get_parent_of_node(tree_node<key,maped_value>* r, 
		tree_node<key,maped_value>* node,tree_node<key,maped_value>* parent_tmp)const{
	
	tree_node<key,maped_value>* parent = parent_tmp;
    if (!r || !node){
        return (parent);
    }
    if (comp(node->pr->first , r->pr->first)) // node->pr->first < r->pr->first
        parent  = Get_parent_of_node(r->left_node,node,r);
    else if (comp(r->pr->first , node->pr->first)) // node->pr->first > r->pr->first
        parent = Get_parent_of_node(r->right_node,node,r);
    else{
        parent = parent_tmp;
    }
    return (parent);
}


template <class key, class maped_value, class Allocator,  class key_compare , class size_type>
	tree_node<key,maped_value>* AVL_Tree<key, maped_value , Allocator, key_compare , size_type>::lower_bound(tree_node<key,maped_value>* r, key k)const{
	if (!r)
		return (nullptr);
	lower_bound(r->left_node,k);
	if (r->pr->first >= k) // k < r->pr->first
			return (r);
	lower_bound(r->right_node,k);
	return (lower_bound(r->right_node,k));
}

template <class key, class maped_value, class Allocator,  class key_compare , class size_type>
	tree_node<key,maped_value>* AVL_Tree<key, maped_value , Allocator, key_compare , size_type>::upper_bound(tree_node<key,maped_value>* r, key k)const{
	
	 if (comp(r->pr->first,k) && r->right_node)
		return (upper_bound(r->right_node,k));
	
	else if (comp(k,r->pr->first) && r->left_node)
		return (upper_bound(r->left_node,k));
	
	else if (r->pr->first == k && r->right_node)
		return (min_node_value(r->right_node));
	
	
	if (k < r->pr->first)
		return (r);
	
	tree_node<key,maped_value>* parent = Get_parent_of_node(root,r,NULL);
	while(parent->pr->first < k){
		parent = Get_parent_of_node(root,parent,NULL);
	}
	return (parent);
}