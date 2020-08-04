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

int mazeMultiPath(int sr, int sc,int er, int ec, string ans){
    if(sr==er && sc==ec){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int jump=1;sr+jump<=er; jump++){
       count+=mazeMultiPath(sr+jump, sc,er,ec, ans+"H"+to_string(jump));
    }
    for(int jump=1;sr+jump<=er && sc+jump<=ec;jump++){
        count+=mazeMultiPath(sr+jump,sc+jump, er, ec,ans+"D"+to_string(jump));
    }
    for(int jump=1;sc+jump<=ec; jump++){
        count+=mazeMultiPath(sr, sc+jump,er,ec,ans+"V"+to_string(jump));
    }
    return count;
}
vector<vector<int>> dir={{0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}};
vector<string>dirN={"R", "E", "U", "N", "L", "W", "D", "S"};

bool isValid(int r,int c,vector<vector<int>>&board ){
    if(r<0||c<0||r>=board.size()|| c>=board[0].size()||board[r][c]==0||board[r][c]==2)
    return false;
    return true;
}

int floodFill(int sr, int sc, int er, int ec, vector<vector<int>>&board,int rad, string ans){
   if(sr == er && sc==ec){
       cout<<ans<<endl;
       return 1;
   }
    int count=0;
    board[sr][sc]=0;
    for (int i=0; i<dir.size(); i++){
        for(int j=1; j<=rad; j++){//magnitude of jump
        int row=sr+j*dir[i][0];
        int col=sc+j*dir[i][1];
        if(isValid(row,col,board)){
            count+=floodFill(row,col,er,ec,board,rad,ans+dirN[i]);

        }
        }
    }
    board[sr][sc]=1;
    return count;
}


void mazePathSet(){
    //cout<<mazePath(0,0,3,3,"")<<endl;
    // vector<string>ans= maze(0,0,2,2);
    // for(string s:ans){
    //     cout<<s<<endl;
    // }
    //cout<<mazeMultiPath(0,0,3,3,"")<<endl;
    int sr=0,sc=0, er=3, ec=3;
    vector<vector<int>>board(er+1,vector<int>(ec+1,1));
    int rad=1;
    cout<<floodFill(sr,sc,er,ec,board,rad,"")<<endl;

}
int coinChangePermInf(vector<int>&arr, int tar,string ans){
    if(tar==0){
        cout<<ans<<endl;
        return 1;
    }

    int count=0;
    for(int ele:arr){
        if(tar-ele>=0)
      count+=coinChangePermInf(arr,tar-ele, ans+to_string(ele)+" ");
    }
    return count;
}

int coinChangeCombInf(vector<int>&arr , int tar,int lidx, string ans){
    if(tar==0){
        cout<<ans<<endl;
        return 1;
    }
    int count =0;
    for(int i=lidx; i<arr.size();i++){
        if(tar-arr[i]>=0){
            count+=coinChangeCombInf(arr, tar-arr[i],i,ans+to_string(arr[i])+" ");
        }
    }
    return count;
}

int coinChangePerm(vector<int>&arr,int lidx, int target,string ans){
    if(target==0){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=lidx;i<arr.size();i++){
        if(target-arr[i]>=0 && arr[i]>=0){
            int temp=arr[i];
            arr[i]=-arr[i];
            count+=coinChangePerm(arr,0,target-temp,ans+to_string(temp)+" ");
            arr[i]=-arr[i];
        }
    }
    return count;  
}

int coinChangeComb(vector<int>&arr,int lidx, int target,string ans){
    if(target==0){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=0;i<arr.size();i++){
        if(target-arr[i]>=0){
count+=coinChangeComb(arr,i+1,target-arr[i],ans+to_string(arr[i])+" ");
        }
    }
    return count;
}

