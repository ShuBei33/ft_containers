/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:34:15 by estoffel          #+#    #+#             */
/*   Updated: 2023/01/12 04:19:04 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "utils.hpp"
#include "vector.hpp"

namespace ft {

	template< class T, class Container = ft::vector< T > > class stack {
		public:
			typedef Container container_type;
			typedef typename Container::value_type value_type;
			typedef typename Container::size_type size_type;

			explicit stack(const Container& cont = Container()): c(cont) { } //construct
			stack(const stack& other): c(other.c) { } //cpy
			stack& operator=(const stack& other) {
				this->c = other.c;
				return *this;
			} //asgn
			~stack() { } //destruct

			bool empty() const {
				return c.empty();
			}
			size_type size() const {
				return c.size();
			}
			value_type& top() {
				return c.back();
			}
			const value_type& top() const {
				return c.back();
			}
			void push (const value_type& val) {
				c.push_back(val);
			}
			void pop() {
				c.pop_back();
			}

			template< class _T, class _Container >
				friend bool operator==(const stack< _T,_Container >& lhs, const stack< _T,_Container >& rhs);
			template< class _T, class _Container >
				friend bool operator!=(const stack<_T,_Container>& lhs, const stack<_T,_Container>& rhs);
			template< class _T, class _Container >
				friend bool operator<(const stack<_T,_Container>& lhs, const stack<_T,_Container>& rhs);
			template< class _T, class _Container >
				friend bool operator<=(const stack<_T,_Container>& lhs, const stack<_T,_Container>& rhs);
			template< class _T, class _Container >
				friend bool operator>(const stack<_T,_Container>& lhs, const stack<_T,_Container>& rhs);
			template< class _T, class _Container >
				friend bool operator>=(const stack<_T,_Container>& lhs, const stack<_T,_Container>& rhs);
	
		protected:
			Container c;

	};

	//usage of friend bc c is protected
	template< class _T, class _Container >
		bool operator==(const stack< _T,_Container >& lhs, const stack< _T,_Container >& rhs) {
			return lhs.c==rhs.c;
		}

	template< class _T, class _Container >
			bool operator!=(const stack< _T,_Container >& lhs, const stack< _T,_Container >& rhs) {
				return lhs.c!=rhs.c;
			}

	template< class _T, class _Container >
			bool operator<(const stack< _T,_Container >& lhs, const stack< _T,_Container >& rhs) {
				return lhs.c<rhs.c;
			}

	template< class _T, class _Container >
			bool operator<=(const stack< _T,_Container >& lhs, const stack< _T,_Container >& rhs) {
				return lhs.c<=rhs.c;
			}

	template< class _T, class _Container >
			bool operator>(const stack< _T,_Container >& lhs, const stack< _T,_Container >& rhs) {
				return lhs.c>rhs.c;
			}

	template< class _T, class _Container >
			bool operator>=(const stack< _T,_Container >& lhs, const stack< _T,_Container >& rhs) {
				return lhs.c>=rhs.c;
			}
}