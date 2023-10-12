int sumdiv[n + 1];
for (int i = 1; i <= n; ++i)
    for (int j = i; j <= n; j += i)
        sumdiv[j] += i;