/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:14:55 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/07 18:26:13 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int		subject_main() {

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

int		main()
{
	std::cout << "**** Subject Main ****" << std::endl;
	subject_main();
	std::cout << std::endl;

	std::cout << "**** MAX ****" << std::endl;
	std::cout << "max(1, 2) = " << max(1, 2) << std::endl;
	std::cout << "max(42, 42) = " << max(42, 42) << std::endl;
	std::cout << "max(1.51, 1.5) = " << max(1.51, 1.5) << std::endl;
	std::cout << "max(10.001f, 10.002f) = " << max(10.001f, 10.002f) << std::endl;
	std::cout << std::endl;

	std::cout << "**** MIN ****" << std::endl;
	std::cout << "min(1, 2) = " << min(1, 2) << std::endl;
	std::cout << "min(-999.9, -1000.0) = " << min(-999.9, -1000.0) << std::endl;
	std::cout << "min('a', 'b') = " << min('a', 'b') << std::endl;
	std::cout << "min(\"42tokyo\", \"42Tokyo\") = " << min("42tokyo", "42Tokyo") << std::endl;
	std::cout << std::endl;

	std::cout << "**** SWAP ****" << std::endl;
	/* ft <-> tf */
	int		ft = 42;
	int		tf = 24;

	std::cout << "before: ft = " << ft << std::endl;
	std::cout << "before: tf = " << tf << std::endl;
	std::cout << "swap(ft, tf)" << std::endl;
	swap(ft, tf);
	std::cout << "after : ft = " << ft << std::endl;
	std::cout << "after : tf = " << tf << std::endl;
	std::cout << std::endl;

	/* AAA <-> aaa */
	std::string	AAA = "AAA";
	std::string	aaa = "aaa";

	std::cout << "before: AAA = " << AAA << std::endl;
	std::cout << "before: aaa = " << aaa << std::endl;
	std::cout << "swap(AAA, aaa)" << std::endl;
	swap(AAA, aaa);
	std::cout << "after : AAA = " << AAA << std::endl;
	std::cout << "after : aaa = " << aaa << std::endl;
}
