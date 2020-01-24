---
title: "[0022] Generate Parentheses"
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
date: 2020-01-01 00:00:22
---

## 题目描述

> 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。 
> 
> 例如，给出 n = 3，生成结果为： 
> 
> [
> "((()))",
> "(()())",
> "(())()",
> "()(())",
> "()()()"
> ]
> 
> Related Topics 字符串 回溯算法

## 题目代码

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
    }
};
```

## 解析

在 LeetCode 中有关括号的题共有七道，除了这一道的另外六道是 Score of Parentheses，Valid Parenthesis String， Remove Invalid Parentheses，Different Ways to Add Parentheses，Valid Parentheses 和 Longest Valid Parentheses。这道题给定一个数字n，让生成共有n个括号的所有正确的形式，对于这种列出所有结果的题首先还是考虑用递归 Recursion 来解，由于字符串只有左括号和右括号两种字符，而且最终结果必定是左括号3个，右括号3个，所以这里定义两个变量 left 和 right 分别表示剩余左右括号的个数，如果在某次递归时，左括号的个数大于右括号的个数，说明此时生成的字符串中右括号的个数大于左括号的个数，即会出现 ')(' 这样的非法串，所以这种情况直接返回，不继续处理。如果 left 和 right 都为0，则说明此时生成的字符串已有3个左括号和3个右括号，且字符串合法，则存入结果中后返回。如果以上两种情况都不满足，若此时 left 大于0，则调用递归函数，注意参数的更新，若 right 大于0，则调用递归函数，同样要更新参数，参见代码如下：

### 方法一

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParenthesisDFS(n, n, "", res);
        return res;
    }
    void generateParenthesisDFS(int left, int right, string out, vector<string> &res) {
        if (left > right) return;
        if (left == 0 && right == 0) res.push_back(out);
        else {
            if (left > 0) generateParenthesisDFS(left - 1, right, out + '(', res);
            if (right > 0) generateParenthesisDFS(left, right - 1, out + ')', res);
        }
    }
};
```

### 方法二

再来看那一种方法，这种方法是 CareerCup 书上给的方法，感觉也是满巧妙的一种方法，这种方法的思想是找左括号，每找到一个左括号，就在其后面加一个完整的括号，最后再在开头加一个 ()，就形成了所有的情况，需要注意的是，有时候会出现重复的情况，所以用set数据结构，好处是如果遇到重复项，不会加入到结果中，最后我们再把set转为vector即可，参见代码如下：：

n＝1:    ()

```cpp

```

### 方法三

```cpp

```

