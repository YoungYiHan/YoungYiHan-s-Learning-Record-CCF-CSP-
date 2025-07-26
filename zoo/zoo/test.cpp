#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef unsigned long long ULL;

int n, m, c, k;
bool f[64] = { }; //默认全部初始化为False

int main() {
    scanf_s("%d %d %d %d", &n, &m, &c, &k);
    ULL sum = 0;
    // 明确哪些位被编号使用过
    for (int i = 0; i < n; i++)
    {
        ULL x;
        scanf_s("%llu", &x);
        sum |= x;
    }
    // 统计现在有多少位可以用
    int a = k;
    int p, q = 0;
    int temp = 0;
    for (int i = 0; i < m; i++)
    {
        scanf_s("%d %d", &p, &q);
        temp = (sum >> p & 1); // 0 -> 表示规则上有,且这位没有编号过
        if (!temp && !f[p])
        {
            a--;
            f[p] = true;
        }
    }
    // 结果分开讨论，因为考虑溢出的情况
    // unsigned long long（ULL）是 64 位 无符号整数，最大能表示 2^64 - 1
    if (a == 64) {
        if (n == 0) puts("18446744073709551616");  // 2^64
        else printf("%llu\n", (~0ull) - (n - 1));  // ~0ull 表示2^64 - 1
    }
    else {
        printf("%llu\n", (1ull << a) - n);  // 2^a - n, 不会溢出
    }
}