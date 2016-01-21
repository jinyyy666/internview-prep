/*****************************************************************
 * My code for check if a given string is a palindrome.
 * You can set two flags : 1) ignoreCase, 2) ignoreSpace.
 * Example:
 * Mom   (igore case) ----> is palindrome
 * mo m  (ignore space) ----> is palindrome
 *
 * How to run to test?
 * cat testcheckPalindrome | ./checkPalindrome 
 *
 * Enjoy!
 *
 * Author: Yingyezhe(Jimmy) Jin
 * Email: jyyz@tamu.edu
 * Date: Oct. 27, 2015
 ****************************************************************/

#include <iostream>
#include <cctype>
#include <cstdio>
#include <string>
#include <assert.h>

using namespace std;


// my version of check the palindrome
class Solution{
public:
  // the function is check if the palindrome is valid:
  bool isValid(string & str, bool ignoreSpace){
    // invalid case 1  empty string:
    // this includes the case where the string is like "\0\0\0" all null-char
    // in C++ stl, this case is properly handled.
    if(str.empty())  return false;
    
    // invalid case 2  all space:
    // this only happens when the space is ignored.
    if(ignoreSpace){
      for(size_t i = 0; i < str.length(); ++i)
	if(str[i] != ' ')
	  return true;

      // if the string fails to return in the loop, then it must be all-space:
      return false;
    }
    
    // if the string pass the two conditions, then the string is valid:
    return true;
  }

  // the function to advance/decrease pointers if the space is ignore:
  inline
  void advancePointers(string& str, size_t& start, size_t& end){
    if(str[start] == ' ')
      start++;
    if(str[end] == ' ')
      end--;
  }

  // the function to do case sensitive comparing:
  inline
  bool basicCompare(string& str, size_t start, size_t end){
    if(str[start] != str[end])
      return false;
    else
      return true;
  }
  
  // the function to do case-insensitive comparing:
  inline
  bool caseCompare(string& str, size_t start, size_t end){
    if(toupper(str[start]) != toupper(str[end]))
      return false;
    else
      return true;
  }

  // the function to check the palindrome:
  bool isPalindrome(string& str, bool ignoreCase, bool ignoreSpace){
    // 1. check if the string is valid or not.
    //    if not, return false.
    if(!isValid(str, ignoreSpace))
      return false;
  
    // 2. Begin the main loop (using two pointers) for checking:
    size_t start = 0, end = str.length()-1;
    while(start < end){
      // Four cases need to be handlded here:

      // 2.1. If not ignore case and not ignore space (00) :
      if(!ignoreCase && !ignoreSpace){
	if(!basicCompare(str, start, end))     // fail to meet condition, return
	  return false;
      }
      // 2.2. If not ignore case but ignore space (01):
      else if(!ignoreCase && ignoreSpace){
	// if one of the pointed char is space, just ignore it
	if(str[start] == ' ' || str[end] == ' '){
	  advancePointers(str, start, end);
	  continue;
	}
	else{
	  // if none of them is space, compare normally:
	  if(!basicCompare(str, start, end))     
	    return false;
	}  
      }
      // 2.3. If ignore case but not ignore space (10):
      else if(ignoreCase && !ignoreSpace){
         if(!caseCompare(str, start, end))
	   return false;
      }
      // 2.4. If ignore case and ignore space:
      else{
	// decouple two flags here:
	if(str[start] == ' ' || str[end] == ' '){
	  // if one of them is space, then increase/decrease pointer,continue:
	  advancePointers(str, start, end);
	  continue;
	}
	else{
	  // if none of them is space, just be case insensitive
          if(!caseCompare(str, start, end))
	     return false;
	}
      }
      start++;
      end--;
    }
    
    // if the string survives, return true:
    return true;
  }

};


// the test function to test all four boolean input combinations:
void myTest(Solution &S, string& str){
cout<<"If not ignore case and space :\n";
   if(S.isPalindrome(str, 0, 0))
     cout<<str<<" is a palindrome!"<<endl;
   else
     cout<<str<<" is not a palindrome!"<<endl;

   cout<<"If not ignore case but ignore space :\n";
   if(S.isPalindrome(str, 0, 1))
     cout<<str<<" is a palindrome!"<<endl;
   else
     cout<<str<<" is not a palindrome!"<<endl;

   cout<<"If ignore case and but not ignore space :\n";
   if(S.isPalindrome(str, 1, 0))
     cout<<str<<" is a palindrome!"<<endl;
   else
     cout<<str<<" is not a palindrome!"<<endl;

   cout<<"If ignore case and space :\n";
   if(S.isPalindrome(str, 1, 1))
     cout<<str<<" is a palindrome!"<<endl;
   else
     cout<<str<<" is not a palindrome!"<<endl;

}


// the function to test the isPalindrome():
// the input will be fed from std::cin
int main(int argc, char** argv){
  Solution S;
  if(argc != 1){
    cout<<"Invalid input!"<<endl;
    cout<<"Please do: cat testcheckPalindrome | ./checkPalindrome"<<endl;
    return -1;
  }
  
  // test the invaild string first:
  cout<<"Testing empty string: "<<endl;
  char tmp[20];
  sprintf(tmp,"\0\0\0\0\0");
  string temp(tmp);
  myTest(S, temp);
  cout<<endl;

  // test the string:
  string str;
  while(getline(cin, str)){
    myTest(S,str);
    cout<<endl;
  }
  
  return 0;
}
