#include <iostream>
#include <vector>
using namespace std;
void nextMove(int n, int r, int c, vector <string> grid){
    //your logic here
    int x, y;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 'p'){
                x = i;
                y = j;
            }
        }
    }
    if(x > r){
        cout << "DOWN\n";
    }
    else if(x < r){
        cout << "UP\n";
    }
    else if(y > c){
        cout << "RIGHT\n";
    }
    else cout <<"LEFT\n";
}
int main(void) {

    int n, r, c;
    vector <string> grid;

    cin >> n;
    cin >> r;
    cin >> c;

    for(int i=0; i<n; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    nextMove(n, r, c, grid);
    return 0;
}
