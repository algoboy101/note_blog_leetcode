---
title: "[0067] Add Binary"
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
date: 2020-01-01 00:01:07
---

## 题目描述

> 给定两个二进制字符串，返回他们的和（用二进制表示）。 
> 
> 输入为非空字符串且只包含数字 1 和 0。 
> 
> 示例 1: 
> 
> 输入: a = "11", b = "1"
> 输出: "100" 
> 
> 示例 2: 
> 
> 输入: a = "1010", b = "1011"
> 输出: "10101" 
> Related Topics 数学 字符串

## 题目代码

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        
    }
};
```

## 解析

### 方法一

二进制数相加，并且保存在string中，要注意的是如何将string和int之间互相转换，并且每位相加时，会有进位的可能，会影响之后相加的结果。而且两个输入string的长度也可能会不同。这时我们需要新建一个string，它的长度是两条输入string中的较大的那个，并且把较短的那个输入string通过在开头加字符‘0’来补的较大的那个长度。这时候我们逐个从两个string的末尾开始取出字符，然后转为数字，想加，如果大于等于2，则标记进位标志carry，并且给新string加入一个字符‘0’。代码如下：


```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int na = a.size();
        int nb = b.size();
        int n = max(na, nb);
        bool carry = false;
        if (na > nb) {
            for (int i = 0; i < na - nb; ++i) b.insert(b.begin(), '0');
        }
        else if (na < nb) {
            for (int i = 0; i < nb - na; ++i) a.insert(a.begin(), '0');
        }
        for (int i = n - 1; i >= 0; --i) {
            int tmp = 0;
            if (carry) tmp = (a[i] - '0') + (b[i] - '0') + 1;
            else tmp = (a[i] - '0') + (b[i] - '0');
            if (tmp == 0) {
                res.insert(res.begin(), '0');
                carry = false;
            }
            else if (tmp == 1) {
                res.insert(res.begin(), '1');
                carry = false;
            }
            else if (tmp == 2) {
                res.insert(res.begin(), '0');
                carry = true;
            }
            else if (tmp == 3) {
                res.insert(res.begin(), '1');
                carry = true;
            }
        }
        if (carry) res.insert(res.begin(), '1');
        return res;
    }
};
```

### 方法二

下面这种写法又巧妙又简洁，用了两个指针分别指向a和b的末尾，然后每次取出一个字符，转为数字，若无法取出字符则按0处理，然后定义进位carry，初始化为0，将三者加起来，对2取余即为当前位的数字，对2取商即为当前进位的值，记得最后还要判断下carry，如果为1的话，要在结果最前面加上一个1，参见代码如下：


```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int m = a.size() - 1, n = b.size() - 1, carry = 0;
        while (m >= 0 || n >= 0) {
            int p = m >= 0 ? a[m--] - '0' : 0;
            int q = n >= 0 ? b[n--] - '0' : 0;
            int sum = p + q + carry;
            res = to_string(sum % 2) + res;
            carry = sum / 2;
        }
        return carry == 1 ? "1" + res : res;
    }
}; 	
```



