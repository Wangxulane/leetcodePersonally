#include<stdio.h>
#include<string.h>//strlen()
#include<stdlib.h>//atoi()

int lengthOfLongestSubstring(char* s) {
    int max=1,flg=1;
    if(strlen(s)==0){
        return 0;
    }
    for(int i=0;i<strlen(s);i++){
        for(int j=i+1;j<strlen(s);j++){
            for(int k=i;k<j;k++){
                if(s[k]==s[j]){
                    flg=0;
                }
            }
            if(!flg){
                break;
            }
            if(max<(j-i+1)){
                max=j-i+1;
            }
        }
        flg=1;
    }
    return max;
}
int main(){
    char *s=(char*)malloc(100*sizeof(char));
    s="abcabcnvjiopr";
    printf("%d",lengthOfLongestSubstring(s));
}