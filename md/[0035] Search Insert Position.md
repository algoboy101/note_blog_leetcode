---
title: "[0035] Search Insert Position"
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
date: 2020-01-01 00:00:35
---

## 题目描述

> 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。 
> 
> 你可以假设数组中无重复元素。 
> 
> 示例 1: 
> 
> 输入: [1,3,5,6], 5
> 输出: 2
> 
> 
> 示例 2: 
> 
> 输入: [1,3,5,6], 2
> 输出: 1
> 
> 
> 示例 3: 
> 
> 输入: [1,3,5,6], 7
> 输出: 4
> 
> 
> 示例 4: 
> 
> 输入: [1,3,5,6], 0
> 输出: 0
> 
> Related Topics 数组 二分查找

## 题目代码

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
    }
};
```

## 解析

这道题基本没有什么难度，实在不理解为啥还是 Medium 难度的，完完全全的应该是 Easy 啊（貌似现在已经改为 Easy 类了），三行代码搞定的题，只需要遍历一遍原数组，若当前数字大于或等于目标值，则返回当前坐标，如果遍历结束了，说明目标值比数组中任何一个数都要大，则返回数组长度n即可，代码如下：

### 方法一

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= target) return i;
        }
        return nums.size();
    }
};
```

### 方法二

当然，我们还可以用二分搜索法来优化时间复杂度，而且个人认为这种方法应该是面试官们想要考察的算法吧，属于博主之前的总结帖 LeetCode Binary Search Summary 二分搜索法小结 中第二类 - 查找不小于目标值的数，参见代码如下：

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.back() < target) return nums.size();
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        return right;
    }
};
```

Github 同步地址：

https://github.com/grandyang/leetcode/issues/35

类似题目：

First Bad Version