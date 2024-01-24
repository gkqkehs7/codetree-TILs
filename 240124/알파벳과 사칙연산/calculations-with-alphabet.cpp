#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<int>> combinations_v;

void combination(vector<int> combination_v) {

    if(combination_v.size() == 6) {
        combinations_v.push_back(combination_v);
        return;
    }

    for(int i=1; i<=4; i++) {
        combination_v.push_back(i);
        combination(combination_v);
        combination_v.pop_back();
    }
}

int calculate(int prev_num, int now_num, string cal) {
    if(cal == "+") {
        return prev_num + now_num;
    } else if(cal == "-") {
        return prev_num - now_num;
    } else if(cal == "*") {
        return prev_num * now_num;
    }
}

int main() {
    string s;
    cin >> s;

    // 조합 미리 구해놓기
    vector<int> combination_v;
    combination(combination_v);

    int answer = -2147483648;

    for(int i=0; i<combinations_v.size(); i++) {

        int prev = 0;
        string prev_cal = "+";

        vector<int> combination_v = combinations_v[i];

        for(int j=0; j<s.length(); j++) {
            if(s[j] == 'a') {
                prev = calculate(prev, combination_v[0],prev_cal);
            } else if(s[j] == 'b') {
                prev = calculate(prev, combination_v[1],prev_cal);
            } else if(s[j] == 'c') {
                prev = calculate(prev, combination_v[2],prev_cal);
            } else if(s[j] == 'd') {
                prev = calculate(prev, combination_v[3],prev_cal);
            } else if(s[j] == 'e') {
                prev = calculate(prev, combination_v[4],prev_cal);
            } else if(s[j] == 'f') {
                prev = calculate(prev, combination_v[5],prev_cal);
            } else {
                prev_cal = s[j];
            }

        }

        answer = max(answer, prev);
    }

    cout << answer;

}