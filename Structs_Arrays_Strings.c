/*
 ============================================================================
 Name        : Structs_Arrays_Strings.c
 Author      : Bruno Calogero
 Version     :
 Copyright   : Your copyright notice
 Description : Structs, Arrays and Strings
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int my_strcmp(char s1[], char s2[])  //function that returns either 1 or 0 (thus the int),  so : yes it is the same string or no it isn't, hence the 'int'

{
	int i=0 ;                        // insert variable to evaluate each letter of the words
	while (s1[i]==s2[i])             // insert a while loop to evaluate step by step each letters of the words, if they are equal we go to the next letter and if either one of the strings arrives at the 'null' we break the loop
	{
		if ( s1[i]=='\0' || s2[i]=='\0')
			break;
		i++;
	}
	if ( s1[i]=='\0' && s2[i]=='\0')   // if both operations are at the null, thus at the same position, we can return 1 meaning there is equivalence between the two words, otherwise we return 0, meaning that there isn't equivalence (ASCII)
		return 1;
	else
		return 0;
}

void my_strcpy(char s1[], char s2[])   //doesn't return anything so chose the 'void'

{
	int i=0 ;                          //enter integer to use within the function that will be assigned to each letter of the word that will be copied to another word
	while (s1[i]!='\0')                // while the integer isn't the last character copy characters from string 2 (word 2) to string 1 (word to be copied)
	{
		s2[i]=s1[i];
		i++;                           // add 1 to i to go to the next value of the string so the next character of the word.
	}
}

int main(void)

{
	char s1[30],s2[30],s3[30]; //setting up the two arrays and number of elements in the latter
	int a;                     //enter dummy variable integer
	scanf("%s",&s1);
	scanf("%s",&s2);
	a=my_strcmp(s1,s2);        // call the the result 0 or 1 from function my_strcmp
	if ( a == 1)               //    if a=1 then the two words are the same otherwise they are not (no braquets because only one action after for loop
		printf ("The two words are the same.");
		else
			printf("The two words are not the same.");
	my_strcpy(s1, s3);                                  // calling value and thus word of function my_strcpy
	printf ("\nThe copy of the first word is: %s", s3); // print copied word

}

//============================================================================================================================================================================================================================================

#include <stdio.h>
#include <stdlib.h>

void add_matrices(int m1[100][100], int m2[100][100], int destination_matrix[100][100], int n_rows, int n_columns ) // function "add_matrices" that adds two dimensional matrixes

{

	int i,j;                          //enter dummy variables to evaluate the two matrices m1 and m2
	for(i=0;i<n_rows;i++)             // use i to evaluate all the rows of the matrices
	       for(j=0;j<n_columns;j++)   // use j to evaluate all the columns of the matrices
	    	   destination_matrix[i][j]=m1[i][j]+m2[i][j]; // add the two matrices and assign it to destination_matrix (resulting matrix of the addition)

}

int main(void)
{
    int m1[100][100], m2[100][100], destination_matrix[100][100], n_rows, n_columns, i, j;     //defining all the variables
    scanf ("%d %d", &n_rows, &n_columns);      // enter the number of rows and columns for matrices
    printf("Enter the First matrix->");
      for(i=0;i<n_rows;i++)
          for(j=0;j<n_columns;j++)
               scanf("%d",&m1[i][j]);         // enter matrix m1
    printf("\nEnter the Second matrix->");
      for(i=0;i<n_rows;i++){
          for(j=0;j<n_columns;j++){
               scanf("%d",&m2[i][j]);         // enter matrix m2
          }
      }
    add_matrices(m1, m2, destination_matrix, n_rows,n_columns);      // call value from function "add_matrices"
      for(i=0;i<n_rows;i++){
          for(j=0;j<n_columns;j++){
          	  printf ("%d ",destination_matrix[i][j]);               // print/show the resulting matrix from the addition
          }
          printf ("\n");
      }
          return 0;
}

//============================================================================================================================================================================================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct library{             //enter struct library for the values that we  want to print or report for every student ( one library will be assigned to one student
	char Name[30];          // array of 30 names
	int StudentNumber;      // student number ID
	float CourseMarks[30];  // array of CourseMarks
};

void main(){

	int a=0;                // introducing variable for the switch
	int i,j;                // introducing dummy variables for for futur selection of array values
	char Name[30];
	int LibraryNumber=0;
	int MarkNumber[100]={0};     // out the brackets to assign 0 to all the marks (the whole array)
	struct library library[100]; // assign an array of values for the library (100 here) , each number up to 100 corresponds to a student

	do                           //set up a do - while combination loop to recall menu after each value of switch
	{
	printf("please enter the wanted option:\n1.Introduce new student\n2.Introduce Mark\n3.Print report of all students\n4:exit\n"); // print the menu for the user to select options from

    scanf("%d",&a);              // input integer between 1 and 4 to select option from menu

    switch(a)                    //introduce a switch that intakes the previously inputed value of a and that therefore selects a case
    {
        case 1:                  // controls student name and number in a given library

            printf("enter students name and number\n");
            scanf ("%s",library[LibraryNumber].Name);             //scan the name and associates it to library number in the array (first value or incremented value )
            scanf("%d",&library[LibraryNumber].StudentNumber);    // scann the student number and associates it to library number in the array (first value or incremented value)
            LibraryNumber++;                                      //increment +1 to lubraryNumber int , thus going to the next value of the library array for a new student for instance
            break;                                               // break the case and returns menu for user


        case 2:                // controls student mark (in a given module) for corresponding value of library of student


            printf("enter students name and mark\n");
            scanf("%s",Name);
            for (i=0;i<LibraryNumber;i++)    // for every value of the library string which we completed in the previous case input an associated CourseMark ( if the name associated to the string value of the library then scan an associated mark)
            {
                if ((strcmp(library[i].Name,Name)==0))
                {
                    scanf ("%f",&library[i].CourseMarks[MarkNumber[i]]); //this also creates an array within an array to assign multiple marks to a same student
                    MarkNumber[i]++;         // increment Marknumber by 1 so that the next MarkNumber array will be associated to the next student we input
                }
            }
            break;


        case 3:         //Prints out the whole record of the libraries we have created

            printf ("The Record For The Entered students is: \n");
            for (i=0;i<LibraryNumber;i++)                                        // for loop so that we can use the dummy variable to print all the elements of each individual libraries
            {
                printf ("Student name: %s \n",library[i].Name);                   //prints the name of the student for the given library
                printf ("Student ID number: %d \n",library[i].StudentNumber);     //prints his mark for a given library
                for(j=0;j<MarkNumber[i];j++)                                       //second for loop to print multiple marks per student if multiple marks have been inputed
                {
                	printf ("Mark for module %d:",j);
                    printf ("  %f \n",library[i].CourseMarks[j]);
                }
            }
            break;

    }                //closing switch
  } while(a!=4);    //closing do - while loop
}

// !!END!! \\

