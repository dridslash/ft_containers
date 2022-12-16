/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:35:19 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/12/16 11:41:10 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STACK_HPP_
#define _STACK_HPP_

#include "vector.hpp"

namespace ft{

template <class T, class Container = ft::vector<T> > 
    class stack{
    public:
        typedef typename Container::value_type            value_type;
        typedef typename Container::size_type             size_type;
        typedef typename Container::reference             reference;
        typedef typename Container::const_reference       const_reference;
        typedef  Container                                container_type;
    
    protected:
        container_type c; // the container to adapt with
    
    public:
    
    explicit stack (const container_type& ctnr = container_type()){c = ctnr;}

    bool empty() const {
        return (c.empty());
    }
    
    size_type size()const{
        return (c.size());
    }
    
    void push(const value_type& x){
        c.push_back(x);
    }
    
    void pop(){
        c.pop_back();
    }

    reference& top(){
        return (c.back());
    }

    const const_reference& top()const{
        return (c.back());
    }


template <class T2, class cont> 
    friend bool operator== (const stack<T2,cont>& lhs, const stack<T2,cont>& rhs){
        return (lhs.c == rhs.c);
}
template <class T2, class cont> 
    friend bool operator!= (const stack<T2,cont>& lhs, const stack<T2,cont>& rhs){
    return (lhs.c != rhs.c);
}

template <class T2, class cont>
    friend bool operator<  (const stack<T2,cont>& lhs, const stack<T2,cont>& rhs){
    return (lhs.c < rhs.c);
}

template <class T2, class cont>
    friend bool operator<= (const stack<T2,cont>& lhs, const stack<T2,cont>& rhs){
    return (lhs.c <= rhs.c);
}

template <class T2, class cont>
    friend bool operator>  (const stack<T2,cont>& lhs, const stack<T2,cont>& rhs){
    return (lhs.c > rhs.c);
}

template <class T2, class cont>
    friend bool operator>= (const stack<T2,cont>& lhs, const stack<T2,cont>& rhs){
    return (lhs.c >= rhs.c);
}

};

}

#endif