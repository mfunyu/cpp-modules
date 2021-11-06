#ifndef DATA_HPP
# define DATA_HPP

# include <string>

class Data
{
	private:
		std::string		_content;

	public:
		Data();
		~Data();
		Data(Data const &other);
		Data	&operator=(Data const &other);

		Data(std::string const & content);

		std::string const&	getContent();
};

#endif /* DATA_HPP */
