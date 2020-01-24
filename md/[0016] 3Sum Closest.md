---
title: "[0016] 3Sum Closest"
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
date: 2020-01-01 00:00:16
---

## 题目描述

> 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。 
> 
> 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
> 
> 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
> 
> Related Topics 数组 双指针

## 题目代码

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
    }
};
```

## 解析

这道题让我们求最接近给定值的三数之和，是在之前那道 3Sum 的基础上又增加了些许难度，那么这道题让返回这个最接近于给定值的值，即要保证当前三数和跟给定值之间的差的绝对值最小，所以需要定义一个变量 diff 用来记录差的绝对值，然后还是要先将数组排个序，然后开始遍历数组，思路跟那道三数之和很相似，都是先确定一个数，然后用两个指针 left 和 right 来滑动寻找另外两个数，每确定两个数，求出此三数之和，然后算和给定值的差的绝对值存在 newDiff 中，然后和 diff 比较并更新 diff 和结果 closest 即可，代码如下：

### 方法一

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = nums[0] + nums[1] + nums[2];
        int diff = abs(closest - target);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int newDiff = abs(sum - target);
                if (diff > newDiff) {
                    diff = newDiff;
                    closest = sum;
                }
                if (sum < target) ++left;
                else --right;
            }
        }
        return closest;
    }
};
```

Github 同步地址：

https://github.com/grandyang/leetcode/issues/16

 

类似题目：

3Sum Smaller

3Sum