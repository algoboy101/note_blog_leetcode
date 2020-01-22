---
title: "[0010] Regular Expression Matching"
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
date: 2020-01-01 00:00:10
---

## 题目描述

> 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。 
> 
> '.' 匹配任意单个字符
> '*' 匹配零个或多个前面的那一个元素
> 
> 
> 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。 
> 
> 说明: 
> 
> 
> s 可能为空，且只包含从 a-z 的小写字母。 
> p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。 
> 
> 
> 示例 1: 
> 
> 输入:
> s = "aa"
> p = "a"
> 输出: false
> 解释: "a" 无法匹配 "aa" 整个字符串。
> 
> 
> 示例 2: 
> 
> 输入:
> s = "aa"
> p = "a*"
> 输出: true
> 解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
> 
> 
> 示例 3: 
> 
> 输入:
> s = "ab"
> p = ".*"
> 输出: true
> 解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
> 
> 
> 示例 4: 
> 
> 输入:
> s = "aab"
> p = "c*a*b"
> 输出: true
> 解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
> 
> 
> 示例 5: 
> 
> 输入:
> s = "mississippi"
> p = "mis*is*p*."
> 输出: false 
> Related Topics 字符串 动态规划 回溯算法

## 题目代码

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        
    }
};
```

## 解析

这道求正则表达式匹配的题和那道 Wildcard Matching 的题很类似，不同点在于*的意义不同，在之前那道题中，*表示可以代替任意个数的字符，而这道题中的*表示之前那个字符可以有0个，1个或是多个，就是说，字符串 a*b，可以表示b或是 aaab，即a的个数任意，这道题的难度要相对之前那一道大一些，分的情况的要复杂一些，需要用递归 Recursion 来解，大概思路如下：

- 若p为空，若s也为空，返回 true，反之返回 false。

- 若p的长度为1，若s长度也为1，且相同或是p为 '.' 则返回 true，反之返回 false。

- 若p的第二个字符不为*，若此时s为空返回 false，否则判断首字符是否匹配，且从各自的第二个字符开始调用递归函数匹配。

- 若p的第二个字符为*，进行下列循环，条件是若s不为空且首字符匹配（包括 p[0] 为点），调用递归函数匹配s和去掉前两个字符的p（这样做的原因是假设此时的星号的作用是让前面的字符出现0次，验证是否匹配），若匹配返回 true，否则s去掉首字母（因为此时首字母匹配了，我们可以去掉s的首字母，而p由于星号的作用，可以有任意个首字母，所以不需要去掉），继续进行循环。

- 返回调用递归函数匹配s和去掉前两个字符的p的结果（这么做的原因是处理星号无法匹配的内容，比如 s="ab", p="a*b"，直接进入 while 循环后，我们发现 "ab" 和 "b" 不匹配，所以s变成 "b"，那么此时跳出循环后，就到最后的 return 来比较 "b" 和 "b" 了，返回 true。再举个例子，比如 s="", p="a*"，由于s为空，不会进入任何的 if 和 while，只能到最后的 return 来比较了，返回 true，正确）。

### 方法一

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        if (p.size() == 1) {
            return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));
        }
        if (p[1] != '*') {
            if (s.empty()) return false;
            return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }
        while (!s.empty() && (s[0] == p[0] || p[0] == '.')) {
            if (isMatch(s, p.substr(2))) return true;
            s = s.substr(1);
        }
        return isMatch(s, p.substr(2));
    }
};
```

### 方法二

上面的方法可以写的更加简洁一些，但是整个思路还是一样的，先来判断p是否为空，若为空则根据s的为空的情况返回结果。当p的第二个字符为*号时，由于*号前面的字符的个数可以任意，可以为0，那么我们先用递归来调用为0的情况，就是直接把这两个字符去掉再比较，或者当s不为空，且第一个字符和p的第一个字符相同时，再对去掉首字符的s和p调用递归，注意p不能去掉首字符，因为*号前面的字符可以有无限个；如果第二个字符不为*号，那么就老老实实的比较第一个字符，然后对后面的字符串调用递归，参见代码如下：

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        if (p.size() > 1 && p[1] == '*') {
            return isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p));
        } else {
            return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }
    }
};
```

### 方法三

我们也可以用 DP 来解，定义一个二维的 DP 数组，其中 dp[i][j] 表示 s[0,i) 和 p[0,j) 是否 match，然后有下面三种情况(下面部分摘自这个帖子)：

1.  P[i][j] = P[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
2.  P[i][j] = P[i][j - 2], if p[j - 1] == '*' and the pattern repeats for 0 times;
3.  P[i][j] = P[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), if p[j - 1] == '*' and the pattern repeats for at least 1 times.

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (j > 1 && p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                } else {
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[m][n];
    }
};
```

GitHub 同步地址：

https://github.com/grandyang/leetcode/issues/10



类似题目：

Wildcard Matching