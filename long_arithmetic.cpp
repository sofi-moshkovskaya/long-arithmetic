#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <math.h>
using namespace std;

void set(vector<int>& array1, int size1, vector<int>& array2, int size2)
{
	if (size1 == size2)
	{
		for (int i = 0; i < size1; i++)
		{
			array1.push_back(rand() % 10);
			array2.push_back(rand() % 10);
		}
		return;
	}

	int size_max = fmax(size1, size2);		
	if (size1 == size_max)
	{
		for (int i = 0; i < size1; i++)
		{
			array1.push_back(rand() % 10);
		}
		int dif = abs(size1 - size2);		
		for (int i = 0; i < size1; i++)
		{
			if (dif != 0)
			{
				array2.push_back(0);
				dif--;
			}
			else array2.push_back(rand() % 10);
		}
	}

	else
	{
		for (int i = 0; i < size2; i++)
		{
			array2.push_back(rand() % 10);
		}
		int dif = abs(size1 - size2);		
		for (int i = 0; i < size2; i++)
		{
			if (dif != 0)
			{
				array1.push_back(0);
				dif--;
			}
			else array1.push_back(rand() % 10);
		}
	}
}


void print(vector<int>& numb)
{
	for (int i = 0; i < numb.size(); i++)
	{
		cout << numb[i];
	}
	cout << endl;
}


vector <int> Add(vector<int>& numb1, vector<int>& numb2)
{
	int size = numb1.size();
	vector<int> result;
	int temp = 0;
	for (int i = 1; i <=size; i++)
	{
		int sum=numb1[size-i] + numb2[size-i];
		if(sum>=10)
		{
			sum -= 10;
			result.insert(result.begin(), sum+temp);
			temp = 1;
			continue;
		}

		if (sum+temp== 10)
		{
			temp = 1;
			result.insert(result.begin(), 0);
			continue;
		}
		result.insert(result.begin(), sum+temp);
		temp = 0;
	}
	if (result.size() == size && temp == 1)
		{
			result.insert(result.begin(), 1);
		}
	return result;
}


vector <int> Subtract(vector<int>& numb1, vector<int>& numb2)
{
	int size = numb1.size();
	vector<int> result;
	int temp = 0;
	for (int i = 1; i <= size; i++)
	{
		int diff = numb1[size - i] - numb2[size - i];
		if (diff <= 0)
		{
			diff+=10;
			result.insert(result.begin(), diff + temp);
			temp = -1;
			continue;
		}

		if (diff + temp == 0)
		{
			temp = -1;
			result.insert(result.begin(), 0);
			continue;
		}
		result.insert(result.begin(), diff + temp);
		temp = 0;
	}
	if (result.size() == size && temp == 1)
	{
		result.insert(result.begin(), 1);
	}
	return result;
}






int main()
{
	//генерируется два числа
	srand(time(NULL));
	int first_size = 1+rand() % 100;
	int second_size = 1+rand() % 100;
	cout << "size 1:  " << first_size << "\nsize 2:  " << second_size << endl;

	//длина массива
	int max = fmax(first_size, second_size);

	int const size = first_size;
	vector<int> number1;
	vector<int> number2;

	//забить массивы рандомными числами, длинна одинаковая
	set(number1, first_size, number2, second_size);

	cout << "size 1:  " << number1.size() << "\nsize 2:  " << number2.size() << endl;
	cout << "first number:		";
	print(number1);
	cout << "second number:		";
	print(number2);

	vector<int> number3=Add(number1, number2);
	cout << "summ:                   ";
	print(number3);

	

	return 1;
}