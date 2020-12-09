#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

int  valid(char a)
{
    if(a >= 'A' && a <= 'Z')
        return 1;
    else if(a >='a' && a <='z')return 1;
    else if((a-'0')>=0 &&(a-'0')<=9)return 1;
       else return 0;
}
int validoption(char B[],int j)
{
    int k=0;
    int n=j-1;
       while(k<n)
    {
        if(B[k]!=B[n])
           return 0;
        k++,n--;
      }
      return 1;
}

int main()
{
 int test=0;
  scanf("%d",&test);
  while(test--)
    {
        fflush(stdin);
    char A[100000];
    char B[100000]={0};
    int i=0,j=0;

  //  printf("\n\tEnter the String : ");
    scanf("%[^\n]%*c",A);

    for(i=0;A[i]!='\0';i++)
    {
        if(valid(A[i]))
           {
            B[j++]=towlower(A[i]);
           }
    }

   // printf("%s",B);
  //printf("\n\tValue of  J is : %d",j);
       
     printf((validoption(B,j)==0)?"NO\n" : "YES\n");
    //((validoption(B,j)==1)?printf("YES\n"):printf("NO\n"));
}
}