#include <vector>

#define LEFT 97
#define RIGHT 98
#define UP 99
#define DOWN 100

using namespace std;

struct Position {
    Position() {
        row = 0;
        col = 0;
    }
    int row;
    int col;
};

void getFourPosition(const vector<vector<int>>& matrix, const Position& startPoint, Position& RU, Position& RD, Position& LD, const int& length, int sideCol, int sideRow) {
    int direction = RIGHT;
    int row = startPoint.row;
    int col = startPoint.col;
    for (int i = 0; i < 3; ++i) {
        for (int step = 0; step < length - 1; ++step) {
            if (direction == RIGHT) {
                if (col - sideCol == length - 1) {
                    direction = DOWN;
                    row++;
                }
                else {
                    col++;
                }
            }
            else if (direction == DOWN) {
                if (row - sideRow == length - 1) {
                    direction = LEFT;
                    col--;
                }
                else {
                    row++;
                }
            }
            else if (direction == LEFT) {
                if (col == sideCol) {
                    direction = UP;
                    row--;
                }
                else {
                    col--;
                }
            }
            else {
                if (row == sideRow) {
                    direction = RIGHT;
                    col++;
                }
                else {
                    row--;
                }
            }
        }
        if (i == 0) {
            RU.row = row;
            RU.col = col;
        }
        else if (i == 1) {
            RD.row = row;
            RD.col = col;
        }
        else {
            LD.row = row;
            LD.col = col;
        }
    }
}

void rotate(vector<vector<int>>& matrix) {
    int length_of_each_size = matrix.size();
    int total_size = length_of_each_size;
    while (length_of_each_size > 1) {
        // Construct start point.
        Position startPoint;
        startPoint.col = (total_size - length_of_each_size) / 2;
        startPoint.row = startPoint.col;
        int sideCol = startPoint.col;
        int sideRow = startPoint.row;
        Position rightUp;
        Position rightDown;
        Position leftDown;
        for (int i = 0; i < length_of_each_size - 1; ++i) {
            getFourPosition(matrix, startPoint, rightUp, rightDown, leftDown, length_of_each_size, sideCol, sideRow);
            
            // Exchange four values.
            int tmp = matrix[startPoint.row][startPoint.col];
            matrix[startPoint.row][startPoint.col] = matrix[leftDown.row][leftDown.col];
            matrix[leftDown.row][leftDown.col] = matrix[rightDown.row][rightDown.col];
            matrix[rightDown.row][rightDown.col] = matrix[rightUp.row][rightUp.col];
            matrix[rightUp.row][rightUp.col] = tmp;
            startPoint.col++;
        }
        length_of_each_size -= 2;
    }
}