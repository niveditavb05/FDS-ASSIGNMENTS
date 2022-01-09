#include <stdio.h>
struct student
{
  char name[50];
  int roll;
  char div[10];

};
void accept(struct student s[20],int n)
{
  printf("\n***ENTER STUDENT'S DETAILS***\n");
   for(int i=0;i<n;i++)
   {
     printf("Enter name,roll no and division :");
     scanf("%s%d%s",s[i].name,&s[i].roll,s[i].div);
   }
}
void append_file(struct student s[20],int n)
{
    FILE *fp;
    fp = fopen("stud_info.txt","a");
    if(fp==NULL)
    {
        printf("***Error in File***\n");
    }
    else{
        for(int i=0;i<n;i++)
        {
            fprintf(fp,"%s  %d  %s",s[i].name,s[i].roll,s[i].div);
            fputs("\n",fp);
        }
    }
     printf("\n***file created***\n");
    fclose(fp);
}
void display(struct student s[20])
{
    FILE *fp;
    fp = fopen("stud_info.txt","r");
    struct student s1;

    if(fp==NULL)
    {
        printf("***Error in File***\n");
    }
    else
    {
        while(fscanf(fp,"%s%d%s",s1.name,&s1.roll,s1.div)!=EOF)
        {

         {
             printf("Name  ROLL   DIV \n");
             printf("%s   %d   %s\n",s1.name,s1.roll,s1.div);
         }
    }
     fclose(fp);
}
}

void par_data(struct student s[20])
{
     int r;
    printf("Enter the roll no. to search :\n");
    scanf("%d",&r);

    FILE *fp;
    fp = fopen("stud_info.txt","r");
    struct student s1;

    if(fp==NULL)
    {
        printf("***Error in File***\n");
    }
    else
    {
        while(fscanf(fp,"%s%d%s",s1.name,&s1.roll,s1.div)!=EOF)
        {
         if(r==s1.roll)
         {
             printf("Name  ROLL   DIV \n");
             printf("%s   %d   %s\n",s1.name,s1.roll,s1.div);
         }
        }
    }
    printf("\n***Info deleted***\n");
     fclose(fp);
}
void deletef(struct student s[20],int n)
{
  int roll_no;
  printf("Enter the roll number you want to delete\n");
  scanf("%d",&roll_no);
   FILE *fp;
   fp = fopen("stud_info.txt","r");

    if(fp==NULL)
    {
        printf("***Error in File***\n");
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            scanf(fp,"%s%d%s",s[i].name,s[i].roll,s[i].div);
        }
    }
     fclose(fp);
    fp = fopen("stud_info.txt","w");
    if(fp==NULL)
    {
        printf("***Error in File***\n");
    }
    else{
        for(int i=0;i<n;i++)
        {
            if(roll_no!=s[i].roll){
            fprintf(fp,"%s  %d  %s",s[i].name,s[i].roll,s[i].div);
            fputs("\n",fp);
            }
        }
    }
  fclose(fp);

}
int main()
{
   struct student s[20];
   int n,ch;
   printf("Enter total number of students \n");
   scanf("%d",&n);
   accept(s,n);
do{
   printf("0.exit \n1.Append in file \n2.Display the file \n3.Display particular data \n4.delete info of particular one\n");

   printf("**Enter your choice**");
   scanf("%d",&ch);

   switch(ch)
   {
   case 1:
   append_file(s,n);
    break;

   case 2:
    display(s);
    break;

   case 3:
    par_data(s);
    break;

   case 4:
    deletef(s,n);
    break;

   }
}while(ch!=0);
}
