#include "get_next_line.h"
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