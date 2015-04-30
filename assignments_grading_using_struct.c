 /*************************************************************************
 *                   Mureithi David Wachira                               *
 *                   P15/2204/2011                                        *
 *                                                                        *
 *                   University of Nairobi                                *
 *                   School of Computing & Informatics                    *
 *                                                                        *
 *                   Course: PROGRAMMING AND PROBLEM SOLVING  (CSC 121)   *
 *                   Date:   Thursday 11th April 2013                     *
 *                                                                        *
 *                  A program to read data for each student	(50)       	  *
 *					of CSC 121 (each line of data consists of the 		  *
 *					student   name, followed by marks (out of 100) 		  *
 *				    obtained in six assignments) , calculate the 		  *
 *					average mark (out of 50) obtained  and output 		  *
 *					the	results under suitable headings. 		          *
 *					  											  		  *
 *					For each student print the name, the six marks, the   *
 *					average and the message pass or fail (use both 		  *
 *					member operator and arrow operator). 	        	  *
 *								 						                  *
 *					At the end print:		                              *
 *					- The number of students processed					  *
 *					- The number who passed (a student passes if average  *
 *   				  is greater than 20 out of 50)	                	  *
 *					- The number who failed							 	  *
 *					- The class average for each of the six assignments)  *
 *					- The name of the best student (with the highest 	  *
 *					  average)							 				  *
 *												 						  *
 *                                                                        *
 *************************************************************************/

 #include<stdio.h>                  /* C Standard Input and Output Library*/
 #define csc_students_total 5      /* Constant for the number of students in the class*/

 /*Variable declarations*/
    int students_counter;
    int highest_average_score, student_with_highest_average_score;
    double mean_csc121,mean_csc122,mean_csc123,mean_csc124,mean_csc125,mean_csc126;
    int pass_count, fail_count;
    double mean_students, pass_count_percent, fail_count_percent;;

/* csc_student structure definition */
  struct csc_student
   {
    char first_name[20]; /* Definition and declaration of the first name of student */
    char last_name[20];  /* Definition and declaration of the last name of student  */
    char reg_number[20]; /* Definition and declaration of the registration number of student */
    int csc121, csc122, csc123, csc124, csc125, csc126; /* Declaration of the 6 subjects done by a CSC student */
    double student_average;
    char pass_fail_status[1];
   }; /* end of structure */

 /* Prototyping of functions*/
int entry_into_structure(struct csc_student csc_student_table[csc_students_total]);
int calculations(struct csc_student csc_student_table[csc_students_total]);

