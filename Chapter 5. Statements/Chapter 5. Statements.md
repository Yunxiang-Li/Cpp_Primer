# Chapter 5. Statements

## Exercise 5.1

**What is a null statement? When might you use a null statement?**

Null statement is an empty statement like this:

```cpp
; // null statement
```
We might use a null statement when the language requires a statement but the program's logic does not.

## Exercise 5.2

**What is a block? When might you might use a block?**

Block is a (possiby empty) sequence of statements and declarations surrounded by a pair of curly braces.

We might use a block when the language requires a single statement but the logic of our program needs more than one. 

## Exercise 5.3

**Use the comma operator (§ 4.10, p. 157) to rewrite the while loop from § 1.4.1 (p. 11) so that it no longer requires a block. Explain whether this rewrite improves or diminishes the readability of this code.**

[5.3 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%205.%20Statements/Codes/5.3%20Solution.cpp)

This rewrite diminishes the readability of the code since `,` operator always guarantees the order and discards the left result but we do not care about this feature in this example which is redundant.

## Exercise 5.4

**Explain each of the following examples, and correct any problems you detect.**

```cpp
(a) while (string::iterator iter != s.end()) { /* . . . */ }

(b) while (bool status = find(word)) { / * . . . * / }
        if (!status) { /* . . . */ }
```

(a) `iter` is not initialized but only declared.

We can fix it like this:

```cpp
strubg::iterator iter = s.begin();
while (iter != s.end())
    { /* . . . */ }
```

(b) `status` is only declared and defined in the while block thus we cannot access it in if block.

We can fix it like this:

```cpp
bool status;
while (status = find(word)) 
    { / * . . . * / }
if (!status)
    { /* . . . */ }
```

## Exercise 5.5

**Using an if–else statement, write your own version of the program to generate the letter grade from a numeric grade.**

[5.5 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%205.%20Statements/Codes/5.5%20Solution.cpp)

## Exercise 5.6

**Rewrite your grading program to use the conditional operator (§ 4.7, p. 151) in place of the if–else statement.**

[5.6 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%205.%20Statements/Codes/5.6%20Solution.cpp)

## Exercise 5.7

**Correct the errors in each of the following code fragments:**

```cpp
(a) if (ival1 != ival2)    
        ival1 = ival2
    else ival1 = ival2 = 0;

(b) if (ival < minval)
        minval = ival;    
        occurs = 1;
        
(c) if (int ival = get_value())
        cout << "ival = " << ival << endl;
    if (!ival) 
        cout << "ival = 0\n";
        
(d) if (ival = 0)    
        ival = get_value();
```

(a) Missing one semicolon behind `ival1 = ival2`.

Correct version:

```cpp
if (ival1 != ival2)    
    ival1 = ival2;
else ival1 = ival2 = 0;
```

(b) Line of codes `occurs = 1` will always be evaluated. We can add braces for the if statements.

Correct version:

```cpp
if (ival < minval)
{
    minval = ival;    
    occurs = 1;
{
```

(c) `ival` is a local variable which cannot be access in the later if statement. We can fix this by declaring `ival` out of if statements.

Correct version:

```cpp
int ival;
if (ival = get_value())
    cout << "ival = " << ival << endl;
if (!ival) 
    cout << "ival = 0\n";
```

(d) Instead of setting `ival`'s value as 0, we actually want to check if `ival` is equal to 0.

Correct version:

```cpp
if (ival == 0)    
    ival = get_value();
```  

## Exercise 5.8

**What is a “dangling else”? How are else clauses resolved in C++?**

The dangling else is a problem in computer programming in which an optional else clause in an if–else statement results in nested conditionals being ambiguous.
In C++, an else is always paired with the closest preceding unmatched if.

## Exercise 5.9 

**Write a program using a series of if statements to count the number of vowels in text read from cin.**

[5.9 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%205.%20Statements/Codes/5.9%20Solution.cpp)

## Exercise 5.10 

**There is one problem with our vowel-counting program as we’ve implemented it: It doesn’t count capital letters as vowels. Write a program that counts both lower- and uppercase letters as the appropriate vowel—that is, your program should count both 'a' and 'A' as part of aCnt, and so forth.**

[5.10 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%205.%20Statements/Codes/5.10%20Solution.cpp)

## Exercise 5.11

**Modify our vowel-counting program so that it also counts the number of blank spaces, tabs, and newlines read.**

[5.11 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%205.%20Statements/Codes/5.11%20Solution.cpp)

