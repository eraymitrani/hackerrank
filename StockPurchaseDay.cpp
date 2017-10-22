#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int stockPurchaseDay(vector <int> &A, int xi, int min) {
    // Complete this function
    if(xi < min) {
        return -1;   
    }
    for(auto i = A.size() - 1; i >= 0; i--){
        if(A[i] <= xi){
            return i + 1;
        }
    }
}

int main() {
    int min = INT_MAX;
    int n;
    cin >> n;
    vector<int> A(n);
    for(int A_i = 0; A_i < n; A_i++){
        int a;
        cin >> a;
        if(a < min){
            min = a;
        }
       A[A_i] = a;
    }
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int xi;
        cin >> xi; 
        int result = stockPurchaseDay(A, xi, min);
        cout << result << endl;
    }
    return 0;
}
