#include <bits/stdc++.h>
#define ll long long int
#define vt vector
#define umap unordered_map
const unsigned int M = 1000000007;
using namespace std;

vt <string> qua;
//umap <char,vt <char>> firstMap
int prec(char c) {
    switch(c) {
        case '+':
            return 1;
            break;
        case '-':
            return 1;
            break;
        case '*':
            return 2;
            break;
        case '/':
            return 2;
            break;
        case '%':
            return 3;
            break;
        default:
            return 0;
            break;
    }
}

string postfix(string str){
    vt <char> stack;
    string postfix;
    for(int i=0;i<str.size();++i) {
        if(str[i]=='(')
            stack.push_back(str[i]);
        else if(str[i]==')') {
            while(stack[stack.size()-1]!='(') {
                postfix+=stack[stack.size()-1];
                stack.pop_back();
                }
            stack.pop_back();
            }
        else if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')) {
            postfix+=str[i];
            }
        else if(str[i]=='%' || str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/') {  
            if(stack.size()-1==-1 || stack[stack.size()-1]=='(') {
                stack.push_back(str[i]);
                }
            else if(prec(str[i])>=prec(stack[stack.size()-1])) {
                stack.push_back(str[i]);
                }
            else if(prec(str[i])<prec(stack[stack.size()-1])) {
                while(prec(str[i])<prec(stack[stack.size()-1])) {
                    postfix+=stack[stack.size()-1];
                    stack.pop_back();
                }
                stack.push_back(str[i]);
                }
            }
        }
    while(stack.size()-1!=-1) {
        postfix+=stack[stack.size()-1];
        stack.pop_back();
        }
    return postfix;
}

void quatrup(string input){
    string temp;
    int i=0;
    while(input.size()>4){
        if(input[i]=='*'|| input[i]=='/'|| input[i]=='+'|| input[i]=='-'){
            temp=input.substr(i-2,3);
            qua.push_back(temp);
            input=input.substr(0,i-2)+to_string(qua.size())+input.substr(i+1,input.size());
            i-=2;
            //cout<<input<<" "<<temp<<"\n";
        }
        ++i;
    }
    qua.push_back(input);
}

char chdig(char x){
    isdigit(x)? return 'X'+x : return x ;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    ifstream fp("input.txt",ios::in);
    string input;
    vt<string> inp;
    while(std::getline(fp, input)){
        string temp="";
        for(int i=0;i<input.size();++i)
            if(!(input[i]=='='|| input[i]==' '))
                temp=temp+input[i];
        temp = postfix(temp);
        inp.push_back(temp);
    }
    fp.close();
    for(int i=0;i<inp.size();++i){
        cout<<inp[i]<<"\n";
        quatrup(inp[i]);
    }
    cout<<"\nQuadruple: \n\n";
    cout<<"\toperator\toperand 1\toperand 2\t result\n";
    for (int i = 0; i < qua.size(); ++i){
        //cout<<qua.size()<<qua[i];
         if(qua[i].size()==2)
            cout<<"\t\t\t\t"<<qua[i][1]<<"\t"<<qua[i][0]<<"\n";
        else if(qua[i].size()==4)
            cout<<"\t"<<qua[i][3]<<"\t"<<qua[i][2]<<"\t"<<qua[i][1]<<"\t"<<qua[i][0]<<"\n";
        else
            cout<<"\t"<<chdig(qua[i][2])<<"\t"<<qua[i][0]<<"\t"<<qua[i][1]<<"\tX"<<i+1<<"\n";
    }
   
    return 0;
}

/*
a=b+c*c
c=a+b-d
a=c+b
b=a

replace 1 with x1
1= c*c
a= b+1
2=a+b
c=2-d
a=c+b
b=a

.............

a=2
3=2+b
c=4
4=3-d
a|=2
a=5
a=c+b
b=a

*/
