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

typedef long long LONG;
typedef long INT;
const INT MAXSA = 1e5 + 10;
LONG A[MAXSA];
INT n;
LONG k;

inline bool chk(LONG tp)
{
    LONG cnt = 0;
    for (INT i = 0; i < n; ++i)
    {
        //if (A[i] <= tp) continue;
        LONG diff = A[i] - tp;
        if (diff <= 0) return true;
        cnt += (diff - 1) / k + 1;
        if (cnt > tp) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (!cin.eof() && cin >> n)
    {
        //int mx = 0;
        for (INT i = 0; i < n; ++i)
        {
            cin >> A[i];
            //if (A[i] > mx) mx = A[i];
        }
        sort(A, A + n, greater<LONG>());
        cin >> k;
        if (k <= 1)
        {
            cout << A[0] << endl;
            //cout << mx << endl;
            continue;
        }
        --k;
        LONG tp = 0;
        LONG b = 1, e = A[0];
        while (b <= e)
        {
            tp = (b + e) >> 1;
            if (chk(tp))
                e = tp - 1;
            else
                b = tp + 1;
        }
        cout << b << endl;
    }

    return 0;
}