---
title: "[0052] N-Queens II"
tags:
  - leetcode
categories:
  - leetcode
author: 张学志
comments: true
updated: false
permalink:
mathjax: false
top: false
description: ...
date: 2020-01-01 00:00:52
---

## 题目描述

> n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。 
> 
> 
> 
> 上图为 8 皇后问题的一种解法。 
> 
> 给定一个整数 n，返回 n 皇后不同的解决方案的数量。 
> 
> 示例: 
> 
> 输入: 4
> 输出: 2
> 解释: 4 皇后问题存在如下两个不同的解法。
> [
>  [".Q..",  // 解法 1
>   "...Q",
>   "Q...",
>   "..Q."],
> 
>  ["..Q.",  // 解法 2
>   "Q...",
>   "...Q",
>   ".Q.."]
> ]
> 
> Related Topics 回溯算法

## 题目代码

```cpp
class Solution {
public:
    int totalNQueens(int n) {
        
    }
};
```

## 解析

### 方法一

这道题是之前那道 N-Queens 的延伸，说是延伸其实我觉得两者顺序应该颠倒一样，上一道题比这道题还要稍稍复杂一些，两者本质上没有啥区别，都是要用回溯法 Backtracking 来解，如果理解了之前那道题的思路，此题只要做很小的改动即可，不再需要求出具体的皇后的摆法，只需要每次生成一种解法时，计数器加一即可，代码如下：



```cpp
class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<int> pos(n, -1);
        helper(pos, 0, res);
        return res;
    }
    void helper(vector<int>& pos, int row, int& res) {
        int n = pos.size();
        if (row == n) ++res;
        for (int col = 0; col < n; ++col) {
            if (isValid(pos, row, col)) {
                pos[row] = col;
                helper(pos, row + 1, res);
                pos[row] = -1;
            }
        }
    }
    bool isValid(vector<int>& pos, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (col == pos[i] || abs(row - i) == abs(col - pos[i])) {
                return false;
            }
        }
        return true;
    }
};
```

### 方法二

但是其实我们并不需要知道每一行皇后的具体位置，而只需要知道会不会产生冲突即可。对于每行要新加的位置，需要看跟之前的列，对角线，及逆对角线之间是否有冲突，所以我们需要三个布尔型数组，分别来记录之前的列 cols，对角线 diag，及逆对角线 anti_diag 上的位置，其中 cols 初始化大小为n，diag 和 anti_diag 均为 2n。列比较简单，是哪列就直接去 cols 中查找，而对角线的话，需要处理一下，如果我们仔细观察数组位置坐标的话，可以发现所有同一条主对角线的数，其纵坐标减去横坐标再加n，一定是相等的。同理，同一条逆对角线上的数字，其横纵坐标之和一定是相等的，根据这个，就可以快速判断主逆对角线上是否有冲突。任意一个有冲突的话，直接跳过当前位置，否则对于新位置，三个数组中对应位置都赋值为 true，然后对下一行调用递归，递归返回后记得还要还原状态，参见代码如下：



```cpp
class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<bool> cols(n), diag(2 * n), anti_diag(2 * n);
        helper(n, 0, cols, diag, anti_diag, res);
        return res;
    }
    void helper(int n, int row, vector<bool>& cols, vector<bool>& diag, vector<bool>& anti_diag, int& res) {
        if (row == n) ++res;
        for (int col = 0; col < n; ++col) {
            int idx1 = col - row + n, idx2 = col + row;
            if (cols[col] || diag[idx1] || anti_diag[idx2]) continue;
            cols[col] = diag[idx1] = anti_diag[idx2] = true;
            helper(n, row + 1, cols, diag, anti_diag, res);
            cols[col] = diag[idx1] = anti_diag[idx2] = false;
        }
    }
};
```

Github 同步地址：

https://github.com/grandyang/leetcode/issues/52

 

类似题目：

N-Queens 