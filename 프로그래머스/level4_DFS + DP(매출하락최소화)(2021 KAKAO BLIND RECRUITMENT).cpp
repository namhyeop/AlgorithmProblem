#include<bits/stdc++.h>

using namespace std;

#define MAX 30001

struct Tree{
    /**
     * DP + Tree 문제
     * DP[A][0] = B A번 사람이 워크숍에 참석을 안할 때, 워크숍에 참석하는 직원들의 매출액의 최소값 B원
     * DP[A][1] = B A번 사람이 워크숍에 참석을 할 때, 워크숍에 참석하는 직원들의 매출액이 최소값인 B원
     */

    int DP[MAX][2];
    vector<int> tree[MAX];
    vector<int> sales;
    vector<vector<int>> links;
    Tree(vector<int> sales, vector<vector<int>> links) : sales{sales}, links{links}, DP(), tree() {}

    void makeTree(){
        for(int i = 0; i < links.size(); i++){
            int parent = links[i][0];
            int child  = links[i][1];
            tree[parent].push_back(child);
        }
    }

    void DFS(int cur){
        //리프노드일 경우 확인해주는 flag 변수
        bool leafNode = true;
        //각 트리의 노드의 자식들을 탐색하며 맨 밑 리프노트로 향해가는 과정
        for(int i = 0; i < tree[cur].size(); i++){
            int next = tree[cur][i];
            leafNode = false;
            DFS(next);
        }

        //리프노드일 경우 현재노드가 참석한다면 그것은 현재 노드의 판매값이고 참석 안할경우는 0이다.
        if(leafNode == true){
            DP[cur][1] = sales[cur - 1];
            DP[cur][0] = 0;
            return;
        }

        //리프노드가 아니라 해당노드가 워크셥에 참석하는지 참석안하는지를 구분해야 하는 경우
        int sum = 0;
        int minCost = 987654321;
        //참석을 하는게 좀 더 효율적인 경우를 나타내는 flag
        bool notMoreEfiicient = false;
        for(int i = 0; i < tree[cur].size(); i++){
            int child = tree[cur][i];
            //자식들에서 참석을 하는 경우와 참석을 안하는 경우를 구분하며 더한 최소값.
            sum += min(DP[child][0], DP[child][1]);
            //참석을 하는 경우가 좀 더효율적이라면 밑에서 참석 안 한경우의 값을 여태까지의 참석을 한 최소의 합계값으로 변경해준다.
            if(DP[child][0] > DP[child][1])
                notMoreEfiicient = true;
            //모든 팀원이 참석을 안해서 누군가를 한 명 보내야 하는 경우. 그 경우는 워크숍에 참석 하는 경우와 참석 안하는 경우의 차이가 최소 값인 경우이다.
            minCost = min(minCost, DP[child][1] - DP[child][0]);
        }
        //참석을 하는 경우
        DP[cur][1] = sales[cur - 1] + sum;
        //참석을 하는 경우가 좀 더효율적인 경우 참석을 안하는 경우에다가 값을 갱신한다.
        if(notMoreEfiicient){
            DP[cur][0] = sum;
        }
        //모든 팀원이 참석을 안해서 누군가를 한 명 보내야 하는 경우
        else
            DP[cur][0] = sum + minCost;
    }
};

int solution(vector<int> sales, vector<vector<int>> links){
    int answer = 0;
    Tree pilot(sales, links);
    pilot.makeTree();
    pilot.DFS(1);
    answer = min(pilot.DP[1][0], pilot.DP[1][1]);
    return answer;
}

int main(){
    vector<int> tmp1 = {14, 17, 15, 18, 19, 14, 13, 16, 28, 17};
    vector<vector<int>> tmp2 = {{10, 8}, {1, 9}, {9, 7}, {5, 4}, {1, 5}, {5, 10}, {10, 6}, {1, 3}, {10, 2}};
    cout << solution(tmp1, tmp2) <<"\n";
}