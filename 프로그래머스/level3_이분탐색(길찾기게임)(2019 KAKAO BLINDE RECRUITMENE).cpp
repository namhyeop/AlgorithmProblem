#include<bits/stdc++.h>

using namespace std;

struct Tree{
    int idx;
    int x, y;
    Tree *left, *right;
};

bool cmp(Tree a , Tree b){
    if(a.y != b.y){
        return a.y > b.y;
    }
    else if(a.x != b.x){
        return a.x < b.x;
    }
    return false;
}

vector<Tree> tree;

void preOrder(const Tree *root, vector<int> &sol){
    if(root == NULL)
        return ;
    sol.push_back(root->idx);
    preOrder(root->left, sol);
    preOrder(root->right, sol);

}

void postOrder(const Tree *root, vector<int> &sol){
    if(root == NULL)
        return ;
    postOrder(root->left, sol);
    postOrder(root->right, sol);
    sol.push_back(root->idx);
}

void makeTree(Tree *Root, Tree *cur){
    if(Root->x > cur->x){
        if(Root->left == NULL){
         Root->left = cur;
         return;
        }
        makeTree(Root->left, cur);
    }
    else{
        if(Root->right == NULL){
            Root ->right = cur;
            return;
        }
        makeTree(Root->right, cur);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeInfo) {
    vector<vector<int>> answer;
    for(int i = 0; i < nodeInfo.size(); i++){
        int x = nodeInfo[i][0];
        int y = nodeInfo[i][1];
        tree.push_back({i + 1, x, y, NULL, NULL});
    }
    sort(tree.begin(), tree.end(), cmp);
    Tree *root = &tree[0];
    for(int i = 1; i < tree.size(); i++){
        makeTree(root, &tree[i]);
    }
    vector<int> preArr, postArr;
    preOrder(root, preArr);
    postOrder(root, postArr);
    answer.push_back(preArr), answer.push_back(postArr);
    return answer;
}

int main(){
    vector<vector<int>> ret = solution({{5,3}, {11,5}, {13,3}, {3,5}, {6,1}, {1,3}, {8,6}, {7,2}, {2,2}});
    for(auto v : ret){
        for(int n : v){
            cout<< n <<" ";
        }
        cout <<"\n";
    }
}
