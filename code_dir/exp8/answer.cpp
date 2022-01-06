#include<bits/stdc++.h>
#define vt vector
#define umap unordered_map

int main(){
    using namespace std;

    string a,b,c,d;
    vt <string> va,vb,vc,vd;
    cout<<"Enter the three address code: operator var1 var2 res\n";
    for(int i=0; i<4;i++){
        cin>>a>>b>>c>>d;
        va.push_back(a);
        vb.push_back(b);
        vc.push_back(c);
        vd.push_back(d);
    }
    char op;string var1,var2,res,temp;
    umap <string,string> prod;
    umap <string,string> trash;
    for(int i=0; i<va.size(); i++){
        temp="";
        if(vb[i].substr(0,1)>="A" && vb[i].substr(0,1)<="Z" && trash.count(vb[i]))
            vb[i]=trash[vb[i]];
        if(vc[i].substr(0,1)>="A" && vc[i].substr(0,1)<="Z" && trash.count(vc[i]))
            vc[i]=trash[vc[i]];
        temp=temp+va[i]+vb[i]+vc[i];
        if(!prod.count(temp))
            prod[temp]=vd[i];
        else
            trash[vd[i]]=prod[temp];
    }
    for(int i=0; i<va.size(); i++){
        if(!trash.count(vd[i]))
            cout<<va[i]<<" "<<vb[i]<<" "<<vc[i]<<" "<<vd[i]<<"\n";
    }
    return 0;
}
/*
* a b X1
* X1 d X2
* a b X3
+ X2 X3 X4
*/