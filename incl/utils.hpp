/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:34:19 by estoffel          #+#    #+#             */
/*   Updated: 2023/01/07 20:07:35 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{
	//std::pair
	template< class T1, class T2 > struct pair {
		//public:
		typedef T1 first_type;
		typedef T2 second_type;

		first_type	first;
		second_type	second;

		pair();
		template < class U, class V > pair (const pair< U,V >& pr);
		pair (const first_type& a, const second_type& b);
		pair& operator=(const pair& pr);
		~pair();
	};

	template< class T1, class T2 >
		bool operator==(const pair< T1,T2 >& lhs, const pair< T1,T2 >& rhs) {
			return lhs.first==rhs.first && lhs.second==rhs.second;
		}

	template< class T1, class T2 >
		bool operator!=(const pair< T1,T2 >& lhs, const pair< T1,T2 >& rhs) {
			return !(lhs==rhs);
		}

	template< class T1, class T2 >
		bool operator< (const pair< T1,T2 >& lhs, const pair< T1,T2 >& rhs) {
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
		pair< T1,T2 > make_pair (T1 x, T2 y)
		{
			return (pair< T1,T2 >(x,y));
		}

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
		bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
			while (first1!=last1)
			{
				if (first2==last2 || *first2<*first1) return false;
				else if (*first1<*first2) return true;
				++first1;
				++first2;
			}
			return (first2!=last2);
		}

	//std::is_integral
	template< class T > struct is_integral {
		//public
		typedef T value_type;
	};

	//std::iterator_traits
	template <class Iterator> class iterator_traits {
		
	};
}
