#include <stdio.h>
#include<conio.h>
void main()
{
    int year, month, day, cy, cmonth, cd, age_year, age_month, age_day;

    int d2, m2;
    printf("\n\t\t\t\t\t==========<<<<<<<<<<*>>>>>>>>>>==========\n");
    printf("\t\t\t\t\t|       ..... AGE CALCULATOR .....      |\n");
    printf("\t\t\t\t\t==========<<<<<<<<<<*>>>>>>>>>>==========\n");
    printf("  Enter your birth day: ");
    scanf("%d", &day);
    printf("\n  ---------------Month: ");
    scanf("%d", &month);
    printf("\n  ----------------Year: ");
    scanf("%d", &year);
    printf("\n  Enter current day: ");
    scanf("%d", &cd);
    printf("\n  ------------Month: ");
    scanf("%d", &cmonth);
    printf("\n  -------------Year: ");
    scanf("%d", &cy);
    if ((day > 31 || day < 1) || (cd > 31 || cd < 1) || (month > 12 || month < 1) || (cmonth > 12 || cmonth < 1))
    {
        printf("\n\a......Banda ban!.....");
        getch();
        exit(0);
    }
    else if (cd < day && cmonth == month && cy == year)
    {
        printf("\n\a.....Phir jaman wagia hain.....");
        getch();
        exit(0);
    }
    else if ((cmonth < month && cy == year) || cy < year)
    {
        printf("\n\a.....Phir jaman wagia hain.....");
        getch();
        exit(0);
    }
    else if (cd == day && cy >= year && cmonth == month)
    {
        printf("\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n");
        printf("\t\a...**HAPPY BIRTH DAY**...\n");
        printf("*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
    }
    if (day <= cd && month <= cmonth && cy >= year)
    {
        age_day = cd - day;
        age_month = cmonth - month;
        age_year = cy - year;
    }
    if (cd < day && cmonth > month && cy > year)
        if (cmonth == 1 || cmonth == 3 || cmonth == 5 || cmonth == 7 || cmonth == 8 || cmonth == 10 || cmonth == 12)
        {
            d2 = cd + 31;
            age_day = d2 - day;
            age_month = cmonth - month - 1;
            age_year = cy - year;
        }
    if (cd < day && cmonth > month && cy > year)
        if (cmonth == 4 || cmonth == 6 || cmonth == 9 || cmonth == 11)
        {
            d2 = cd + 30;
            age_day = d2 - day;
            age_month = cmonth - month - 1;
            age_year = cy - year;
        }
    if (cd < day && month < cmonth && cy > year)
        if (cmonth == 2 && cy % 4 == 0)
        {
            d2 = cd + 29;
            age_day = d2 - day;
            age_month = cmonth - month - 1;
            age_year = cy - year;
        }
    if (cd < day && cmonth > month && cy > year)
        if (cmonth == 2 && cy % 4 != 0)
        {
            d2 = cd + 28;
            age_day = d2 - day;
            age_month = cmonth - month - 1;
            age_year = cy - year;
        }
    if (cd < day && cmonth <= month && cy > year)
        if (cmonth == 1 || cmonth == 3 || cmonth == 5 || cmonth == 7 || cmonth == 8 || cmonth == 10 || cmonth == 12)
        {
            d2 = cd + 31;
            age_day = d2 - day;
            m2 = cmonth + 12;
            age_month = m2 - month - 1;
            age_year = cy - year - 1;
        }
    if (cd < day && cmonth <= month && cy > year)
        if (cmonth == 4 || cmonth == 6 || cmonth == 9 || cmonth == 11)
        {
            d2 = cd + 30;
            age_day = d2 - day;
            m2 = cmonth + 12;
            age_month = m2 - month - 1;
            age_year = cy - year - 1;
        }
    if (cd < day && cmonth <= month && cy > year)
        if (cmonth == 2 && cy % 4 == 0)
        {
            d2 = cd + 29;
            age_day = d2 - day;
            m2 = cmonth + 12;
            age_month = m2 - month - 1;
            age_year = cy - year - 1;
        }
    if (cmonth == 2 && cy % 4 != 0)
    {
        d2 = cd + 28;
        age_day = d2 - day;
        m2 = cmonth + 12;
        age_month = m2 - month - 1;
        age_year = cy - year - 1;
    }
    if (cd > day && cmonth < month && cy > year)
        if (cmonth == 2 && cy % 4 == 0)
        {
            age_day = cd - day;
            m2 = cmonth + 12;
            age_month = m2 - month;
            age_year = cy - year - 1;
        }
    if (cd >= day && cmonth < month && cy > year)
        if (cmonth == 2 && cy % 4 != 0)
        {
            age_day = cd - day;
            m2 = cmonth + 12;
            age_month = m2 - month;
            age_year = cy - year - 1;
        }

    printf("\n\n\t\t\t============================================================");
    printf("\n\t\t\t\t....Your age is %d years %d months %d days....", age_year, age_month, age_day);
    printf("\n\t\t\t============================================================");
}
