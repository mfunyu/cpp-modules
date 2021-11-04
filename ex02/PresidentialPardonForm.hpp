/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:56:33 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/04 14:18:37 by mfunyu           ###   ########.fr       */
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
		PresidentialPardonForm();
		virtual void	beExecuted() const;

	public:
		~PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &other);
		PresidentialPardonForm	&operator=(PresidentialPardonForm const &other);

		PresidentialPardonForm(std::string target);
};

#endif /* PRESIDENTIALPARDONFORM_HPP */
