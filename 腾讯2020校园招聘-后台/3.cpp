#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int N, Q;
vector<int> allNumber;
vector<long long> inv, revInv;
 
void solve(int layer, int i, int j, vector<long long>& target) {
    if (layer == 0) return;
    const int mid = (i + j) >> 1;
 
    solve(layer - 1, i, mid, target);
    solve(layer - 1, mid + 1, j, target);
 
    int ptr1 = i, ptr2 = mid + 1;
    const int ptr1_end = mid, ptr2_end = j;
    const int len1 = mid - i + 1;
 
    long long currentAnswer = 0;
    vector<int> tmp(j - i + 1, 0);
    int tmpPtr = 0;
    while (ptr1 <= ptr1_end && ptr2 <= ptr2_end) {
        if (allNumber[ptr1] <= allNumber[ptr2]) {
            tmp[tmpPtr++] = allNumber[ptr1];
            ptr1++;
        } else {
            tmp[tmpPtr++] = allNumber[ptr2];
            ptr2++;
            currentAnswer += len1 - (ptr1 - i);
        }
    }
    while (ptr1 <= ptr1_end) {
        tmp[tmpPtr++] = allNumber[ptr1++];
    }
    while (ptr2 <= ptr2_end) {
        tmp[tmpPtr++] = allNumber[ptr2++];
    }
 
    for (int ptr = 0; ptr < tmpPtr; ptr++) {
        allNumber[i + ptr] = tmp[ptr];
    }
    target[layer] += currentAnswer;
}
 
int main() {
    int n;
    cin >> n;
 
    N = 1 << n;
    inv = revInv = vector<long long>(n + 1, 0);
 
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        allNumber.push_back(tmp);
    }
 
    vector<int> rawBackup = allNumber;
    solve(n, 0, N - 1, inv);
    allNumber = rawBackup;
    reverse(allNumber.begin(), allNumber.end());
    solve(n, 0, N - 1, revInv);
 
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int m;
        cin >> m;
 
        long long answer = 0;
        for (int j = m; j >= 0; j--) {
            swap(inv[j], revInv[j]);
        }
 
        for (int j = 0; j <= n; j++) answer += inv[j];
        cout << answer << endl;
    }
 
    return 0;
}
