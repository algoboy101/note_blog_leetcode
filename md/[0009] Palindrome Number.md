---
title: "[0009] Palindrome Number"
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
date: 2020-01-01 00:00:09
---

## 题目描述

> 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。 
> 
> 示例 1: 
> 
> 输入: 121
> 输出: true
> 
> 
> 示例 2: 
> 
> 输入: -121
> 输出: false
> 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
> 
> 
> 示例 3: 
> 
> 输入: 10
> 输出: false
> 解释: 从右向左读, 为 01 。因此它不是一个回文数。
> 
> 
> 进阶: 
> 
> 你能不将整数转为字符串来解决这个问题吗？ 
> Related Topics 数学

## 题目代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        
    }
};
```

## 解析

这道验证回文数字的题如果将数字转为字符串，就变成了验证回文字符串的题，没啥难度了，我们就直接来做 follow up 吧，不能转为字符串，而是直接对整数进行操作，可以利用取整和取余来获得想要的数字，比如 1221 这个数字，如果 计算 1221 / 1000， 则可得首位1， 如果 1221 % 10， 则可得到末尾1，进行比较，然后把中间的 22 取出继续比较。代码如下：

### 方法一

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int div = 1;
        while (x / div >= 10) div *= 10;
        while (x > 0) {
            int left = x / div;
            int right = x % 10;
            if (left != right) return false;
            x = (x % div) / 10;
            div /= 100;
        }
        return true;
    }
};
```

### 方法二

再来看一种很巧妙的解法，还是首先判断x是否为负数，这里可以用一个小 trick，因为整数的最高位不能是0，所以回文数的最低位也不能为0，数字0除外，所以如果发现某个正数的末尾是0了，也直接返回 false 即可。好，下面来看具体解法，要验证回文数，那么就需要看前后半段是否对称，如果把后半段翻转一下，就看和前半段是否相等就行了。所以做法就是取出后半段数字，进行翻转，具体做法是，每次通过对 10 取余，取出最低位的数字，然后加到取出数的末尾，就是将 revertNum 乘以 10，再加上这个余数，这样翻转也就同时完成了，每取一个最低位数字，x都要自除以 10。这样当 revertNum 大于等于x的时候循环停止。由于回文数的位数可奇可偶，如果是偶数的话，那么 revertNum 就应该和x相等了；如果是奇数的话，那么最中间的数字就在 revertNum 的最低位上了，除以 10 以后应该和x是相等的，参见代码如下：

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        int revertNum = 0;
        while (x > revertNum) {
            revertNum = revertNum * 10 + x % 10;
            x /= 10;
        }
        return x == revertNum || x == revertNum / 10;
    }
};
```

### 方法三

下面这种解法由热心网友 zeeng 提供，如果是 palindrome，反转后仍是原数字，就不可能溢出，只要溢出一定不是 palindrome 返回 false 就行。可以参考 Reverse Integer 这题，直接调用 Reverse()。

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        return reverse(x) == x;
    }
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            if (res > INT_MAX / 10) return -1;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};
```

Github 同步地址：

https://github.com/grandyang/leetcode/issues/9

 

类似题目：

Palindrome Linked List

Reverse Integer