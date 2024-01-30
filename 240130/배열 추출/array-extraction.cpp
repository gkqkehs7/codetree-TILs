#include <iostream>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int> pq;
    vector<int> v;

    for(int i=0; i<n; i++) {
        int input;
        cin >> input;

        if(input == 0) {
            if(pq.size() == 0) {
                cout << 0 << "\n";
            } else {
                cout << pq.top() << "\n";
                pq.pop();
            }

        } else {
            pq.push(input);
        }
    }

    return 0;

}