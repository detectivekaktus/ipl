# The Imperative Programming Language
The imperative programming language, IPL for short, is a high-level functional imperative programming language that is under development. The file extension for the language is `.ipl`.

The goals of this project are the following:
1. Get a Turing-complete programming language that can be used as a tool to solve problems.
2. Implement an assembly-like syntax for the language.
3. Implement x86-64 compilation.
4. Implement javascript compilation.
5. Implement some core utilities and functions.

## Syntax and features
You may want to check out the syntax for the language down below. Keep in mind that the final result may look different from what you see below!
Here also you can take a look at desired features this language aims to achieve.

### Hello World
```ipl
integer main <- (argv: string[]):
    set msg: string = "Hello World"
    print msg
    ret 0
```

### Loops
```ipl
// For loop
integer main <- (argv: string[]):
    set i: integer = 0
    loop i in 0..100 start
        call tostring, i; string str
        print str
    end
    ret 0
```

```pl
// While loop
integer main <- (argv: string[]):
    set i: integer = 0
    set j: integer = 10
    loop i < j start
        call tostring, i; string str_i
        call tostring, j; string str_j
        
        print str_i
        print str_j
        inc i
    end
    ret 0
```

### Conditions
```ipl
integer main <- (argv: string[]):
    set a: integer = 10
    set b: integer = 5
    check a < b start
        print "How"
        ret 0
    end
    print "a is greater than b"
    ret 0
```

### Enums
```ipl
integer enum RATING:
    HIGH,
    MEDIUM,
    LOW
```

### Structs
```ipl
struct Human:
    name: string,
    age: integer
```

### Functions
```ipl
// Functions without return value
void hello <- ():
    print "Hello World"

// Functions with return value
integer sum <- (a: integer, b: integer):
    re a + b

integer main <- (argv: string[]):
    call hello; null
//  Hello World
    call sum, 5, 2; integer res
    call tostring, res; string str
    print str
//  7
    ret 0
```

### Arrays
```ipl
integer main <- (argv: string[]):
    set arr: integer[] = [1, 2, 3, 4, 5]
    set arr[1] = 5
//  arr = [1, 5, 3, 4, 5]

    del arr[1]
//  arr = [1, 3, 4, 5]

    push arr, 6
//  arr = [1, 3, 4, 5, 6]

    ins arr, 1, 2
//  arr = [1, 2, 3, 4, 5, 6]
    ret 0
```

### Maps
```ipl
integer main <- (argv: string[]):
    set hashmap: map[string, integer] = {}
    set hashmap["one"] = 1
    set hashmap["two"] = 2
    set hashmap["three"] = 3
//  map = { "one": 1, "two": 2, "three": 3 }

    del hashmap["two"]
//  map = { "one": 1, "three": 3 }

    has hashmap["two"]
//  false
    ret 0
```

## Built-in types
| Type | Possible values | Equivalent in C |
| ---- | --------------- | --------------- |
| integer | from −9223372036854775807 to +9223372036854775807 | signed long long int |
| decimal | from 1.7E-308 to 1.7E+308 | double |
| boolean | true or false | bool |
| string | 1024 bytes long string | char[] |
| null | null | NULL |
| map | ... | internal hashmap implementation |

## Build and dependencies
The project depends on the NASM assembler and a modern C compiler such as GCC or Clang, so be sure to install them on your machine. Unfortunately, the project is not made for Windows-driven operating systems and will probably never be supported on them.

To build the project simply invoke the `build.sh` script in the root directory and you will find yourself with `ipl` executable inside the same directory.

## Contributing
Feel free to improve this language as we go along but be sure to read [CONTRIBUTING.md](https://github.com/detectivekaktus/ipl/blob/main/CONTRIBUTING.md) file before submitting a pull request.
