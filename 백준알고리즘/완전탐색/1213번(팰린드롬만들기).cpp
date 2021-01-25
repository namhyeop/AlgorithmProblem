#include<iostream>
#include<vector>
#include<string>

using namespace std;

int alpha[26];

int main(int argc, char *argv[])
{
	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++)
		alpha[s[i] - 'A']++;

	vector<pair<char, int>> v;
	vector<char> middle;
	bool flag = false;

	for (int i = 0; i < 26; i++)
	{
		if (alpha[i] % 2 && flag)
		{
			cout << "I'm Sorry Hansoo\n";
			return 0;
		}
		else if (alpha[i] % 2 && !flag)
		{
			v.push_back({ i + 'A', alpha[i] - 1 });
			middle.push_back(i + 'A');
			flag = true;
		}
		else
			v.push_back({ i + 'A', alpha[i] });
	}

	string result;

	for (int i = 0; i < v.size(); i++)
	for (int j = 0; j < (v[i].second / 2); j++)
		result += v[i].first;

	for (int i = 0; i < result.size(); i++)
		cout << result[i];
	if (middle.size())
		cout << middle[0];
	for (int i = result.size() - 1; i >= 0; i--)
		cout << result[i];
	
	cout << "\n";

	return 0;
}
