//Employee 表保存了一年内的薪水信息。 
//
// 请你编写 SQL 语句，来查询一个员工三个月内的累计薪水，但是不包括最近一个月的薪水。 
//
// 结果请按 'Id' 升序，然后按 'Month' 降序显示。 
//
// 示例： 
//输入： 
//
// | Id | Month | Salary |
//|----|-------|--------|
//| 1  | 1     | 20     |
//| 2  | 1     | 20     |
//| 1  | 2     | 30     |
//| 2  | 2     | 30     |
//| 3  | 2     | 40     |
//| 1  | 3     | 40     |
//| 3  | 3     | 60     |
//| 1  | 4     | 60     |
//| 3  | 4     | 70     |
// 
//
// 输出： 
//
// | Id | Month | Salary |
//|----|-------|--------|
//| 1  | 3     | 90     |
//| 1  | 2     | 50     |
//| 1  | 1     | 20     |
//| 2  | 1     | 20     |
//| 3  | 3     | 100    |
//| 3  | 2     | 40     |
// 
//
// 
//
// 解释： 
//
// 员工 '1' 除去最近一个月（月份 '4'），有三个月的薪水记录：月份 '3' 薪水为 40，月份 '2' 薪水为 30，月份 '1' 薪水为 20。 
//
// 所以近 3 个月的薪水累计分别为 (40 + 30 + 20) = 90，(30 + 20) = 50 和 20。 
//
// | Id | Month | Salary |
//|----|-------|--------|
//| 1  | 3     | 90     |
//| 1  | 2     | 50     |
//| 1  | 1     | 20     |
// 
//
// 员工 '2' 除去最近的一个月（月份 '2'）的话，只有月份 '1' 这一个月的薪水记录。 
//
// | Id | Month | Salary |
//|----|-------|--------|
//| 2  | 1     | 20     |
// 
//
// 员工 '3' 除去最近一个月（月份 '4'）后有两个月，分别为：月份 '4' 薪水为 60 和 月份 '2' 薪水为 40。所以各月的累计情况如下： 
//
// | Id | Month | Salary |
//|----|-------|--------|
//| 3  | 3     | 100    |
//| 3  | 2     | 40     |
// 
//
// 
//

${question.code}