#include<bits/stdc++.h>

using namespace std;

int testcase;
vector<int> v; 
int main()
{
	cin >> testcase;

	for (int i = 0; i < testcase; i++)
	{
		long long n;
		cin >> n;
		long long tmpn = n;
		
		while (1)
		{
			v.clear();
			tmpn = n;
			while (1)
			{
				if (tmpn > 10)
				{
					v.push_back(tmpn % 10);
					tmpn = tmpn / 10;
				}
				else
				{
					v.push_back(tmpn);
					break;
				}
			}

			int sum = 0;
			for (int i = 0; i < v.size(); i++)
				sum += v[i];

			int ret = 0;
			bool flag = true;
			
			for (int i = 2; i <= sum; i++)
			{
				if (n % i == 0 && sum % i == 0)
				{
					cout << n << "\n";
					flag = false;
					break;
				}
			}

			if (flag == false)
			{
				break;
			}
			n++;
		}
	}
	return 0;
}
