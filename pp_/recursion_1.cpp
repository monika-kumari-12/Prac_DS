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

vector <string> words={"@#$","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz","#^&","$%^"};
vector<string> nokia(string s){
    if(s.length()==0){
        vector<string>base;
        base.push_back("");
        return base;
    }
   int idx=s[0]-'0';
   string word=words[idx];
   string nstr=s.substr(1);
   vector<string>smallAns=nokia(nstr);
   vector<string>myAns;
   for(string s:smallAns){
       for(int i=0;i<word.length();i++){
           myAns.push_back(word[i]+s);
       }

   }
   return myAns;

}
int nokia_count(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    int idx=s[0]-'0';
    string word=words[idx];
    for(int i=0; i<word.length();i++){
        string nstr=s.substr(1);
        count+=nokia_count(nstr, ans+word[i]);
    }
    return count;
}
//10110
int nokia_01(string s, string ans){
    
    if(s.length()==0){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;

    int idx=s[0]-'0';
    string word=words[idx];
    for(int i=0; i<word.length();i++){
        string nstr=s.substr(1);
        count+=nokia_01(nstr, ans+word[i]);
    }
    if(s.length()>1){
        int idx1=s[1]-'0';
        int num=idx*10+idx1;
        if(num>=10 && num<=11){
            word=words[num];
            for(int i=0; i<word.length();i++){
                count+=nokia_01(s.substr(2),ans+word[i]);
            }
        }

    }
    return count;

}

void solve(){
    // printInc(1,10);
    // cout<<"\n";
    // printDec(2,9);
    // cout<<"\n";
    // printEvenOdd(2,15);
    // cout<<"\n";
    // string s="abc";
    // vector<string>ans=permutation(s);
    // for(string s:ans){
    //     cout<<s<<" ";
    // }
    // vector<string> keys=nokia("145");
    // for(string s:keys){
    //     cout<<s<<" ";
    // }
   int c= nokia_count("123","");
   cout<<c;
}

int main(){
    solve();
    return 0;
}