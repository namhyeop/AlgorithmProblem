#include<bits/stdc++.h>

using namespace std;

int n;
int arr[2000005];
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		arr[tmp + 1000000]++;
	}

	for (int i = 0; i <= 2000000; i++)
	{
		while (arr[i]--)
			cout << i - 1000000 << "\n";
	}
}
