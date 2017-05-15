#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
void next_move(int posr, int posc, vector <string> board) {
    //add logic here
    if(board[posr][posc] == 'd'){
        cout <<"CLEAN\n";
        return;
    }
    int r, c, best=999999;
    for(int i = 0; i < board.size(); i ++){
        for(int j = 0; j < board[0].size(); j++){
            if(board[i][j] == 'd'){
                if(abs(posr - i) + abs(posc - j) < best){
                    best = abs(posr - i) + abs(posc - j);
                    r = i;
                    c = j;
                   // cout << r << ' ' << j <<endl;
                }
            } 
        }
    }
    if((r - posr) == 1){
        cout << "DOWN\n";
        return;
    }
    else if((r - posr) == -1){
        cout << "UP\n";
        return;
    }
    if((c - posc) == 1){
        cout << "RIGHT\n";
        return;
    }
    else if((c - posc) == -1){
        cout << "LEFT\n";
        return;
    }
    if(abs(r - posr) > abs(c - posc)){
        if(r - posr > 0){
            cout << "DOWN\n";
            return;
        }
        else{
            cout << "UP\n";
            return;
        }
    }
    else{
        if(c - posc > 0){
            cout << "RIGHT\n";
            return;
        }
        else{
            cout << "LEFT\n";
            return;
        }
    }
}
int main(void) {
    int pos[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    for(int i=0;i<5;i++) {
        string s;cin >> s;
        board.push_back(s);
    }
    next_move(pos[0], pos[1], board);
    return 0;
}
