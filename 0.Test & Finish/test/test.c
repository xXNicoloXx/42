# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <ctype.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <fcntl.h>
# include <stdarg.h>

void test2(char *test, va_list list)
{
    printf("%d\n", va_arg(list, int));

}
int test(char *test, ...)
{
	int i;
	int nbrch;
	va_list list;
    void *oui;

	i = 0;
	nbrch = 0;
	va_start(list, test);
	test2(test, list);
	test2(test, list);
	test2(test, list);
	test2(test, list);
    return (0);
}

int main (void)
{
    test("test", 1, 2, 3 ,4);
    return (0);
}