#include<bits/stdc++.h>

using namespace std;

int n;
vector<string> v;

bool cmp(string a, string b)
{
	if (a.size() != b.size())
		return a.size() < b.size();
	else
	{
		int sumA = 0;
		int sumB = 0;
		for (int i = 0; i < a.size(); i++)
		{
			if ('0' <= a[i] && a[i] <= '9')
				sumA += a[i] -'0';
		}
		for (int i = 0; i < b.size(); i++)
		{
			if ('0' <= b[i] && b[i] <= '9')
				sumB += b[i] -'0';
		}
		if (sumA != sumB)
			return sumA < sumB;

		else
			return a < b;
	}
}

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++)
		cout << v[i] << "\n";

	return 0;
}
