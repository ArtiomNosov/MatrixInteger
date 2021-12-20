#include "UI.h"

char *get_str()
{
    char buf[81] = {0};
    char *res = NULL;
    int len = 0;
    int n = 0;

    do {

        n = scanf("%80[^\n]", buf);
        
        if (n<0)
        {
            if (!res)
            {
                return NULL;
            }
        } else if (n > 0) {

            int chunk_len = strlen(buf);
            int str_len = len + chunk_len;
            res = realloc(res, str_len + 2);
            memcpy(res + len, buf, chunk_len);
            len = str_len;
        } else {
            scanf("%*c");
        }
    } while (n > 0);


    if (len > 0)
    {
        res[len] = '\n';
        res[len+1] = '\0';
    } else {
        res = calloc(1, sizeof(char));
        *res = '\0';
    }

    return res;
}

int errorNoMemory(void* ptr)
{
    if (ptr == NULL)
    {
        printf("Ошибка! Недостаточно памяти!\n");
        scanf("%*c");
        return NoMemory;
    }
    return OK;
}