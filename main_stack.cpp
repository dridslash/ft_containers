/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:47:26 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/12/16 11:33:29 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include "vector.hpp"
#include "stack.hpp"


int main(){

    std::stack<int> st;
    ft::stack<int> ft_st;
    st.push(1);
    st.push(10);
    st.push(20);
    st.push(30);

    ft_st.push(1);
    ft_st.push(10);
    ft_st.push(20);
    ft_st.push(30);
    
    while(!st.empty()){
        std::cout<<st.top()<<std::endl;
        st.pop();
    }

    std::cout<<"-------------------------------------\n";

    while(!ft_st.empty()){
        std::cout<<ft_st.top()<<std::endl;
        ft_st.pop();
    }

    return (0);
}