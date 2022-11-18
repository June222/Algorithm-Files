#include <iostream>
#include <vector>

using namespace std;

#define SYMBOLSIZE 6

char symbols[SYMBOLSIZE] = { '+','-','*','/','(',')' };

vector<char> answer;
vector<char> buffer;

string getInfix() {
	string infix;
	cin >> infix;
	return infix;
}

bool isSymbol(char c) {
	for (int i = 0; i < SYMBOLSIZE; i++) {
		if (symbols[i] == c) {
			return true;
		}
	}
	return false;
}

bool isPlus(char x) {
	return x == '+';
}
bool isMinus(char x) {
	return x == '-';
}
bool isProduct(char x) {
	return x == '*';
}
bool isDivide(char x) {
	return x == '/';
}
bool isLeftBRK(char x) {
	return x == '(';
}
bool isRightBRK(char x) {
	return x == ')';
}
bool isPlusORMinus(char x) {
	return (isPlus(x) || isMinus(x));
}
bool isProductORDivide(char x) {
	return (isProduct(x) || isDivide(x));
}
void symbolProcess(char currSymbol) {

	if (buffer.empty()) {
		buffer.push_back(currSymbol);
		return;
	}
	if (isRightBRK(currSymbol)) {
		while (!buffer.empty() && !isLeftBRK(buffer.back())) {
			answer.push_back(buffer.back());
			buffer.pop_back();
		}
		buffer.pop_back(); // eliminate LeftBRK
	}
	else if (isLeftBRK(currSymbol)) {
		buffer.push_back(currSymbol);
	}
	else if (isProductORDivide(currSymbol)) {
		if (!isProductORDivide(buffer.back())) {
			buffer.push_back(currSymbol);
		}
		else {
			while (!buffer.empty() && !isLeftBRK(buffer.back()) && isProductORDivide(buffer.back())) {
				answer.push_back(buffer.back());
				buffer.pop_back();
			}
			buffer.push_back(currSymbol);
		}
	}
	else if (isPlusORMinus(currSymbol)) {
		while (!buffer.empty() && !isLeftBRK(buffer.back())) {
			answer.push_back(buffer.back());
			buffer.pop_back();
		}
		buffer.push_back(currSymbol);
	}
}

void solution(string infix) {
	for (int i = 0; i < infix.size(); i++) {
		char currChar = infix[i];
		if (isSymbol(currChar)) { symbolProcess(currChar); }
		else { answer.push_back(currChar); }
	}
	while (!buffer.empty()) {
		answer.push_back(buffer.back());
		buffer.pop_back();
	}
}

void printAnswer() {
	for (auto a : answer)
		cout << a;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string infix = getInfix();
	solution(infix);
	printAnswer();
	return 0;
}