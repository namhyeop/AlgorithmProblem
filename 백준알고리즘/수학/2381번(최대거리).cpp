#include<bits/stdc++.h>

using namespace std;
const int MAX = 10000 * 5 + 1;

int n;
int a[MAX];
int b[MAX];

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		a[i] = tmp1 + tmp2;
		b[i] = tmp1 - tmp2;
	}
	sort(a, a + n);
	sort(b, b + n);
	int ret = max(a[n - 1] - a[0], b[n - 1] - b[0]);
	cout << ret << "\n";

	return 0;
}
