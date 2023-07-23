#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


//function prototype
void availability();
void booking();
int search(char *str, int studentID);
void reallocation();
void roomdetails();
void maleroom();
void femaleroom();
void store(char *str, int i, struct hostelers block2);
int roomnumber(int line, int i);
void mainmenu();
int countingBeds(char *str);
void deleting(char *str, int j);
void cancel();
int countingzero(char *str);
void searchempty(char *str);
int bedavail(char *str);
int billing(int weeks, char *str, int service);
void payment();
void amountreceivable();
void goback();

//main function
int main()
{
	mainmenu();
	return 0;
}

//main menu
void mainmenu()
{
	int option;
	printf("\n\t*****************************************\n\t*\t        WELCOME TO   \t\t*\n\t*\t   WISDOM COLLEGE HOSTEL\t*\n\t*\t     MANAGEMENT SYSTEM\t\t*\n\t*****************************************\n");
	printf("\n\n\n\t1: CHECK ROOM AVAILABILITY\n\t2: BOOK ROOM\n\t3: ROOM CANCELLATION\n\t4: ROOM REALLOCATION\n\t5: ROOM DETAILS\n\t6: PAYMENT\n\t7: AMOUNT RECEIVABLE\n\t8: EXIT SYSTEM");
	printf("\n\nChoose an option: ");
	scanf("%d", &option);
	switch (option)
	{

	case 1: availability();
		break;
	case 2: booking();
		break;
	case 3: cancel();
		break;
	case 4: reallocation();
		break;
	case 5: roomdetails();
		break;
	case 6: payment();
		break;
	case 7: amountreceivable();
		break;
	case 8:exit(0);
		break;
	default: {printf("Please Enter a Valid Option:");
		mainmenu();
	}
	}
}

//structure to store students detail
struct hostelers {
	int studentID;
	char name[50];
	int amountdue;
	int paymentmade;
	int room_no;
}A1[100], A2[200], B2[200], B4[400]; 
//declaring structure variables 

//check room function
void availability()
{
	printf("\n\n\t\t\t\tAVAILABILITY\n");
	printf(" **************************************************************************\n ");
	printf("|   BLOCK   |   GENDER   |    ROOM TYPE   |        BEDS AVAILABLE        |\n ");
	printf("************************************************************************** \n ");
	printf("     A1          Male        Single Bed                  %3d              \n ", bedavail("A1.txt"));
	printf("     A2          Male         2-Bedded                   %3d              \n ", bedavail("A2.txt"));
	printf("     A3          Male         3-Bedded       -BLOCK UNDER CONSTRUCTION-   \n ");
	printf("     A4          Male         4-Bedded       -BLOCK UNDER CONSTRUCTION-   \n ");
	printf("     B1         Female       Single Bed      -BLOCK UNDER CONSTRUCTION-   \n ");
	printf("     B2         Female        2-Bedded                   %3d              \n ", bedavail("B2.txt"));
	printf("     B3         Female        3-Bedded       -BLOCK UNDER CONSTRUCTION-   \n ");
	printf("     B4         Female        4-Bedded                   %3d              \n ", bedavail("B4.txt"));
	goback();
}

int bedavail(char *str) {
	if (strcmp(str, "A1.txt") == 0)
		return 100 - countingBeds("A1.txt") + countingzero("A1.txt");

	else if (strcmp(str, "A2.txt") == 0)
		return 200 - countingBeds("A2.txt") + countingzero("A2.txt");

	else if (strcmp(str, "B2.txt") == 0)
		return 200 - countingBeds("B2.txt") + countingzero("B2.txt");

	else if (strcmp(str, "B4.txt") == 0)
		return 400 - countingBeds("B4.txt") + countingzero("B4.txt");

}

//count number of beds occupied per block excluding those that are cancelled
int countingBeds(char *str) {
	int lines = 0;
	char ch;
	FILE *fptr;
	fptr = fopen(str, "r");
	if (fptr == NULL) {
		printf("Error in opening file");
		exit(1);
	}
	for (ch = fgetc(fptr); ch != EOF; ch = fgetc(fptr))
	{
		if (ch == '\n')
			lines++;
	}

	fclose(fptr);
	return lines;
}

//count number of zero(cancelled) beds 
int countingzero(char *str) {
	struct hostelers A1[100], A2[200], B2[200], B4[400];
	int counter = 0, j;
	char ch;
	FILE *fptr;
	fptr = fopen(str, "r");
	if (fptr == NULL) {
		printf("Error in opening file");
		exit(1);
	}
	if (strcmp(str, "A1.txt") == 0) {
		for (j = 1; j <= countingBeds("A1.txt"); j++) {
			fscanf(fptr, "%d\t%s\t%03d\t%d\t%d\n", &A1[j].studentID, &A1[j].name, &A1[j].room_no, &A1[j].amountdue, &A1[j].paymentmade);
			if (A1[j].studentID == 0) {
				counter++;
			}
		}
	}

	else if (strcmp(str, "A2.txt") == 0) {
		for (j = 1; j <= countingBeds("A2.txt"); j++) {
			fscanf(fptr, "%d\t%s\t%03d\t%d\t%d\n", &A2[j].studentID, &A2[j].name, &A2[j].room_no, &A2[j].amountdue, &A2[j].paymentmade);
			if (A2[j].studentID == 0) {
				counter++;
			}
		}
	}

	else if (strcmp(str, "B2.txt") == 0) {
		for (j = 1; j <= countingBeds("B2.txt"); j++) {
			fscanf(fptr, "%d\t%s\t%03d\t%d\t%d\n", &B2[j].studentID, &B2[j].name, &B2[j].room_no, &B2[j].amountdue, &B2[j].paymentmade);
			if (B2[j].studentID == 0) {
				counter++;
			}
		}
	}

	else if (strcmp(str, "B4.txt") == 0) {
		for (j = 1; j <= countingBeds("B4.txt"); j++) {
			fscanf(fptr, "%d\t%s\t%03d\t%d\t%d\n", &B4[j].studentID, &B4[j].name, &B4[j].room_no, &B4[j].amountdue, &B4[j].paymentmade);
			if (B4[j].studentID == 0) {
				counter++;
			}
		}
	}

	fclose(fptr);
	return counter;
}



