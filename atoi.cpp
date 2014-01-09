#include<iostream>
#include<climits>

class Solution {
public:
     bool isSpace(char c){
         if(c == ' ' || c == '\t' || c == '\n' )
            return true;
         else
            return false;
     }
     
     bool isDigit(char c){
         if(c >= '0' && c <='9')
            return true;
         else
            return false;
     }
     
     bool isAlpha(char c){
         if( (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
            return true;
         else
            return false;
     }
    
     int atoi(const char *str) {
         int temp;
         bool neg = false;
         bool rangeErr = false;
         const char *tempStr;
         unsigned int cutoff;
         unsigned int cutlim;
         int number = 0;
         tempStr = str;
         
         //if(tempStr == '\0') return 0;
         
         //remove leading spaces and leading zeros;
         do{
             temp = *tempStr++;
         }while(isSpace(temp));
         
         //check if number is negative or not
         if(temp == '-'){
             neg = true;
         }
        
         //If digit is encountered assign it to the number
         if(isDigit(temp)){
                 temp = temp - '0';
				 number = temp;
		 }
         
         //If first digit is Alphabet, then return 0
         if(isAlpha(temp)){
			 return 0;
		 }
		 
		 //compute the cutoff, for range checking
         cutoff = neg ? (unsigned int)INT_MIN : INT_MAX;
         cutlim = cutoff % 10;
         cutoff = cutoff / 10;
         
         while(temp = *tempStr++){
             if(isSpace(temp) || isAlpha(temp) || !isDigit(temp))
                 break;
             
             if(isDigit(temp))
                 temp = temp - '0';
             
			 if((number == cutoff && temp > cutlim) || (number > cutoff)){
				 rangeErr = true;
                 break;
             }
             
             number = number * 10 + temp;
         }
         
         if(rangeErr){
                 if(neg)
                     return INT_MIN;
                 else
                     return INT_MAX;
             }
             
        if(neg)
            return -number;
        else
            return number;
     }
};
