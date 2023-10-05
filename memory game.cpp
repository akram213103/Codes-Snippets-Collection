#include <iostream>
#include <cstdlib>

using namespace std;

void initializeBoard(int cards[4][4], bool visible[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cards[i][j] = rand() % 8 + 1;
            visible[i][j] = false;
        }
    }
}

bool checkWin(bool visible[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (!visible[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void displayBoard(int cards[4][4], bool visible[4][4]) {
    cout << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (visible[i][j]) {
                cout << cards[i][j] << " ";
            }
            else {
                cout << "* ";
            }
        }
        cout << endl;
    }
}

bool input(int& row, int& col, bool visible[4][4]) {
    cout << "Enter the row (1 to 4) and column (1 to 4) position of the pair:\n Make sure to put spaces between numbers\nExample: 1 3 \n ";
    cin >> row >> col;
    if (row < 0 || row > 3 || col < 0 || col > 3) {
        cout << "Invalid position." << endl;
        return false;
    }
    if (visible[row][col]) {
        cout << "This card is already visible." << endl;
        return false;
    }
    return true;
}

int main() {

    srand(50);

    int cards[4][4];
    bool visible[4][4];

    initializeBoard(cards, visible);

    int row1, col1, row2, col2;
    while (!checkWin(visible)) {
        displayBoard(cards, visible);

        while (!input(row1, col1, visible));
        visible[row1][col1] = true;
        displayBoard(cards, visible);

        while (!input(row2, col2, visible));
        visible[row2][col2] = true;
        displayBoard(cards, visible);

        if (cards[row1][col1] != cards[row2][col2]) {
            cout << "Pair do not match. Select again!\n";
            visible[row1][col1] = false;
            visible[row2][col2] = false;
        }
        else {
            cout << "Pair match!\n";
        }
    }

}