#include<stdio.h>
#include<strUtils.h>
#define MAXSTRLEN 100

typedef enum {
    len = 'l',
    cat = 'c',
    end = 'e',
} Opt;

int printUsage() {
    printf("String Utilities\n\n")
    printf("Usage:\n")
    printf("strutils -l <string>            - Get string length \n")
    printf("strutils -c <string1> <string2> - Concatenate 2 strings \n")
    printf("strutils -e <string> <suffix>   - Check if string ends with suffix \n")
    return 1;
}

int main(int argc, char* argv[]) {
    /* len
     * cat
     * end */
    // print usage and return error
    if (argc < 3)
       return printUsage();

    char* string1 = argv+2;
    char* string2 = argv+3;

    if (argv[1][0] == '-') {
        switch((Opt)argv[1][1]) {
            case len:
                printf("%s\n", strLen(string1));
                return 0;
            case cat:
                printf("%s\n", strCat(string1, string2));
                return 0;
            case end:
                printf("%s\n", strEnd(string1, string2));
                return 0;
            default:
                printf("ERROR: Invalid inputs\n");
                return 1;
        }
    }
    return 0;
}

