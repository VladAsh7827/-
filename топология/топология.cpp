#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> gr(1e5 + 1);
vector<int> used(1e5 + 1);
vector<int> res;
int ans = 0;

void dfs(int v) {
    used[v] = 1;
    for (auto x : gr[v]) {
        if (used[x] == 1) {
            ans = 1;
        }
        else if (used[x] == 0) {
            dfs(x);
        }
    }
    res.push_back(v);
    used[v] = 2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        gr[a].push_back(b);
    }
    for (int v = 1; v < n + 1; v++)
        if (!used[v])
            dfs(v);
    reverse(res.begin(), res.end());
    if (ans) {
        cout << -1 << endl;
    }
    else {
        for (auto x : res) {
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}