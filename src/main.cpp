/** --------------------------- 
* @file		main.cpp
* @author	Charlie Welsh
* @version	1.0
*
* CS162-01 - Assignment 5.1
*	The Knight's Tour assignment
*
* --------------------------- */

#include <iostream>
#include <iomanip>

const int BOARD_SIZE = 5;

struct Board {
	int array [BOARD_SIZE][BOARD_SIZE] = {{0}};
};

/**
*	Recursively solves the knights tour using brute force
*	Prints any solutions it finds.
*	
*	@param board -				the board we’re working with (contains all moves-to-date)
*	@param row -				the row we’re going to attempt to place the knight on this move (zero-indexed).
*	@param col -				the column we’re going to attempt place the knight on this move (zero-indexed).
*	@param currentMoveNumber -	the move number we’re making (1 = first move)
*
*	@return The number of solutions the given board and move leads to
*
*/

int solveKnightsTour(Board board, int row, int col, int currentMoveNum = 1, int solutions = 0); 

/**
*	Prints the contents of a Board object. 
*	
*	@param board -				the board we’re working with (contains all moves-to-date)
*
*/

void printBoard(Board board, int solution = 0);



int main() {
	Board board;
	std::cout << solveKnightsTour(board, 2, 2) << " solutions found" << std::endl;
}

// -------------------

void printBoard(Board board, int solution = 0) {
	std::cout << "Solution " << solution << ":" << std::endl;
	for (int col = 0; col < BOARD_SIZE; col++) {
		for (int row = 0; row < BOARD_SIZE; row++) {
			std::cout << std::setfill('0') << std::setw(2) << board.array[row][col] << " ";
		}
		std::cout << '\n';
	}
	std::cout << std::endl;
}

// -------------------

int solveKnightsTour(Board board, int row, int col, int currentMoveNum, int solutions) {
	const int startCol = col;
	const int startRow = row;
	bool shortHorizontal = false;
	
	board.array[row][col] = currentMoveNum;
	if (currentMoveNum != BOARD_SIZE * BOARD_SIZE) {
		for (int rotation = 0; rotation < 4; rotation++) {
			switch(rotation) {
				case 0:
					col = startCol + 2;
					shortHorizontal = true;
					break;
				case 1:
					row = startRow + 2;
					shortHorizontal = false;
					break;
				case 2:
					col = startCol - 2;
					shortHorizontal = true;
					break;
				case 3:
					row = startRow - 2;
					shortHorizontal = false;
					break;
			}
			
			for (int direction = 0; direction < 2; direction++) {
				if (shortHorizontal) {
					switch (direction) {
						case 0:
							row = startRow - 1;
							break;
						case 1:
							row = startRow + 1;
							break;
					}
				} else {
					switch (direction) {
						case 0:
							col = startCol - 1;
							break;
						case 1:
							col = startCol + 1;
							break;
					}
				}
				if (
					row < BOARD_SIZE 	&&
					row >= 0 			&&
					col < BOARD_SIZE	&&
					col >= 0 			&&
					board.array[row][col] == 0
				) {
					solutions = solveKnightsTour(board, row, col, currentMoveNum + 1, solutions);
				}
			}
		}
	} else {
		solutions++;
		printBoard(board, solutions);
	}
	
	return solutions;
}