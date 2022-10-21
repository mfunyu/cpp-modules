/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:44:58 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/19 14:15:53 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <string>

class RobotomyRequestForm : public Form
{
  private:
	RobotomyRequestForm();
	virtual void beExecuted() const;

  public:
	static const int kGradeToSign = 72;
	static const int kGradeToExec = 45;

	virtual ~RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const& other);
	RobotomyRequestForm& operator=(RobotomyRequestForm const& other);

	RobotomyRequestForm(std::string target);
};

#endif /* ROBOTOMYREQUESTFORM_HPP */
