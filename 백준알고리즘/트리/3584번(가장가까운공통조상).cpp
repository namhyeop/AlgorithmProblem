#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e4 + 1;
int TestNum, N;
int parent[MAX];
bool visited[MAX];

void input(){
    cin >> N;
    memset(visited, false, sizeof(visited));
    fill(parent, parent + MAX -1, 0);
    for(int i = 0; i < N - 1; i++){
        int p, c;
        cin >>p >> c;
        parent[c] = p;
    }
}

void pro(){
    int targetA, targetB;
    cin >> targetA >> targetB;

    while(targetA){
        visited[targetA] = true;
        targetA = parent[targetA];
    }

    while(targetB && !visited[targetB]){
        targetB = parent[targetB];
    }
    cout << targetB << "\n";
}

int main(){
    cin >> TestNum;
    for(int checkFlag = 0; checkFlag < TestNum; checkFlag++){
        input();
        pro();
    }
}

//#include<bits/stdc++.h>
//#define MAX 10001 //LCA알고리즘
//using namespace std;
//
//int depth[MAX];
//int ac[MAX][20];
//int parent[MAX];
//int maxLevel;
//vector<int> board[MAX];
//
//void make_tree(int here, int parent)
//{
//	depth[here] = depth[parent] + 1;
//	ac[here][0] = parent;
//	maxLevel = (int)floor(log2(MAX));
//
//	for (int i = 1; i <= maxLevel; i++)
//	{
//		int tmp = ac[here][i - 1];
//		ac[here][i] = ac[tmp][i - 1];
//	}
//
//	int len = board[here].size();
//	for (int i = 0; i < len; i++)
//	{
//		int there = board[here][i];
//		if (there != parent)
//			make_tree(there, here);
//	}
//}
//
//int main()
//{
//	int Testcase;
//	int n;
//
//	cin >> Testcase;
//	while (Testcase--)
//	{
//		memset(depth, 0, sizeof(depth));
//		memset(ac, 0, sizeof(ac));
//		memset(parent, 0, sizeof(parent));
//		for (int i = 0; i < MAX; i++)
//			board[i].clear();
//
//		cin >> n;
//
//		for (int i = 1; i < n; i++)
//		{
//			int node1, node2;
//			cin >> node1 >> node2;
//			board[node1].push_back(node2);
//			board[node2].push_back(node1);
//			parent[node2] = node1;
//		}
//
//		int root;
//		for (int i = 1; i <= n; i++)
//		{
//			if (parent[i] == 0)
//			{
//				root = i;
//				break;
//			}
//		}
//
//		depth[0] = -1;
//
//		make_tree(root, 0);
//
//		int a, b;
//		cin >> a >> b;
//
//		if (depth[a] != depth[b])
//		{
//			if (depth[a] > depth[b])
//				swap(a, b);
//
//			for (int i = maxLevel; i >= 0; i--)
//			{
//				if (depth[a] <= depth[ac[b][i]])
//					b = ac[b][i];
//			}
//		}
//
//		int lca = a;
//
//		if (a != b)
//		{
//			for (int i = maxLevel; i >= 0; i--)
//			{
//				if (ac[a][i] != ac[b][i])
//				{
//					a = ac[a][i];
//					b = ac[b][i];
//				}
//				lca = ac[a][i];
//			}
//		}
//		cout << lca << "\n";
//	}
//	return 0;
//}
