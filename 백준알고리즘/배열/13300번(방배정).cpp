#include<bits/stdc++.h>

using namespace std;

int n, k;
int arrW[7];
int arrM[7];
int ret = 0;

int main()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		int sex, grade;
		cin >> sex >> grade;

		if (sex == 0)
			arrW[grade]++;
		else
			arrM[grade]++;
	}

	for (int i = 1; i <= 6 ; i++)
	{
		while (arrW[i])
		{
			if (arrW[i] < k)
			{
				ret++;
				break;
			}
			ret += arrW[i] / k;
			arrW[i] = arrW[i] % k;
		}
	}

	for (int i = 1; i <= 6; i++)
	{
		while (arrM[i])
		{
			if (arrM[i] < k)
			{
				ret++;
				break;
			}
			ret += arrM[i] / k;
			arrM[i] = arrM[i] % k;
		}
	}

	cout << ret << "\n";
}
