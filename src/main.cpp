#include <iostream>
#include <iomanip>

const int BOARD_WIDTH = 5;
const int BOARD_HEIGHT = 5;

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

struct Board {
	int array [BOARD_WIDTH][BOARD_HEIGHT] = {{0}};
};

int solveKnightsTour(Board board, int row, int col, int currentMoveNum = 1); 


int main() {
	Board board;
	std::cout << solveKnightsTour(board, 2, 2) << " solutions found" << std::endl;
}

void printBoard(Board board) {
	for (int col = 0; col < BOARD_HEIGHT; col++) {
		for (int row = 0; row < BOARD_WIDTH; row++) {
			std::cout << std::setfill('0') << std::setw(2) << board.array[row][col] << " ";
		}
		std::cout << '\n';
	}
	std::cout << std::endl;
}

int solveKnightsTour(Board board, int row, int col, int currentMoveNum) {
	const int startCol = col;
	const int startRow = row;
	bool shortHorizontal = false;
	int solutions = 0;
	
	board.array[row][col] = currentMoveNum;
	if (currentMoveNum != BOARD_HEIGHT * BOARD_WIDTH) {
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
					row < BOARD_WIDTH 	&&
					row >= 0 			&&
					col < BOARD_HEIGHT	&&
					col >= 0 			&&
					board.array[row][col] == 0
				) {
					solutions = solutions + solveKnightsTour(board, row, col, currentMoveNum + 1);
				}
			}
		}
	} else {
		printBoard(board);
		solutions = 1;
	}
	
	return solutions;
}