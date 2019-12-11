#include<stdio.h> 
#include<stdlib.h>
#include <fcntl.h> 
#include<unistd.h>
#include<string.h>
int main() 
{ 
  int fd, sz,fd1,fd2; 
  char *c = (char *) calloc(100, sizeof(char)); 
  
  fd = open("buffer.txt", O_RDONLY); 
 // printf("fd of open is %d ",fd);
  
 // if (fd < 0) { perror("r1"); exit(1); } 
  
  sz = read(fd, c, 101); 
   printf("fd of read is %d ",sz);
  printf("called read(% d, c, 10).  returned that"
         " %d bytes  were read.\n", fd, sz); 
  c[sz] = '\0'; 
  /*printf("Those bytes are as follows: % s\n", c); 
  fd1=creat("file2.txt",O_CREAT);
   printf("fd of create is %d ",fd1);
  fd2=dup(fd1);
   printf("fd of duplicate is %d ",fd2);
  sz = write(fd2, c, 71);
   printf("fd of write is %d ",sz);*/
    int fd4=creat("file3.txt",O_CREAT|O_WRONLY);
   printf("fd of create is %d ",fd4);
   lseek(fd, 30, 20); 
            write(fd4, c, 100); 
} 


