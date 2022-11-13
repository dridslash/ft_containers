/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 09:52:48 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/11/13 15:28:10 by mnaqqad          ###   ########.fr       */
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
    typedef Iterator<value_type>                            iterator;
    typedef Iterator<const value_type>                      const_iterator;
    typedef Reverse_iterator<iterator>                      reverse_iterator;
    typedef Reverse_iterator<const_iterator>                const_reverse_iterator;


    explicit vector(const allocator_type& alloc = allocator_type()):_allocator(alloc),_v_data(nullptr),_v_size(0), _v_capacity(0){
    }
    
    explicit vector (size_type n , const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):_allocator(alloc){
        if (n > 0){
        size_type i = 0;
        _v_data = _allocator.allocate(n);
        while(i < n){
            _allocator.construct(_v_data + i, val);
            i++;
        }
        _v_size = n;
        _v_capacity = n;
        }else{
            _v_data = nullptr;
            _v_size = 0;
            _v_capacity = 0;
        }
    }

    template<class InputIterator>
        vector(InputIterator first , InputIterator last, const allocator_type& alloc = allocator_type(),
        typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = nullptr):_allocator(alloc),_v_data(nullptr),_v_size(0), _v_capacity(0){
            assign(first,last);
        }
    
    ~vector(){
        for(size_type j = 0; j < _v_size; j++){
            _allocator.destroy(_v_data + j);
        }
        if (_v_data)
            _allocator.deallocate(_v_data,_v_capacity);
            _v_size = 0;
            _v_capacity = 0;
    }

    vector (const vector& x){
        _allocator = x.get_allocator();
        if (x._v_data){
        _v_size = x.size();
        _v_capacity = x.capacity();
        _v_data = _allocator.allocate(_v_capacity);
        size_type i = 0;
        while(i < _v_size){
            _allocator.construct(_v_data + i,*(x.begin() + i));
            i++;
        }
        }
    }

    vector& operator=(const vector& x){
        assign(x.begin(),x.end());
        return (*this);
    }

    template <class InputIterator>
        void assign(InputIterator first , InputIterator last,
        typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = nullptr){
            size_type i = 0;
            clear();
            vector tmp;
            while(first != last){
                tmp.push_back(*(first));
                first++;
            }
            size_type s = tmp.size();
            if (s > _v_capacity)
                reserve(s);
            while(i < tmp.size()){
                _allocator.construct(_v_data + i,*(tmp.begin() + i));
                i++;
            }
            _v_size = s;
    }
    void assign(size_type n , const value_type& val){
        size_type i = 0;
        if (_v_data)
        clear();
        if (n > _v_capacity){
            reserve(n);
        }
        while(i < n){
            _allocator.construct(_v_data + (i++), val);
        }
        _v_size = n;   
    }

    iterator insert (iterator position, const value_type& val){
        size_type predicted_size = _v_size;
        size_type index = position - begin();
        if (++predicted_size > _v_capacity){
            if (_v_capacity == 0){
            reserve(1);
            }
            else
           reserve(2 * _v_capacity);
        }
        for(size_type i = _v_size ; i > index; i--){
            _allocator.destroy(_v_data + i - 1);
            _allocator.construct(_v_data + i , *((_v_data + i) - 1));
        }
        ++_v_size;
        _allocator.construct(_v_data + index , val);
        return (begin() + index);
    }
    
    void insert (iterator position, size_type n, const value_type& val){
        if (n > max_size())
            throw std::length_error("vector\n");
        size_type index = position - begin();
        size_type predica = _v_size;
        if (predica + n > _v_capacity){
            if (_v_capacity == 0){
                reserve(n);
            }
            else
                reserve(2 * _v_capacity);
            if (_v_capacity < predica + n){
                reserve(n + _v_size);
            }
        }
        for(size_type i = _v_size; i > index ; i--){
            _allocator.destroy(_v_data + i - 1);
            _allocator.construct(_v_data + i  - 1 + n, *(_v_data + i - 1));
        }
        for(size_type i = 0 ; i < n ; i++){
            _allocator.construct(_v_data + (index++) , val);
        }
        _v_size += n;
       
    }
    
    template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last){
        vector tmp;
        tmp.assign(first, last);
        size_type n = tmp.size();
        size_type index = position - begin();
        size_type predica = _v_size;
        if (_v_size + n > _v_capacity){
            if (_v_capacity == 0){
                reserve(n);
            }
            else
                reserve(2 * _v_capacity);
            if (_v_capacity < predica + n){
                reserve(n + _v_size);
            }
        }
        for(size_type i = _v_size ; i > index ; i--){
             _allocator.destroy(_v_data + i - 1);
            _allocator.construct(_v_data + i  - 1 + n, *(_v_data + i - 1));
        }
        for(iterator i = tmp.begin();i != tmp.end(); i++){
            _allocator.construct(_v_data + (index++),*(i));
        }
        _v_size += n;
    }

    reference at(size_type n){
        if (n < _v_size)
        return (_v_data[n]);
        else
            throw std::out_of_range("vector\n");
    }

    const_reference at(size_type n) const{
        if (n < _v_size)
        return (_v_data[n]);
        else
            throw std::out_of_range("vector\n");
    }

    reference back(){
        return (_v_data[_v_size - 1]);
    }

    const_reference back() const{
        return (_v_data[_v_size - 1]);
    }

    iterator begin() {
        return (iterator(_v_data));
    }
    
    const_iterator begin() const{
        return (const_iterator(_v_data));
    }

    iterator end() {
        return (_v_data + _v_size);
    }

    const_iterator end() const{
        return (_v_data + _v_size);
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
        _v_size = 0;
    }

    bool empty() const {
        if (_v_size == 0)
            return (true);
        return (false);
    }

    iterator erase(iterator position){
        size_type index = position - begin();
        for(size_type i = index; i < _v_size - 1;i++){
            _allocator.destroy(_v_data + i);
            _allocator.construct(_v_data + i, *(_v_data + i + 1));
        }
        _allocator.destroy(_v_data + _v_size - 1);
        _v_size--;
        return (_v_data + index);
    }

    iterator erase(iterator first, iterator last){
        vector tmp;
        tmp.assign(first, last);
        size_type index = first - begin();
        size_type n = tmp.size();
        if (first != last){
            for(size_type i = index ; i < _v_size - n; i++){
            _allocator.destroy(_v_data + i);
            _allocator.construct(_v_data + i, *(_v_data + i + n));
            }
            for(size_type i = _v_size - n ; i < _v_size;i++){
                _allocator.destroy(_v_data + i);
            }
        }
        _v_size -= n;
        return (_v_data + index);
    }

    reference front(){
        return (_v_data[0]);
    }

    const reference front() const{
        return (_v_data[0]);
    }

    allocator_type get_allocator()const{
        return (_allocator);
    }

    size_type max_size()const{
        if (sizeof(T) == sizeof(char)){
            return(9223372036854775807);
        }
        return (_allocator.max_size());
    }

    reference operator[] (size_type n){
        return (_v_data[n]);
    }

    const reference operator[] (size_type n) const{
        return (_v_data[n]);
    }
    
    void pop_back(){
        _allocator.destroy((_v_data + _v_size) - 1);
        _v_size--;
    }

    void push_back(const value_type& val){
        if (_v_size == _v_capacity){
            if (_v_capacity == 0)
            reserve(2 * _v_capacity + 1);
            else
           reserve(2 * _v_capacity);
        }
        _allocator.construct((_v_data + _v_size++), val);
    }

    void reserve(size_type n){
        size_type i = 0;
        if (n > max_size()){
            throw std::length_error("vector\n");
        }
        else if (n > _v_capacity){
        pointer tmp_vec = _allocator.allocate(n);
        while(i < _v_size){
            _allocator.construct(tmp_vec + i,*(_v_data + i));
            i++;
        }
        for(size_type j = 0; j < _v_size; j++){
           _allocator.destroy(_v_data + j);
       }
        if (_v_data){
            _allocator.deallocate(_v_data,_v_capacity);
        }
        _v_capacity = n;
        _v_data = tmp_vec;
        }
    }

    reverse_iterator rbegin(){
        return (reverse_iterator(_v_data + _v_size - 1));
    }

    const_reverse_iterator rbegin() const {
        return (const_reverse_iterator(_v_data + _v_size - 1));
    }

    size_type size() const{
        return (_v_size);
    }

    reverse_iterator rend(){
        return (reverse_iterator(_v_data - 1));
    }

    const_reverse_iterator rend() const{
        return (const_reverse_iterator(_v_data - 1));
    }

    void resize(size_type n , value_type val = value_type()){
        if(n > max_size())
            throw std::length_error("vector");
        size_type right_size = 0;
        if (n > _v_capacity){
            if (_v_capacity == 0)
            reserve(n);
            else
            reserve(2 * _v_capacity);
        }
        if (_v_size == 0){
            assign(n,val);
        }
        else if (_v_size > 0 && n > _v_size){
            right_size = _v_size;
            for(size_type i = 0; i < n - right_size; i++){
                insert(end(),val);
            }
        }
        else if (_v_size > 0 && n < _v_size){
            right_size = _v_size;
            for(size_type i = n; i < right_size; i++){
                _allocator.destroy(_v_data + i);
                _v_size--;
            }
        }
    }

    void swap(vector& x){
        pointer tmp = x._v_data;
        size_type size = _v_size;
        size_type cap = _v_capacity;
        x._v_data = _v_data;
        _v_data = tmp;
        _v_size = x._v_size;
        _v_capacity = x._v_capacity;
        x._v_size = size;
        x._v_capacity = cap;
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
        if (lhs._v_size == rhs._v_size)
        return(!ft::equal(lhs.begin(),lhs.end(),rhs.begin()));
        return (true);
    }

    template <class T2, class Alloc>
    friend bool operator<(const vector<T2,Alloc>& lhs, const vector<T2,Alloc>& rhs){
        if (lhs._v_size < rhs._v_size)
            return (true);
        else
            return(ft::lexicographical_compare(lhs.begin(),lhs.end(),rhs.begin(),rhs.end()));
        return (false);
    }

    template <class T2, class Alloc>
    friend bool operator<=(const vector<T2,Alloc>& lhs, const vector<T2,Alloc>& rhs){
        if (lhs._v_size <= rhs._v_size && ft::equal(lhs.begin(),lhs.end(),rhs.begin()))
            return (true);
        return (false);
    }

    template <class T2, class Alloc>
    friend bool operator>(const vector<T2,Alloc>& lhs, const vector<T2,Alloc>& rhs){
        if (lhs._v_size > rhs._v_size)
            return (true);
        else
            return(!ft::equal(lhs.begin(),lhs.end(),rhs.begin()));
        return (false);
    }

    template <class T2, class Alloc>
    friend bool operator>=(const vector<T2,Alloc>& lhs, const vector<T2,Alloc>& rhs){
        if (lhs._v_size >= rhs._v_size)
            return (true);
        return (false);
    }

    template <class T2, class Alloc>  void swap (vector<T2,Alloc>& x, vector<T2,Alloc>& y){
        x.swap(y);
    }
    
    protected:
        allocator_type _allocator;
        pointer _v_data;
        size_type _v_size;
        size_type _v_capacity;

};
}

#endif