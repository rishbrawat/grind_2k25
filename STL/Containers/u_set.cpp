/*
   unordered_set: stores unqiue elements are allows for very fast lookup. conceptually it answers one core question efficiently:
   `is this element present or not!`

   the elements are not sorted or based on indices.
   
   core properties
      if a value is entered twice, only one exists.
      no indexing
      unordered
      hashbased structure


   classic problems
      check if seen before
      rmeove duplicates
      visited elements
      unique values
*/

#include<unordered_set>
#include<iostream>
#include<vector>
using namespace std;


int main() {
   

   vector<int> v = {5,6,7,8,9};
   // initialize from a container (range constructor)
   unordered_set<int> vs(v.begin(), v.end()); // i will check it as it confuses me that both methods return an iterator
   // copy constructor
   unordered_set<int> cvs(vs);
   for(auto& x: cvs) {
      cout << x << ' ';
   }
   cout << endl;

   // we cannot access elements using cvs[i]
   // when size of set is known beforehand we should reserve the memory in advanced to avoid rehashing issues

   unordered_set<int> s = {1,2,3,3,4}; // duplicates are auto removed
   for(auto& x: s) {
      cout << x << ' ';
   }  cout << endl;
   
   // insert - insert an element, no overwrite, returns an iterator bool
   s.insert(5);
   s.insert(10);

   // find() - memebership check, returns an iterator if element is present otherwise it points to the end()
   if(s.find(5) != s.end()) {
      cout << "5 exist on the set\n";
   }

   // count- yes/no presence, useful for quick checks, returns 1 if present and 0 if not
   if(s.count(11)) {
      cout << "11 exists on the set\n";
   }

   // erase() - remove an element, safe even if some value does not exist
   s.erase(10);

   // erase by iterator
   auto it = s.find(5);
   if(it!=s.end()) {
      s.erase(it);
   }
   // clear() - reset the set
   s.clear();

   // common short algos
   // seen before check
   for(auto& x: v) {
      if(s.count(x)) {
         // duplicate found
         break;
      }
      s.insert(x);
   }

   // deleting from set
   for(it = s.begin(); it!=s.end(); ) {
      if(*it % 2 == 0) {
         it = s.erase(it);
      }
      else 
         ++it;
   }

   // const for each loop is readonly
}
