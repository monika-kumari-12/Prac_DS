#include <iostream>
#include<vector>
using namespace std;
void printInc(int a,int b){
if(a==b+1)return;
cout<<a<<" ";
printInc(a+1,b);
}
void printDec(int a, int b){
    if(a==b+1)return;
    printDec(a+1, b);
    cout<<a<<" ";
}

void printEvenOdd(int a,int b){
    if(a== b+1)return;
    if(a%2 ==0)
    cout<<a<<" ";
    printEvenOdd(a+1,b);
    if(a%2 !=0)
    cout<<a<<" ";

}
vector<string> permutation(string s){
    if(s.length()==1){
        vector<string>base;
        base.push_back(s);
        return base;
    }

    char ch=s[0];
    string nstr=s.substr(1);
    vector<string>smallAns=permutation(nstr);
    vector<string>myAns;
    for(string s:smallAns){
        for(int i=0;i<=s.length();i++)
        myAns.push_back(s.substr(0,i)+ch+s.substr(i));

    }
    return myAns;



}
void solve(){
    printInc(1,10);
    cout<<"\n";
    printDec(2,9);
    cout<<"\n";
    printEvenOdd(2,15);
    cout<<"\n";
    string s="abc";
    vector<string>ans=permutation(s);
    for(string s:ans){
        cout<<s<<" ";
    }
}

int main(){
    solve();
    return 0;
}