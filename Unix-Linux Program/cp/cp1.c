/*cp version1 
 *copy file
 *use opne() write() read() creat()
 *
 *      open source file
 *      open destination file
 * +--->read from src file-----<is eof?>-----+
 * |                                         |
 * +----write to dst file                    |
 *                                           |   
 *      close src file                       |
 *      close dst file<----------------------+  
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define COPYMODE 0644   //The permission value of destination file
#define BUFSIZE 4096    //How much data will be read into memory

void printerr(char *,char *);

int main(int argc,char *argv[]){
    char buf[BUFSIZE];//define a buffer
    int input_fd,output_fd,n_bytes;
    if(argc!=3){//Arguments not enough
        fprintf(stderr,"usage:%s <source file> <destination file>\n",argv[0]);
        exit(1);
    }
    input_fd=open(argv[1],O_RDONLY);//open source file
    if(input_fd==-1){
        printerr("Cannot Open input file",argv[1]);
    }
    output_fd=creat(argv[2],COPYMODE);//create destination file
    if(output_fd==-1){
        printerr("Cannot Create output file",argv[2]);
    }
    while( (n_bytes=read(input_fd,buf,BUFSIZE))>0 ){//read and write file
        if(write(output_fd,buf,n_bytes)!=n_bytes)
            printerr("Write Error to",argv[2]);
    }
    if(n_bytes==-1) //There are some errors if n_bytes is -1 
        printerr("Read error from",argv[1]);
    if( close(input_fd)==-1||close(output_fd)==-1 ) //clsoe file
        printerr("Error when closing files","");
    return 0;
}

void printerr(char *str1,char *str2){
    fprintf(stderr,"%s %s",str1,str2);
    perror(str2);
    exit(1);
}
