/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:09:32 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/16 14:33:48 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	private:

	public:
		Cat();
		virtual ~Cat();
		Cat(Cat const &other);
		Cat	&operator=(Cat const &other);

		virtual void	makeSound() const;
};

#endif /* CAT_HPP */
