/*****************************************************
 *
 *  CSCV352 - Exercise5_4.c
 * Exercise5_4
Write a program that traverses a linked list and prints a summary of each node in the list. 
In this exercise you are provided with a program that populates a list of employee records 
using a linked list structure. The function PopulateList() is provided and called to initialize 
the data in the list. The function returns a pointer to a linked list of records. 
You must use the list returned by PopulateList() and print the data for each node in the list.
Take a screenshot showing the terminal after the program runs. The screenshot should show the 
output of your program. Name the screenshot either Exercise5_4.jpg or Exercise5_4.png, depending on 
the image type of the screenshot file.
When complete, turn in your source code file using the filename Exercise5_4.c and your screenshot file 
named according to the above instruction.

 *
 *  Student:  <Student's Name>
 *
******************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


///////////////////////////////////////////////////////
//                CONSTANTS
///////////////////////////////////////////////////////
#define  MAX_NAME   128
#define  MAX_DATE   64
#define  MAX_EMAIL_ADDRESS 128


///////////////////////////////////////////////////////
//               typedefs and structures
//////////////////////////////////////////////////////
typedef struct employee_data {
    struct employee_data *pNext;
	char firstName[MAX_NAME];
	char lastName[MAX_NAME];
	char middleName[MAX_NAME];
	char emailAddress[MAX_EMAIL_ADDRESS];
	char title[MAX_EMAIL_ADDRESS];
	float annualSalary;
	char dateOfHire[MAX_DATE];
} EmployeeInformation;


///////////////////////////////////////////////////////
//               globalVariables
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//                FunctionPrototypes
///////////////////////////////////////////////////////
EmployeeInformation *PopulateList();

/*****************************************************
 *
 *  Function:  main()
 *
 *  Parameters:
 *
 *      argc - main parameter for argument count
 *      argv - main parameter for argument values
 *
******************************************************/
int main(int argc, char *argv[]) 
{
	EmployeeInformation *pEmployeeList;
	
    pEmployeeList = PopulateList();

	// TODO: Add your code here to print the list

    return 0;
}


///////////////////////////////////////////////////////
//     Code for loading the list
//          DO NOT MODIFY
///////////////////////////////////////////////////////
#define NUM_ENTRIES 15

typedef struct {
     char *firstName;
     char *middleName;
     char *lastName;
     char *emailAddress;
     char title[MAX_EMAIL_ADDRESS];
	 char dateOfHire[MAX_DATE];
     float annualSalary;
} EmployeeInformationPtrs;


EmployeeInformationPtrs initialData [] = {
{"Max","Peake","Allan","max.allan@me.com", "Engineer I", "Jul 14, 2021", 64000.00},
{"Mary","Hodges","Scott","mary.scott@me.com", "Engineer II", "Jan 29, 2020", 68300.00},
{"Peter","Young","Alsop","peter.alsop@me.com", "Director", "May 1, 2020", 860000.00},
{"Eric","Chapman","Bailey","eric.bailey@me.com", "Help Desk Manager", "Feb 4, 2021", 390000.00},
{"Sebastian","Rampling","Cameron","sebastian.cameron@me.com", "Senior Engineer", "Aug 24, 2019", 84700.00},
{"Gordon","Underwood","Watson","gordon.watson@me.com", "VP Sales", "Mar 6, 2018", 244600.00},
{"Sebastian","Burgess","Ince","sebastian.ince@me.com", "Sales Associate", "Sep 18, 2021", 32000.00},
{"Amelia","Ince","Nolan","amelia.nolan@me.com", "CEO", "Jan 11, 2022", 485000.00},
{"Eric","Springer","Mills","eric.mills@me.com", "CTO", "Jul 18, 2021", 640000.00},
{"Adrian","Lee","Rampling","adrian.rampling@me.com", "VP Engineering", "Apr 11, 2020", 164000.00},
{"Lily","Abraham","Wright","lily.wright@me.com", "Engineer III", "Mar 20, 2020", 724000.00},
{"Julia","Mackay","Turner","julia.turner@me.com", "VP Marketing", "Jan 8, 2022", 88000.00},
{"Tracey","Rutherford","MacLeod","tracey.macleod@me.com", "Sales Engineer", "Jun 14, 2018", 67000.00},
{"Leonard","Stewart","Mackay","leonard.mackay@me.com", "CFO", "Nov 1, 2020", 297000.00},
{"Dylan","Vaughan","Miller","dylan.miller@me.com", "Senior Accountant", "May 14, 2021", 54000.00}};


EmployeeInformation *PopulateList()
{
	EmployeeInformation *pListHead=NULL;
	EmployeeInformation *pNewEntry=NULL;

	for (int i = 0; i < NUM_ENTRIES; ++i)
	{
		pNewEntry = malloc(sizeof(EmployeeInformation));
		if (pNewEntry == NULL)
		{
			printf("Critical memory error\n");
			exit(0);
		}
		strcpy(pNewEntry->firstName, initialData[i].firstName);
		strcpy(pNewEntry->lastName, initialData[i].lastName);
		strcpy(pNewEntry->middleName, initialData[i].middleName);
		strcpy(pNewEntry->emailAddress, initialData[i].emailAddress);
		strcpy(pNewEntry->dateOfHire, initialData[i].dateOfHire);
		strcpy(pNewEntry->title, initialData[i].title);
		pNewEntry->annualSalary = initialData[i].annualSalary;	
		pNewEntry->pNext =  NULL;

		// Insert the new entry at the beginning of the list
		if (pListHead == NULL)
		{
            pListHead = pNewEntry;
		}
		else
		{
			pNewEntry->pNext = pListHead;
			pListHead = pNewEntry;
		}
	}

	return pListHead;
}
