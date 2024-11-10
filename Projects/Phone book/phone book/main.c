#include <stdio.h>
#include <conio.h>
#include <string.h>

// prototype......
void password();
void main_menu();
void choice();
void input();
void create_contact();
void view_contact();
void search_contact();
void delete_contact();
void delete_allContact();

typedef struct person
{
    char first_name[20];
    char last_name[20];
    char country_name[20];
    char c_code[15];
    char mobile_no[15];
} person;

// Main func.....
int main()
{
    password(); // call password func......
}

// definition (password)func....
void password()
{
    system("cls");
    system("color 0C");
    printf("\n\t\t\t\t\t ***************************");
    printf("\n\t\t\t\t\t *\t  PASSWORD\t   *");
    printf("\n\t\t\t\t\t ***************************");
    printf("\n\n\tEnter 3 digit password please :");
    char pass[4] = {0};
    int i = 0;
    for (i = 0; i <= 2; i++)
    {
        pass[i] = getch();
        if (pass[i] == 13 || pass[i] == 8 || pass[i] == 32)
        {
            printf("\n\n\t\a Enter valid input.......");
            getch();
            system("cls");
            password();
        }
        printf("*");
    }
    pass[i] = '\0';
    if (pass[0] == '1' && pass[1] == '2' && pass[2] == '3')
        main_menu(); // call main menu func.......
    else
    {
        printf("\n\n\a   ...W R O N G...please try again... :");
        printf("\n   press any key to continue >>>>>>");
        getch();
        system("cls");
        password(); // call password func.....
    }
}

// definition (Main menu)func......
void main_menu()
{
    system("cls");
    system("color 1E");
    printf(".......Contact Book........");
    printf("\n\n\t\t\t\t\t*****.....*****.....*****.....*****");
    printf("\n\t\t\t\t\t\t     MAIN MENU ");
    printf("\n\t\t\t\t\t*****.....*****.....*****.....*****");
    printf("\n\n\t1.CREATE CONTACT");
    printf("\n\n\t2.VIEW CONTACTS");
    printf("\n\n\t3.SEARCH CONTACT");
    printf("\n\n\t4.DELETE CONTACT");
    printf("\n\n\t5.DELETE ALL CONTACTS");
    printf("\n\n\t6.EXIT");
    choice(); // call choice func......
}

// definition (choice)func....
void choice()
{
    char ch;
    printf("\n\n   Enter your choice :");
    ch = getche();
    while (1)
    {
        switch (ch)
        {
        case '1':
            create_contact();
            break;
        case '2':
            view_contact();
            break;
        case '3':
            search_contact();
            break;
        case '4':
            delete_contact();
            break;
        case '5':
            delete_allContact();
            break;
        case '6':
            system("cls");
            printf("\n\t\t\t\t.......... THANK YOU FOR VISITING ........... :)");
            printf("\nPress any key to continue.....");
            getch();
            exit(1);
        default:
            printf("\n\n\a  .... I N V L I D input....");
            printf("\n  please try again.....");
            printf("\n\nPress any key to continue >>>>>>");
            getch();
            system("cls");
            main_menu(); // call main menu func......
        }
    }
}

// definition (create contact) func.....
void create_contact()
{
    system("cls");
    system("color 0A");
    printf("\n\n\t\t\t\t*.*.*.*.*.*.*.* Create your contact *.*.*.*.*.*.*.*");
    printf("\n\n  Enter your first name :");
    input();
    printf("  Enter your last name :");
    input();
    printf("  Enter your country name :");
    input();
    printf("  Enter your country code :");
    input();
    printf("  Enter your mobile no :");
    input();
    printf("\n\n  Record added successfully....... :");
    printf("\n  Press any key to continue >>>>>");
    getch();
    main_menu();
}

