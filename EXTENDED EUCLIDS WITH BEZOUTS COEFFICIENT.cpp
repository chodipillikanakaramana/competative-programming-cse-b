#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Extended Euclidean Algorithm
ll egcd(ll a, ll b, ll &x, ll &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }

    ll x1, y1;

    ll d = egcd(b % a, a, x1, y1);

    x = y1 - (b / a) * x1;
    y = x1;

    return d;
}

int main()
{
    ll A, B;
    cin >> A >> B;

    ll x, y;

    // Find one solution
    ll D = egcd(A, B, x, y);

    // All solutions:
    // x = x + k*(B/D)
    // y = y - k*(A/D)

    ll p = B / D;
    ll q = A / D;

    ll bestX = x;
    ll bestY = y;

    auto check = [&](ll k)
    {
        ll nx = x + k * p;
        ll ny = y - k * q;

        if (llabs(nx) + llabs(ny) <
            llabs(bestX) + llabs(bestY))
        {
            bestX = nx;
            bestY = ny;
        }
        else if (llabs(nx) + llabs(ny) ==
                 llabs(bestX) + llabs(bestY))
        {
            if (nx <= ny)
            {
                bestX = nx;
                bestY = ny;
            }
        }
    };

    // Minimum occurs near where x becomes 0
    ll k1 = -x / p;

    // Or where y becomes 0
    ll k2 = y / q;

    // Check nearby values
    for (ll k = k1 - 3; k <= k1 + 3; k++)
        check(k);

    for (ll k = k2 - 3; k <= k2 + 3; k++)
        check(k);

    cout << bestX << " " << bestY << " " << D;

    return 0;
}
