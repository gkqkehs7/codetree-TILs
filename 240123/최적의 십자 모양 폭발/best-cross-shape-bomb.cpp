#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<vector<int>> explode(vector<vector<int>> v, int x, int y) {
    int range = v[x][y];

    // 오른쪽 폭발
    for(int i=0; i<range; i++) {
        if(y + i == v.size()) break;
        v[x][y + i] = 0;
    }

    // 왼쪽 폭발
    for(int i=0; i<range; i++) {
        if(y - i == -1) break;
        v[x][y - i] = 0;
    }

    // 위 폭발
    for(int i=0; i<range; i++) {
        if(x - i == -1) break;
        v[x - i][y] = 0;
    }

    // 아래 폭발
    for(int i=0; i<range; i++) {
        if(x + i == v.size()) break;
        v[x + i][y] = 0;
    }

    return v;
};

vector<vector<int>> sink(vector<vector<int>> v, int x, int y, int range) {
    for(int j=0; j<v.size(); j++) {
        for(int i=v.size() - 1; i > 0; i--) {
            if(j != y) {
                if(v[i][j] == 0) {
                    v[i][j] = v[i-1][j];
                    v[i-1][j] = 0;
                }
            }
        }
    }

    stack<int> s;

    for(int i=0; i<v.size(); i++) {
        if(v[i][y] != 0) {
            s.push(v[i][y]);
        }
        v[i][y] = 0;
    }

    for(int i = v.size() - 1; i >= 0; i--) {
        if(!s.empty()) {
            v[i][y] = s.top();
            s.pop();
        } else {
            v[i][y] = 0;
        }
    }

    return v;
}

int get_pair(vector<vector<int>> v) {
    int pair_num = 0;
    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<v.size(); j++) {
            int now = v[i][j];

            if(now != 0) {
                if(j + 1 < v.size() && v[i][j + 1] == now) {
                    pair_num++;
                }

                if(i + 1 < v.size() && v[i + 1][j] == now) {
                    pair_num++;
                }
            }
        }
    }

    return pair_num;
}

int main() {
   int n;
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

   int answer = 0;

   for(int i=0; i<n; i++) {
       for(int j=0; j<n; j++) {

           // vector 복사
           vector<vector<int>> copy_v;
           for(int k=0; k<n; k++) {
               vector<int> temp;
               for(int p=0; p<n; p++) {
                   temp.push_back(v[k][p]);
               }
               copy_v.push_back(temp);
           }

           // 폭빌
           vector<vector<int>> exploded_v = explode(copy_v, i, j);

           // 가라앉기
           vector<vector<int>> sinked_v = sink(exploded_v, i, j, v[i][j]);

           int pair_num = get_pair(sinked_v);

            answer = max(answer, pair_num);
       }
   }

   cout << answer;
}