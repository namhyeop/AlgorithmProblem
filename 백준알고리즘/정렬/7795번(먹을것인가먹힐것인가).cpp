#include<bits/stdc++.h>

using namespace std;

int Testcase;
vector<int> a,b;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> Testcase;
	while (Testcase--)
	{
		int aSize, bSize;
		cin >> aSize >> bSize;

		a.resize(aSize);
		b.resize(bSize);

		for (int i = 0; i < aSize; i++)
			cin >> a[i];
		for (int i = 0; i < bSize; i++)
			cin >> b[i];

		sort(a.begin(), a.end(),greater<int>());
		sort(b.begin(), b.end());

		int cnt = 0;
		for (int i = 0; i < aSize; i++)
		{
			bool flag = true;
			for (int j = 0; j < bSize; j++)
			{
				if (j == 0 && a[i] <= b[j])
				{
					flag = false;
					break;
				}
				if (a[i] > b[j])
					cnt++;
			}
			if (flag == false)
				break;
		}
		cout << cnt << "\n";
	}
	return 0;
}
