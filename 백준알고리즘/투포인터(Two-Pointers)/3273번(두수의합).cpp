#include<bits/stdc++.h>

using namespace std;

int n;
int m;
vector<int> v;
int ret = 0;

int main()
{
	cin >> n;
	v.resize(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	cin >> m;
	sort(v.begin(), v.end());

	int left = 0;
	int right = n - 1;

	while (1)
	{
		if (left >= right)
			break;
		if (v[left] + v[right] == m)
		{
			left++;
			right--;
			ret++;
		}
		else if (v[left] + v[right] > m)
			right--;
		else
			left++;
	}

	cout << ret << "\n";
	
	return 0;
}
