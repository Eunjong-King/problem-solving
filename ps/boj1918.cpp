#include <stack>
#include <iostream>
#include <string>
using namespace std;

int getOrder(char& c){
    if(c=='+' || c=='-'){
        return 0;
    }
    else if(c == '*' || c=='/'){
        return 1;
    }
    else{
        return 2;
    }
}

int main(void){
    string mid;
    cin >> mid;
    stack<char> s;
    char top;
    int orderT, orderC;

    for(auto c : mid){
        if(c >= 'A' && c <= 'Z'){
            cout << c;
        }
        else if(c == '('){
            s.push(c);
        }
        else if(c == ')'){
            top = s.top();
            while(top != '('){
                cout << top;
                s.pop();
                top = s.top();
            }
            s.pop();
        }
        else{
            if(s.empty()){
                s.push(c);
            }
            else{
                top = s.top();
                orderT = getOrder(top);
                orderC = getOrder(c);

                while(!s.empty() && orderC <= orderT && top != '('){
                    cout << top;
                    s.pop();
                    if(!s.empty()){
                        top = s.top();
                        orderT = getOrder(top);
                    }
                }
                s.push(c);
            }
        }
    }

    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
    cout << endl;

    return 0;
}