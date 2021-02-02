#include<bits/stdc++.h>

using namespace std;

long long input;
int idx;

void um_moo(int n)
{
	if (n == 1)
	{
		if (idx + 1 == input)
		{
			cout << "m" << "\n";
			exit(0);
		}
		else if (idx + 2 == input || idx + 3 == input)
		{
			cout << "o" << "\n";
			exit(0);
		}
		idx += 3;
		return;
	}

	um_moo(n - 1);
	if (idx + 1 == input)
	{
		cout << "m" << "\n";
		exit(0);
	}
	idx++;
	for (int i = 0; i < n + 1 ; i++)
	{
		idx++;
		if (idx == input)
		{
			cout << "o" << "\n";
			exit(0);
		}
	}
	um_moo(n - 1);
}
int main(int argc, char*argv[])
{
	cin >> input;
	um_moo(30);
}
/*메모리 초과
void make_flow(string flow, int idx)
{
	if (idx == 30)
	{
		cout << flow[2*n-2] << "\n";
		return;
	}

	string closeflow = flow;
	string tmpflow = flow;
	tmpflow += " o";

	flow +=" " + tmpflow + " " + closeflow;
	make_flow(flow, idx + 1);
}
int main(int argc, char *argv[])
{
	string flow= "m o o";
	cin >> n;
	int idx = 0;
	make_flow(flow, idx);
	
	return 0;
}
*/
