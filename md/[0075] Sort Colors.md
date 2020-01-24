---
title: "[0075] Sort Colors"
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
date: 2020-01-01 00:01:15
---

## 题目描述

> 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。 
> 
> 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。 
> 
> 注意: 
> 不能使用代码库中的排序函数来解决这道题。 
> 
> 示例: 
> 
> 输入: [2,0,2,1,1,0]
> 输出: [0,0,1,1,2,2] 
> 
> 进阶： 
> 
> 
> 一个直观的解决方案是使用计数排序的两趟扫描算法。 
> 首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。 
> 你能想出一个仅使用常数空间的一趟扫描算法吗？ 
> 
> Related Topics 排序 数组 双指针

## 题目代码

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        
    }
};
```

## 解析

### 方法一

法，因为数组中只有三个不同的元素，所以实现起来很容易。

- 首先遍历一遍原数组，分别记录 0，1，2 的个数。
- 然后更新原数组，按个数分别赋上 0，1，2。

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> colors(3);
        for (int num : nums) ++colors[num];
        for (int i = 0, cur = 0; i < 3; ++i) {
            for (int j = 0; j < colors[i]; ++j) {
                nums[cur++] = i;
            }
        }
    }
};
```

### 方法二

题目中还要让只遍历一次数组来求解，那么就需要用双指针来做，分别从原数组的首尾往中心移动。

- 定义 red 指针指向开头位置，blue 指针指向末尾位置。

- 从头开始遍历原数组，如果遇到0，则交换该值和 red 指针指向的值，并将 red 指针后移一位。若遇到2，则交换该值和 blue 指针指向的值，并将 blue 指针前移一位。若遇到1，则继续遍历。

 
```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, blue = (int)nums.size() - 1;
        for (int i = 0; i <= blue; ++i) {
            if (nums[i] == 0) {
                swap(nums[i], nums[red++]);
            } else if (nums[i] == 2) {
                swap(nums[i--], nums[blue--]);
            } 
        }
    }
};
```

### 方法三

当然我们也可以使用 while 循环的方式来写，那么就需要一个变量 cur 来记录当前遍历到的位置，参见代码如下：


```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = (int)nums.size() - 1, cur = 0;
        while (cur <= right) {
            if (nums[cur] == 0) {
                swap(nums[cur++], nums[left++]);
            } else if (nums[cur] == 2) {
                swap(nums[cur], nums[right--]);
            } else {
                ++cur;
            }
        }
    }
};
```

Github 同步地址：

https://github.com/grandyang/leetcode/issues/75

 

类似题目：

Sort List

Wiggle Sort II

Wiggle Sort