int main(void)/* The main method*/
{   /* Brief detail on the screen about the program*/
    printf(" /*************************************************************************\n *                   Mureithi David Wachira                               *\n *                   P15/2204/2011                                        *\n *                                                                        *\n *                   University of Nairobi                                *\n *                   School of Computing & Informatics                    *\n *                                                                        *\n *                   Course: PROGRAMMING AND PROBLEM SOLVING  (CSC 121)   *\n *                   Date:   Thursday 11th April 2013                     *\n *                                                                        *\n *                   A program to read data for each student	(50)      *\n *	             of CSC 121 (each line of data consists of the 	  *\n *	              students name, followed by marks (out of 100) 	  *\n *		     obtained in six assignments) , calculate the 	  *\n *		     average mark (out of 50) obtained  and output 	  *\n *		     the results under suitable headings. 		  *\n *					  				  *\n *		     For each student print the name, the six marks, the  *\n *		     average and the message pass or fail (use both 	  *\n *		     member operator and arrow operator). 	          *\n *								 	  *\n *		     At the end print:		                          *\n *			- The number of students processed		  *\n *			- The number who passed (a student passes if      *\n *   			  average is greater than 20 out of 50)	          *\n *			- The number who failed				  *\n *			- The class average for each of the 6 assignments *\n *			- The name of the best student (with the highest  *\n *			  average)					  *\n *							         	  *\n *                                                                        *\n *************************************************************************/\n");

    /* Creating a variable of the user defined structure*/
    struct csc_student csc_student_table[csc_students_total];

    entry_into_structure (csc_student_table);/* Call of the function entry_into_structure ()*/
    printf("\n\nStudent Name   CSC121  CSC122  CSC123  CSC124  CSC125  CSC126  Average  Status \n------------   ------  ------  ------  ------  ------  ------  -------  ------\n");

    calculations(csc_student_table);/* Call of the calculations ()*/

    /* Percentage of students who passed and failed */
    pass_count_percent=(((double)(pass_count))/csc_students_total*100);
    fail_count_percent=(((double)(fail_count))/csc_students_total*100);

    /* Loop to print the students details and scores*/
    for (students_counter=1; students_counter<= csc_students_total; students_counter++)
    {  printf("%3c. %8s%5d%8d%8d%8d%8d%8d       %2.2lf%8c\n",toupper(csc_student_table[students_counter].first_name[0]), csc_student_table[students_counter].last_name, csc_student_table[students_counter].csc121, csc_student_table[students_counter].csc122, csc_student_table[students_counter].csc123, csc_student_table[students_counter].csc124, csc_student_table[students_counter].csc125, csc_student_table[students_counter].csc126, csc_student_table[students_counter].student_average, csc_student_table[students_counter].pass_fail_status[0] );
    }

    printf("\n\n------------   ------  ------  ------  ------  ------  ------  -------  \n");
    printf("%s%1s\t%2.1lf\t%2.1lf\t%2.1lf\t%2.1lf\t%2.1lf\t%2.1lf\t(%2.2lf/50)\n\n", "Average", "(mean):", mean_csc121, mean_csc122, mean_csc123, mean_csc124, mean_csc125, mean_csc126, mean_students );
    printf("Total number of students: %d\n", csc_students_total);
    printf("Students who passed : %d (%3.2lf %%)\n", pass_count, pass_count_percent);
    printf("Students who failed : %d (%3.2lf %%)\n", fail_count, fail_count_percent);
   printf("\n\nThe best student is : %s %s with an average score of %3.2lf\n", csc_student_table[student_with_highest_average_score].first_name, csc_student_table[student_with_highest_average_score].last_name, csc_student_table[student_with_highest_average_score].student_average);

    return 0;/* An indication that the program runs successfully*/
} /* The end of the main method*/


int calculations(struct csc_student csc_student_table[csc_students_total])
{

    for (students_counter=1; students_counter<= csc_students_total; students_counter++)
    {      /* Finding the highest average score in the class */
           if( highest_average_score < csc_student_table[students_counter].student_average)
           {highest_average_score=csc_student_table[students_counter].student_average;
            student_with_highest_average_score=students_counter;
           }
           /* Calculating the number of students who have passed*/
           if(csc_student_table[students_counter].pass_fail_status[0]=='P')
           {
             pass_count++;
           }
           /* Calculating the number of students who have passed*/
           else if(csc_student_table[students_counter].pass_fail_status[0]=='F')
           {
             fail_count++;
           }
    }
           /* Division of the totals obtained by the number of students in the class*/
           mean_csc121=mean_csc121/csc_students_total ;
           mean_csc122=mean_csc122/csc_students_total ;
           mean_csc123=mean_csc123/csc_students_total ;
           mean_csc124=mean_csc124/csc_students_total ;
           mean_csc125=mean_csc125/csc_students_total ;
           mean_csc126=mean_csc126/csc_students_total ;
           mean_students=mean_students/csc_students_total ;

    return 0;
}

