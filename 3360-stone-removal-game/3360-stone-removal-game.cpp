class Solution {
public:
    bool canAliceWin(int n) {
        
        if(n<10){
            return false;
        }
        int rem=n;
        int take = 10;
        bool aliceturn = true;
        while(rem>=take && take > 0 ){
            rem -= take;
            take--;
            aliceturn = !aliceturn;
        }
       
       return !aliceturn;
    }
};