#include<bits/stdc++.h>

using namespace std;

int main()
{
	vector<string> v;
	string n;
	cin >> n;

	for (int i = 0; i < n.size(); i++)
	{
		string tmp;
		for (int j = i; j < n.size(); j++)
		{
			tmp += n[j];
		}
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";

	return 0;
}
