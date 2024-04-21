using ll = long long;

class Solution {
public:
ll MOD = 1e9 + 7;
ll power(ll x, ll y)
{
    ll res = 1;     // Initialize result

    x = x % MOD; // Update x if it is more than or
                // equal to p

    if (x == 0) return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % MOD;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % MOD;
    }
    return res;
}
    int countGoodNumbers(long long n) {
        return (power(4, n/2) * power(5, n-n/2))%MOD;
    }
};