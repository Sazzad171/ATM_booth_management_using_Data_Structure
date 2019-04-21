#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>

struct node
{
    char fname[20];
    char lname[20];
    char phn[11];
    int acno;
    int pswrd[4];
    int rpswrd[4];
    double acb;
    struct node *next;
}*head;


void newac()
{
    struct node *newnode,*current;
    int a,i;
    char ch;
    newnode=(struct node*)malloc(sizeof(struct node));
    current=head;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    printf("Enter user first Name:");
    scanf("%s",&newnode->fname);
    printf("Enter user last Name:");
    scanf("%s",&newnode->lname);
    printf("Enter user's phone no.:");
    scanf("%s",&newnode->phn);
    printf("Enter user's account no.:");
    scanf("%d",&newnode->acno);
    printf("Enter user's first account balance:");
    scanf("%lf",&newnode->acb);
    printf("Enter user's PIN <any 4 digit>:");
    for(i=0; i<4; i++)
    {
        ch = getch();
        newnode->pswrd[i] = ch;
        ch = '*' ;
        printf("%c",ch);
    }
    printf("\nRe-type PIN:");
    for(i=0; i<4; i++)
    {
        ch = getch();
        newnode->rpswrd[i] = ch;
        ch = '*' ;
        printf("%c",ch);
    }
    //scanf("%s",&newnode->rpswrd);
    a=strcmp(newnode->pswrd,newnode->rpswrd);
    while(a!=0)
    {
        printf("Re-type PIN:");
        scanf("%s",&newnode->rpswrd);
        newnode->rpswrd[4]=newnode->rpswrd[4];
    }
    newnode->next=NULL;
    current->next=newnode;
}

