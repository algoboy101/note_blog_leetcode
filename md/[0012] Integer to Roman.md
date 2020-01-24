---
title: "[0012] Integer to Roman"
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
date: 2020-01-01 00:00:12
---

## 题目描述

> 罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。 
> 
> 字符          数值
> I             1
> V             5
> X             10
> L             50
> C             100
> D             500
> M             1000 
> 
> 例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做 XXVII, 即为 XX + V + II 。 
> 
> 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况： 
> 
> 
> I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。 
> X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
> C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。 
> 
> 
> 给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。 
> 
> 示例 1: 
> 
> 输入: 3
> 输出: "III" 
> 
> 示例 2: 
> 
> 输入: 4
> 输出: "IV" 
> 
> 示例 3: 
> 
> 输入: 9
> 输出: "IX" 
> 
> 示例 4: 
> 
> 输入: 58
> 输出: "LVIII"
> 解释: L = 50, V = 5, III = 3.
> 
> 
> 示例 5: 
> 
> 输入: 1994
> 输出: "MCMXCIV"
> 解释: M = 1000, CM = 900, XC = 90, IV = 4. 
> Related Topics 数学 字符串

## 题目代码

```cpp
class Solution {
public:
    string intToRoman(int num) {
        
    }
};
```

## 解析

之前那篇文章写的是罗马数字转化成整数 Roman to Integer， 这次变成了整数转化成罗马数字，基本算法还是一样。由于题目中限定了输入数字的范围 (1 - 3999), 使得题目变得简单了不少。

I - 1

V - 5

X - 10

L - 50

C - 100 

D - 500

M - 1000

例如整数 1437 的罗马数字为 MCDXXXVII， 我们不难发现，千位，百位，十位和个位上的数分别用罗马数字表示了。 1000 - M, 400 - CD, 30 - XXX, 7 - VII。所以我们要做的就是用取商法分别提取各个位上的数字，然后分别表示出来：

100 - C

200 - CC

300 - CCC

400 - CD

500 - D

600 - DC

700 - DCC

800 - DCCC

900 - CM

可以分为四类，100 到 300 一类，400 一类，500 到 800 一类，900 最后一类。每一位上的情况都是类似的，代码如下：

### 方法一

```cpp
class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        vector<char> roman{'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        vector<int> value{1000, 500, 100, 50, 10, 5, 1};
        for (int n = 0; n < 7; n += 2) {
            int x = num / value[n];
            if (x < 4) {
                for (int i = 1; i <= x; ++i) res += roman[n];
            } else if (x == 4) {
                res = res + roman[n] + roman[n - 1]; 
            } else if (x > 4 && x < 9) {
                res += roman[n - 1];
                for (int i = 6; i <= x; ++i) res += roman[n];
            } else if (x == 9) {
                res = res + roman[n] + roman[n - 2];
            }
            num %= value[n];            
        }
        return res;
    }
};
```

### 方法二

本题由于限制了输入数字范围这一特殊性，故而还有一种利用贪婪算法的解法，建立一个数表，每次通过查表找出当前最大的数，减去再继续查表，参见代码如下：

```cpp
class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        vector<int> val{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> str{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        for (int i = 0; i < val.size(); ++i) {
            while (num >= val[i]) {
                num -= val[i];
                res += str[i];
            }
        }
        return res;
    }
};
```

### 方法三

下面这种方法个人感觉属于比较投机取巧的方法，把所有的情况都列了出来，然后直接按位查表，O(1) 的时间复杂度啊，参见代码如下：

```cpp
class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        vector<string> v1{"", "M", "MM", "MMM"};
        vector<string> v2{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> v3{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> v4{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return v1[num / 1000] + v2[(num % 1000) / 100] + v3[(num % 100) / 10] + v4[num % 10];
    }
};
```

Github 同步地址：

https://github.com/grandyang/leetcode/issues/12

 

类似题目：

Roman to Integer

Integer to English Words

