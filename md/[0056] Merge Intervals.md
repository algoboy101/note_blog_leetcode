---
title: "[0056] Merge Intervals"
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
date: 2020-01-01 00:00:56
---

## 题目描述

> 给出一个区间的集合，请合并所有重叠的区间。 
> 
> 示例 1: 
> 
> 输入: [[1,3],[2,6],[8,10],[15,18]]
> 输出: [[1,6],[8,10],[15,18]]
> 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
> 
> 
> 示例 2: 
> 
> 输入: [[1,4],[4,5]]
> 输出: [[1,5]]
> 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。 
> Related Topics 排序 数组

## 题目代码

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
    }
};
```

## 解析

### 方法一

这道和之前那道 Insert Interval 很类似，这次题目要求我们合并区间，之前那题明确了输入区间集是有序的，而这题没有，所以我们首先要做的就是给区间集排序，由于我们要排序的是个结构体，所以我们要定义自己的 comparator，才能用 sort 来排序，我们以 start 的值从小到大来排序，排完序我们就可以开始合并了，首先把第一个区间存入结果中，然后从第二个开始遍历区间集，如果结果中最后一个区间和遍历的当前区间无重叠，直接将当前区间存入结果中，如果有重叠，将结果中最后一个区间的 end 值更新为结果中最后一个区间的 end 和当前 end 值之中的较大值，然后继续遍历区间集，以此类推可以得到最终结果，代码如下：



```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res{intervals[0]};
        for (int i = 1; i < intervals.size(); ++i) {
            if (res.back()[1] < intervals[i][0]) {
                res.push_back(intervals[i]);
            } else {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }   
        return res;
    }
};
```

### 方法二

下面这种解法将起始位置和结束位置分别存到了两个不同的数组 starts 和 ends 中，然后分别进行排序，之后用两个指针i和j，初始化时分别指向 starts 和 ends 数组的首位置，然后如果i指向 starts 数组中的最后一个位置，或者当 starts 数组上 i+1 位置上的数字大于 ends 数组的i位置上的数时，此时说明区间已经不连续了，我们来看题目中的例子，排序后的 starts 和 ends 为：

starts:    1    2    8    15

ends:     3    6    10    18

红色为i的位置，蓝色为j的位置，那么此时 starts[i+1] 为8，ends[i] 为6，8大于6，所以此时不连续了，将区间 [starts[j], ends[i]]，即 [1, 6] 加入结果 res 中，然后j赋值为 i+1 继续循环，参见代码如下：

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> res;
        vector<int> starts, ends;
        for (int i = 0; i < n; ++i) {
            starts.push_back(intervals[i][0]);
            ends.push_back(intervals[i][1]);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        for (int i = 0, j = 0; i < n; ++i) {
            if (i == n - 1 || starts[i + 1] > ends[i]) {
                res.push_back({starts[j], ends[i]});
                j = i + 1;
            }
        } 
        return res;
    }
};
```

### 方法三

这道题还有另一种解法，这个解法直接调用了之前那道题 Insert Interval 的函数，由于插入的过程中也有合并的操作，所以我们可以建立一个空的集合，然后把区间集的每一个区间当做一个新的区间插入结果中，也可以得到合并后的结果，那道题中的四种解法都可以在这里使用，但是没必要都列出来，这里只选了那道题中的解法二放到这里，代码如下：



```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        for (int i = 0; i < intervals.size(); ++i) {
            res = insert(res, intervals[i]);
        }
        return res;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int> newInterval) {
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

Github 同步地址：

https://github.com/grandyang/leetcode/issues/56

 

类似题目：

Employee Free Time

Insert Interval

Meeting Rooms II

Meeting Rooms

Teemo Attacking

Add Bold Tag in String

Range Module

Partition Labels

Interval List Intersections