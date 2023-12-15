#include "get_next_line_bonus.h"
// int main()
// {
//     int fd = open("test.txt", O_RDWR);
//     char *r;
    
//     r = get_next_line(fd);
//     printf("%s", r);
//     r = get_next_line(fd);
//     printf("%s", r);
//     r = get_next_line(fd);
//     printf("%s", r);

//     // while ((r =get_next_line(fd)) != NULL)
//     // {
//     //   printf("%s",r);
//     // }
//     close(fd);

//     return 0;
// }

//+++++++++++++++++++++++
// int main()
// {
//     int fd = open("test.txt", O_RDWR);
//     char *r;
//     while ((r =get_next_line(fd)) != NULL)
//     {
//       printf("%s",r);
// 	  system("leaks a.out");
//     }
// 	close(fd);
// 	printf("%s",r);
//     return 0;
// }
//+++++++++++++++++++++++
// int main()
// {
//     int fd = open("test.txt", O_RDWR);
//     char *r;
    
//     r = get_next_line(fd);
//     printf("%s\n",r);
// 	free(r);
// 	close(fd);

// 	fd = open("test.txt", O_RDWR);
// 	r = get_next_line(fd);
//     printf("%s",r);
// 	free(r);
    
//     close(fd);
//     return 0;
// }

//======bonus 

// int main()
// {
// 	int fd1 = open("test.txt",O_RDONLY);
// 	int fd2 = open("test2.txt",O_RDONLY);
// 	char *r1 = get_next_line(fd1);
// 	printf("%s",r1);
// 	free(r1);
// 	char *r2 = get_next_line(fd2);
// 	printf("%s",r2);
// 	free(r2);
// }

//---------

int main()
{
	int fd1 = open("test.txt",O_RDONLY);
	int fd2 = open("test2.txt",O_RDONLY);
	char *r ;
	 while ((r =get_next_line(fd2)) != NULL)
	{
		if(fd2 == 4)
			fd2=3;
		else
			fd2=4;
		printf("%s",r);
	}
}
