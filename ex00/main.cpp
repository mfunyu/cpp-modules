/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:14:55 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/14 23:27:49 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

/* -------------------------------------------------------------------------- */

#define COLOR_CYAN "\033[36m"
#define COLOR_RESET "\033[0m"

namespace {
void	printHeader(std::string content)
{
	std::cout << std::endl;
	std::cout << COLOR_CYAN << "****** " << content <<\
				 " ******" << COLOR_RESET << std::endl;
}

void	printSubHeader(std::string content)
{
	std::cout << COLOR_CYAN << "[ " << content <<\
				 " ]" << COLOR_RESET << std::endl;
}

void	printHelp()
{
	std::cout << "usage: ./a.out [testname]" << std::endl;
	std::cout << "  \"testnames\"" << std::endl;
	std::cout << "\t\"subject\"\t-> subject's main" << std::endl;
	std::cout << "\t\"original\"\t-> my original main" << std::endl;
	std::cout << "\t\"review\"\t-> main for review (using class Awesome)" << std::endl;
}
} //namespace

/* ------------------------------- For Review ------------------------------- */

namespace review {
class Awesome
{
	public:
		Awesome(int n) : _n(n) {}
		bool operator==(Awesome const &rhs) const { return (this->_n == rhs._n); }
		bool operator!=(Awesome const &rhs) const { return (this->_n != rhs._n); }
		bool operator>(Awesome const &rhs) const { return (this->_n > rhs._n); }
		bool operator<(Awesome const &rhs) const { return (this->_n < rhs._n); }
		bool operator>=(Awesome const &rhs) const { return (this->_n >= rhs._n); }
		bool operator<=(Awesome const &rhs) const { return (this->_n <= rhs._n); }
		int	getN() const { return _n; }
		void print() const { std::cout << this->_n << std::endl; }
	private:
		int _n;
};

std::ostream & operator<<(std::ostream & os, const Awesome & aw)
{
	os << aw.getN();
	return os;
}

void	review_main()
{
	printHeader("Review Main");
	Awesome		a(42);
	Awesome		b(10);

	printSubHeader("MAX");
	std::cout << "a = " << a << ", b = " << b << " | result: " << max<Awesome>(a, b) << std::endl;

	printSubHeader("MIN");
	std::cout << "a = " << a << ", b = " << b << " | result: " << min<Awesome>(a, b) << std::endl;

	printSubHeader("SWAP");
	std::cout << "before: a = " << a << std::endl;
	std::cout << "before: b = " << b << std::endl;
	std::cout << "** swap<Awesome>(a, b) **" << std::endl;
	swap<Awesome>(a, b);
	std::cout << "after : a = " << a << std::endl;
	std::cout << "after : b = " << b << std::endl;
}
} // namespace review

/* ----------------------------- subject's main ----------------------------- */

int		subject_main()
{
	printHeader("Subject Main");
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return 0;
}

void	my_main()
{
	printHeader("MAX");
	std::cout << "max(1, 2) = " << max<int>(1, 2) << std::endl;
	std::cout << "max(42, 42) = " << max<int>(42, 42) << std::endl;
	std::cout << "max(1.51, 1.5) = " << max<double>(1.51, 1.5) << std::endl;
	std::cout << "max(10.001f, 10.002f) = " << max<float>(10.001f, 10.002f) << std::endl;

	printHeader("MIN");
	std::cout << "min(1, 2) = " << min<int>(1, 2) << std::endl;
	std::cout << "min(-999.9, -1000.0) = " << min<double>(-999.9, -1000.0) << std::endl;
	std::cout << "min('a', 'b') = " << min<char>('a', 'b') << std::endl;
	std::cout << "min(\"abc\", \"abd\") = " << min<std::string>("abc", "abd") << std::endl;
	std::cout << "min(\"abd\", \"abc\") = " << min<std::string>("abd", "abc") << std::endl;
	std::cout << "min(\"42tokyo\", \"42Tokyo\") = " << min<std::string>("42tokyo", "42Tokyo") << std::endl;

	printHeader("SWAP");
	{
		/* ft <-> tf */
		printSubHeader("ft <-> tf");
		int		ft = 42;
		int		tf = 24;

		std::cout << "before: ft = " << ft << std::endl;
		std::cout << "before: tf = " << tf << std::endl;
		std::cout << "** swap<int>(ft, tf) **" << std::endl;
		swap<int>(ft, tf);
		std::cout << "after : ft = " << ft << std::endl;
		std::cout << "after : tf = " << tf << std::endl;
	}
	{
		/* AAA <-> aaa */
		printSubHeader("AAA <-> aaa");
		std::string	AAA = "AAA";
		std::string	aaa = "aaa";

		std::cout << "before: AAA = " << AAA << std::endl;
		std::cout << "before: aaa = " << aaa << std::endl;
		std::cout << "** swap<std::string>(AAA, aaa) **" << std::endl;

		::swap<std::string>(AAA, aaa);
		std::cout << "after : AAA = " << AAA << std::endl;
		std::cout << "after : aaa = " << aaa << std::endl;
	}
}

int		main(int ac, char **av)
{
	std::string	test = (ac > 1 ? av[1] : "");

	if (test == "subject") {
		subject_main();
	} else if (test == "original") {
		my_main();
	} else if (test == "review") {
		review::review_main();
	} else {
		printHelp();
	}
}