## Exercise 5.12

**Modify our vowel-counting program so that it counts the number of occurrences of the following two-character sequences: ff, fl, and fi.**

[5.12 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%205.%20Statements/Codes/5.12%20Solution.cpp)

## Exercise 5.13

**Each of the programs in the highlighted text on page 184 contains a common programming error. Identify and correct each error.**

```cpp
(a) unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch) {
        case 'a': aCnt++;    
        case 'e': eCnt++;    
        default: iouCnt++;
    }
    
(b) unsigned index = some_value();
    switch (index) {    
        case 1:        
            int ix = get_value();        
            ivec[ ix ] = index;        
            break;    
        default:        
            ix = ivec.size()-1;        
            ivec[ ix ] = index;
     }
     
(c) unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    switch (digit) {
    case 1, 3, 5, 7, 9:        
        oddcnt++;        
        break;
    case 2, 4, 6, 8, 10: 
        evencnt++;
        break;
    }
        
(d) unsigned ival=512, jval=1024, kval=4096;
    unsigned bufsize;
    unsigned swt = get_bufCnt();
    switch(swt) {    
        case ival:
            bufsize = ival * sizeof(int);
            break;
        case jval:       
            bufsize = jval * sizeof(int);        
            break;    
        case kval:        
            bufsize = kval * sizeof(int);        
            break;
     }
```

(a) No break statement for each case thus if the program run case a statement then all statements below case a statement will also be ran.

Correct version:

```cpp
unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
char ch = next_text();
switch (ch) {
    case 'a': aCnt++; break;    
    case 'e': eCnt++; break;   
    default: iouCnt++; break;
}
```

(b) `ix` may be not in scope if we fall into default statement directly without executing case 1 statement.

Correct version:

```cpp
unsigned index = some_value();
switch (index) {
    int ix;
    case 1:        
        ix = get_value();        
        ivec[ ix ] = index;        
        break;    
    default:        
        ix = ivec.size() - 1;        
        ivec[ ix ] = index;
}
```

(c) We cannot write case statement together directly like this. Moreover, case 10 should be actually case 0 since the result of a number mod 10 is in range 0~9.

Correct version:

```cpp
unsigned evenCnt = 0, oddCnt = 0;
int digit = get_num() % 10;
switch (digit) {
    case 1: case 3: case 5: case 7: case 9:        
        oddcnt++;        
        break;
    case 2: case 4: case 6: case 8: case 0: 
        evencnt++;
        break;
}
```

(d) Case label must be a constant expression.

Correct version:

```cpp
const unsigned ival = 512, jval = 1024, kval = 4096;
unsigned bufsize;
unsigned swt = get_bufCnt();
switch(swt) {    
    case ival:
        bufsize = ival * sizeof(int);
        break;
    case jval:       
        bufsize = jval * sizeof(int);        
        break;    
    case kval:        
        bufsize = kval * sizeof(int);        
        break;
}
```

## Exercise 5.14

**Write a program to read strings from standard input looking for duplicated words. The program should find places in the input where one word is followed immediately by itself. Keep track of the largest number of times a single repetition occurs and which word is repeated. Print the maximum number of duplicates, or else print a message saying that no word was repeated. For example, if the input is**

> how now now now brown cow cow

the output should indicate that the word **now** occurred three times.

[5.14 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%205.%20Statements/Codes/5.14%20Solution.cpp)

## Exercise 5.15

**Explain each of the following loops. Correct any problems you detect.**

```cpp
(a) for (int ix = 0; ix != sz; ++ix)  { /* . . . */ }
    if (ix != sz)     // . . .
        
(b) int ix;
    for (ix != sz; ++ix) { /* . . . */ }
    
(c) for (int ix = 0; ix != sz; ++ix, ++ sz)  { /* . . . */ }
```

(a) `ix` is declared in the for statement thus it is accessible only in for blocks so that we cannot access `ix` in the later if statement.

Correct version:

```cpp
int ix;
for (ix = 0; ix != sz; ++ix)  { /* . . . */ }
if (ix != sz)     // . . .
```

(b) Even if we want to omit the initialization statement part in a for statement, we still need to set it as a null statement.

Correct version:

```cpp
int ix;
for (; ix != sz; ++ix) { /* . . . */ }
```

(c) After each iteration of the for loop, both `sz` and `ix` are incremented by one thus if `ix != sz` is not false(`sz == 0`) at the beginning then this for loop will be an infinite loop.

