class PolynomialHashing
{
    int base, mod, n;
    vector<int> power, hash, revhash;

public:
    PolynomialHashing(int base = 181, int mod = 1e9 + 7) : base(base), mod(mod)
    {
        hash.push_back(0);
        power.push_back(1);
        revhash.push_back(0);
    }
    void add_string(string &s)
    {

        int sz = s.size();
        n = s.size();
        for (int i = 0; i < n; i++)
        {
            addrev(s[sz - i - 1]);
            add(s[i]);
        }
    }
    void add(int c)
    {
        hash.push_back(((hash.back() * base) % mod + c) % mod);
        power.push_back((power.back() * base) % mod);
    }
    void addrev(int c)
    {
        revhash.push_back(((revhash.back() * base) % mod + c) % mod);
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
    int getrev(int l, int r)
    {
        return (revhash[r] - revhash[l - 1] * power[r - l + 1] % mod + mod) % mod;
    }

    int is_pal(int i, int j)
    {
        return h1.get(i, j) == h1.getrev(n - j + 1, n - i + 1) and
               h2.get(i, j) == h2.getrev(n - j + 1, n - i + 1);
    };

    int getpower(int n)
    {
        return power[n];
    }

    void clear()
    {
        power.clear();
        hash.clear();
        power.push_back(1);
        hash.push_back(0);
    }
};

PolynomialHashing h1(base1, mod1),
    h2(base2, mod2);
