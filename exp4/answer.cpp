#include <bits/stdc++.h>
#define ll long long int
#define vt vector
const unsigned int M = 1000000007;
using namespace std;

/*
E  -> TR
R  -> +T R| #
T  -> F Y
Y  -> *F Y | #
F  -> (E) | i
*/


void first(){

}

void follow(){

}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    ifstream fp("input.txt",ios::in);
    string input;
    vt<string> inp;
    unordered_map <char,vt <char>> firstMap, followMap;
    while(std::getline(std::cin, input)){
        string temp="";
        for(int i=0;i<input.size();++i){
            if(!((input[i]=='-'&& input[++i]=='>')|| input[i]==' '|| input[i]=='|')){
                temp=temp+input[i];
            }
            if(input[i]=='|'){
                inp.push_back(temp);
                temp=input[0]; 
            }
        }
        inp.push_back(temp);
    }
    fp.close();
    for(int i=0;i<inp.size();++i){
        cout<<inp[i]<<"\n";
    }
    first();
    follow();
    //how to display vector;
    return 0;
}


