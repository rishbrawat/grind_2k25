
#include<iostream>
#include<string>

// for upper and lower
#include<cctype>
using namespace std;

int main() {
   // create a string, length of the string must be reserved tho
   string str = "this is a string";
   cout << "str: " << str << endl;

   // find length of the string
   int len = str.length();
   cout << "length of the string: " << len << endl;

   // find a word in the string str
   string key = "string";
   int found = str.find(key);

   // replace the word string with something
   string newStr = "replaced string";

   // only replace if the word is found tho, if the length is lower than there will be fragments at the end of the string, if starting index is wrong, fragments will be there
   if(found != string::npos) {

      str.replace(found, key.length(), newStr);
   }
   cout << "str: " << str << endl;

   len = str.length();
   // print individual characters
   for(int i = 0; i < len; i++) {
      char c = str[i];

      cout << c << " ";
   }
   cout << endl;

   // insert a new string in the string 
   string insertStr = " new word appeared";
   str.insert(len, insertStr);

   cout << str << endl;
   len = str.length();

   // convert all chars into uppercase
   for(int i = 0; i < len; ++i) {
      char c = str[i];
      if(c >= 'a' && c <= 'z') {
         str[i] = c - 32;
      }
   }
   cout << str << endl;

   // convert them back to lowercase
   for(int i = 0; i < len; ++i) {
      char c = str[i];
      if(c >= 'A' && c <= 'Z') {
         str[i] = c + 32;
      }
   }
   cout << str << endl;

   // inbuilt methods for upper and lower
   for(int i = 0; i < len; ++i) {
      str[i] = toupper(str[i]);
   }
   cout << str << endl;

   // lower
   for(int i = 0; i < len; ++i) {
      str[i] = tolower(str[i]);
   }
   cout << str << endl;



   return 0;
}