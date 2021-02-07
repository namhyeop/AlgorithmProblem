#include<bits/stdc++.h>
#define MAX 51
using namespace std;

string input;
int inputLength;
int maxValue;
bool visited[MAX];
vector<int> v;
void split_input(int level)
{
	if (level == inputLength)
	{
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << "\n";
		exit(0);
	}
	
	string tmp = "";
	int tmpChangeint = 0;
	for (int i = level; i <= level + 1; i++)
	{
		tmp += input[i];
		tmpChangeint = stoi(tmp);
		
		if (tmpChangeint > maxValue)
			continue;
		if (!visited[tmpChangeint])
		{
			v.push_back(tmpChangeint);
			visited[tmpChangeint] = true;
			split_input(i + 1);
			visited[tmpChangeint] = false;
			v.pop_back();
		}
	}
}
int main(int argc, char*argv[])
{
	cin >> input;
	inputLength = input.size();
	if (inputLength < 10)
		maxValue = inputLength;
	else
		maxValue = (inputLength - 9) / 2 + 9; //11개의 길이가 있으면 1~9까지 그리고 2개의 숫자가 합쳐진 순열이 나와야 길이가 맞다

	split_input(0);

	return 0;
}
