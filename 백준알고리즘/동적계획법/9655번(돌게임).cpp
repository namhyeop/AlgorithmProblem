#include<bits/stdc++.h>

using namespace std;
const int MAX = 1001;
int cache[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	cache[1] = 1;
	cache[2] = 0;
	for (int i = 3; i <= n; i++)
	{
		if (i % 2 == 1)
			cache[i] = 1;
		else if(i%2 == 0)
			cache[i] = 0;
	}

	if (cache[n] == 1)
		cout << "SK"<< "\n";
	else if (cache[n] == 0)
		cout << "CY" << "\n";
	
	

	return 0;
}
