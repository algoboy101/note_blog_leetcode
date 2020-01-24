---
title: "[0070] Climbing Stairs"
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
date: 2020-01-01 00:01:10
---

## 题目描述

> 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。 
> 
> 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？ 
> 
> 注意：给定 n 是一个正整数。 
> 
> 示例 1： 
> 
> 输入： 2
> 输出： 2
> 解释： 有两种方法可以爬到楼顶。
> 1.  1 阶 + 1 阶
> 2.  2 阶 
> 
> 示例 2： 
> 
> 输入： 3
> 输出： 3
> 解释： 有三种方法可以爬到楼顶。
> 1.  1 阶 + 1 阶 + 1 阶
> 2.  1 阶 + 2 阶
> 3.  2 阶 + 1 阶
> 
> Related Topics 动态规划

## 题目代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        
    }
};
```

## 解析

### 方法一

这篇博客最开始名字叫做爬梯子问题，总是有童鞋向博主反映移动端打不开这篇博客，博主觉得非常奇怪，自己也试了一下，果然打不开。心想着是不是这个博客本身有问题，于是想再开一个相同的帖子，结果还是打不开，真是见了鬼了。于是博主换了个名字，结果居然打开了？！进经过排查后发现，原来是“爬梯子”这三个字是敏感词，放到标题里面，博客就被屏蔽了，我也真是醉了，完全是躺枪好么，无奈之下，只好改名为爬楼梯问题了 -。-|||。

这个爬梯子问题最开始看的时候没搞懂是让干啥的，后来看了别人的分析后，才知道实际上跟斐波那契数列非常相似，假设梯子有n层，那么如何爬到第n层呢，因为每次只能爬1或2步，那么爬到第n层的方法要么是从第 n-1 层一步上来的，要不就是从 n-2 层2步上来的，所以递推公式非常容易的就得出了：dp[n] = dp[n-1] + dp[n-2]。 由于斐波那契额数列的求解可以用递归，所以博主最先尝试了递归，拿到 OJ 上运行，显示 Time Limit Exceeded，就是说运行时间超了，因为递归计算了很多分支，效率很低，这里需要用动态规划 (Dynamic Programming) 来提高效率，代码如下：

```cpp
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        vector<int> dp(n);
        dp[0] = 1; dp[1] = 2;
        for (int i = 2; i < n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp.back();
    }
};
```

### 方法二

我们可以对空间进行进一步优化，只用两个整型变量a和b来存储过程值，首先将 a+b 的值赋给b，然后a赋值为原来的b，所以应该赋值为 b-a 即可。这样就模拟了上面累加的过程，而不用存储所有的值，参见代码如下：


```cpp
class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1;
        while (n--) {
            b += a;
            a = b - a;
        }
        return a;
    }
};
```

### 方法三

虽然前面说过递归的写法会超时，但是只要加上记忆数组，那就不一样了，因为记忆数组可以保存计算过的结果，这样就不会存在重复计算了，大大的提高了运行效率，其实递归加记忆数组跟迭代的 DP 形式基本是大同小异的，参见代码如下：

```cpp
class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo(n + 1);
        return helper(n, memo);
    }
    int helper(int n, vector<int>& memo) {
        if (n <= 1) return 1;
        if (memo[n] > 0) return memo[n];
        return memo[n] = helper(n - 1, memo) + helper(n - 2, memo);
    }
};
```

### 方法四

论坛上还有一种分治法 Divide and Conquer 的解法，用的是递归形式，可以通过，但是博主没有十分理解，希望各位看官大神可以跟博主讲一讲～

```cpp
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return 1;       
        return climbStairs(n / 2) * climbStairs(n - n / 2) + climbStairs(n / 2 - 1) * climbStairs(n - n / 2 - 1);
    }
};
```

### 方法五

```cpp
最后来看一种叼炸天的方法，其实斐波那契数列是可以求出通项公式的，推理的过程请参见 知乎上的这个贴子，那么有了通项公式后，直接在常数级的时间复杂度范围内就可以求出结果了，参见代码如下：


```