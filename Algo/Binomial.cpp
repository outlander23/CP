
class BinomialCoefficients
{
    const int MOD;       // modulo value
    vector<int> fact;    // vector to store factorials
    vector<int> invfact; // vector to store inverse factorials
public:
    BinomialCoefficients(int n, int mod) : MOD(mod)
    { // constructor that precomputes factorials and inverse factorials
        fact.resize(n + 1);
        invfact.resize(n + 1);

        fact[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            fact[i] = (1LL * fact[i - 1] * i) % MOD;
        }

        invfact[n] = inverse(fact[n]);
        for (int i = n - 1; i >= 0; i--)
        {
            invfact[i] = (1LL * invfact[i + 1] * (i + 1)) % MOD;
        }
    }

    int inverse(int x)
    { // function to compute the inverse of a number modulo MOD using Fermat's Little Theorem
        int exp = MOD - 2;
        int res = 1;
        while (exp > 0)
        {
            if (exp % 2 == 1)
            {
                res = (1LL * res * x) % MOD;
            }
            x = (1LL * x * x) % MOD;
            exp /= 2;
        }
        return res;
    }

    int nCr(int n, int r) const
    { // overloaded operator to return coefficient (n choose r)
        if (r < 0 || r > n)
        {
            return 0;
        }
        return (1LL * fact[n] * invfact[r] % MOD * invfact[n - r] % MOD);
    }
};