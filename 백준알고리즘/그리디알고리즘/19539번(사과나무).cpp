#include<bits/stdc++.h>
using namespace std;

int n, k,sum,divisum;

int main()
{
	cin >> n;

	sum = divisum = 0;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		divisum += num / 2,sum += num;
	}

	sum % 3 == 0 ? sum/3 <= divisum ? cout <<"YES" <<"\n" : cout <<"NO"<<"\n" : cout << "NO" << "\n";

}
