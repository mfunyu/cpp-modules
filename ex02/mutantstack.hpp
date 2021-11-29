/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:12:27 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/29 15:26:12 by mfunyu           ###   ########.fr       */
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

	typedef typename std::stack<T>::container_type container_type;

	typedef typename container_type::reverse_iterator		iterator;
	typedef typename container_type::const_reverse_iterator const_iterator;
	typedef typename container_type::iterator				reverse_iterator;
	typedef typename container_type::const_iterator const_reverse_iterator;

	iterator	   begin() { return this->c.rbegin(); }
	const_iterator begin() const { return this->c.rbegin(); }
	iterator	   end() { return this->c.rend(); }
	const_iterator end() const { return this->c.rend(); }

	reverse_iterator	   rbegin() { return this->c.begin(); }
	const_reverse_iterator rbegin() const { return this->c.begin(); }
	reverse_iterator	   rend() { return this->c.end(); }
	const_reverse_iterator rend() const { return this->c.end(); }
};

#endif /* MUTANTSTACK_HPP */
