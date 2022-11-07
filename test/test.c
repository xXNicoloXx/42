#include<stdio.h>
#include<fcntl.h>
#include <unistd.h>
#include <stdlib.h>

//char *get_next_line(int fd);

int ft(int size)
{
	int i = 0;
	char *str;
	int iligne = 0;
	int ok = 1;
	
	static int nbrligne = 0;
	str = malloc(sizeof(char) * (size + 1));
	str[size] = '\0';

	int fd1 = open("myfile.txt", O_RDONLY, 0);
	read(fd1, str, size);
	//printf("\n\t\tREAD\n");
	
	while (iligne < nbrligne)
	{
		while (i < size)
		{
			if (str[i] == 'H')
				iligne++;
			if (iligne == nbrligne)
				break;
			i++;
		}
		if (iligne != nbrligne)
		{
			read(fd1, str, size);
			//printf("\n\t\tREAD\n");
			i = 0;
		}
		//printf("\tnbrligne = %d  | iligne = %d \t str[%d] = %c\n",nbrligne, iligne , i,str[i]);
	}
	//printf("INTER %s i = %d \n", str, i);
	if (iligne)
		i++;
	while (str[i] != 'H')
	{
		//printf("str[%d] = %c (size = %d)\n", i, str[i], size);
		if (i >= size)
		{
			read(fd1, str, size);
			//printf("\n\t\tREAD\n");
			i = 0;
		}
		else
		{
			printf("%c", str[i]);
			i++;
		}
	}
	
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

	
	close(fd1);
	free(str);
	nbrligne++;
	printf("\t\t\t%d", nbrligne);
}

int main ()
{
	int size = 10;
	
	ft(size);
	printf("\n========\n");
	ft(size);
	printf("\n========\n");
	ft(size);
	printf("\n========\n");
	ft(size);
	printf("\n========\n");
	ft(size);
	printf("\n========\n");


}