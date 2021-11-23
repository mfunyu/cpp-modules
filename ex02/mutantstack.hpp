/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:12:27 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/23 23:43:51 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
  private:
  public:
	MutantStack() {}
	~MutantStack() {}
	MutantStack(MutantStack const& other) { *this = other; }
	MutantStack& operator=(MutantStack const& other)
	{
		if (this != &other) {}
		return *this;
	}

	typedef typename std::stack<T>::container_type::reverse_iterator iterator;

	iterator begin() { return (this->c.rbegin()); }
	iterator end() { return (this->c.rend()); }
};

#endif /* MUTANTSTACK_HPP */