//booking function
void booking()
{
	int choose;
	printf("\tROOM FOR:\n");
	printf("\t1: MALE\n\t2: FEMALE\n\t3: EXIT TO MAIN MENU\nCHOOSE AN OPTION:");
	scanf("%d", &choose);
	if (choose == 1)
		maleroom();
	else if (choose == 2)
		femaleroom();
	else if (choose == 3)
		mainmenu();
	else
	{
		printf("Please Enter a Valid Option");
		booking();
	}
}

//booking for male
void maleroom()
{
	int i;
	struct hostelers A1[100], A2[200];
	char choose2[3];
	printf("\n\tROOM TYPES");
	printf("\n\tA1: Single Bed");
	printf("\n\tA2: 2-Bedded");
	printf("\n\tA3: 3-Bedded");
	printf("\n\tA4: 4-Bedded");
	printf("\n\tE0: EXIT TO MAIN MENU");
	printf("\nChoose a Room Type:");
	scanf("%s", &choose2);
	if (strcmp(choose2, "A1") == 0) {
		if (bedavail("A1.txt") == 0)
			printf("Block is full.");
		else {
			if (countingzero("A1.txt") != 0)
				searchempty("A1.txt");
			else {
				i = 1;
				store("A1.txt", i, A1[countingBeds("A1.txt") + 1]);
			}
		}
	}
	else if (strcmp(choose2, "A2") == 0) {
		if (bedavail("A2.txt") == 0)
			printf("Block is full.");
		else {
			if (countingzero("A2.txt") != 0)
				searchempty("A2.txt");
			else {
				i = 1;
				store("A2.txt", i, A2[countingBeds("A2.txt") + 1]);
			}
		}
	}
	else if (strcmp(choose2, "A3") == 0 || strcmp(choose2, "A4") == 0) {
		printf("Block is under construction.");
		maleroom();
	}
	else if (strcmp(choose2, "E0") == 0)
		mainmenu();
	else {
		printf("\nInvalid Room Type. Please Choose Again.\n");
		maleroom();
	}
}

//booking for female
void femaleroom()
{
	int i;
	char choose2[3];
	struct hostelers B2[200], B4[400];
	printf("\n\tROOM TYPES");
	printf("\n\tB1: Single Bed");
	printf("\n\tB2: 2-Bedded");
	printf("\n\tB3: 3-Bedded");
	printf("\n\tB4: 4-Bedded");
	printf("\n\tE0: EXIT TO MAIN MENU");
	printf("\nChoose a Room Type:");
	scanf("%s", &choose2);
	if (strcmp(choose2, "B2") == 0) {
		if (bedavail("B2.txt") == 0)
			printf("Block is full.");
		else {
			if (countingzero("B2.txt") != 0)
				searchempty("B2.txt");
			else {
				i = 1;
				store("B2.txt", i, B2[countingBeds("B2.txt") + 1]);
			}
		}
	}
	else if (strcmp(choose2, "B4") == 0) {
		if (bedavail("B4.txt") == 0)
			printf("Block is full.");
		else {
			if (countingzero("B4.txt") != 0)
				searchempty("B4.txt");
			else {
				i = 1;
				store("B4.txt", i, B4[countingBeds("B4.txt") + 1]);
			}
		}
	}
	else if (strcmp(choose2, "B1") == 0 || strcmp(choose2, "B3") == 0) {
		printf("Block is under construction.");
		femaleroom();
	}
	else if (strcmp(choose2, "E0") == 0)
		mainmenu();
	else {
		printf("\nInvalid Room Type. Please Choose Again.\n");
		femaleroom();
	}
}




//for storing students record into file
void store(char *str, int i, struct hostelers block2)
{
	FILE *fptr;
	char ch, option[4], include_meal[4], include_gym[4], comfirm[4];
	int lines = 1, j, service_price = 0, weeks, received, amountdue;
	struct hostelers A1[100], A2[200], B2[200], B4[400];

	fptr = fopen(str, "a+");
	if (fptr == NULL) {
		printf("Error in opening file");
		exit(1);
	}
	for (ch = fgetc(fptr); ch != EOF; ch = fgetc(fptr))
	{
		if (ch == '\n')
			lines++;
	}

	block2.room_no = roomnumber(lines, i);
	printf("\n\tRoom number: %03d", block2.room_no);
	printf("\n\n\tENTER STUDENT DETAILS");
	printf("\nStudent ID: ");
	scanf("%d", &block2.studentID);
	getchar();
	if (block2.studentID != 0) {
		printf("\nStudent Name: ");
		gets(block2.name);
		//additional services
		printf("\n\tAdditional Services:\n\n");
		printf("\t1.Internet-UNAVAILABLE-\n\t2.Meal\n\t3.Laundry-UNAVAILABLE-\n\t4.Gym\n\n");
		printf("Include Meal? (yes/no):");
		scanf("%s", &include_meal);
		if (strcmp(include_meal, "yes") == 0 || strcmp(include_meal, "Yes") == 0)
			service_price = service_price + 120;
		printf("Include Gym? (yes/no):");
		scanf("%s", &include_gym);
		if (strcmp(include_gym, "yes") == 0 || strcmp(include_gym, "Yes") == 0)
			service_price = service_price + 10;
		printf("Number of weeks booking:");
		scanf("%d", &weeks);
		printf("The Amount of staying is: %d\n", billing(weeks, str, service_price));
		//storing data into files
		printf("Amount receiving: ");
		scanf("%d", &received);
		amountdue = billing(weeks, str, service_price) - received;
		block2.amountdue = amountdue;
		block2.paymentmade = received;
		printf("Comfirm Booking?(yes/no)");
		scanf("%s", &comfirm);
		if (strcmp(comfirm, "yes") == 0) {
			fprintf(fptr, "%d\t%s\t%03d\t%d\t%d\n", block2.studentID, block2.name, block2.room_no, block2.amountdue, block2.paymentmade);
			printf("\nBooking successfull!\n");
		}
	}
	else {
		printf("\nInvalid Student ID.\n\n");
		booking();
	}

	fclose(fptr);
	goback();
}

