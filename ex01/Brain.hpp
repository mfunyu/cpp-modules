/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 21:27:52 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/31 12:35:51 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

# define TOTAL_IDEAS 100

class Brain
{
	private:
		std::string		_ideas[TOTAL_IDEAS];

	public:
		Brain();
		~Brain();
		Brain(Brain const &other);
		Brain	&operator=(Brain const &other);

		std::string	getIdeas(unsigned int i) const;
		void		setIdeas(unsigned int i, std::string idea);
};

#endif /* BRAIN_HPP */
