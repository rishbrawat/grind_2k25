// a set stores unique values, no duplications allowed, values are stored in insertion order.

const s = new Set([1,2,3,4,5]);
console.log(s);


// add values
s.add(6);
console.log(s);
// check existence
console.log(s.has(6));

// delete a value
console.log(s.delete(6));
console.log(s);

console.log(s.size);
// iterating a set
// for (const value of s) {
//     console.log(value);
// }

// clear all values
s.clear(); 
console.log(s);

let arr = [1,2,3,4,5];


arr.forEach(item => s.add(item));
console.log(s);


const s1 = new Set([1,2,3,4,5]);
const s2 = new Set([1,5,6,7,3]);

// console.log(s1.intersection(s2)); modern methods