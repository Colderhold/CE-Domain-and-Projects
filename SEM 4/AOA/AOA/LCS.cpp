#include<stdio.h>
#include<string.h>
 
int i,j,m,n,c[20][20],count;
char x[20],y[20],b[20][20];

void lcs();
void print(int i,int j);

int main()
{
    printf("Enter the 1st string: ");
    scanf("%s",&x);
    printf("Enter the 2nd string: ");
    scanf("%s",&y);
    printf("LCS matrix is: \n");
    lcs();
    return 0;
}

void lcs()
{
  m=strlen(x);
  n=strlen(y);
  for(i=0;i<=m;i++)
    c[i][0]=0;
  for(j=0;j<=n;j++)
    c[0][j]=0;
  for(i=1;i<=m;i++)
  {
        for(j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='d';
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]='u';
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]='s';
            }
        }
   }
   for(i=1;i<m;i++)
   {
        for(j=1;j<n;j++)
        {
            printf(" %d%c ",c[i][j],b[i][j]);
        }
        printf("\n");
   }
   print(m,n);
   printf("\n Length of sequence is: %d",count);
}

void print(int i,int j)
{
   if(i==0 || j==0)
        return;
   if(b[i][j]=='d')
   {
     print(i-1,j-1);
     printf("%c",x[i-1]);
     count++;
   }
   else if(b[i][j]=='u')
   {
        print(i-1,j);
   }
   else
   {
        print(i,j-1);
    }
}