int entry_into_structure(struct csc_student csc_student_table[csc_students_total])
        /* Loop to go enable the entering of data of a student*/
{       for(students_counter=1; students_counter<= csc_students_total; students_counter++)
        {
            printf("First name of the student # %d:\n", students_counter);                               /* Prompt user to enter the first name of the student*/
            scanf("%s",&csc_student_table[students_counter].first_name);                                 /* Capture of the name of the first student by the system*/

            printf("Last name of the student # %d:\n", students_counter);                                /* Prompt user to enter the last name of the student*/
            scanf("%s",&csc_student_table[students_counter].last_name);                                  /* Capture of the last name of the student by the system*/

            printf("Registration number of the student # %d:\n", students_counter);                      /* Prompt user to enter the registration number of the student*/
            scanf("%s",&csc_student_table[students_counter].reg_number);                                 /* Capture of the registration number of the student by the system*/

            printf("\nMarks (out of 100) that the student # %d scored in CSC 121:\n", students_counter); /* Prompt user to enter the score of the first subject*/
            scanf("%d",&csc_student_table[students_counter].csc121);                                     /* Capture of the score of the first subject by the system*/
            mean_csc121=mean_csc121+csc_student_table[students_counter].csc121;                          /* Incrementation of the score to the score of the class*/

            printf("Marks (out of 100) that the student # %d scored in CSC 122:\n", students_counter);   /* Prompt user to enter the score of the second subject*/
            scanf("%d",&csc_student_table[students_counter].csc122);                                     /* Capture of the score of the second subject by the system*/
            mean_csc122=mean_csc122+csc_student_table[students_counter].csc122;                          /* Incrementation of the score to the score of the class*/

            printf("Marks (out of 100) that the student # %d scored in CSC 123:\n", students_counter);   /* Prompt user to enter the score of the third subject*/
            scanf("%d",&csc_student_table[students_counter].csc123);                                     /* Capture of the score of the third subject by the system*/
            mean_csc123=mean_csc123+csc_student_table[students_counter].csc123;                          /* Incrementation of the score to the score of the class*/

            printf("Marks (out of 100) that the student # %d scored in CSC 124:\n", students_counter);   /* Prompt user to enter the score of the fourth subject*/
            scanf("%d",&csc_student_table[students_counter].csc124);                                     /* Capture of the score of the fourth subject by the system*/
            mean_csc124=mean_csc124+csc_student_table[students_counter].csc124;                          /* Incrementation of the score to the score of the class*/

            printf("Marks (out of 100) that the student # %d scored in CSC 125:\n", students_counter);   /* Prompt user to enter the score of the fifth subject*/
            scanf("%d",&csc_student_table[students_counter].csc125);                                     /* Capture of the score of the fifth subject by the system*/
            mean_csc125=mean_csc125+csc_student_table[students_counter].csc125;                          /* Incrementation of the score to the score of the class*/

            printf("Marks (out of 100) that the student # %d scored in CSC 126:\n", students_counter);   /* Prompt user to enter the score of the sixth subject*/
            scanf("%d",&csc_student_table[students_counter].csc126);                                     /* Capture of the score of the sixth subject by the system*/
            mean_csc126=mean_csc126+csc_student_table[students_counter].csc126;                          /* Incrementation of the score to the score of the class*/

            csc_student_table[students_counter].student_average=((double)((csc_student_table[students_counter].csc121) + (csc_student_table[students_counter].csc122) + (csc_student_table[students_counter].csc123) + (csc_student_table[students_counter].csc124) + (csc_student_table[students_counter].csc125) + (csc_student_table[students_counter].csc126))/6)/2;
            mean_students=mean_students+csc_student_table[students_counter].student_average;

            /* Determination of whether the student has passsed*/
            if ((csc_student_table[students_counter].student_average)>20 && (csc_student_table[students_counter].student_average)<=50)
            {
              csc_student_table[students_counter].pass_fail_status[0]='P';
            }
            /* Determination of whether the student has failed*/
            else if ((csc_student_table[students_counter].student_average)<=20 && (csc_student_table[students_counter].student_average)>0)
            {
              csc_student_table[students_counter].pass_fail_status[0]='F';
            }


         /* Printing a line to seperate the data of one student to another */
         printf("\n\n------------------------------------------------------------------------------\n");


        }

  return 0;
}