// defining input func.....
void input()
{
    char ch;
    char str[50];
    int i = 0;
    scanf("%c", &ch);
    if (ch == '\n')
    {
        printf("\aPlease enter valid input....  ");
        input();
    }
    else
    {
        while (ch != '\n')
        {
            str[i] = ch;
            scanf("%c", &ch);
            i++;
        }
        str[i] = '\0';

        // writing data to file......
        FILE *fptr;
        fptr = fopen("contact book.txt", "a+");
        if (fptr == NULL)
        {
            printf("\a\nFile opening error..... :");
            printf("\nPress any key to continue >>>>>");
            getch();
            main_menu();
        }
        else
        {
            fprintf(fptr, "%s ", str);
            fclose(fptr);
        }
    }
}

// definition (view contacts)func....
void view_contact()
{
    system("cls");
    system("color 0E");
    person p;
    int num = 0;
    FILE *fptr;
    fptr = fopen("contact book.txt", "r");
    if (fptr == NULL)
    {
        printf("\nFile opening error..... :");
        printf("\nPress any key to continue >>>>>");
        getch();
        main_menu();
    }
    else
    {
        while (fscanf(fptr, "%s %s %s %s %s", p.first_name, p.last_name, p.country_name, p.c_code, p.mobile_no) != EOF)
        {
            if (num == 0)
            {
                printf("\n\n\n\t\t\t*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*");
                printf("\n\t\t\t*                       SAVED CONTACTS                          *");
                printf("\n\t\t\t*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*\n\n");
                printf("\n  ..............................................................................................................");
                printf("\n     Name\t\t\t  Country name\t\t      Country code \t\t       Mobile number\n");
                printf("  ..............................................................................................................\n\n");
                num = 1;
            }
            // strcat(p.first_name,p.last_name); //concatination....
            printf(" %s %s", p.first_name, p.last_name);

            int len_1 = 35 - strlen(p.first_name) - strlen(p.last_name) - 1; // for printing spaces.....
            int len_2 = 34 - strlen(p.country_name);
            int len_3 = 27 - strlen(p.c_code);

            for (int i = 0; i < len_1; i++)         
                printf(" ");
            printf("%s", p.country_name);
            for (int i = 0; i < len_2; i++)
                printf(" ");
            printf("%s", p.c_code);
            for (int i = 0; i < len_3; i++)
                printf(" ");
            puts(p.mobile_no);
        }
        if (num == 0)
        {
            printf("\a\n....Sorry contact is not available yet.......");
        }
        fclose(fptr);
        printf("\n\nPress any key to continue >>>>>");
        getch();
        system("cls");
        main_menu();
    }
}

// defining (search contact)func....
void search_contact()
{
    system("cls");
    system("color 0E");
    char temp_name[20];
    person p;
    int point = 0;
    FILE *fptr;
    fptr = fopen("contact book.txt", "r+");
    if (fptr == NULL)
    {
        printf("\nFile opening error..... :");
        printf("\nPress any key to continue >>>>>");
        getch();
        main_menu(); // call main menu func......
    }
    else
    {
        printf("\n....Search Contact....");
        printf("\n\nEnter name : ");
        gets(temp_name);
        while (temp_name[0] == '\0')
        {
            printf("\aEnter valid name.....");
            gets(temp_name);
        }
        while (fscanf(fptr, "%s %s %s %s %s", p.first_name, p.last_name, p.country_name, p.c_code, p.mobile_no) != EOF)
        {
            if (strcmp(temp_name, p.first_name) == 0 || strcmp(temp_name, p.last_name) == 0)
            {
                if (point == 0)
                {
                    printf("\n   Name\t\t\t     Country name\t\t     Country code \t\t      Mobile number\n");
                    printf("  ...........................................................................................................\n\n");
                    point = 1;
                }
                // strcat(p.first_name,p.last_name); //concatination(combine two strings)....

                printf(" %s %s", p.first_name, p.last_name);

                int len_1 = 30 - strlen(p.first_name) - strlen(p.last_name) - 1; // for printing spaces.....
                int len_2 = 34 - strlen(p.country_name);
                int len_3 = 27 - strlen(p.c_code);

                for (int i = 0; i < len_1; i++)
                    printf(" ");
                printf(" %s", p.country_name);
                for (int i = 0; i < len_2; i++)
                    printf(" ");
                printf(" %s", p.c_code);
                for (int i = 0; i < len_3; i++)
                    printf(" ");
                puts(p.mobile_no);
            }
        }
        if (point == 0)
        {
            printf("\a\n ...SORRY...contact related to this name is not available : ......");
        }
        fclose(fptr);
        printf("\n Press any key to continue >>>>>");
        getch();
        main_menu(); // call main menu func......
    }
}

