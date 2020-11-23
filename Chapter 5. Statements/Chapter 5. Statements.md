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

## Exercise 4.14

**Explain what happens in each of the if tests:**

```cpp
if (42 = i)   //  Compile error: arithmetic literal cannot be lvalue.
if (i = 42)   //  First assign 42 to i, then since i is non-zero thus if(i) is always true.
```

## Exercise 4.15

**The following assignment is illegal. Why? How would you correct it?**

```cpp
double dval;
int ival;
int *pi;
dval = ival = pi = 0;
```
because pi is an int pointer and we cannot assign an int pointer's value to an int(this is not convertable).

Correct it:

```cpp
double dval;
int ival;
int *pi;
dval = ival = *pi = 0;
```

## Exercise 4.16

**Although the following are legal, they probably do not behave as the programmer expects. Why? Rewrite the expressions as you think they should be.**

```cpp
(a) if (p = getPtr() != 0)
(b) if (i = 1024)
```

(a) Because `=`'s precedence is lower than `!=`, thus this expression will be `if (p = (getPtr() != 0))`. First check if `getPtr()` is equal to 0 or not and then assign the boolean result to `p` and finally check if `p` has bool value true or false.

I believe that the programmer actually want to assign `getPtr()`'s value to `p` and then check if `p`'s value is equal to 0 or not.

Therefore we can rewrite like this `if ((p = getPtr()) != 0)`

(b) This expression first assign 1024 to `i` and then check `i`'s bool value. Because `i` is non-zero then `i`'s bool value is always true thus this expression is always ture.

I believe that the programmer actually want to check if `i` is equal to 1024 so we can rewrite like this `if (i == 1024)`

## Exercise 4.17

**Explain the difference between prefix and postfix increment.**

The prefix operators increment(or decrement) the operand first and return the incremented(or decremented) object as an lvalue.

The postfix operators first return a copy of the object's original value as an rvalue and then increment(or decrement) the operand.

## Exercise 4.18

**What would happen if the while loop on page 148 that prints the elements from a vector used the prefix increment operator?**

It will skip the first element, print from the second element and it will also try to dereference v.end() at last.(This is an undefined behavior and very dangerous)

## Exercise 4.19

**Given that ptr points to an int, that vec is a `vector<int>`, and that ival is an int, explain the behavior of each of these expressions. Which, if any, are likely to be incorrect? Why? How might each be corrected?.**
    
```cpp
(a) ptr != 0 && *ptr++
(b) ival++ && ival
(c) vec[ival++] <= vec[ival]
```

(a) First check wheter `ptr` is a nullptr or not and check whether the pointer `ptr`'s value is zero of not and finally move on to `ptr`'s next element.

This expression is correct since left part of `&&` will be evaluated first.

(b) First check if `ival` is zero or not and then increment `ival` by one. Then check the new `ival` value whether it is zero or not.

This expression is correct since left part of `&&` will be evaluated first.

(c) This expression is incorrect since we do not know whether left part of `<=` will be evaluated first or the right part will be evaluated first thus this expression will cause an undefined bahavior.

## Exercise 4.20

**Assuming that iter is a `vector<string>::iterator`, indicate which, if any, of the following expressions are legal. Explain the behavior of the legal expressions and why those that aren’t legal are in error.**

```cpp
(a) *iter++;

(b) (*iter)++;

(c) *iter.empty()

(d) iter->empty();

(e) ++*iter;

(f) iter++->empty();
```

(a) Legal, first dereference and get the string points by the `iter` iterator. Then move on to the next iterator.

(b) Illegal, first dereference and get the string points by the `iter` iterator. Then try to increment the string by one which is illegal.

(c) Illegal, `.` has higher order precedence than dereference. However, it is illegal to call `empty` member method on a string iterator.

(d) Legal, first dereference and get the string points by the `iter` iterator. Then call `empty` method on current string to check if it is an empty string.

(e) Illegal, first dereference and get the string points by the `iter` iterator. Then try to increment the string by one which is illegal.

(f) Legal, first dereference and call `empty` method on current string to check if it is an empty string. Then move on to the next iterator.

## Exercise 4.21

**Write a program to use a conditional operator to find the elements in a vector<int> that have odd value and double the value of each such element.**

[4.21 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%204.%20Expressions/Codes/4.21%20Solution.cpp)

## Exercise 4.22 

**Extend the program that assigned high pass, pass, and fail grades to also assign low pass for grades between 60 and 75 inclusive. Write two versions: One version that uses only conditional operators; the other should use one or more if statements. Which version do you think is easier to understand and why?**

