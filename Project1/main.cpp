#include <iostream>

//just some macros since I am lazy and didn't want to write these lines multiple times
#define print(x) std::cout << x << std::endl;
#define getInput(x) std::cin >> x;
#define clearConsole std::cout << "\033c";

//This is the fast and simple function to calculate the factorial
uint64_t factorial_Calculator(uint64_t n)
{
	if (n <= 1)
	{
		return 1;
	}
	
	return n * factorial_Calculator(n - 1);
}

//This also calculates the factorial, but it also prints all the steps in the calculation
void factorial_CalculatorPrinter(uint64_t n)
{
	static uint64_t tempNumb = 1;

	if (n <= 1)
	{
		print("Done!")
		tempNumb = 1;
		return;
	}
	tempNumb *= n;

	print(tempNumb)

	factorial_CalculatorPrinter(n - 1);
}

//calculates the fibonacci sequence and prints out the steps
void fibby(uint64_t n)
{
	static uint64_t n_1 = 0;
	static uint64_t n_2 = 0;

	if (n < 1)
	{
		n_1 = 0;
		n_2 = 0;
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

	print("Choose what you want to see!")
	print("1 = Recursive factorial calculator")
	print("2 = Recursive factorial calculator with the steps")
	print("3 = Fibonacci sequence")
	getInput(choice)

	clearConsole

	if (choice == 1)
	{
		print("Give me a number!")
		uint64_t number;

		getInput(number)
		clearConsole

		print("Here is the result!")
		print(factorial_Calculator(number))
	}
	else if (choice == 2)
	{
		print("Give me a number!")
		uint64_t number;

		getInput(number)
		clearConsole

		print("Here is the result!")
		factorial_CalculatorPrinter(number);
	}
	else if (choice == 3)
	{
		print("Give me a number!")
		uint64_t number;

		getInput(number)
		clearConsole

		print("Here is the result!")
		fibby(number);
	}
	else
	{
		print("Invalid Input :(!")
		return 0;
	}

	char restartChoice;
	print("Do you want to go back to the start? Y/N")
	getInput(restartChoice)

	if (restartChoice == 'Y' || restartChoice == 'y')
	{
		clearConsole
		return main();
	}
	else if (restartChoice == 'N' || restartChoice == 'n')
	{
		return 1;
	}

	return 0;
}