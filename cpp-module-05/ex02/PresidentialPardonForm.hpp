/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:56:33 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/19 14:15:35 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"
#include <string>

class PresidentialPardonForm : public Form
{
  private:
	PresidentialPardonForm();
	virtual void beExecuted() const;

  public:
	static const int kGradeToSign = 25;
	static const int kGradeToExec = 5;

	virtual ~PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const& other);
	PresidentialPardonForm& operator=(PresidentialPardonForm const& other);

	PresidentialPardonForm(std::string target);
};

#endif /* PRESIDENTIALPARDONFORM_HPP */
