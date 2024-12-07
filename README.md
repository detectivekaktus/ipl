# The Imperative Programming Language
The imperative programming language, IPL for short, is a high-level functional imperative programming language that is under development. The file extension for the language is `.ipl`.

The goals of this project are the following:
1. Get a Turing-complete programming language that can be used as a tool to solve problems.
2. Implement an assembly-like syntax for the language.
3. Implement x86-64 compilation.
4. Implement javascript compilation.
5. Implement some core utilities and functions.

## Syntax
You may want to check out the syntax for the language down below. Keep in mind that the final result may look different from what you see below!

Here's a Hello World program in this language.
```ipl
main:
    set msg: string = "Hello World"
    call print, msg; out
    ret 0
```

A fizzbuzz problem on numbers from 0 to 99.
```ipl
main:
    set i: integer = 0
    for i 0..100 start
        if i % 3 == 0 && i & 5 == 0 start
            call print, "FizzBuzz"; out
        else if i % 3 == 0 start
            call print, "Fizz"; out
        else if i % 5 == 0 start
            call print, "Buzz"; out
        else
            call string, i; str
            call print, str; out
        end
    end
    ret 0
```

## Contributing
Feel free to improve this language as we go along but be sure to read [CONTRIBUTING.md](https://github.com/detectivekaktus/ipl/blob/main/CONTRIBUTING.md) file before submitting a pull request.
