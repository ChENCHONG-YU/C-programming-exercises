#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <cctype>

using namespace std;

// �P�_�O�_���B��l
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

// �]�w�B��l���u����
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '%') return 2;
    return 0;
}

// ����򥻪��ƾǹB��
int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b == 0 ? 0 : a / b; // �קK���H 0
        case '%': return b == 0 ? 0 : a % b; // �קK���� 0
    }
    return 0;
}

// �p��ƾǪ�F��
int evaluate(const string &expression) {
    stack<int> values;  // �x�s�Ʀr
    stack<char> ops;    // �x�s�B��l
    
    istringstream iss(expression);
    string token;
    
    while (iss >> token) {
        if (isdigit(token[0])) {  // �p�G�O�Ʀr
            values.push(stoi(token));
        } else if (token == "(") {  // ���A��
            ops.push('(');
        } else if (token == ")") {  // �k�A��
            while (!ops.empty() && ops.top() != '(') {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.pop(); // ���� '('
        } else if (isOperator(token[0])) {  // �B��l
            while (!ops.empty() && precedence(ops.top()) >= precedence(token[0])) {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.push(token[0]);
        }
    }
    
    // �p��Ѿl���B��
    while (!ops.empty()) {
        int val2 = values.top(); values.pop();
        int val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOp(val1, val2, op));
    }
    
    return values.top();
}

int main() {
    string line;
    while (getline(cin, line)) {  // Ū������ EOF
        if (!line.empty()) {
            cout << evaluate(line) << endl;
        }
    }
    return 0;
}
