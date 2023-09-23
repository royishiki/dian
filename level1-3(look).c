/*此采用look算法，n为总乘客数，数组a[n]、b[n]分别存放乘客的起始、目标楼层
  m为电梯所在楼层，r为电梯内人数，t为时间*/ 
#include<stdio.h>
#include<math.h>
int main( )
{int n,q;
 	printf("input how many pepole:");
 	scanf("%d",&n);
  	q=n;
 int a[n],b[n],c[n],i;
  	printf("input the floor:\n");//输入用户起始楼层 ,目标楼层 
 	for(i=0;i<q;i++)
 	{
  		scanf("%d,%d",&a[i],&b[i]);
 	}
  	printf("\n");
 int m,t,r;
    t=0,r=0;
  	printf("电梯起始楼层："); 
    scanf("%d",&m);
    printf("%d,%d,%d\n",m,t,r);
    do
    {
 		for(m,t;m<11;m++,t++)//上行 
 		{
  			for(i=0;i<q;i++)
  			{   
   				if(m==c[i])//送人 
   				{
   					r=r-1;
  			 		printf("%d,%d,%d\n",m,t,r); 
  					c[i]=12;
					n=n-1; 
   				}
   				if(m==a[i])//接人 
   				{
					if(r==4)
					continue;//超载情况下忽略请求 
    				r=r+1;
    				printf("%d,%d,%d\n",m,t,r);
   					c[i]=b[i];
   					a[i]=12;//破坏a[i]，使其数据失效 
   				}	

  			}
 		}
 	if(m=11&&n>0||r>0)
 		{m=10,t=t-1;//调整误差 
  		for(m,t;m>0;m=m-1,t++)//下行 
  		{
  			for(i=0;i<q;i++)
  			{   
   				if(m==c[i])//送人 
   				{
   					r=r-1;
   					printf("%d,%d,%d\n",m,t,r); 
    				c[i]=12;
    				n=n-1;
   				}
   				if(m==a[i])//接人 
   				{
					if(r==4)
					continue;
    				r=r+1;
    				printf("%d,%d,%d\n",m,t,r);
    				c[i]=b[i];
    				a[i]=12;
   				}

  			}
  		}
  		m=1,t=t-1;//调整误差 
 		}
	}while(n!=0);
 return 0;
 }
