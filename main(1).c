#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char name[]="books.bin";
char c;
typedef struct
{
    //int num;
    char name_author[30];
} author;
typedef struct
{
    int d,m,y;

} date;
typedef struct
{
    int isbn;
    char address[30];
    int c_author;//number of the author
    author author[30];
    int part;
    int copy;


} book ;
typedef struct
{
    int id;
    char name_student[30];
} student;
typedef struct
{
    student student;
    date borrow;
    date reset;
    int num_book;
    char name_book[30];


} borrow_book;
int file_ok(FILE*f)
{
    if(f==NULL)
    {
        perror("cant open the file....................!");
        exit(-1);
    }
}
int found(int num)
{
    book book;
    FILE *f=fopen(name,"rb");
    file_ok(f);
    while(fread(&book,sizeof(book),1,f))
    {
        if(book.isbn==num)
        {
            fclose(f);
            return -1;
        }

    }
    fclose(f);
    return 1;


}
void add(char *name_file)
{
    int i=0;
    int j;
    book book;
    FILE*fp=fopen(name_file,"wb");
    FILE*f=fopen(name,"ab");
    file_ok(f);
    file_ok(fp);

    do
    {

        printf("number of book:");
        scanf("%d",&book.isbn);
        if(found(book.isbn)==-1)
        {
            printf("this book is already exists :\n\n");
        }

    }
    while(found(book.isbn)==-1);

    printf("address of book:");
    fflush(stdin);
    scanf("%s",&book.address);
    printf("the number of author:\n");
    scanf("%d",&book.c_author);
    for(j=1; j<=book.c_author; j++)
    {
        printf("the counter of author (%d)",j);
        fflush(stdin);
        printf("name:");
        scanf("%s",&book.author[j].name_author);
    }
    printf("part of book:");
    scanf("%d",&book.part);
    printf("copy of book:");
    scanf("%d",&book.copy);

    fwrite(&book,sizeof(book),1,f);

    fwrite(&book,sizeof(book),1,fp);

fclose(f);
fclose(fp);
}
void dat(date date)
{
       do{
        printf("enter year: ");
        scanf("%d",&date.y);
        printf("enter month: ");
        scanf("%d",&date.m );
        printf("enter day: ");
        scanf("%d",&date.d );
   }while(!((date.y>0)&&(date.m>0&&date.m<=12)&&(date.d>0&&date.m<=30)));


}
void copy(char name_f1[],char name_f2[])
{
    book book;
    FILE *f=fopen(name_f1,"rb");
    FILE *temp=fopen(name_f2,"wb");
    while(fread(&book,sizeof(book),1,f))
    {
        fwrite(&book,sizeof(book),1,temp);
    }
    fclose(f);
    fclose(temp);
}