//dividing the lines with number of people that can be in a room and then round down the number to find the room number
int roomnumber(int lines, int i)
{
	double num;
	int roomnumber;
	num = (double)lines / (double)i;
	roomnumber = ceil(num);
	return roomnumber;
}

//searching student records in respective file
int search(char *str, int studentID) {
	FILE *fptr;
	int j, exist = 0;
	struct hostelers A1[100], A2[200], B2[200], B4[400];
	fptr = fopen(str, "r+");
	if (fptr == NULL) {
		printf("Error in opening file");
		exit(1);
	}
	if (strcmp(str, "A1.txt") == 0) {
		for (j = 1; j <= countingBeds("A1.txt"); j++) {
			fscanf(fptr, "%d\t%s\t%03d\t%d\t%d\n", &A1[j].studentID, &A1[j].name, &A1[j].room_no, &A1[j].amountdue, &A1[j].paymentmade);
			if (A1[j].studentID == studentID) {
				exist = 1;
				break;
			}
		}
	}
	else if (strcmp(str, "A2.txt") == 0) {
		for (j = 1; j <= countingBeds("A2.txt"); j++) {
			fscanf(fptr, "%d\t%s\t%03d\t%d\t%d\n", &A2[j].studentID, &A2[j].name, &A2[j].room_no, &A2[j].amountdue, &A2[j].paymentmade);
			if (A2[j].studentID == studentID) {
				exist = 1;
				break;
			}
		}
	}
	else if (strcmp(str, "B2.txt") == 0) {
		for (j = 1; j <= countingBeds("B2.txt"); j++) {
			fscanf(fptr, "%d\t%s\t%03d\t%d\t%d\n", &B2[j].studentID, &B2[j].name, &B2[j].room_no, &B2[j].amountdue, &B2[j].paymentmade);
			if (B2[j].studentID == studentID) {
				exist = 1;
				break;
			}
		}
	}
	else if (strcmp(str, "B4.txt") == 0) {
		for (j = 1; j <= countingBeds("B4.txt"); j++) {
			fscanf(fptr, "%d\t%s\t%03d\t%d\t%d\n", &B4[j].studentID, &B4[j].name, &B4[j].room_no, &B4[j].amountdue, &B4[j].paymentmade);
			if (B4[j].studentID == studentID) {
				exist = 1;
				break;
			}
		}
	}
	fclose(fptr);
	if (exist == 0) {
		return exist;
	}
	else
		return j;
}


//cancelling function
void cancel() {
	FILE *fptr;
	int studentID;
	char block[3], comfirm[4];
	struct hostelers A1[100], A2[200], B2[200], B4[400];
	printf("Enter Student ID:");
	scanf("%d", &studentID);
	if (studentID == 0) {
		printf("\nInvalid Student ID.\n");
		cancel();
	}
	printf("Enter Block booked(eg: A1): ");
	scanf("%s", &block);
	if (strcmp(block, "A1") == 0)
		if (search("A1.txt", studentID) != 0) {
			deleting("A1.txt", search("A1.txt", studentID));
			goback();
		}

		else {
			printf("\nInvalid StudentID.\n");
			cancel();
		}
	else if (strcmp(block, "A2") == 0)
		if (search("A2.txt", studentID) != 0) {
			deleting("A2.txt", search("A2.txt", studentID));
			goback();
		}
		else {
			printf("\nInvalid StudentID.\n");
			cancel();
		}
	else if (strcmp(block, "B2") == 0)
		if (search("B2.txt", studentID) != 0) {
			deleting("B2.txt", search("B2.txt", studentID));
			goback();
		}
		else {
			printf("\nInvalid StudentID.\n");
			cancel();
		}
	else if (strcmp(block, "B4") != 0)
		if (search("B4.txt", studentID) != 0) {
			deleting("B4.txt", search("B4.txt", studentID));
			goback();
		}
		else {
			printf("\nInvalid StudentID.\n");
			cancel();
		}
	else {
		printf("\nInvalid Block. Please Enter a Valid Block.\n");
		cancel();
	}
}


