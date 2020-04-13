#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main() {
    int N;
    cin >> N;
 
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
 
        int left = 0, right = 3;
        while (left + 2 < s.size()) {
            if (left + 2 < s.size() && s[left] == s[left + 1] && s[left + 1] == s[left + 2]) {
                right = s.erase(s.begin() + left + 2) - s.begin();
                left = right - 3;
            } else if (left + 3 < s.size() && s[left] == s[left + 1] && s[left + 2] == s[left + 3] && s[left + 1] != s[left + 2]) {
                right = s.erase(s.begin() + left + 3) - s.begin();
                left = right - 3;
            } else {
                left++, right++;
            }
        }
 
        cout << s << endl;
    }
    return 0;
}