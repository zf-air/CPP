#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char* s="2*xs-y";
    char* p;
    p=strstr(s,"xs");
    printf("%d",p-s);
    return 0;
}
