#include <bits/stdc++.h>
#define ll long long int
#define vt vector

bool checkkeyword(std::string x){
    char keywords[32][10] = {"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","printf","struct","switch","typedef","union","unsigned","void","scanf","while"};
    for(int i=0; i<32;i++)
        if(keywords[i]==x)
            return true;
    return false;
}

bool checkoperator(char x){
    std::string keyword = "+-*/=%^";
    for(int i=0; i<keyword.size();i++)
        if(keyword[i]==x)
            return true;
    return false;
}

bool checkreloperator(char x){
    std::string keyword = "><!=";
    for(int i=0; i<keyword.size();i++)
        if(keyword[i]==x)
            return true;
    return false;
}

bool checkspecialchar(char x){
    std::string keyword = "$@#(){}[]";
    for(int i=0; i<keyword.size();i++)
        if(keyword[i]==x)
            return true;
    return false;
}

bool bisnum(std::string x){
    for(int i=0; i<x.size();i++)
        if(!isdigit(x[i]))
            return false;
    return true;
}

void postprod(std::string temp){
    if(bisnum(temp))
        std::cout<<temp<<" is a constant"<<"\n";
    else
        std::cout<<temp<<" is inidentifier"<<"\n";
}

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    ifstream fp("input.txt",ios::in);
    string input;
    vt<string> inp;
    while(std::getline(fp, input))
        inp.push_back(input);
    char k;
    int l=1;
    for(auto x: inp){
        cout<<"Line No : "<<l<<"\n";
        string temp="";
        for(int i=0; i<x.size();i++){
            k=x[i];
            if(isalnum(k)){
                temp+=k;
                if(checkkeyword(temp)){
                    cout<<temp<<" is keyword"<<"\n";
                    temp="";
                }
            }
            else{
                if(temp!="")
                        postprod(temp);
                if(checkspecialchar(k))
                    cout<<k<<" is special character"<<"\n";
                else if(checkreloperator(k)){
                    if(k=='=' && x[i+1]!='=')
                        cout<<k<<" is arithematic operator"<<"\n";
                    else if(x[i+1]=='='){
                        i++;
                        cout<<k<<x[i]<<" is relational operator"<<"\n";
                    }
                    else
                        cout<<k<<" is relational operator"<<"\n";
                }
                else if(checkoperator(k))
                    cout<<k<<" is arithematic operator"<<"\n";
                else if(k==',' ||k==';')
                    cout<<k<<" is seperator"<<"\n";
                temp="";
            } 
        }
        l++;
        cout<<"\n";
    }
    fp.close();

    return 0;
}