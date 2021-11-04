/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:44:58 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/04 12:47:41 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include "Form.hpp"

# define ROBOTOMY_SIGN 72
# define ROBOTOMY_EXEC 45

class RobotomyRequestForm : public Form
{
	private:
		std::string		_target;
		RobotomyRequestForm();

	public:
		~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &other);
		RobotomyRequestForm	&operator=(RobotomyRequestForm const &other);

		RobotomyRequestForm(std::string target);

		void	beExecuted() const;
};

#endif /* ROBOTOMYREQUESTFORM_HPP */
