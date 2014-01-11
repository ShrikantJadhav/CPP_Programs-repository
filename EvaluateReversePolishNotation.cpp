#include<stack>
#include<iostream>
#include<vector>

class Solution {
private:
	bool ifNumeric(string strArg);
    bool ifOperator(string strArg);
    int performOperation(int lhs,int rhs,string strArg);
public:
    int evalRPN(vector<string> &tokens);
};


 int Solution::evalRPN(vector<string> &tokens) {
		stack<int> v1;

		for(vector<string>::iterator it1 = tokens.begin(); it1 != tokens.end();it1++){
			if(ifNumeric(*it1)){
				v1.push(atoi((*it1).c_str()));
			}
			else{
				if(ifOperator(*it1)){ 
					int lhs = v1.top();
					v1.pop();
					int rhs = v1.top();
					v1.pop();
					int nResult = performOperation(rhs,lhs,*it1);
					v1.push(nResult);
				}
			}
		}
		if(!v1.empty()){
			return v1.top();
		}
    }

 bool Solution::ifNumeric(string strArg){
	 int i = 0;
	 bool bRetVal = true;
	 bool bNegNumber = false;
	 if(strArg[0] == '-' && strArg.length() > 1){
		 bNegNumber = true;
	 }
	 while(strArg[i] != '\0'){
		 int nChar = int(strArg[i]);
		 if((nChar < 48 || nChar > 57) && !bNegNumber){
			 bRetVal = false;
		 }
		 i++;
	 }
	 return bRetVal;
 }

 bool Solution::ifOperator(string strArg){
	 switch(strArg[0]){
	 case '+' :
	 case '-':
	 case '*':
	 case '/':
	 case '^':
		 return true;
	 default:
		 return false;
	 }
 }

 int  Solution::performOperation(int lhs,int rhs,string strArg){
	  switch(strArg[0]){
	 case '+' :
		 return lhs + rhs;
	 case '-':
		 return lhs - rhs;
	 case '*':
		 return lhs * rhs;
	 case '/':
		 return lhs / rhs;
	 default:
		 return 0;
	 }
 }
