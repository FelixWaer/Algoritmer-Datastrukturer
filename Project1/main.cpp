#include <iostream>

//just some macros since I am lazy and didn't want to write these lines multiple times
#define PRINT(x) std::cout << (x) << std::endl
#define GET_INPUT(x) std::cin >> (x)
#define CLEAR_CONSOLE std::cout << "\033c"

//Calculates the factorial of the given value and returns the factorial value.
uint64_t calculate_Factorial(uint64_t n)
{
	if (n <= 1)
	{
		return 1;
	}

	return n * calculate_Factorial(n - 1);
}

//Calculates the factorial of the given value and prints all the steps of the calculation. Also returns the factorial value.
uint64_t calculate_FactorialSteps(uint64_t n)
{
	if (n <= 1)
	{
		PRINT(1);
		return 1;
	}

	n *= calculate_FactorialSteps(n - 1);
	PRINT(n);
	return(n);
}

//calculates the fibonacci sequence and prints out the sequence
void calculate_Fibonacci(uint64_t n)
{
	static uint64_t numb1 = 0;
	static uint64_t numb2 = 0;

	if (n < 1)
	{
		numb1 = 0;
		numb2 = 0;
		PRINT("Done!");
		return;
	}
	if (numb1 < 1)
	{
		PRINT(numb1);
		numb1 += 1;
		calculate_Fibonacci(n - 1);
	}
	else
	{
		uint64_t tempNumb = numb1 + numb2;
		numb2 = numb1;
		numb1 = tempNumb;

		PRINT(tempNumb);

		calculate_Fibonacci(n - 1);
	}
}

int main()
{
	int choice;

	while (true)
	{
		PRINT("Choose what you want to see!"),
		PRINT("1 = Recursive factorial calculator");
		PRINT("2 = Recursive factorial calculator with the steps");
		PRINT("3 = Fibonacci sequence");
		GET_INPUT(choice);

		CLEAR_CONSOLE;

		switch (choice)
		{
		case 1: {
			uint64_t number;

			PRINT("Give me a number!");
			GET_INPUT(number);
			CLEAR_CONSOLE;
			PRINT("Here is the result!");

			PRINT(calculate_Factorial(number));

			break;
			}

		case 2: {
			uint64_t number;

			PRINT("Give me a number!");
			GET_INPUT(number);
			CLEAR_CONSOLE;
			PRINT("Here is the result!");

			calculate_FactorialSteps(number);

			break;
			}

		case 3: {
			uint64_t number;

			PRINT("Give me a number!");
			GET_INPUT(number);
			CLEAR_CONSOLE;
			PRINT("Here is the result!");

			calculate_Fibonacci(number);

			break;
			}
		default: {
			continue;
			}
		}

		char restartChoice;
		PRINT("Do you want to go back to the start? Y/N");
		GET_INPUT(restartChoice);

		if (restartChoice == 'N' || restartChoice == 'n')
		{
			break;
		}

		CLEAR_CONSOLE;
	}

	CLEAR_CONSOLE;
	PRINT("Exited program");

	return 1;
}