/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:54:57 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/16 16:50:02 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal
{
	protected:
		std::string		_type;

	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(WrongAnimal const &other);
		WrongAnimal	&operator=(WrongAnimal const &other);

		WrongAnimal(std::string type);

		std::string		getType() const;

		void	makeSound() const;
};

#endif /* WRONGANIMAL_HPP */
