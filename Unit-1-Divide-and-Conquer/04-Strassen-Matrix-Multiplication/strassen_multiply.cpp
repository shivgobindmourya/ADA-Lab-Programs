#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> addMatrix(const vector<vector<int>>& A,
                              const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    return C;
}

vector<vector<int>> subtractMatrix(const vector<vector<int>>& A,
                                   const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }

    return C;
}

vector<vector<int>> strassen(vector<vector<int>> A,
                             vector<vector<int>> B) {
    int n = A.size();

    // Base case
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int mid = n / 2;

    vector<vector<int>> A11(mid, vector<int>(mid));
    vector<vector<int>> A12(mid, vector<int>(mid));
    vector<vector<int>> A21(mid, vector<int>(mid));
    vector<vector<int>> A22(mid, vector<int>(mid));

    vector<vector<int>> B11(mid, vector<int>(mid));
    vector<vector<int>> B12(mid, vector<int>(mid));
    vector<vector<int>> B21(mid, vector<int>(mid));
    vector<vector<int>> B22(mid, vector<int>(mid));

    // Divide matrices into 4 parts
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    // Strassen's 7 multiplications
    auto M1 = strassen(addMatrix(A11, A22),
                       addMatrix(B11, B22));

    auto M2 = strassen(addMatrix(A21, A22), B11);

    auto M3 = strassen(A11,
                       subtractMatrix(B12, B22));

    auto M4 = strassen(A22,
                       subtractMatrix(B21, B11));

    auto M5 = strassen(addMatrix(A11, A12), B22);

    auto M6 = strassen(subtractMatrix(A21, A11),
                       addMatrix(B11, B12));

    auto M7 = strassen(subtractMatrix(A12, A22),
                       addMatrix(B21, B22));

    // Calculate result quadrants
    auto C11 = addMatrix(
        subtractMatrix(addMatrix(M1, M4), M5),
        M7
    );

    auto C12 = addMatrix(M3, M5);

    auto C21 = addMatrix(M2, M4);

    auto C22 = addMatrix(
        subtractMatrix(addMatrix(M1, M3), M2),
        M6
    );

    // Combine four quadrants
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            C[i][j] = C11[i][j];
            C[i][j + mid] = C12[i][j];
            C[i + mid][j] = C21[i][j];
            C[i + mid][j + mid] = C22[i][j];
        }
    }

    return C;
}

vector<vector<int>> strassen_multiply(
    vector<vector<int>>& A,
    vector<vector<int>>& B) {

    return strassen(A, B);
}


int main() {
    vector<vector<int>> A = {
        {1, 2},
        {3, 4}
    };

    vector<vector<int>> B = {
        {5, 6},
        {7, 8}
    };

    vector<vector<int>> result = strassen_multiply(A, B);

    for (auto row : result) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}