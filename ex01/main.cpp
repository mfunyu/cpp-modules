/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:57:09 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/03 15:00:52 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int		main()
{
	{
		Bureaucrat	bureaucrat_A("bureaucrat_A", 40);
		Form		form_A("form_A", 10, 40);

		bureaucrat_A.signForm(form_A);
	}
}
