#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

# define MAX_MATERIALS 4

#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*	_memory[MAX_MATERIALS];

	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(MateriaSource const &other);
		MateriaSource	&operator=(MateriaSource const &other);

		void		learnMateria(AMateria* a);
		AMateria*	createMateria(std::string const & type);
};

#endif /* MATERIASOURCE_HPP */
