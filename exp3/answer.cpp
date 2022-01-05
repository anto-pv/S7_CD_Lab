#include <bits/stdc++.h>
#define vt vector
#define ll long long int

int i=0;
std::string input;
bool E(),F(),Ep(),T(),Tp();
bool E(){
    std::cout<<"E";
    if(T()){
        if(Ep())
            return true;
        else
            return false;
    }
    else
        return false;
}

bool Tp(){
    std::cout<<"Tp";
    if(input[i]=='/' || input[i] =='*'){
        i++;
        if(F())
            if(Tp())
                return true;
            else
                return false;
        else
            return false;
    }
    else
        return true;
}

bool T(){
    std::cout<<"T";
    if(F()){
        if(Tp())
            return true;
        else
            return false;
    }
    else
        return false;
}

bool Ep(){
    std::cout<<"Ep";
    if(input[i]=='+' || input[i+1] =='-'){
        i++;
        if(T())
            if(Ep())
                return true;
            else
                return false;
        else
            return false;
    }
    else
        return true;
}

bool F(){
    std::cout<<"F";
    if(input[i]=='('){
        i++;
        if(E()){
            if(input[i]==')'){
                i++;
                return true;
            }
            else
                return false;
        }
        else
            return false;
    }
    else if(isalnum(input[i])){
        i++;
        return true;
    }
    else
        return false;
}

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    ifstream fp("input.txt",ios::in);
    getline(fp,input);
    fp.close();
    cout<<"\nRecursive descent parsing for the following grammar\n"; 
    cout<<"\nE->TE'\nE'->+TE'/-TE'/@\nT->FT'\nT'->*FT'//FT'/@\nF->(E)/ID\n\n"; 
    cout<<input<<"\n";
    if(E()){
        if(i==input.size())
            cout<<"string is accepted";
        else
            cout<<"string is not accepted";
    }
    else
        cout<<"string is not accepted"<<i;
    return 0;
}