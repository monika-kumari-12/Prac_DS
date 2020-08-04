public class l002{
    public static void main(String[] args){
        solve();

    }

    public static void solve(){
        //floodfillSet();
        coinChangeSet();


    }
    public static void floodfillSet(){
        int[][] board=new int[4][4];
        //   int a=longestPath(0, 0, 3, 3, board, "");
        //   System.out.println(a);
    
          pair ansP=floodfill_longestPath(0,0,3,3, board);
          System.out.println(ansP.str+"-->"+ansP.len);
    
          Pair ansPShortest=floodfillShortestPath(0, 0, 3, 3, board);
          System.out.println(ansPShortest.s+"-->"+ansPShortest.len);
    
    }

    public static void coinChangeSet(){
        int[] arr={2,3,5,7};
        int tar=10;
        int a=coinchangePer(arr, tar,"");
        System.out.println("infinite permutation"+a);
        int b=coinchangeComb(arr, tar, 0, "");
        System.out.println("infinite comb"+b);
        boolean[] vis=new boolean[arr.length];
        int c=permuationWithoutRep(arr, tar, vis, "");
        System.out.println(" permutation"+c);

        int d=combinationWithoutRep(arr, tar, 0, "");
        System.out.println("comb"+d);
    }
    
    static int[][]dir={{1,0},{0,-1},{-1,0},{0,1}};
    static String[] dirN={"R","D","L","U"};

    public static int longestPath(int sr, int sc,int er, int ec, int[][]board,String ans){
        if(sr==er && sc==ec){
            System.out.println(ans);
            return 0;
        }
        int maxH=0;
        board[sr][sc]=2;
        for(int i=0;i<dir.length;i++){
            int row=sr+dir[i][0];
            int col=sc+dir[i][1];
            if(row>=0 && col>=0 && row<board.length && col<board[0].length && board[row][col]==0){
                int curHeight=longestPath(row,col,er, ec,board,ans+dirN[i]);
                if(curHeight>maxH){
                    maxH=curHeight;
                }
            }
        }
        board[sr][sc]=0;
        return maxH+1;
    }

    static class pair{
        int len=0;
        String str="";
        pair(int len, String str){
            this.len=len;
            this.str=str;
        }
    }
    public static pair floodfill_longestPath(int sr,int sc, int er,int ec, int[][]board){
        if(sr==er && sc==ec){
            return new pair(0,"");
        }
        board[sr][sc]=2;
        pair myPair=new pair(0,"");
        for(int i=0;i<dir.length;i++){
            int row=sr+dir[i][0];
            int col=sc+dir[i][1];
            if(row>=0 && col>=0 && row<board.length && col<board[0].length && board[row][col]==0){
                pair recP=floodfill_longestPath(row, col, er, ec, board);
                if(recP.len+1>myPair.len){
                    myPair.len=recP.len+1;
                    myPair.str=recP.str+dirN[i];
                }
            }
        }
        board[sr][sc]=0;
        return myPair;

    }


    static class Pair{
        int len=0;
        String s="";
        Pair(int len,String s){
            this.len=len;
            this.s=s;
        }
    }
    public static Pair floodfillShortestPath(int sr,int sc,int er,int ec,int[][]board){
        if(sr==er && sc==ec){
            Pair myPair= new Pair(0,"");
            return myPair;
        }
        board[sr][sc]=2;
        Pair myPair= new Pair((int)1e7,"");
        for(int i=0;i<dir.length;i++){
            int  row=sr+dir[i][0];
            int col=sc+dir[i][1];
            if(row>=0 && col>=0&& row<board.length && col<board[0].length && board[row][col]==0){
                Pair myAns=floodfillShortestPath(row, col, er, ec, board);
                if(myAns.len+1<myPair.len){
                    myPair.len=myAns.len+1;
                    myPair.s=myAns.s+dirN[i];
                }
            }
        }
        board[sr][sc]=0;
        return myPair;
    }
    //Infinite perm
    public static int coinchangePer(int[] arr,int target, String ans){
        if(target==0){
            System.out.println(ans);
            return 1;
        }
        int count=0;
        for(int i=0;i<arr.length;i++){
         if(target-arr[i]>=0)
         count+=coinchangePer(arr, target-arr[i], ans+arr[i]+" ");
        }
        return count;
    }

    //comb infinite

    public static int coinchangeComb(int[]arr,int target,int vidx, String ans){
        if(target==0){
            System.out.println(ans);
            return 1;
        }
        int count=0;
        for(int i=vidx;i<arr.length;i++){
            if(target-arr[i]>=0){
                count+=coinchangeComb(arr, target-arr[i], i, ans+arr[i]+" ");
            }
        }
        return count;
    }

    //permutation without rep

    public static int permuationWithoutRep(int[] arr, int target, boolean[] vis, String ans){
        if(target==0){
            System.out.println(ans);
            return 1;
        }
        int count=0;
        for(int i=0;i<arr.length;i++){
            if(!vis[i] && target-arr[i]>=0){
                vis[i]=true;
                count+=permuationWithoutRep(arr, target-arr[i], vis, ans+arr[i]+" ");
                vis[i]=false;
            }
            
        }
        return count;
    }

    //comb without rep

    public static int combinationWithoutRep(int[] arr, int target, int vidx, String ans){
        if(target==0){
            System.out.println(ans);
            return 1;
        }
        int count=0;
        for(int i=0; i<arr.length;i++){
            if( target-arr[i]>=0){
               
                count+=combinationWithoutRep(arr, target-arr[i],  i+1, ans+arr[i]+" ");
                
            }
        }
        return count;
    }

}