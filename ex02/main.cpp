#include <iostream>
#include <iomanip>
#include <Array.hpp>

/* ----------------------------- print & format ----------------------------- */

#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"
#define COLOR_CYAN "\033[36m"
#define COLOR_RESET "\033[0m"

void	printHelp()
{
	std::cout << "usage: ./a.out [testname]\n" << std::endl;
	std::cout << "  \"testnames\"" << std::endl;
	std::cout << "\t\"subject\" -> subject test" << std::endl;
	std::cout << "\t\"constructor\" -> constructor test" << std::endl;
	std::cout << "\t\"copyC\" -> copy constructor test" << std::endl;
	std::cout << "\t\"=\" -> assignment operator test" << std::endl;
	std::cout << "\t\"[]\" -> subscription operator test" << std::endl;
	std::cout << "\t\"size\" -> size() test" << std::endl;
}

void	printTestName(std::string test){
	std::cout << COLOR_CYAN << "****** Test " << test <<\
				 " ******" << COLOR_RESET << std::endl;
}

template <typename T>
void	printList(std::string title, Array<T> & elem, int total) {
	std::cout << std::left << std::setw(9) << title << "| ";
	for (int i = 0; i < total; i++) {
		std::cout << "[" << i << "]: " << elem[i] << " " << std::flush;
	}
	std::cout << std::endl;
}


#include <cxxabi.h>
std::string getNameByTypeInfo(std::type_info const& typeInfo)
{
	char*	charName;
	int		status = 0;
	charName = abi::__cxa_demangle(typeInfo.name(), 0, 0, &status);
	std::string	strName(charName);
	std::free(charName);
	return strName;
}

template <typename T>
void	printTestInfo(std::string info1, unsigned int value1) {
	std::cout << COLOR_CYAN << "[ " << \
				 info1 << ": " << value1 << \
				 " <" << getNameByTypeInfo(typeid(T)) << ">" << \
				 " ]" << COLOR_RESET << std::endl;
}

template <typename T>
void	printTestInfo(std::string info1, unsigned int value1,
						std::string info2, int value2)
{
	std::cout << COLOR_CYAN << "[ " << \
				 info1 << ": " << value1 << ", " << \
				 info2 << ": " << value2 << \
				 " <" << getNameByTypeInfo(typeid(T)) << ">" << \
				 " ]" << COLOR_RESET << std::endl;
}

void	printKO() {
	std::cout <<  COLOR_RED << "[KO]" << COLOR_RESET << std::endl;
}

void	printOK() {
	std::cout <<  COLOR_GREEN << "[OK]" << COLOR_RESET << std::endl;
}

/* ------------------------------ subject main ------------------------------ */

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

	for (int i = 0; i < MAX_VAL; i++) {
		if (mirror[i] != numbers[i]) {
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try {
		numbers[-2] = 0;
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}
	try {
		numbers[MAX_VAL] = 0;
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++) {
		numbers[i] = rand();
	}
	delete[] mirror;

	return 0;
}

/* ---------------------------------- tests --------------------------------- */

template <typename T>
void	testSize(unsigned int size)
{
	printTestInfo<T>("size", size);
	Array<T> array(size);

	std::cout << "array.size() = " << array.size() << std::endl;

	if (array.size() != size) {
		printKO();
		return ;
	}
	printOK();
}

template <typename T>
void	testSubscriptOperator(unsigned int size, int index)
{
	printTestInfo<T>("size", size, "index", index);

	Array<T> array(size);
	for (unsigned int i = 0; i < size; i++) {
		array[i] = i;
	}

	try {
		std::cout << "array[" << index << "] = " << std::flush;
		std::cout << array[index] << std::endl;
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;;
	}
}

template <typename T>
void	testAssignmentOperator(unsigned int dst_size, unsigned int src_size)
{
	printTestInfo<T>("dst_size", dst_size, "src_size", src_size);

	Array<T> src(src_size);
	for (unsigned int i = 0; i < src_size; i++) {
		src[i] = i + 'a';
	}

	Array<T> dst(dst_size);
	for (unsigned int i = 0; i < dst_size; i++) {
		dst[i] = i + 'A';
	}

	printList<T>("dst", dst, dst_size);
	printList<T>("src", src, src_size);
	dst = src;
	printList<T>("dst", dst, src_size);
	printList<T>("src", src, src_size);
	printOK();
}

template <typename T>
void	testCopyConstructor(unsigned int original_size)
{
	printTestInfo<T>("original_size", original_size);

	Array<T> original(original_size);
	for (unsigned int i = 0; i < original_size; i++) {
		original[i] = i + 'a';
	}

	Array<T> copy(original);

	printList<T>("original", original, original_size);
	printList<T>("copy", copy, original_size);

	for (unsigned int i = 0; i < original_size; i++) {
		if (original[i] != copy[i]) {
			printKO();
			return ;
		}
	}
	printOK();
}

template <typename T>
void	testConstructor(unsigned int size)
{
	printTestInfo<T>("size", size);

	Array<T> zeroInitializedArray(size);

	printList("zero_initialized", zeroInitializedArray, size);

	for (unsigned int i = 0; i < size; i++) {
		if (zeroInitializedArray[i]) {
			printKO();
			return ;
		}
	}
	printOK();
}
} /* namespace */

int		main(int ac, char **av)
{
	try {
		std::string	test = (ac > 1 ? av[1] : "");

		if (test == "subject") {
			subject_main();
		} else if (test == "constructor") {
			printTestName("Constructor");
			testConstructor<int>(10);
			testConstructor<float>(8);
			testConstructor<const unsigned char>(1);
		} else if (test == "copyC") {
			printTestName("Copy Constructor");
			testCopyConstructor<int>(5);
			testCopyConstructor<float>(8);
			testCopyConstructor<double>(3);
			testCopyConstructor<std::string>(6);
		} else if (test == "=") {
			printTestName("Assignment Operator = ");
			testAssignmentOperator<unsigned int>(3, 2);
			testAssignmentOperator<char>(0, 12);
			testAssignmentOperator<std::string>(5, 5);
		} else if (test == "[]") {
			printTestName("Subscript Operator []");
			testSubscriptOperator<float>(7, 3);
			testSubscriptOperator<unsigned char>(5, -1);
			testSubscriptOperator<long>(2, 5);
		} else if (test == "size") {
			printTestName("size");
			testSize<const float>(3);
			testSize<unsigned char>(0);
			testSize<const std::string>(5);
		} else {
			printHelp();
		}
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
