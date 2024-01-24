#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
vector<vector<int>> combinations_v;
int visited[20];

void combination(vector<int> combination_v) {

    if(combination_v.size() == m) {
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
    cin >> n >> m;

    vector<pair<int, int>> v;

    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;

        v.push_back(make_pair(x, y));
    }

    vector<int> comb;
    combination(comb);

    int answer = 999999999;

    for(int i=0; i<combinations_v.size(); i++) {


        int max_len = 0;

        for(int p = 0; p<combinations_v[i].size(); p++) {
            for(int k = p + 1; k < combinations_v[i].size(); k++) {
                int x1 = v[combinations_v[i][p]].first;
                int y1 = v[combinations_v[i][p]].second;

                int x2 = v[combinations_v[i][k]].first;
                int y2 = v[combinations_v[i][k]].second;

                int len = (x2-x1) * (x2-x1) + (y2-y1) * (y2-y1);

                max_len = max(max_len, len);
            }
        }

        answer = min(answer, max_len);
    }

    cout << answer;
}