#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* inv(char *s, int len) {
    char temp;
    for(int i = 0; i < len / 2; i++) {
        temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
    return s;
}

char* finalString(char* s) {
    int len = strlen(s);
    char* ts = (char*)malloc(sizeof(char) * (len + 1)); // 分配足够的内存来存储字符串，包括终止空字符 '\0'
    if (ts == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(ts, s); // 将输入字符串复制到动态分配的内存中
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (ts[i] == 'i') {
            inv(ts, i+1);
        }
    }
    int co=strlen(ts);
    for (int i = 0; i < co; i++) {
        if (ts[i] != 'i') {
            ts[j++] = ts[i];
        }
    }
    ts[j] = '\0';
    return ts;
}
int main() {
    char s[] = "abcideifghi";
    char* result = finalString(s);
    printf("%s\n", result);
    free(result); // 释放动态分配的内存
    return 0;
}