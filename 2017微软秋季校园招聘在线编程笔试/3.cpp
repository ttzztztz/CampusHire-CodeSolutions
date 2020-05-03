#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

typedef pair<long long, int> PLI;
typedef pair<int, long long> PIL;

class Student {
public:
    int id, idx, cur;
    vector<PIL> tasks;

    Student() : id(0), idx(0), cur(0) {};
};

int main() {
    ios::sync_with_stdio(false);
    int N, M;
    long long K;
    cin >> N >> M >> K;

    vector<long long> freeTime(M, 0);
    vector<long long> answer(N);
    unordered_map<int, Student> student;

    priority_queue<PLI, vector<PLI>, greater<PLI>> heap;
    for (int i = 0; i < N; i++) {
        int id;
        long long gateTime, T;
        cin >> id >> gateTime >> T;

        student[id].id = id;
        student[id].idx = i;

        for (int j = 0; j < T; j++) {
            int office;
            long long tme;
            cin >> office >> tme;

            office--;
            student[id].tasks.emplace_back(office, tme);
        }
        heap.emplace(gateTime + K, id);
    }

    while (!heap.empty()) {
        long long time;
        int id;
        tie(time, id) = heap.top();
        heap.pop();

        Student &stu = student[id];
        int& curOffice = stu.cur;

        if (freeTime[stu.tasks[curOffice].first] > time) {
            time = freeTime[stu.tasks[curOffice].first];
        }

        freeTime[stu.tasks[curOffice].first] = time + stu.tasks[curOffice].second;
        if (curOffice == stu.tasks.size() - 1) {
            answer[stu.idx] = time + stu.tasks[curOffice].second;
        } else {
            heap.emplace(time + stu.tasks[curOffice].second + K, id);
            curOffice++;
        }
    }

    for (long long i : answer) cout << i << endl;
    return 0;
}