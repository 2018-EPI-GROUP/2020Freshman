#include <cstdio>
#include <iostream>
#include <sys/types.h>
#include <dirent.h>
#include <vector>
#include <string>
#include <algorithm>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>
using namespace std;

vector<string> vec;
void do_ls(char *,int);
void print_vec();
int maxL=0;
int main(int ac,char *av[]){
    if(ac == 1) do_ls(".",0);
    else{
        for(int i = 1;i<ac;i++)
            do_ls(av[i],0);
    }
    return 0;
}

void do_ls(char *dir,int mode){
    DIR *d_fd = opendir(dir);
    if(d_fd == NULL){
        fprintf(stderr,"%s Cannot be opened",dir);
        return;
    }
    struct dirent *direntp=NULL;
    while( (direntp=readdir(d_fd)) != NULL ){
        if(!mode){
            if(direntp->d_name[0] == '.')
                continue;
        }
        //printf("%s\n",direntp->d_name);
        maxL=direntp->d_namelen>maxL?direntp->d_namelen:maxL;
        string tmp=direntp->d_name;
        vec.push_back(tmp);
    }
    print_vec();
    closedir(d_fd);
}

void print_vec(){
    sort(vec.begin(),vec.end());
    int n=vec.size();
    int terL=0;
    struct winsize size;
    ioctl(STDIN_FILENO,TIOCGWINSZ,&size);
    terL=size.ws_col;
    int col=ws_col/maxL;
    col=(col==0?1:col);
    int j=0;
    for(int i=0;i<n;i++){
        j++;
        cout<<vec[i]<<" ";
        if(j==col){
            j=0;
            cout<<endl;
        }        
    }
}
