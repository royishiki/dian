/*此采用scan算法，n为总乘客数，数组d[n]、b[n]分别存放乘客的起始、目标楼层,
  a[n]、c[n]用来实时读取起始，目标楼层。 
  m为电梯所在楼层，r为电梯内人数，t为时间*/ 
#include<stdio.h>
int main( )
{int n,q,sum;
  	printf("输入乘坐电梯总人数:");
  	scanf("%d",&n);
 	q=n;
 int a[n],b[n],c[n],o[n],d[n],i,j,x,y,h;
  	for(i=0;i<q;i++)
  	{
   		c[i]=0,a[i]=0;
  	}
  	printf("输入用户起始楼层,目标楼层,时间（认为第一个人为0时刻 :\n");
  	for(i=0;i<q;i++)
  	{
  		scanf("%d,%d,%d",&d[i],&b[i],&o[i]);
  	}
  	printf("\n");
 int m,t,r;
  	t=0,r=0;
  	printf("电梯起始楼层："); 
  	scanf("%d",&m);
  	printf("%d,%d,%d\n",m,t,r);
    x=d[0];//判断电梯上行还是下行启动 
	if(m>x)
	 	goto xia;
 do
 {
  	shi:if(n>0)
 	{ 
	 	for(m,t;m<11;m++,t++)//上行 
  		{
   			for(h=0;h<q;h++)//按时间读入起始楼层 
   			{
  				if(o[h]==t)
  				a[h]=d[h];
   			} 
    		sum=0;
   			for(j=0;j<q;j++)//检查有无服务请求 
   			{
    			sum=sum+a[j]+c[j];
   			}
    		if(sum==0)
     		{
   	 			m=m-1;//消除误差，使电梯静止 
      			continue;
	 		}   
   			for(i=0;i<q;i++)
   			{   
    			if(m==c[i])//查有无乘客出电梯 
   				{
   					r=r-1;
   					printf("%d,%d,%d\n",m,t,r); 
   					n=n-1;
   					x=0,y=0;//判断电梯此时是否处在所有请求楼层的最高处 
    				for(j=0;j<q;j++)
    				{	
     					if(c[i]>=a[j])
     					 x=x;
     					else
     					 x=x+1;
    				}
    				if(x>0)
     				c[i]=0;//将已完成送人的楼层数据删除 
    				else
    				{
	 					for(j=0;j<q;j++)
      					{
      					 	if(c[i]>=c[j])
       						 y=y;
      					 	else
       						 y=y+1;
     					}
     					if(y>0)
      					c[i]=0;
     					else
     					{c[i]=0;
     					goto xia;}
    				}
   				}
    			if(m==a[i])//查有无乘客入电梯 
    			{
	 				if(r==4)//超载则忽略此次请求 
	  				continue;
     				r=r+1;
     				printf("%d,%d,%d\n",m,t,r);
     				c[i]=b[i];
     				x=0,y=0; 
     				for(j=0;j<q;j++)
     				{
      					if(a[i]>=a[j])
      					 x=x;
      					else
      					 x=x+1;
	 				}
    				if(x>0)
     				a[i]=0,o[i]=-1;//将该用户的时间破坏，防止第一个来的人与电梯楼层相同时电梯将此人接两遍
    				else
     				{
      					for(j=0;j<q;j++)
     					{
       						if(a[i]>=c[j])
        					y=y;
       						else
       	 					y=y+1;
      					}
     					if(y>0)
      					a[i]=0,o[i]=-1;
     					else
    					{a[i]=0,o[i]=-1;
     					goto xia;}
     				}
    			}
   			}
   	
  		}
  
  	}
  	xia:if(n>0||r>0)//下行  
  	{if(m==11)
    m=10,t=t-1;
  		for(m,t;m>0;m=m-1,t++)
  		{
   			for(h=0;h<q;h++)
   			{
  				if(o[h]==t)
  			 	 a[h]=d[h];
    		}	 
    		sum=0;
   			for(j=0;j<q;j++)
   			{
   			 	sum=sum+a[j]+c[j];
   			}
   			if(sum==0)
   			{
    			m=m+1;
    			continue;
   			}
   			for(i=0;i<q;i++)
   			{  
   			 	if(m==c[i])//
    			{
   	 				r=r-1;
   	 				printf("%d,%d,%d\n",m,t,r); 
   	 				n=n-1;
   	 				x=0,y=0; //判断电梯此时是否处在所有请求楼层的最低处  
    				for(j=0;j<q;j++)
    				{
     					if(c[i]<=a[j])
        				x=x;
     					else
     					{
      						if(a[j]==0)
	  		 				x=x;
	  						else
	   						x=x+1; 
	 					}
    				}
    				if(x>0)
     				c[i]=0;
    				else
     				{
	  					for(j=0;j<q;j++)
      					{
       						if(c[i]<=c[j])
        						y=y;
       						else
       						{
	    						if(c[j]==0)
         						y=y;
        						else
         						y=y+1;
       						}
      					}
      					if(y>0)
      					c[i]=0;
      					else
      					{c[i]=0;
       					goto shi;}
     				}     
    			}
    			if(m==a[i])//
    			{
	 				if(r==4)
      				continue;
     				r=r+1;
     				printf("%d,%d,%d\n",m,t,r);
     				c[i]=b[i];
    				x=0,y=0; 
    				for(j=0;j<q;j++)
    				{
     					if(a[i]<=a[j])
        				x=x;
     					else
     					{
      						if(a[j]==0)
	   						x=x;
	  						else
	   						x=x+1; 
	 					}
    				}
    				if(x>0)
     				a[i]=0,o[i]=-1;
    				else    
					{
						for(j=0;j<q;j++)
      					{
      						if(a[i]<=c[j])
        					y=y;
      						else
      		 				{
	    						if(c[j]==0)
         						y=y;
        						else
         						y=y+1;
       						}
      					}
      					if(y>0)
       					a[i]=0,o[i]=-1;
      				else
      				{a[i]=0,o[i]=-1;
      			 	goto shi;}
  	 				}
    			}
   			} 
 	 	}
   		if(m==0)//调整误差 
   		m=1,t=t-1;
  	}
 }while(n!=0);
 return 0;
}
