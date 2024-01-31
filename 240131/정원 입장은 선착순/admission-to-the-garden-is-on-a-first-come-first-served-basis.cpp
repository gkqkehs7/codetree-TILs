#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<tuple<int, int, int>> pq;
    priority_queue<tuple<int, int, int>> temp;

    for(int i=0; i<n; i++) {
        int a, t;
        cin >> a >> t;

        pq.push(make_tuple(-a, -i, -t));
    }


    int prev_end = -get<0>(pq.top()) + -get<2>(pq.top());
    pq.pop();

    int waiting_time = 0;

    while(!pq.empty()) {
        int start_time = -get<0>(pq.top());
        int index = -get<1>(pq.top());
        int time = -get<2>(pq.top());

        if(start_time > prev_end) {
            start_time = -get<0>(pq.top());
            prev_end = start_time + time;
            pq.pop();
        }

        while (start_time < prev_end && !pq.empty()) {
            temp.push(make_tuple(-index, -start_time, -time));
            pq.pop();

            start_time = -get<0>(pq.top());
            index = -get<1>(pq.top());
            time = -get<2>(pq.top());
        }

        while(!temp.empty()) {
            int temp_start_time = -get<1>(temp.top());
            int temp_end_time = -get<2>(temp.top());

            waiting_time = max(waiting_time, prev_end - temp_start_time);
            // cout << prev_end - temp_start_time << "\n";
            prev_end += temp_end_time;
            temp.pop();
        }
    }

    cout << waiting_time;
    return 0;
}