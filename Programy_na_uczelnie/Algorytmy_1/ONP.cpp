#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <sstream>
#include <map>
using namespace std;

//Priority
int precedence(char op)
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

//INFIX to ONP
string infixToPostfix(const string &expr)
{
    stack<char> st;
    string output;

    for (size_t i = 0; i < expr.size(); i++)
    {
        char c = expr[i];

        if (isspace(c)) continue;

        if (isalnum(c))
        {
            output += c;
            output += ' ';
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                output += st.top();
                output += ' ';
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        else if (isOperator(c))
        {
            while (!st.empty() && precedence(st.top()) >= precedence(c))
            {
                output += st.top();
                output += ' ';
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        output += st.top();
        output += ' ';
        st.pop();
    }

    return output;
}

//ONP to INFIX
string postfixToInfix(const string &expr)
{
    stack<string> st;
    stringstream ss(expr);
    string token;

    while (ss >> token)
    {
        // operand
        if (isalnum(token[0]) && token.size() == 1)
        {
            st.push(token);
        }
        // operator
        else if (isOperator(token[0]) && token.size() == 1)
        {
            if (st.size() < 2)
            {
                cerr << "Błąd: niepoprawne wyrażenie ONP\n";
                return "";
            }
            string b = st.top();
            st.pop();
            string a = st.top();
            st.pop();
            string exprInfix = "(" + a + " " + token + " " + b + ")";
            st.push(exprInfix);
        }
        else
        {
            cerr << "Błąd: nieznany token: " << token << endl;
            return "";
        }
    }

    if (st.size() != 1)
    {
        cerr << "Błąd: niepoprawne wyrażenie ONP\n";
        return "";
    }

    return st.top();
}

// --- Test ---
int main()
{
    string infix = "A*(B+C)/D";
    string postfix = infixToPostfix(infix);
    string backToInfix = postfixToInfix(postfix);

    cout << "Wyrazenie infiksowe: " << infix << endl;
    cout << "ONP: " << postfix << endl;
    cout << "Z powrotem na infiks: " << backToInfix << endl;

    return 0;
}
