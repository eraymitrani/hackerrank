#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
void nextMove(int x, int y, int color, vector <string> grid){
    //your logic here
    int count = 0;
    start:
    count++;
    int loca = rand() % (x - 3) + 1;
    int locb = rand() % (y - 3) + 1;
    char c = grid[loca][locb];
    if(count > 6){
        here:
        if(grid[x-1][1] == c || grid[x-2][0] == c){
            cout << x - 1 << " " << y - y << endl;
            return;
        }
        x -= rand() % 3;
        y += rand() % 3;
        goto here;
    }
    if(c != 'V' && c!= 'I' && c!= 'G' && c!= 'B' && c!='Y' && c!='O' && c!='R') goto start;
    if(grid[loca][locb+1] == c || grid[loca + 1][locb] == c || grid[loca][locb-1] == c || grid[loca - 1][locb] == c){
        cout << loca << " " << locb << endl;
        return;
    }
    goto start;
    
}
int main(void) {

    int x,y,k;
    cin >> x >> y >> k;
    vector <string> grid;

    for(int i=0; i<x; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    nextMove( x, y, k, grid);

    return 0;
}
