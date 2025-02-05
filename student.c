// ***
// *** You MUST modify this file
// ***

#include "hw5.h"

void StudentPrint(Student *stu, int num)
{
    printf("There are %d students\n", num);
    for (int ind = 0; ind < num; ind++)
    {
        printf("ID = %d, Name = %s\n", stu[ind].ID, stu[ind].name);
    }
}

// count the number of '\n' to determine the number of records
int countNewLine(FILE *fptr)
{
    int numline = 0;
    while (!feof(fptr))
    {
        int onechar = fgetc(fptr);
        if (onechar == '\n')
        {
            numline++;
        }
    }
    return numline;
}

/* This is the first function you need to implement */
bool StudentRead(char *filename, Student **stu, int *numelem)
{
    /* 1.1: open the file to read */
    FILE *fptr;
    // the name of the file to open is stored in filename
    // if fopen fails, return false
    // do not use fclose since fopen already fails

    /* end of 1.1: open the file to read */

    int numline = countNewLine(fptr);

    // return to the beginning of the file
    // you can use fseek or
    // fclose followed by fopen
    // You need to check whether fseek or fopen fails
    // Do not use rewind because it does not report whether it fails
    int rtv; // return value
    rtv = fseek(fptr, 0, SEEK_SET);
    if (rtv == -1) // fseek fails
    {
        fclose(fptr);
        return false;
    }

    /* 1.2 allocate memory for the data */
    Student *stuptr;
    // stuptr is an array of type Student
    // refer to hw5.h to understand the type Student
    // the number of elements in this array is numline
    // use the malloc function
    // check whether memory allocation fails

    /* end of 1.2: allocate memory for the data */

    /* 1.3: read data from the file */
    // read the data from the file
    // store the data to the array stuptr
    // fclose the file after read of data is done

    /* end of 1.3: allocate memory for the data */

    *numelem = numline;
    *stu = stuptr;
    return true;
}

/* This is the second function you need to implement */
bool StudentWrite(char *filename, Student *stu, int numelem)
{
    // open the file to write
    // the name of file to open is stored in string filename
    // if fopen fails, return false
    // do not use fclose since fopen already fails
    // stu is an array of type Student
    // refer to hw5.h to understand the type Student
    // the number of elements in array stu is numelem
    // write the data from array stu to the opened file
    // fclose the file in the end

    return true;
}

/* This is the third function you need to implement */
void sortStudents(Student *stu, int numelem, int (*compar)(const void *, const void *))
{
    /* Fill in to call qsort function to sort array stu */
    // stu: an array of Students. numelem: number of elements in the array. compar: comparison function
    // refer to hw5.h to understand the type Student
}

/* This is the fourth function you need to implement */
int compareID(const void *p1, const void *p2)
{
    /* Fill in to compare p1 and p2 by id */
    // return a negative value if the ID of the first student is smaller
    // return a positive value if the ID of the first student is larger
    // return zero if the IDs of the two students are the same
}

/* This is the fifth function you need to implement */
int compareName(const void *p1, const void *p2)
{
    /* Fill in to compare p1 and p2 by name */
    // use strcmp function to compare two strings
    // return a negative value if the name of the first student is alphabetically earlier
    // return a positive value if the name of the first student is alphabetically later
    // return zero if the names of the two students are the same
}

/* This is the sixth function you need to implement */
bool areStudentsSorted(Student *stu, int numelem, int (*compar)(const void *, const void *))
{
    /* Fill in to check if the stu array is sorted according to compar */
    // return true if the stu array is sorted according to compar
    // return false otherwise
    // refer to hw5.h to understand the type Student
}
