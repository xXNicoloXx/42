#include <string.h>
#include <stdio.h>



char * strnstr(const char *  s1 , const char *  s2 , size_t  len );


char *ft_strnstr(char *src, char *cmp, int n)
{
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    while (src[i] != '\0')
    {
        k = i;
        //printf("src[%d] = %c\n", i, src[i]);
        while (src[k] == cmp[j])
        {
            k++;
            j++;
        }
        if (k > n)
            return(0);
        if (cmp[j] == '\0')
            return(&src[i]);
        i++;
        j = 0;
    }
    
    return(0);
    

}

int main(void)
{
    int i = 0;
    while (i < 20)
    {
    
    
    char *srcstr = "Bonjour les amis comment ca va ?";
    char *cmpstr = "s";


    printf("%s\n", strnstr(srcstr, cmpstr, i));
    printf("%s\n\n\n", ft_strnstr(srcstr, cmpstr, i));
    i++;
    }
}