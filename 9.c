#include<stdio.h>
#include<stdlib.h>

typedef struct linked
{
  int val;
  struct linked* r;
}link;

link* head,*cur,*prev;
int ch,nf,ip,pf=0;
int *a;
int *ff;

void callfifo()
{
  ff = (int *)malloc(sizeof(int) * nf);
  int r = -1;
  int j, i;
  for (j = 0; j < nf; j++)
    ff[j] = -1;
  for (i = 0; i < ip; i++)
  {
    int flag = 0;
    for (j = 0; j < nf; j++)
    {
      if (a[i] == ff[j])
      {
        flag = 1;
        break;
      }
    }
    if (flag == 0)
    {
      r = (r + 1) % nf;
      ff[r] = a[i];
      pf++;
    }
  }
}

void initalizelink()
{
  head = (link*) malloc (sizeof(link));
  head->val = -1;
  link *temp = (link*) malloc (sizeof(link));
  temp->val = -1;
  link *temp1 = (link*) malloc (sizeof(link));
  temp1->val = -1;
  head->r = temp;
  temp->r = temp1;
  temp1->r = NULL;
}

void calllru()
{
  int flag = 0;
  int i;
  initalizelink();
  for (i = 0; i < ip; i++)
  {
    flag = 0;
    {
      link *temp = (link *)malloc(sizeof(link));
      temp->val = a[i];
      temp->r = NULL;
      cur = head;
      prev = head;

      while (cur != NULL)
      {
        if (cur->val == a[i])
        {
          flag = 1;
          if (cur != head)
          {
            prev->r = cur->r;
            cur->r = head;
            head = cur;
          }
        }
        prev = cur;
        cur = cur->r;
      }

      if (flag == 0)
      {
        cur = head;
        prev = head;
        while (cur->r != NULL)
        {
          prev = cur;
          cur = cur->r;
        }
        temp->r = head;
        head = temp;
        prev->r = NULL;
        pf++;
      }
    }
  }
}

void main()
{
  printf("Enter page table size and number of inputs\n");
  scanf("%d%d", &nf, &ip);
  a = (int *)malloc(sizeof(int) * ip);
  printf("Enter values\n");
  int i;
  for (i = 0; i < ip; i++)
  {
    scanf("%d", &a[i]);
  }
  printf("Enter choice 1.FIFO 2.LRU\n");
  scanf("%d", &ch);
  switch (ch)
  {
  case 1:
    callfifo();
    break;
  case 2:
    calllru();
    break;
  default:
    printf("invalid\n");
    break;
  }
  printf("Page faults: %d\n", pf);
}