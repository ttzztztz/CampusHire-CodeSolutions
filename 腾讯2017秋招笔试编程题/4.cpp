#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main() {
    int N;
    cin >> N;
 
    int left = -90, right = 90;
    while (right - left + 1 >= 6) {
        const int mid = (left + right) / 2;
 
        if (N < mid) {
            cout << 0;
            right = mid;
        } else {
            cout << 1;
            left = mid;
        }
    }
    cout << endl;
    return 0;
}