//in order to delete student records a temp file has to be created and then replaced the original file
void deleting(char *str, int j)
{
	FILE *fptr, *ftemp;
	char ch;
	int counter;
	fptr = fopen(str, "r");
	ftemp = fopen("temp.txt", "w");
	if (fptr == NULL || ftemp == NULL) {
		printf("Error in opening file");
		exit(1);
	}
	if (strcmp(str, "A1.txt") == 0) {
		for (counter = 1; counter <= countingBeds("A1.txt"); counter++) {
			fscanf(fptr, "%d\t%s\t%03d\t%d\t%d\n", &A1[counter].studentID, &A1[counter].name, &A1[counter].room_no, &A1[counter].amountdue, &A1[counter].paymentmade);
			if (counter == j) {
				printf("\t--RECORD FOUND--\n\tStudent ID:%d\n\tStudent Name:%s\n\tRoom Number:%03d\n\tAmount Due: %d\n\tPayment Made: %d", A1[j].studentID, A1[j].name, A1[j].room_no, A1[j].amountdue, A1[j].paymentmade);
				A1[j].studentID = 0;
				fprintf(ftemp, "%d\t%s\t%03d\t%d\t%d\n", A1[j].studentID, A1[j].name, A1[j].room_no, A1[j].amountdue, A1[j].paymentmade);
			}
			else
				fprintf(ftemp, "%d\t%s\t%03d\t%d\t%d\n", A1[counter].studentID, A1[counter].name, A1[counter].room_no, A1[counter].amountdue, A1[counter].paymentmade);
		}
	}
	else if (strcmp(str, "A2.txt") == 0) {
		for (counter = 1; counter <= countingBeds("A2.txt"); counter++) {
			fscanf(fptr, "%d\t%s\t%03d\t%d\t%d\n", &A2[counter].studentID, &A2[counter].name, &A2[counter].room_no, &A2[counter].amountdue, &A2[counter].paymentmade);
			if (counter == j) {
				printf("\t--RECORD FOUND--\n\tStudent ID:%d\n\tStudent Name:%s\n\tRoom Number:%03d\n\tAmount Due: %d\n\tPayment Made: %d", A2[j].studentID, A2[j].name, A2[j].room_no, A2[j].amountdue, A2[j].paymentmade);
				A2[j].studentID = 0;
				fprintf(ftemp, "%d\t%s\t%03d\t%d\t%d\n", A2[j].studentID, A2[j].name, A2[j].room_no, A2[j].amountdue, A2[j].paymentmade);
			}
			else
				fprintf(ftemp, "%d\t%s\t%03d\t%d\t%d\n", A2[counter].studentID, A2[counter].name, A2[counter].room_no, A2[counter].amountdue, A2[counter].paymentmade);
		}
	}
	else if (strcmp(str, "B2.txt") == 0) {
		for (counter = 1; counter <= countingBeds("B2.txt"); counter++) {
			fscanf(fptr, "%d\t%s\t%03d\t%d\t%d\n", &B2[counter].studentID, &B2[counter].name, &B2[counter].room_no, &B2[counter].amountdue, &B2[counter].paymentmade);
			if (counter == j) {
				printf("\t--RECORD FOUND--\n\tStudent ID:%d\n\tStudent Name:%s\n\tRoom Number:%03d\n\tAmount Due: %d\n\tPayment Made: %d", B2[j].studentID, B2[j].name, B2[j].room_no, B2[j].amountdue, B2[j].paymentmade);
				B2[j].studentID = 0;
				fprintf(ftemp, "%d\t%s\t%03d\t%d\t%d\n", B2[j].studentID, B2[j].name, B2[j].room_no, B2[j].amountdue, B2[j].paymentmade);
			}
			else
				fprintf(ftemp, "%d\t%s\t%03d\t%d\t%d\n", B2[counter].studentID, B2[counter].name, B2[counter].room_no, B2[counter].amountdue, B2[counter].paymentmade);
		}
	}
	else if (strcmp(str, "B4.txt") == 0) {
		for (counter = 1; counter <= countingBeds("B4.txt"); counter++) {
			fscanf(fptr, "%d\t%s\t%03d\t%d\t%d\n", &B4[counter].studentID, &B4[counter].name, &B4[counter].room_no, &B4[counter].amountdue, &B4[counter].paymentmade);
			if (counter == j) {
				printf("\t--RECORD FOUND--\n\tStudent ID:%d\n\tStudent Name:%s\n\tRoom Number:%03d\n\tAmount Due: %d\n\tPayment Made: %d", B4[j].studentID, B4[j].name, B4[j].room_no, B4[j].amountdue, B4[j].paymentmade);
				B4[j].studentID = 0;
				fprintf(ftemp, "%d\t%s\t%03d\t%d\t%d\n", B4[j].studentID, B4[j].name, B4[j].room_no, B4[j].amountdue, B4[j].paymentmade);
			}
			else
				fprintf(ftemp, "%d\t%s\t%03d\t%d\t%d\n", B4[counter].studentID, B4[counter].name, B4[counter].room_no, B4[counter].amountdue, B4[counter].paymentmade);
		}
	}
	fclose(fptr);
	fclose(ftemp);
	remove(str);
	rename("temp.txt", str);
	printf("\nCancellation Successfull!\n");
}

