#include"stdafx.h"
#include<iostream>
using namespace std;

int main(int argc, char argv[])
{
	int n;
	cin >> n;
	int Array[1000] = {0};
	int tmp, tmp1 = 0;;
	for (int i = 0; i < n; i++)
	{
		cin >> Array[i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n-(i+1); j++)
		{
			if (Array[j] > Array[j + 1])
			{
				tmp = Array[j + 1];
				Array[j + 1] = Array[j];
				Array[j] = tmp;
			}
		}
	}

	tmp = 0;

		for (int i = 0; i < n; i++)
		{
			tmp += Array[i];
			tmp1 += tmp;

		}
		
		printf("%d", tmp1);
}
