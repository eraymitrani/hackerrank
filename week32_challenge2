#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    std::ios_base::sync_with_stdio(false);
    int n, hit, t, hp, dead = 0;
    cin >> n >> hit >> t;
    vector<int> monsters;
    monsters.reserve(n);
    for(int i = 0; i < n; i++){
        cin >> hp;
        monsters.push_back(hp);
    }
    sort(monsters.begin(), monsters.end());
    for(int i = 0; i < t && dead < n; i ++){
        monsters[dead]-= hit;
        if(monsters[dead] <=0) dead++;
    }
    cout << dead << endl;
    return 0;
}
