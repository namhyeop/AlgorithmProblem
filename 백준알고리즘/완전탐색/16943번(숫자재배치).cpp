#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<climits>
using namespace std;

int main(int argc, char *argv[])
{
	string s;
	int b;
	int maxValue = -1;
	cin >> s >> b;

	sort(s.begin(), s.end());
	
	do
	{
		if (s[0] == '0' || stoi(s) >= b)
			continue;
		maxValue = max(maxValue, stoi(s));
	} while (next_permutation(s.begin(), s.end()));

	cout << maxValue << "\n";

	return 0;
}
