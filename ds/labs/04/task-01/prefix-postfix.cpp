#include "../stack/mystack.h"

int precedence(char);
bool isOperator(char);
char* infixToPostfix(char*, int);
char* infixToPrefix(char*, int);
bool isOperator(string);
int calculateValue(int, int, string);
int evaluateReversePolishNotation(string*, int);

int main() {
    //char arr[] = { '(', '(', '(', 'A', '+', 'B', ')', '*', '(', 'C', '-', 'E', ')', ')', '/', '(', 'F', '+', 'G', ')', ')' };
    //char arr[] = { '(', '(', 'A', '+', 'B', ')', '*', '(', 'C', '-', 'D', ')', ')', '\0' };
    //char arr[] = { '(','a','+','b','+','c' ,')' };
    //char arr[] = { '(', 'A', '+', 'B', '*', 'C', ')' };
    char arr[] = { '(', 'A', '+', 'B', '*', 'C', '-', 'D', '/', 'E', ')' };

    char* postfix = infixToPostfix(arr, sizeof(arr) / sizeof(char));

    cout << "Postfix: ";
    for (int i = 0; i < postfix[i] != '\0'; i++) { cout << postfix[i] << " "; }
    cout << endl;
    delete[] postfix;

    //-----------------------------------------------------------------------------------------------

    //char array[] = { '(', '(', '(', 'A', '+', 'B', ')', '*', '(', 'C', '-', 'E', ')', ')', '/', '(', 'F', '+', 'G', ')', ')' };
    //char array[] = { '(', '(', 'A', '+', 'B', ')', '*', '(', 'C', '-', 'D', ')', ')', '\0' };
    //char array[] = { '(','a','+','b','+','c' ,')' };
    //char array[] = { '(', 'A', '+', 'B', '*', 'C', ')' };
    char array[] = { '(', 'A', '+', 'B', '*', 'C', '-', 'D', '/', 'E', ')' };

    char* prefix = infixToPrefix(array, sizeof(array) / sizeof(char));

    cout << "Prefix: ";
    for (int i = 0; i < prefix[i] != '\0'; i++) { cout << prefix[i] << " "; }
    cout << endl;
    delete[] prefix;

    //-----------------------------------------------------------------------------------------------

    //string tokens[] = { "4","13","5","/","+" };
    //string tokens[] = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
    //string tokens[] = { "5", "1", "2", "+", "4", "*", "+", "3", "-" }; // = 14;           
    string tokens[] = { "/" };
    cout << "Evaluation of Reverse Polish Notation: " << evaluateReversePolishNotation(tokens, sizeof(tokens) / sizeof(string));
    cout << endl;
    return 0;
}


int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '%') return 2;
    return 0;
}

bool isOperator(char c) { return c == '+' || c == '-' || c == '*' || c == '/' || c == '%'; }

char* infixToPostfix(char* arr, int size) {
    MyStack<char> st(30);
    char* array = new char[size + 1];
    int k = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == '(') { st.push(arr[i]); }
        else if ((arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= 'A' && arr[i] <= 'Z')) { array[k++] = arr[i]; }

        else if (isOperator(arr[i])) {
            while (!st.isEmpty() && st.top() != '(' && (precedence(st.top()) >= precedence(arr[i]))) {
                array[k++] = st.top();
                st.pop();
            }
            st.push(arr[i]);
        }

        else if (arr[i] == ')') {
            while (!st.isEmpty() && st.top() != '(') {
                array[k++] = st.top();
                st.pop();
            }
            if (!st.isEmpty()) st.pop(); // pop '('
        }
    }

    // pop any remaining operators in stack {NOT IMPORTANT}
    while (!st.isEmpty()) {
        array[k++] = st.top();
        st.pop();
    }
    array[k] = '\0';
    return array;
}

char* infixToPrefix(char* arr, int size) {
    // reverse and swap brackets
    char* reversed = new char[size + 1];
    for (int i = 0; i < size; i++) {
        if (arr[size - i - 1] == '(')      reversed[i] = ')';
        else if (arr[size - i - 1] == ')') reversed[i] = '(';
        else                               reversed[i] = arr[size - i - 1];
    }
    reversed[size] = '\0';

    // run postfix on reversed array
    MyStack<char> st(30);
    char* temp = new char[size + 1];
    int k = 0;

    for (int i = 0; i < size; i++) {
        if (reversed[i] == '(') { st.push(reversed[i]); }
        else if ((reversed[i] >= 'a' && reversed[i] <= 'z') || (reversed[i] >= 'A' && reversed[i] <= 'Z')) { temp[k++] = reversed[i]; }

        else if (isOperator(reversed[i])) {
            while (!st.isEmpty() && st.top() != '(' && (precedence(st.top()) > precedence(reversed[i]))) {
                // important: >= converts to > in prefix because left associative becomes right associative while reversing
                temp[k++] = st.top();
                st.pop();
            }
            st.push(reversed[i]);
        }

        else if (reversed[i] == ')') {
            while (!st.isEmpty() && st.top() != '(') {
                temp[k++] = st.top();
                st.pop();
            }
            if (!st.isEmpty()) st.pop(); // pop '('
        }
    }

    // pop any remaining operators in stack {NOT IMPORTANT}
    while (!st.isEmpty()) {
        temp[k++] = st.top();
        st.pop();
    }
    temp[k] = '\0';

    // reverse the result
    char* array = new char[k + 1];
    for (int i = 0; i < k; i++) { array[i] = temp[k - 1 - i]; }
    array[k] = '\0';

    delete[] reversed;
    delete[] temp;
    return array;
}

bool isOperator(string s) { return s == "+" || s == "-" || s == "*" || s == "/" || s == "%"; }

int calculateValue(int a, int b, string s) {
    if (s == "+") return a + b;
    else if (s == "-") return a - b;
    else if (s == "*") return a * b;
    else if (s == "%") return a % b;
    else if (s == "/") {
        if (b == 0) {
            cout << "Error: Division by zero\n";
            exit(1);
        }
        return a / b;
    }
    return -1;
}

int evaluateReversePolishNotation(string* tokens, int size) {
    MyStack<int> st(30);
    int result = 0;
    for (int i = 0; i < size; i++) {
        if (isOperator(tokens[i])) {
            if (st.size() < 2) {
                cout << "Error: Not enough operands\n";
                exit(1);
            }
            int b = st.pop();
            int a = st.pop();
            st.push(calculateValue(a, b, tokens[i]));
        }
        else {
            st.push(stoi(tokens[i]));
        }
    }
    return st.top();
}