#include <iostream>

bool matchSymbols(std::string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'X' || str[i] == 'O' || str[i] == '.') {
            return true;
        } else
            return false;
    }
}

bool inputCheck(std::string str, char name) {
    for (int count = 0; count < 3; count++) {
        std::cout << name << ": ";
        std::cin >> str;
        if (matchSymbols(str)) {
            return true;
        } else if (!matchSymbols(str) && count == 2) {
            std::cout << "Too more attempts for Input!!!\nGood by!!!\n";
            return false;
        }
    }
}



int main() {
    std:: string rowA, rowB, rowC;
    char nameA = 'A', nameB = 'B', nameC = 'C';
    std::cout << "Input 3 strings by 3 symbols ('X', 'O' or '.'):\n";
    if (!inputCheck(rowA, nameA)) {
        return 0;
    } else if (!inputCheck(rowB, nameB)) {
        return 0;
    } else if (!inputCheck(rowC, nameC)) {
        return 0;
    }
    
}
