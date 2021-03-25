#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	string input;
	cin.ignore();
	getline(cin, input);
	string tmp;
	stringstream stream;
	vector<int> v;
	stream.str(input);

	long long ret = 0;
	while (stream >> tmp)
	{
		if (v.size() == 2)
		{
			int tmp1 = v.back();
			v.pop_back();
			int tmp2 = v.back();
			v.pop_back();
			ret += tmp1 * tmp2;
			v.push_back(tmp1 + tmp2);
		}

		v.push_back(stoi(tmp));		
	}
	if (v.size() == 2)
	{
		ret += v[0] * v[1];
		v.push_back(v[0] + v[1]);
	}

	cout << ret << '\n';
	return 0;
}
