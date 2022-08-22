#include <iostream>

bool matchSymbols(std::string x) {
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
				if (x[i] < '0' || x[i] > '9') {
					std::cout << "Unacceptable symbols!!!\n";
					return false;
				}
				preChar = ' ';
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
	return true;
}

bool matchOctas(std::string x) {
	if (!matchSymbols(x)) {
		return false;
	} else {
		int zeros = 0, digits = 0;
		char pre = ' ';
		for (int i = 0; i < x.length(); i++) {
			if (x[i] > '0' && x[i] <= '9') {
				if (digits == 3) {
					std::cout << "Too More Digits in Octa!!!\n";
					return false;
				} else if (digits == 2 && zeros == 1 && pre != '0') {
					std::cout << "Prefix '0' ERROR!!!\n";
					return false;
				} else if (zeros == 2) {
					std::cout << "Prefix '00' ERROR!!!\n";
					return false;
				}
				digits++;
			} else if (x[i] == '0') {
				if (digits == 3) {
					std::cout << "Too More Digits in Octa!!!\n";
					return false;
				} else if (digits == 2 && zeros == 1 && pre != '0') {
					std::cout << "Prefix '0' ERROR!!!\n";
					return false;
				} else if (zeros == 2) {
					std::cout << "Prefix '00' ERROR!!!\n";
					return false;
				}
				digits++;
				zeros++;
			} else { // x[i] == '.'
				if (digits > 3) {
					std::cout << "Too More Digits in Octa!!!\n";
					return false;
				} else if (zeros == 3) {
					std::cout << "Prefix '00' ERROR!!!\n";
					return false;
				} else if (digits == 3 && zeros == 2 && pre != '0') {
					std::cout << "Prefix '0' ERROR!!!\n";
					return false;
				} else if (digits == 2 && zeros == 1 && pre != '0') {
					std::cout << "Prefix '0' ERROR!!!\n";
					return false;
				}
				digits = 0;
				zeros = 0;
			}
			pre = x[i];
		}
	}
	return true;
}

int get_Octa_By_Num(std::string x, int octaNum) {
	int octa_0 = 0, octa_1 = 0, octa_2 = 0, octa_3 = 0, count = 0;
	int charNum = 0;
	for (int i = 0; i < x.length(); i++) {
		if (x[i] != '.') {
			if (count == 0) {
				if (charNum == 0) {
					octa_0 += x[i] - '0';
				} else if (charNum == 1) {
					octa_0 = octa_0 * 10 + (x[i] - '0');
				} else if (charNum == 2) {
					octa_0 = octa_0 * 10 + (x[i] - '0');
				}
			} else if (count == 1) {
				if (charNum == 0) {
					octa_1 += x[i] - '0';
				} else if (charNum == 1) {
					octa_1 = octa_1 * 10 + (x[i] - '0');
				} else if (charNum == 2) {
					octa_1 = octa_1 * 10 + (x[i] - '0');
				}
			} else if (count == 2) {
				if (charNum == 0) {
					octa_2 += x[i] - '0';
				} else if (charNum == 1) {
					octa_2 = octa_2 * 10 + (x[i] - '0');
				} else if (charNum == 2) {
					octa_2 = octa_2 * 10 + (x[i] - '0');
				}
			} else if (count == 3) {
				if (charNum == 0) {
					octa_3 += x[i] - '0';
				} else if (charNum == 1) {
					octa_3 = octa_3 * 10 + (x[i] - '0');
				} else if (charNum == 2) {
					octa_3 = octa_3 * 10 + (x[i] - '0');
				}
			}
			charNum++;
		} else if (x[i] == '.') {
			count++;
			charNum = 0;
		}
	}

	if (octaNum == 0)
		return octa_0;
	else if (octaNum == 1)
		return octa_1;
	else if (octaNum == 2)
		return octa_2;
	else if (octaNum == 3)
		return octa_3;
}

int main() {
	std::string ip;
	bool is_Valid = true;

	std::cout << "Input IP-address:\n";
	std::getline(std::cin, ip);

	if (matchOctas(ip)) {
		for (int i = 0; i < 4; i++) {
			if (get_Octa_By_Num(ip, i) > 255) {
				std::cout << "octa_" << i << ": " << get_Octa_By_Num(ip, i) << " > 255 - ERROR\n";
				is_Valid = false;
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
