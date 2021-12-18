/*
H - 括号匹配
*/
#include <bits/stdc++.h>
using namespace std;

bool isLeftBracket( char ch ) {
    bool isleft = false;
    switch ( ch ) {
    case '(':
    case '[':
    case '{':
        isleft = true;
        break;
    default:
        break;
    }
    return isleft;
}

bool isRightBracket( char ch ) {
    bool isright = false;
    switch ( ch ) {
    case ')':
    case ']':
    case '}':
        isright = true;
        break;
    default:
        break;
    }
    return isright;
}

bool isMatchedWithTop( char ch, stack<char> charStack ) {
    bool isMatched = false;
    if ( charStack.empty() ) return isMatched;

    char top = charStack.top();
    switch ( ch ) {
    case '(':
        if ( top == ')' ) isMatched = true;
        break;
    case '[':
        if ( top == ']' ) isMatched = true;
        break;
    case '{':
        if ( top == '}' ) isMatched = true;
        break;
    case ')':
        if ( top == '(' ) isMatched = true;
        break;
    case ']':
        if ( top == '[' ) isMatched = true;
        break;
    case '}':
        if ( top == '{' ) isMatched = true;
        break;
    default:
        break;
    }
    return isMatched;
}

int main() {
    stack<char> brackets;
    string str;
    bool islegal = false, isbreaked = false;

    getline( cin, str );
    for ( auto it = str.cbegin(); it != str.end(); ++it ) {
        if ( isLeftBracket( *it ) ) {
            brackets.push( *it );
            // cout << "pushed: " << brackets.top() << endl;
        } else if ( isRightBracket( *it ) ) {
            if ( !isMatchedWithTop( *it, brackets ) ) {
                // cout << "breaked with: " << *it << endl;
                isbreaked = true;
                break;
            } else {
                // cout << "poped: " << brackets.top() << endl;
                brackets.pop();
            }
        }
    }

    if ( !isbreaked && brackets.empty() ) islegal = true;
    cout << ( islegal ? "Yes" : "No" ) << endl;
    return 0;
}

/*
input:
(a+b)!=c

output:
Yes
*/