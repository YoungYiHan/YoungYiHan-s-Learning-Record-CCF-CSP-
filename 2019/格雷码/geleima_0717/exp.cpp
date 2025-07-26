#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <iostream>

using namespace std;
typedef unsigned long long U;

string f(int n, U k)
{
    U mid = 1ULL << (n - 1);
    if (n <= 0)
    {
        return "";
    }
    else
    {
        if (k < mid)
        {
            return "0" + f(n - 1, k);
        }
        else
        {
            k = mid - (k - mid) - 1;
            return "1" + f(n - 1, k);
        }
    }
}


int main()
{
    int n = 0;
    U k = 1;
    scanf_s("%d%llu", &n, &k);
    cout << f(n, k);

    return 0;
}