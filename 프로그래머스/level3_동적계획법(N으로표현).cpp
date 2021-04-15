#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;
const int minValue = 9;

int getValue(int N, int cnt)
{
	int ret = 0;
	for (int i = 0; i < cnt; i++)
		ret = ret * 10 + N;

	return ret;
}
int solution(int N, int number)
{
	vector<set<int>> v(minValue);

	for (int i = 1; i < minValue; i++)
	{
		v[i].insert(getValue(N, i));
		for (int j = 1; j < i; j++)
		{
			for (int k = 1; k < i; k++)
			{
				if (j + k == i)
				{
					for (auto a : v[j])
					{
						for (auto b : v[k])
						{
							v[i].insert(a + b);
							v[i].insert(a*b);
							if (a > b)
								v[i].insert(a - b);
							if (a < b)
								v[i].insert(b - a);
							if (b > 0)
								v[i].insert(a / b);
							if (a > 0)
								v[i].insert(b / a);
						}
					}
				}
			}
		}
	}

	for (int i = 1; i < minValue; i++)
	for (auto a : v[i])
	if (a == number)
		return i;
	return -1;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cout << solution(5, 1230) << "\n";
}
