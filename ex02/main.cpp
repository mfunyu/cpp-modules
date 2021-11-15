#include <iostream>
#include <iomanip>
#include <Array.hpp>

/* ----------------------------- print & format ----------------------------- */

#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"
#define COLOR_CYAN "\033[36m"
#define COLOR_RESET "\033[0m"

void	printTestName(std::string test){
	std::cout << std::endl;
	std::cout << COLOR_CYAN << "****** Test " << test <<\
				 " ******" << COLOR_RESET << std::endl;
}

template <typename T>
void	printElem(int i, T elem, int total) {
	std::cout << "[" << i << "]: " << elem << " " << std::flush;
	if (i == total - 1) {
		std::cout << std::endl;
	}
}

template <typename T>
void	printList(std::string title, Array<T> elem, int total) {
	std::cout << std::left << std::setw(9) << title << "| ";
	for (int i = 0; i < total; i++) {
		printElem(i, elem[i], total);
	}
}

void	printTestInfo(std::string testinfo) {
	std::cout << testinfo << ": ";
}

void	printKO() {
	std::cout <<  COLOR_RED << "[KO]" << COLOR_RESET << std::endl;
}

void	printOK() {
	std::cout <<  COLOR_GREEN << "[OK]" << COLOR_RESET << std::endl;
}

/* ---------------------------------- tests --------------------------------- */

#define MAX_VAL 750

namespace {
int		subject_main()
{
	printTestName("Subject main");
	Array<int> numbers(MAX_VAL);
	int *mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	// SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	std::cout << "same values are saved" << std::endl;
	try
	{
		numbers[-2] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete[] mirror; //

	return 0;
}

template <typename T>
void	testSize(std::string type)
{
	unsigned int	n = 8;
	Array<T> test(n);
	printTestInfo("Accurate size returned <" + type + ">");

	if (test.size() != n) {
		printKO();
		return ;
	}
	printOK();
}

template <typename T>
void	testSubscriptOperator(std::string type)
{
	int		n = 8;
	Array<T> test(n);
	std::string testInfo = "Exception thrown at right index <" + type + ">";
	try {
		for (int i = 0; i < n + 10; i++) {
			test[i] = i * 10;
			if (i >= n) {
				printKO();
				return ;
			}
		}
	} catch (std::exception &e){
		printOK();
	}
}

template <typename T>
void	testAssignmentOperator(std::string type)
{
	int		n = 8;
	int		m = 4;
	Array<T> src(n);
	Array<T> dst(m);
	std::string testInfo = "Running deep copy <" + type + ">";
	dst = src;
	for (int i = 0; i < n; i++) {
		dst[i] = i + 'A';
		if (dst[i] == src[i]) {
			printKO();
			return ;
		}
	}
	printList<T>("dst", dst, n);
	printList<T>("src", src, n);
	printOK();
}

template <typename T>
void	testCopyConstructor(std::string type)
{
	int		n = 5;
	Array<T> original(n);
	Array<T> copy(original);
	std::string testInfo = "Running deep copy <" + type + ">";
	for (int i = 0; i < n; i++) {
		original[i] = i + 'a';
		if (original[i] == copy[i]) {
			printKO();
			return ;
		}
	}
	printList<T>("original", original, n);
	printList<T>("copy", copy, n);
	printOK();
}

template <typename T>
void	testConstructor(std::string type)
{
	int		n = 10;
	Array<T> numbers(n);
	std::string testInfo = "Initialized to default <" + type + ">";
	for (int i = 0; i < n; i++) {
		printElem<T>(i, numbers[i], n);
		if (numbers[i] != 0) {
			printKO();
			return ;
		}
	}
	printOK();
}

void	testConstructor()
{
	std::string testInfo = "Initialized to default <std::string>";
	int		n = 10;
	Array<std::string> strs(n);
	for (int i = 0; i < n; i++) {
		printElem<std::string>(i, strs[i], n);
		if (!strs[i].empty()) {
			printKO();
			return ;
		}
	}
	printOK();
}
} /* namespace */

int		main()
{
	try {
	subject_main();

	printTestName("Constructor");
	testConstructor<int>("int");
	testConstructor<float>("float");
	testConstructor<const unsigned char>("const unsigned char");
	testConstructor();

	printTestName("Copy Constructor");
	testCopyConstructor<int>("int");
	testCopyConstructor<float>("float");
	testCopyConstructor<double>("double");
	testCopyConstructor<std::string>("std::string");

	printTestName("Assignment Operator = ");
	testAssignmentOperator<unsigned int>("unsigned int");
	testAssignmentOperator<char>("char");
	testAssignmentOperator<std::string>("std::string");

	printTestName("Subscript Operator []");
	testSubscriptOperator<float>("float");
	testSubscriptOperator<unsigned char>("unsigned char");
	testSubscriptOperator<int64_t>("int64_t");

	printTestName("size");
	testSize<const float>("const float");
	testSize<unsigned char>("unsigned char");
	testSize<const std::string>("const std::string");

	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
