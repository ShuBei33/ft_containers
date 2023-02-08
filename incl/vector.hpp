/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:34:22 by estoffel          #+#    #+#             */
/*   Updated: 2023/02/08 01:46:59 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <stdexcept>
#include <algorithm>
#include "utils.hpp"
#include <iostream>

namespace ft {
	template<class T, class Alloc = std::allocator<T> > class vector {
		public:
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef pointer iterator;
			typedef const_pointer const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
			typedef typename allocator_type::size_type size_type;

			explicit vector(const allocator_type& alloc = allocator_type())
				: _alloc(alloc), _ptr(NULL), _size(0), _capacity(0) {}
			explicit vector(size_type n, const value_type& val = value_type(),const allocator_type& alloc = allocator_type())
				: _alloc(alloc), _ptr(NULL), _size(0), _capacity(0) {
					_ptr = _alloc.allocate(n);
					for (size_type i = 0; i != n; ++i)
						_alloc.construct(_ptr+i, val);
				}
			template<class InputIterator>
			vector(InputIterator first, InputIterator last,const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
				: _alloc(alloc), _ptr(NULL), _size(0), _capacity(0) {
					_capacity = last - first;
					_ptr = _alloc.allocate(_capacity);
					for (InputIterator it = first; it != last; ++it)
						this->push_back(*it);
				}
			vector(const vector& x)
				: _alloc(x._alloc), _ptr(NULL), _size(0), _capacity(0) {}
			vector& operator=(const vector& x) {
				if (_ptr) {
					clear();
					_alloc.deallocate(_ptr, _capacity);
				}
				this->_alloc = x._alloc;
				this->_size = x._size;
				this->_ptr = _alloc.allocate(x._size);
				for (size_type i = 0; i < x._size; ++i)
					_alloc.construct(_ptr+i, x._ptr[i]);
				this->_capacity = x._size;
				return *this;
			}
			~vector() {
				clear();
				_alloc.deallocate(_ptr, _capacity);
			}


	//---------------------------------------- ITERATORS ----------------------------------------//


			iterator begin() {
				return _ptr;
			}
			const_iterator begin() const {
				return _ptr;
			}
			iterator end() {
				return _ptr+_size;
			}
			const_iterator end() const {
				return _ptr+_size;
			}
			reverse_iterator rbegin() {
				return reverse_iterator(end());
			}
			const_reverse_iterator rbegin() const {
				return const_reverse_iterator(end());
			}
			reverse_iterator rend() {
				return reverse_iterator(begin());
			}
			const_reverse_iterator rend() const {
				return const_reverse_iterator(begin());
			}


	//---------------------------------------- CAPACITY -----------------------------------------//


			size_type size() const {
				return _size;
			}
			size_type max_size() const {
				return _alloc.max_size();
			}
			void resize(size_type n, value_type val = value_type()) {
				if (n > _capacity)
					reserve(n);
				while (n < _size)
					push_back(val);
				while (_size > n)
					pop_back();
			}
			size_type capacity() const {
				return _capacity;
			}
			bool empty() const {
				return _size==0;
			}
			void reserve(size_type n) {
				if (n > max_size())
					throw std::length_error("vector::reserve");
				if (_capacity >= n)
					return ;
				pointer tmp = _alloc.allocate(n);
				for (size_type i = 0; i < _size; ++i) {
					_alloc.construct(tmp+i, _ptr[i]);
					_alloc.destroy(_ptr+i);
				}
				if (_capacity)
					_alloc.deallocate(_ptr, _capacity);
				_ptr = tmp;
				_capacity = n;
			}


	//------------------------------------- ELEMENT ACCESS --------------------------------------//


			reference operator[](size_type n) {
				return _ptr[n];
			}
			const_reference operator[](size_type n) const {
				return _ptr[n];
			}
			reference at(size_type n) {
				if (n >= _size)
					throw std::out_of_range("vector::at");
				return _ptr[n];
			}
			const_reference at(size_type n) const {
				if (n >= _size)
					throw std::out_of_range("vector::at");
				return _ptr[n];
			}
			reference front() {
				return *begin();
			}
			const_reference front() const {
				return *begin();
			}
			reference back() {
				return *rend();
			}
			const_reference back() const {
				return *rend();
			}


	//--------------------------------------- MODIFIERS -----------------------------------------//


			template<class InputIterator>
			void assign(InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) {
				clear();
				for (InputIterator it = first; it != last; ++it)
					push_back(*it);
			}
			void assign(size_type n, const value_type& val) {
				clear();
				for (size_type i = 0; i < n; ++i)
					push_back(val);
			}
			void push_back(value_type const& val) {
				if (!is_available())
					(_capacity ? reserve(_capacity<<1) : reserve(1)); //x2 binary
				_alloc.construct(_ptr+_size, val);
				++_size;
			}
			void pop_back() {
				if (empty())
					return ;
				_alloc.destroy(_ptr+(--_size));
			}
			iterator insert(iterator pos, const value_type& val) {
				if (!is_available())
					(_capacity ? reserve(_capacity<<1) : reserve(1));
				for (iterator it = (end()-1); it >= pos; --it) {
					_alloc.construct(it+1, *it);
					_alloc.destroy(it);
				}
				_alloc.construct(pos, val);
				++_size;
				return pos;
			}
			// void print(void) {
			// 	for (size_type x = 0; x < _size; ++x) {
			// 		std::cout << _ptr[x] << std::endl;
			// 	}
			// 	std::cout << std::endl;
			// }
			// void debug(void) {
			// 	std::cout << "size : " << _size << '\n';
			// 	std::cout << "capacity : " << _capacity << '\n';
			// 	std::cout << std::endl;
			// }
			void insert(iterator pos, size_type n, const value_type& val) {
				if (is_available() < n)
					reserve((_capacity<<1) + n);
				for (iterator it = (end()-1); it >= pos; --it) {
					_alloc.construct(it+n, *it);
					_alloc.destroy(it);
				}
				for (size_type i = 0; i < n; ++i)
					_alloc.construct(pos++, val);
				_size += n;
			}
			template <class InputIterator>
			void insert(iterator pos, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) {
				
			}
			iterator erase (iterator pos) {
				if (pos == end()) {
					pop_back();
					return pos;
				}
				_alloc.destroy(pos);
				
			}
			iterator erase (iterator first, iterator last) {
				
			}
			void swap (vector& x) {
				std::swap(this->_alloc, _alloc.x);
				std::swap(this->_ptr, _ptr.x);
				std::swap(this->_size, _size.x);
				std::swap(this->_capacity, _capacity.x);
			}
			void clear() {
				if (!_ptr)
					return ;
				for (size_type i = 0; i < _size; ++i)
					_alloc.destroy(_ptr+i);
				_size = 0;
			}
			allocator_type get_allocator() const {
				return _alloc;
			}


	//--------------------------------------- ALLOCATOR -----------------------------------------//


		private:
			allocator_type	_alloc;
			pointer			_ptr;
			size_type		_size;
			size_type		_capacity;

			size_type is_available() {
				return _capacity-_size;
			}
	};


	//---------------------------------------- OVERLAY ------------------------------------------//


	template <class T, class Alloc>
	bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return lhs.size()==rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}
	template <class T, class Alloc>
	bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !(lhs==rhs);
	}
	template <class T, class Alloc>
	bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	template <class T, class Alloc>
	bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !(rhs<lhs);
	}
	template <class T, class Alloc>
	bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return rhs<lhs;
	}
	template <class T, class Alloc>
	bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !(lhs<rhs);
	}


	//----------------------------------------- OTHER -------------------------------------------//


	//std::swap (vector)
	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
		x.swap(y);
	}
}
