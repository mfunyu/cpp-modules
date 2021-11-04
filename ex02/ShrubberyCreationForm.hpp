/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 21:55:40 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/04 14:19:45 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include "Form.hpp"

# define SHRUBBERY_SIGN 145
# define SHRUBBERY_EXEC 137

class ShrubberyCreationForm : public Form
{
	private:
		ShrubberyCreationForm();
		virtual void	beExecuted() const;

	public:
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &other);
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &other);

		ShrubberyCreationForm(std::string target);

};

#endif /* SHRUBBERYCREATIONFORM_HPP */