int coinChangePermInfSub(vector<int>&arr,int target,int idx, string ans){
    if(idx==arr.size() || target==0){
        if(target==0){
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count=0;
    if(target-arr[idx]>=0){
        count+=coinChangePermInfSub(arr,target-arr[idx],0,ans+to_string(arr[idx])+" ");
     } 
    count+=coinChangePermInfSub(arr,target,idx+1,ans);
    return count;
}

int coinChangePermSub(vector<int>&arr,int target,int idx,string ans){
    if(idx==arr.size()|| target==0){
        if(target==0){
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count=0;
    if(target-arr[idx]>=0){
        int temp=arr[idx];
        arr[idx]=-arr[idx];
        count+=coinChangePermSub(arr, target-arr[temp],0, ans+to_string(arr[temp])+" ");
    }
    count+=coinChangePermSub(arr,target,idx+1, ans);
    return count;
}
int coinChangeCombInfSub(vector<int>&arr, int target,int idx, string ans){
    if(idx==arr.size() || target==0){
        if(target==0){
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count=0;
    if(target-arr[idx]>=0){
        count+=coinChangeCombInfSub(arr, target-arr[idx],idx,ans+to_string(arr[idx])+" ");
    }
    count+=coinChangeCombInfSub(arr, target,idx+1,ans);
    return count;
}

int coinChangeCombSub(vector<int>&arr, int target, int idx,string ans){
    if(idx==arr.size()|| target==0){
        if(target==0){
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count=0;
    if(target-arr[idx]>=0){
        count+=coinChangeCombSub(arr,target-arr[idx],idx+1,ans+to_string(arr[idx])+" ");
    }
     count+=coinChangeCombSub(arr, target,idx+1, ans );
    return count;
}
int queenComb1D(vector<bool>&boxes,int tnq,int qpsf,int idx,string ans){
    if(tnq==qpsf){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=idx;i<boxes.size();i++){
        count+=queenComb1D(boxes, tnq,qpsf+1,i+1,ans+"b"+to_string(i)+" "+"q"+to_string(qpsf)+" ");
    }
    
    return count;
}

int queenComb1DSub(vector<bool>&boxes,int tnq, int qpsf, int idx,string ans){
    if(tnq==qpsf || idx==boxes.size()){
        if(tnq==qpsf){
            cout<<ans<<endl;
            return 1;
        }
        return 0;

    }
    int count=0;
    count+=queenComb1DSub(boxes, tnq,qpsf+1,idx+1,ans+to_string(idx)+"b q"+to_string(qpsf)+" ");
    count+=queenComb1DSub(boxes, tnq, qpsf,idx+1, ans);
    return count;
}
int queenPerm1D(vector<bool>&boxes,int idx,int tnq,int qpsf,string ans){
    if(qpsf==tnq){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=idx;i<boxes.size();i++)

    {if(!boxes[i]){
        boxes[i]=true;
        count+=queenPerm1D(boxes,0,tnq,qpsf+1, ans+" "+to_string(i)+"b q"+to_string(qpsf)+"");
        boxes[i]=false;
    }
        
    }
    return count;
}

int queenPerm1DSub(vector<bool>&boxes,int idx, int tnq,int qpsf, string ans){
    if(qpsf==tnq || idx==boxes.size()){
        if(qpsf==tnq){
cout<<ans<<endl;
        return 1;
        }
        return 0;
        
    }
    int count=0;
    if(boxes[idx]){
        boxes[idx]=true;
        count+=queenPerm1DSub(boxes,0,tnq,qpsf+1,ans+" "+to_string(idx)+"b q"+to_string(qpsf)+" ");
    boxes[idx]=false;
    }
    count+=queenPerm1DSub(boxes,idx+1,tnq, qpsf,ans);
    return count;
}

void Queen1D(){
    vector<bool>boxes(5, false);
    int tnq=3;
// cout<<queenComb1D(boxes,tnq,0,0,"")<<endl;
// cout<<queenComb1DSub(boxes,tnq,0,0,"")<<endl;
// cout<<queenPerm1D(boxes,0,tnq,0,"")<<endl;
cout<<queenPerm1DSub(boxes,0,tnq,0,"")<<endl;

}
void coinChange(){
    vector<int> arr={2,3,5,7};
    int tar=10;
    //int a=coinChangePermInf(arr,tar,"");
    //cout<<a<<endl;
    //int b=coinChangeCombInf(arr,tar,0,"");
    //cout<<b<<endl;
    // int c=coinChangePerm(arr,0,tar,"");
    // cout<<c<<endl;
    int d=coinChangePermInfSub(arr,tar,0,"");
    cout<<d<<endl;
    int e=coinChangeCombInfSub(arr,tar,0,"");
    cout<<e<<endl;
    int f=coinChangePermSub(arr,tar,0,"");
    cout<<f<<endl;
    int g=coinChangeCombSub(arr,tar,0,"");
    cout<<g<<endl;
}
int queenComb2D(vector<vector<bool>>&boxes, int tnq,int idx, int qpsf,string ans){
    if(qpsf==tnq){
        cout<<ans<<endl;
        return 1;
    }
    
    int count=0;
    for(int i=idx;i<boxes.size()*boxes[0].size();i++){
        int r=i/boxes.size();
        int c=i% boxes[0].size();
        count+=queenComb2D(boxes, tnq,i+1, qpsf+1, ans+"("+to_string(r)+" "+to_string(c)+" ) ");
    }

    return count;
}
int queenPerm2D(vector<vector<bool>>&boxes,int tnq,int idx,int qpsf,string ans){
    if(tnq==qpsf){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=idx;i<boxes.size()*boxes[0].size();i++){
        int r=i/boxes.size();
        int c=i%boxes[0].size();
        count+=queenPerm2D(boxes, tnq,0,qpsf+1,ans+"("+to_string(r)+to_string(c)+") ");


    }
    return count;
}
void Queen2D(){
    vector<vector<bool>>boxes(4, vector<bool>(4,0));
    int tnq=4;
    cout<<queenComb2D(boxes,tnq,0,0,"");
    cout<<queenPerm2D(boxes, tnq,0,0,"");

}


int main(){
    //mazePathSet();
    //coinChange();
    //Queen1D();
    Queen2D();
    return 0;
}