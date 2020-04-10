#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
 
using namespace std;
 
int main() {
    int N;
    cin >> N;
    vector<int> numbers(N);
    for (int i = 0; i < N; i++) cin >> numbers[i];
    sort(numbers.begin(), numbers.end());
 
    int max_number = numeric_limits<int>::min(), min_number = numeric_limits<int>::max();
    int left = 0, right = N - 1;
    while (left < right) {
        max_number = max(max_number, numbers[left] + numbers[right]);
        min_number = min(min_number, numbers[left] + numbers[right]);
        left++, right--;
    }
    cout << max_number - min_number << endl;
    return 0;
}