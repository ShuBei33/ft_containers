/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:16:38 by estoffel          #+#    #+#             */
/*   Updated: 2023/01/11 23:47:09 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <iostream>

int	main() {
	int	tab[] = {0,1,2,3,4,5,6,7,8,9};

	// ft::is_integral<int*>::value;
	std::cout << std::boolalpha << "answer is " << ft::is_integral<int>::value << std::endl;
	// std::cout << "answer is " << *(ben + 2) << std::endl;
	return 0;
}