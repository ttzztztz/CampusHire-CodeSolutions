# 2019 PayPal实习生招聘编程卷

## T1 Hard

扔鸡蛋🥚动态规划问题，可参考[887. Super Egg Drop](https://leetcode.com/problems/super-egg-drop/)
发现f1, f2的单调性以后需要用二分优化dp过程，否则会超时

## T2 Medium

很显然的并查集问题，就是输出格式有点奇怪

## T3 Medium

差分+贪心，然后双指针即可，我偷懒了，用了std::map，更好的做法是用离散化代替std::map

## T4 Easy

有点像约瑟夫环问题，用一个数组模拟一下就可以了