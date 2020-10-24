#include "find.h"
#include <iostream>
using namespace std;
//бинарный поиск
int BinarySearch(int n, int arr[], int search)
{
	int bot = 0;
	int top = n - 1;
	int mid;
	while (top >= bot)
	{
		mid = (top + bot) / 2;
		if (arr[mid] == search)
			return (mid + 1);
		else
		{
			if (arr[mid] < search)
			{
				bot = mid + 1;
			}
			else
			{
				top = mid;
			}
		}
		return -1;
	}
}
//Последовательный поиск элементов
int LineSearch(int mass[], int number)
{
	int flag = 0;
	int i;
	int lengthMass = (sizeof(mass) / sizeof(mass[0])); 
	for (i = 0; i < lengthMass; i++) 
	{
		if (mass[i] == number)
		{
			flag = 0;
			break;
		}
	}
	if (flag == 0)
		cout << "\nValue found at position: " << i + 1;
	else
		cout << "\nValue Not found.";
}