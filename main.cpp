#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

typedef long long LL;
const long MAXSA = 1e5 + 10;
LL A[MAXSA];
long n;
LL k;

bool chk(LL tp)
{
    LL cnt = 0, t;
    for (long i = 0; i < n; ++i)
    {
        LL diff = A[i] - tp;
        if (diff <= 0) return true;
        t = diff / k + ((diff % k == 0) ? 0 : 1);
        cnt += t;
        if (cnt > tp) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n)
    {
        for (long i = 0; i < n; ++i)
            cin >> A[i];
        sort(A, A + n, greater<LL>());
        cin >> k;
        if (k <= 1)
        {
            cout << A[0] << endl;
            continue;
        }
        --k;
        LL tp = 0;
        LL b = 0, e = A[0], ans = 0;
        while (b <= e)
        {
            tp = (b + e) >> 1;
            if (chk(tp))
                ans = tp,
                e = tp - 1;
            else
                b = tp + 1;
        }
        cout << ans << endl;
    }

    return 0;
}