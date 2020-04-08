class Solution {
public:
    /**
     *
     * @param n int整型 第n天
     * @return int整型
     */
    int solution(int n) {
        int d = 1, answer = 0;
        while (f(d) <= n) {
            answer += d * d;
            d++;
        }
         
        if (f(d) > n) {
            d--;
            const int delta = n - f(d);
            answer += delta * (d + 1);
        }
        return answer;
    }
private:
    int f(int n) {
        return (n * n + n) / 2;
    }
};