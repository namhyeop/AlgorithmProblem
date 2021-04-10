#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

int Testcase;
vector<int> v;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> Testcase;

	for (int i = 0; i < Testcase; i++)
	{
		int n;
		cin >> n;
		v.resize(n);

		for (int i = 0; i < n; i++)
			cin >> v[i];

		int curiValue;
		bool flag = false;
		bool flag1 = false;
		for (int i = 0; i < n; i++)
		{
			if (flag == true)
			{
				flag1 = true;
				if (curiValue == v[i])
					cout << i  << "\n";
				else
					cout << i - 1 << "\n";
				break;
			}

			if (i != 0)
			if (v[i] != v[i - 1])
			{
				curiValue = v[i -1] ;
				flag = true;
			}
		}	

		if (flag1 == false)
			cout << n << "\n";
	}

	return 0;
}
