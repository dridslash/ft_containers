/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 08:42:01 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/12/13 12:36:45 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STRUCT_UTILS_HPP_
#define _STRUCT_UTILS_HPP_

namespace ft{

//b- ENABLE_IF_STRUCTURE
 
template<bool , typename T = void>
struct enable_if{};

template<typename T>
struct enable_if<true, T>{
     typedef T type;
};

//b- END

/////////////////////////////////////////////////////////////////////////////////////////////////

//y- IS_INTEGRAL

template<class T, T value_>
   struct inherited_integral{
        static const T value = value_;
};

template <class T>
    struct            is_integral : public inherited_integral<bool,false>{};
    template<>struct  is_integral<bool> : public inherited_integral<bool,true>{};
    template<>struct  is_integral<int> : public inherited_integral<bool,true>{};
    template<>struct  is_integral<char> : public inherited_integral<bool,true>{};
    template<>struct  is_integral<char16_t> : public inherited_integral<bool,true>{};
    template<>struct  is_integral<char32_t> : public inherited_integral<bool,true>{};
    template<>struct  is_integral<wchar_t> : public inherited_integral<bool,true>{};
    template<>struct  is_integral<signed char> : public inherited_integral<bool,true>{};
    template<>struct  is_integral<short int> : public inherited_integral<bool,true>{};
    template<>struct  is_integral<long int> : public inherited_integral<bool,true>{};
    template<>struct  is_integral<unsigned char> : public inherited_integral<bool,true>{};
    template<>struct  is_integral<unsigned short int> : public inherited_integral<bool,true>{};
    template<>struct  is_integral<unsigned int> : public inherited_integral<bool,true>{};
    template<>struct  is_integral<unsigned long int> : public inherited_integral<bool,true>{};
    template<>struct  is_integral<unsigned long long int> : public inherited_integral<bool,true>{};

//y- END

///////////////////////////////////////////////////////////////////////////////////////////////////

    //r-//////////////////////////--EQUAL--/////////////////////////////////////////
    
    template<class InputIterator1, class  InputIterator2>
        bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2){
            while(first1 != last1){
                if (!(*first1 == *first2))
                    return (false);
                ++first1;++first2;
            }
            return (true);
        }

        template<class InputIterator1, class  InputIterator2>
        bool map_equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2){
            while(first1 != last1){
                if (!((*first1).first == (*first2).first) && !((*first1).second == (*first2).second))
                    return (false);
                ++first1;++first2;
            }
            return (true);
        }
    
    template<class InputIterator1, class  InputIterator2, class BinaryPredicate>
        bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 , BinaryPredicate pred){
            while(first1 != last1){
                if (!pred(first1 , first2))
                    return (false);
                ++first1;++first2;
            }
            return (true);
        }
        
    //r-////////////////////////////--END--//////////////////////////////////////////////



    //g-/////////////////////////////////////--LEXICOGRAPHICAL_COMPARE---////////////////
    
    template<class InputIterator1, class InputIterator2>
        bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1 , InputIterator2 first2 , InputIterator2 last2){
            while (first1!=last1)
                {
                    if (first2 == last2 || *first2<*first1) return false;
                    else if (*first1<*first2) return true;
                    ++first1; ++first2;
                }
                return (first2 != last2);
        }

        template<class InputIterator1, class InputIterator2>
        bool lexicographical_compare_map(InputIterator1 first1, InputIterator1 last1 , InputIterator2 first2 , InputIterator2 last2){
            while (first1!=last1)
                {
                    if (first2 == last2 || (((*first2).first < (*first1).first) || (!((*first2).first < (*first1).first) && (*first2).second < (*first1).second))) return false;
                    else if ((((*first1).first < (*first2).first) || (!((*first1).first < (*first2).first) && (*first1).second < (*first2).second))) return true;
                    ++first1; ++first2;
                }
                return (first2 != last2);
        }

    template<class InputIterator1, class InputIterator2, class Compare>
        bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1 , InputIterator2 first2 , InputIterator2 last2, Compare comp){
            while(first1 != last1){
                if (first2 == last2 || comp(*first2,*first1)) return (false);
                else if (comp(*first1,*first2)) return (true);
                ++first1;++first2;
            }
            return (first2 != last2);
        }

    //g-/////////////////////////////////////--END---////////////////
}

#endif