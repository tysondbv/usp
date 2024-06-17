#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<setjmp.h>

jmp_buf buf;
int main(){
volatile int x = 10;
register int y = 50;
printf("before jmp functions");
printf("x and y values %d %d\n ",x,y);
if(setjmp(buf)!=0){
printf("x and y values after jump functions : %d %d\n ",x,y);
return 0;
}
x=30;
y=40;
longjmp(buf,1);
}