//this function is used when booking to ensure cancelled spots are filled up first by assigned rooms with student id zero to them
void searchempty(char *str)
{
	FILE *fptr, *ftemp;
	int j, count = 0, service_price = 0, weeks, received, amountdue;
	char include_meal[4], include_gym[4], comfirm[4];
	struct hostelers A1[100], A2[200], B2[200], B4[400];
	fptr = fopen(str, "r+");
	ftemp = fopen("temp.txt", "w");
	if (fptr == NULL || ftemp == NULL) {
		printf("Error in opening file");
		exit(1);
	}
	if (strcmp(str, "A1.txt") == 0) {
		for (j = 1; j <= countingBeds("A1.txt"); j++) {
			fscanf(fptr, "%d\t%s\t%03d\t%d\t%d\n", &A1[j].studentID, &A1[j].name, &A1[j].room_no, &A1[j].amountdue, &A1[j].paymentmade);
			if (A1[j].studentID == 0 && count == 0) {
				printf("\n\tRoom number: %03d", A1[j].room_no);
				printf("\n\n\tENTER STUDENT DETAILS");
				printf("\nStudent ID: ");
				scanf("%d", &A1[j].studentID);
				getchar();
				if (A1[j].studentID != 0) {
					printf("\nStudent Name: ");
					gets(A1[j].name);
					//additional services
					printf("\n\tAdditional Services:\n\n");
					printf("\t1.Internet-UNAVAILABLE-\n\t2.Meal\n\t3.Laundry-UNAVAILABLE-\n\t4.Gym\n\n");
					printf("Include Meal? (yes/no):");
					scanf("%s", &include_meal);
					if (strcmp(include_meal, "yes") == 0 || strcmp(include_meal, "Yes") == 0)
						service_price = service_price + 120;
					printf("Include Gym? (yes/no):");
					scanf("%s", &include_gym);
					if (strcmp(include_gym, "yes") == 0 || strcmp(include_gym, "Yes") == 0)
						service_price = service_price + 10;
					printf("Number of weeks booking:");
					scanf("%d", &weeks);
					printf("The Amount of staying is: %d\n", billing(weeks, str, service_price));
					//storing data into files 
					printf("Amount receiving: ");
					scanf("%d", &received);
					amountdue = billing(weeks, str, service_price) - received;
					A1[j].amountdue = amountdue;
					A1[j].paymentmade = received;
					printf("Comfirm Booking?(yes/no)");
					scanf("%s", &comfirm);
					if (strcmp(comfirm, "yes") == 0) {
						fprintf(ftemp, "%d\t%s\t%03d\t%d\t%d\n", A1[j].studentID, A1[j].name, A1[j].room_no, A1[j].amountdue, A1[j].paymentmade);
						printf("\nBooking successfull!\n");
						count++;
					}
					else
						goback();
				}
				else {
					printf("\nInvalid Student ID.\n\n");
					booking();
				}

			}
			else
				fprintf(ftemp, "%d\t%s\t%03d\t%d\t%d\n", A1[j].studentID, A1[j].name, A1[j].room_no, A1[j].amountdue, A1[j].paymentmade);
		}
	}
	else if (strcmp(str, "A2.txt") == 0) {
		for (j = 1; j <= countingBeds("A2.txt"); j++) {
			fscanf(fptr, "%d\t%s\t%03d\t%d\t%d\n", &A2[j].studentID, &A2[j].name, &A2[j].room_no, &A2[j].amountdue, &A2[j].paymentmade);
			if (A2[j].studentID == 0 && count == 0) {
				printf("\n\tRoom number: %03d", A2[j].room_no);
				printf("\n\n\tENTER STUDENT DETAILS");
				printf("\nStudent ID: ");
				scanf("%d", &A2[j].studentID);
				getchar();
				if (A2[j].studentID != 0) {
					printf("\nStudent Name: ");
					gets(A2[j].name);
					printf("\n\tAdditional Services:\n\n");
					printf("\t1.Internet-UNAVAILABLE-\n\t2.Meal\n\t3.Laundry-UNAVAILABLE-\n\t4.Gym\n\n");
					printf("Include Meal? (yes/no):");
					scanf("%s", &include_meal);
					if (strcmp(include_meal, "yes") == 0 || strcmp(include_meal, "Yes") == 0)
						service_price = service_price + 120;
					printf("Include Gym? (yes/no):");
					scanf("%s", &include_gym);
					if (strcmp(include_gym, "yes") == 0 || strcmp(include_gym, "Yes") == 0)
						service_price = service_price + 10;
					printf("Number of weeks booking:");
					scanf("%d", &weeks);
					printf("The Amount of staying is: %d\n", billing(weeks, str, service_price));
					//storing data into files 
					printf("Amount receiving: ");
					scanf("%d", &received);
					amountdue = billing(weeks, str, service_price) - received;
					A2[j].amountdue = amountdue;
					A2[j].paymentmade = received;
					printf("Comfirm Booking?(yes/no)");
					scanf("%s", &comfirm);
					if (strcmp(comfirm, "yes") == 0) {
						fprintf(ftemp, "%d\t%s\t%03d\t%d\t%d\n", A2[j].studentID, A2[j].name, A2[j].room_no, A2[j].amountdue, A2[j].paymentmade);
						printf("\nBooking successfull!\n");
						count++;
					}
					else
						goback();
				}
				else {
					printf("\nInvalid Student ID.\n\n");
					booking();
				}
			}
			else
				fprintf(ftemp, "%d\t%s\t%03d\t%d\t%d\n", A2[j].studentID, A2[j].name, A2[j].room_no, A2[j].amountdue, A2[j].paymentmade);
		}
	}

	else if (strcmp(str, "B2.txt") == 0) {
		for (j = 1; j <= countingBeds("B2.txt"); j++) {
			fscanf(fptr, "%d\t%s\t%03d\t%d\t%d\n", &B2[j].studentID, &B2[j].name, &B2[j].room_no, &B2[j].amountdue, &B2[j].paymentmade);
			if (B2[j].studentID == 0 && count == 0) {
				printf("\n\tRoom number: %03d", B2[j].room_no);
				printf("\n\n\tENTER STUDENT DETAILS");
				printf("\nStudent ID: ");
				scanf("%d", &B2[j].studentID);
				getchar();
				if (B2[j].studentID != 0) {
					printf("\nStudent Name: ");
					gets(B2[j].name);
					printf("\n\tAdditional Services:\n\n");
					printf("\t1.Internet-UNAVAILABLE-\n\t2.Meal\n\t3.Laundry-UNAVAILABLE-\n\t4.Gym\n\n");
					printf("Include Meal? (yes/no):");
					scanf("%s", &include_meal);
					if (strcmp(include_meal, "yes") == 0 || strcmp(include_meal, "Yes") == 0)
						service_price = service_price + 120;
					printf("Include Gym? (yes/no):");
					scanf("%s", &include_gym);
					if (strcmp(include_gym, "yes") == 0 || strcmp(include_gym, "Yes") == 0)
						service_price = service_price + 10;
					printf("Number of weeks booking:");
					scanf("%d", &weeks);
					printf("The Amount of staying is: %d\n", billing(weeks, str, service_price));
					//storing data into files 
					printf("Amount receiving: ");
					scanf("%d", &received);
					amountdue = billing(weeks, str, service_price) - received;
					B2[j].amountdue = amountdue;
					B2[j].paymentmade = received;
					printf("Comfirm Booking?(yes/no)");
					scanf("%s", &comfirm);
					if (strcmp(comfirm, "yes") == 0) {
						fprintf(ftemp, "%d\t%s\t%03d\t%d\t%d\n", B2[j].studentID, B2[j].name, B2[j].room_no, B2[j].amountdue, B2[j].paymentmade);
						printf("\nBooking successfull!\n");
						count++;
					}
					else
						goback();
				}
				else {
					printf("\nInvalid Student ID.\n\n");
					booking();
				}
			}
			else
				fprintf(ftemp, "%d\t%s\t%03d\t%d\t%d\n", B2[j].studentID, B2[j].name, B2[j].room_no, B2[j].amountdue, B2[j].paymentmade);
		}
	}

	else if (strcmp(str, "B4.txt") == 0) {
		for (j = 1; j <= countingBeds("B4.txt"); j++) {
			fscanf(fptr, "%d\t%s\t%03d\t%d\t%d\n", &B4[j].studentID, &B4[j].name, &B4[j].room_no, &B4[j].amountdue, &B4[j].paymentmade);
			if (B4[j].studentID == 0 && count == 0) {
				printf("\n\tRoom number: %03d", B4[j].room_no);
				printf("\n\n\tENTER STUDENT DETAILS");
				printf("\nStudent ID: ");
				scanf("%d", &B4[j].studentID);
				getchar();
				if (B4[j].studentID != 0) {
					printf("\nStudent Name: ");
					gets(B4[j].name);
					printf("\n\tAdditional Services:\n\n");
					printf("\t1.Internet-UNAVAILABLE-\n\t2.Meal\n\t3.Laundry-UNAVAILABLE-\n\t4.Gym\n\n");
					printf("Include Meal? (yes/no):");
					scanf("%s", &include_meal);
					if (strcmp(include_meal, "yes") == 0 || strcmp(include_meal, "Yes") == 0)
						service_price = service_price + 120;
					printf("Include Gym? (yes/no):");
					scanf("%s", &include_gym);
					if (strcmp(include_gym, "yes") == 0 || strcmp(include_gym, "Yes") == 0)
						service_price = service_price + 10;
					printf("Number of weeks booking:");
					scanf("%d", &weeks);
					printf("The Amount of staying is: %d\n", billing(weeks, str, service_price));
					//storing data into files 
					printf("Amount receiving: ");
					scanf("%d", &received);
					amountdue = billing(weeks, str, service_price) - received;
					B4[j].amountdue = amountdue;
					B4[j].paymentmade = received;
					if (strcmp(comfirm, "yes") == 0) {
						fprintf(ftemp, "%d\t%s\t%03d\t%d\t%d\n", B4[j].studentID, B4[j].name, B4[j].room_no, B4[j].amountdue, B4[j].paymentmade);
						printf("\nBooking successfull!\n");
						count++;
					}
					else
						goback();
				}
				else {
					printf("\nInvalid Student ID.\n\n");
					booking();
				}
			}
			else
				fprintf(ftemp, "%d\t%s\t%03d\t%d\t%d\n", B4[j].studentID, B4[j].name, B4[j].room_no, B4[j].amountdue, B4[j].paymentmade);
		}
	}
	fclose(fptr);
	fclose(ftemp);
	remove(str);
	rename("temp.txt", str);
	goback();

}