int compar_date(date e1,date e2)
{
if(e1.y==e2.y)
{
if(e1.m==e2.m)
    {
  return (e1.d>e2.d);

    }
return (e1.m>e2.m);
}
return (e1.y>e2.y);
}
void add_file_borrow(char *name_borrow,int num)
{
    FILE*bf=fopen(name_borrow,"rb");
    borrow_book borrow_book;
    book book;
    file_ok(bf);
    int i=0;
    student student;

    int m,k=0;
    while(fread(&borrow_book,sizeof(borrow_book),1,bf)>0)
    {
        if( num==student.id)
            ++i;
    }
    fclose(bf);
    if(i>=3)
        printf("cant borrow the book.....\n\n");
    else if(i==0)
    {
       printf("the student not found in  students file......\n\n");
       printf("please enter the id of book for borrow......\n");
        scanf("%d",&m);
        FILE*f=fopen(name,"rb");

        while(fread(&book,sizeof(book),1,f))
              {
                 if(m==book.isbn)
                    {
                    if(book.copy>0)
                       k=1;

                    }
              }
              fclose(f);
              if(!k)
              {
                  printf("............the book not found .........\n");
              }
      else{  FILE* std=fopen("student.bin","ab");
        f=fopen(name,"rb");
        bf=fopen(name_borrow,"ab");
        file_ok(bf);
        file_ok(std);
        file_ok(f);
        student.id=num;
        printf("%d\n",num);
        printf("name of student:");
        scanf("%s",&student.name_student);
        //strcpy(student->name_student,name_student);

       fwrite(&student,sizeof(student),1,std);

        borrow_book.student=student;
        printf("the date of borrow......\n");
        dat(borrow_book.borrow);
        printf("the date of reset......\n");
        dat(borrow_book.reset);
        fwrite(&borrow_book,sizeof(borrow_book),1,bf);
              fclose(f);
              f=fopen(name,"rb");
              char b[]="temp.bin";
              FILE *temp=fopen(b,"wb");
        while(fread(&book,sizeof(book),1,f))
              {
                if(m==book.isbn)
                   {
                    --book.copy;
    fwrite(&book,sizeof(book),1,temp);
                   }
                   else
    fwrite(&book,sizeof(book),1,temp);

              }
        fclose(std);
        fclose(bf);
        fclose(f);
        fclose(temp);
        copy(b,name);

    }}
    else if(i>0&&i<3)
    {
        bf=fopen(name_borrow,"rb");

        while(fread(&borrow_book,sizeof(borrow_book),1,bf))
            {

            }


}}
 int delt(char *name_borrow)
 {
  int ok=0;
  borrow_book borrow_book;
  FILE *bf=fopen(name_borrow,"rb");

  while(fread(&borrow_book,sizeof(borrow_book),1,bf))
  {

  }
 }
  void reruns(char*name,char *name_borrow)
  {
      int n,m;
      int ok=0;
      borrow_book borrow_book ;
      book book;
    printf("enter  the number of book that you want reruns:");
    scanf("%d",&n);
     printf("enter the number of student who you want reruns:");
     scanf("%d",&m);
     char name_temp[]="tem";
     FILE *f=fopen(name,"rb");
     FILE *bf=fopen(name_borrow,"rb");
     FILE *temp=fopen(name_temp,"wb");
     while(fread(&borrow_book,sizeof(borrow_book),1,bf))
     {
         if((n!=borrow_book.num_book&&m!=borrow_book.student.id&&!ok)||ok)

             fwrite(&borrow_book,sizeof(borrow_book),1,temp);
           else
            ok=1;
     }
     fclose(temp);
     fclose(bf);
     char name_t="t";
     FILE *t=fopen(name_t,"wb");
     copy(name_temp,name_borrow);
     while(fread(&book,sizeof(book),1,f))
     {
      if(n==book.isbn)
      {
         ++book.copy;
         fwrite(&book,sizeof(book),1,t) ;
      }
      else
    fwrite(&book,sizeof(book),1,t) ;

     }
     copy(name_t,name);

  }

  void display(char *name)
  {
      FILE *f=fopen()
  }
  void search(char *name)
  {
      FILE *
  }
  void display_author(char *name,char name_th)
  {
      int j;
      book book;
      FILE *f=fopen(name,"rb");
      while(fread(&book,sizeof(book),1,f))
      {
       if(strcmp(name_th,book.author)==0)
       {
          printf("%d",&book.isbn);
          for()
       }
      }
  }
int main()
{
    int i=0;
    int num;
    char name_file[30];
    printf("name  of file book..........\n");
    gets(name_file);
    add(name_file);
    char name_borrow[]="borrow.bin";
    char name_student[30];
    char name_th;
    //printf("please enter the student for borrow......\n");
    //scanf("%s",&name_student);
    printf("please enter number of student for borrow....\n");
    scanf("%d",&num);
    add_file_borrow(name_borrow,num);
    printf("please enter ");
    printf("please enter name of author who you want display activities..........\n");
    scanf("%s",&name_th);
    return 0;
}
