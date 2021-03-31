#include<bits/stdc++.h>

using namespace std;
const int MAX = 51;
int n;
int a[MAX];
int b[MAX];

int main()
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++)
		cin >> b[i];
	
	sort(a, a + n);
	sort(b, b + n, greater<int>());

	int ret = 0;
	for (int i = 0; i < n; i++)
		ret += a[i] * b[i];

	cout << ret << "\n";
	return 0;
}
