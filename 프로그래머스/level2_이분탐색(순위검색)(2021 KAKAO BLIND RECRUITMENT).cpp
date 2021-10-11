#include<bits/stdc++.h>

using namespace std;
//db[i][j][k][l]: value -> i언어, j분야, k경력, l음식인 사람들의 점수 목록
vector<int> db[3][2][2][2];

vector<int> splitInfo(string s){
    string tmp;
    int num;
    vector<int> v;
    for(auto c : s){
        if(c == ' '){
            if(tmp == "cpp" || tmp == "backend" || tmp == "junior" || tmp == "chicken") num = 0;
            else if(tmp == "python") num = 2;
            else num = 1;
            tmp = "";
            v.push_back(num);
        }
        else{
            tmp += c;
        }
    }
    v.push_back(stoi(tmp));
    return v;
}

vector<string> splitQuery(string s){
    string tmp;
    int num;
    vector<string> v;

    for(auto c : s){
        if(c == ' '){
            if(tmp == "and"){
                tmp = "";
                continue;
            }
            v.push_back(tmp);
            tmp = "";
        }
        else
            tmp += c;
    }
    v.push_back(tmp);
    return v;
}

vector<int> solution(vector<string> info, vector<string> query){
    vector<int> answer;
    for(auto s : info){
        vector<int> v = splitInfo(s);
        db[v[0]][v[1]][v[2]][v[3]].push_back(v[4]);
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                for(int l = 0; l < 2; l++){
                    sort(db[i][j][k][l].begin(), db[i][j][k][l].end());
                }
            }
        }
    }

    for(auto s : query){
        vector<string> v = splitQuery(s);
        int ans = 0;
        int score = stoi(v[4]);
        int ai, bi, aj, bj, ak, bk, al, bl;

        if(v[0] == "cpp"){
            ai = bi = 0;
        }
        else if(v[0] == "java"){
            ai = bi = 1;
        }
        else if(v[0] == "python"){
            ai = bi = 2;
        }
        else
            ai = 0, bi = 2;

        if(v[1] == "backend"){
            aj = bj = 0;
        }
        else if(v[1] == "frontend"){
            aj = bj = 1;
        }
        else
            aj = 0, bj = 1;

        if(v[2] == "junior"){
            ak = bk = 0;
        }
        else if(v[2] == "senior"){
            ak = bk = 1;
        }
        else
            ak = 0, bk = 1;

        if(v[3] == "chicken"){
            al = bl = 0;
        }
        else if(v[3] == "pizza"){
            al = bl = 1;
        }
        else
            al = 0, bl = 1;

        for(int i = ai; i <= bi; i++){
            for(int j = aj; j <= bj; j++){
                for(int k = ak; k <= bk; k++){
                    for(int l = al; l <= bl; l++){
                        if(db[i][j][k][l].size() == 0)
                            continue;

                        int total = db[i][j][k][l].size();
                        auto iter = lower_bound(db[i][j][k][l].begin(), db[i][j][k][l].end(), score);
                        if(iter == db[i][j][k][l].end())
                            continue;
                        ans += total - (iter - db[i][j][k][l].begin());
                    }
                }
            }
        }
        answer.push_back(ans);
    }
    return answer;
}

int main() {
    vector<int> ret = solution({"java backend junior pizza 150", "python frontend senior chicken 210",
                                "python frontend senior chicken 150", "cpp backend senior pizza 260",
                                "java backend junior chicken 80", "python backend senior chicken 50"},
                               {"java and backend and junior and pizza 100",
                                "python and frontend and senior and chicken 200", "cpp and - and senior and pizza 250",
                                "- and backend and senior and - 150", "- and - and - and chicken 100",
                                "- and - and - and - 150"});
    for (auto cur : ret) {
        cout << cur << " ";
    }
}

//시간초과 실패
//#include<bits/stdc++.h>
//
//using namespace std;
//
//struct play {
//    vector<string> info;
//    vector<string> query;
//    vector<string> icmd[50001];
//    vector<string> qcmd[100001];
//    vector<int> ret;
//
//    play(vector<string> info, vector<string> query) : info(info), query(query), icmd{}, qcmd{}, ret{} {}
//
//    void parsing(vector<string> &a, vector<string> cmd[]) {
//        for (int i = 0; i < a.size(); i++) {
//            stringstream ss(a[i]);
//            string tmp;
//            while (getline(ss, tmp, ' ')) {
//                cmd[i].push_back(tmp);
//            }
//        }
//    }
//
//    void simulation() {
//        parsing(info, icmd);
//        parsing(query, qcmd);
//        int iSize = info.size();
//        int qSize = query.size();
//        for(int q = 0, qidx = 0; q < qSize; q++){
//            vector<string> curqcmd = qcmd[q];
//            int cnt = 0;
//            for(int i = 0; i < iSize; i++){
//                bool flag = true;
//                qidx = 0;
//                for(auto icur : icmd[i]){
//                    if(curqcmd[qidx] == "and"){
//                        qidx++;
//                    }
//
//                    if(qidx == 7){
//                        if(pointCheck(icur, curqcmd[qidx])){
//                            continue;
//                        }
//                        else{
//                            flag = false;
//                            break;
//                        }
//                    }
//
//                    if(curqcmd[qidx] == "-"){
//                        qidx++;
//                        continue;
//                    }
//                    else if(curqcmd[qidx] == icur){
//                        qidx++;
//                        continue;
//                    }
//                    else{
//                        flag = false;
//                        break;
//                    }
//                }
//                if(flag == true){
//                    cnt++;
//                }
//            }
//            ret.push_back(cnt);
//        }
//    }
//
//    bool pointCheck(string icur, string qcur){
//        int infoValue = stoi(icur);
//        int queryValue = stoi(qcur);
//        if(infoValue >= queryValue){
//            return true;
//        }
//        else
//            return false;
//    }
//
//    void print(vector<string> cmd) {
//        for (auto cur : cmd) {
//            cout << cur << " ";
//        }
//        cout << "\n";
//        cout << "===========================" << "\n";
//    }
//};
//
//vector<int> solution(vector<string> info, vector<string> query) {
//    vector<int> answer;
//    return answer;
//}
//
//int main() {
//    vector<int> ret = solution({"java backend junior pizza 150", "python frontend senior chicken 210",
//                                "python frontend senior chicken 150", "cpp backend senior pizza 260",
//                                "java backend junior chicken 80", "python backend senior chicken 50"},
//                               {"java and backend and junior and pizza 100",
//                                "python and frontend and senior and chicken 200", "cpp and - and senior and pizza 250",
//                                "- and backend and senior and - 150", "- and - and - and chicken 100",
//                                "- and - and - and - 150"});
//    for (auto cur : ret) {
//        cout << cur << " ";
//    }
//
//}