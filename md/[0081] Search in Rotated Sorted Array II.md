---
title: "[0081] Search in Rotated Sorted Array II"
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
date: 2020-01-01 00:01:21
---

## 题目描述

> 假设按照升序排序的数组在预先未知的某个点上进行了旋转。 
> 
> ( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。 
> 
> 编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。 
> 
> 示例 1: 
> 
> 输入: nums = [2,5,6,0,0,1,2], target = 0
> 输出: true
> 
> 
> 示例 2: 
> 
> 输入: nums = [2,5,6,0,0,1,2], target = 3
> 输出: false 
> 
> 进阶: 
> 
> 
> 这是 搜索旋转排序数组 的延伸题目，本题中的 nums 可能包含重复元素。 
> 这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？ 
> 
> Related Topics 数组 二分查找

## 题目代码

```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
    }
};
```

## 解析

### 方法一

这道是之前那道 Search in Rotated Sorted Array 的延伸，现在数组中允许出现重复数字，这个也会影响我们选择哪半边继续搜索，由于之前那道题不存在相同值，我们在比较中间值和最右值时就完全符合之前所说的规律：如果中间的数小于最右边的数，则右半段是有序的，若中间数大于最右边数，则左半段是有序的。而如果可以有重复值，就会出现来面两种情况，[3 1 1] 和 [1 1 3 1]，对于这两种情况中间值等于最右值时，目标值3既可以在左边又可以在右边，那怎么办么，对于这种情况其实处理非常简单，只要把最右值向左一位即可继续循环，如果还相同则继续移，直到移到不同值为止，然后其他部分还采用 Search in Rotated Sorted Array 中的方法，可以得到代码如下：

 

```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size(), left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] < nums[right]) {
                if (nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            } else if (nums[mid] > nums[right]){
                if (nums[left] <= target && nums[mid] > target) right = mid - 1;
                else left = mid + 1;
            } else --right;
        }
        return false;
    }
};
```

Github 同步地址：

https://github.com/grandyang/leetcode/issues/81

 

类似题目：

Search in Rotated Sorted Array