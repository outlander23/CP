#undef _GLIBCXX_DEBUG

#include <bits/stdc++.h>

// Generic to_string function
template <typename T>
string to_string(const T &value)
{
    ostringstream oss;
    oss << value;
    return oss.str();
}

// Overloads for special cases
template <typename A, typename B>
string to_string(const pair<A, B> &p)
{
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename... Args>
string to_string(const tuple<Args...> &t)
{
    return "(" + std::apply([](const auto &...args)
                            { return ((to_string(args) + ", ") + ...); },
                            t) +
           ")";
}

template <size_t N>
string to_string(const bitset<N> &bs)
{
    return bs.to_string();
}

template <typename T>
string to_string(const vector<T> &v)
{
    bool first = true;
    string res = "{";
    for (const auto &x : v)
    {
        if (!first)
            res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

// Print macro
#define print(...) cerr << "[" << #__VA_ARGS__ << "]: " << to_string(__VA_ARGS__) << endl