void tm()
{
    time_t now;
    now = time(NULL);
    struct tm tm = *localtime(&now);
    printf(" Date: %d-%d-%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    printf(" Time: %d:%d:%d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
}

void editac()
{
    struct node *current;
    int item,a=0,b,ed;
    printf("Enter an a/c no. what you want to edit:");
    scanf("%d",&item);
    current=head;
    while(current!=NULL)
    {
        if(current->acno==item)
        {
            printf("\nWhat you want to edit?\nPress -->'1' User first name edit.\nPress -->'2' User last name edit.\nPress -->'3' User phone no. edit.\nPress -->'4' User a/c no. edit.\n");
            scanf("%d",&ed);
            switch(ed)
            {
            case 1:
                printf("Enter user new first Name:");
                scanf("%s",&current->fname);
                break;
            case 2:
                printf("Enter user new last Name:");
                scanf("%s",&current->lname);
                break;
            case 3:
                printf("Enter user's new phone no.:");
                scanf("%s",&current->phn);
                break;
            case 4:
                printf("Enter user's new account no.:");
                scanf("%d",&current->acno);
                break;
            }

            a=1;
            break;
        }
        current=current->next;
    }
    if(a==0)
    {
        printf("Does not match A/C\n");
    }
}



void acdelete()
{
    struct node *current,*prev;
    current=head;
    int acn;
    printf("Enter the a/c no. you want to delete:");
    scanf("%d",&acn);
    if(head->acno==acn)
    {
        head=current;
        head=head->next;
        free(current);
    }
    else
    {
        while(current!=NULL)
        {

            if(current->acno==acn)
            {
                prev->next=current->next;
                free(current);
                break;
            }
            prev=current;
            current=current->next;
        }
    }
}


void search()
{
    struct node *current;
    int item,a=0;
    printf("Enter an a/c no. what you want to searching:");
    scanf("%d",&item);
    current=head;
    while(current!=NULL)
    {
        if(current->acno==item)
        {
            printf("\nUser name: %s %s\n",current->fname,current->lname);
            printf("User phone no: %s\n",current->phn);
            printf("User a/c no: %d\n",current->acno);
            printf("User a/c balance: %.2lf\n",current->acb);
            a=1;
            break;
        }
        current=current->next;
    }
    if(a==0)
    {
        printf("Does not match A/C\n");
    }
}

void dispaly()
{
    struct node *current;
    current=head;
    while(current!=NULL)
    {
        printf("\nUser name: %s %s\n",current->fname,current->lname);
        printf("User phone no: %s\n",current->phn);
        printf("User a/c no: %d\n",current->acno);
        printf("User a/c balance: %.2lf\n",current->acb);
        current=current->next;
    }
}



void transfer(int ac,int mn)
{
    struct node *currnt;
    currnt=head;
    while(currnt!=NULL)
    {
        if(currnt->acno==ac)
        {
            currnt->acb=currnt->acb+mn;
            break;
        }
        currnt=currnt->next;
    }
}


void fst()
{
    printf("********\tWELCOME TO DAFFODIL BANK BD Ltd.\t********\n\n\t\tFirst you need to LOG IN\n\n");
    char id[10]="Admin",usr[10],ps[4]="1010",pw[4];
    int cm,cmp,vr;
    char pasword[10],usrname[10], ch;
    int i;
    struct node *current,*newnode;
    char fnam[20],lnam[20],ph[11];


    head=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("Unable to allocate memory\n");
    }
    else
    {
        char fnam[]="Tania";
        char lnam[]="khatun";
        char ph[]="01685069742";
        char ps[]="2020";
        strcpy(head->fname,fnam);
        strcpy(head->lname,lnam);
        strcpy(head->phn,ph);
        head->acno=1001;
        head->acb=0.0;
        strcpy(head->pswrd,ps);

        head->next=NULL;
        current=head;

        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("Unable to allocate memory\n");
            //break;
        }
        else
        {
            char fnam[]="Sazzad";
            char lnam[]="bin_jafor";
            char ph[]="01679383667";
            char ps[]="3030";
            strcpy(newnode->fname,fnam);
            strcpy(newnode->lname,lnam);
            strcpy(newnode->phn,ph);
            newnode->acno=1002;
            newnode->acb=0.0;
            strcpy(newnode->pswrd,ps);

            newnode->next=NULL;
            current->next=newnode;
            current=current->next;
        }
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("Unable to allocate memory\n");
            //break;
        }
        else
        {
            char fnam[]="Al";
            char lnam[]="Amin";
            char ph[]="01737154982";
            char ps[]="4040";
            strcpy(newnode->fname,fnam);
            strcpy(newnode->lname,lnam);
            strcpy(newnode->phn,ph);
            newnode->acno=1003;
            newnode->acb=0.0;
            strcpy(newnode->pswrd,ps);

            newnode->next=NULL;
            current->next=newnode;
            current=current->next;
        }
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("Unable to allocate memory\n");
            //break;
        }
        else
        {
            char fnam[]="Mohammad";
            char lnam[]="Sohel";
            char ph[]="01684546434";
            char ps[]="6374";
            strcpy(newnode->fname,fnam);
            strcpy(newnode->lname,lnam);
            strcpy(newnode->phn,ph);
            newnode->acno=1004;
            newnode->acb=0.0;
            strcpy(newnode->pswrd,ps);

            newnode->next=NULL;
            current->next=newnode;
            current=current->next;
        }

    }


    printf("Press '0' -->Log in as Administration \nPress '1' -->Log in as Customer\n\n");
    int rg;
    scanf("%d",&rg);
    switch(rg)
    {



    case 1:
        vr=1;
        int more2,a;
        char paswrd[10], ch;
        int i,acn,cs;
        printf("\nEnter A/C no. : ");
        scanf("%d",&acn);
        printf("Enter PIN: ");

        for(i=0; i<4; i++)
        {
            ch = getch();
            paswrd[i] = ch;
            ch = '*' ;
            printf("%c",ch);
        }
        do
        {
            int a=0,wd,dp,b=0,ac,mn;
            char nps[4],op[4],npsn[4],p[4];
            current=head;

            while(current!=NULL)
            {
                if(acn==current->acno)
                {
                    /*a=strcmp(current->pswrd,paswrd);
                    if(a==0)
                    {*/
                    printf("\nEnter your choice\n\nPress '1'--> A/C balance inquiry\nPress '2'--> balance withdraw\nPress '3'--> deposite money\nPress '4' --> change PIN\nPress '5' --> Transfer money\nPress '6' --> Logout\n\n");
                    scanf("%d",&cs);
                    switch(cs)
                    {
                    case 1:
                        printf("Your a/c no: %d\n",current->acno);
                        printf("Your a/c balance: %.2lf\n",current->acb);
                        printf("\nDAFFODIL BANK Ltd.\n\n");
                        break;
                    case 2:
                        if(b<=5)
                        {
                            printf("Enter the amount what you want withdraw <minimum 500,maximum 20000> : ");
                            scanf("%d",&wd);
                            if(wd>=500&&wd<=20000&&wd%500==0&&current->acb-100>=wd)
                            {
                                current->acb=current->acb-wd;
                                printf("\n Your a/c no: %d\n",current->acno);
                                printf(" You withdraw Tk: %d\n",wd);
                                printf(" Your current a/c balance: %.2lf\n",current->acb);
                                tm();
                                printf("\n\tDAFFODIL BANK Ltd.\n\n");
                            }
                            else
                            {
                                printf("\nWrong input\n");
                            }
                            b++;
                        }
                        else
                        {
                            printf("\nYou already withdraw money at 5 times\n");
                        }
                        break;
                    case 3:
                        printf("Enter the amount what you want deposit <minimum 500> :");
                        scanf("%d",&dp);
                        current->acb=current->acb+dp;
                        printf("\n Your a/c no: %d\n",current->acno);
                        printf(" Your deposited Tk: %d\n",dp);
                        printf(" Your current a/c balance: %.2lf\n",current->acb);
                        tm();
                        printf("\n\tDAFFODIL BANK Ltd.\n\n");
                        break;
                    case 4:
                        printf("Enter old PIN : ");
                        for(i=0; i<4; i++)
                        {
                            ch = getch();
                            op[i] = ch;
                            ch = '*' ;
                            printf("%c",ch);
                        }
                        printf("\nEnter new PIN:");
                        for(i=0; i<4; i++)
                        {
                            ch = getch();
                            nps[i] = ch;
                            ch = '*' ;
                            printf("%c",ch);
                        }
                        printf("\nRe-type new PIN:");
                        for(i=0; i<4; i++)
                        {
                            ch = getch();
                            npsn[i] = ch;
                            ch = '*' ;
                            printf("%c",ch);
                        }
                        if(nps[0]==npsn[0]&&nps[1]==npsn[1]&&nps[2]==npsn[2]&&nps[3]==npsn[3])
                        {
                            strcpy(current->pswrd,nps);
                            printf("\nPassword changed succesfully\n");
                        }
                        else
                        {
                            printf("\nDo not match password\n");
                        }

                        break;
                    case 6:
                        lgot();
                        break;
                    case 5:
                        printf("\nEnter A/C no. where you want to transfer money : ");
                        scanf("%d",&ac);
                        printf("\nEnter amount : ");
                        scanf("%d",&mn);
                        if(mn>=500&&mn%500==0&&current->acb-100>=mn)
                        {
                            current->acb=current->acb-mn;
                            printf("\n Your a/c no: %d\n",current->acno);
                            printf(" You transfered Tk: %d\n",mn);
                            printf(" Your current a/c balance: %.2lf\n",current->acb);
                            tm();
                            printf("\n\tDAFFODIL BANK Ltd.\n\n");
                            transfer(ac,mn);
                        }
                        else
                        {
                            printf("\nWrong input\n");
                        }
                        break;

                    }

                    /* }

                     else
                     {
                         printf("\n\nWrong PIN\n");
                         break;
                     }*/

                    a=1;
                }
                current=current->next;
            }
            if(a==0)
            {
                printf("\nDo not match\n");
            }
            printf("\nAre you want to do anymore operation?if want press -->'1':");
            scanf("%d",&more2);
        }

        while(more2==1);
        break;




    case 0:
        vr=0;

        printf("\nEnter admin name: ");
        scanf("%s",&usrname);
        printf("Enter password: ");

        for(i=0; i<4; i++)
        {
            ch = getch();
            pasword[i] = ch;
            ch = '*' ;
            printf("%c",ch);
        }
        cm=strcmp(id,usrname);
        if(cm==0&&ps[0]==pasword[0]&&ps[1]==pasword[1]&&ps[2]==pasword[2]&&ps[3]==pasword[3])
        {
            int more;
            do
            {
                int slct;
                char psw[10],pswd[10];
                printf("\nSelect what you want to do.\n\nPress '1' -->Open new account.\nPress '2' -->Edit any a/c information.\nPress '3' -->Delete any account.\nPress '4' -->Search any account.\nPress '5' -->Display all account information.\nPress '6' -->change Admin password.\nPress '7' -->Logout.\n");
                scanf("%d",&slct);
                switch(slct)
                {
                case 1:
                    newac();
                    break;
                case 2:
                    editac();
                    break;
                case 3:
                    acdelete();
                    break;
                case 4:
                    search();
                    break;
                case 5:
                    dispaly();
                    break;
                case 7:
                    lgot();
                    break;
                case 6:
                    printf("\nEnter old password:");
                    for(i=0; i<4; i++)
                    {
                        ch = getch();
                        psw[i] = ch;
                        ch = '*' ;
                        printf("%c",ch);
                    }
                    if(ps[0]==psw[0]&&ps[1]==psw[1]&&ps[2]==psw[2]&&ps[3]==psw[3])
                    {
                        printf("\nEnter new password:");
                        for(i=0; i<4; i++)
                        {
                            ch = getch();
                            psw[i] = ch;
                            ch = '*' ;
                            printf("%c",ch);
                        }
                        printf("\nRe-type new password:");
                        for(i=0; i<4; i++)
                        {
                            ch = getch();
                            pswd[i] = ch;
                            ch = '*' ;
                            printf("%c",ch);
                        }
                        if(pswd[0]==psw[0]&&pswd[1]==psw[1]&&pswd[2]==psw[2]&&pswd[3]==psw[3])
                        {
                            ps[4]=psw[4];
                            printf("\nPassword changed succesfully\n");
                        }
                        else
                        {
                            printf("\nDo not match password\n");
                        }
                    }

                    else
                    {
                        printf("\nWrong password\n");
                    }
                    break;
                }
                printf("\nAre you want to do anymore operation?if want press -->'1':");
                scanf("%d",&more);
            }

            while(more==1);

        }
        else
        {
            printf("\nWrong username or password\n");
        }
        break;
    default:
        printf("\nWrong press\n");
        break;
    }
}


