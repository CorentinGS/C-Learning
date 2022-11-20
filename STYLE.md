# Code Style

Here are the rules to follow to write code that is consistent with the rest of the project.

## Indentation

* Use `4` spaces for indentation.
* Use `1` space between keywords operands and brackets.

## Initializations

* Declare variables at the beginning of the block.
* Declare variables of the same type on the same line.

```c
int 
main(void) {
    int a, b, c;
    /* ... */
}
```

* Do not initialize `static` and `global` variables to `0` or `NULL`.

```c
/* Bad */
static int a = 0;
static int b = NULL;

/* Good */
static int a;
static int b;
```

* Declare local variables in order
    1. Custom structures and enumerations
    2. Integer types, wider unsigned type first
    3. Single/Double floating point

```c
int
my_func(void) {
    /* 1 */
    my_struct_t my;     /* First custom structures */
    my_struct_ptr_t* p; /* Pointers too */

    /* 2 */
    uint32_t a;
    int32_t b;
    uint16_t c;
    int16_t g;
    char h;
    /* ... */

    /* 3 */
    double d;
    float f;
}
```

* Declare counter variables in for loop if possible

```c
/* Good */
for (size_t i = 0; i < 10; ++i) {
    /* ... */
}
```

* Initialize Compound Types with `0`

```c
/* Bad */
struct TemperatureNode node;
memset(&node,0, sizeof node);

/* Good */
const struct TemperatureNode zeroNode = {0};
struct TemperatureNode node = {0};

/* Perform some operations on the node... */

/* Reset the node (equal to node = zeroNode; ) */
memcpy(&node,&zeroNode, sizeof node);
```

* Use `sizeof` on variables, not types.

```c
/* Bad */
int a[10];
memset(a,0, sizeof(int) * 10);

/* Good */
int a[10];
memset(a,0, sizeof a);

/* Bad */
CustomStruct* custom_struct = malloc(sizeof(CustomStruct));

/* Good */
CustomStruct* custom_struct = malloc(sizeof *custom_struct);
```

* Don't use magic numbers.

```c
/* Bad */
someFunctionToStartTimer(30);

/* Good */
const int timeInSeconds = 30;
someFunctionToStartTimer(timeInSeconds);

/* Good */
const int MINUTE = 60;
someFunctionToStartTimer(30 * MINUTE);
```

* Named parameters

```c
/* Good */
int timeInSeconds = 30;
someFunctionToStartTimer(timeInSeconds=20);
```

### Logic

* Never use `stdbool.h`, use `1` and `0` instead.

```c
#define TRUE 1
#define FALSE 0
```

* Don't compare against `TRUE` or `FALSE`.

```c
/* Bad */
if (myBool == TRUE) {
    /* ... */
}

/* Good */
if (myBool) {
    /* ... */
}
```

* Compare using constant on the left.

```c
/* Bad */
if (myInt == 0) {
    /* ... */
}

/* Good */
if (0 == myInt) {
    /* ... */
}
```

* Compare pointers against `NULL`.

```c
/* Bad */
if (myPtr || myPtr == 0) {
    /* ... */
}

/* Good */
if (myPtr == NULL) {
    /* ... */
}
```

* Use `NULL` instead of `0` for pointers.

* Use pre-increment and pre-decrement operators.

```c
/* Bad */
for (int i = 0; i < 10; i++) {
    /* ... */
    a++;
}

/* Good */
for (int i = 0; i < 10; ++i) {
    /* ... */
    ++a;
}
```

* Use size_t for length or size variables.
* Use const
    * for function parameters that are not modified
    * for pointers if the memory pointed to is not modified
    * for variables that are not modified
    * for array size

```c
/* myPointer is not modified but the data pointed can */
void myFunction(int* const myPointer) {
    /* ... */
}
```

* Use `static` for internal functions and variables.
* Never use VLA (Variable Length Array).

