**7-9 Number Sequence**

A number sequence is defined as follows:

f(1) = 1, f(2) = 1, f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7.

Given A, B, and n, you are to calculate the value of f(n).

### 输入格式:

The input consists of multiple test cases. Each test case contains 3 integers A, B and n on a single line (1 <= A, B <= 1000, 1 <= n <= 100,000,000). Three zeros signal the end of input and this test case is not to be processed.

### 输出格式:

For each test case, print the value of f(n) on a single line.

### 输入样例:

```in
1 1 3
1 2 10
0 0 0
```

### 输出样例:

```out
2
5
```

```
代码长度限制 		16 KB
时间限制 			400 ms
内存限制 			64 MB
```

