#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 999999999;

void back_tracking(vector<int> v, int now, int depth) {
    if(now >= v.size()) {
        return;
    }

    if(now == v.size() - 1) {
        answer = min(answer, depth);
    }

    for(int i=1; i<=v[now]; i++) {
        back_tracking(v, now + i, depth + 1);
    }

}

int main() {
    int n;
    cin >> n;

    vector<int> v;
    for(int i=0; i<n; i++) {
        int input;
        cin >> input;

        v.push_back(input);
    }

    back_tracking(v, 0, 0);

    if(answer == 999999999) cout << -1;

    cout << answer;
}