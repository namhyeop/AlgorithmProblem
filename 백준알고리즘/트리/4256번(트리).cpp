#include<iostream>
#include<vector>
using namespace std;

int nodeNum;
int preorder[1001];
int inorder[1001];

void printPostOrder(int l, int r, int root)
{

	if (l > r)
		return;

	int bridge = inorder[preorder[root]];

	printPostOrder(l, bridge -1, root + 1);
	printPostOrder(bridge +1, r, root+bridge-l+1);
	cout << preorder[root] <<' ';

}

int main(int argc, char * argv[])
{
	int Testcase;

	cin >> Testcase;

	for (int i = 0; i < Testcase; i++)
	{
		cin >> nodeNum;

		for (int i = 0; i < nodeNum; i++)
		{
			int tmp;
			cin >> preorder[i];
		}

		for (int i = 0; i < nodeNum; i++)
		{
			int tmp;
			cin >> tmp;
			inorder[tmp] = i;
		}

		printPostOrder(0, nodeNum-1, 0);
		cout << '\n';
	}
}
