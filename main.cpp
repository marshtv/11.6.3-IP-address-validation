#include <iostream>
bool matchSymbols(std::string x)
{
    if (x.length() < 7 && x.length() > 15) {
        std::cout << "Unacceptable number of symbols!!!\n";
        return false;
    } else if (x[0] == '.' || x[x.length() - 1] == '.') {
        std::cout << "Dot Must not to be First or Last!!!\n";
        return false;
    } else {
        int dotNum = 0;
        char preChar = ' ';
        for (int i = 0; i < x.length(); i++) {
            if (x[i] != '.') {
                if (x[i] < '0' && x[i] > '9') {
                    std::cout << "Unacceptable symbols!!!\n";
                    return false;
                }
            } else if (x[i] == '.') {
                if (preChar == '.') {
                    std::cout << "More then One Dot in a row!!!\n";
                    return false;
                }
                dotNum++;
                preChar = '.';
            }
        }
        if (dotNum != 3) {
            std::cout << "Unacceptable number of Dots!!!\n";
            return false;
        }
    }

}

bool matchOctas(std::string x) {
    if (!matchSymbols(x)) {
        return false;
    } else {
        char preDigit = ' ', prePreDigit = ' ';
        for (int i = 0; i < x.length(); i++) {
            if (x[i] >= '0' && x[i] <= '9') {
                if (prePreDigit < '0' && prePreDigit > '9') {
                    if (preDigit < '0' && preDigit > '9') {
                        prePreDigit = preDigit;
                        preDigit = x[i];
                    }
                } else if (prePreDigit >= '0' && prePreDigit <= '9') {

                }
            } else {
                preDigit = ' ';
                prePreDigit = ' ';
            }
        }
    }
}

int get_Octa_By_Num(std::string x, int octaNum) {
    int octa = 0, count = 0;
    int charNum = 0;
    for (int i = 0; i < x.length(); i++) {
        if (count == octaNum) {
            if (x[i] != '.') {
                if (charNum == 0) {
                    octa += (int) (x[i] - '0');
                    charNum++;
                    count++;
                } else if (charNum == 1) {
                    octa = octa * 10 + (int) (x[i] - '0');
                    charNum++;
                } else if (charNum == 2) {
                    octa = octa * 10 + (int) (x[i] - '0');
                }
            } else {
                charNum = 0;
            }
        } else if (count > octaNum)
            break;
    }
    return octa;
}

int main() {
    std::string ip;
    bool is_Valid = true;

    std::cout << "Input IP-address:\n";
    std::getline(std::cin, ip);

    if (matchInput(ip)) {
        for (int i = 0; i <= 3; i++) {
            if (get_Octa_By_Num(ip, i) > 254) {
                std::cout << "octa_" << i << ": " << get_Octa_By_Num(ip, i) << "\n";
                is_Valid = false;
                break;
            }
        }
    } else {
        is_Valid = false;
    }

    if (is_Valid)
        std::cout << "Valid\n";
    else
        std::cout << "Invalid\n";
}
