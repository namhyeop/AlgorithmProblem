#include<bits/stdc++.h>

using namespace std;

int arr[202];
int main(void)
{
	int n;
	int v;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int tmp = 100;
		cin >> tmp;
		arr[tmp + 100]++;
	}
	cin >> v;
	cout << arr[v + 100] << "\n";

	return 0;
}
