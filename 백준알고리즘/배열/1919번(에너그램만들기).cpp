#include <bits/stdc++.h>

using namespace std;

int arrA[26];
int arrB[26];

int main()
{
	string a, b;
	cin >> a >> b;
	int ret = 0;
	if (a.size() < b.size())
		swap(a, b);
	for (int i = 0; i < a.size(); i++)
		arrA[a[i] - 'a']++;
	for (int i = 0; i < b.size(); i++)
		arrB[b[i] - 'a']++;

	for (int i = 0; i < 26; i++)
	if (arrA[i] != arrB[i])
		ret += abs(arrA[i] - arrB[i]);
	
	cout << ret << "\n";
	
	return 0;
}
