#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;

int n;
int arr[MAX];

int cmp(int a, int b)
{
	return a > b;
}

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n, cmp);

	for (int i = 0; i < n; i++)
		cout << arr[i] << "\n";
}
