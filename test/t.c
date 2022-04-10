#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char** argv){
	int a=1,b=2;
	char s[]="dfsa";
	if (a==b){
		printf("a=1\n");
	}
	else{
		printf("others\n");
	}
	if(strcmp(s,"1234")==0){
		printf("compare sucess\n");
	}
	return 0;
}
