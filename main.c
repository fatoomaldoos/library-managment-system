#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char dont_reset[]="dont_reuns";
char name[]="books";
char c;
char name_reuns[]="reruns";
int *j=0;
///=====================================
struct author
{
    char name_author[30];
};
///=====================================
struct date
{
    int d,m,y;

};
///=====================================
struct book
{
    int isbn;
    char address[30];
    int c_author;//number of the author
    struct author author[5];
    int part;
    int copy;

} ;
///=====================================
struct student
{
    int id;
    char name_student[30];
};
///=====================================
struct borrow_book
{
    struct student student;//تسجيلة الطالب
    struct date borrow;
    struct date reset;
    struct date never_reset;
    struct book book;
    int num_book;
    int n;
    int b[3];

};
///======================================
struct reuns//سنستخدمها بملف الكتب المعادة
{
    struct borrow_book b;//
    struct date rev;
};
///======================================
int file_ok(FILE*f)//
{
    if(f==NULL)
    {
        printf("cant open the file....................!");
        exit(-1);
    }
}
///===================================================================================
int found(int num)
{
    struct book book;
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
///====================================================================================
void add(char *name_file)
{
    int i=0;
    int j;
    struct book book;
    FILE*fp=fopen(name_file,"wb");
    FILE*f=fopen(name,"ab");
    // file_ok(f);
    //file_ok(fp);

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

        printf("name:");
        fflush(stdin);
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
///====================================================================================
struct date dat(struct date date)
{
    do
    {
        printf("enter year: ");
        scanf("%d",&date.y);
        printf("enter month: ");
        scanf("%d",&date.m );
        printf("enter day: ");
        scanf("%d",&date.d );
    }
    while(!((date.y>0)&&(date.m>0&&date.m<=12)&&(date.d>0&&date.m<=30)));
    return  date;

}
///====================================================================================
/*void copy(char name_f1[],char name_f2[])
{
    struct book book;
    FILE *f=fopen(name_f1,"rb");
    FILE *temp=fopen(name_f2,"wb");
    while(fread(&book,sizeof(book),1,f))
    {
        fwrite(&book,sizeof(book),1,temp);
    }
    fclose(f);
    fclose(temp);
}*/
///===================================================================================
int compar_date(struct date e1,struct date e2)
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
///====================================================================================
void add_file_borrow()
{
    char name_student[]="file_student";
    char file_name[]="name_book";
    char name_borrow[]="borrow_book";
    FILE*bf=fopen(name_borrow,"ab");
    FILE*s=fopen(name_student,"rb");
    FILE*f=fopen(file_name,"rb");
    struct borrow_book borrow_book;
    struct student student;
    struct book book;
    printf("please enter the name of student:");
    fflush(stdin);
    gets(borrow_book.student.name_student);
    fflush(stdin);
    printf("please enter the number of student:");
    scanf("%d",&borrow_book.student.id);
    int t=0;
    while(fread(&student,sizeof(student),1,s))
    {
        if(borrow_book.student.id==student.id)
            t=1;
    }
    fclose(s);
    if(t==0)
    {
        s=fopen(name_student,"ab");
        fwrite(&borrow_book.student,sizeof(student),1,s);
        fclose(s);
    }
    printf("please enter the amount of book that you want to borrow:");
    scanf("%d",&borrow_book.n);
    int i,j=0;
    char book_name[50];
    for(i=0; i<borrow_book.n; i++)
    {
point:

        printf("please enter the name of book:");
        gets(book.address);
        while(fread(&book,sizeof(book),1,f))

            if(strcmp(book_name,book.address)==0)
            {
                borrow_book.book=book;
                printf("the date of borrow......\n");
                dat(borrow_book.borrow);
                printf("the date of reset......\n");
                dat(borrow_book.reset);
            }



            else
                printf("the book not found try again:");
        goto point;
    }
    fwrite(&borrow_book,sizeof(borrow_book),1,bf);
    fclose(bf);
    fclose(f);
    fclose(s);



}
/*
void add_file_borrow(char *name_borrow,int num)
{
    FILE*bf=fopen(name_borrow,"rb");
    struct borrow_book borrow_book;
    struct book book;
    file_ok(bf);
    int b,i=0;
    struct student student;

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
        printf("the student isnt exsist in  students file......\n\n");
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
        else
        {
            FILE* std=fopen("student.bin","ab");
            f=fopen(name,"rb");
            bf=fopen(name_borrow,"ab");
            file_ok(bf);
            file_ok(std);
            file_ok(f);
            student.id=num;
            printf("name of student:");
            fflush(stdin);
            scanf("%s",&student.name_student);
            fwrite(&student,sizeof(student),1,std);

            borrow_book.student=student;
            borrow_book.num_book=m;

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

        }
    }
    /*
    else if(i>0&&i<3)
    {
        int b=0;
        int l;
        struct   reuns reuns;
        char name_temp;
        int ret;
        bf=fopen(name_borrow,"rb");
        FILE *t=fopen(name_temp,"rb");
        printf("please enter the id of book for borrow......\n");
        scanf("%d",&l);
        FILE*f=fopen(name,"rb");

        while(fread(&book,sizeof(book),1,f))
        {
            if(l==book.isbn)
            {
                if(book.copy>0)
                    b=1;

            }
        }
        fclose(f);
        if(!b)
        {
            printf("............the book not found .........\n");
        }
        else
        {
            FILE *fr=fopen(name_reuns,"rb");
            while(fread(&reuns,sizeof(reuns),1,fr))
            {
                if(num==reuns.b.student.id)
                {
                    if(ret=compar_date(reuns.rev,reuns.b.reset)==1)
                    {

                    }

                }
            }
        }
    }*/


///====================================================================================
void deleat_borrow_book(struct student student)
{
    char temp[]="temp_file";
    struct borrow_book borrow_book;
    char name_borrow[]="borrow_book";
    FILE*bf=fopen(name_borrow,"rb");
    FILE*t=fopen(temp,"wb");
    while(fread(&borrow_book,sizeof(borrow_book),1,bf))
    {
        if(student.id==borrow_book.student.id)
            continue;
        fwrite(&borrow_book,sizeof(borrow_book),1,t);
    }
    fclose(bf);
    fclose(t);
    t=fopen(temp,"rb");
    bf=fopen(name_borrow,"wb");

    while(fread(&borrow_book,sizeof(borrow_book),1,t))
        fwrite(&borrow_book,sizeof(borrow_book),1,bf);
    fclose(t);
    fclose(bf);

}
void retreun_book()
{
    char name_borrow[]="borrow_book";
    FILE*bf=fopen(name_borrow,"rb");
    char student_name[50];
    printf("please enter the student name:");
    fflush(stdin);
    gets(student_name);
    struct borrow_book borrow_book;
    while(fread(&borrow_book,sizeof(borrow_book),1,bf))
    {
        if((strcmp(student_name,borrow_book.student.name_student))==0)
        {
            printf("enter the book name:");
            char book_name[50];
            fflush(stdin);
            gets(book_name);
            int t=0,i,j;
            for(i=0; i<borrow_book.book.copy; i++)
            {
                if(strcmp(book_name,borrow_book.book.address)==0)
                    t=1;
                for(j=0; j<borrow_book.book.copy; j++)
                    borrow_book.book.copy--;
                break;
            }
        }
        fclose(bf);

    }
    if(borrow_book.book.copy==0)
        deleat_borrow_book(borrow_book.student);
    fclose(bf);



}

///=================================================================================
void display(char *name)///عرض معلوات الكتب الموجودة بالمكتبة
{
    FILE *f=fopen(name,"rb");
    file_ok(f);
    int i;
    struct book book;
    printf("number\t\taddress\t\tcopies\t\tpart\t\tauthor\n\n");

    while(fread(&book,sizeof(book),1,f))
    {
        printf("%6d\t\t",book.isbn);
        printf("%7s\t\t",book.address);
        printf("%5d\t\t",book.copy);
        printf("%4d\t\t",book.part);
        for(i=1; i<=book.c_author; i++)
        {
            printf("%6s\n",book.author[i].name_author);
            printf("\t\t\t\t\t\t\t\t");
        }
        printf("\n");
    }
}
///=================================================================================
void search(char *name,char address[])///البحث عن كتاب حسب العنوان
{
    int j,test=0;
    FILE *f=fopen(name,"rb");
    struct book book;

    while(fread(&book,sizeof(book),1,f))
    {
        if(strcmp(book.address,address)==0)
        {
            test=1;
            printf("%6d\t\t",book.isbn);
            printf("%7s\t\t",book.address);
            printf("%5d\t\t",book.copy);
            printf("%4d\t\t",book.part);
            for(j=1; j<=book.c_author; j++)
            {
                printf("%6s\n",book.author[j].name_author);
                printf("\t\t\t\t\t\t\t\t");
            }
            printf("\n");
        }

    }
    fclose(f);
    if(!test)
    {
        printf("the book isnt exsist");
    }
}
fclose(f);
///==================================================================================
void display_author(char *name,char *name_th)///عرض جميع الكتب لمؤلف معين
{
    int j;
    int test=0;
    struct book book;
    FILE *f=fopen(name,"rb");
    while(fread(&book,sizeof(book),1,f))
    {

        {
            for(j=1; j<=book.c_author; j++)
            {

                if(strcmp(name_th,book.author[j].name_author)==0)
                {
                    test=1;
                    printf("%6d\t\t",book.isbn);
                    printf("%7s\t\t",book.address);
                    printf("%5d\t\t",book.copy);
                    printf("%4d\t\t",book.part);
                    for(j=1; j<=book.c_author; j++)
                    {
                        printf("%6s\n",book.author[j].name_author);
                        printf("\t\t\t\t\t\t\t\t");
                    }
                    printf("\n");
                }
            }
        }
    }
    if(!test)
    {
        printf("the author not exists....\n");
        printf("...........................\n");

    }
}
///==================================================================================

void display_std(int num )///عرض الكتب المستعارة من قبل طالب محدد ومازالت بحوزته
{
    char name_borrow[]="file_borrow";
    // FILE *f;

    int i;
    int test=0;
    struct book book;
    char name_file[]="name_book";
    struct borrow_book borrow_book;
    FILE*bf=fopen(name_borrow,"rb");
    while(fread(&borrow_book,sizeof(borrow_book),1,bf))
    {
        if(num==borrow_book.student.id)
        {
            test=1;
            FILE*f=fopen(name_file,"rb");
            while(fread(&book,sizeof(book),1,f))
            {
                if(borrow_book.num_book==book.isbn)
                {
                    printf("the number of book:%d\n",book.isbn);
                    printf("the address of book:%s\n ",book.address);
                    printf("the part:%d\n",book.part);
                    for(i=1; i<=book.c_author; i++)
                        printf("the name of author:%s\n",book.author[i].name_author);
                }
            }
            fclose(f);

        }
    }
    fclose(bf);

    if(!test)
    {
        printf("the student not exists......\n");

    }
}

///==================================================================================

void display_book()///عرض الكتل الواجب اعادتها ولم تعاد بالتاريخ المحدد
{
    char name_borrow[]="file_borrow";
    struct borrow_book borrow_book;
    struct reuns reuns;
    int ret ,i;
    struct book book;
    FILE*bf=fopen(name_borrow,"rb");

    while(&borrow_book,sizeof(borrow_book),1,bf)
    {
        if(ret=compar_date(reuns.rev,reuns.b.reset)==1)
        {
            printf("the number of book:%d\n",book.isbn);
            printf("the address of book:%s\n ",book.address);
            printf("the part:%d\n",book.part);
            for( i=1; i<=book.c_author; i++)
                printf("the name of author:%s\n",book.author[i].name_author);
        }

    }
    fclose(bf);
}
///====================================================================================
/*void borrow_opreation(char *name_borrow)///عمليات الاستعارة مرتبة حسب التاريخ
{
    int i,j;
    struct borrow_book borrow_book;
    struct borrow_book b[100];
    //b[i]=NULL;
    FILE*bf=fopen(name_borrow,"rb");
    printf("enter date for comparsing:");
    dat( b[i].borrow );
    while(fread(&borrow_book,sizeof(borrow_book),1,bf))
    if((borrow_book.borrow.y==b[i].borrow.y)&&(borrow_book.borrow.m==b[i].borrow.m))
    {

        for(i=0; i<     ; i++)
            for(j=i+1; j<b[j]     ; j++)
                if(b[i]>b[j])
                {
                    a=b[i];
                    b[i]=b[j];
                    b[j]=a;
                }
                for(i=0;i<b[i];i++)
                {
                    if(b[i]!=NULL)
                    {
                       printf("num of book:%d",b[i].num_book);
                       printf("the number of student:%d",b[i].student.id);
                       printf("the name of student:%s",b[i].student.name_student);
                       printf("the date of borrow:%d\%d\%d",b[i].borrow.d,b[i].borrow.m,b[i].borrow.y);
                       printf("the date of reset:%d\%d\%d"b[i].reset.d,b[i].reset.m,b[i].reset.y);
                    }

                }


    }
}*/
/*
void daisplay_book_mor(char *name_borrow)
{
    int i,j;
    struct borrow_book borrow_book;
    struct borrow_book b[100];

}*/


///===================================================================================
int main()
{
    system("COLOR 70");


    int i=0;
    int num;
    char name_th[50];
    char name_file[30];
    char name_borrow[]="borrow.bin";
    char name_student[30];
    char address[50];
    do
    {


        printf("\nenter 1 to add new book :\n\n");
        printf("enter 2 to borrow a book:\n\n");
        printf("enter 3 to dasplay the book that exsist in the library:\n\n");
        printf("enter 4 to display the book that belong to a particular author:\n\n");
        printf("enter 5 to display the book that didnt reset in the date:\n\n");
        printf("enter 6 to search about book depend on the number of book:\n\n");
        printf("enter 7 to reruns a book to the library:\n\n");
        printf("enter 8 to display the book that borroed by student and didnt reset:\n\n");

        int x,num;
        printf("please enter the number of x:");
        scanf("%d",&x);
        switch(x)
        {


        case 1:/*printf("please enter the name of book:");
    gets(name_file);*/
            add(name_file);
            break;

        case 2:
            printf("please enter number of student for borrow....\n");
            scanf("%d",&num);
            add_file_borrow(name_borrow,num);
            break;
        case 3:
            display(name);

            break;

        case 4:

            printf("please enter name of author who you want display activities..........\n");
            printf("...........................\n");
            fflush(stdin);
            gets(name_th);
            printf("...........................\n");
            display_author(name,name_th);
            break;
        case 5:

            display_book();
            break;
        case 6:
            printf("please enter the address of book for search:");
            fflush(stdin);
            gets(address);
            search(name,address);
            break;
        case 7:
            retreun_book();
            break;
        case 8:
            printf("please enter the number of student:");
            scanf("%d",&num);
            display_std(num);
            break;
        case 9:
            exit(1);
            break;
        }
    }
    while(1);
    return 0;
}
