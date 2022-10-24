#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
      long long int r=0,sign=1,i=0;
        
        
    while(1)
        {
            if(s[i] == ' ')
                i++;
            else
            break;
         }
      if(s[i]=='-')
      {
        sign = -1;
           if(int(s[i+1])>=48&& int(s[i+1]) <=57)
              i++;
          else return 0;
      }
     if(s[i]=='+')
      {
        
            if(int(s[i+1])>=48   && int(s[i+1]) <=57)
              i++;
          else return 0;
      }
        while(1)
        {
            if(s[i]=='0')
                i++;
            else break;
        }
     while(1)
     {
        if(int(s[i])>=48&& int(s[i])<=57)
            r = r*10 + int(s[i++])-48;
         else break;
        long long int  c = r*sign;
           if(c< (-1)*(pow(2,31)))
       return  (-1)*(pow(2,31)); 
           if(c>pow(2,31)-1)
         return pow(2,31)-1;
     }
        
   r*= sign ;
        return r;
        
    }
};

int main(){
    Solution s ;
    int result= s.myAtoi("45");
     cout<<result ;
     return 0;
}