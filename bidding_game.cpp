#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int calculate_bid(int player, int pos, int* first_moves, int* second_moves) {
	//Your logic to be put here
	int o_left = 100, t_left = 100, bid = 0, draw=0;
	int winning = 0, i = 0;
	if (pos > 5) winning = 1;
	else if (pos < 5) winning = -1;
	int* counter = first_moves;
	while (*(first_moves + i) != 0) {
		int bet1 = *(first_moves + i);
		int bet2 = *(second_moves + i);
		if (bet1 > bet2) {
			o_left -= bet1;
		}
		else if(bet2> bet1) t_left -= bet2;
        else{
            draw++;
            if(draw%2){
                o_left -= bet1;
            }
            else{
                t_left -= bet2;
            }
        }
		i++;
	}
	if (pos > 8) {
		if (player == 1) {
			return o_left;
		}
	}
	if (pos < 2) {
		if (player == 2) {
			return t_left;
		}
	}
	if (player == 1) {
        bid = o_left / (10 - pos);
        if(bid == 0 && o_left > 0) return 1;
        if(bid > 19) return (20 - (rand()%6));
		return bid;
	}
	if (player == 2) {
        bid = t_left / pos;
        if(bid == 0 && t_left > 0) return 1;
        if(bid > 19) return (20 - (rand()%6));
		return bid;
	}
	return bid;
}
int main(void) {
	int player;                                 //1 if first player 2 if second
	int scotch_pos;                             //position of the scotch 
	int bid, iter = 0;                                    //Amount bid by the player
	size_t buf_limit = 500;
	char *first_move = (char *)malloc(buf_limit);      //previous bids of the first player
	char *second_move = (char *)malloc(buf_limit);     //prevous bids of the second player
	char remove_new_line[2];
	int first_moves[200] = { 0 };
	int second_moves[200] = { 0 };
	char *tok_1, *tok_2;
	cin >> player;
	cin >> scotch_pos;
	cin.getline(remove_new_line, 2);           //removes a new line from the buffer
	cin.getline(first_move, 200);
	cin.getline(second_move, 200);
	tok_1 = strtok(first_move, " ");
	for (int i = 0; tok_1; i++) {
		first_moves[i] = atoi(tok_1);
		tok_1 = strtok(NULL, " ");
	}
	tok_2 = strtok(second_move, " ");
	for (int i = 0; tok_2; i++) {
		second_moves[i] = atoi(tok_2);
		tok_2 = strtok(NULL, " ");
	}
	bid = calculate_bid(player, scotch_pos, first_moves, second_moves);
	cout << bid;
	return 0;
}