//reallocation function first delete and then book
void reallocation() {
	int studentID;
	char block[3];
	printf("Enter Student ID:");
	scanf("%d", &studentID);
	if (studentID == 0) {
		printf("\nInvalid Student ID.\n");
		reallocation();
	}
	printf("Enter Block booked(eg: A1): ");
	scanf("%s", &block);
	if (strcmp(block, "A1") == 0)
		if (search("A1.txt", studentID) != 0) {
			deleting("A1.txt", search("A1.txt", studentID));
			maleroom();
		}
		else {
			printf("\nInvalid StudentID.\n");
			cancel();
		}
	else if (strcmp(block, "A2") == 0)
		if (search("A2.txt", studentID) != 0) {
			deleting("A2.txt", search("A2.txt", studentID));
			maleroom();
		}
		else {
			printf("\nInvalid StudentID.\n");
			cancel();
		}
	else if (strcmp(block, "B2") == 0)
		if (search("B2.txt", studentID) != 0) {
			deleting("B2.txt", search("B2.txt", studentID));
			femaleroom();
		}
		else {
			printf("\nInvalid StudentID.\n");
			cancel();
		}
	else if (strcmp(block, "B4") != 0)
		if (search("B4.txt", studentID) != 0) {
			deleting("B4.txt", search("B4.txt", studentID));
			femaleroom();
		}
		else {
			printf("\nInvalid StudentID.\n");
			cancel();
		}
	else {
		printf("\nInvalid Block. Please Enter a Valid Block.\n");
		cancel();
	}
}

//function to calculate bill based on services chosen and roomtype
int billing(int weeks, char *str, int service) {
	int bill = 0;
	if (strcmp(str, "A1.txt") == 0)
		bill = (400 + service) * weeks;
	else if (strcmp(str, "A2.txt") || strcmp(str, "B2.txt") == 0)
		bill = (200 + service) * weeks;
	else if (strcmp(str, "B4.txt") == 0)
		bill = (100 + service) * weeks;
	return bill;
}


//display the amount receivable
void amountreceivable()
{
	FILE *fptr;
	char block[3];
	int j, count = 1, totalOver = 0, totalReceived = 0;
	printf("Enter Block:(eg: A1): ");
	scanf("%s", &block);
	if (strcmp(block, "A1") == 0) {
		fptr = fopen("A1.txt", "r");
		for (j = 1; j <= countingBeds("A1.txt"); j++) {
			fscanf(fptr, "%d\t%s\t%03d\t%d\t%d\n", &A1[j].studentID, &A1[j].name, &A1[j].room_no, &A1[j].amountdue, &A1[j].paymentmade);
			if (A1[j].studentID == 0)
				continue;
			printf("%03d. StudentID: %d\tStudent Name: %s\tAmount Receivable: %d\tPayment Received: %d\n", count, A1[j].studentID, A1[j].name, A1[j].amountdue, A1[j].paymentmade);
			count++;
			totalOver = totalOver + A1[j].amountdue;
			totalReceived = totalReceived + A1[j].paymentmade;
		}
	}
	else if (strcmp(block, "A2") == 0) {
		fptr = fopen("A2.txt", "r");
		for (j = 1; j <= countingBeds("A2.txt"); j++) {
			fscanf(fptr, "%d\t%s\t%03d\t%d\t%d\n", &A2[j].studentID, &A2[j].name, &A2[j].room_no, &A2[j].amountdue, &A2[j].paymentmade);
			if (A2[j].studentID == 0)
				continue;
			printf("%03d. StudentID: %d\tStudent Name: %s\tAmount Receivable: %d\tPayment Received: %d\n", count, A2[j].studentID, A2[j].name, A2[j].amountdue, A2[j].paymentmade);
			count++;
			totalOver = totalOver + A2[j].amountdue;
			totalReceived = totalReceived + A2[j].paymentmade;
		}
	}
	else if (strcmp(block, "B2") == 0) {
		fptr = fopen("B2.txt", "r");
		for (j = 1; j <= countingBeds("B2.txt"); j++) {
			fscanf(fptr, "%d\t%s\t%03d\t%d\t%d\n", &B2[j].studentID, &B2[j].name, &B2[j].room_no, &B2[j].amountdue, &B2[j].paymentmade);
			if (A1[j].studentID == 0)
				continue;
			printf("%03d. StudentID: %d\tStudent Name: %s\tAmount Receivable: %d\tPayment Received: %d\n", count, B2[j].studentID, B2[j].name, B2[j].amountdue, B2[j].paymentmade);
			count++;
			totalOver = totalOver + B2[j].amountdue;
			totalReceived = totalReceived + B2[j].paymentmade;
		}
	}
	else if (strcmp(block, "B4") == 0) {
		fptr = fopen("B4.txt", "r");
		for (j = 1; j <= countingBeds("B4.txt"); j++) {
			fscanf(fptr, "%d\t%s\t%03d\t%d\t%d\n", &B4[j].studentID, &B4[j].name, &B4[j].room_no, &B4[j].amountdue, &B4[j].paymentmade);
			if (A1[j].studentID == 0)
				continue;
			printf("%03d. StudentID: %d\tStudent Name: %s\tAmount Receivable: %d\tPayment Received: %d\n", count, B4[j].studentID, B4[j].name, B4[j].amountdue, B4[j].paymentmade);
			count++;
			totalOver = totalOver + B4[j].amountdue;
			totalReceived = totalReceived + B4[j].paymentmade;
		}
	}
	else
		printf("Invalid block");

	printf("\nTotal Amount Receivable: %d", totalOver);
	printf("\nTotal Payment Received: %d", totalReceived);
	goback();
}


