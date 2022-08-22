#include <iostream>
#include <cmath>

bool matchSymbols(std::string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'X' || str[i] == 'O' || str[i] == '.') {
            return true;
        } else
            return false;
    }
}

char getSymbol_by_coordinate(std::string row_A, std::string row_B, std::string row_C, int x, int y) {
    if (y == 0)
        return row_A[x];
    else if (y == 1)
        return row_B[x];
    else if (y == 2)
        return row_C[x];
}

bool check_Row_Win(std::string row_A, std::string row_B, std::string row_C, int row_Num, char x_or_o) {
    char c_0, c_1, c_2;
    int x;
    c_0 = getSymbol_by_coordinate(row_A, row_B, row_C, x = 0, row_Num);
    c_1 = getSymbol_by_coordinate(row_A, row_B, row_C, x = 1, row_Num);
    c_2 = getSymbol_by_coordinate(row_A, row_B, row_C, x = 2, row_Num);
    if (c_0 == x_or_o && c_0 == c_1 && c_1 == c_2)
        return true;
    else
        return false;
}

bool check_Column_Win(std::string row_A, std::string row_B, std::string row_C, int column_Num, char x_or_o) {
    char c_0, c_1, c_2;
    int y;
    c_0 = getSymbol_by_coordinate(row_A, row_B, row_C, column_Num, y = 0);
    c_1 = getSymbol_by_coordinate(row_A, row_B, row_C, column_Num, y = 1);
    c_2 = getSymbol_by_coordinate(row_A, row_B, row_C, column_Num, y = 2);

    if (c_0 == x_or_o && c_0 == c_1 && c_1 == c_2)
        return true;
    else
        return false;
}

bool check_1_Diagonal_Win(std::string row_A, std::string row_B, std::string row_C, char x_or_o) {
    char d1_0, d1_1, d1_2;
    int x, y;
    d1_0 = getSymbol_by_coordinate(row_A, row_B, row_C, x = 0, y = 0);
    d1_1 = getSymbol_by_coordinate(row_A, row_B, row_C, x = 1, y = 1);
    d1_2 = getSymbol_by_coordinate(row_A, row_B, row_C, x = 2, y = 2);

    if (d1_1 == x_or_o && d1_1 == d1_0 && d1_1 == d1_2)
        return true;
    else
        return false;
}

bool check_2_Diagonal_Win(std::string row_A, std::string row_B, std::string row_C, char x_or_o) {
    char d2_0, d2_1, d2_2;
    int x, y;
    d2_0 = getSymbol_by_coordinate(row_A, row_B, row_C, x = 2, y = 0);
    d2_1 = getSymbol_by_coordinate(row_A, row_B, row_C, x = 1, y = 1);
    d2_2 = getSymbol_by_coordinate(row_A, row_B, row_C, x = 0, y = 2);

    if (d2_1 == x_or_o && d2_1 == d2_0 && d2_1 == d2_2)
        return true;
    else
        return false;
}

int turns_Number_by_Player_or_Remains(std::string row_A, std::string row_B,
                                      std::string row_C, char x_or_o_or_dot) {
    int turns_X = 0, turns_O = 0, turns_remains;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (getSymbol_by_coordinate(row_A, row_B, row_C, i, j) == 'X')
                turns_X++;
            else if (getSymbol_by_coordinate(row_A, row_B, row_C, i, j) == 'O')
                turns_O++;
            else {
                turns_remains++;
            }
        }
    }
    if (x_or_o_or_dot == 'X')
        return turns_X;
    else if (x_or_o_or_dot == 'O')
        return turns_O;
    else if (x_or_o_or_dot == '.')
        return turns_remains;
}

