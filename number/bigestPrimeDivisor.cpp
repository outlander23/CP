int big[n + 1] = {1, 1};
for (int i = 1; i <= n; ++i)
    if (big[i] == 1)
        for (int j = i; j <= n; j += i)
            big[j] = i;