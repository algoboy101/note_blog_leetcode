---
title: "[0007] Reverse Integer"
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
date: 2020-01-01 00:00:07
---

## 题目描述

> 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。 
> 
> 示例 1: 
> 
> 输入: 123
> 输出: 321
> 
> 
> 示例 2: 
> 
> 输入: -123
> 输出: -321
> 
> 
> 示例 3: 
> 
> 输入: 120
> 输出: 21
> 
> 
> 注意: 
> 
> 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231, 231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。 
> Related Topics 数学

## 题目代码

```cpp
class Solution {
public:
    int reverse(int x) {
        
    }
};
```

## 解析

翻转数字问题需要注意的就是溢出问题，看了许多网上的解法，由于之前的 OJ 没有对溢出进行测试，所以网上很多人的解法没有处理溢出问题也能通过 OJ。现在 OJ 更新了溢出测试，所以还是要考虑到。为什么会存在溢出问题呢，由于int型的数值范围是 -2147483648～2147483647， 那么如果要翻转 1000000009 这个在范围内的数得到 9000000001，而翻转后的数就超过了范围。博主最开始的想法是，用 long 型数据，其数值范围为 -9223372036854775808~9223372036854775807， 远大于 int 型这样就不会出现溢出问题。但实际上 OJ 给出的官方解答并不需要使用 long，一看比自己的写的更精简一些，它没有特意处理正负号，仔细一想，果然正负号不影响计算，而且没有用 long 型数据，感觉写的更好一些，那么就贴出来吧：

### 方法一

```cpp
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            if (abs(res) > INT_MAX / 10) return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};
```

### 方法二

在贴出答案的同时，OJ 还提了一个问题 To check for overflow/underflow, we could check if ret > 214748364 or ret < –214748364 before multiplying by 10. On the other hand, we do not need to check if ret == 214748364, why? （214748364 即为 INT_MAX / 10）

为什么不用 check 是否等于 214748364 呢，因为输入的x也是一个整型数，所以x的范围也应该在 -2147483648～2147483647 之间，那么x的第一位只能是1或者2，翻转之后 res 的最后一位只能是1或2，所以 res 只能是 2147483641 或 2147483642 都在 int 的范围内。但是它们对应的x为 1463847412 和 2463847412，后者超出了数值范围。所以当过程中 res 等于 214748364 时， 输入的x只能为 1463847412， 翻转后的结果为 2147483641，都在正确的范围内，所以不用 check。

我们也可以用 long 型变量保存计算结果，最后返回的时候判断是否在 int 返回内，但其实题目中说了只能存整型的变量，所以这种方法就只能当个思路扩展了，参见代码如下：

```cpp
class Solution {
public:
    int reverse(int x) {
        long res = 0;
        while (x != 0) {
            res = 10 * res + x % 10;
            x /= 10;
        }
        return (res > INT_MAX || res < INT_MIN) ? 0 : res;
    }
};
```

Github 同步地址：

https://github.com/grandyang/leetcode/issues/7

 

类似题目：

String to Integer (atoi)

Reverse Bits

