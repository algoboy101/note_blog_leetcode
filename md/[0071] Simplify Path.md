---
title: "[0071] Simplify Path"
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
date: 2020-01-01 00:01:11
---

## 题目描述

> 以 Unix 风格给出一个文件的绝对路径，你需要简化它。或者换句话说，将其转换为规范路径。 
> 
> 在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。更多信息请参阅：Linux / Unix中的绝对路径 vs 相对路径 
> 
> 请注意，返回的规范路径必须始终以斜杠 / 开头，并且两个目录名之间必须只有一个斜杠 /。最后一个目录名（如果存在）不能以 / 结尾。此外，规范路径必须是表示绝对路径的最短字符串。 
> 
> 
> 
> 示例 1： 
> 
> 输入："/home/"
> 输出："/home"
> 解释：注意，最后一个目录名后面没有斜杠。
> 
> 
> 示例 2： 
> 
> 输入："/../"
> 输出："/"
> 解释：从根目录向上一级是不可行的，因为根是你可以到达的最高级。
> 
> 
> 示例 3： 
> 
> 输入："/home//foo/"
> 输出："/home/foo"
> 解释：在规范路径中，多个连续斜杠需要用一个斜杠替换。
> 
> 
> 示例 4： 
> 
> 输入："/a/./b/../../c/"
> 输出："/c"
> 
> 
> 示例 5： 
> 
> 输入："/a/../../b/../c//.//"
> 输出："/c"
> 
> 
> 示例 6： 
> 
> 输入："/a//b////c/d//././/.."
> 输出："/a/b/c" 
> Related Topics 栈 字符串

## 题目代码

```cpp
class Solution {
public:
    string simplifyPath(string path) {
        
    }
};
```

## 解析

### 方法一

这道题让简化给定的路径，光根据题目中给的那一个例子还真不太好总结出规律，应该再加上两个例子 path = "/a/./b/../c/", => "/a/c"和path = "/a/./b/c/", => "/a/b/c"， 这样我们就可以知道中间是"."的情况直接去掉，是".."时删掉它上面挨着的一个路径，而下面的边界条件给的一些情况中可以得知，如果是空的话返回"/"，如果有多个"/"只保留一个。那么我们可以把路径看做是由一个或多个"/"分割开的众多子字符串，把它们分别提取出来一一处理即可，代码如下：



```cpp
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        int i = 0;
        while (i < path.size()) {
            while (path[i] == '/' && i < path.size()) ++i;
            if (i == path.size()) break;
            int start = i;
            while (path[i] != '/' && i < path.size()) ++i;
            int end = i - 1;
            string s = path.substr(start, end - start + 1);
            if (s == "..") {
                if (!v.empty()) v.pop_back(); 
            } else if (s != ".") {
                v.push_back(s);
            }
        }
        if (v.empty()) return "/";
        string res;
        for (int i = 0; i < v.size(); ++i) {
            res += '/' + v[i];
        }
        return res;
    }
};
```

### 方法二

还有一种解法是利用了C语言中的函数strtok来分隔字符串，但是需要把string和char*类型相互转换，转换方法请猛戳这里。除了这块不同，其余的思想和上面那种解法相同，代码如下：


```cpp
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        char *cstr = new char[path.length() + 1];
        strcpy(cstr, path.c_str());
        char *pch = strtok(cstr, "/");
        while (pch != NULL) {
            string p = string(pch);
            if (p == "..") {
                if (!v.empty()) v.pop_back();
            } else if (p != ".") {
                v.push_back(p);
            }
            pch = strtok(NULL, "/");
        }
        if (v.empty()) return "/";
        string res;
        for (int i = 0; i < v.size(); ++i) {
            res += '/' + v[i];
        }
        return res;
    }
}; 
```

### 方法三

C++中也有专门处理字符串的机制，我们可以使用stringstream来分隔字符串，然后对每一段分别处理，思路和上面的方法相似，参见代码如下：


```cpp
class Solution {
public:
    string simplifyPath(string path) {
        string res, t;
        stringstream ss(path);
        vector<string> v;
        while (getline(ss, t, '/')) {
            if (t == "" || t == ".") continue;
            if (t == ".." && !v.empty()) v.pop_back();
            else if (t != "..") v.push_back(t);
        }
        for (string s : v) res += "/" + s;
        return res.empty() ? "/" : res;
    }
};
```

