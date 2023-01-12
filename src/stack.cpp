/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:34:32 by estoffel          #+#    #+#             */
/*   Updated: 2023/01/12 05:04:46 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"
#include <iostream>

int	main()
{
	ft::stack<int> s;
	std::cout << std::boolalpha << "Stack is empty: " << (s.empty()) << std::endl; //start empty
	std::cout << "Stack size is: " << (s.size()) << '\n' << std::endl;
	std::cout << "- Add int 8 on top of the stack -\n\n";
	s.push(8);
	std::cout << "Stack is empty: " << (s.empty()) << std::endl;
	std::cout << "Stack size is: " << (s.size()) << std::endl;
	std::cout << "Top of stack is: " << (s.top()) << '\n' << std::endl;
	std::cout << "- Add int 1 on top of the stack -\n\n";
	s.push(1);
	std::cout << "Stack is empty: " << (s.empty()) << std::endl;
	std::cout << "Stack size is: " << (s.size()) << std::endl;
	std::cout << "Top of stack is: " << (s.top()) << '\n' << std::endl;
	std::cout << "- remove int 1 on top of the stack -\n\n";
	s.pop();
	std::cout << "Stack is empty: " << (s.empty()) << std::endl;
	std::cout << "Stack size is: " << (s.size()) << std::endl;
	std::cout << "Top of stack is: " << (s.top()) << '\n' << std::endl;
	std::cout << "- remove int 8 on top of the stack -\n\n";
	s.pop();
	std::cout << "Stack is empty: " << (s.empty()) << std::endl;
	std::cout << "Stack size is: " << (s.size()) << std::endl;
	std::cout << "Stack is empty: " << (s.empty()) << std::endl;
		return 0;
}