#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

void input() {
    int input;
    arr.push_back(0);
    while (cin >> input) {
        arr.push_back(input);
    }
}

void divide(int l, int r){
    if(l > r){
        return ;
    }
    int mid = r;
    for(int i = l + 1; i <= r; i++){
        if(arr[i] > arr[l]){
            mid = i - 1;
            break;
        }
    }
    divide(l + 1, mid);
    divide(mid +1 , r);
    cout << arr[l] << "\n";
}

void pro(){
    int size = arr.size();
    divide(1, size);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    pro();
}


//#include<bits/stdc++.h>
//#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
//#define pill pair<int,int>
//#define mp(X,Y) make_pair(X,Y)
//#define ll long long
//#define sz(v) (int)(v).size()
//
//using namespace std;
//
//struct Node
//{
//	int data;
//	Node *left;
//	Node *right;
//};
//
//Node *root = NULL;
//
//Node *insert(Node *node, int data)
//{
//	if (node == NULL)
//	{
//		node = new Node();
//		node->data = data;
//		node->left = NULL;
//		node->right = NULL;
//	}
//	else if (data <= node->data)
//	{
//		node->left = insert(node->left, data);
//	}
//	else
//		node->right = insert(node->right, data);
//	return node;
//}
//
//void postOrder(Node *node)
//{
//	if (node->left != NULL)
//		postOrder(node->left);
//	if (node->right != NULL)
//		postOrder(node->right);
//	cout << node->data << "\n";
//}
//
//int main(void)
//{
//	fastio;
//	int num;
//	while (scanf("%d", &num) != EOF)
//	{
//		if (num == EOF)
//			break;
//		root = insert(root, num);
//	}
//	postOrder(root);
//	return 0;
//}
