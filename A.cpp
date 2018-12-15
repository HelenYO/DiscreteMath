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

int main() {

    freopen("schedule.in", "r", stdin);
    freopen("schedule.out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        int d_temp, w_temp;
        cin >> d_temp >> w_temp;
        array.emplace_back(d_temp, w_temp);
    }
    sort(array.begin(), array.end(), [](pair<int, int> a, pair<int, int> b) { return (a.first < b.first); });

    priority_queue<int>deadlines;

    long ans = 0;
    int curTime = 1;
    for (int i = 0; i < n; ++i) {

        deadlines.push(array[i].second);
        if (array[i].first >= curTime) {
            curTime++;
        } else {
            ans += array[deadlines.top()].second;
            deadlines.pop();
        }
    }
    cout << ans;
}