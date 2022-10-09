#include "test1.h"
#include <stdbool.h>



bool SDB_IsIdExist(uint8 id_check)
{
    int i ;
    for( i=0;i<entries;i++)
    {

        if (s[i].Student_ID == id_check)
        {
            return true;
        }
    }
    return false;
}
bool SDB_AddEntry(uint8 id,uint8 year,uint8* subjects,uint8* grades)
{

        if((grades[0]>=0 && grades[0]<=100) && (grades[1]>=0 && grades[1]<=100) && (grades[2]>=0 && grades[2]<=100) && SDB_IsIdExist(id) == false)
        {
            s[entries].Student_ID=id;
            s[entries].Student_year=year;

            s[entries].Course1_ID = subjects[0];
            s[entries].Course1_grade = grades[0];

            s[entries].Course2_ID = subjects[1];
            s[entries].Course2_grade = grades[1];

            s[entries].Course3_ID = subjects[2];
            s[entries].Course3_grade = grades[2];

            entries++;
            return true;
        }
        else
        {
            return false;
        }
}
uint8 GetUsedSize()
{
    return entries;
}
bool SDB_IsFull()
{
    if (entries == max)
    {
        return true;
    }
    else
    {
        return false;
    }

}
bool SDB_ReadEntry(uint8 id_check,uint8* year,uint8* subjects,uint8* grades)
{
    int i ;
    for( i=0;i<entries;i++)
    {

        if (s[i].Student_ID == id_check)
        {
            printf("The entry exists\n\n");

            *year = s[i].Student_year;
            printf("Student's year is :%d \n",*year);

            subjects[0] = s[i].Course1_ID;
            printf("Course 1 ID : %d\n",subjects[0]);

            grades[0] = s[i].Course1_grade;
            printf("Course 1 grade : %d\n",grades[0]);

            subjects[1] = s[i].Course2_ID;
            printf("Course 2 ID : %d\n",subjects[1]);

            grades[1] = s[i].Course2_grade;
            printf("Course 2 grade : %d\n",grades[1]);

            subjects[2] = s[i].Course3_ID;
            printf("Course 3 ID : %d\n",subjects[2]);

            grades[2] = s[i].Course3_grade;
            printf("Course 3 grade : %d\n",grades[2]);



            printf("\n\n");
            return 1;
        }
    }
    printf("The entry does not exist");
    return 0;

}
void SDB_DeleteEntry (uint8 id_check)
{
int  i ,j ;
    for( i=0;i<entries;i++)
    {

        if (id_check == s[i].Student_ID)
        {

            for ( j=i ; j<entries-1 ; j++)
            {
                s[j] = s[j+1];
            }

            s[entries-1].Student_ID = 0;
            s[entries-1].Student_year = 0;

            s[entries-1].Course1_ID =0;
            s[entries-1].Course2_ID =0;
            s[entries-1].Course3_ID =0;

            s[entries-1].Course1_grade = 0;
            s[entries-1].Course2_grade = 0;
            s[entries-1].Course3_grade = 0;




            entries--;
            printf("The entry is deleted\n ");
            break ;
         }
    }

}
void SDB_GetIdList(uint8* count , uint8*list)
{
int i ;
    printf("Number of entries is %d\n\n",*count);

    for ( i=0;i<entries;i++)
    {
        temp_arr_id[i] = s[i].Student_ID;
    }

    printf("ID list of Students :\n");
    for ( i=0;i<entries;i++)
    {
        printf("%d\n",temp_arr_id[i]);
    }
    printf("\n\n");
}
bool SDB_EditEntry (uint8 id_check , uint8 id , uint8 year , uint8* subjects , uint8* grades)
{
    int i ;
    if((grades[0]>=0 && grades[0]<=100) && (grades[1]>=0 && grades[1]<=100) && (grades[2]>=0 && grades[2]<=100))
    {
        for ( i=0;i<entries;i++)
        {

            if(s[i].Student_ID == id_check)
            {
                    s[i].Student_ID=id;
                    s[i].Student_year=year;

                    s[i].Course1_ID = subjects[0];
                    s[i].Course1_grade = grades[0];

                    s[i].Course2_ID = subjects[1];
                    s[i].Course2_grade = grades[1];

                    s[i].Course3_ID = subjects[2];
                    s[i].Course3_grade = grades[2];
                    return true;
            }

        }
    }
    else
    {
        return false;
    }
}
void SDB_DisplayEntries ()
{
    int i ;
    if(entries >0)
    {
        printf("                               Students' Data (from oldest to newest)     \n\n");
        printf(" -----------------------------------------------------------------------------------------------------------  \n");
        printf("  ID   | Year  | Course 1 ID | Course 2 ID | Course 3 ID | Course 1 Grade | Course 2 Grade | Course 3 Grade\n");
        for( i=0;i<entries;i++)
        {
            printf("  %d    | %d  |      %d      |      %d     |      %d      |      %d        |      %d         |      %d     \n",s[i].Student_ID , s[i].Student_year , s[i].Course1_ID  ,s[i].Course1_grade , s[i].Course2_ID  ,s[i].Course2_grade , s[i].Course3_ID  ,s[i].Course3_grade);

        }

        printf(" -----------------------------------------------------------------------------------------------------------  \n");
    }
    else
    {
        printf("There is no data to show\n\n\n");
    }

}
