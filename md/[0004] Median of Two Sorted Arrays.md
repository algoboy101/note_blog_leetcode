---
title: "[0004] Median of Two Sorted Arrays"
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
date: 2020-01-01 00:00:04
---

## 题目描述

> 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。 
> 
> 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。 
> 
> 你可以假设 nums1 和 nums2 不会同时为空。 
> 
> 示例 1: 
> 
> nums1 = [1, 3]
> nums2 = [2]
> 
> 则中位数是 2.0
> 
> 
> 示例 2: 
> 
> nums1 = [1, 2]
> nums2 = [3, 4]
> 
> 则中位数是 (2 + 3)/2 = 2.5
> 
> Related Topics 数组 二分查找 分治算法

## 题目代码

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
    }
};
```

## 解析

### 方法一

合并两个数组，排序。长度为奇数时，返回中间数字；否则，返回中间两个的平均数。

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty() && nums2.empty())
            return -1.0;
        vector<int> nums;
        for(int i=0; i<nums1.size(); i++)
            nums.push_back(nums1[i]);
        for(int i=0; i<nums2.size(); i++)
            nums.push_back(nums2[i]);
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        if(sz % 2 == 1)
            return nums[sz / 2];
        else
            return (nums[sz/2 -1] + nums[sz/2]) / 2.0;
    }
};
```

### 方法二

```cpp

```

### 方法三

```cpp

```

