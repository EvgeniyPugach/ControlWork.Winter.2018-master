#include <iostream>

using namespace std;

const int maxSize = 10;

int nextSmallerThan(int);
void nextSmallerThanTests();
void createNullArray(int *, int);
void getDigits(int, int *);
bool equalArray(int *, int *, int);


int main()
{
	nextSmallerThanTests();

	system("pause");
	return 0;
}

int nextSmallerThan(int number)
{
	int arrayNumbers[maxSize];
	int newArrayNumbers[maxSize];

	createNullArray(arrayNumbers, maxSize);
	getDigits(number, arrayNumbers);

	for (int i = number - 1; i > 0; i--)
	{
		getDigits(i, newArrayNumbers);

		if (equalArray(arrayNumbers, newArrayNumbers, maxSize))
		{
			return i;
		}
	}
	return -1;
}

bool equalArray(int * firstArray, int * secondArray, int size)
{
	for (int j = 0; j < size; j++)
	{
		if (firstArray[j] != secondArray[j])
		{
			return false;
		}
	}

	return true;
}



void getDigits(int number, int * arr)
{
	createNullArray(arr, maxSize);

	while (number > 0)
	{
		int digit = number % 10;
		arr[digit] += 1;
		number /= 10;
	}

}

void createNullArray(int * arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = 0;
	}
}

void nextSmallerThanTests()
{
	cout << (nextSmallerThan(21) == 12) << endl;
	cout << (nextSmallerThan(531) == 513) << endl;
	cout << (nextSmallerThan(2071) == 2017) << endl;
	cout << (nextSmallerThan(9) == -1) << endl;
	cout << (nextSmallerThan(111) == -1) << endl;
	cout << (nextSmallerThan(135) == -1) << endl;
	cout << (nextSmallerThan(1027) == -1) << endl;
	//...
	cout << (nextSmallerThan(12846) == 12684) << endl;
	cout << (nextSmallerThan(671) == 617) << endl;
	cout << (nextSmallerThan(1912) == 1129) << endl;
	cout << (nextSmallerThan(2016) == 1062) << endl;
	cout << (nextSmallerThan(-10) == -1) << endl;
	cout << (nextSmallerThan(1234) == -1) << endl;
	cout << (nextSmallerThan(177) == -1) << endl;
	cout << (nextSmallerThan(987654321) == 987654312) << endl;
}
