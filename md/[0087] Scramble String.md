---
title: "[0087] Scramble String"
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
date: 2020-01-01 00:01:27
---

## 题目描述

> 给定一个字符串 s1，我们可以把它递归地分割成两个非空子字符串，从而将其表示为二叉树。 
> 
> 下图是字符串 s1 = "great" 的一种可能的表示形式。 
> 
> great
> /    \
> gr    eat
> / \    /  \
> g   r  e   at
> / \
> a   t
> 
> 
> 在扰乱这个字符串的过程中，我们可以挑选任何一个非叶节点，然后交换它的两个子节点。 
> 
> 例如，如果我们挑选非叶节点 "gr" ，交换它的两个子节点，将会产生扰乱字符串 "rgeat" 。 
> 
> rgeat
> /    \
> rg    eat
> / \    /  \
> r   g  e   at
> / \
> a   t
> 
> 
> 我们将 "rgeat” 称作 "great" 的一个扰乱字符串。 
> 
> 同样地，如果我们继续交换节点 "eat" 和 "at" 的子节点，将会产生另一个新的扰乱字符串 "rgtae" 。 
> 
> rgtae
> /    \
> rg    tae
> / \    /  \
> r   g  ta  e
> / \
> t   a
> 
> 
> 我们将 "rgtae” 称作 "great" 的一个扰乱字符串。 
> 
> 给出两个长度相等的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。 
> 
> 示例 1: 
> 
> 输入: s1 = "great", s2 = "rgeat"
> 输出: true
> 
> 
> 示例 2: 
> 
> 输入: s1 = "abcde", s2 = "caebd"
> 输出: false 
> Related Topics 字符串 动态规划

## 题目代码

```cpp
class Solution {
public:
    bool isScramble(string s1, string s2) {
        
    }
};
```

## 解析

### 方法一

这道题定义了一种搅乱字符串，就是说假如把一个字符串当做一个二叉树的根，然后它的非空子字符串是它的子节点，然后交换某个子字符串的两个子节点，重新爬行回去形成一个新的字符串，这个新字符串和原来的字符串互为搅乱字符串。这道题可以用递归 Recursion 或是动态规划 Dynamic Programming 来做，我们先来看递归的解法，参见网友 uniEagle 的博客，简单的说，就是 s1 和 s2 是 scramble 的话，那么必然存在一个在 s1 上的长度 l1，将 s1 分成 s11 和 s12 两段，同样有 s21 和 s22，那么要么 s11 和 s21 是 scramble 的并且 s12 和 s22 是 scramble 的；要么 s11 和 s22 是 scramble 的并且 s12 和 s21 是 scramble 的。就拿题目中的例子 rgeat 和 great 来说，rgeat 可分成 rg 和 eat 两段， great 可分成 gr 和 eat 两段，rg 和 gr 是 scrambled 的， eat 和 eat 当然是 scrambled。根据这点，我们可以写出代码如下：



```cpp
// Recursion
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        string str1 = s1, str2 = s2;
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        if (str1 != str2) return false;
        for (int i = 1; i < s1.size(); ++i) {
            string s11 = s1.substr(0, i);
            string s12 = s1.substr(i);
            string s21 = s2.substr(0, i);
            string s22 = s2.substr(i);
            if (isScramble(s11, s21) && isScramble(s12, s22)) return true;
            s21 = s2.substr(s1.size() - i);
            s22 = s2.substr(0, s1.size() - i);
            if (isScramble(s11, s21) && isScramble(s12, s22)) return true;
        }
        return false;
    }
};
```

### 方法二

