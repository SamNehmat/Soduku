#ifndef SUDOKU_H
#define SUDOKU_H 
#include "Searchable.h"
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <cmath>
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::set;


// TODO: Your Sudoku class goes here:
class Sudoku {

public:
	int boardSize;
    vector<vector<set<int>>> square;
    Sudoku(const int tmp)
    :boardSize(tmp){
set<int>temp;

for (int i = 0; i < boardSize; i++){
	temp.insert(i);
}
    for (int j=0; j < boardSize; j++){
	vector<set<int>>tempx;
	
        for (int p=1; p<=boardSize; p++){ 
        tempx.push_back(temp);
        
		square.push_back(tempx);
}
	}
	}
int getSquare(int row, int col){
if (square[row][col].size() == 1){
           return *square[row][col].begin();
           }
else return -1;
}

bool setSquare(int row, int col, int value){
bool change = false;
square[row][col].clear();
square[row][col].insert(value);

int boxSize = sqrt(boardSize);
int strtBox = floor(value/boxSize) * boxSize;
int endBox = strtBox + boxSize -1;

while (change){
change = false;
for (int i= 0; i < boardSize; ++i){
    for (int j=0; j < boardSize; ++j){
		if (square[row][col].size() == 1){
			cout << " this is" << value << endl;
			for (int r=0; r < boardSize; ++r){
				if (r != col){
					square[row][r].erase(value);
					change = true;
				}
				if (r != row){
					square[r][col].erase(value);
					change = true;
				}
			}
			for (int b= strtBox; b<=endBox; b++){
				if (b != col){
					square[row][b].erase(value);
					change = true;
				}
				if (b != row){
					square[b][col].erase(value);
					change = true;
				}
			}
			
		}
	if (square[i][j].empty()){
	return false;}
	}
	}
}
return true;
}
};
#endif