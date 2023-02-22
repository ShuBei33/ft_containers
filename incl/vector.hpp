/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:34:22 by estoffel          #+#    #+#             */
/*   Updated: 2023/02/22 20:09:52 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#define HINT(what) std::cout << "\x1b[32m" << what << "\x1b[0m" << std::endl

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
					this->assign(n, val);
				}
			template<class InputIterator>
			vector(InputIterator first, InputIterator last,const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
				: _alloc(alloc), _ptr(NULL), _size(0), _capacity(0) {
					this->assign(first, last);
				}
			vector(const vector& x)
				: _alloc(x._alloc), _ptr(NULL), _size(0), _capacity(0) {
					this->assign(x.begin(), x.end());
				}
			vector& operator=(const vector& x) {
				if (&x != this)
					this->assign(x.begin(), x.end());
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
				reserve(n);
				while (n > _size)
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
				if (_ptr) {
					_alloc.deallocate(_ptr, _capacity);
				}
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
					throw std::out_of_range("ft::vector::at");
				return _ptr[n];
			}
			const_reference at(size_type n) const {
				if (n >= _size)
					throw std::out_of_range("ft::vector::at");
				return _ptr[n];
			}
			reference front() {
				return *begin();
			}
			const_reference front() const {
				return *begin();
			}
			reference back() {
				return *rbegin();
			}
			const_reference back() const {
				return *rbegin();
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
				if (_size == 0)
					return ;
				_alloc.destroy(_ptr+(--_size));
			}
			iterator insert(iterator pos, const value_type& val) {
				insert(pos, 1, val);
				return pos;
			}
			
			void insert(iterator pos, size_type n, const value_type& val) {
				size_type pst = pos - begin();
				if (!n) return;
				
				if (!_capacity)
					reserve(1);
				
				if (is_available() < n) {
					reserve(_capacity<<1);
				}
				
				// for (iterator it = (end()-1); it >= pos; --it) {
				// 	HINT("yolo");
				// 	_alloc.construct(&(*(it+n)), *it);
				// 	_alloc.destroy(&(*it));
				// }
				// pointer tmp = _ptr+pst;
				// for (size_type i = 0; i < n; ++i) {
				// 	HINT("yolo2");
				// 	_alloc.construct(tmp+i, val);
					
				// }
				for (size_type i = _size; i > pst; --i) {
					_alloc.construct(_ptr+i+n-1, _ptr[i-1]);
					_alloc.destroy(_ptr+i-1);
					HINT(i);
				}
				pointer tmp = _ptr+pst;
				for (size_type i = 0; i < n; ++i)
					_alloc.construct(tmp+i, val);
				_size += n;
			}
			
			template <class InputIterator>
			void insert(iterator pos, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) {
				size_type len = std::distance(first, last);
				if (is_available() < len)
					reserve((_capacity<<1) + len);
				for (iterator it = (end()-1); it >= pos; --it) {
					_alloc.construct(&(*(it+len)), *it);
					_alloc.destroy(&(*it));
				}
				for (InputIterator it = first; it != last; ++it)
					_alloc.construct(&(*it), *it);
				_size += len;
			}
			iterator erase (iterator pos) {
				iterator it = begin();
				while (it != pos)
					++it;
				_alloc.destroy(&(*it));
				for (; it + 1 != end(); ++it) {
					_alloc.construct(&(*it), *(it+1));
				}
				_alloc.destroy(end()-1);
				--_size;
				return pos;
			}
			iterator erase (iterator first, iterator last) {
				size_type len = std::distance(first, last);
				pointer ret = first;
				pointer pos = first;
				for (; first != last; ++first)
					_alloc.destroy(&(*first));
				for (iterator it = last; it != end(); ++it) {
					_alloc.construct(&(*pos++), *(it));
					_alloc.destroy(&(*it));
				}
				_size -= len;
				return ret;
			}
			void swap (vector& x) {
				std::swap(this->_alloc, x._alloc);
				std::swap(this->_ptr, x._ptr);
				std::swap(this->_size, x._size);
				std::swap(this->_capacity, x._capacity);
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
