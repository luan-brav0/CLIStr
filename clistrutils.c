#include<stdio.h>
#include"strUtils.h"

#define MAXSTRLEN 100

typedef enum {
    len = 'l',
    cat = 'c',
    end = 'e',
} Opt;

int printUsage() {
    printf("String Utilities\n\n");
    printf("Usage:\n");
    printf("clistrutils -l <string>            - Get string length \n");
    printf("clistrutils -c <string1> <string2> - Concatenate 2 strings \n");
    printf("clistrutils -e <string> <suffix>   - Check if string ends with suffix \n");
    return 1;
}

int main(int argc, char* argv[]) {
    /* len
     * cat
     * end */
    // print usage and return error
    if (argc < 3)
       return printUsage();

    char** pString1 = argv+2;
    char** pString2 = argv+3;

    if (argv[1][0] == '-') {
        switch((Opt)argv[1][1]) {
            case len:
                printf("%d\n", strLen(*pString1));
                return 0;
            case cat:
                printf("%s\n", strCat(*pString1, *pString2));
                return 0;
            case end:
                int result = strEnd(*pString1, *pString2);
                printf((result == 1) ? "TRUE\n" : "FALSE\n", result);
                return 0;
            default:
                printf("ERROR: Invalid inputs\n");
                return 1;
        }
    }
    return 0;
}
