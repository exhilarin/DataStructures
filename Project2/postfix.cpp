#include <iostream>
#include <stack>
#include <string>
using namespace std;

string getOp(char c)
{
    if (c == '+') return "AD";
    if (c == '-') return "SB";
    if (c == '*') return "ML";
    if (c == '/') return "DV";
}

string makeTemp(int &i)
{
    return "TEMP" + to_string(i++);
}

void processOperator(stack<string> &st, char opChar, int &i)
{
    string right = st.top(); st.pop();
    string left  = st.top(); st.pop();

    string temp = makeTemp(i);
    string op   = getOp(opChar);

    cout << "LD " << left << endl;
    cout << op << " " << right << endl;
    cout << "ST " << temp << endl;
    st.push(temp);
}

int main()
{
    string postfix;
    cin >> postfix;
    stack<string> st;

    int i = 1;
    for (char c : postfix) 
    {
        if (isalpha(c))
            st.push(string(1, c));
        else
            processOperator(st, c, i);
    }
    return 0;
}
