#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int k;
char inSign[10];
vector<int> maxV, minV;

bool CMP(vector<int> &v)
{
	for (int i = 0; i < k; i++)
	{
		if (inSign[i] == '<' && v[i] > v[i + 1])
			return false;
		else if (inSign[i] == '>' && v[i] < v[i + 1])
			return false;
	}
	return true;
}

void print_num(vector<int> &v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i];
	cout << "\n";
}

int main(int argc, char *argv[])
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	
	cin >> k;

	for (int i = 0; i < k; i++)
		cin >> inSign[i];

	for (int i = 9; i > 9 - (k + 1); i--)
		maxV.push_back(i);
	for (int i = 0; i < k + 1; i++)
		minV.push_back(i);
	
	while (1)
	{
		if (CMP(maxV))
			break;
		prev_permutation(maxV.begin(), maxV.end());
	}

	while (1)
	{
		if (CMP(minV))
			break;
		next_permutation(minV.begin(), minV.end());
	}

	print_num(maxV);
	print_num(minV);

	return 0;
}
