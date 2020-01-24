---
title: "[0020] Valid Parentheses"
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
date: 2020-01-01 00:00:20
---

## 题目描述

> 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。 
> 
> 有效字符串需满足： 
> 
> 
> 左括号必须用相同类型的右括号闭合。 
> 左括号必须以正确的顺序闭合。 
> 
> 
> 注意空字符串可被认为是有效字符串。 
> 
> 示例 1: 
> 
> 输入: "()"
> 输出: true
> 
> 
> 示例 2: 
> 
> 输入: "()[]{}"
> 输出: true
> 
> 
> 示例 3: 
> 
> 输入: "(]"
> 输出: false
> 
> 
> 示例 4: 
> 
> 输入: "([)]"
> 输出: false
> 
> 
> 示例 5: 
> 
> 输入: "{[]}"
> 输出: true 
> Related Topics 栈 字符串

## 题目代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        
    }
};
```

## 解析

这道题让我们验证输入的字符串是否为括号字符串，包括大括号，中括号和小括号。这里需要用一个栈，开始遍历输入字符串，如果当前字符为左半边括号时，则将其压入栈中，如果遇到右半边括号时，若此时栈为空，则直接返回 false，如不为空，则取出栈顶元素，若为对应的左半边括号，则继续循环，反之返回 false，代码如下：

### 方法一

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') parentheses.push(s[i]);
            else {
                if (parentheses.empty()) return false;
                if (s[i] == ')' && parentheses.top() != '(') return false;
                if (s[i] == ']' && parentheses.top() != '[') return false;
                if (s[i] == '}' && parentheses.top() != '{') return false;
                parentheses.pop();
            }
        }
        return parentheses.empty();
    }
};
```

Github 同步地址：

https://github.com/grandyang/leetcode/issues/20

 

类似题目：

Remove Invalid Parentheses

Different Ways to Add Parentheses

Longest Valid Parentheses

Generate Parentheses

Check If Word Is Valid After Substitutions
