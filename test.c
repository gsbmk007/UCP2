#include <stdio.h>

int main(int argc, char *argv[])

{


printf("Hello World");

FILE *file;

char filename[]="data.txt";
char word[100];
int nread=0;
int a,b;

file =fopen(filename,"r");

if(file == NULL){

    printf("Failed to open file ");

    return 1;
}

int done =0;
while(  !done){
    nread=fscanf(file,"%d %d",&a,&b);
    printf("Nread = \n\n"+nread);
    printf("A:%d B:%d\n\n",a,b);
    if(nread!=3){
        done=1;}
    printf("sss");
    


}


}
