#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
    string arr[] = {"I","II","III","IV","V","VI","VII","VIII","IX","X"};
        string ans = "";
        int m= num/1000;
            for(int i=0;i<m;i++)
                ans += "M";
                num %= 1000;
           if(num>=900)
           {
               ans += "CM";
               num -= 900;
           }
         m = num/500;
           for(int i=0;i<m;i++)
               ans += "D";
               num %= 500;
        if(num>=400)
             {ans += "CD";
                 num -= 400;
             }
      m = num /100;
           for(int i=0;i<m;i++)
              ans += "C";
               num %= 100;
        if(num >=90)
        {   ans += "XC";
         num -= 90;
             }
          m = num/50;
        for(int i=0;i<m;i++)
               ans += "L";
               num %= 50;
         if(num>=40)
        {
          ans += "XL";
             num -= 40;
                 }
    m = num /10;
    for(int i=0;i<m;i++)
               ans += "X";
               num %= 10;
           if(num!=0)
               ans += arr[num-1]; 
      return ans;    
    }
};

int main(){
    Solution s ;
    string result= s.intToRoman(23);
     cout<<result ;
     return 0;
}