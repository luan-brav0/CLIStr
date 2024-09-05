# My first CLI app in C
This is what I came up with quickly just to put out what I got so far from Chapter 5 in classic *The C Programming Language* book.

## Features
- strLen (Get String Length);
- strCat (Concatenate a string at the end of another);
- strEnd (Check for a given suffix in a string).

## Usage
`clistrutils -l <string>`            - Get string length
`clistrutils -c <string1> <string2>` - Concatenate 2 strings
`clistrutils -e <string> <suffix>`   - Check if string ends with suffix

## Building from source
```sh
gcc -c strUtils.c
ar rcs libstrUtils.a strUtils.o

gcc -o clistrutils clistrutils.c -L. -strUtils
```
