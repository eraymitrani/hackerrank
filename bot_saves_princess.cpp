#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;
void displayPathtoPrincess(int n, vector <string> grid){
    //your logic here
    if(grid[0][0] == 'p' && n % 2){
        for(int i = 1; i < n; i+=2){
            cout << "UP\n";
            cout << "LEFT\n";
        }
    }
    else if(grid[0][n-1] == 'p' && n % 2){
        for(int i = 1; i < n; i+=2){
            cout << "UP\n";
            cout << "RIGHT\n";
        }
    }
    else if(grid[n - 1][0] == 'p' && n % 2){
        for(int i = 1; i < n; i+=2){
            cout << "DOWN\n";
            cout << "LEFT\n";
        }
    }
    else if(grid[n-1][n-1] == 'p' && n % 2){
        for(int i = 1; i < n; i+=2){
            cout << "DOWN\n";
            cout << "RIGHT\n";
        }
    }
}
int main(void) {

    int m;
    vector <string> grid;

    cin >> m;

    for(int i=0; i<m; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    displayPathtoPrincess(m,grid);

    return 0;
}
