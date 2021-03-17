#include<bits/stdc++.h>
#include<string>
using namespace std;


int Testcase;
string a, b;
int arrA[26];
int arrB[26];

bool isValid()
{
	if (a.size() != b.size())
		return false;
	if (a.size() == b.size())
	{
		for (int i = 0; i < 26; i++)
		{
			if (arrA[i] != arrB[i])
				return false;
		}
	}
	return true;
}

int main(void)
{
	cin >> Testcase;

	while (Testcase--)
	{
		cin >> a >> b;
		memset(arrA, 0, sizeof(arrA));
		memset(arrB, 0, sizeof(arrB));

		for (int i = 0; i < a.size(); i++)
			arrA[a[i] - 'a']++;
		for (int i = 0; i < b.size(); i++)
			arrB[b[i] - 'a']++;

		if (isValid())
			cout << "Possible" << "\n";
		else
			cout << "Impossible" << "\n";
	}
}
