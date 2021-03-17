#include<bits/stdc++.h>

using namespace std;

int arr[26];

int main(void)
{
	string tmp;
	cin >> tmp;

	for (int i = 0; i < tmp.size(); i++)
		arr[tmp[i] - 'a']++;

	for (int i = 0; i < 26; i++)
		cout << arr[i] << " ";

	return 0;
}
