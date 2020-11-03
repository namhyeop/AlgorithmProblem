#include<iostream>
#include<vector>

using namespace std;

int cutNode;
int ret = 0;

void cutting_leaf(int nowNode, vector<vector<int>> &Tree)
{
	if (cutNode == nowNode)
		return;
	int childSize = Tree[nowNode].size();
	switch (childSize)
	{
	case 0:
		ret++;
		break;
	case 1:
		if (Tree[nowNode][0] == cutNode)
		{
			ret++;
			break;
		}
	default:
		for (int i = 0; i < childSize; i++)
			cutting_leaf(Tree[nowNode][i],Tree);
		break;
	}
}

int main(int argc, char *argv[])
{
	int inputN;
	int root;
	cin >> inputN;

	vector<vector<int>> Tree(inputN);

	for (int child = 0; child < inputN; child++)
	{
		int parent;
		cin >> parent;
		if (parent != -1)
			Tree[parent].push_back(child);
		else
			root = child;
	}

	cin >> cutNode;

	cutting_leaf(root, Tree);

	cout << ret << "\n";
}
