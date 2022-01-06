#include<bits/stdc++.h>
#define vt vector

int main(){
    using namespace std;

    ifstream fp("input.txt",ios::in);
    string input;
    vt <string> inp;
    while(getline(fp,input)){
        inp.push_back(input);
    }
    fp.close();
    char rega,regb,regd;
    for(auto x: inp){
        cout<<"MOV AX ["<<x[1]<<"]\n";
        if(x[0]=='+')
            cout<<"ADD AX ["<<x[2]<<"]\n";
        else if(x[0]=='-')
            cout<<"SUB AX ["<<x[2]<<"]\n";
        else if (x[0]=='*'){
            cout<<"MOV BX ["<<x[2]<<"]\n";
            cout<<"MUL BX"<<"\n";
        }
        else if (x[0]=='/'){
            cout<<"MOV BX ["<<x[2]<<"]\n";
            cout<<"DIV BX"<<"\n";
        }
        cout<<"MOV ["<<x[3]<<"] AX"<<"\n";
    }
    return 0;
}