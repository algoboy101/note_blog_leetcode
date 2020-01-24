---
title: "[0069] Sqrt(x)"
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
date: 2020-01-01 00:01:09
---

## 题目描述

> 实现 int sqrt(int x) 函数。 
> 
> 计算并返回 x 的平方根，其中 x 是非负整数。 
> 
> 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。 
> 
> 示例 1: 
> 
> 输入: 4
> 输出: 2
> 
> 
> 示例 2: 
> 
> 输入: 8
> 输出: 2
> 说明: 8 的平方根是 2.82842..., 
>      由于返回类型是整数，小数部分将被舍去。
> 
> Related Topics 数学 二分查找

## 题目代码

```cpp
class Solution {
public:
    int mySqrt(int x) {
        
    }
};
```

## 解析

### 方法一

这道题要求我们求平方根，我们能想到的方法就是算一个候选值的平方，然后和x比较大小，为了缩短查找时间，我们采用二分搜索法来找平方根，这里属于博主之前总结的 LeetCode Binary Search Summary 二分搜索法小结 中的第三类的变形，找最后一个不大于目标值的数，这里细心的童鞋可能会有疑问，在总结贴中第三类博主的 right 用的是开区间，那么这里为啥 right 初始化为x，而不是 x+1 呢？因为总结帖里的 left 和 right 都是数组下标，这里的 left 和 right 直接就是数字本身了，一个数字的平方根是不可能比起本身还大的，所以不用加1，还有就是这里若x是整型最大值，再加1就会溢出。最后就是返回值是 right-1，因为题目中说了要把小数部分减去，只有减1才能得到正确的值，代码如下：


```cpp
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        int left = 0, right = x;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x / mid >= mid) left = mid + 1;
            else right = mid;
        }
        return right - 1;
    }
};
```

### 方法二

这道题还有另一种解法，是利用牛顿迭代法，记得高数中好像讲到过这个方法，是用逼近法求方程根的神器，在这里也可以借用一下，可参见网友 Annie Kim's Blog的博客，因为要求 x2 = n 的解，令 f(x)=x2-n，相当于求解 f(x)=0 的解，可以求出递推式如下：

xi+1=xi - (xi2 - n) / (2xi) = xi - xi / 2 + n / (2xi) = xi / 2 + n / 2xi = (xi + n/xi) / 2

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        double res = 1, pre = 0;
        while (abs(res - pre) > 1e-6) {
            pre = res;
            res = (res + x / res) / 2;
        }
        return int(res);
    }
};
```

### 方法三

也是牛顿迭代法，写法更加简洁一些，注意为了防止越界，声明为长整型，参见代码如下：


```cpp
class Solution {
public:
    int mySqrt(int x) {
        long res = x;
        while (res * res > x) {
            res = (res + x / res) / 2;
        }
        return res;
    }
};
```

