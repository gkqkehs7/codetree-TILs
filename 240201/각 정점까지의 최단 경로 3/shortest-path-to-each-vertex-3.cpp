#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int dp[101] = { 0, };
    vector<pair<int, int>> graph[101];
    priority_queue<pair<int, int>> pq;

    for(int i=0; i<101; i++) {
        dp[i] = 999999999;
    }

    // 그래프 만들기
    for(int i=0; i<m; i++) {
        int start, end, distance;
        cin >> start >> end >> distance;

        graph[start].push_back({ end, distance });
    }

    dp[1] = 0;
    pq.push({ 0, 1 });

    while(!pq.empty()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(dp[now] < cost) continue;

        for(int i=0; i<graph[now].size(); i++) {
            int next = graph[now][i].first;
            int distance = graph[now][i].second;

            if(cost + distance < dp[next]) {
                pq.push({ cost + distance, next });
                dp[next] = cost + distance;
            }
        }
    }

    for(int i = 2; i <= n; i++) {
        if(dp[i] == 999999999) {
            cout << -1 << "\n";
            continue;
        }
        cout << dp[i] << "\n";
    }


    return 0;
}