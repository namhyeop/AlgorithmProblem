#include <bits/stdc++.h>

using namespace std;

int n;

struct Node{
    char left, right;
};

vector<Node> arr[26];

void pre_search(int cur){
    if(char('A' + cur) == '.'){
        return ;
    }
    cout << char('A' + cur);
    for(Node next : arr[cur]){
        pre_search(next.left - 'A');
        pre_search(next.right - 'A');
    }
}

void middle_search(int cur){
    if(char('A' + cur) == '.'){
        return ;
    }
    for(Node next : arr[cur]){
        middle_search(next.left - 'A');
        cout << char('A' + cur);
        middle_search(next.right - 'A');
    }
}

void post_search(int cur){
    if(char('A' + cur) == '.'){
        return ;
    }
    for(Node next : arr[cur]){
        post_search(next.left - 'A');
        post_search(next.right - 'A');
        cout << char('A' + cur);
    }
}
int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        char node;
        char left , right;
        cin >> node >> left >> right;
        arr[node - 'A'].push_back({left, right});
    }
    pre_search(0);
    cout <<"\n";
    middle_search(0);
    cout <<"\n";
    post_search(0);
}

////이 방법이 훨씬 더 직접적
//#include<iostream>
//
//using namespace std;
//
//char Tree[26][2];
//
//void preorder(char root)
//{
//	if (root == '.')
//		return;
//	else
//	{
//		cout << root;
//		preorder(Tree[root - 'A'][0]);
//		preorder(Tree[root - 'A'][1]);
//	}
//}
//
//void inorder(char root)
//{
//	if (root == '.')
//		return;
//
//		inorder(Tree[root - 'A'][0]);
//		cout << root;
//		inorder(Tree[root - 'A'][1]);
//}
//
//void postorder(char root)
//{
//	if (root == '.')
//		return;
//
//		postorder(Tree[root - 'A'][0]);
//		postorder(Tree[root - 'A'][1]);
//		cout << root;
//}
//
//int main(int argc, char *argv[])
//{
//	int Testcase;
//	cin >> Testcase;
//
//	char root;
//	char left;
//	char right;
//
//	for (int i = 0; i < Testcase; i++)
//	{
//		cin >> root >> left >> right;
//		Tree[root - 'A'][0] = left;
//		Tree[root - 'A'][1] = right;
//	}
//
//	preorder('A');
//	cout << '\n';
//	inorder('A');
//	cout << '\n';
//	postorder('A');
//	cout << '\n';
//
//	return 0;
//}


/*
//#include<bits/stdc++.h>
//#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
//#define pii pair<int,int>
//#define mp(X,Y) make_pair(X,Y)
//#define mt(X,Y) make_tuple(X,Y)
//#define mtt(X,Y,Z) make_tuple(X,Y,Z)
//#define ll long long
//#define sz(v) (int)(v).size()
//
//using namespace std;
//const int MAX = 26;
//int n;
////tree[i].second가 true면 왼쪽 자식 아니면 오른쪽 자식
//vector<pair<int, bool>> tree[MAX];
//
//void preorder(int node)//MLR
//{
//	cout << (char)(node + 'A');
//	for (int i = 0; i < tree[node].size(); i++)
//		preorder(tree[node][i].first);
//}
//
//void inorder(int node) // LMR
//{
//	if (tree[node].size() && tree[node][0].second) // 자식이 존재하고 왼쪽 자식이라면
//		inorder(tree[node][0].first);
//	cout << (char)(node + 'A');
//	//오른쪽 자식만 존재한다면
//	if (tree[node].size() && !tree[node][0].second)
//		inorder(tree[node][0].first);
//	//양쪽 자식이 다 존재하면
//	else if (tree[node].size() == 2)
//		inorder(tree[node][1].first);
//}
//
//void postorder(int node)
//{
//	for (int i = 0; i < tree[node].size(); i++)
//		postorder(tree[node][i].first);
//	cout << (char)(node + 'A');
//}
//
//int main(void)
//{
//	fastio;
//	cin >> n;
//	
//	for (int i = 0; i < n; i++)
//	{
//		char a, b, c;
//		cin >> a >> b >> c;
//
//		if (b != '.')
//			tree[a - 'A'].push_back({ b - 'A', true });
//		if (c != '.')
//			tree[a - 'A'].push_back({ c - 'A', false });
//	}
//
//	preorder(0);
//	cout << "\n";
//	inorder(0);
//	cout << "\n";
//	postorder(0);
//	cout << "\n";
//	return 0;
//}
*/
