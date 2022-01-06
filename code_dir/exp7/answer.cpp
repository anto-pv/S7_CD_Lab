#include<bits/stdc++.h>
#define vt vector
#define umap unordered_map

int main(){
    using namespace std;

    string input;
    vt <string> inp;
    ifstream fp("input.txt",ios::in);
    while(getline(fp,input))
        inp.push_back(input);
    fp.close();
    cout<<"Enter the number of unrolls required:\n";
    int n=2;
    //this code only work for max of loop is mutiple of loop unrolls
    //cin>>n;
    int i=0,t=0,cond=0;
    string ci="",gi="";
    for(auto x: inp){
        for(int k=0; k<x.size();k++){
            if(x[k]=='='){
                k++;
                while(x[k]!=';'){
                    if(x[k]>='0' && x[k]<'9'){
                        i=i*pow(10,ci.size())+((int)x[k]-48);
                        ci+=x[k];
                    }
                    k++;
                }
            }
            if(x[k]=='<'){
                k++;
                ci="";
                while(x[k]!=')'){
                    if(x[k]>='0' && x[k]<'9'){
                        t=t*pow(10,ci.size())+((int)x[k]-48);
                        ci+=x[k];
                    }
                    k++;
                }
            }
            if(x[k]=='{' || cond==1){
                cond = 1;
                k++;
                while(x[k]!='}' && k<x.size()){
                    gi+=x[k];
                    k++;
                }
                if(x[k]=='}')
                    cond=0;
            }
        }}
    cout<<i<<gi;

    ofstream sp("unrolledLoop.txt",ios::out);
    sp<<"for(int i="<<i<<"; i<"<<t<<"; i+="<<n<<" ){";
    for(int i=0; i<n; i++){
        sp<<"\n"<<gi<<"\n\ti++;";
    }
    sp<<"\n}";
    sp.close();

    return 0;
}

/*
input.txt
------------------------
for(int i= 0; i<10;i++){
    print("Hello world");
}
*/