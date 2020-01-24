---
title: "[0034] Find First and Last Position of Element in Sorted Array"
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
date: 2020-01-01 00:00:34
---

## 题目描述

> 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。 
> 
> 你的算法时间复杂度必须是 O(log n) 级别。 
> 
> 如果数组中不存在目标值，返回 [-1, -1]。 
> 
> 示例 1: 
> 
> 输入: nums = [5,7,7,8,8,10], target = 8
> 输出: [3,4] 
> 
> 示例 2: 
> 
> 输入: nums = [5,7,7,8,8,10], target = 6
> 输出: [-1,-1] 
> Related Topics 数组 二分查找

## 题目代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
    }
};
```

## 解析

这道题让我们在一个有序整数数组中寻找相同目标值的起始和结束位置，而且限定了时间复杂度为 O(logn)，这是典型的二分查找法的时间复杂度，所以这里也需要用此方法，思路是首先对原数组使用二分查找法，找出其中一个目标值的位置，然后向两边搜索找出起始和结束的位置，代码如下：

### 方法一

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx = search(nums, 0, nums.size() - 1, target);
        if (idx == -1) return {-1, -1};
        int left = idx, right = idx;
        while (left > 0 && nums[left - 1] == nums[idx]) --left;
        while (right < nums.size() - 1 && nums[right + 1] == nums[idx]) ++right;
        return {left, right};
    }
    int search(vector<int>& nums, int left, int right, int target) {
        if (left > right) return -1;
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) return search(nums, mid + 1, right, target);
        else return search(nums, left, mid - 1, target);
    }
};
```

### 方法二

可能有些人会觉得上面的算法不是严格意义上的 O(logn) 的算法，因为在最坏的情况下会变成 O(n)，比如当数组里的数全是目标值的话，从中间向两边找边界就会一直遍历完整个数组，那么下面来看一种真正意义上的 O(logn) 的算法，使用两次二分查找法，第一次找到左边界，第二次调用找到右边界即可，具体代码如下：

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        if (right == nums.size() || nums[right] != target) return res;
        res[0] = right;
        right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) left = mid + 1;
            else right = mid;
        }
        res[1] = right - 1;
        return res;
    }
};
```

### 方法三

其实我们也可以只使用一个二分查找的子函数，来同时查找出第一个和最后一个位置。如何只用查找第一个大于等于目标值的二分函数来查找整个范围呢，这里用到了一个小 trick，首先来查找起始位置的 target，就是在数组中查找第一个大于等于 target 的位置，当返回的位置越界，或者该位置上的值不等于 target 时，表示数组中没有 target，直接返回 {-1, -1} 即可。若查找到了 target 值，则再查找第一个大于等于 target+1 的位置，然后把返回的位置减1，就是 target 的最后一个位置，即便是返回的值越界了，减1后也不会越界，这样就实现了使用一个二分查找函数来解题啦，参见代码如下：

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = firstGreaterEqual(nums, target);
        if (start == nums.size() || nums[start] != target) return {-1, -1};
        return {start, firstGreaterEqual(nums, target + 1) - 1};
    }
    int firstGreaterEqual(vector<int>& nums, int target) {
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

https://github.com/grandyang/leetcode/issues/34

类似题目：

First Bad Version

 