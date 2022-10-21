/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 21:55:40 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/19 14:16:32 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <string>

class ShrubberyCreationForm : public Form
{
  private:
	ShrubberyCreationForm();
	virtual void beExecuted() const;

  public:
	static const int kGradeToSign = 145;
	static const int kGradeToExec = 137;

	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const& other);
	ShrubberyCreationForm& operator=(ShrubberyCreationForm const& other);

	ShrubberyCreationForm(std::string target);
};

#endif /* SHRUBBERYCREATIONFORM_HPP */
