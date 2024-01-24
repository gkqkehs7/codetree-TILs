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
        // 선택된 m개  0 1 3
        vector<int> combination_v = combinations_v[i];

        int max_len = 0;

        for(int p = 0; p<combination_v.size(); p++) {
            for(int k = p + 1; k < combination_v.size(); k++) {
                int x1 = v[combination_v[p]].first;
                int y1 = v[combination_v[p]].second;

                int x2 = v[combination_v[k]].first;
                int y2 = v[combination_v[k]].second;

                int len = (x2-x1) * (x2-x1) + (y2-y1) * (y2-y1);

                max_len = max(max_len, len);
            }
        }

        answer = min(answer, max_len);
    }

    cout << answer;
}