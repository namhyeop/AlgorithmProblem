#include <bits/stdc++.h>

using namespace std;
const int MAX = 500 + 5;
bool visited[MAX];
vector<int> arr[MAX];
int vCnt, edgeCnt;
int n, m;

void input() {
    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= n; i++)
        arr[i].clear();

    for(int i = 0; i < m ; i++){
        int p, c;
        cin >> p >> c;
        arr[p].push_back(c);
        arr[c].push_back(p);
    }
}

void dfs(int curNode){
    vCnt++;
    edgeCnt += arr[curNode].size();
    visited[curNode] = true;
    for(int next : arr[curNode]){
        if(!visited[next]){
            dfs(next);
        }
    }
}

void pro(int t) {
    int ret = 0;
    for(int i = 1 ; i <= n; i++) {
        if(!visited[i]) {
            vCnt = 0, edgeCnt = 0;
            dfs(i);
            if(vCnt -1 == edgeCnt / 2){
                ret++;
            }
        }
    }

    if(ret == 0){
        cout << "Case " << t << ": No trees." <<"\n";
    }else if(ret == 1){
        cout << "Case " << t << ": There is one tree." <<"\n";
    }else{
        cout << "Case " << t << ": A forest of " << ret << " trees." <<"\n";
    }
}

int main(){
    int t = 1;
    while(1){
        cin >> n >> m;
        if(n == 0 && m == 0){
            break;
        }
        input();
        pro(t);
        t++;
    }
}

//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int cutNode;
//int ret = 0;
//
//void cutting_leaf(int nowNode, vector<vector<int>> &Tree)
//{
//	if (cutNode == nowNode)
//		return;
//	int childSize = Tree[nowNode].size();
//	switch (childSize)
//	{
//	case 0:
//		ret++;
//		break;
//	case 1:
//		if (Tree[nowNode][0] == cutNode)
//		{
//			ret++;
//			break;
//		}
//	default:
//		for (int i = 0; i < childSize; i++)
//			cutting_leaf(Tree[nowNode][i],Tree);
//		break;
//	}
//}
//
//int main(int argc, char *argv[])
//{
//	int inputN;
//	int root;
//	cin >> inputN;
//
//	vector<vector<int>> Tree(inputN);
//
//	for (int child = 0; child < inputN; child++)
//	{
//		int parent;
//		cin >> parent;
//		if (parent != -1)
//			Tree[parent].push_back(child);
//		else
//			root = child;
//	}
//
//	cin >> cutNode;
//
//	cutting_leaf(root, Tree);
//
//	cout << ret << "\n";
//}
