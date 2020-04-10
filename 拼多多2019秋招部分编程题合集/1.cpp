#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <limits>
#include <cmath>
 
using namespace std;
 
int N, K;
string numbers;
vector<int> statics;
vector<vector<int>> ways;
 
int main() {
    statics.resize(10);
    ways = vector<vector<int>>(10, vector<int>(10, 0));
 
    cin >> N >> K >> numbers;
    int min_cost = numeric_limits<int>::max(), min_index = -1;
    for (const char ch : numbers) statics[ch - '0']++;
    for (int i = 0; i <= 9; i++) {
        if (statics[i] >= K) {
            cout << 0 << endl << numbers << endl;
            exit(0);
        }
 
        int left = i - 1, right = i + 1, rest = K - statics[i], currentCost = 0;
        vector<int> current(10);
        while (rest > 0) {
            if (rest > 0 && right <= 9) {
                if (statics[right] >= rest) {
                    current[right] = rest;
                    rest = 0;
                }
                else {
                    current[right] = statics[right];
                    rest -= statics[right];
                }
 
                currentCost += abs(right - i) * current[right];
            }
 
            if (rest > 0 && left >= 0) {
                if (statics[left] >= rest) {
                    current[left] = rest;
                    rest = 0;
                }
                else {
                    current[left] = statics[left];
                    rest -= statics[left];
                }
 
                currentCost += abs(left - i) * current[left];
            }
            left--, right++;
        }
 
        ways[i] = current;
        if (currentCost < min_cost) {
            min_cost = currentCost;
            min_index = i;
        }
    }
 
    cout << min_cost << endl;
    for (int i = 0; i < N; i++) {
        const int digit = numbers[i] - '0';
 
        if (digit > min_index && ways[min_index][digit] > 0) {
            ways[min_index][digit]--;
            numbers[i] = min_index + '0';
        }
    }
 
    for (int i = N - 1; i >= 0; i--) {
        const int digit = numbers[i] - '0';
 
        if (digit < min_index && ways[min_index][digit] > 0) {
            ways[min_index][digit]--;
            numbers[i] = min_index + '0';
        }
    }
    cout << numbers << endl;
    return 0;
}