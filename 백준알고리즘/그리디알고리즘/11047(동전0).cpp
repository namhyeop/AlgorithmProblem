#include<bits/stdc++.h>

using namespace std;

int n, k, ret;
int arr[11];
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = n - 1; i >= 0; i--)
	{
		ret += k / arr[i];
		k %= arr[i];
	}
	cout << ret << "\n";
}
/*
#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int count=0;
	int N, TargetValue;
	int Array[10];
	cin >> N >>TargetValue;

	for (int i = 0; i < N; i++)
	{
		cin >> Array[i];
	}
	
		for (int j = N ; j > 0; j--)
		{
			if ((TargetValue / Array[j-1]) != 0)
			{
				count += TargetValue / Array[j-1];
				TargetValue = TargetValue % Array[j-1];

			}
			
		}
	
	cout << count << endl;
}
*/
