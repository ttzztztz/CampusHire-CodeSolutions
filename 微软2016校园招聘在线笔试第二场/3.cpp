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

int vote[1005][1005];

int main() {
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = K; j >= 0; j--) {
            int tmp;
            cin >> tmp;
            vote[i][tmp] = j;
        }
    }

    int answer = 0;
    for (int j = K; j > 0; j--) {
        int cnt = 0;

        for (int i = 0; i < N; i++) {
            if (vote[i][j] > vote[i][answer]) {
                cnt++;
            }
        }

        if (cnt > N / 2) answer = j;
    }
    if (answer == 0) {
        cout << "otaku" << endl;
    } else {
        cout << answer << endl;
    }
    return 0;
}