Correct version:

```cpp
for (int ix = 0; ix != sz; ++ix)  { /* . . . */ }
```

## Exercise 5.16

**The while loop is particularly good at executing while some condition holds; for example, when we need to read values until end-of-file. The for loop is generally thought of as a step loop: An index steps through a range of values in a collection. Write an idiomatic use of each loop and then rewrite each using the other loop construct. If you could use only one loop, which would you choose? Why?**

```cpp
// Idiomatic while loop 
int i;
while ( cin >> i )
    // ...

// Rewrite by for loop 
for (int i = 0; cin >> i;)
    // ...

// Idiomatic for loop 
for (int i = 0; i != size; ++i)
    // ...

// Rewrite by while loop
int i = 0;
while (i != size)
{
    // ...
    ++i;
}
```

If I could use only one loop, I prefer for loop because it provides more information and is written in a better form.

## Exercise 5.17

**Given two vectors of ints, write a program to determine whether one vector is a prefix of the other. For vectors of unequal length, compare the number of elements of the smaller vector. For example, given the vectors containing 0, 1, 1, and 2 and 0, 1, 1, 2, 3, 5, 8, respectively your program should return true.**

[5.17 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%205.%20Statements/Codes/5.17%20Solution.cpp)

## Exercise 5.18

**Explain each of the following loops. Correct any problems you detect.**

```cpp
(a) do    
     int v1, v2;    
     cout << "Please enter two numbers to sum:" ;    
     if (cin >> v1 >> v2)       
         cout << "Sum is: " << v1 + v2 << endl;
    while (cin);
    
(b) do {
     // . . .
    } while (int ival = get_response());
    
(c) do {   
     int ival = get_response(); 
    } while (ival);
```

(a) We need add brackets if we have more than one statements under the do statement part or this will cause syntax error.

Correct version:

```cpp
do {
 int v1, v2;    
 cout << "Please enter two numbers to sum:" ;    
 if (cin >> v1 >> v2)       
     cout << "Sum is: " << v1 + v2 << endl;
 }
while (cin);
```

(b) We should not declare or initialize a varibale under the while part of a do-while loop.

Correct version:

```cpp
int ival;
do {
 // . . .
} while (ival = get_response());
```

(c) `ival` is declared and initialized in the do statement thus we cannot access it under the while statement.

Correct version:

```cpp
int ival;
do {   
    ival = get_response(); 
} while (ival);
```

## Exercise 5.19

**Write a program that uses a do while loop to repetitively request two strings from the user and report which string is less than the other.**

[5.19 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%205.%20Statements/Codes/5.19%20Solution.cpp)

## Exercise 5.20

**Write a program to read a sequence of strings from the standard input until either the same word occurs twice in succession or all the words have been read. Use a while loop to read the text one word at a time. Use the break statement to terminate the loop if a word occurs twice in succession. Print the word if it occurs twice in succession, or else print a message saying that no word was repeated.**

[5.20 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%205.%20Statements/Codes/5.20%20Solution.cpp)

## Exercise 5.21

**Revise the program from the exercise in § 5.5.1 (p. 191) so that it looks only for duplicated words that start with an uppercase letter.**

[5.21 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%205.%20Statements/Codes/5.21%20Solution.cpp)

## Exercise 5.22

**The last example in this section that jumped back to begin could be better written using a loop. Rewrite the code to eliminate the goto.**

```cpp
// backward jump over an initialized variable definition is okay
begin:
    int sz = get_size();
    if (sz <= 0) {
        goto begin;
    }
```

Modified version:

```cpp
int sz;

do {
    sz = get_size();
}
while (sz <= 0);
```

## Exercise 5.23

**Write a program that reads two integers from the standard input and prints the result of dividing the first number by the second.**

[5.23 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%205.%20Statements/Codes/5.23%20Solution.cpp)

## Exercise 5.24

**Revise your program to throw an exception if the second number is zero. Test your program with a zero input to see what happens on your system if you don’t catch an exception.**

[5.24 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%205.%20Statements/Codes/5.24%20Solution.cpp)

Without catching exceptions, my system output a message `terminate called after throwing an instance of 'std::runtime_error'
  what():  The divisor cannot be zero!`

## Exercise 5.25

**Revise your program from the previous exercise to use a try block to catch the exception. The catch clause should print a message to the user and ask them to supply a new number and repeat the code inside the try.**

[5.25 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%205.%20Statements/Codes/5.25%20Solution.cpp)
