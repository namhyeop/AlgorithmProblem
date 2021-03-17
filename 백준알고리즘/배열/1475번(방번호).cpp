#include<bits/stdc++.h>

using namespace std;

int arr[10];
int main(void)
{
	int set = 1;
	string n;
	cin >> n;

	for (int i = 0; i < 10; i++)
		arr[i] = 1;

	for (int i = 0; i < n.size(); i++)
	{
		if (arr[n[i] - '0'] > 0)
		{
			arr[n[i] - '0']--;
		}
		else if (n[i] == '6' || n[i] == '9')
		{
			if (n[i] == '6')
			{
				if (arr[9] > 0)
				{
					arr[9]--;
				}
				else
				{
					for (int i = 0; i < 10; i++)
						arr[i]++;
					arr[6]--;
					set++;
				}
			}
			else if (n[i] == '9')
			{
				if (arr[6] > 0)
				{
					arr[6]--;
				}
				else
				{
					for (int i = 0; i < 10; i++)
						arr[i]++;
					arr[9]--;
					set++;
				}
			}
		}
		else
		{
			for (int i = 0; i < 10; i++)
				arr[i]++;
			arr[n[i] - '0']--;
			set++;
		}
	}

	cout << set << "\n";

	return 0;
}
