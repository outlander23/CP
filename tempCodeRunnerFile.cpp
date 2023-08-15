
// int query(int x)
// {
//     int ans = 0;

//     Trie *curr = root;

//     for (int i = 30; i >= 0; i--)
//     {
//         int bit = (x >> i) & 1;
//         if (curr->child[bit])
//         {
//             curr = curr->child[bit];
//         }
//         else
//         {
//             return ans;
//         }
//     }

//     return ans;
// }