[4.22 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%204.%20Expressions/Codes/4.22%20Solution.cpp)

## Exercise 4.23

**The following expression fails to compile due to operator precedence. Using Table 4.12 (p. 166), explain why it fails. How would you fix it?**

```cpp
string s = "word";
string pl = s + s[s.size() - 1] == 's' ? "" : "s" ;
```

`+` operator has higher order precedence than `==` operator thus the second line will be `string pl = (s + s[s.size() - 1]) == 's' ? "" : "s" ;`.

First add `s` with `s[3]`(char `d` actually) and the result is a new string `wordd`. Then compare new string with the char `s`. However, we cannot use `==` to compare a string with a char thus codes cannot compile.

We can easily fix this issue by adding one more parenthesis.

```cpp
string s = "word";
string pl = s + (s[s.size() - 1] == 's') ? "" : "s" ;
```

## Exercise 4.24

**Our program that distinguished between high pass, pass, and fail depended on the fact that the conditional operator is right associative. Describe how that operator would be evaluated if the operator were left associative.**

Here is the program:

```cpp
finalgrade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : "pass";
```

If the operator is left associative, then the program will be:

```cpp
finalgrade = ((grade > 90) ? "high pass" : (grade < 60)) ? "fail" : "pass";
```

If the `grade` is lower or equal to 90, then we will evaluate `(grade < 60)` part instead of the later conditional statement. And then we will evaluate expression `true ? "fail" : "pass"` or `false ? "fail" : "pass"` according to the `grade`'s value. Therefore the final output can be "pass" or "fail".

If the `grade` is higher than 90, then first conditional statement will have result `"high pass"` and then we evaluate expression `"high pass" ? "fail" : "pass"` since `high pass` will always be converted to true when considered as a bool value thus this expression will always have true result so the final output will always be "fail".

## Exercise 4.25

**What is the value of ~'q' << 6 on a machine with 32-bit ints and 8 bit chars, that uses Latin-1 character set in which 'q' has the bit pattern 01110001?**

Because `~` operator has a higher order precedence than `<<` operator thus we first evaluate `~'q'` which will get a negative value. Before C++ 20, left shift of a negative value is an undefined behaviour. Since C++ 20, the result is defined well and the result is `11111111111111111110001110000000`

## Exercise 4.26

**In our grading example in this section, what would happen if we used unsigned int as the type for quiz1?**

There are altogether 30 students in the example. According to the standard, unsigned int is only guaranteed to hold at least 16 bits. If we choose unsigned int, the result may be undefined.

## Exercise 4.27

**What is the result of each of these expressions?**

```cpp
unsigned long ul1 = 3, ul2 = 7;
```

We can use bit representations for `3` and `7`:

`0011` for `3` and `0111` for `7`

> (a) ul1 & ul2

> (b) ul1 | ul2

> (c) ul1 && ul2

> (d) ul1 || ul2


(a) `0011` & `0111` => `0011` => `3`

(b) `0011` | `0111` => `0111` => `7`

(c) `0011` && `0111` => true

(d) `0011` || `0111` => true

## Exercise 4.28

**Write a program to print the size of each of the built-in types.**

[4.28 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%204.%20Expressions/Codes/4.28%20Solution.cpp)

## Exercise 4.29

**Predict the output of the following code and explain your reasoning. Now run the program. Is the output what you expected? If not, figure out why.**

```cpp
int x[10];
int *p = x;
cout << sizeof(x)/sizeof(*x) << endl;
cout << sizeof(p)/sizeof(*p) << endl;
```

First line of codes `cout << sizeof(x)/sizeof(*x) << endl;` will output the element number of the array. Because `sizeof(x)` will output each element type's size (int here) multiplies total element number of the array `x` and `sizeof(*x)` will output each element type's size (int here) thus `sizeof(x)/sizeof(*x)` will give us the total element number of the array `x` which is 10.

Second line of codes `cout << sizeof(p)/sizeof(*p) << endl;`'s result depends on system, I use 64-bit system thus `sizeof(p)` which will output the size of a pointer is 8. In practice, pointers will be 2 bytes on a 16-bit system, 3 bytes on a 24-bit system, 4 bytes on a 32-bit system, and 8 bytes on a 64-bit system. `sizeof(*p)` will output the size of the data type the pointer points to thus `sizeof(*p)` => `sizeof(int)` = 4. Therefore result on my machine is 8/4 => 2.

## Exercise 4.30

**Using Table 4.12 (p. 166), parenthesize the following expressions to match the default evaluation:**

> (a) sizeof x + y

> (b) sizeof p->mem[i]

