/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 21:27:52 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/16 21:03:54 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	private:
		static const unsigned int	kMaxIdeas = 100;

		std::string		_ideas[kMaxIdeas];

	public:
		Brain();
		~Brain();
		Brain(Brain const &other);
		Brain	&operator=(Brain const &other);

		std::string const &	getIdeas(unsigned int i) const;
		void				setIdeas(unsigned int i, std::string idea);
};

#endif /* BRAIN_HPP */
