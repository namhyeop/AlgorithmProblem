#include<bits/stdc++.h>

using namespace std;
const int MAX = 101;

int arr[MAX];

int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	int sum = 0;
	for (int i = n - 1; i >= 1; i--)
	{
		if (arr[i] <= arr[i - 1])
		{
			sum += (arr[i - 1] - arr[i]) + 1;
			arr[i - 1] = arr[i - 1] - ((arr[i - 1] - arr[i]) + 1);
		}
	}

	cout << sum << "\n";
	return 0;
}
