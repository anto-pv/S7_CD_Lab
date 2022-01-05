#include <bits/stdc++.h>
#define ll long long int
#define vt vector
#define umap unordered_map
const unsigned int M = 1000000007;
using namespace std;

umap <char,vt <char>> firstMap, followMap;
umap<char, int> check;
/*input.txt
E  = -T-R
R  = -T R| #
T  = F Y
Y  = *F Y | #
F  = (E) | i
*/


void first(int i,vt <string> &inp){
    if(isalnum(inp[i][1]) && inp[i][1]!='i'){
        if(inp[i][0]!=inp[i][1]){
        if(check[inp[i][1]]!=1){
            for(int t=0;t<inp.size();++t){
                if(inp[t][0]==inp[i][1])
                    first(t,inp);
            }
            check[inp[i][1]]=1;
        }        
        vt <char> tempo=firstMap[inp[i][1]];
        int jmax= firstMap[inp[i][0]].size();
        for( int k=0;k<tempo.size();++k){
            int f=0;
            for(int j=0;j<jmax; ++j){
                if(firstMap[inp[i][0]][j]==tempo[k]){
                    f=1;
                    break;
                }
            }
            if(!f)
                firstMap[inp[i][0]].push_back(tempo[k]);
        }}
    }
    else
        firstMap[inp[i][0]].push_back(inp[i][1]);
}

void follow(char p, vt <string> &inp){
    if(check[p]!=1){
    for(int i=0;i<inp.size(); ++i){
        for(int j=1; j<inp[i].size(); ++j){
            if(inp[i][j]==p){
                if(j==inp[i].size()-1){
                    if(p!=inp[i][0]){
                    follow(inp[i][0],inp);
                    vt <char> tempo=followMap[inp[i][0]];
                    int jmax= followMap[p].size();
                    for(int m=0; m<tempo.size(); ++m){
                        int f=0;
                        for(int j=0;j<jmax; ++j){
                            if(tempo[m]==followMap[p][j]){
                                f=1;
                                break;
                            }
                        }
                        if(!f)
                            followMap[p].push_back(tempo[m]);
                    }
                    }
                }
                else if(isalnum(inp[i][j+1]) && inp[i][j+1]!='i'){
                    vt <char> tempo=firstMap[inp[i][j+1]];
                    int jmax= followMap[p].size();
                    for( int k=0;k<tempo.size();++k){
                        if(tempo[k]=='#'){
                            follow(inp[i][j+1],inp);
                            vt <char> tempo2=followMap[inp[i][j+1]];
                            int jmax2 = followMap[p].size();
                            for(int m=0; m<tempo2.size(); ++m){
                                int f=0;
                                for(int j=0;j<jmax2; ++j){
                                    if(tempo2[m]==followMap[p][j]){
                                        f=1;
                                        break;
                                    }
                                }
                                if(!f)
                                    followMap[p].push_back(tempo2[m]);
                            }
                        }
                        else{
                            int f=0;
                            for(int j=0;j<jmax; ++j){
                            if(followMap[p][j]==tempo[k]){
                                f=1;
                                break;
                            }
                            }
                            if(!f)
                                followMap[p].push_back(tempo[k]);
                        }
                    }
                }
                else
                    followMap[p].push_back(inp[i][j+1]);
            }
        }
    }
    check[p]=1;
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    ifstream fp("input.txt",ios::in);
    string input;
    vt<string> inp;
    while(std::getline(fp, input)){
        string temp="";
        for(int i=0;i<input.size();++i){
            if(!(input[i]=='='|| input[i]==' '|| input[i]=='|')){
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
        //cout<<inp[i]<<"\n";
        if(check[inp[i][0]]!=1){
            for(int j=0;j<inp.size();++j){
                if(inp[j][0]==inp[i][0])
                    first(j,inp);
            }
            check[inp[i][0]]=1;
        }
    }
    for(auto x:firstMap ){
        cout<<"First("<<x.first<<") = { ";
        for(auto y: x.second){
            cout<<y<<", ";
        }
        cout<<" }\n";
    }
    cout<<"..............................\n";
    //follow(inp[0][0]);
    //how to display vector;
    check.clear();
    followMap['E'].push_back('$');
    for(auto x: firstMap){
        follow(x.first,inp);
    }
    for(auto x:followMap ){
        cout<<"Follow("<<x.first<<") = { ";
        for(auto y: x.second){
            cout<<y<<", ";
        }
        cout<<" }\n";
    }
    return 0;
}
