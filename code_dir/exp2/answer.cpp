#include <bits/stdc++.h>
#define ll long long int
#define vt vector
const unsigned int M = 1000000007;
using namespace std;

char prec[9][9] = {

            /*stack    +    -   *   /   ^   i   (   )   $  */

            /*  + */  '>', '>','<','<','<','<','<','>','>',

            /*  - */  '>', '>','<','<','<','<','<','>','>',

            /*  * */  '>', '>','>','>','<','<','<','>','>',

            /*  / */  '>', '>','>','>','<','<','<','>','>',

            /*  ^ */  '>', '>','>','>','<','<','<','>','>',

            /*  i */  '>', '>','>','>','>','o','o','>','>',

            /*  ( */  '<', '<','<','<','<','<','<','<','p',

            /*  ) */  '>', '>','>','>','>','o','o','>','>',

            /*  $ */  '<', '<','<','<','<','<','<','<','<',

};

 void reduce(vt <char> &stack,int &i){
    if(stack[stack.size()-1]=='i'){
        stack.pop_back();
        stack.push_back('E');
        return;
    }
    else if(stack[stack.size()-1]=='E'){
        stack.pop_back();
        stack.pop_back();
        return;
    }
    else if(stack[stack.size()-1]==')'){
        stack.pop_back();
        stack.pop_back();
        stack.pop_back();
        stack.push_back('E');
        return;
    }
    else{
        cout<<"Error: Operand is missing\n";
        i=-1;
        return;
    }
}

int getindex(char ch,vt <char> &stack){
    int i=1;
    while(ch=='E'){
        ch = stack[stack.size()-i];
        i++;
    }
    switch(ch){
        case '+':
            return 0;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 3;
        case '^':
            return 4;
        case 'i':
            return 5;
        case '(':
            return 6;
        case ')':
            return 7;
        case '$':
            return 8;
    }
    return -1;
}

void printstack(vt <char> &stack){
    for(int i=0; i<stack.size(); i++)
        cout<<stack[i];
    cout<<"\t\t";
}

void printinput(string &s,int pos){
    for(int i=pos; i<s.size(); i++)
        cout<<s[i];
    cout<<"\t\t";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    string s;cin>>s;
    char temp;
    vt <char> stack;
    stack.push_back('$');
    s+='$';

    int i=0,p=0;
    for(int j=0;j<s.size();j++){
        if(s[j]==')')
            p++;
        else if(s[j]=='(')
            p--;
    }
    if(p){
        cout<<"Error: Parathsis is missing\n";
        i=-1;
    }
    else{
    cout<<"STACK\t\tINPUT\t\tACTION\n";
    printstack(stack);
    printinput(s,i);
    cout<<"SHIFT\n";}
    while(i!=-1){
        temp=prec[getindex(stack[stack.size()-1],stack)][getindex(s[i],stack)];
        if(temp=='<'){
            stack.push_back(s[i]);
            printstack(stack);
            printinput(s,i+1);
            cout<<"SHIFT\n";
            i++;
        }
        else if(temp=='>'){
            reduce(stack,i);
            if(i==-1)
                break;
            printstack(stack);
            printinput(s,i);
            cout<<"REDUCE\n";
        }
        else{
            cout<<"\nError";
            if(temp=='p')
                cout<<": Closing parathsis is missing\n";
            else if(temp=='o')
                cout<<": Operator is missing\n";
            i=-1;
        }

        if(stack.size()==3 && stack[stack.size()-1]=='$')
            i=-1;

    }
    if(stack.size()==3 && stack[stack.size()-1]=='$')
        cout<<"ACCEPTED\n";
    else{
        cout<<"REJECTED\n";
    }

    return 0;
}