```c
/* Bad */
void myFunction(int size) {
    int myArray[size];
    /* ... */
}

/* Good */
void myFunction(int size) {
    int* myArray;
    myArray = malloc(sizeof(*myArray) * size);
}
```

* Protect `malloc` against NULL

```c
/* Bad */
int* myArray = malloc(sizeof(*myArray) * size);

/* Good */
int* myArray = malloc(sizeof(*myArray) * size);
if (myArray == NULL) {
    /* Handle error */
}

/* Good Short */
if (!(matrix = malloc(sizeof(int) * 9))) {
    /* Handle error */
}
```

* Protect `free` against NULL

```c
/* Bad */
free(myArray);

/* Good */
if (myArray != NULL) {
    free(myArray);
}
```

* Use `assert` for debugging purposes.

```c
/* Bad */
if (myArray == NULL) {
    /* Handle error and print a message */
}

/* Good */
assert(myArray != NULL);
```



* Prefer `switch` over `if` when possible.
* Prefer `for` over `while` when possible.

### Import

* Use `#include <...>` for system headers.
* Use `#include "..."` for project headers.

### Structures and enumerations

1. When structure is declared with name only, use `struct` keyword.

```c
struct MyStruct {
    /* ... */
};
```

2. When structure is declared with type only, use `typedef` keyword.

```c
typedef struct {
    /* ... */
} my_struct_t;
```

3. When structure is declared with name and type, use `typedef` keyword.

```c
typedef struct MyStruct {
    /* ... */
} my_struct_t;
```

* Enumerations should be declared with `typedef` keyword.
* Enumerations should be declared with name and type.

```c
typedef enum MyEnum {
    /* ... */
} my_enum_t;
```

### Macros 

* Use `#define` for constants.
* Use `#define` for macros.
* Protect macros using parentheses
```c
#define MY_MACRO(x) ((x) + 1)
``` 

* Protect macros using do-while
```c
#define MY_MACRO(x) do { \
    (x) = (x) + 1; \
} while (0)
```

## Snippets I like

### Basic

* `for` loop

```c
for (size_t i = 0; i < 10; ++i) {
    /* ... */
}
```

* `while` loop using `for`

```c
size_t i = 0;
for (; i < 10; ++i) {
    /* ... */
}

/* or */

for (size_t i = 0; i < 10; ) {
    /* ... */
    ++i;
}
```

* forever loop

```c
# define forever for (;;)

forever {
    /* ... */
    }
```

### Binary operations

* Swap two variables

```c
#define SWAPP(a, b) do { \
    a ^= b; \
    b ^= a; \
    a ^= b; \
} while (0)

/* or */

#define SWAP(a, b) (((a) ^ (b)) && ((b) ^= (a) ^= (b), (a) ^= (b)))
```

### Strings 

* ToLower 
    
```c
#define TOLOWER(c) ((c) | 0x20)
/* 0x20 = 0010 0000  = 32 */

/* or */

#define IS_UPPER_CASE(c) ((c) - 'A' <= 'Z' - 'A')
#define TOLOWER(c) (IS_UPPER_CASE(c) ? (c) | 0b100000 : (c))

/* or */

#define TOLOWER(c) ((c) | ' ')
```

* ToUpper

```c
#define TOUPPER(c) ((c) & ~0x20)

/* or */

#define IS_LOWER_CASE(c) ((c) - 'a' <= 'z' - 'a')
#define TOUPPER(c) (IS_LOWER_CASE(c) ? (c) & ~0b100000 : (c))

/* or */

#define TOUPPER(c) ((c) & '_')
```



## Inspiration

* [Educative](https://www.educative.io)
* [@MaJerle](https://github.com/MaJerle/c-code-style)
* [@Tmatis](https://github.com/tmatis/42make/blob/master/Makefile)
* [Awesome Competitive Programming](https://github.com/lnishan/awesome-competitive-programming)