//display student record and their roomdetails
void roomdetails() {
	FILE *fptr;
	int studentID;
	char block[3];
	printf("Enter Student ID:");
	scanf("%d", &studentID);
	if (studentID == 0) {
		printf("\nInvalid student ID.\n");
		roomdetails();
	}
	printf("Enter Block booked(eg: A1): ");
	scanf("%s", &block);
	if (strcmp(block, "A1") == 0)
		if (search("A1.txt", studentID) != 0) {
			fptr = fopen("A1.txt", "r");
			if (fptr == NULL) {
				printf("Error in opening file");
				exit(1);
			}
			fscanf(fptr, "%d\t%s\t%03d\t%d\t%d\n", &A1[search("A1.txt", studentID)].studentID, &A1[search("A1.txt", studentID)].name, &A1[search("A1.txt", studentID)].room_no, &A1[search("A1.txt", studentID)].amountdue, &A1[search("A1.txt", studentID)].paymentmade);
			printf("--RECORD FOUND--\n Student ID:%d\nStudent Name:%s\nRoom Number:%03d\nAmount Due: %d\nPayment Made: %d", A1[search("A1.txt", studentID)].studentID, A1[search("A1.txt", studentID)].name, A1[search("A1.txt", studentID)].room_no, A1[search("A1.txt", studentID)].amountdue, A1[search("A1.txt", studentID)].paymentmade);
		}
		else {
			printf("\nInvalid StudentID.\n");
			roomdetails();
		}
	else if (strcmp(block, "A2") == 0)
		if (search("A2.txt", studentID) != 0) {
			fptr = fopen("A2.txt", "r");
			if (fptr == NULL) {
				printf("Error in opening file");
				exit(1);
			}
			fscanf(fptr, "%d\t%s\t%03d\t%d\t%d\n", &A2[search("A2.txt", studentID)].studentID, &A2[search("A2.txt", studentID)].name, &A2[search("A2.txt", studentID)].room_no, &A2[search("A2.txt", studentID)].amountdue, &A2[search("A2.txt", studentID)].paymentmade);
			printf("--RECORD FOUND--\n Student ID:%d\nStudent Name:%s\nRoom Number:%03d\nAmount Due: %d\nPayment Made: %d", A2[search("A2.txt", studentID)].studentID, A2[search("A2.txt", studentID)].name, A2[search("A2.txt", studentID)].room_no, A2[search("A2.txt", studentID)].amountdue, A2[search("A2.txt", studentID)].paymentmade);
		}
		else {
			printf("\nInvalid StudentID.\n");
			roomdetails();
		}
	else if (strcmp(block, "B2") == 0)
		if (search("B2.txt", studentID) != 0) {
			fptr = fopen("B2.txt", "r");
			if (fptr == NULL) {
				printf("Error in opening file");
				exit(1);
			}
			fscanf(fptr, "%d\t%s\t%03d\t%d\t%d\n", &B2[search("B2.txt", studentID)].studentID, &B2[search("B2.txt", studentID)].name, &B2[search("B2.txt", studentID)].room_no, &B2[search("B2.txt", studentID)].amountdue, &B2[search("B2.txt", studentID)].paymentmade);
			printf("--RECORD FOUND--\n Student ID:%d\nStudent Name:%s\nRoom Number:%03d\nAmount Due: %d\nPayment Made: %d", B2[search("B2.txt", studentID)].studentID, B2[search("B2.txt", studentID)].name, B2[search("B2.txt", studentID)].room_no, B2[search("B2.txt", studentID)].amountdue, B2[search("B2.txt", studentID)].paymentmade);
		}
		else {
			printf("\nInvalid StudentID.\n");
			roomdetails();
		}
	else if (strcmp(block, "B4") == 0)
		if (search("B4.txt", studentID) != 0) {
			fptr = fopen("B4.txt", "r");
			if (fptr == NULL) {
				printf("Error in opening file");
				exit(1);
			}
			fscanf(fptr, "%d\t%s\t%03d\t%d\t%d\n", &B4[search("B4.txt", studentID)].studentID, &B4[search("B4.txt", studentID)].name, &B4[search("B4.txt", studentID)].room_no, &B4[search("B4.txt", studentID)].amountdue, &B4[search("B4.txt", studentID)].paymentmade);
			printf("--RECORD FOUND--\n Student ID:%d\nStudent Name:%s\nRoom Number:%03d\nAmount Due: %d\nPayment Made: %d", B4[search("B4.txt", studentID)].studentID, B4[search("B4.txt", studentID)].name, B4[search("B4.txt", studentID)].room_no, B4[search("B4.txt", studentID)].amountdue, B4[search("B4.txt", studentID)].paymentmade);
		}
		else { 
			printf("\nInvalid StudentID.\n");
			roomdetails();
		}
	else {
			printf("\nInvalid Block. Please Enter a Valid Block.\n");
			roomdetails();
	}
	fclose(fptr);
	goback();
}

