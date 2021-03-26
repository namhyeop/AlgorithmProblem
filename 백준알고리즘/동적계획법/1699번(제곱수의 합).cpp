#include<bits/stdc++.h>

using namespace std;
const int MAX = 1e5 + 1;
int cache[MAX]; //어떤 자연수 N을 제곱수의 합으로 나타날 때 항의 최소 개수

int main()
{
	int n;
	cin >> n;
	
	for (int i = 0; i <= n; i++)
		cache[i] = i;

	for (int i = 1; i <= n; i++)
	for (int j = 1; j*j <= i; j++)
	{
		cache[i] = min(cache[i], cache[i - j*j] + 1);
		
		/*
		cout << i << " " << j << "\n";
		for (int a = 0; a <= n; a++)
		{
			cout << cache[a] << " ";

		}
		cout << "\n";
		cout << "-----------------------";
		cout << "\n";
		*/
		
	}
	cout << cache[n] << "\n";
}

/*
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

int n;
int maxI = 1;
int psSum[100001];

int search(int sum)
{
	for (int i = 2; i < 100001; i++)
	{
		if (psSum[i] == 1)
			continue;
		int result = 987654321;
		for (int j = (int)sqrt(i); j >= 1; j--)
		{
			int cnt = 1 + psSum[i - (j*j)];
			if (result > cnt)
			{
				result = cnt;
				psSum[i] = result;
			}
		}
	}

	return psSum[n];
}

int main(int argc, char*argv[])
{
	cin >> n;
	memset(psSum, 0, sizeof(psSum));
	while (maxI*maxI <= n)
	{
		psSum[maxI] = maxI * maxI;
		maxI++;
	}
	cout << search(n) << endl;

	return 0;
}
*/
