#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for(int i=0; i<n; i++) {
        int input;
        cin >> input;

        if(input == 0) {
            if(pq.size() == 0) cout << 0 << "\n";
            else {
                int value = pq.top().first;
                int temp = pq.top().second;
                
                if(temp == 0) {
                    cout << -value << "\n";
                } else if(temp == 1) {
                    cout << value << "\n";
                }
                pq.pop();
            }
        } else if(input > 0) {
            pq.push(make_pair(input, 1));
        } else if(input < 0) {
            pq.push(make_pair(-input, 0));
        }
    }

    return 0;
}