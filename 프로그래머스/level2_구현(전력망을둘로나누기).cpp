#include<bits/stdc++.h>

#define ll long long
using namespace std;
const int MAX = 101;

int visited[MAX];
vector<int> Tree[MAX];
int firstCase, secondCase;

/**
 * 탐색을 진행하면서 그룹에 맞게 count 증가를 진행해준다.
 */
void DFS(int cur, int &count){

    /**
     * 탐색 개수가 0인 경우는 1개를 의미하므로 예외처리
     */
    if(Tree[cur].size() == 0){
        count == 0 ? firstCase++ : secondCase++;
    }

    for(int i = 0; i < Tree[cur].size(); i++){
        int next = Tree[cur][i];
        if(!visited[next]){
            visited[next] = true;
            count == 0 ? firstCase++ : secondCase++;
            DFS(next, count);
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INT_MAX;
    /**
     * 트리 양방향 간선 채워주는 과정
     */
    for(int i = 0; i < wires.size(); i++){
        Tree[wires[i][0]].push_back(wires[i][1]);
        Tree[wires[i][1]].push_back(wires[i][0]);
    }

    for(int i = 0; i < wires.size(); i++) {
        int target = wires[i][0];
        int eraseTarget = wires[i][1];

        /**
         * 지울 대상 설정
         */
        int pos1 = find(Tree[target].begin(), Tree[target].end(), eraseTarget) - Tree[target].begin();
        int pos2 = find(Tree[eraseTarget].begin(), Tree[eraseTarget].end(), target) - Tree[eraseTarget].begin();

        /**
        * 지울 대상 지우기
        */
        Tree[target].erase(Tree[target].begin() + pos1);
        Tree[eraseTarget].erase(Tree[eraseTarget].begin() + pos2);

        memset(visited, false, sizeof(visited));
        int count = 0;
        bool notTwoFlag = true;
        firstCase = 0, secondCase = 0;

        for (int i = 0; i < n; i++) {
            /**
             * 두 그룹이상일 경우 탐색 중지
             */
            if(count > 2){
                notTwoFlag = false;
                break;
            }
            if (!visited[i + 1]) {
                DFS(i + 1, count);
                count++;
            }
        }


        if(notTwoFlag){
            answer = min(answer, abs(firstCase - secondCase));
        }
        /**
        * 지운 대상 복구
        */
        Tree[target].insert(Tree[target].begin() + pos1, eraseTarget);
        Tree[eraseTarget].insert(Tree[eraseTarget].begin() + pos2, target);
    }

    return answer;
}

int main() {
    int ret1 = solution(9, {{1,3},{2,3},{3,4},{4,5},{4,6},{4,7},{7,8},{7,9}});
    cout << ret1 <<"\n";
}