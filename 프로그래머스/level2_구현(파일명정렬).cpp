#include<bits/stdc++.h>

using namespace std;

struct info{
    string head;
    int number;
    int idx;
};

vector<info> infoList;

int find_Num(int start, string str){
    int ret = start;
    for(int i = start + 1; i < str.size(); i++){
        if('0' <= str[i] && str[i] <= '9'){
            return i;
        }
    }
    return ret;
}

int find_fe(int start, string str) {
    for (int i = start; i < start + 5; i++) {
        if ('0' <= str[i] && str[i] <= '9') {
            continue;
        }
        else{
            return i;
        }
    }
}

string upper_head(string head){
    string ret = "";
    for (const auto &item: head) {
        if(!('A' <= item && item <='Z'))
            ret += toupper(item);
        else
            ret += item;
    }
    return ret;
}

bool cmp(info a, info b){
    if(a.head != b.head)
        return a.head < b.head;
    if(a.number != b.number)
        return a.number < b.number;
    if(a.idx != b.idx)
        return a.idx < b.idx;
    return false;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;

    int idx = 0;
    for (auto item: files) {
        int fs = find_Num(0,item);
        int fe = find_fe(fs, item);
        string head = item.substr(0, fs);
        string parseHead = upper_head(head);
        int number = stoi(item.substr(fs ,fe - fs + 1));
        infoList.push_back({parseHead, number, idx});
        idx++;
    }

    sort(infoList.begin(), infoList.end(), cmp);

    for (auto item: infoList) {
        answer.push_back(files[item.idx]);
    }
    return answer;
}

int main(){
    vector test1 = solution({"img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"});
    cout << toupper('-') <<"\n";
//    int test1= stoi("0011");
//    cout << test1 <<"\n";
}