当然，这道题也可以用动态规划 Dynamic Programming，根据以往的经验来说，根字符串有关的题十有八九可以用 DP 来做，那么难点就在于如何找出状态转移方程。参见网友 Code Ganker 的博客，这其实是一道三维动态规划的题目，使用一个三维数组 dp[i][j][n]，其中i是 s1 的起始字符，j是 s2 的起始字符，而n是当前的字符串长度，dp[i][j][len] 表示的是以i和j分别为 s1 和 s2 起点的长度为 len 的字符串是不是互为 scramble。有了 dp 数组接下来看看状态转移方程，也就是怎么根据历史信息来得到 dp[i][j][len]。判断这个是不是满足，首先是把当前 s1[i...i+len-1] 字符串劈一刀分成两部分，然后分两种情况：第一种是左边和 s2[j...j+len-1] 左边部分是不是 scramble，以及右边和 s2[j...j+len-1] 右边部分是不是 scramble；第二种情况是左边和 s2[j...j+len-1] 右边部分是不是 scramble，以及右边和 s2[j...j+len-1] 左边部分是不是 scramble。如果以上两种情况有一种成立，说明 s1[i...i+len-1] 和 s2[j...j+len-1] 是 scramble 的。而对于判断这些左右部分是不是 scramble 是有历史信息的，因为长度小于n的所有情况都在前面求解过了（也就是长度是最外层循环）。上面说的是劈一刀的情况，对于 s1[i...i+len-1] 有 len-1 种劈法，在这些劈法中只要有一种成立，那么两个串就是 scramble 的。总结起来状态转移方程是：

dp[i][j][len] = || (dp[i][j][k] && dp[i+k][j+k][len-k] || dp[i][j+len-k][k] && dp[i+k][j][len-k])

对于所有 1<=k<len，也就是对于所有 len-1 种劈法的结果求或运算。因为信息都是计算过的，对于每种劈法只需要常量操作即可完成，因此求解递推式是需要 O(len)（因为 len-1 种劈法）。如此总时间复杂度因为是三维动态规划，需要三层循环，加上每一步需要线行时间求解递推式，所以是 O(n^4)。虽然已经比较高了，但是至少不是指数量级的，动态规划还是有很大优势的，空间复杂度是 O(n^3)。代码如下：

```cpp
// DP
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        int n = s1.size();
        vector<vector<vector<bool>>> dp (n, vector<vector<bool>>(n, vector<bool>(n + 1)));
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                for (int j = 0; j <= n - len; ++j) {
                    if (len == 1) {
                        dp[i][j][1] = s1[i] == s2[j];
                    } else {
                        for (int k = 1; k < len; ++k) {
                            if ((dp[i][j][k] && dp[i + k][j + k][len - k]) || (dp[i + k][j][len - k] && dp[i][j + len - k][k])) {
                                dp[i][j][len] = true;
                            }
                        }
                    }                
                }
            }
        }
        return dp[0][0][n];
    }
};
```

### 方法三

上面的代码的实现过程如下，首先按单个字符比较，判断它们之间是否是 scrambled 的。在更新第二个表中第一个值 (gr 和 rg 是否为 scrambled 的)时，比较了第一个表中的两种构成，一种是 g与r, r与g，另一种是 g与g, r与r，其中后者是真，只要其中一个为真，则将该值赋真。其实这个原理和之前递归的原理很像，在判断某两个字符串是否为 scrambled 时，比较它们所有可能的拆分方法的子字符串是否是 scrambled 的，只要有一个种拆分方法为真，则比较的两个字符串一定是 scrambled 的。比较 rge 和 gre 的实现过程如下所示：

复制代码
     r    g    e
g    x    √    x
r    √    x    x
e    x    x    √


     rg    ge
gr    √    x
re    x    x


     rge
gre   √
复制代码
 

DP 的另一种写法，参考网友加载中..的博客，思路都一样，代码如下：

```cpp
// Still DP
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        int n = s1.size();
        vector<vector<vector<bool>>> dp (n, vector<vector<bool>>(n, vector<bool>(n + 1)));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                for (int k = 1; k <= n - max(i, j); ++k) {
                    if (s1.substr(i, k) == s2.substr(j, k)) {
                        dp[i][j][k] = true;
                    } else {
                        for (int t = 1; t < k; ++t) {
                            if ((dp[i][j][t] && dp[i + t][j + t][k - t]) || (dp[i][j + k - t][t] && dp[i + t][j][k - t])) {
                                dp[i][j][k] = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};
```

Github 同步地址：

https://github.com/grandyang/leetcode/issues/87

 