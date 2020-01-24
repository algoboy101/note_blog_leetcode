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

```

### 方法二

```cpp

```

### 方法三

```cpp

```

