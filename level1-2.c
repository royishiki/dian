#include<stdio.h>
int main() 
{ 
	FILE *fp;
	fp= fopen("shuju.dat","r");
	if((fp=fopen("shuju.dat","r"))==NULL)
	{
		printf("cannot open this file\n");
	}
    int a,b,c;
       fscanf(fp,"%d %d %d",&a,&b,&c);
    int m,t;
       m=0;
       t=0;
       printf("%d,%d,%d\n",c,t,m);
          t=abs(a-c); 
       printf("%d,%d,%d\n",a,t,m+1);
          a=abs(a-b);
       printf("%d,%d,%d\n",b,t+a,m);
    fclose(fp);
return 0;
    	
}
