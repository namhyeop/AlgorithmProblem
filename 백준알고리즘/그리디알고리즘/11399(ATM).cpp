#include<bits/stdc++.h>

using namespace std;
const int MAX = 1001;

int arr[MAX];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	sort(arr, arr + n);

	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		int tmpSum = 0;
		for (int j = 0; j <= i; j++)
		{
			tmpSum += arr[j];
		}
		ret += tmpSum;
	}
	cout << ret << "\n";
	
	return 0;
}

/*
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
*/
