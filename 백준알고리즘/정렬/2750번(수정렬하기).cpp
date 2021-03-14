#include<bits/stdc++.h>

using namespace std;

int n;
int arr[1001];

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
		cout << arr[i] << "\n";
}
