#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

typedef struct
             {char data;
              int weight;
              int parent,lchild,rchild;
             }huffnode,*hufftree; /*��̬��������洢�շ�����*/
typedef char **huffcode;
hufftree ht;
huffcode hc;
int N;
void savehufftree()
{FILE *fp;char choise;int i;
 fp=fopen("D:\\hfmtree.txt","r");
 if(fp!=NULL)
   {printf("\n\t���ļ��Ѵ��ڣ��Ƿ񸲸�(y/n):");
    getchar();
    scanf("%c",&choise);
    if(choise=='n'||choise=='N')  exit(1);
   }
 fclose(fp);
 fp=fopen("D:\\hfmtree.txt","wb");
 if(fp!=NULL)
       printf("\n\t%s�ļ��Ѵ���\n","D:\\hfmtree.txt");
 else  {
	printf("�����ļ�ʧ��.\n");
	exit(1);}
 for(i=1;i<2*N;i++)
   { fputc(ht[i].data,fp);
     fprintf(fp,"%4d,%4d,",ht[i].weight,ht[i].parent);
     fprintf(fp,"%4d,%4d;",ht[i].lchild,ht[i].rchild);
   }
 printf("\n\t�ɹ�д���ļ�D:\\hfmtree.txt\n");
 fclose(fp);
}

void output_save()
{FILE *fp;int i;
 fp=fopen("D:\\huffcode.txt","w+");
 printf("\n\t������������벢��ΪD:\\huffcode.txt\n");
for(i=1;i<=N;i++)
  {printf("%c",ht[i].data);
   fputc(ht[i].data,fp);
   fputc(':',fp);
   printf("\t");
   puts(hc[i]);
   fputs(hc[i],fp);
  }
fclose(fp);
}

int inithfmtree()
{int M,i,start,c,k,f;
 int l,r,m1,m2;
 char *cd;
 printf("Enter the number of characters:");
 scanf("%d",&N);
 M=2*N;
 ht=(hufftree)malloc(M*sizeof(huffnode));  /*0�ŵ�Ԫδ��*/
 for(i=1;i<=N;i++)
     { getchar();
       printf("\n�����%d��=>\n\t�ַ�:",i);
       scanf("%c",&ht[i].data);
       printf("\tȨֵ:");
       scanf("%d",&ht[i].weight);
       ht[i].parent=ht[i].lchild=ht[i].rchild=0;
     }
for(i=N+1;i<M;i++)
      {
	ht[i].weight=ht[i].parent=ht[i].lchild=ht[i].rchild=0;
	ht[i].data='0';
      }
 for(i=N+1;i<M;++i)   /*�����������*/
   { m1=m2=32767;
     l=r=0;
 /*��ht[1,2����i-1]��ѡ��parentΪ0��weight��С��������㣬����ŷֱ�Ϊl��r*/
     for(k=1;k<=i-1;k++)
        if(ht[k].parent==0)
	   if(ht[k].weight<m1)
	     { m2=m1;
	       r=l;
	       m1=ht[k].weight;
	       l=k;
	     }
	   else if(ht[k].weight<m2)
                {m2=ht[k].weight;
		 r=k;
                }
     ht[l].parent=i;ht[r].parent=i;
     ht[i].lchild=l;ht[i].rchild=r;
     ht[i].weight=ht[l].weight+ht[r].weight;
  }
 savehufftree();  /*�ļ������������*/
  /*��Ҷ����������ÿ���ַ��ĺշ�������  */
 hc=(huffcode)malloc((N+1)*sizeof(char *)); /*����N���ַ������ͷָ������*/
 cd=(char *)malloc(N*sizeof(char));
 cd[N-1]='\0';
 for(i=1;i<=N;++i)
     { start=N-1;
       for(c=i,f=ht[i].parent;f!=0;c=f,f=ht[f].parent)
           if(ht[f].lchild==c) cd[--start]='0';
           else cd[--start]='1';
           hc[i]=(char *)malloc((N-start)*sizeof(char));
	   strcpy(hc[i],&cd[start]);
     }
  free(cd);
  output_save();
}

int coding()
{FILE *fp1,*fp2;int i;char d;
 fp1=fopen("d:\\tobetran.txt","r");
 if(fp1==NULL) { printf("���ļ�������.");
		 return 0;
	       }
 fp2=fopen("D:\\codefile.txt","w+");
 printf("codes:(�Ѵ�Ϊ�ļ�D:\codefile.txt).\n");
 while(feof(fp1)==0)
  { d=fgetc(fp1);
   for(i=1;i<=N;i++)
   if(d==ht[i].data) { printf("%s",hc[i]);
		       fputs(hc[i],fp2);
		     }

  }
 fclose(fp1);
 fclose(fp2);
 }
int translating()
{FILE *fp1,*fp2;char d;int i;
 fp1=fopen("D:\\codefile.txt","r");
 fp2=fopen("D:\\textfile.txt","w+");
 for(i=1;i<2*N&&ht[i].parent!=0;i++);
 while(!feof(fp1))
 { d=fgetc(fp1);
   if(!ht[i].lchild&&!ht[i].rchild)
    { printf("%c",ht[i].data);
      fputc(ht[i].data,fp2);
      for(i=1;i<2*N&&ht[i].parent!=0;i++);
	if(i>=2*N) { printf("����!");
		     return 0;
		    }
    }
  if(d=='0'&&ht[i].lchild) i=ht[i].lchild;
  else if(d=='1'&&ht[i].rchild) i=ht[i].rchild;
  }
   fclose(fp1);
   fclose(fp2);
   }

void main()
{int choice;
 while(1)
  { printf("\n\t*******************************\n");
    printf("\t**1.��ʼ������ϵͳ\n");
    printf("\t**2.���ļ����б���.\n");
    printf("\t**3.���ļ���������.\n");
    printf("\t**4.�˳�.\n");
    printf("\t*******************************\n");
    printf("ѡ��(1-4):");
    scanf("%d",&choice);
    switch(choice)
    { case 1:inithfmtree();break;
      case 2:coding();break;
      case 3:translating();break;
      case 4:printf("ллʹ��!");exit(1);
      default:printf("�����������������!");
    }
  }
}
