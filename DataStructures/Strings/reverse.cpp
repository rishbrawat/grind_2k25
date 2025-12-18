#include<iostream>
#include<string>
using namespace std;

string reverseStr(string str, int length) {
   string reversed(length, ' ');

   if(length == 0) {
      return "";
   } 

   for(int i = length-1, j = 0; i >= 0; --i, ++j) {
      reversed[j] = str[i];
   }
   return reversed;

}

// this can be solved using boundary pointers as well
string reversedStr2(string str, int length) {
   int start = 0;
   int end = length-1;

   if(length == 0) {
      return "";
   }

   while (start < end) {
      char temp = str[end];
      str[end] = str[start];
      str[start] = temp;

      // dont forget to move pointers
      start++;
      end--;
   }

   return str;
}

int main() {
   string str = "hello"; // reverse = olleh
   int length = str.length();

   string newStr = reverseStr(str, length);
   cout << newStr << endl;

   newStr = reversedStr2(newStr, length);
   cout << newStr << endl;

   return 0;
}