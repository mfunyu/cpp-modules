#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

# define MAX_MATERIALS 4

class AMateria;

class Character : public ICharacter
{
	private:
		std::string		_name;
		// AMateria		_inventory[MAX_MATERIALS];

	public:
		Character();
		~Character();
		Character(Character const &other);
		Character	&operator=(Character const &other);

		Character(std::string name);

		std::string const&	getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
};

#endif /* CHARACTER_HPP */
