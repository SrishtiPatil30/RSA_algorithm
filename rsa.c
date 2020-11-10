#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
int gcd(int m,int n)
{
    int r=0;
    while(n!=0)
    {
        r=m%n;
        m=n;
        n=r;
    }
    return m;

}
int main()
{
    
    int p,q,n,e,d,lambdaN,length,i,j;
    char string[20];
    int message[20],cipher[20];
    printf("\n \nEnter two distinct prime numbers:");
    scanf("%d%d",&p,&q);
    n=p*q;
    lambdaN=(p-1)*(q-1);
    for(i=2;i<lambdaN;i++)
        if(gcd(i,lambdaN)==1)break;
    e=i;
    printf("\nPublic key=(%d,%d)",n,e);
   for(i=2;i<lambdaN;i++)
        if((e*i-1)%lambdaN==0)break;
    d=i;
    printf("\nPrivate key=(%d,%d)\n",n,d);
    printf("Enter the message, lower case characters, no space in between:");
    scanf("%s",string);
    length=strlen(string);
    for(i=0;i<length;i++)
    {
        message[i]=string[i]-96;
    }
    printf("\nAt Sender encrypt message to cipher, cipher=");
    for(i=0;i<length;i++)
    {
       
        cipher[i]=1;
        for(j=0;j<e;j++)
            cipher[i]=(cipher[i]*message[i])%n;

        printf("\n%c as %d",message[i]+96,cipher[i]);

    }
    printf("\nAt Receiver decrypt cipher to message, message=");
    for(i=0;i<length;i++)
    {
    
    
        message[i]=1;
        for(j=0;j<d;j++)
            message[i]=(message[i]*cipher[i])%n;
    
        
        printf("\n%d as %c",cipher[i],message[i]+96);

    }
    printf("\n");
    return 0;

}
