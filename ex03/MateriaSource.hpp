#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class AMateria;

class MateriaSource : public IMateriaSource
{
	private:

	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(MateriaSource const &other);
		MateriaSource	&operator=(MateriaSource const &other);

		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const & type);
};

#endif /* MATERIASOURCE_HPP */
