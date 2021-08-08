#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

char* to_hex(int64_t val)
{
    char* HEX_DIGITS = "0123456789abcdef";
    char* s = malloc(sizeof(char)*10);
    if(val<0)
    {
        int64_t a =1;
        val+=(a<<32);
    }
    int limit =0;
    while (1)
    {
        char d[2] = {HEX_DIGITS[val & 0xf],'\0'};
        
        char* temp= strdup(s);
        strcpy(s,d);
        strcat(s,temp);
        free(temp);

        val >>=4;
        limit++;
        if (val==0 || limit==8)
        {
        break;
        }
    }
    char* f = "0x";
    char* temp2= strdup(s);
    strcpy(s,f);
    strcat(s,temp2);
    free(temp2);
    return(s);
}

int main(){
    //33 # 0x21
    //-1 # 0xffffffff
    char* ans = to_hex(-1);
    int i =0;

    while (ans[i] != '\0')
    {
        printf("%c",ans[i]);
        i++;
    }
    free(ans);
    return 0;
}
