#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> combinations_v;

int visited[10] = {false, };

void combination(vector<int> combination_v) {
    if(combination_v.size() == n) {
        combinations_v.push_back(combination_v);
        return;
    }

    for(int i=0; i<n; i++) {
        if(visited[i] == false) {
            combination_v.push_back(i);
            visited[i] = true;

            combination(combination_v);

            combination_v.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n;

    vector<vector<int>> v;

    for(int i=0; i<n; i++) {
        vector<int> temp;
        for(int j=0; j<n; j++) {
            int input;
            cin >> input;
            temp.push_back(input);
        }
        v.push_back(temp);
    }

    vector<int> combination_v;
    combination(combination_v);

    int answer = 0;
    for(int i=0; i<combinations_v.size(); i++) {

        vector<int> comb = combinations_v[i];
        int min_value = 999999999;


        for(int j=0; j<n; j++) {
            min_value = min(min_value, v[j][comb[j]]);
        }

        answer = max(answer, min_value);
    }

    cout << answer;
}