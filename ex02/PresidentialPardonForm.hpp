/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:56:33 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/04 13:57:59 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include "Form.hpp"

# define PRESIDENTIALPARDON_SIGN 25
# define PRESIDENTIALPARDON_EXEC 5

class PresidentialPardonForm : public Form
{
	private:
		std::string		_target;
		PresidentialPardonForm();

	public:
		~PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &other);
		PresidentialPardonForm	&operator=(PresidentialPardonForm const &other);

		PresidentialPardonForm(std::string target);

		void	beExecuted() const;
};

#endif /* PRESIDENTIALPARDONFORM_HPP */
