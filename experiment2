#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct State {
    int jug1, jug2;
    State(int a, int b) : jug1(a), jug2(b) {}
};

set<pair<int,int>> visited;
vector<State> path;


bool dfs(int jug1, int jug2, int cap1, int cap2, int goal) {
    if (visited.count({jug1, jug2})) return false;

    visited.insert({jug1, jug2});
    path.push_back(State(jug1, jug2));

    if (jug1 == goal || jug2 == goal) return true;

    if (dfs(cap1, jug2, cap1, cap2, goal)) return true;

    if (dfs(jug1, cap2, cap1, cap2, goal)) return true;
  
    if (dfs(0, jug2, cap1, cap2, goal)) return true;
  
    if (dfs(jug1, 0, cap1, cap2, goal)) return true;
 
    int pour = min(jug1, cap2 - jug2);
    if (dfs(jug1 - pour, jug2 + pour, cap1, cap2, goal)) return true;
 
    pour = min(jug2, cap1 - jug1);
    if (dfs(jug1 + pour, jug2 - pour, cap1, cap2, goal)) return true;

    path.pop_back(); 
    return false;
}

int main() {
    int cap1, cap2, goal;
    cout << "Enter capacity of first jug: ";
    cin >> cap1;
    cout << "Enter capacity of second jug: ";
    cin >> cap2;
    cout << "Enter goal amount: ";
    cin >> goal;

    if (dfs(0, 0, cap1, cap2, goal)) {
        cout << "Solution path: { ";
        for (size_t i = 0; i < path.size(); i++) {
            cout << "(" << path[i].jug1 << "," << path[i].jug2 << ")";
            if (i != path.size() - 1) cout << ", ";
        }
        cout << " }\n";
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}