> (c) sizeof a < b

> (d) sizeof f()

(a) (sizeof x) + y `sizeof` operator has higher order precedence than `+`(add) operator.

(b) sizeof(p -> mem[i]) `sizeof` operator has lower order precedence than `+`(add) operator.

(c) sizeof(a) < b `sizeof` operator has higher order precedence than `<` operator.

(d) (sizeof f()) return the return type size of the function `f()`, if the return type is void then the result depends on compilers.

## Exercise 4.31

**The program in this section used the prefix increment and decrement operators. Explain why we used prefix and not postfix. What changes would have to be made to use the postfix versions? Rewrite the program using postfix operators.**

We used prefix just because the book said **Use Postfix Operators only When Necessary** before and also sometimes compilers can optimize prefix better than postfix.
It will be no changes whether we choose prefix or postfix in this program, here is the version of postfix:

```cpp
vector<int>::size_type cnt = ivec.size();
for(vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)
    ivec[ix] = cnt;
```

## Exercise 4.32

** Explain the following loop.**

```cpp
constexpr int size = 5;
int ia[size] = {1,2,3,4,5};
for (int *ptr = ia, ix = 0; ix != size && ptr != ia+size; ++ix, ++ptr)   
{ /* ...   */ }
```

The loop use both pointer(ptr) and array index(ix) to traverse and do something on each array element. Two different ways to realize same feature.

## Exercise 4.33

**Using Table 4.12 (p. 166) explain what the following expression does:**

```cpp
someValue ? ++x, ++y : --x, --y
```

Because the `,` operator has the lowest order precedence thus the expression will be `(someValue ? ++x, ++y : --x), --y`.

First we check whether `someValue` has true or false value.

If true, then increment `x` by one, else increment `y` by one and the result of `(someValue ? ++x, ++y : --x),` part is `++y` and then we just discard the `someValue ? ++x, ++y : --x` part and decrement `y` by one thus the final result of the expression is just `y` if someValue is true.

If false, then decrement `x` by one and the result of `(someValue ? ++x, ++y : --x),` part is `--x`. However, since `(someValue ? ++x, ++y : --x),` part will always be discared then this expression's final result will always be `--y`.

To conclude, we may increment or decrement `x` by one but the result of this expression is always `y` or `--y` which has no relation with `x`.

## Exercise 4.34

**Given the variable definitions in this section, explain what conversions take place in the following expressions:**

> (a) if (fval)

> (b) dval = fval + ival;

> (c) dval + ival * cval;

**Remember that you may need to consider the associativity of the operators.**

(a) Convert `fval` from float to bool

(b) First convert `ival` from int to float and add `ival` with `fval`. Then convert the sum from float to double.

(c) First convert `cval` from char to int and multiply `ival` with `cval`. Then convert the sum from float to double.

## Exercise 4.35

**Given the following definitions,**

```cpp
char cval;     
int ival;
unsigned int ui;
float fval;
double dval;
```

**identify the implicit type conversions, if any, taking place:**

> (a) cval = 'a' + 3;

> (b) fval = ui - ival * 1.0;

> (c) dval = ui * fval;

> (d) cval = ival + fval + dval;

(a) First promote `a` from char to int and add with `3`. Then convert the sum from int back to char.

(b) First convert `ival` from int to double and multiply `ival` with 1.0. Then convert `ival` from int to double and add with the previous double sum. Finally convert result from double back to float by truncation.

(c) First promote `ui` from unsigned int to float and multiply with `fval`. Then convert the result to double.

(d) First promote `ival` from int to float and add with `fval`. Then promote the result from float to double and add with `dval`. Finally convert result from double back to char by truncation.

## Exercise 4.36

**Assuming i is an int and d is a double write the expression `i *= d` so that it does integral, rather than floating-point, multiplication.**

```cpp
i *= static_cast<int>(d);
```

## Exercise 4.37

**Rewrite each of the following old-style casts to use a named cast:**

```cpp
int i;
double d;
const string *ps;
char *pc;
void *pv;
```

> (a) pv = (void*)ps;

> (b) i = int(* pc);

> (c) pv = &d;

> (d) pc = (char*) pv;

(a) pv = static_cast<void*>(const_cast<string*>(ps));

(b) i = static_cast<int>(*pc);

(c) pv = static_cast<void*>(&d);

(d) pc = static_cast<char*>(pv);

## Exercise 4.38

**Explain the following expression:**

```cpp
double slope = static_cast<double>(j/i);
```

`j/i` is an integer by truncation and then cast this result to a double and store this double result in a double variable `slope`.

