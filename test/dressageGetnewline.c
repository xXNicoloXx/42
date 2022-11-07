#include<stdio.h>
#include<fcntl.h>
#include <unistd.h>
#include <stdlib.h>

//char *get_next_line(int fd);



char *ft_my_malloc(int)


int ft(int fd1)
{
	int size = 10;
	int i = 0;
	static char *str;
	int ok = 1;
	static int readnbr = 1;
	printf("\n\t\tintro str = %s\n",str);
	if (str == (NULL))
		str = malloc(sizeof(char) * (size + 1));
	str[size] = '\0';


	while (str[i] == 'V')
		i++;
	//printf("i = %d", i);
	ok = 1;
	while (str[i] != 'H' || ok)
	{
		//printf("str[%d] = %c (size = %d)\n", i, str[i], size);
		if (i >= size)
		{
			read(fd1, str, size);
			printf("\n\t\tREAD %d str = %s\n", readnbr, str);
			readnbr++;
			i = 0;
		}
		else
		{
			printf("%c", str[i]);
			str[i] = 'V';
			i++;
			ok = 0;
		}
	}
	str[i] = 'V';
	printf("\n\t\toutro str = %s\n",str);
	
	/*while (i < size)
	{
		printf("debug2,5 %d\n", i);
		printf("%c", str[i]);
		i++;
	}
	printf("debug3 %d\n", i);
	while (ok)
	{
		read(fd1, str, size);
		while (i < size && ok == 1)
		{
			if (str[i] == 'H')
				ok = 0;
			else 
				printf("%c", str[i]);
				
		}
		*/

	

	//free(str);
}

int main ()
{

	int fd = open("myfile.txt", O_RDONLY, 0);

	ft(fd);
	printf("\n========\n");
	ft(fd);
	printf("\n========\n");
	close(fd);
	fd = open("myfile.txt", O_RDONLY, 0);
	ft(fd);
	printf("\n========\n");
	ft(fd);
	printf("\n========\n");
	ft(fd);
	printf("\n========\n");
	close(fd);


}