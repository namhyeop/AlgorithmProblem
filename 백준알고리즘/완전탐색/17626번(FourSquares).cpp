#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

int main(void)
{
	fastio;
	int n;
	cin >> n;

	int maxCycle = sqrt(n) + 1;
	int ret = 0, cnt = 0;

	int i, j, k, l; 
	for (i = 0; i <= maxCycle; i++)
	{
		bool flag1 = false;
		ret += i * i;
		for (j = 0; j <= maxCycle; j++)
		{
			bool flag2 = false;
			ret += j*j;
			for (k = 0; k <= maxCycle; k++)
			{
				bool flag3 = false;
				ret += k * k;
				for (l = 0; l <= maxCycle; l++)
				{
					ret += l*l;
					if (ret == n)
					{
						flag3 = true;
						break;
					}
					ret -= l*l;
				}
				if (flag3)
				{
					flag2 = true;
					break;
				}
				ret -= k * k;
			}
			ret -= j*j;
			if (flag2)
			{
				flag1 = true;
				break;
			}
		}
		ret -= i*i;
		if (flag1)
		{
			break;
		}
	}

	if (i > 0)
		cnt++;
	if (j > 0)
		cnt++;
	if (k > 0)
		cnt++;
	if (l > 0)
		cnt++;

	cout << cnt << "\n";
}
