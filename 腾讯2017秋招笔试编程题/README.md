# 腾讯 2017 秋招笔试编程题

这套题和 2020 年那套相比， **没有难度** 。

## T1 Medium

其实可以推公式，但是这道题数据很小，直接暴力dfs就可以过，最坏情况需要dfs `pow(26, 4)` 次

类似的题目：[440. K-th Smallest in Lexicographical Order](https://leetcode.com/problems/k-th-smallest-in-lexicographical-order)

## T2 Very Easy

这道题是 C 语言练习题？？？？？？

## T3 Medium

埃氏筛，然后遍历即可。其实也可以用欧拉筛，但是复杂度方面优化得并不明显

## T4 Easy

二分搜索，有个坑，区间范围有负数的时候，`(left + right) >> 1` 与 `(left + right) / 2`不等价