class PolynomialHashing
{
    int base, mod;
    vector<int> power, hash;

public:
    PolynomialHashing(int base = 181, int mod = 1e9 + 7) : base(base), mod(mod)
    {
        power.push_back(1);
        hash.push_back(0);
    }
    void add_string(string &s)
    {
        for (auto c : s)
            add(c);
    }

    void add(int c)
    {
        hash.push_back(((hash.back() * base) % mod + c) % mod);
        power.push_back((power.back() * base) % mod);
    }

    int hashvalue()
    {
        return hash.back();
    }

    int changeInPos(int pos, int c)
    {
        int old = hash.back();
        int posChar = (get(pos, pos) * power[power.size() - pos - 1]) % mod;
        old -= posChar;
        if (old < 0)
            old += mod;
        old = (old + (c * power[power.size() - pos - 1]) % mod) % mod;

        return old;
    }

    int get(int l, int r)
    {
        return (hash[r] - hash[l - 1] * power[r - l + 1] % mod + mod) % mod;
    }

    int getpower(int n)
    {
        return power[n];
    }
};
