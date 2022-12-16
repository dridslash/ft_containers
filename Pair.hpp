/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:47:04 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/12/11 12:00:50 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PAIR___HPP
#define __PAIR___HPP

namespace ft{
template<class T1, class T2>
    struct pair{
        typedef T1 first_type;
        typedef T2 second_type;

        T1 first;
        T2 second;

        pair():first(T1()) , second(T2()){}
        pair(const T1& a, const T2& b):first(a), second(b){}
        pair& operator=(const pair& pr){
            first = pr.first;
            second = pr.second;
            return (*this);
        }
        template<class U, class V>
            pair(const pair<U,V>& p):first(p.first), second(p.second){}
        template <class U, class V>
            friend bool operator== (const pair<U,V>& lhs, const pair<U,V>& rhs){
            return((lhs.first == rhs.first) && (lhs.second == rhs.second));
        }
        template <class U, class V> 
            friend bool operator!= (const pair<U,V>& lhs, const pair<U,V>& rhs){
            return (!(lhs == rhs));
        }
        template <class U, class V>
            friend bool operator<(const pair<U,V>& lhs, const pair<U,V>& rhs){
            return ((lhs.first < rhs.first) || (!(rhs.first < lhs.first) && (lhs.second < rhs.second)));
        }
        template <class U, class V>
            friend bool operator<=(const pair<U,V>& lhs, const pair<U,V>& rhs){
            return(!(rhs < lhs));
        }
        template <class U, class V>
            friend bool operator>(const pair<U,V>& lhs, const pair<U,V>& rhs){
            return ((rhs < lhs));
        }
        template <class U, class V>
            friend bool operator>=(const pair<U,V>& lhs, const pair<U,V>& rhs){
            return(!(rhs > lhs));
        }

    };   
    template<class U, class V>
        pair<U,V> make_pair(U x, V y){
                return (pair<U,V>(x,y));
        }
}

#endif