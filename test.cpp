#include <iostream>
#include <vector>
// Function to rotate a matrix in anti-clockwise direction
using namespace std;
void rotateMatrix(vector<vector<int>> &matrix, int N)
{

    for (int x = 0; x < N / 2; x++)
    {
        for (int y = x; y < N - x - 1; y++)
        {
            int temp = matrix[x][y];
            matrix[x][y] = matrix[y][N - 1 - x];
            matrix[y][N - 1 - x] = matrix[N - 1 - x][N - 1 - y];
            matrix[N - 1 - x][N - 1 - y] = matrix[N - 1 - y][x];
            matrix[N - 1 - y][x] = temp;
        }
    }
}

// Function to display the matrix
void displayMatrix(const vector<vector<int>> &matrix, int N)
{

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    // Fill the matrix with values based on the provided input
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char x;
            cin >> x;
            matrix[i][j] = x - 'a' + 1;
        }
    }
    displayMatrix(matrix, n);
    // Function call
    rotateMatrix(matrix, n);

    // Print rotated matrix
    displayMatrix(matrix, n);

    return 0;
}