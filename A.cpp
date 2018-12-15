//
// Created by Елена on 15/12/2018.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
vector<pair<int, int>> array;

struct comp {
    bool operator() (const int &a, const int &b) {
        return a > b;
    }
};

int main() {

    freopen("schedule.in", "r", stdin);
    freopen("schedule.out", "w", stdout);

    cin >> n;

    vector<pair<int, int>> dead;
    
    for (int i = 0; i < n; ++i) {
        int d_temp, w_temp;
        cin >> d_temp >> w_temp;
        dead.emplace_back(d_temp, w_temp);
    }
    sort(dead.begin(), dead.end(), [](pair<int, int> a, pair<int, int> b) { return (a.first < b.first); });

    priority_queue<int, vector<int>, comp>queue;
    long long answer = 0;

    for (int i = 0; i < n; i++) {
        queue.push(dead[i].second);
        if (dead[i].first < queue.size()){
            int temp = queue.top();
            answer += temp;
            queue.pop();
        }
    }
    cout << answer;
}
