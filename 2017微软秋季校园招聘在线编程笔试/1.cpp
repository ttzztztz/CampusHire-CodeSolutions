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

int main() {
    int N;
    int oddCount = 0, evenCount = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        long long tmp;
        cin >> tmp;
        if (tmp % 2 == 1) oddCount++;
        else evenCount++;
    }
    
    cout << N - 2 * min(oddCount, evenCount) << endl;
    return 0;
}