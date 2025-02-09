#include <iostream>
#include <vector>
using namespace std;

bool attack(pair<int, int> p1, pair<int, int> p2) 
{
    return (p1.first == p2.first || p1.second == p2.second || abs(p1.first - p2.first) == abs(p1.second - p2.second));
}

bool validno(vector<pair<int, int>>& queens) 
{
    for (int i=0; i<queens.size(); i++) 
    {
        for (int j=i+1; j<queens.size(); j++) 
        {
            if (attack(queens[i], queens[j])) 
            {
                return false;
            }
        }
    }
    return true;
}

void solve(int n, vector<pair<int, int>>& v, vector<vector<pair<int, int>>>& s) {
    if (v.size() == n) 
    {
        if (validno(v)) 
        {
            s.push_back(v);
        }
        return;
    }
    for (int row=0; row<n; row++) 
    {
        for (int col=0; col<n; col++) 
        {
            v.push_back({row, col});
            solve(n, v, s);
            v.pop_back();
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<pair<int, int>>> s;
    vector<pair<int, int>> v;

    solve(n, v, s);

    int ctr = 0;
    for (auto& sol : s) 
    {
        cout << ++ctr << '\n';
        for (auto& p : sol) 
        {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << '\n';
    }

    cout << ctr;
    return 0;
}
