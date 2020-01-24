---
title: "[0073] Set Matrix Zeroes"
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
date: 2020-01-01 00:01:13
---

## 题目描述

> 给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。 
> 
> 示例 1: 
> 
> 输入: 
> [
>   [1,1,1],
>   [1,0,1],
>   [1,1,1]
> ]
> 输出: 
> [
>   [1,0,1],
>   [0,0,0],
>   [1,0,1]
> ]
> 
> 
> 示例 2: 
> 
> 输入: 
> [
>   [0,1,2,0],
>   [3,4,5,2],
>   [1,3,1,5]
> ]
> 输出: 
> [
>   [0,0,0,0],
>   [0,4,5,0],
>   [0,3,1,0]
> ] 
> 
> 进阶: 
> 
> 
> 一个直接的解决方案是使用 O(mn) 的额外空间，但这并不是一个好的解决方案。 
> 一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。 
> 你能想出一个常数空间的解决方案吗？ 
> 
> Related Topics 数组

## 题目代码

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
    }
};
```

## 解析

### 方法一

据说这题是CareerCup上的原题，我还没有刷CareerCup，所以不知道啦，不过这题也不算难，虽然我也是看了网上的解法照着写的，但是下次遇到绝对想的起来。这道题中说的空间复杂度为O(mn)的解法自不用多说，直接新建一个和matrix等大小的矩阵，然后一行一行的扫，只要有0，就将新建的矩阵的对应行全赋0，行扫完再扫列，然后把更新完的矩阵赋给matrix即可，这个算法的空间复杂度太高。将其优化到O(m+n)的方法是，用一个长度为m的一维数组记录各行中是否有0，用一个长度为n的一维数组记录各列中是否有0，最后直接更新matrix数组即可。这道题的要求是用O(1)的空间，那么我们就不能新建数组，我们考虑就用原数组的第一行第一列来记录各行各列是否有0.

- 先扫描第一行第一列，如果有0，则将各自的flag设置为true
- 然后扫描除去第一行第一列的整个数组，如果有0，则将对应的第一行和第一列的数字赋0
- 再次遍历除去第一行第一列的整个数组，如果对应的第一行和第一列的数字有一个为0，则将当前值赋0
- 最后根据第一行第一列的flag来更新第一行第一列

代码如下：

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        int m = matrix.size(), n = matrix[0].size();
        bool rowZero = false, colZero = false;
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) colZero = true;
        }
        for (int i = 0; i < n; ++i) {
            if (matrix[0][i] == 0) rowZero = true;
        } 
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (rowZero) {
            for (int i = 0; i < n; ++i) matrix[0][i] = 0;
        }
        if (colZero) {
            for (int i = 0; i < m; ++i) matrix[i][0] = 0;
        }
    }
};
```


