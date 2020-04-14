#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
 
using namespace std;
 
long long N, M;
 
long long judge(int first) {
    long long answer = 0;
    for (int i = 0; i < N; i++) {
        answer += first;
 
        first = ceil(first / 2.0);
    }
    return answer;
}
 
int main() {
    cin >> N >> M;
 
    long long left = 1, right = M;
    while (left <= right) {
        const long long mid = (left + right) >> 1;
 
        if (judge(mid) > M) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << right << endl;
    return 0;
}