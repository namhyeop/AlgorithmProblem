//#include<bits/stdc++.h>
//
//using namespace std;
//const int MAX = 1001;
//
//char input1[MAX + 1], input2[MAX + 1];
//
//int cache[MAX][MAX];
//
//int main()
//{
//	scanf("%s %s", input1 + 1, input2 + 1);
//
//	int i, j;
//	for (i = 1; input1[i]; i++)
//	{
//		for (j = 1; input2[j]; j++)
//			cache[i][j] = max({cache[i][j - 1], cache[i - 1][j], cache[i - 1][j - 1] + (input1[i] == input2[j])});
//	}
//
//	cout << cache[i - 1][j - 1];
//}

#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;
const int MAX = 1002;

char input1[MAX];
char input2[MAX];
int cache[MAX][MAX];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	scanf("%s %s", input1 + 1, input2 + 1);

	int i= 0, j = 0;
	for (i = 1; input1[i]; i++)
	for (j = 1; input2[j]; j++)
		cache[i][j] = max({ cache[i - 1][j], cache[i][j - 1], cache[i - 1][j - 1] + (input1[i] == input2[j]) });

	cout << cache[i - 1][j - 1];
}
