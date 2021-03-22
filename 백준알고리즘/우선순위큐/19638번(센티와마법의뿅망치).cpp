#include<bits/stdc++.h>

using namespace std;

int ctryMan;
int Key;
int Testcase;

int main()
{
	cin >> ctryMan >> Key >> Testcase;
	int average = INT_MAX;
	priority_queue<int, vector<int>, less<int>> pq;
	for (int i = 0; i < ctryMan; i++)
	{
		int tmp;
		cin >> tmp;
		pq.push(tmp);
	}

	int cnt = 0;
	while (Testcase--)
	{
		int frontValue = pq.top();
		if (frontValue < Key)
		{
			cout << "YES\n";
			cout << cnt << "\n";
			return 0;
		}
		else
		{
			if (frontValue > 1)
			{
				frontValue /= 2;
				pq.pop();
				pq.push(frontValue);
			}
		}
		cnt++;
	}

	if (pq.top() < Key)
	{
		cout << "YES\n";
		cout << cnt << "\n";
	}
	else
	{
		cout << "NO" << '\n';
		cout << pq.top() << '\n';
	}

	return 0;
}
