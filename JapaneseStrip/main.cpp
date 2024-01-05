#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

unsigned long long int count_stripes(int n, int k, const vector<int> &code) {
    vector<vector<unsigned long long int>> dp(n, vector<unsigned long long int>(k, 0));

    /*vector<int> s;
    for (int i = 0; i < k; i++) {
        s.push_back(i);
        for (int j = 0; j <= i; j++)
            s.back() += code[j];
    }

    for (int num: s)
        cout << num << " ";
    cout << '\n' << '\n';*/

    for (int i = code[0] - 1; i < n; i++)
        dp[i][0] = 1;

    for (int j = 1; j < k; j++) {
        for (int i = 0; i < n; i++) {
            for (int l = code[j] + 1; l <= i; l++) {
                dp[i][j] += dp[i - l][j - 1];
            }
        }
    }

    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++)
            cout << dp[i][j] << " ";
        cout << '\n';
    }*/

    unsigned long long int result = 0;

    for (int i = 0; i < n; i++)
        result += dp[i][k - 1];

    return result;
}

int main() {
    ifstream in("in.txt");
    ofstream out("out.txt");
    int n, k;
    in >> n >> k;
    if (k == 0)
    {
        in.close();
        out << 1 << endl;
        out.close();
        return 0;
    }
    in.ignore();

    vector<int> code(k);
    for (int i = 0; i < k; i++) {
        in >> code[i];
        if (code[i] == 0) {
            code[i] = 1;
            n++;
        }
    }

    in.close();
    unsigned long long int answer = count_stripes(n, k, code);
    out << answer << endl;
    out.close();

    return 0;
}
