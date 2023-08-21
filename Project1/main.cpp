#include <iostream>

#define print(x) std::cout << x << std::endl;

void recursive(uint64_t n)
{
	static uint64_t tempNumb = 1;

	if (n <= 1)
	{
		print("Done!")
		return;
	}
	tempNumb *= n;

	print(tempNumb)

	recursive(n - 1);
}

void recursive_ptr(uint64_t &n)
{
	static uint64_t tempNumb = n;

	tempNumb -= 1;

	print(n)

	if (tempNumb <= 1)
	{
		print("Done!")
		return;
	}

	n *= tempNumb;

	recursive_ptr(n);
}

void fibby(uint64_t n)
{
	static uint64_t n_1 = 0;
	static uint64_t n_2 = 0;

	if (n < 1)
	{
		print("Done!")
		return;
	}
	if (n_1 < 1)
	{
		print(n_1)
		n_1 += 1;
		fibby(n - 1);
	}
	else
	{
		uint64_t tempNumb = n_1 + n_2;
		n_2 = n_1;
		n_1 = tempNumb;

		print(tempNumb)

		fibby(n - 1);
	}
}

int main()
{
	int choice;

	std::cout << "1 = recursive" << std::endl << "2 = fibby" << std::endl;
	std::cin >> choice;

	std::cout << "\033c";

	if (choice == 1)
	{
		print("Give me a number!")
		uint64_t number;

		std::cin >> number;

		recursive_ptr(number);
	}
	else if (choice == 2)
	{
		print("Give me a number!")
		uint64_t number;

		std::cin >> number;

		fibby(number);
		
	}
	else
	{
		print("invalid input!")
		print("choose again!")
		return main();
	}

	return 1;
}