#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;

int Testcase;
int n;
long long ret;
vector<int> v;
int maxValue[MAX];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> Testcase;

	while (Testcase--)
	{
		cin >> n;

		v.clear();
		v.resize(n);
		ret = 0;

		for (int i = 0; i < n; i++)
			cin >> v[i];
		
		int	max = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			if (v[i] > max)
				max = v[i];
			maxValue[i] = max;
		}

		int size = v.size();
		for (int i = 0; i < size; i++)
		{
			if (maxValue[i] - v[i] > 0)
				ret += maxValue[i] - v[i];
		}

		cout << ret << "\n";
	}
	return 0;
}