bool is_Game_Correct_Win(std::string row_A, std::string row_B, std::string row_C) {
    int rowWins_X = 0, rowWins_O = 0;
    int columnWins_X = 0, columnWins_O = 0;
    int diagonal_1_Wins_X = 0, diagonal_2_Wins_X = 0;
    int diagonal_1_Wins_O = 0, diagonal_2_Wins_O = 0;
    char x_Player = 'X';
    char o_Player = 'O';
    char empty = '.';

    for (int i = 0; i < 3; i++) {
        if (check_Row_Win(row_A, row_B, row_C, i, x_Player)) {
            rowWins_X++;
        }
        if (check_Row_Win(row_A, row_B, row_C, i, o_Player)) {
            rowWins_O++;
        }
        if (check_Column_Win(row_A, row_B, row_C, i, x_Player)) {
            columnWins_X++;
        }
        if (check_Column_Win(row_A, row_B, row_C, i, o_Player)) {
            columnWins_O++;
        }
    }
    if (check_1_Diagonal_Win(row_A, row_B, row_C, x_Player))
        diagonal_1_Wins_X++;
    if (check_1_Diagonal_Win(row_A, row_B, row_C, o_Player))
        diagonal_1_Wins_O++;
    if (check_2_Diagonal_Win(row_A, row_B, row_C, x_Player))
        diagonal_2_Wins_X++;
    if (check_2_Diagonal_Win(row_A, row_B, row_C, o_Player))
        diagonal_2_Wins_O++;
/*    std::cout << "rowWins_O = " << rowWins_O << "\n";
    std::cout << "rowWins_X = " << rowWins_X << "\n";
    std::cout << "columnWins_O = " << columnWins_O << "\n";
    std::cout << "columnWins_X = " << columnWins_X << "\n";
    std::cout << "diagonal_1_Wins_O = " << diagonal_1_Wins_O << "\n";
    std::cout << "diagonal_1_Wins_X = " << diagonal_1_Wins_X << "\n";
    std::cout << "diagonal_2_Wins_O = " << diagonal_2_Wins_O << "\n";
    std::cout << "diagonal_2_Wins_X = " << diagonal_2_Wins_X << "\n";*/

    if (diagonal_1_Wins_O > 0 && diagonal_2_Wins_O > 0) {
        std::cout << "Incorrect (O - diagonal win ERROR)\n";
        return false;
    } else if (diagonal_1_Wins_X > 0 && diagonal_2_Wins_X > 0) {
        std::cout << "Incorrect (X - diagonal win ERROR)\n";
        return false;
    } else if (rowWins_O > 1 || rowWins_X > 1 || columnWins_O > 1 || columnWins_X > 1) {
        std::cout << "Incorrect (O or X double win ERROR)\n";
        return false;
    } else if (rowWins_O > 0 && rowWins_X > 0 || columnWins_O > 0 && columnWins_X > 0) {
        std::cout << "Incorrect (O or X parallel win ERROR)\n";
        return false;
    } else if   (abs(turns_Number_by_Player_or_Remains(row_A, row_B, row_C, o_Player)
                - turns_Number_by_Player_or_Remains(row_A, row_B, row_C, x_Player)) > 1) {
        std::cout << "Incorrect (number of turns ERROR)\n";
        return false;
    } else if      ((turns_Number_by_Player_or_Remains(row_A, row_B, row_C, o_Player)
                   - turns_Number_by_Player_or_Remains(row_A, row_B, row_C, x_Player)) == 0
                   || (turns_Number_by_Player_or_Remains(row_A, row_B, row_C, o_Player)
                   - turns_Number_by_Player_or_Remains(row_A, row_B, row_C, x_Player)) == 1) {
        if (rowWins_O == 1 || columnWins_O == 1 || rowWins_O == 1 && columnWins_O == 1
                || rowWins_O == 1 && diagonal_1_Wins_O == 1 || rowWins_O == 1 && diagonal_2_Wins_O == 1
                || columnWins_O == 1 && diagonal_1_Wins_O == 1 || columnWins_O == 1 && diagonal_2_Wins_O == 1) {
            std::cout << "Vanya win.\n";
            return true;
        }
    }
    if      ((turns_Number_by_Player_or_Remains(row_A, row_B, row_C, x_Player)
                    - turns_Number_by_Player_or_Remains(row_A, row_B, row_C, o_Player)) == 0
                    || (turns_Number_by_Player_or_Remains(row_A, row_B, row_C, x_Player)
                    - turns_Number_by_Player_or_Remains(row_A, row_B, row_C, o_Player)) == 1) {
        if (rowWins_X == 1 || columnWins_X == 1 || rowWins_X == 1 && columnWins_X == 1
                || rowWins_X == 1 && diagonal_1_Wins_X == 1 || rowWins_X == 1 && diagonal_2_Wins_X == 1
                || columnWins_X == 1 && diagonal_1_Wins_X == 1 || columnWins_X == 1 && diagonal_2_Wins_X == 1) {
            std::cout << "Petya win.\n";
            return true;
        }
    } else if (rowWins_O == 0 && rowWins_X == 0 && columnWins_O == 0 && columnWins_X == 0
                && diagonal_1_Wins_O == 0 && diagonal_1_Wins_X == 0
                && diagonal_2_Wins_O == 0 && diagonal_2_Wins_X == 0
                && turns_Number_by_Player_or_Remains(row_A, row_B, row_C, empty) >= 0) {
        std::cout << "Nobody.\n";
        return false;
    }
}

int main() {
    std:: string row_A, row_B, row_C;
    // char nameA = 'A', nameB = 'B', nameC = 'C';
    std::cout << "Input 3 strings by 3 symbols ('X', 'O' or '.'):\n";
    for (int count = 0; count < 3; count++) {
        // std::cout << nameA << ":";
        std::cin >> row_A;
        if (matchSymbols(row_A)) {
            break;
        } else if (!matchSymbols(row_A) && count == 2) {
            std::cout << "Too many attempts for Input row A!!!\nGood by!!!\n";
            return 0;
        }
    }
    for (int count = 0; count < 3; count++) {
        // std::cout << nameB << ":";
        std::cin >> row_B;
        if (matchSymbols(row_B)) {
            break;
        } else if (!matchSymbols(row_B) && count == 2) {
            std::cout << "Too many attempts for Input row B!!!\nGood by!!!\n";
            return 0;
        }
    }
    for (int count = 0; count < 3; count++) {
        // std::cout << nameC << ":";
        std::cin >> row_C;
        if (matchSymbols(row_C)) {
            break;
        } else if (!matchSymbols(row_C) && count == 2) {
            std::cout << "Too many attempts for Input row C!!!\nGood by!!!\n";
            return 0;
        }
    }

    if (!(is_Game_Correct_Win(row_A, row_B, row_C))) {
        return 0;
    }
}
