import java.util.Scanner;
import java.util.ArrayList;

public class l001{
    public static Scanner scn =new Scanner (System.in);
    public static void main(String[] args){
        solve();
    }

    public static void set1(){
        int n=scn.nextInt();
        int a=fact(n);
        System.out.println(a);
        int b=power(2,4);
        int c=powerBetter(2,10);
        System.out.println(b);
        System.out.println(c);
    }

    public static void set2(){
        int [] arr={1, 5,6,7,8};
        display(arr,0);
        boolean a= find( arr,0,8);
        System.out.println(a);
        int c=maximum(arr,0);
        System.out.println(c);
        int d=minimum(arr,0);
        System.out.println(d);
    }

    public static void set3(){
        String s="abc";
        String s1="aab";
        
        // ArrayList<String> ans=subseq(s);
        // for (String str:ans){
        //     System.out.print(str+" ");
        // }
        
        //System.out.println(subseq(s));
        //System.out.println(subseq_1(s));
        //System.out.println(subseqCount(s, ""));
        //System.out.println(permutation(s));
        //System.out.println(permutation_02(s, ""));
        System.out.println(permWithoutDup(s1, ""));
        
    }

    public static void solve(){
        //set1();
        //set2();
        set3();

    }

    public static int fact(int n){
        return (n<=1) ? n :n*fact(n-1);
        
    }
    
    public static int powerBetter(int a, int b){
        if(b==0) 
        return 1;
         int smallAns=powerBetter(a,b/2);
         smallAns*=smallAns;
        return (b%2==0)?smallAns:a*smallAns;
    }


    public static int power(int a,int b){
        return b==0? 1: a*power(a,b-1);
    }

    public static void display(int []arr, int vidx ){
        if(vidx==arr.length) return;
       System.out.print(arr[vidx] + " ");
        display(arr, vidx+1);
    }

    public static boolean find(int [] arr,int vidx, int data){
        if(vidx==arr.length)return false;
        if(arr[vidx]==data)return true;
        return find(arr,vidx+1,data);
    }
    public static int maximum(int []arr,int vidx){
        if(vidx==arr.length-1) return arr[vidx];
        int cur_max=maximum(arr,vidx+1);
        return Math.max(cur_max, arr[vidx]);
    }

    public static int minimum(int[] arr,int vidx){
        if(vidx==arr.length-1)return arr[vidx];
        int cur_min=minimum(arr,vidx+1);
        return Math.min(cur_min, arr[vidx]);
    }

    public static ArrayList<String>subseq(String s){
        if(s.length()==0){
            ArrayList<String>base=new ArrayList<>();
            base.add("");
            return base;
        }

        char ch=s.charAt(0);
        String nstr=s.substring(1);
        ArrayList<String> smallAns=subseq(nstr);
        ArrayList<String>myAns=new ArrayList<>();
        for(String str: smallAns){
            myAns.add(str);
            myAns.add(str+ch);
        }
        return myAns;
    }

    public static ArrayList<String>subseq_1(String s){
        if(s.length()==0){
            ArrayList<String>base=new ArrayList<>();
            base.add("");
            return base;
        }
        char ch=s.charAt(0);
        String nstr=s.substring(1);
        ArrayList<String>smallAns=subseq_1(nstr);
        ArrayList<String>myAns=new ArrayList<String>();
        myAns.addAll(smallAns);
        for(String str:smallAns){
            myAns.add(ch+str);
        }
        return myAns;
        
    }
    
    public static int subseqCount(String s, String ans){
         if(s.length()==0){
             System.out.print(ans+" ");
             return 1;
         }
        int count=0;
        count+=subseqCount(s.substring(1), ans);
        count+=subseqCount(s.substring(1), ans+s.charAt(0));
        return count;

    }
    public static ArrayList<String>permutation(String str){
        if(str.length()==1){
            ArrayList<String>base=new ArrayList<>();
            base.add(str);
            return base;
        }

        char ch=str.charAt(0);
        String nstr=str.substring(1);
        ArrayList<String> smallAns=permutation(nstr);
        ArrayList<String> myAns=new ArrayList<>();
        for(String s: smallAns){
            for( int i=0;i<=s.length();i++){
                myAns.add(s.substring(0,i)+ch+s.substring(i));
            }
        }
        return myAns;
    }
    public static int permutation_02(String s, String ans){
        if(s.length()==0){
            System.out.println(ans);
            return 1;
        }
        int count=0;
        for (int i=0; i<s.length();i++){
            String nstr=s.substring(0,i)+s.substring(i+1);
            count+=permutation_02(nstr, ans+s.charAt(i));
        }
        return count;
    }

    public static int permWithoutDup(String s, String ans){
        if(s.length()==0){
            System.out.println(ans);
            return 1;
        }
        int count=0;
        boolean[] vis =new boolean[26];
        for (int i=0;i<s.length(); i++){
            char ch=s.charAt(i);
            if(!vis[ch-'a']){
                vis[ch-'a']=true;
                String nstr=s.substring(0,i)+s.substring(i+1);
                count+=permWithoutDup(nstr, ans+ch);
            }

        }
        return count;
    }

    


}