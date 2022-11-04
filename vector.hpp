/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 09:52:48 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/11/04 19:04:31 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBCPP_CONT_VECTOR
#define _LIBCPP_CONT_VECTOR

#include "Vector_iterator.hpp"
#include "struct_utils.hpp"

namespace ft{
template<class T , class Allocator = std::allocator<T> >
    class vector{
        public:
    typedef T                                               value_type;
    typedef Allocator                                       allocator_type;
    typedef typename allocator_type::reference              reference;
    typedef typename allocator_type::const_reference        const_reference;
    typedef typename allocator_type::pointer                pointer;
    typedef typename allocator_type::const_pointer          const_pointer;
    typedef typename allocator_type::difference_type        difference_type;
    typedef typename allocator_type::size_type              size_type;
    typedef Iterator<T>                                     iterator;
    typedef reverse_iterator<iterator>                      reverse_iterator;
    //typedef std::reverse_iterator<const_iterator>         const_reverse_iterator;
    //typedef implementation-defined                        const_iterator;


    explicit vector(const allocator_type& alloc = allocator_type()):_allocator(alloc),_v_data(nullptr),_v_size(0), _v_capacity(0){
    }
    
    explicit vector (size_type n , const value_type& val = value_type()){
        if (n > 0){
        size_type i = 0;
        _allocator = allocator_type();
        _v_data = _allocator.allocate(n);
        while(i < n){
            _allocator.construct(_v_data + (i++), val);
        }
        _v_size = n;
        _v_capacity = n;
        }else{
            _allocator = allocator_type();
            _v_data = nullptr;
            _v_size = 0;
            _v_capacity = 0;
        }
    }

    // template<class InputIterator>
    //     vector(InputIterator first , InputIterator last, const allocator_type& alloc = allocator_type()){
    //         (void)alloc;
    //         while(first != last){
    //             push_back(*first);
    //             ++first;
    //         }
    //     } 
    
    ~vector(){
        for(size_type j = 0; j < _v_size; j++){
            _allocator.destroy(_v_data + j);
        }
        if (_v_data && _v_size > 0)
            _allocator.deallocate(_v_data,_v_size);
        else if(_v_data && _v_capacity > 0)
            _allocator.deallocate(_v_data,_v_capacity);
            
    }

    vector (const vector& x){
        *this = x;
    }

    vector& operator=(const vector& x){
        *this = x;
        return (*this);
    }

    // template <class InputIterator>
    //     void assign(InputIterator first , InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = nullptr){
    //         allocator.allocate(last - first);
    //         int i = 0;
    //        while(first != last){
    //             alloc.consruct(,*first);
    //             ++first;
    //        }
    // }
    // void assign(size_type n , const value_type& val){
    //         // std::cout<<"hello\n";
    // }

    // iterator insert (iterator position, const value_type& val);
    
    // void insert (iterator position, size_type n, const value_type& val);
    
    // template <class InputIterator>    void insert (iterator position, InputIterator first, InputIterator last);

    reference at(size_type n){
        if (n < _v_size)
        return (_v_data[n]);
        else
            throw std::out_of_range("ft::exception\n");
    }

    const reference at(size_type n) const{
        if (n < _v_size)
        return (_v_data[n]);
        else
            throw std::out_of_range("ft::exception\n");
    }

    reference back(){
        return (_v_data[_v_size - 1]);
    }

    const reference back() const{
        return (_v_data[_v_size - 1]);
    }

    iterator begin() {
        return iterator(_v_data);
    }
    
    const iterator begin() const{
        return iterator(_v_data);
    }

    iterator end() {
        return iterator(_v_data + (_v_size));
    }

    const iterator end() const{
        return iterator(_v_data + (_v_size));
    }
    
    size_type capacity() const {
        return (_v_capacity);
    }

    void clear(){
        size_type i = 0;
        while(i < _v_size){
            _allocator.destroy(_v_data + i);
            i++;
        }
    }

    bool empty() const {
        if (_v_size == 0)
            return (true);
        return (false);
    }

    iterator erase(iterator position){
        iterator pos_tmp = position;
        _allocator.destroy(*position);
        _v_size--;
        return (pos_tmp + 1);
    }

    iterator erase(iterator first, iterator last){
        if (first != last && _v_size > 0){
        while(first != last){
            _allocator.destroy(*first);
            _v_size--;
            ++first;
        }
        }
        return (first);
    }

