/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:34:36 by estoffel          #+#    #+#             */
/*   Updated: 2023/02/22 17:48:05 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

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
	std::cout << "size: " << v.size() << std::endl;
	std::cout << "capacity: " << v.capacity() << std::endl;
	std::cout << "empty: " << v.empty() << std::endl;
	std::cout << "max_size: " << v.max_size() << std::endl;
}


int	main()
{
	// NS::vector<int> v;
	// for (int x = 1; x <= 10; ++x) {
	// 	v.push_back(x);
	// }

	
	// NS::vector<int>::iterator it = v.begin();
	// it+=v.size();
	

	// debug(v);
	// v.insert(it, 3, 666);
	// debug(v);


	// NS::vector<int> v2;
	// v2.push_back(123);
	
	// v = v2;
	
	
	// return 0;
	NS::vector<int> vct(10);
	NS::vector<int> vct2;
	NS::vector<int> vct3;

	//for (unsigned long int i = 0; i < vct.size(); ++i)
	//	vct[i] = (vct.size() - i) * 3;
	//debug(vct);

	vct2.insert(vct2.end(), 42);
	vct2.insert(vct2.begin(), 2, 21);
	debug(vct2);

	vct2.insert(vct2.end() - 2, 42);
	debug(vct2);

	vct2.insert(vct2.end(), 2, 84);
	debug(vct2);

	vct2.resize(4);
	debug(vct2);

	vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
	vct.clear();
	debug(vct2);

	debug(vct);

	for (int i = 0; i < 5; ++i)
		vct3.insert(vct3.end(), i);
	vct3.insert(vct3.begin() + 1, 2, 111);
	debug(vct3);

	return (0);
}