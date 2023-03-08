/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:34:12 by estoffel          #+#    #+#             */
/*   Updated: 2023/03/03 01:06:27 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "utils.hpp"
#include <functional>

namespace ft {
	template< class Key,class T, class Compare = less<Key>,class Alloc = allocator<pair<const Key,T> > > class map {
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef pair<const key_type,mapped_type> value_type;
			typedef Compare key_compare;
			//TODO value_compare;
			typedef Alloc allocator_type;
			typedef allocator_type::reference reference;
			typedef allocator_type::const_reference const_reference;
			typedef allocator_type::pointer pointer;
			typedef allocator_type::const_pointer const_pointer;
			typedef ft::rbt_iterator<value_type> iterator;
			typedef ft::rbt_iterator<const value_type> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
			typedef typename allocator_type::size_type size_type;

			explicit map (const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type()) {}

			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) {
				
			}

			map(const map& x) {}

			map& operator=(const map& x) {}

			~map() {}


	//---------------------------------------- ITERATORS ----------------------------------------//



			iterator begin() {
				
			}

			const_iterator begin() const {
				
			}

			iterator end() {
				
			}

			const_iterator end() const {
				
			}

			reverse_iterator rbegin() {
				
			}

			const_reverse_iterator rbegin() const {
				
			}

			reverse_iterator rend() {
				
			}

			const_reverse_iterator rend() const {
				
			}



	//---------------------------------------- CAPACITY -----------------------------------------//



			bool empty() const {
				
			}

			size_type size() const {
				
			}

			size_type max_size() const {
				
			}



	//------------------------------------- ELEMENT ACCESS --------------------------------------//



			mapped_type& operator[](const key_type& k) {
				
			}



	//--------------------------------------- MODIFIERS -----------------------------------------//



			pair<iterator,bool> insert(const value_type& val) {
				
			}

			iterator insert(iterator position, const value_type& val) {
				
			}

			template <class InputIterator>
			void insert(InputIterator first, InputIterator last) {
				
			}

			void erase(iterator position) {
				
			}

			size_type erase(const key_type& k) {
				
			}

			void erase(iterator first, iterator last) {
				
			}

			void swap(map& x) {
				
			}
			void clear() {
				
			}



	//--------------------------------------- OBSERVERS -----------------------------------------//



			key_compare key_comp() const {
				
			}
			value_compare value_comp() const {
				
			}



	//--------------------------------------- OPERATIONS ----------------------------------------//



			iterator find (const key_type& k) {
				
			}

			const_iterator find (const key_type& k) const {
				
			}

			size_type count (const key_type& k) const {
				
			}

			iterator lower_bound (const key_type& k) {
				
			}

			const_iterator lower_bound (const key_type& k) const {
				
			}

			iterator upper_bound (const key_type& k) {
				
			}

			const_iterator upper_bound (const key_type& k) const {
				
			}

			pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
				
			}

			pair<iterator,iterator> equal_range (const key_type& k) {
				
			}



	//--------------------------------------- ALLOCATOR -----------------------------------------//



			allocator_type get_allocator() const {
				
			}
	};
}