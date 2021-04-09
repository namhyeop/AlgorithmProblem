#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;
const int MAX = 1001;
char input1[MAX + 1];
char input2[MAX + 1];
int cache[MAX][MAX];

void print_sentance(int i, int j)
{
	if (cache[i][j] == 0)
		return;

	if (input1[i] == input2[j])
	{
		print_sentance(i - 1, j - 1);
		cout << input1[i];
	}
	else
		cache[i - 1][j] > cache[i][j - 1] ? print_sentance(i - 1, j) : print_sentance(i, j - 1);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	scanf("%s %s", input1 + 1, input2 + 1);

	int i, j;
	for (i = 1; input1[i]; i++)
	for (j = 1; input2[j]; j++)
		cache[i][j] = max({ cache[i][j - 1], cache[i - 1][j], cache[i - 1][j - 1] + (input1[i] == input2[j]) });

	cout << cache[i - 1][j - 1] << "\n";
	print_sentance(i - 1, j - 1);

	return 0;
}
