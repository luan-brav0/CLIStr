#include "strUtils.h"

int strLen(char* c) {
    int i;
    while (*c != '\0')
        i++, c++;
    return i;
}

int strEnd(char* s, char* t) {
    int sLen = strLen(s);
    int tLen = strLen(t);
    if (s == NULL || t == NULL) {
        printf("ERROR: strEnd recived at least one null pointer\n");
        return 0;
    }
    if (tLen > sLen) {
        printf("ERROR: trying to check for bigger string inside of another smaller string\n");
        return 0;
    }
    // point s to -tLen index
    printf("Checking if S ends in with T:\n%s\nand\n%s\n", s, t);
    s += sLen - tLen;
    for (; *t != '\0'; s++, t++)
        if (*s != *t)
           return 1;
    return 0;
}


char* strCat(char* s, char* t) {
    char* temp = (char*)malloc((sizeof(char) * (strLen(s)+strLen(t)))+1);
    char* pTemp = temp;
    if (temp == NULL) {
        printf("ERROR: Memory allocation failed.\n");
        return NULL;
    }
    printf("Attempt to concat:\n%s\nand\n%s\n", s, t);
    for (; *s != '\0'; pTemp++, s++)
        *pTemp = *s;
    }
    for (; *t != '\0'; pTemp++, t++)
        *pTemp = *t;
    return temp;
}

char* strCpy(char* s, char* t, int n) {
    char* temp = (char*)malloc((sizeof(char) * (strLen(s)+strLen(t)))+1);
    char* pTemp = temp;
    if (temp == NULL) {
        printf("ERROR: Memory allocation failed.\n");
        return NULL;
    }
    printf("Attempt to concat:\n%s\nand\n%s\n", s, t);
    for (; *s != '\0'; pTemp++, s++)
        *pTemp = *s;
    char* t0 = t;
    for (; t != t0+n; pTemp++, t++)
        *pTemp = *t;
    return temp;
}
