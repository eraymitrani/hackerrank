#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s ="0";
    while(s.length() <= 1000){
        string t;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0'){
                t.push_back('1');
            }
            else t.push_back('0');
        }
        s.append(t);
    }
    int q, c;
    cin >> q;
    for(int i = 0; i < q; i ++){
        cin >> c;
        cout << s[c] << endl;
    }
    return 0;
}