// defining (delete)func....
void delete_contact()
{
    system("cls");
    system("color 0C");
    FILE *fptr, *fp;
    char name[20];
    person p;
    int point = 0;
    fptr = fopen("contact book.txt", "r");
    fp = fopen("original.txt", "w");
    if ((fptr == NULL) || (fp == NULL))
    {
        printf("file opening error!....");
        printf("\nPress any key to continue......");
        getch();
        main_menu(); // call main menu func......
    }
    printf("\n XXXXX Delete contact XXXXX");
    printf("\n\n Enter name :");
    gets(name);
    while (name[0] == '\0')
    {
        printf("\aEnter valid name.....");
        gets(name);
    }
    while (fscanf(fptr, "%s %s %s %s %s ", p.first_name, p.last_name, p.country_name, p.c_code, p.mobile_no) != EOF)
    {
        if (strcmp(p.first_name, name) == 0 || strcmp(p.last_name, name) == 0)
        {
            point = 1;
            continue;
        }
        fprintf(fp, "%s\t%s\t%s\t%s\t%s\n", p.first_name, p.last_name, p.country_name, p.c_code, p.mobile_no);
    }
    fclose(fptr);
    fclose(fp);
    fptr = fopen("contact book.txt", "w");
    fp = fopen("original.txt", "r");
    while (fscanf(fp, "%s %s %s %s %s ", p.first_name, p.last_name, p.country_name, p.c_code, p.mobile_no) != EOF)
    {
        fprintf(fptr, "%s\t%s\t%s\t%s\t%s\n", p.first_name, p.last_name, p.country_name, p.c_code, p.mobile_no);
    }
    fclose(fptr);
    fclose(fp);
    remove("original.txt");
    if (point == 0)
    {
        printf("\n\a ...SORRY...contact related to this name is not available :( ......");
        printf("\nPress any key to continue......");
        getch();
        main_menu(); // call main menu func......
    }
    printf("\n\a...Your contact has been deleted successfully....");
    printf("\nPress any key to continue......");
    getch();
    main_menu(); // call main menu func......
}

// defining (delete_allcontact)func....
void delete_allContact()
{
    system("cls");
    system("color 0C");
    FILE *fptr;
    printf("\n\tXXXXX  DELETE ALL CONTACTS  XXXXX");
    printf("\n\n  Are you sure you want to delete all contacts : ");
    printf("\n  Enter \'y\' for \'yes\' and \'N\' for \'No\' : ");
    char ch = getche();
    if (ch == 'y')
    {
        fptr = fopen("contact book.txt", "w");
        if (fptr == NULL)
        {
            printf("\nFile opening error..... :(");
            printf("\nPress any key to continue >>>>>");
            getch();
            main_menu();
        }
        printf("\n\n->-> All data has been deleted.......");
        printf("\nPress any key to continue >>>>>");
        getch();
        fclose(fptr);
        main_menu(); // call main menu func......
    }
    else if (ch == 'n')
    {
        printf("\nPress any key to continue >>>>>");
        getch();
        main_menu();
    }
    else
    {
        printf("\a\n\n ...I N V L I D ...input....");
        printf("\n Press any key to continue >>>>>");
        getch();
        delete_allContact();
    }
}
