/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:30:39 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/11/04 17:59:44 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VEC_ITERATOR
#define __VEC_ITERATOR

#include <iostream>


   //p- /////////////---Iterator_TRAITS----/////////////

    template<class Iterator>
    struct iterator_traits{
       typedef typename Iterator::value_type           value_type;
       typedef typename Iterator::difference_type      difference_type;
       typedef typename Iterator::pointer              pointer;
       typedef typename Iterator::reference            reference;
       typedef typename Iterator::iterator_category    iterator_category;
    };
    
    template<class T>
    struct iterator_traits<T*>{
       typedef T                                value_type;
       typedef std::ptrdiff_t                   difference_type;
       typedef T*                               pointer;
       typedef T&                               reference;
       typedef std::random_access_iterator_tag  iterator_category;
    };

    template<class T>
    struct iterator_traits<const T*>{
       typedef T                                value_type;
       typedef std::ptrdiff_t                   difference_type;
       typedef const T*                         pointer;
       typedef const T&                         reference;
       typedef std::random_access_iterator_tag  iterator_category;
    };

   //p- ///////////////////////////END/////////////////////////////////

   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   //b- ---------------------------CLASS_ITERATOR-----------------------------//
   template<class T> class Iterator{
      public:
         typedef  typename iterator_traits<T*>::value_type           value_type;
         typedef  typename iterator_traits<T*>::pointer              pointer;
         typedef  typename iterator_traits<T*>::reference            reference;
         typedef  typename iterator_traits<T*>::difference_type      difference_type;
         typedef  typename iterator_traits<T*>::iterator_category     iterator_category;

   //b- --------------------------CONSTRUCTORS/DES --------------------------------///
         
         
         Iterator():m_ptr(nullptr){}
         
         Iterator(pointer _ptr):m_ptr(_ptr){}

         Iterator(const Iterator& it){m_ptr = it.m_ptr;}

         ~Iterator(){}
         
   //b- /////////////////________MEMBER_____FUNCTIONS___________///////////////////////
         
         Iterator base()const{return (*this);}
         
         Iterator& operator=(const Iterator& it){m_ptr = it.m_ptr; return ((*this));}
         
         reference operator*(){return *(m_ptr);}

         reference operator[] (difference_type n) const{(*this)->m_ptr + n ; return (*this);}

         pointer operator->(){return &(this->operator*());}
         
         Iterator& operator+=(difference_type n){m_ptr += n ; return (*this);}

         Iterator& operator-=(difference_type n){m_ptr -= n ; return (*this);}

         Iterator operator-(difference_type n ){Iterator tmp(*this); tmp -= n;}

         Iterator operator+(difference_type n ){Iterator tmp(*this); tmp += n;}

         Iterator operator++(int){Iterator tmp = *this; ++m_ptr; return (tmp);}

         Iterator& operator++(){++m_ptr; return (*this);}
         
         Iterator operator--(int){Iterator tmp(*this); --this->m_ptr; return (tmp);}

         Iterator operator--(){--this->m_ptr; return (*this);}


   //b- ------------______GENERIC_FUNCTIONS_________-------------//////////

         template<class Iterator>
            friend typename iterator_traits<Iterator>::difference_type operator-(const Iterator& lhs,const Iterator& rhs){
            return (rhs - lhs);
         }
         template<class Iterator>
            friend typename iterator_traits<Iterator>::difference_type operator+(typename iterator_traits<Iterator>::difference_type n,const Iterator&  it){
            return (it + n);
         }
         template <class Iterator>
            friend bool operator==(const Iterator& lhs,const Iterator& rhs){return (lhs.base().m_ptr == rhs.base().m_ptr);}
         template <class Iterator>
            friend bool operator!=(const Iterator& lhs,const Iterator& rhs){return !(lhs.base().m_ptr == rhs.base().m_ptr);}
         template <class Iterator>
            friend bool operator<(const Iterator& lhs,const Iterator& rhs){return (lhs.base() < rhs.base());}
         template <class Iterator>
            friend bool operator<=(const Iterator& lhs,const Iterator& rhs){return (lhs.base() <= rhs.base());}
         template <class Iterator>
            friend bool operator>(const Iterator& lhs,const Iterator& rhs){return (lhs.base() > rhs.base());}
         template <class Iterator>
            friend bool operator>=(const Iterator& lhs,const Iterator& rhs){return (lhs.base() >= rhs.base());}

         private:
            pointer m_ptr;
   };
   //-///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   //-///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   
   //y- ----------------------------CLASS-_REVERSE_ITERATOR_-----------------------------//
    
     template<class Iterator> class reverse_iterator{
      public:
         typedef  typename iterator_traits<Iterator>::value_type                             value_type;
         typedef  Iterator                                                                   iterator_type;
         typedef  typename iterator_traits<Iterator>::pointer                                pointer;
         typedef  typename iterator_traits<Iterator>::reference                              reference;
         typedef  typename iterator_traits<Iterator>::difference_type                        difference_type;
         typedef  typename iterator_traits<Iterator>::iterator_category                      iterator_category;

   //y- --------------------------CONSTRUCTORS/DES --------------------------------///
         
         
         reverse_iterator(){}

         explicit reverse_iterator (iterator_type it){this->current = it;}

         template<class Iter>
            reverse_iterator(const reverse_iterator<Iter>& rev_it){(*this) = rev_it;}

         ~reverse_iterator(){}
         
   //y- /////////////////________MEMBER_____FUNCTIONS___________///////////////////////
         
         
         reverse_iterator base()const{return this;}
         
         reference operator*(){return *current;}

         reference operator[] (difference_type n) const{(*this) + n ; return (*this);}

         pointer operator->(){return &this->operator*();}
         
         reverse_iterator& operator+=(difference_type n){current += n ; return (*this);}

         reverse_iterator& operator-=(difference_type n){current -= n ; return (*this);}

         reverse_iterator operator-(difference_type n ){reverse_iterator tmp(*this); tmp -= n;}

         reverse_iterator operator+(difference_type n ){reverse_iterator tmp(*this); tmp += n;}

         reverse_iterator operator++(int){reverse_iterator tmp = *this; ++(*this); return (tmp);}

         reverse_iterator& operator++(){++(*this); return (*this);}
         
         reverse_iterator operator--(int){reverse_iterator tmp(*this); --(*this); return (tmp);}

         reverse_iterator operator--(){--(*this); return (*this);}


   //y- -------------______GENERIC_FUNCTIONS_________-------------//////////
         
         template<class Iter>
            friend typename iterator_traits<Iter>::difference_type operator-(const reverse_iterator<Iter>& lhs,    const reverse_iterator<Iter>& rhs){
             return (rhs - lhs);
         }
         template<class Iter>
            friend typename iterator_traits<Iter>::difference_type operator+(typename reverse_iterator<Iter>::difference_type n,const reverse_iterator<Iter>& rev_it){
             return (rev_it + n);
         }
         template <class Iter>
            friend bool operator==(const reverse_iterator<Iter>& lhs,const reverse_iterator<Iter>& rhs){return (lhs.base() == rhs.base());}
         template <class Iter>
            friend bool operator!=(const reverse_iterator<Iter>& lhs,const reverse_iterator<Iter>& rhs){return !(lhs.base() == rhs.base());}
         template <class Iter>
            friend bool operator<(const reverse_iterator<Iter>& lhs,const reverse_iterator<Iter>& rhs){return (lhs.base() < rhs.base());}
         template <class Iter>
            friend bool operator<=(const reverse_iterator<Iter>& lhs,const reverse_iterator<Iter>& rhs){return (lhs.base() <= rhs.base());}
         template <class Iter>
            friend bool operator>(const reverse_iterator<Iter>& lhs,const reverse_iterator<Iter>& rhs){return (lhs.base() > rhs.base());}
         template <class Iter>
            friend bool operator>=(const reverse_iterator<Iter>& lhs,const reverse_iterator<Iter>& rhs){return (lhs.base() >= rhs.base());}

          protected:
            Iterator current;
   };

#endif