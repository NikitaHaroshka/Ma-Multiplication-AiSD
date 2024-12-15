#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int s;
    fin >> s;

    vector<int> A(s + 1);
    for (int i = 0; i < s; i++) {
        int rows, cols;
        fin >> rows >> cols;
        A[i] = rows;
        if (i == s - 1) {
            A[i + 1] = cols;
        }
    }

    vector<vector<int>> ma(s, vector<int>(s, 0));
    for (int l = 2; l <= s; l++) {
        for (int i = 0; i < s - l + 1; i++) {
            int j = i + l - 1;
            ma[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = ma[i][k] + ma[k + 1][j] + A[i] * A[k + 1] * A[j + 1];
                ma[i][j] = min(ma[i][j], q);
            }
        }
    }
    fout << ma[0][s - 1] << endl;

    return 0;
}
