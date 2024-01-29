#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
int n;

vector<vector<int>> combinations;

void combination(vector<int> v) {
    if(v.size() == 2) {
        combinations.push_back(v);
        return;
    }

    for(int i=0; i<n; i++) {
        v.push_back(i);
        combination(v);
        v.pop_back();
    }
}

int main() {
    cin >> n;

    vector<vector<int>> v;

    for(int i=0; i<4; i++) {
        vector<int> temp;
        for(int j=0; j<n; j++) {
            int input;
            cin >> input;
            temp.push_back(input);
        }

        v.push_back(temp);

    }

    unordered_map<int, int> hash;

    vector<int> temp;
    combination(temp);
    for(int i=0; i<combinations.size(); i++) {
        int a = v[0][combinations[i][0]];
        int b = v[1][combinations[i][1]];

        hash.insert(make_pair(a + b, 0));
    }

    int answer = 0;

    for(int i=0; i<combinations.size(); i++) {
        int c = v[2][combinations[i][0]];
        int d = v[3][combinations[i][1]];

        if(hash.find(-c -d) != hash.end()) {
            hash.find(-c -d)->second += 1;
        }
    }

    for(auto elem : hash) {
        answer += elem.second;
    }

    cout << answer;
}