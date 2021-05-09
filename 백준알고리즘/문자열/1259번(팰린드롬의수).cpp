#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string num ="";

	while (1)
	{
		cin >> num;

		if (num == "0")
			break;
		string orientedStr = num;
		reverse(num.begin(), num.end());

		if (num == orientedStr)
			cout << "yes" << "\n";
		else
			cout << "no" << "\n";
	}
}
