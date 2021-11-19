/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:58:49 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/19 21:26:49 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#include <string>

class Intern
{
  private:
	template <typename AForm>
	Form* makeAForm(std::string const& target) const;

  public:
	Intern();
	~Intern();
	Intern(Intern const& other);
	Intern& operator=(Intern const& other);

	Form* makeForm(std::string const formName, std::string const& target) const;
};

#endif /* INTERN_HPP */
