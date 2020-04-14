#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
 
using namespace std;
 
int N, M;
typedef pair<int, int> PII;
vector<PII> task;
vector<vector<int>> worker;
 
int cost(const PII &p) {
    return 200 * p.first + 3 * p.second;
}
 
int main() {
    worker = vector<vector<int>>(105, vector<int>{});
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        worker[b].push_back(a);
    }
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        task.emplace_back(x, y);
    }
 
    long long answer = 0, cnt = 0;
    sort(task.begin(), task.end(), [&](const auto &$1, const auto &$2) -> bool {
        return cost($1) > cost($2);
    });
 
    for (int i = 0; i <= 100; i++)
        sort(worker[i].begin(), worker[i].end(), [](const auto &$1, const auto &$2) -> bool {
            return $1 < $2;
        });
 
    for (const auto &currentTask : task) {
        for (int j = currentTask.second; j <= 100; j++) {
            auto it = lower_bound(worker[j].begin(), worker[j].end(), currentTask.first);
            if (it != worker[j].end()) {
                answer += cost(currentTask);
                cnt++;
                worker[j].erase(it);
                break;
            }
        }
    }
    cout << cnt << " " << answer << endl;
    return 0;
}