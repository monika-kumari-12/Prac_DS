#include<iostream>
#include<vector>
using namespace std;

int mazePath(int sr,int sc, int er, int ec, string ans){
    if(sr==er && sc ==ec){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    if(sc+1<=ec){
        count+=mazePath(sr, sc+1, er,ec, ans+"H");
    }
    if(sr+1<=er && sc+1<=ec){
        count+=mazePath(sr+1, sc+1, er, ec, ans+"D");

    }
    if(sr+1<=er){
        count+=mazePath(sr+1, sc,er, ec,ans+"V");
    }
    return count;

}

vector<string> maze(int sr, int sc,int er,int ec){
    if(sr==er && sc==ec){
        vector<string>base;
        base.push_back("");
        return base;
    }

    vector<string>myAns;
    if(sc+1<=ec){
    vector<string>Hor=maze(sr, sc+1, er, ec);
    for(string s:Hor){
        myAns.push_back("H"+s);
    }
    }
    if(sr+1<=er && sc+1<=ec){
        vector<string>Diag=maze(sr+1,sc+1,er, ec);
        for(string s:Diag){
            myAns.push_back("D"+s);
        }

    }
    if(sr+1<=er){
        vector<string>Ver=maze(sr+1, sc, er,ec);
        for(string s:Ver){
            myAns.push_back("V"+s);
        }
    }
    return myAns;

}

void mazePathSet(){
    //cout<<mazePath(0,0,3,3,"")<<endl;
    vector<string>ans= maze(0,0,2,2);
    for(string s:ans){
        cout<<s<<endl;
    }
    
}
int main(){
    mazePathSet();
    return 0;
}