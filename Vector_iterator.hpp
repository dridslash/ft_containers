/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:30:39 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/12/11 17:47:00 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VEC_ITERATOR
#define __VEC_ITERATOR

#include <iostream>


   //p- /////////////---Iterator_TRAITS----/////////////
namespace ft{
   
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

         operator Iterator<const value_type>(){return (Iterator<const value_type>(m_ptr));}

         
   //b- /////////////////________MEMBER_____FUNCTIONS___________///////////////////////
         
         pointer base()const{return (m_ptr);}
         
         Iterator& operator=(const Iterator& it){m_ptr = it.m_ptr; return ((*this));}
         
         reference operator*(){return *(m_ptr);}

         reference operator[] (difference_type n) const{return (m_ptr[n]);}

         pointer operator->(){return &(this->operator*());}
         
         Iterator& operator+=(difference_type n){m_ptr += n ; return (*this);}

         Iterator& operator-=(difference_type n){m_ptr -= n ; return (*this);}

         Iterator operator-(difference_type n )const{return Iterator(m_ptr - n);}

         Iterator operator+(difference_type n )const{return Iterator(m_ptr + n);}
         
         Iterator operator++(int){Iterator tmp = (*this); ++m_ptr; return (tmp);}

         Iterator& operator++(){++m_ptr; return (*this);}
         
         Iterator operator--(int){Iterator tmp(*this); --m_ptr; return (tmp);}

         Iterator operator--(){--m_ptr; return (*this);}


   //b- ------------______GENERIC_FUNCTIONS_________-------------//////////

         difference_type operator-(const Iterator& rhs)const{
            return (static_cast<difference_type>(m_ptr - rhs.m_ptr));
         }
         
         template <class T2> 
            friend Iterator operator+(difference_type n,const Iterator<T2>& it){
               return (it.m_ptr + n);
         }
         
          difference_type operator+(const Iterator&  it)const{
            return (static_cast<difference_type>(m_ptr + it.m_ptr));
         }
         template <class Iter, class Iter2>
             friend bool operator==(const Iter& lhs, const Iter2& rhs){return (lhs.base() == rhs.base());}
         template <class Iter, class Iter2>
            friend bool operator!=(const Iter& lhs, const Iter2& rhs){return (!(lhs.base() == rhs.base()));}
         template <class Iter, class Iter2>
           friend  bool operator<(const Iter& lhs, const Iter2& rhs){return (lhs.base() < rhs.base());}
         template <class Iter, class Iter2>
            friend bool operator<=(const Iter& lhs, const Iter2& rhs){return (lhs.base() <= rhs.base());}
         template <class Iter, class Iter2>
            friend bool operator>(const Iter& lhs, const Iter2& rhs){return (lhs.base() > rhs.base());}
         template <class Iter, class Iter2>
            friend bool operator>=(const Iter& lhs, const Iter2& rhs){return (lhs.base() >= rhs.base());}

         private:
            pointer m_ptr;
   };
   
   //r-///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   //r-///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   
   //y- ----------------------------CLASS-_REVERSE_ITERATOR_-----------------------------//
    
     template<class Iterator> class Reverse_iterator{
      public:
         typedef  typename iterator_traits<Iterator>::value_type                             value_type;
         typedef  Iterator                                                                   iterator_type;
         typedef  typename iterator_traits<Iterator>::pointer                                pointer;
         typedef  typename iterator_traits<Iterator>::reference                              reference;
         typedef  typename iterator_traits<Iterator>::difference_type                        difference_type;
         typedef  typename iterator_traits<Iterator>::iterator_category                      iterator_category;

   //y- --------------------------CONSTRUCTORS/DES --------------------------------///
         
         
         Reverse_iterator():current(){}

         explicit Reverse_iterator (iterator_type it):current(it){}
         
         template <class Iter>
            Reverse_iterator(const Reverse_iterator<Iter>& rev_it){current = rev_it.base();}
         
         ~Reverse_iterator(){}

         
   //y- /////////////////________MEMBER_____FUNCTIONS___________///////////////////////
         
         
         iterator_type base()const{return (current);}

         reference operator*(){return *(current - 1);}

         reference operator[] (difference_type n) const{return *(current - 1 - n);}

         pointer operator->(){return &this->operator*();}
         
         Reverse_iterator& operator+=(difference_type n){current -= n ; return (*this);}

         Reverse_iterator& operator-=(difference_type n){current += n ; return (*this);}

         Reverse_iterator operator-(difference_type n ){return Reverse_iterator(current + n);}

         Reverse_iterator operator+(difference_type n ){return Reverse_iterator(current - n);}

         Reverse_iterator operator++(int){Reverse_iterator tmp (*this); --(current); return (tmp);}

         Reverse_iterator& operator++(){--(current); return (*this);}
         
         Reverse_iterator operator--(int){Reverse_iterator tmp(*this); ++(current); return (tmp);}

         Reverse_iterator operator--(){++(current); return (*this);}


   //y- -------------______GENERIC_FUNCTIONS_________-------------//////////
         
         template <class T>
            friend difference_type operator-(const Reverse_iterator<T>& lhs, const Reverse_iterator<T>& rhs){
             return (static_cast<difference_type>(rhs.base() - lhs.base()));
         }

         template <class T>
            friend Reverse_iterator operator+(difference_type n,const Reverse_iterator<T>& rev_it){
               return (Reverse_iterator(rev_it.base() - n));
         }

         template <class T>
            friend difference_type operator+(const Reverse_iterator<T>& lhs, const Reverse_iterator<T>& rhs){
             return (static_cast<difference_type>(rhs.base() + lhs.base()));
         }
         
         template <class Iter>
            bool operator==(const Reverse_iterator<Iter>& rhs){return (current == rhs.base());}
         template <class Iter>
            bool operator!=(const Reverse_iterator<Iter>& rhs){return !(current == rhs.base());}
         template <class Iter>
            bool operator<(const Reverse_iterator<Iter>& rhs){return (current > rhs.base());}
         template <class Iter>
            bool operator<=(const Reverse_iterator<Iter>& rhs){return (current >= rhs.base());}
         template <class Iter>
            bool operator>(const Reverse_iterator<Iter>& rhs){return (current < rhs.base());}
         template <class Iter>
            bool operator>=(const Reverse_iterator<Iter>& rhs){return (current <= rhs.base());}

          protected:
            Iterator current;
   };
}
#endif