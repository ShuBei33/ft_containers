/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:34:36 by estoffel          #+#    #+#             */
/*   Updated: 2023/02/08 00:05:43 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
//#define STD


#ifdef STD
#define NS std
#else
#define NS ft
#endif

template <typename T>
void debug(const NS::vector<T>& v) {
	for (typename NS::vector<T>::size_type i = 0; i < v.size(); ++i) {
		std::cout << v[i] << std::endl;
	}
	std::cout << v.size() << std::endl;
	std::cout << v.capacity() << std::endl;
	std::cout << v.empty() << std::endl;
	std::cout << v.max_size() << std::endl;
}


int	main()
{
	NS::vector<int> v;
	for (int x = 1; x <= 10; ++x) {
		v.push_back(x);
	}

	
	NS::vector<int>::iterator it = v.begin();
	

	debug(v);
	v.insert(it, 666);
	debug(v);


	NS::vector<int> v2;
	v2.push_back(123);
	
	v = v2;
	
	
	return 0;
}