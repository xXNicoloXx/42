#include <string.h>
#include <stdio.h>



char * strstr( const char * fullString, const char * substring );


char *ft_strstr(char *src, char *cmp )
{
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    while (src[i] != '\0')
    {
        k = i;
        while (src[k] == cmp[j])
        {
            k++;
            j++;
        }
        if (cmp[j] == '\0')
            return(&src[i]);
        i++;
        j = 0;
    }
    
    return(0);

}

int main(void)
{
    char *srcstr = "Bonjour les amis comment ca va ?";
    char *cmpstr = "om";

    printf("%s\n", strstr(srcstr, cmpstr));
    printf("%s\n", ft_strstr(srcstr, cmpstr));
}