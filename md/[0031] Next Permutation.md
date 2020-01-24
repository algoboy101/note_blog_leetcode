---
title: "[0031] Next Permutation"
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
date: 2020-01-01 00:00:31
---

## 题目描述

> 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。 
> 
> 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。 
> 
> 必须原地修改，只允许使用额外常数空间。 
> 
> 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。 
> 1,2,3 → 1,3,2 
> 3,2,1 → 1,2,3 
> 1,1,5 → 1,5,1 
> Related Topics 数组

## 题目代码

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
    }
};
```

## 解析

这道题让我们求下一个排列顺序，由题目中给的例子可以看出来，如果给定数组是降序，则说明是全排列的最后一种情况，则下一个排列就是最初始情况，可以参见之前的博客 Permutations。再来看下面一个例子，有如下的一个数组

1　　2　　7　　4　　3　　1

下一个排列为：

1　　3　　1　　2　　4　　7

那么是如何得到的呢，我们通过观察原数组可以发现，如果从末尾往前看，数字逐渐变大，到了2时才减小的，然后再从后往前找第一个比2大的数字，是3，那么我们交换2和3，再把此时3后面的所有数字转置一下即可，步骤如下：

1　　2　　7　　4　　3　　1

1　　2　　7　　4　　3　　1

1　　3　　7　　4　　2　　1

1　　3　　1　　2　　4　　7

### 方法一

```cpp
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int i, j, n = num.size();
        for (i = n - 2; i >= 0; --i) {
            if (num[i + 1] > num[i]) {
                for (j = n - 1; j > i; --j) {
                    if (num[j] > num[i]) break;
                }
                swap(num[i], num[j]);
                reverse(num.begin() + i + 1, num.end());
                return;
            }
        }
        reverse(num.begin(), num.end());
    }
};
```

### 方法二

下面这种写法更简洁一些，但是整体思路和上面的解法没有什么区别，参见代码如下：

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {int n = nums.size(), i = n - 2, j = n - 1;
        while (i >= 0 && nums[i] >= nums[i + 1]) --i;
        if (i >= 0) {
            while (nums[j] <= nums[i]) --j;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};
```

Github 同步地址：

https://github.com/grandyang/leetcode/issues/31


类似题目：

Permutations II

Permutations

Permutation Sequence

Palindrome Permutation II 

Palindrome Permutation