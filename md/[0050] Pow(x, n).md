---
title: "[0050] Pow(x, n)"
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
date: 2020-01-01 00:00:50
---

## 题目描述

> 实现 pow(x, n) ，即计算 x 的 n 次幂函数。 
> 
> 示例 1: 
> 
> 输入: 2.00000, 10
> 输出: 1024.00000
> 
> 
> 示例 2: 
> 
> 输入: 2.10000, 3
> 输出: 9.26100
> 
> 
> 示例 3: 
> 
> 输入: 2.00000, -2
> 输出: 0.25000
> 解释: 2-2 = 1/22 = 1/4 = 0.25 
> 
> 说明: 
> 
> 
> -100.0 < x < 100.0 
> n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。 
> 
> Related Topics 数学 二分查找

## 题目代码

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        
    }
};
```

## 解析

### 方法一

这道题让我们求x的n次方，如果只是简单的用个 for 循环让x乘以自己n次的话，未免也把 LeetCode 上的题想的太简单了，一句话形容图样图森破啊。OJ 因超时无法通过，所以需要优化，使其在更有效的算出结果来们可以用递归来折半计算，每次把n缩小一半，这样n最终会缩小到0，任何数的0次方都为1，这时候再往回乘，如果此时n是偶数，直接把上次递归得到的值算个平方返回即可，如果是奇数，则还需要乘上个x的值。还有一点需要引起注意的是n有可能为负数，对于n是负数的情况，我可以先用其绝对值计算出一个结果再取其倒数即可，之前是可以的，但是现在 test case 中加了个负2的31次方后，这就不行了，因为其绝对值超过了整型最大值，会有溢出错误，不过可以用另一种写法只用一个函数，在每次递归中处理n的正负，然后做相应的变换即可，代码如下：

	

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        double half = myPow(x, n / 2);
        if (n % 2 == 0) return half * half;
        if (n > 0) return half * half * x;
        return half * half / x;
    }
};
```

### 方法二

这道题还有迭代的解法，让i初始化为n，然后看i是否是2的倍数，不是的话就让 res 乘以x。然后x乘以自己，i每次循环缩小一半，直到为0停止循环。最后看n的正负，如果为负，返回其倒数，参见代码如下：



```cpp
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        for (int i = n; i != 0; i /= 2) {
            if (i % 2 != 0) res *= x;
            x *= x;
        }
        return n < 0 ? 1 / res : res;
    }
};
```

Github 同步地址：

https://github.com/grandyang/leetcode/issues/50

 

类似题目：

Sqrt(x)

Super Pow