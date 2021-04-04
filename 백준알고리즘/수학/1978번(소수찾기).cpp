#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)

using namespace std;

int n;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		if (num == 1)
			continue;

		bool flag = false;
		for (int i = 2; i < num; i++)
		if (num % i == 0)
		{
			flag = true;
			break;
		}
		if (flag == true)
			continue;
	
		sum++;
	}

	cout << sum << "\n";
	
	return 0;
}
