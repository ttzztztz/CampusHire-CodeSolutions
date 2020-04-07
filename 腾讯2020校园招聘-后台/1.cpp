#include <iostream>
#include <cstring>
#include <algorithm>
 
using namespace std;
 
string solve(const string &str);
 
string repeat(const string &str, const string &repeat_times) {
    int number = stoi(repeat_times);
 
    string answer;
    for (int i = 0; i < number; i++) {
        answer += str;
    }
    return answer;
}
 
string parse(const string &str) {
    string repeat_times;
 
    int i = 0;
    for (; i < str.size(); i++) {
        if (str[i] != '|') {
            repeat_times += str[i];
        } else {
            break;
        }
    }
 
    return repeat(solve(str.substr(i + 1)), repeat_times);
}
 
string solve(const string &str) {
    string answer;
 
    string inside;
    int ptr = 0, level = 0, start = -1;
    while (ptr < str.size()) {
        if (str[ptr] == '[') {
            if (level == 0 && start == -1) {
                start = ptr;
            } else {
                inside += str[ptr];
            }
            level++;
        } else if (str[ptr] == ']') {
            level--;
            if (level == 0) {
                answer += parse(inside);
                inside = "";
                start = -1;
            } else {
                inside += str[ptr];
            }
        } else {
            if (level == 0) answer += str[ptr];
            else inside += str[ptr];
        }
        ptr++;
    }
 
    return answer;
}
 
int main() {
    string str;
    cin >> str;
    cout << solve(str) << endl;
    return 0;
}
