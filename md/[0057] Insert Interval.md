---
title: "[0057] Insert Interval"
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
date: 2020-01-01 00:00:57
---

## 题目描述

> 给出一个无重叠的 ，按照区间起始端点排序的区间列表。 
> 
> 在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。 
> 
> 示例 1: 
> 
> 输入: intervals = [[1,3],[6,9]], newInterval = [2,5]
> 输出: [[1,5],[6,9]]
> 
> 
> 示例 2: 
> 
> 输入: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
> 输出: [[1,2],[3,10],[12,16]]
> 解释: 这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
> 
> Related Topics 排序 数组

## 题目代码

```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
    }
};
```

## 解析

### 方法一

这道题让我们在一系列非重叠的区间中插入一个新的区间，可能还需要和原有的区间合并，可以对给定的区间集进行一个一个的遍历比较，那么会有两种情况，重叠或是不重叠，不重叠的情况最好，直接将新区间插入到对应的位置即可，重叠的情况比较复杂，有时候会有多个重叠，需要更新新区间的范围以便包含所有重叠，之后将新区间加入结果 res，最后将后面的区间再加入结果 res 即可。具体思路是，用一个变量 cur 来遍历区间，如果当前 cur 区间的结束位置小于要插入的区间的起始位置的话，说明没有重叠，则将 cur 区间加入结果 res 中，然后 cur 自增1。直到有 cur 越界或有重叠 while 循环退出，然后再用一个 while 循环处理所有重叠的区间，每次用取两个区间起始位置的较小值，和结束位置的较大值来更新要插入的区间，然后 cur 自增1。直到 cur 越界或者没有重叠时 while 循环退出。之后将更新好的新区间加入结果 res，然后将 cur 之后的区间再加入结果 res 中即可，参见代码如下：

```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size(), cur = 0;
        while (cur < n && intervals[cur][1] < newInterval[0]) {
            res.push_back(intervals[cur++]);
        }
        while (cur < n && intervals[cur][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[cur][0]);
            newInterval[1] = max(newInterval[1], intervals[cur][1]);
            ++cur;
        }
        res.push_back(newInterval);
        while (cur < n) {
            res.push_back(intervals[cur++]);
        }
        return res;
    }
};
```

### 方法二

下面这种方法的思路跟上面的解法很像，只不过没有用 while 循环，而是使用的是 for 循环，但是思路上没有太大的区别，变量 cur 还是用来记录新区间该插入的位置，稍有不同的地方在于在 for 循环中已经将新区间后面不重叠的区间也加进去了，for 循环结束后就只需要插入新区间即可，参见代码如下：



```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size(), cur = 0;
        for (int i = 0; i < n; ++i) {
            if (intervals[i][1] < newInterval[0]) {
                res.push_back(intervals[i]);
                ++cur;
            } else if (intervals[i][0] > newInterval[1]) {
                res.push_back(intervals[i]);
            } else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        res.insert(res.begin() + cur, newInterval);
        return res;
    }
};
```

### 方法三

下面这种解法就是把上面解法的 for 循环改为了 while 循环，其他的都没有变，代码如下：



```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size(), cur = 0, i = 0;
        while (i < n) {
            if (intervals[i][1] < newInterval[0]) {
                res.push_back(intervals[i]);
                ++cur;
            } else if (intervals[i][0] > newInterval[1]) {
                res.push_back(intervals[i]);
            } else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
            ++i;
        }
        res.insert(res.begin() + cur, newInterval);
        return res;
    }
};
```



Github 同步地址：

https://github.com/grandyang/leetcode/issues/57

 

类似题目：

Range Module

Merge Intervals