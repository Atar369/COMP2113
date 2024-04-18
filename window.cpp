#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "keyboard.h"

using namespace std;

void PrintWindow(vector<vector<string> >& board, int x, int y, int width, int height, const string& content) {
    // Adjust the provided coordinates and dimensions to fit within the gameplay screen
    int adjustedX = min(max(0, x), static_cast<int>(board[0].size()) - 1); // size_t to int
    int adjustedY = min(max(0, y), static_cast<int>(board.size()) - 1);
    int adjustedWidth = min(width, static_cast<int>(board[0].size()) - adjustedX);
    int adjustedHeight = min(height, static_cast<int>(board.size()) - adjustedY);

    // Calculate the starting position for the content to be centered, but wrong for now
    int contentX = adjustedX + (adjustedWidth - content.length()) / 2;
    int contentY = adjustedY + (adjustedHeight - 1) / 2;

    // Update the game board with the content
    int contentIndex = 0;
    for (int i = 0; i < adjustedHeight; ++i) {
        for (int j = 0; j < adjustedWidth; ++j) {
            if (contentIndex < content.length()) {
                board[contentY + i][contentX + j] = content[contentIndex++];
            }
        }
    }

    // Print the game board
    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell;
        }
        cout << endl;
    }

    // Reset the game board to its original state
    contentIndex = 0;
    for (int i = 0; i < adjustedHeight; ++i) {
        for (int j = 0; j < adjustedWidth; ++j) {
            if (contentIndex < content.length()) {
                board[contentY + i][contentX + j] = " ";
                contentIndex++;
            }
        }
    }
}


// testing
int main() {
    vector<vector<string> > gameBoard;
    vector<string> row1;
    row1.push_back("#");
    row1.push_back("#");
    row1.push_back("#");
    row1.push_back("#");
    row1.push_back("#");
    row1.push_back("#");
    row1.push_back("#");
    row1.push_back("#");
    row1.push_back("#");
    row1.push_back("#");
    row1.push_back("#");
    row1.push_back("#");
    gameBoard.push_back(row1);

    vector<string> row2;
    row2.push_back("#");
    row2.push_back(" ");
    row2.push_back(" ");
    row2.push_back(" ");
    row2.push_back(" ");
    row2.push_back(" ");
    row2.push_back(" ");
    row2.push_back(" ");
    row2.push_back(" ");
    row2.push_back(" ");
    row2.push_back(" ");
    row2.push_back("#");
    gameBoard.push_back(row2);

    vector<string> row3;
    row3.push_back("#");
    row3.push_back(" ");
    row3.push_back(" ");
    row3.push_back(" ");
    row3.push_back(" ");
    row3.push_back(" ");
    row3.push_back(" ");
    row3.push_back(" ");
    row3.push_back(" ");
    row3.push_back(" ");
    row3.push_back(" ");
    row3.push_back("#");
    gameBoard.push_back(row3);

    vector<string> row4;
    row4.push_back("#");
    row4.push_back(" ");
    row4.push_back(" ");
    row4.push_back(" ");
    row4.push_back(" ");
    row4.push_back(" ");
    row4.push_back(" ");
    row4.push_back(" ");
    row4.push_back(" ");
    row4.push_back(" ");
    row4.push_back(" ");
    row4.push_back("#");
    gameBoard.push_back(row4);

    vector<string> row5;
    row5.push_back("#");
    row5.push_back("#");
    row5.push_back("#");
    row5.push_back("#");
    row5.push_back("#");
    row5.push_back("#");
    row5.push_back("#");
    row5.push_back("#");
    row5.push_back("#");
    row5.push_back("#");
    row5.push_back("#");
    row5.push_back("#");
    gameBoard.push_back(row5);

    string content = "Hello";
    PrintWindow(gameBoard, 1, 1, content.length(), 1, content);

    return 0;
}
