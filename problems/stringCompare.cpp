// simple string comparer:
// Examples: abc9 < abc123 abc > ab9 (char is important than digit!)
// image9.jpg < image10.jpg
// image001b.jpg < image2a.jpg
// aaa < b
// Follow up: the name with binary
// image\b101.jpg = image5 < image6.jpg

#include <string>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;
class Solution{
public:
  int convert(string & s , int & pos, int base){
    if(pos >= s.length()) return 0;
    int i = pos, num = 0;
    for(; i < s.length(); ++i){
      if(isdigit(s[i])){
	num = base*num + s[i] - '0'; // should not be num += .....!!!
        if(num == 0)  return 0;
      }
      else{
	break;
      }
    }
    pos = i-1;
    return num;
  }
  // @return: 1: > (larger)  0 : (equal)  -1: < (smaller)
  int stringCompare(string& s1, string& s2){
    if(s1.empty())  return !s2.empty() ? -1 : 0;
    if(s2.empty())  return s1.empty() ? 0 : 1;
    // idea: compare it one char by one char
    int i = 0, j = 0;
    while(i < s1.length() && j < s2.length()){
      if(isdigit(s1[i]) && isdigit(s2[i])){
	int a = convert(s1, i, 10), b = convert(s2, j, 10);
	cout<<"a: "<<a<<"\tb: "<<b<<endl;
	if(a != b) return a > b ? 1 : -1;
      }
      else if(s1[i] == '\b' && s2[j] == '\b' || s1[i] == '\b' && isdigit(s2[j]) || s2[j] == '\b' && isdigit(s1[i])){
	if(s1[i] == '\b') i++;
	if(s2[j] == '\b') j++;
	int a = convert(s1, i, 2), b = convert(s2, j, 2);
	cout<<"a: "<<a<<"\tb: "<<b<<endl;
	if(a != b) return a > b ? 1 : -1;
      }
      else if(isdigit(s1[i]))  return -1; // s2[j] is char while s1[i] is not
      else if(isdigit(s2[j]))  return 1;
      else{
	if(s1[i] != s2[j])  return s1[i] > s2[j] ? 1 : -1;
      }
      i++, j++;
    }
    return i == s1.length() && j == s2.length() ? 0 : (j == s2.length() ? 1 : -1);
  }
};


int main(int argc, char ** argv){
  vector<vector<string> > test({{"image9.jpg", "image10.jpg"}, {"abc9 ", "abc123"}, {"abc", "ab9"}, {"image001b.jpg", "image2a.jpg"}, {"aaa", "b"}, {"image\b101.jpg", "image6.jpg"}, {"aaa100", "aaa99"}, {"image\b101.jpg", "image\b10101.jpg"},  {"image\b101.jpg", "image1.jpg"},  {"image\b101b.jpg", "image\b101a.jpg"},});
  Solution s;
  for(int i = 0; i < test.size(); ++i){
    int res = s.stringCompare(test[i][0], test[i][1]);
    cout<<test[i][0]<<(res == 0 ? "\t==\t" : (res == -1 ? "\t<\t" : "\t>\t"))<<test[i][1]<<endl;
  }
}