    reference front(){
        return (_v_data);
    }

    const reference front() const{
        return (_v_data);
    }

    allocator_type get_allocator()const{
        return (_allocator);
    }

    size_type max_size()const{
        return (_allocator.max_size());
    }

    reference operator[] (size_type n){
        return (_v_data[n]);
    }

    const reference operator[] (size_type n) const{
        return (_v_data[n]);
    }
    
    void pop_back(){
        _allocator.destroy(back());
        _v_size--;
    }

    void push_back(const value_type& val){
        if (_v_size == _v_capacity){
            if (_v_capacity == 0)
            reserve(2 * _v_capacity + 1);
            else
           reserve(2 * _v_capacity);
        }
        if (_v_data){
        _allocator.construct(_v_data + (_v_size++), val);
        }
    }

    void reserve(size_type n){
        size_type i = 0;
        if (n < _v_capacity)
            return;
        else if (n > max_size()){
            throw std::length_error("ft::exception\n");
        }
        else if (n > _v_capacity){
        pointer tmp_vec = _allocator.allocate(n);
        while(i < _v_size){
            _allocator.construct(tmp_vec + i,*(_v_data + i));
            i++;
        }
        if (_v_size > 0 && _v_data)
        for(size_type j = 0; j < _v_size; j++){
           _allocator.destroy(_v_data + j);
       }
        if (_v_data)
            _allocator.deallocate(_v_data,_v_capacity);
        _v_capacity = n;
        _v_data = tmp_vec;
    }
    }

    reverse_iterator rbegin(){
        return ((_v_data + _v_size) - 1);
    }

    const reverse_iterator rbegin() const {
        return ((_v_data + _v_size) - 1);
    }

    size_type size() const{
        return (_v_size);
    }

    reverse_iterator rend(){
        return (_v_data--);
    }

    // void resize(size_type n , value_type val = value_type()){
    //     size_type i = n + 1;
    //     if ( n < _v_size){
    //         erase(_v_data + i);
    //         _allocator.deallocate(_v_data + i,_v_size);
    //         _v_size = n;
    //     }
    //     /* resize
        
    //     else if ( n > _v_size){
    //        //g-need insert 
    //     }
    //     else if (n > _capacity){
    //         //g- need insert/erase
    //     }
        
    //     */
    // }

    void swap(vector& x){
        pointer tmp = _v_data;
        _v_data = x._v_data;
        x._v_data = tmp;
    }

    template <class T2, class Alloc> 
    friend bool operator==(const vector<T2,Alloc>& lhs, const vector<T2,Alloc>& rhs){
        if (lhs._v_size == rhs._v_size){
            return(ft::equal(lhs.begin(),lhs.end(),rhs.begin()));
        }
        return(false);
    }
    	
    template <class T2, class Alloc> 
    friend bool operator!=(const vector<T2,Alloc>& lhs, const vector<T2,Alloc>& rhs){
        if (lhs._v_size == rhs._v_size){
            return(ft::equal(lhs.begin(),lhs.end(),rhs.begin()));
        }
        return(true);
    }

    template <class T2, class Alloc>
    friend bool operator<(const vector<T2,Alloc>& lhs, const vector<T2,Alloc>& rhs){
        return(ft::lexicographical_compare(lhs.begin(),lhs.end(),rhs.begin()));
    }

    template <class T2, class Alloc>
    friend bool operator<=(const vector<T2,Alloc>& lhs, const vector<T2,Alloc>& rhs){
        return(ft::lexicographical_compare(lhs.begin(),lhs.end(),rhs.begin()));
    }

    template <class T2, class Alloc>
    friend bool operator>(const vector<T2,Alloc>& lhs, const vector<T2,Alloc>& rhs){
        return(ft::lexicographical_compare(lhs.begin(),lhs.end(),rhs.begin()));
    }

    template <class T2, class Alloc>
    friend bool operator>=(const vector<T2,Alloc>& lhs, const vector<T2,Alloc>& rhs){
        return(ft::lexicographical_compare(lhs.begin(),lhs.end(),rhs.begin()));
    }

    template <class T2, class Alloc>  void swap (vector<T2,Alloc>& x, vector<T2,Alloc>& y){
        pointer tmp = x._v_data;
        x._v_data = y._v_data;
        x._v_data = tmp;
    }
    
    protected:
        allocator_type _allocator;
        pointer _v_data;
        size_type _v_size;
        size_type _v_capacity;

};
}

#endif