//allow payment to be doe
void payment() {
	FILE *fptr, *ftemp;
	int studentID, received, j;
	char block[3];
	printf("Enter Student ID:");
	scanf("%d", &studentID);
	if (studentID == 0) {
		printf("\nInvalid Student ID.\n");
		payment();
	}
	printf("Enter Block booked(eg: A1): ");
	scanf("%s", &block);
	ftemp = fopen("temp.txt", "w");
	if (strcmp(block, "A1") == 0) {
		if (search("A1.txt", studentID) != 0) {
			fptr = fopen("A1.txt", "r");
			if (fptr == NULL || ftemp == NULL) {
				printf("Error in opening file");
				exit(1);
			}
			for (j = 1; j <= countingBeds("A1.txt"); j++) {
				fscanf(fptr, "%d\t%s\t%03d\t%d\t%d\n", &A1[j].studentID, &A1[j].name, &A1[j].room_no, &A1[j].amountdue, &A1[j].paymentmade);
				if (j == search("A1.txt", studentID)) {
					printf("Amount Due For Student: %d\n", A1[j].amountdue);
					printf("Amount receiving: ");
					scanf("%d", &received);
					fprintf(ftemp, "%d\t%s\t%03d\t%d\t%d\n", A1[j].studentID, A1[j].name, A1[j].room_no, A1[j].amountdue - received, A1[j].paymentmade + received);
				}
				else
					fprintf(ftemp, "%d\t%s\t%03d\t%d\t%d\n", A1[j].studentID, A1[j].name, A1[j].room_no, A1[j].amountdue, A1[j].paymentmade);
			}
		}
		else {
			printf("\nInvalid student ID\n");
			payment();
		}

		fclose(fptr);
		fclose(ftemp);
		remove("A1.txt");
		rename("temp.txt", "A1.txt");
	}
	else if (strcmp(block, "A2") == 0) {
		if (search("A2.txt", studentID) != 0) {
			fptr = fopen("A2.txt", "r");
			if (fptr == NULL || ftemp == NULL) {
				printf("Error in opening file");
				exit(1);
			}
			for (j = 1; j <= countingBeds("A2.txt"); j++) {
				fscanf(fptr, "%d\t%s\t%03d\t%d\t%d\n", &A2[j].studentID, &A2[j].name, &A2[j].room_no, &A2[j].amountdue, &A2[j].paymentmade);
				if (j == search("A2.txt", studentID)) {
					printf("Amount Due For Student: %d\n", A2[j].amountdue);
					printf("Amount receiving: ");
					scanf("%d", &received);
					A2[j].amountdue = A2[j].amountdue - received;
					A2[j].paymentmade = A2[j].paymentmade + received;
					fprintf(ftemp, "%d\t%s\t%03d\t%d\t%d\n", A2[j].studentID, A2[j].name, A2[j].room_no, A2[j].amountdue, A2[j].paymentmade);
				}
				else
					fprintf(ftemp, "%d\t%s\t%03d\t%d\t%d\n", A2[j].studentID, A2[j].name, A2[j].room_no, A2[j].amountdue, A2[j].paymentmade);
			}

		}

		else {
			printf("\nInvalid student ID\n");
			payment();
		}
		fclose(fptr);
		fclose(ftemp);
		remove("A2.txt");
		rename("temp.txt", "A2.txt");
	}
	else if (strcmp(block, "B2") == 0) {
		if (search("B2.txt", studentID) != 0) {
			fptr = fopen("B2.txt", "r");
			if (fptr == NULL || ftemp == NULL) {
				printf("Error in opening file");
				exit(1);
			}
			for (j = 1; j <= countingBeds("B2.txt"); j++) {
				fscanf(fptr, "%d\t%s\t%03d\t%d\t%d\n", &B2[j].studentID, &B2[j].name, &B2[j].room_no, &B2[j].amountdue, &B2[j].paymentmade);
				if (j == search("B2.txt", studentID)) {
					printf("Amount Due For Student: %d\n", B2[j].amountdue);
					printf("Amount receiving: ");
					scanf("%d", &received);
					B2[j].amountdue = B2[j].amountdue - received;
					B2[j].paymentmade = B2[j].paymentmade + received;
					fprintf(ftemp, "%d\t%s\t%03d\t%d\t%d\n", B2[j].studentID, B2[j].name, B2[j].room_no, B2[j].amountdue, B2[j].paymentmade);
				}
				else
					fprintf(ftemp, "%d\t%s\t%03d\t%d\t%d\n", B2[j].studentID, B2[j].name, B2[j].room_no, B2[j].amountdue, B2[j].paymentmade);
			}
		}
		else {
			printf("\nInvalid student ID\n");
			payment();
		}

		fclose(fptr);
		fclose(ftemp);
		remove("B2.txt");
		rename("temp.txt", "B2.txt");

	}
	else if (strcmp(block, "B4") == 0) {
		if (search("B4.txt", studentID) != 0) {
			fptr = fopen("B4.txt", "r");
			if (fptr == NULL || ftemp == NULL) {
				printf("Error in opening file");
				exit(1);
			}
			for (j = 1; j <= countingBeds("B4.txt"); j++) {
				fscanf(fptr, "%d\t%s\t%03d\t%d\t%d\n", &B4[j].studentID, &B4[j].name, &B4[j].room_no, &B4[j].amountdue, &B4[j].paymentmade);
				if (j == search("B4.txt", studentID)) {
					printf("Amount Due For Student: %d\n", B4[j].amountdue);
					printf("Amount receiving: ");
					scanf("%d", &received);
					B4[j].amountdue = B4[j].amountdue - received;
					B4[j].paymentmade = B4[j].paymentmade + received;
					fprintf(ftemp, "%d\t%s\t%03d\t%d\t%d\n", B4[j].studentID, B4[j].name, B4[j].room_no, B4[j].amountdue, B4[j].paymentmade);
				}
				else
					fprintf(ftemp, "%d\t%s\t%03d\t%d\t%d\n", B4[j].studentID, B4[j].name, B4[j].room_no, B4[j].amountdue, B4[j].paymentmade);
			}
		}
		else {
			printf("\nInvalid student ID\n");
			payment();
		}
		fclose(fptr);
		fclose(ftemp);
		remove("B4.txt");
		rename("temp.txt", "B4.txt");
	}
	else {
		printf("\nInvalid Block. Please Enter a Valid Block.\n");
		payment();
	}
	goback();
}

//function to return back to main menu
void goback() {
	char option[4];
	printf("\n\nReturn to Main Menu?(yes/no): ");
	scanf("%s", &option);
	if (strcmp(option, "yes") == 0 || strcmp(option, "Yes") == 0 || strcmp(option, "y") == 0)
		mainmenu();
	else
		exit(0);
}