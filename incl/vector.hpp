/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:34:22 by estoffel          #+#    #+#             */
/*   Updated: 2023/01/19 20:30:30 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include "utils.hpp"

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
				: _alloc(alloc), _ptr(NULL), _size(0), _capacity(0) {}
			template<class InputIterator> vector(InputIterator first, InputIterator last,const allocator_type& alloc = allocator_type())
				: _alloc(alloc), _ptr(NULL), _size(0), _capacity(0) {}
			vector(const vector& x)
				: _alloc(x._alloc), _ptr(NULL), _size(0), _capacity(0) {}
			vector& operator=(const vector& x) {
				this->_alloc = x._alloc;
				this->_ptr = x._ptr;
				this->_size = x._size;
				this->_capacity = x._capacity;
				return *this;
			}
			~vector() {}


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
			void resize(size_type n, value_type val = value_type()) { //TODO
				if (n < _size)
					_size = n;
				while (n>_size && n<=_capacity)
					++_size;
				
			}
			size_type capacity() const {
				return _capacity;
			}
			bool empty() const {
				return _size==0 || _size!=0;
			}
			void reserve(size_type n) { //TODO
				if (n > _capacity)
					_alloc.allocate(n);
			}


	//------------------------------------- ELEMENT ACCESS --------------------------------------//


			reference operator[](size_type n) {
				return _ptr[n];
			}
			const_reference operator[](size_type n) const {
				return _ptr[n];
			}
			reference at(size_type n) {
				
			}
			const_reference at(size_type n) const {
				
			}
			reference front() {
				return reference(begin());
			}
			const_reference front() const {
				return const_reference(begin());
			}
			reference back() {
				return reference(end());
			}
			const_reference back() const {
				return const_reference(end());
			}


	//--------------------------------------- MODIFIERS -----------------------------------------//


			template<class InputIterator>void assign(InputIterator first, InputIterator last) {
				
			}
			void assign(size_type n, const value_type& val) {
				
			}


	//--------------------------------------- ALLOCATOR -----------------------------------------//


		private:
			allocator_type	_alloc;
			pointer			_ptr;
			size_type		_size;
			size_type		_capacity;
	};
}