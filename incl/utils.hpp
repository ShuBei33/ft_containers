/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:34:19 by estoffel          #+#    #+#             */
/*   Updated: 2023/02/14 04:04:38 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iterator>

namespace ft
{

	//----------------------------------------- UTILITY -----------------------------------------//


	//std::pair
	template< class T1, class T2 > struct pair {
		//public:
		typedef T1 first_type;
		typedef T2 second_type;

		first_type	first;
		second_type	second;

		pair() {}
		template < class U, class V > pair(const pair< U,V >& pr) { this->first = pr.first; this->second = pr.second;}
		pair(const first_type& a, const second_type& b) { this->first = a; this->second = b; }
		pair& operator=(const pair& pr) {
			this->first = pr.first;
			this->second = pr.second;
			return *this;
		}
		~pair() {}
	};

	//lhs = left hand symbol
	template< class T1, class T2 >
		bool operator==(const pair< T1,T2 >& lhs, const pair< T1,T2 >& rhs) {
			return lhs.first==rhs.first && lhs.second==rhs.second;
		}

	template< class T1, class T2 >
		bool operator!=(const pair< T1,T2 >& lhs, const pair< T1,T2 >& rhs) {
			return !(lhs==rhs);
		}

	template< class T1, class T2 >
		bool operator<(const pair< T1,T2 >& lhs, const pair< T1,T2 >& rhs) {
			return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
		}

	template< class T1, class T2 >
		bool operator<=(const pair< T1,T2 >& lhs, const pair< T1,T2 >& rhs) {
			return !(rhs<lhs);
		}

	template < class T1, class T2 >
		bool operator>(const pair< T1,T2 >& lhs, const pair< T1,T2 >& rhs) {
			return rhs<lhs;
		}

	template< class T1, class T2 >
		bool operator>=(const pair< T1,T2 >& lhs, const pair< T1,T2 >& rhs) {
			return !(lhs<rhs);
		}

	//std::make_pair
	template< class T1, class T2 >
		pair< T1,T2 > make_pair(T1 x, T2 y) {
			return (pair< T1,T2 >(x,y));
		}


	//---------------------------------------- ALGORITHM ----------------------------------------//


	//std::equal
	template< class InputIterator1, class InputIterator2 >
		bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
			while (first1!=last1) {
				if (!(*first1==*first2))
					return false;
				++first1;
				++first2;
			}
			return true;
		}

	//std::lexicographical_compare
	template< class InputIterator1, class InputIterator2 >
		bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
			while (first1!=last1)
			{
				if (first2==last2 || *first2<*first1) return false;
				else if (*first1<*first2) return true;
				++first1;
				++first2;
			}
			return (first2!=last2);
		}


	//--------------------------------------- TYPE TRAITS ---------------------------------------//


	//parent of std::is_integral
	template < class T, T v > struct integral_constant {
		static T const value = v;
		typedef T value_type;
		typedef integral_constant< T, v > type;
		operator T() { return v; }
	};

	typedef integral_constant< bool,false > false_type;
	typedef integral_constant< bool,true > true_type;

	//std::is_integral
	template< class T > struct is_integral: public false_type { };

	template< > struct is_integral< bool >: public true_type { };
	template< > struct is_integral< char >: public true_type { };
	template< > struct is_integral< signed char >: public true_type { };
	template< > struct is_integral< short int >: public true_type { };
	template< > struct is_integral< int >: public true_type { };
	template< > struct is_integral< long int >: public true_type { };
	template< > struct is_integral< long long int >: public true_type { };
	template< > struct is_integral< unsigned char >: public true_type { };
	template< > struct is_integral< unsigned short int >: public true_type { };
	template< > struct is_integral< unsigned int >: public true_type { };
	template< > struct is_integral< unsigned long int >: public true_type { };
	template< > struct is_integral< unsigned long long int >: public true_type { };
	template< > struct is_integral< wchar_t >: public true_type { };

	//std::enable_if
	template< bool Cond, class T = void > struct enable_if {};
	template< class T > struct enable_if< true, T > { typedef T type; };


	//---------------------------------------- ITERATOR -----------------------------------------//


	//std::iterator_traits
	template < class Iter > struct iterator_traits {
		typedef typename Iter::difference_type difference_type;
		typedef typename Iter::value_type value_type;
		typedef typename Iter::pointer pointer;
		typedef typename Iter::reference reference;
		typedef typename Iter::iterator_category iterator_category;
	};
	
	template < class T > struct iterator_traits< T* > {
		typedef std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template < class T > struct iterator_traits< const T* > {
		typedef std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef const T* pointer;
		typedef const T& reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	//std::reverse_iterator
	template < class Iterator > class reverse_iterator {
		public:
			typedef Iterator iterator_type;
			typedef typename iterator_traits< Iterator >::iterator_category iterator_category;
			typedef typename iterator_traits< Iterator >::value_type value_type;
			typedef typename iterator_traits< Iterator >::difference_type difference_type;
			typedef typename iterator_traits< Iterator >::pointer pointer;
			typedef typename iterator_traits< Iterator >::reference reference;

			reverse_iterator() { }
			explicit reverse_iterator(iterator_type it) { this->it = it; }
			template < class Iter > reverse_iterator(const reverse_iterator< Iter >& rev_it) { this->it = rev_it.base(); }
			~reverse_iterator() { }
			
			iterator_type base() const { return this->it; }

			reference operator*() const {
				iterator_type iter = it;
				--iter;
				return *iter;
			}
			reverse_iterator operator+(difference_type n) const {
				iterator_type iter = it - n;
				return reverse_iterator(iter);
			}
			reverse_iterator operator++(int) {
				reverse_iterator iter = *this;
				++(*this);
				return iter;
				}
			reverse_iterator& operator++() {
				--it;
				return *this;
			}
			reverse_iterator& operator+=(difference_type n) {
				it -= n;
				return *this;
			}
			reverse_iterator operator-(difference_type n) const {
				iterator_type iter = it + n;
				return reverse_iterator(iter);
			}
			reverse_iterator operator--(int) {
				reverse_iterator iter = *this;
				--(*this);
				return iter;
			}
			reverse_iterator& operator--() {
				++it;
				return *this;
			}
			reverse_iterator& operator-=(difference_type n) {
					it += n;
				return *this;
			}
			pointer operator->() const {
				return &(**this);
			}
			reference operator[](difference_type n) const {
				return it[-n -1];
			}

		private:
			iterator_type it;
	};

	template< class Iterator1, class Iterator2 >
		bool operator==(const reverse_iterator< Iterator1 >& lhs,const reverse_iterator< Iterator2 >& rhs) {
			return lhs.base()==rhs.base();
		}

	template< class Iterator1, class Iterator2 >
		bool operator!=(const reverse_iterator< Iterator1 >& lhs,const reverse_iterator< Iterator2 >& rhs) {
			return lhs.base()!=rhs.base();
		}

	template< class Iterator1, class Iterator2 >
		bool operator<(const reverse_iterator< Iterator1 >& lhs,const reverse_iterator< Iterator2 >& rhs) {
			return lhs.base()>rhs.base();
		}

	template< class Iterator1, class Iterator2 >
		bool operator<=(const reverse_iterator< Iterator1 >& lhs,const reverse_iterator< Iterator2 >& rhs) {
			return lhs.base()>=rhs.base();
		}

	template< class Iterator1, class Iterator2 >
		bool operator>(const reverse_iterator< Iterator1 >& lhs,const reverse_iterator< Iterator2 >& rhs) {
			return lhs.base()<rhs.base();
		}

	template< class Iterator1, class Iterator2 >
		bool operator>=(const reverse_iterator< Iterator1 >& lhs,const reverse_iterator< Iterator2 >& rhs) {
			return lhs.base()<=rhs.base();
		}

	template< class Iterator >
		reverse_iterator< Iterator > operator+(typename reverse_iterator< Iterator >::difference_type n,const reverse_iterator< Iterator >& rev_it) {
			return rev_it + n;
		}

	template< class Iterator1, class Iterator2 >
		typename reverse_iterator< Iterator1 >::difference_type operator-(const reverse_iterator< Iterator1 >& lhs,const reverse_iterator< Iterator2 >& rhs) {
			return rhs.base()-lhs.base();
	}
}
