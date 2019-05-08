#include <stdio.h>
#include <string.h>
typedef struct Terminal
{
    char r1[10];
    char r2[10];
    char first[10];
    char follow[10];
    int ft;
    int fot;
} Term;

Term r[2];
char* ip="abba$";

int isterminal(char c)
{
    int comp = (int)c;
    if((comp>=97 && comp<=122) || comp==51)
        return 1;
    return 0;
}

void calfirst(int rno)
{
    int i;
    for(i=2;r[rno].r1[i]!='\0';i++)
    {
        if(isterminal(r[rno].r1[i]))
        {
            r[rno].ft++;
            r[rno].first[r[rno].ft]=r[rno].r1[i];
            r[rno].first[r[rno].ft+1]='\0';
            break;
        }
    }
    if (rno==1)
    {
        for(i=2;r[rno].r2[i]!='\0';i++)
        {
            if(isterminal(r[rno].r2[i]))
            {
                r[rno].ft++;
                r[rno].first[r[rno].ft]=r[rno].r2[i];
                r[rno].first[r[rno].ft+1]='\0';
                break;
            }
        }
    }
}

void calfollow(int rno)
{
    int i,j;
    if(rno==0)
    {
        r[rno].follow[++r[rno].fot]='$';
        r[rno].follow[r[rno].fot+1]='\0';
    }
    for(i=2;r[rno].r1[i]!='\0';i++)
    {
        if(r[rno].r1[i]=='A')
            j=0;
        if(r[rno].r1[i]=='B')
            j=1;
        if(r[rno].r1[i]=='A'||r[rno].r1[i]=='B')
        {
            if(isterminal(r[rno].r1[i+1]) && r[rno].r1[i+1]!='3')
            {
                r[j].follow[++r[j].fot]=r[rno].r1[i+1];
            }
            else
            {
                if(r[rno].r1[i+1]=='A')
                    strcat(r[j].follow,r[0].first);
                if(r[rno].r1[i+1]=='B')
                    strcat(r[j].follow,r[1].first);                
            }  
        }
    }
    for(i=2;r[rno].r2[i]!='\0';i++)
    {
         if(r[rno].r1[i]=='A')
            j=0;
        if(r[rno].r1[i]=='B')
            j=1;
        if(r[rno].r1[i]=='A'||r[rno].r1[i]=='B')
        {
            if(isterminal(r[rno].r2[i+1]) && r[rno].r2[i+1]!='3')
            {
                r[j].follow[++r[j].fot]=r[rno].r2[i+1];
            }
            else
            {
                if(r[rno].r2[i+1]=='A')
                    strcat(r[j].follow,r[0].first);
                if(r[rno].r2[i+1]=='B')
                    strcat(r[j].follow,r[1].first);                
            }  
        }
    }
}

void main()
{
    strcpy(r[0].r1,"A=aBa");
    strcpy(r[1].r1,"B=bB");
    strcpy(r[1].r2,"B=3");
    strcpy(r[0].r2,"");
    r[0].fot=r[0].ft=r[1].fot=r[1].ft=-1;
    int i;
    for(i=0;i<2;i++)
    {
        calfirst(i);
    }
    printf("First of A %s \n",r[0].first);
    printf("First of B %s \n",r[1].first);
    for(i=0;i<2;i++)
    {
        calfollow(i);
    }
    printf("Follow of A %s \n",r[0].follow);
    printf("Folow of B %s \n",r[1].follow);
}