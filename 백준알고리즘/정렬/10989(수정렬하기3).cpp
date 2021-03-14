#include<bits/stdc++.h>

using namespace std;

int n;
int arr[10001];
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int maxValue = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		arr[tmp]++;

		if (tmp > maxValue)
			maxValue = tmp;
	}

	for (int i = 0; i <= maxValue; i++)
	{
		while (arr[i]--)
			cout << i << "\n";
	}
}
