#include <iostream>
using namespace std;

int sol[8][8];

int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
 

void printBoard(){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			cout << sol[i][j] << " ";
		}
		cout << endl;
	}
}

bool isSafe(int x, int y){
	if(x>=0 && x<8 && y>=0 && y<8 && sol[x][y]==-1)
		return true;
	else
		return false;
}

bool solveKT(int moveNum, int x, int y){
	if(moveNum == 64){
		return true;
	}

	for(int i=0; i<8; i++){
		int xNext = x + xMove[i];
		int yNext = y + yMove[i];
		if(isSafe(xNext, yNext)){
			sol[xNext][yNext] = moveNum;
			if(solveKT(moveNum+1, xNext, yNext)){
				return true;
			}
			else{
				//backtracking
				sol[xNext][yNext] = -1;
			}
		}
	}
	return false;
}

int main(){
	//board intialization
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			sol[i][j] = -1;
		}
	}

	//first move
	sol[0][0] = 0;

	if(solveKT(1, 0, 0)){
		printBoard();
	}
	else{
		cout << "sol doesn't exist";
	}

	return 0;
}