void lgot()
{
    while(1)
    {
        printf("********\tWELCOME TO DAFFODIL BANK BD Ltd.\t********\n\n\t\tFirst you need to LOG IN\n\n");
        char id[10]="Admin",usr[10],ps[4]="1010",pw[4];
        int cm,cmp,vr;
        char pasword[10],usrname[10], ch;
        int i;
        struct node *current,*newnode;
        char fnam[20],lnam[20],ph[11];

        printf("Press '0' -->Log in as Administration \nPress '1' -->Log in as Customer\n\n");
        int rg;
        scanf("%d",&rg);
        switch(rg)
        {



        case 1:
            vr=1;
            int more2,a;
            char paswrd[10], ch;
            int i,acn,cs;
            printf("\nEnter A/C no. : ");
            scanf("%d",&acn);
            printf("Enter PIN: ");

            for(i=0; i<4; i++)
            {
                ch = getch();
                paswrd[i] = ch;
                ch = '*' ;
                printf("%c",ch);
            }
            do
            {
                int a=0,wd,dp,b=0,ac,mn;
                char nps[4],op[4],npsn[4],p[4];
                current=head;

                while(current!=NULL)
                {
                    if(acn==current->acno)
                    {
                        /*a=strcmp(current->pswrd,paswrd);
                        if(a==0)
                        {*/
                        printf("\nEnter your choice\n\nPress '1'--> A/C balance inquiry\nPress '2'--> balance withdraw\nPress '3'--> deposite money\nPress '4' --> change PIN\nPress '5' --> Transfer money\nPress '6' --> Logout\n\n");
                        scanf("%d",&cs);
                        switch(cs)
                        {
                        case 1:
                            printf("Your a/c no: %d\n",current->acno);
                            printf("Your a/c balance: %.2lf\n",current->acb);
                            printf("\nDAFFODIL BANK Ltd.\n\n");
                            break;
                        case 2:
                            if(b<=5)
                            {
                                printf("Enter the amount what you want withdraw <minimum 500,maximum 20000> : ");
                                scanf("%d",&wd);
                                if(wd>=500&&wd<=20000&&wd%500==0&&current->acb-100>=wd)
                                {
                                    current->acb=current->acb-wd;
                                    printf("\n Your a/c no: %d\n",current->acno);
                                    printf(" You withdraw Tk: %d\n",wd);
                                    printf(" Your current a/c balance: %.2lf\n",current->acb);
                                    tm();
                                    printf("\n\tDAFFODIL BANK Ltd.\n\n");
                                }
                                else
                                {
                                    printf("\nWrong input\n");
                                }
                                b++;
                            }
                            else
                            {
                                printf("\nYou already withdraw money at 5 times\n");
                            }
                            break;
                        case 3:
                            printf("Enter the amount what you want deposit <minimum 500> :");
                            scanf("%d",&dp);
                            current->acb=current->acb+dp;
                            printf("\n Your a/c no: %d\n",current->acno);
                            printf(" Your deposited Tk: %d\n",dp);
                            printf(" Your current a/c balance: %.2lf\n",current->acb);
                            tm();
                            printf("\n\tDAFFODIL BANK Ltd.\n\n");
                            break;
                        case 4:
                            printf("Enter old PIN : ");
                            for(i=0; i<4; i++)
                            {
                                ch = getch();
                                op[i] = ch;
                                ch = '*' ;
                                printf("%c",ch);
                            }
                            printf("\nEnter new PIN:");
                            for(i=0; i<4; i++)
                            {
                                ch = getch();
                                nps[i] = ch;
                                ch = '*' ;
                                printf("%c",ch);
                            }
                            printf("\nRe-type new PIN:");
                            for(i=0; i<4; i++)
                            {
                                ch = getch();
                                npsn[i] = ch;
                                ch = '*' ;
                                printf("%c",ch);
                            }
                            if(nps[0]==npsn[0]&&nps[1]==npsn[1]&&nps[2]==npsn[2]&&nps[3]==npsn[3])
                            {
                                strcpy(current->pswrd,nps);
                                printf("\nPassword changed succesfully\n");
                            }
                            else
                            {
                                printf("\nDo not match password\n");
                            }

                            break;
                        case 6:
                            lgot();
                            break;
                        case 5:
                            printf("\nEnter A/C no. where you want to transfer money : ");
                            scanf("%d",&ac);
                            printf("\nEnter amount : ");
                            scanf("%d",&mn);
                            if(mn>=500&&mn%500==0&&current->acb-100>=mn)
                            {
                                current->acb=current->acb-mn;
                                printf("\n Your a/c no: %d\n",current->acno);
                                printf(" You transfered Tk: %d\n",mn);
                                printf(" Your current a/c balance: %.2lf\n",current->acb);
                                tm();
                                printf("\n\tDAFFODIL BANK Ltd.\n\n");
                                transfer(ac,mn);
                            }
                            else
                            {
                                printf("\nWrong input\n");
                            }
                            break;


                        }

                        /* }

                         else
                         {
                             printf("\n\nWrong PIN\n");
                             break;
                         }*/

                        a=1;
                    }
                    current=current->next;
                }
                if(a==0)
                {
                    printf("\nDo not match\n");
                }
                printf("\nAre you want to do anymore operation?if want press -->'1':");
                scanf("%d",&more2);
            }

            while(more2==1);
            break;




        case 0:
            vr=0;

            printf("\nEnter admin name: ");
            scanf("%s",&usrname);
            printf("Enter password: ");

            for(i=0; i<4; i++)
            {
                ch = getch();
                pasword[i] = ch;
                ch = '*' ;
                printf("%c",ch);
            }
            cm=strcmp(id,usrname);
            if(cm==0)
            {
                int more;
                do
                {
                    int slct;
                    char psw[10],pswd[10];
                    printf("\nSelect what you want to do.\n\nPress '1' -->Open new account.\nPress '2' -->Edit any a/c information.\nPress '3' -->Delete any account.\nPress '4' -->Search any account.\nPress '5' -->Display all account information.\nPress '6' -->change Admin password.\nPress '7' -->Logout.\n");
                    scanf("%d",&slct);
                    switch(slct)
                    {
                    case 1:
                        newac();
                        break;
                    case 2:
                        editac();
                        break;
                    case 3:
                        acdelete();
                        break;
                    case 4:
                        search();
                        break;
                    case 5:
                        dispaly();
                        break;
                    case 7:
                        lgot();
                        break;
                    case 6:
                        printf("\nEnter old password:");
                        for(i=0; i<4; i++)
                        {
                            ch = getch();
                            psw[i] = ch;
                            ch = '*' ;
                            printf("%c",ch);
                        }
                        if(ps[0]==psw[0]&&ps[1]==psw[1]&&ps[2]==psw[2]&&ps[3]==psw[3])
                        {
                            printf("\nEnter new password:");
                            for(i=0; i<4; i++)
                            {
                                ch = getch();
                                psw[i] = ch;
                                ch = '*' ;
                                printf("%c",ch);
                            }
                            printf("\nRe-type new password:");
                            for(i=0; i<4; i++)
                            {
                                ch = getch();
                                pswd[i] = ch;
                                ch = '*' ;
                                printf("%c",ch);
                            }
                            if(pswd[0]==psw[0]&&pswd[1]==psw[1]&&pswd[2]==psw[2]&&pswd[3]==psw[3])
                            {
                                ps[4]=psw[4];
                                printf("\nPassword changed succesfully\n");
                            }
                            else
                            {
                                printf("\nDo not match password\n");
                            }
                        }

                        else
                        {
                            printf("\nWrong password\n");
                        }
                        break;
                    }
                    printf("\nAre you want to do anymore operation?if want press -->'1':");
                    scanf("%d",&more);
                }

                while(more==1);

            }
            else
            {
                printf("\nWrong username or password\n");
            }
            break;
        default:
            printf("\nWrong press\n");
            break;
        }
    }

}


int main()
{
    fst();
    return 0;
}
