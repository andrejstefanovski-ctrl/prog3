#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isMatch(string word, string pattern)
{
    int n = word.length();
    int m = pattern.length();

    vector<vector<bool>> T(n + 1, vector<bool>(m + 1, false));

    T[0][0] = true;

    for (int j=1; j<=m; j++) {
        if (pattern[j-1] == '*') {
            T[0][j] = T[0][j-1];
        }
    }

    for (int i=1; i<=n; i++) 
    {
        for (int j=1; j<=m; j++) 
        {
            if (pattern[j-1] == '*') 
            {
                T[i][j] = T[i-1][j] || T[i][j-1];
            }
            else if (pattern[j-1] == '?' || word[i-1] == pattern[j-1]) {

                T[i][j] = T[i-1][j-1];
            }
        }
    }

    return T[n][m];
}

int main()
{
    string word = "xyxzzxy";
    string pattern = "x***x?";

    if (isMatch(word, pattern)) {
        cout << "Match" << endl;
    } else {
        cout << "No Match" << endl;
    }

    return 0;
}
