#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef unsigned long long ULL;

int n, m, c, k;
bool f[64] = { }; //Ĭ��ȫ����ʼ��ΪFalse

int main() {
    scanf_s("%d %d %d %d", &n, &m, &c, &k);
    ULL sum = 0;
    // ��ȷ��Щλ�����ʹ�ù�
    for (int i = 0; i < n; i++)
    {
        ULL x;
        scanf_s("%llu", &x);
        sum |= x;
    }
    // ͳ�������ж���λ������
    int a = k;
    int p, q = 0;
    int temp = 0;
    for (int i = 0; i < m; i++)
    {
        scanf_s("%d %d", &p, &q);
        temp = (sum >> p & 1); // 0 -> ��ʾ��������,����λû�б�Ź�
        if (!temp && !f[p])
        {
            a--;
            f[p] = true;
        }
    }
    // ����ֿ����ۣ���Ϊ������������
    // unsigned long long��ULL���� 64 λ �޷�������������ܱ�ʾ 2^64 - 1
    if (a == 64) {
        if (n == 0) puts("18446744073709551616");  // 2^64
        else printf("%llu\n", (~0ull) - (n - 1));  // ~0ull ��ʾ2^64 - 1
    }
    else {
        printf("%llu\n", (1ull << a) - n);  // 2^a - n, �������
    }
}