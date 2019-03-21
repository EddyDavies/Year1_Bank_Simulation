#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bank.h"
#include <time.h>  //for the current date 

void examplePeople(struct customer *cust);
void examplePerson(struct customer *cust, int accNum);
void createNewAccount(struct customer *cust, int accNum);
void editAccount(struct customer *cust, int accNum);
void createDeposit(struct customer *cust, int accNum);
void createWithdrawal(struct customer *cust, int accNum);
void createLoan(struct customer *cust, int accNum);
void createTransfer(struct customer *cust, int accNum);
void managementStats(struct customer *cust);
void updateTransfers(struct customer *cust);
void transferDeposit(struct customer *customer, int i, double amount, int type);
void transferWithdrawal(struct customer *customer, int i, double amount, int type);
int check_transfer_date(struct customer *customer, int custID, int transferNO);

 
    struct tm timenow;
    


void main () {
	int accNum, i, mode = 0, finish = 0;
	struct customer cust[NOF_CUSTS];
        time_t t=time(NULL);
        timenow = *localtime(&t);
	for(i=0; i<NOF_CUSTS; i++) { 
 		cust[i].amount = -1;
	}
	examplePeople(cust);
	printf("Welcome to Jasmil Bank \n\n");
        printf("Checking and updating all transfers for today\n");
        updateTransfers(cust);
	
	while(finish != 2) {
		printf("What is your Account Number? (0-%d) ", NOF_CUSTS-1);
		fflush(stdin);
		scanf("%d", &accNum);
		
	
		//Confirm viable account number inputted or error and end program if not.
		if(NOF_CUSTS>accNum && accNum>-1) {
			printf("Account Selected\n");
			
			if(accNum == 0) {
				//managementStats(cust)
			}
			
			//Checks if this is a new account
			if(cust[accNum].amount == -1) {
				createNewAccount(cust, accNum); 
			}
			
			//Asks for input of what the program should do next.
			printf("Welcome %s\n\t", cust[accNum].firstName);
			while(mode != 1 && mode != 2 && mode != 3 && mode != 4 && mode != 5) { //Starts a while loop the runs repatedly until 1, 2 or 3 is chosen.
				printf("\nPlease choose from options below:\n");
				printf("1 - Make a Deposit\n");
				printf("2 - Make a Withdrawal\n");
				printf("3 - Make a Loan\n");
				printf("4 - Create a Transfer\n");
				printf("5 - Edit Account Details\n");
                                printf("6 - Check and update all transfers\n");
				fflush(stdin);	//Clears the buffer before the user enters a value.
				scanf("%d", &mode); 
			}
			//Runs an if statement to run the relevant function.
			if(mode==1){
				createDeposit(cust, accNum);
			}else if (mode==2){
				createWithdrawal(cust, accNum);
			}else if (mode==3){
				createLoan(cust, accNum);
			}else if (mode==4){
				createTransfer(cust, accNum);
			}else if (mode==5){
				editAccount(cust, accNum);
			}
		//Runs an else statement for the situation that an invalid account number is inputted.
		} else {
			printf("Account Number not found.\n\n");
		}
		//Asks for input on whether the program should end or continue
		printf("Would you like to make another transaction?\n");
		printf("1 - Yes \n2 - No\n");
		fflush(stdin);
		scanf("%d", &finish);
		mode = 0;
	}
}

void examplePeople(struct customer *cust){
	int accNum, depNum, withNum;
	//Management Account (0)
	accNum = 0;
	depNum = 1;
	withNum = 1;
	cust[accNum].status = 1;
	cust[accNum].idType = 1;
	strcpy(cust[accNum].firstName, "Admin");
	strcpy(cust[accNum].lastName, "Admin");
	cust[accNum].addressNumber = 1;
	strcpy(cust[accNum].addressRoadName,"Bank Street");
	strcpy(cust[accNum].addressPostCode, "E14 5EE");
	examplePerson(cust, accNum);
	
	//Example Person 1 (1)
	accNum = 1;
	depNum = 2;
	withNum = 2;
	cust[accNum].status = 1;
	cust[accNum].idType = 1;
	strcpy(cust[accNum].firstName, "David");
	strcpy(cust[accNum].lastName, "Smith");
	cust[accNum].addressNumber = 34;
	strcpy(cust[accNum].addressRoadName,"Edinburgh Road");
	strcpy(cust[accNum].addressPostCode, "L7 8RD");
	examplePerson(cust, accNum);
	
	//Example Person 2 (55)
	//accNum = 55;
        accNum++;
	depNum = 3;
	withNum = 3;
	cust[accNum].status = 2;
	cust[accNum].idType = 3;
	strcpy(cust[accNum].firstName, "Joy");
	strcpy(cust[accNum].lastName, "Cross");
	cust[accNum].addressNumber = 27;
	strcpy(cust[accNum].addressRoadName,"Portland Street");
	strcpy(cust[accNum].addressPostCode, "PR8 1HU");
	examplePerson(cust, accNum);
	
	//Example Person 3 (12)
	//accNum = 12;
        accNum++;
	depNum = 4;
	withNum = 4;
	cust[accNum].status = 3;
	cust[accNum].idType = 3;
	strcpy(cust[accNum].firstName, "Jasmine");
	strcpy(cust[accNum].lastName, "Gee");
	cust[accNum].addressNumber = 3;
	strcpy(cust[accNum].addressRoadName,"Rainbow Street");
	strcpy(cust[accNum].addressPostCode, "R31 5JL");
	examplePerson(cust, accNum);
	
	//Example Person 4 (72)
	//accNum = 72;
        accNum++;
	depNum = 5;
	withNum = 5;
	cust[accNum].status = 1;
	cust[accNum].idType = 1;
	strcpy(cust[accNum].firstName, "Barack");
	strcpy(cust[accNum].lastName, "Obama");
	cust[accNum].addressNumber = 30;
	strcpy(cust[accNum].addressRoadName,"Downing Street");
	strcpy(cust[accNum].addressPostCode, "E20 2ST");
	examplePerson(cust, accNum);
	
	//Example Person 5 (99)
	//accNum = 99;
        accNum++;
	depNum = 6;
	withNum = 6;
	cust[accNum].status = 2;
	cust[accNum].idType = 4;
	strcpy(cust[accNum].firstName, "Brad");
	strcpy(cust[accNum].lastName, "Pitt");
	cust[accNum].addressNumber = 72;
	strcpy(cust[accNum].addressRoadName,"Portland Street");
	strcpy(cust[accNum].addressPostCode, "L37 2HG");
	examplePerson(cust, accNum);
	
	//Example Person 6 (32)
	//accNum = 32;
        accNum++;
	depNum = 7;
	withNum = 7;
	cust[accNum].status = 3;
	cust[accNum].idType = 5;
	strcpy(cust[accNum].firstName, "Simon");
	strcpy(cust[accNum].lastName, "Cowell");
	cust[accNum].addressNumber = 126;
	strcpy(cust[accNum].addressRoadName,"Bank Street");
	strcpy(cust[accNum].addressPostCode, "M33 4RL");
	examplePerson(cust, accNum);
	cust[accNum].listWithdrawals[withNum].day = 28;
	cust[accNum].listWithdrawals[withNum].month = 10;
	cust[accNum].listWithdrawals[withNum].year = 2015;
	cust[accNum].amount = 545.58;
	
	//Example Person 7 (19)
	//accNum = 19;
        accNum++;
	depNum = 8;
	withNum = 8;
	cust[accNum].status = 4;
	cust[accNum].idType = 5;
	strcpy(cust[accNum].firstName, "Henry");
	strcpy(cust[accNum].lastName, "Winsor");
	cust[accNum].addressNumber = 3;
	strcpy(cust[accNum].addressRoadName,"Edinburgh Road");
	strcpy(cust[accNum].addressPostCode, "SK9 5UE");
	examplePerson(cust, accNum);
	cust[accNum].listWithdrawals[withNum].day = 8;
	cust[accNum].listWithdrawals[withNum].month = 05;
	cust[accNum].listWithdrawals[withNum].year = 2011;
	cust[accNum].amount = 545.58;
	
	//Example Person 8 (81)
	//accNum = 81;
        accNum++;
	depNum = 9;
	withNum = 9;
	cust[accNum].status = 1;
	cust[accNum].idType = 4;
	strcpy(cust[accNum].firstName, "Justin");
	strcpy(cust[accNum].lastName, "Beiber");
	cust[accNum].addressNumber = 69;
	strcpy(cust[accNum].addressRoadName,"Portland Street");
	strcpy(cust[accNum].addressPostCode, "L3 5UE");
	examplePerson(cust, accNum);
	cust[accNum].listWithdrawals[withNum].day = 01;
	cust[accNum].listWithdrawals[withNum].month = 01;
	cust[accNum].listWithdrawals[withNum].year = 2018;
	cust[accNum].amount = 556.18;

	
	//Example Person 9 (24)
	//accNum = 24;
        accNum++;
	depNum = 10;
	withNum = 10;
	cust[accNum].status = 2;
	cust[accNum].idType = 3;
	strcpy(cust[accNum].firstName, "Robert");
	strcpy(cust[accNum].lastName, "Marley");
	cust[accNum].addressNumber = 41;
	strcpy(cust[accNum].addressRoadName,"Bank Street");
	strcpy(cust[accNum].addressPostCode, "SW3 8VD");
	examplePerson(cust, accNum);
	cust[accNum].listDeposits[depNum].day = 01;
	cust[accNum].listDeposits[depNum].month = 01;
	cust[accNum].listDeposits[depNum].year = 2018;
	cust[accNum].amount = 91.54;
	
	//Example Person 10 (66)
	//accNum = 66;
        accNum++;
	depNum = 11;
	withNum = 11;
	cust[accNum].status = 3;
	cust[accNum].idType = 2;
	strcpy(cust[accNum].firstName, "Kate");
	strcpy(cust[accNum].lastName, "Moss");
	cust[accNum].addressNumber = 15;
	strcpy(cust[accNum].addressRoadName,"Edinburgh Road");
	strcpy(cust[accNum].addressPostCode, "PR7 3NG");
	examplePerson(cust, accNum);
	cust[accNum].listDeposits[depNum].day = 21;
	cust[accNum].listDeposits[depNum].month = 07;
	cust[accNum].listDeposits[depNum].year = 1998;
	cust[accNum].amount = 18;
	
	//Example Person 11 (69)
	//accNum = 69;
        accNum++;
	depNum = 12;
	withNum = 12;
	cust[accNum].status = 4;
	cust[accNum].idType = 1;
	strcpy(cust[accNum].firstName, "Channing");
	strcpy(cust[accNum].lastName, "Tatum");
	cust[accNum].addressNumber = 83;
	strcpy(cust[accNum].addressRoadName,"Portland Street");
	strcpy(cust[accNum].addressPostCode, "M20 2GT");
	examplePerson(cust, accNum);
	cust[accNum].listDeposits[depNum].day = 02;
	cust[accNum].listDeposits[depNum].month = 01;
	cust[accNum].listDeposits[depNum].year = 2017;
	cust[accNum].amount = 115;

}

void examplePerson(struct customer *cust, int accNum){
	int i; 
	cust[accNum].amount = 0;
	for(i=0; i<NOF_DEPS; i++) {
		cust[accNum].listDeposits[i].amount = -1;
	} for(i=0; i<NOF_WITHS; i++) {
		cust[accNum].listWithdrawals[i].amount = -1;
	} for(i=0; i<NOF_LOANS; i++) {
		cust[accNum].listLoans[i].originalAmount = -1;
	} for(i=0; i<NOF_TRANS; i++) {
		cust[accNum].listTransfers[i].amount = -1;
	}
}

void createNewAccount(struct customer *cust, int accNum){
	int i = 0, mode = 0, correct = 0;
	cust[accNum].status = 1;
	//1 - Unblocked and Active
	//2 - Unblocked and Inactive
	//3 - Blocked and Active
	//4 - Blocked and Inactive
		
	while (correct != 1) {
		//Set the account amount to 0 so it is known this is an opened account.
		cust[accNum].amount = 0;
		//Asks for the input of all the essential information about the customer.
		printf("New Account \nPlease enter your first name: \n");
		fflush(stdin);
		scanf("%s", cust[accNum].firstName);
		printf("Please enter your last name: \n");
		fflush(stdin);
		scanf("%s", cust[accNum].lastName);
		printf("Please enter the your address number: \n");
		fflush(stdin);
		scanf("%d", &cust[accNum].addressNumber);
		printf("Please enter your address road name: \n");
		fflush(stdin);
		scanf("%[^\n]%*c", cust[accNum].addressRoadName);
		printf("Please enter your address post code: \n");
		fflush(stdin);
		scanf("%[^\n]%*c", cust[accNum].addressPostCode);
	
		//A number is inputted that refers to the type of identification used.
		while(mode != 1 && mode != 2 && mode != 3 && mode != 4 && mode != 5) {//Starts a while loop the runs repatedly until 1, 2 or 3 is chosen.
			printf("Please choose the form of Idetification you have:\n");
			printf("1 - Passport\n");
			printf("2 - Drivers Licence\n");
			printf("3 - Birth Certificate\n");
			printf("4 - Utility Bill\n");
			printf("5 - Other\n");
			fflush(stdin);	//Clears the buffer before the user enters a value.
			scanf("%d", &mode);
		}	
		cust[accNum].idType = mode;
			
		//This prints all the information inputted about the customer and saved in the array.
		printf("Name: %s %s\n", cust[accNum].firstName, cust[accNum].lastName);
		printf("Address %d %s %s:\n", cust[accNum].addressNumber, cust[accNum].addressRoadName, cust[accNum].addressPostCode);
		printf("Idetification: Type %d\n", cust[accNum].idType);
		printf("Account Status: Unblocked and Active (Default Status)\n\n");
	
		printf("Are all these details correct?\n");
		printf("1 - Yes \n2 - No\n");
		fflush(stdin);
		scanf("%d", &correct);
	}
		
	//Here I run a for loop that sets the amount as -1 for each of the indexs in each of the structure arrays created.
	//This is so unused indexs have an amount of -1, this can be checked for and then the first free index used.
	for(i=0; i<NOF_DEPS; i++) {
		cust[accNum].listDeposits[i].amount = -1;
	} for(i=0; i<NOF_WITHS; i++) {
		cust[accNum].listWithdrawals[i].amount = -1;
	} for(i=0; i<NOF_LOANS; i++) {
		cust[accNum].listLoans[i].originalAmount = -1;
	} for(i=0; i<NOF_TRANS; i++) {
		cust[accNum].listTransfers[i].amount = -1;
	}
}

void editAccount(struct customer *cust, int accNum){
	
	int i = 0, mode = 0, mode2 = 0, correct = 0;
	while (correct != 1) {
		//A number is inputted that refers to what the user wants to edit.
		while(mode != 1 && mode != 2 && mode != 3 && mode != 4) {//Starts a while loop the runs repatedly until 1, 2 or 3 is chosen.
			printf("Please choose the form of Idetification you have:\n");
			printf("1 - Name\n");
			printf("2 - Address\n");
			printf("3 - Account Status\n");
			printf("4 - Identification Type\n");
			fflush(stdin);	//Clears the buffer before the user enters a value.
			scanf("%d", &mode);
		}
		
		if(mode==1){
			
		printf("New Account \nPlease enter your first name: \n");
		fflush(stdin);
		scanf("%s", cust[accNum].firstName);
		printf("Please enter your last name: \n");
		fflush(stdin);
			
		}else if (mode==2){
			scanf("%s", cust[accNum].lastName);
			printf("Please enter the your address number: \n");
			fflush(stdin);
			scanf("%d", &cust[accNum].addressNumber);
			printf("Please enter your address road name: \n");
			fflush(stdin);
			scanf("%[^\n]%*c", cust[accNum].addressRoadName);
			printf("Please enter your address post code: \n");
			fflush(stdin);
			scanf("%[^\n]%*c", cust[accNum].addressPostCode);
			
		}else if (mode==3){	
			while(mode2 != 1 && mode2 != 2 && mode2 != 3 && mode2 != 4) {//Starts a while loop the runs repatedly until 1, 2 or 3 is chosen.
				printf("Please choose the form of Idetification you have:\n");
				printf("1 - Unblocked and Active\n");
				printf("2 - Unblocked and Inactive\n");
				printf("3 - Blocked and Active\n");
				printf("4 - Blocked and Inactive\n");
				fflush(stdin);	//Clears the buffer before the user enters a value.
				scanf("%d", &mode2);
			}	
			cust[accNum].status = mode2;
			//Set the status as the number refering to the type chosen by the user.

		}else if (mode==4){
			//A number is inputted that refers to the type of identification used.
			while(mode2 != 1 && mode2 != 2 && mode2 != 3 && mode2 != 4 && mode2 != 5) {//Starts a while loop the runs repatedly until 1, 2 or 3 is chosen.
				printf("Please choose the form of Idetification you have:\n");
				printf("1 - Passport\n");
				printf("2 - Drivers Licence\n");
				printf("3 - Birth Certificate\n");
				printf("4 - Utility Bill\n");
				printf("5 - Other\n");
				fflush(stdin);	//Clears the buffer before the user enters a value.
				scanf("%d", &mode2);
			}	
			cust[accNum].idType = mode;
		}
			
		//This prints all the information inputted about the customer and saved in the array.
		printf("Name: %s %s\n", cust[accNum].firstName, cust[accNum].lastName);
		printf("Address %d %s %s:\n", cust[accNum].addressNumber, cust[accNum].addressRoadName, cust[accNum].addressPostCode);
		printf("Idetification: Type %d\n", cust[accNum].idType);
		
		if(cust[accNum].status==1){
			printf("Account Status: Unblocked and Active\n\n");
		}else if (cust[accNum].status==2){
			printf("Account Status: Unblocked and Inactive\n\n");
		}else if (cust[accNum].status==3){
			printf("Account Status: Blocked and Active\n\n");
		}else if (cust[accNum].status==4){
			printf("Account Status: Blocked and Inactive\n\n");
		}
		
		printf("Are all these details now correct?\n");
		printf("1 - Yes \n2 - No\n");
		fflush(stdin);
		scanf("%d", &correct);
	}
}

void createLoan(struct customer *cust, int accNum) {
	int i;
	
	for(i=0; i<NOF_LOANS; i++){
		if (cust[accNum].listLoans[i].originalAmount== -1){
			break;
		} 
	}
	
	//Ask for the input of all the data about the loan.
	printf("\nWhat was the amount of the initial loan?\n");
	fflush(stdin);
	scanf("%d", &cust[accNum].listLoans[i].originalAmount);
	printf("\nWhat was the start day of the loan\n");
	fflush(stdin);
	scanf("%d", &cust[accNum].listLoans[i].startDay);
	printf("\nWhat was the start month of the loan\n");
	fflush(stdin);
	scanf("%d", &cust[accNum].listLoans[i].startMonth);
	printf("\nWhat was the start year of the loan\n");
	fflush(stdin);
	scanf("%d", &cust[accNum].listLoans[i].startYear);
	printf("\nWhat was the end day of the loan\n");
	fflush(stdin);
	scanf("%d", &cust[accNum].listLoans[i].endDay);
	printf("\nWhat was the end month of the loan\n");
	fflush(stdin);
	scanf("%d", &cust[accNum].listLoans[i].endMonth);
	printf("\nWhat was the end year of the loan\n");
	fflush(stdin);
	scanf("%d", &cust[accNum].listLoans[i].endYear);

	//Finds the length of the loan in months
	cust[accNum].listLoans[i].length = (cust[accNum].listLoans[i].endMonth - cust[accNum].listLoans[i].startMonth) 
	+ ((cust[accNum].listLoans[i].endYear - cust[accNum].listLoans[i].startYear) * 12) ;
	printf("\nLength of loan: %d", &cust[accNum].listLoans[i].length);
	//Finds the interest of the loan initially taken out
	cust[accNum].listLoans[i].interest = cust[accNum].listLoans[i].length * LOAN_INTEREST * cust[accNum].listLoans[i].originalAmount;
	printf("\nInterest of loan: %d", &cust[accNum].listLoans[i].interest);
	//Calculates the repayment amount
	cust[accNum].listLoans[i].repaymentAmount = cust[accNum].listLoans[i].originalAmount * cust[accNum].listLoans[i].interest;
	printf("\nRepayment amount: %d", &cust[accNum].listLoans[i].repaymentAmount);
}

void createDeposit(struct customer *cust, int accNum) {
	
	int i;
	
	for(i=0; i<NOF_DEPS; i++){
		if (cust[accNum].listDeposits[i].amount== -1){
			break;
		} 
	}
	
	
	printf("\nThe current balance for the account %d is %.2f \n", accNum, cust[accNum].amount);
	
	//Gets the date of the transaction
	printf("\nPlease enter the day for the deposit in number form (E.g. 16) \n");
	fflush(stdin);
	scanf("%d", &cust[accNum].listDeposits[i].day);
	printf("\nPlease enter the month for the deposit in number form (E.g. 01) \n");
	fflush(stdin);
	scanf("%d", &cust[accNum].listDeposits[i].month);
	printf("\nPlease enter the year for the deposit in number form (E.g. 2018) \n");
	fflush(stdin);
	scanf("%d", &cust[accNum].listDeposits[i].year);
	
	//Gets the amount to deposit
	printf("\nEnter the amount of money you wish to deposit:\n");
	fflush(stdin);
	scanf("%f",  &cust[accNum].listDeposits[i].amount);
	cust[accNum].amount = cust[accNum].listDeposits[i].amount+cust[accNum].amount;
	
	//Gets the transaction type 
	printf("\nEnter the type of transaction you wish to do to deposit the money");
	printf("\n 1 - Cash");	
	printf("\n 2 - Cheque");
	printf("\n 3 - Transfer\n");
	fflush(stdin); 
	scanf("%f", &cust[accNum].listDeposits[i].type );

	printf("Change implemented.\n");
}


void createWithdrawal(struct customer *cust, int accNum) {
		int i; double withdrawal;
	
	for(i=0; i<NOF_WITHS; i++){
		if (cust[accNum].listWithdrawals[i].amount== -1){
			break;
		} 
	}
	
	
	printf("\nThe current balance for the account %d is %.2f \n", accNum, cust[accNum].amount);
	
	//Gets the date of the transaction
	printf("\nPlease enter the day for the withdrawal in number form (E.g. 16) \n");
	fflush(stdin);
	scanf("%d", &cust[accNum].listWithdrawals[i].day);
	printf("\nPlease enter the month for the withdrawal in number form (E.g. 01) \n");
	fflush(stdin);
	scanf("%d", &cust[accNum].listWithdrawals[i].month);
	printf("\nPlease enter the year for the withdrawal in number form (E.g. 2018) \n");
	fflush(stdin);
	scanf("%d", &cust[accNum].listWithdrawals[i].year);
	
	//Gets the amount to deposit
	printf("\nEnter the amount of money you wish to deposit:\n");
	fflush(stdin);
	scanf("%f", &cust[accNum].listWithdrawals[i].amount);
	cust[accNum].amount = cust[accNum].amount - cust[accNum].listWithdrawals[i].amount;
	
	//Gets the transaction type 
	printf("\nEnter the type of transaction you wish to do to deposit the money");
	printf("\n 1 - Cash");	
	printf("\n 2 - Cheque");
	printf("\n 3 - Transfer \n");
	fflush(stdin); 
	scanf("%d", &cust[accNum].listWithdrawals[i].type );

	printf("Change implemented.\n");
}



void managementStats(struct customer *cust){
	printf("Management Statistics");
	printf("Not Found, code not implemented yet.");	
	
}

void createTransfer(struct customer *customer, int custID)
{
    
    double amount;
    int type;
    int frequency;
    int setDay;
    int setMonth;
    int setYear;
    int startDay;
    int startMonth;
    int startYear;
    int endDay;
    int endMonth;
    int endYear;
    int dstCustindex;
    int transferNO=0;
    
    while(customer[custID].listTransfers[transferNO].amount!=-1)
    {
        transferNO++;
    
    }
    
    printf("How much would you like to transfer? ");
    fflush(stdin);	//Clears the buffer before the user enters a value.
    scanf("%d", &customer[custID].listTransfers[transferNO].amount);
    
    printf("What is the account number of the recipient? ");
    fflush(stdin);	//Clears the buffer before the user enters a value.
    scanf("%d", &customer[custID].listTransfers[transferNO].dstCustindex);
    
    printf("Is this is single or recurrent transfer?"
            "1 - single"
            "2 - recurrent ");
    fflush(stdin);	//Clears the buffer before the user enters a value.
    scanf("%d", &customer[custID].listTransfers[transferNO].type);
    
    if (customer[custID].listTransfers[transferNO].type==2){
    printf("What is the frequency of transfer?"
            "1 - daily"
            "2 - monthly"
            "3 - annually ");
    fflush(stdin);	//Clears the buffer before the user enters a value.
    scanf("%d", &customer[custID].listTransfers[transferNO].frequency);
    }
    
     printf("What is the start day of the transfer? ");
    fflush(stdin);	//Clears the buffer before the user enters a value.
    scanf("%d", &customer[custID].listTransfers[transferNO].startDay);
    
     printf("What is the start month of the transfer? ");
    fflush(stdin);	//Clears the buffer before the user enters a value.
    scanf("%d", &customer[custID].listTransfers[transferNO].startMonth);
    
     printf("What is the start year of the transfer? ");
    fflush(stdin);	//Clears the buffer before the user enters a value.
    scanf("%d", &customer[custID].listTransfers[transferNO].startYear);
    
    if (customer[custID].listTransfers[transferNO].type==2){
         printf("What is the end day of the transfer? ");
    fflush(stdin);	//Clears the buffer before the user enters a value.
    scanf("%d", &customer[custID].listTransfers[transferNO].endDay);
    
     printf("What is the end month of the transfer? ");
    fflush(stdin);	//Clears the buffer before the user enters a value.
    scanf("%d", &customer[custID].listTransfers[transferNO].endMonth);
    
     printf("What is the end year of the transfer? ");
    fflush(stdin);	//Clears the buffer before the user enters a value.
    scanf("%d", &customer[custID].listTransfers[transferNO].endYear);
    }
    
    
    //ask for account number
    //collect transfer details
    //printf("4 - Account Status\n");
        //fflush(stdin);	//Clears the buffer before the user enters a value.
        //scanf("%d", &amount);
        //customer[custID].listTransfers[].amount=amount
        //while(customer[custID].listTransfers[j].amount!=-1){   //find the first unused withdrawal
        //j++;
   // }
}

void updateTransfers(struct customer *customer) {
    //function performs transfers and returns status
    //status returned is equal to 
    //0=transfers completed
    int destination_customer_index;
    int i=0;
    int t=0;
    while(customer[i].amount!=-1) //accounts with negative id are not in use
    { 
        if (customer[i].status==NONBLOCKEDACTIVE){
            while (customer[i].listTransfers[t].amount!=-1){
                if(check_transfer_date(customer, i, t)==1){
                    //transfer is due, check does customer have enough money in account
                    if (customer[i].listTransfers[t].amount<=customer[i].amount){
                        //there is enough money for a transfer so check destination account
                        destination_customer_index = customer[i].listTransfers[t].dstCustindex;
                        if (customer[destination_customer_index].status == NONBLOCKEDACTIVE){
                            transferWithdrawal(customer, i, customer[i].listTransfers[t].amount, TRANSACTION_TRANSFER);
                            transferDeposit(customer, destination_customer_index, customer[i].listTransfers[t].amount, TRANSACTION_TRANSFER);
                        } 
                    }
                }
               t++;         
            }
        }
        i++; //go to next customer
    }
    
}

void transferWithdrawal(struct customer *customer, int i, double amount, int type)
//takes customer index and amount of withdrawal
//it creates a withdrawal entry
{
    
    // for every entry in list withdrawals
    //if withdrawal amount is -1 then create new withdrawal
    int j=0;
    while(customer[i].listWithdrawals[j].amount!=-1){   //find the first unused withdrawal
        j++;
    }
   
    customer[i].listWithdrawals[j].amount=amount;		// Created a withdrawal in your customer
    customer[i].listWithdrawals[j].type=type;			// transfer
    customer[i].listWithdrawals[j].day= timenow.tm_mday;
    customer[i].listWithdrawals[j].month=timenow.tm_mon;
    customer[i].listWithdrawals[j].year=timenow.tm_year;
    
    customer[i].amount=customer[i].amount-amount;   //debit customer's account
}

void transferDeposit(struct customer *customer, int i, double amount, int type)
{
    int j=0;
    while(customer[i].listDeposits[j].amount!=-1){   //find the first unused deposit
        j++;
    }
    customer[i].listDeposits[j].amount=amount;		// Created a deposit in your customer
    customer[i].listDeposits[j].type=type;			// transfer
    customer[i].listDeposits[j].day= timenow.tm_mday;
    customer[i].listDeposits[j].month=timenow.tm_mon;
    customer[i].listDeposits[j].year=timenow.tm_year;
    
    customer[i].amount+=amount;                 //updates customer's balance


}

int check_transfer_date(struct customer *customer, int custID, int transferNO){ //this function returns 1 if a transfer is due today
//while (next_transfer<enddate){ next_transfer=start_date+frequency 
//next_transfer_month=start_month + 1
  // if (next_transfer_month ==13){next_transfer_month=1; next_transfer_year=startYear+1;}
   
    
    int startDay=customer[custID].listTransfers[transferNO].startDay;
    int startMonth=customer[custID].listTransfers[transferNO].startMonth;
    int startYear=customer[custID].listTransfers[transferNO].startYear;
    int endDay=customer[custID].listTransfers[transferNO].endDay;
    int endMonth=customer[custID].listTransfers[transferNO].endMonth;
    int endYear=customer[custID].listTransfers[transferNO].endYear;
    
    int current_day;
    int current_month;
    int current_year;
    
    int next_transfer_day;
    int next_transfer_month;
    int next_transfer_year;
    int transfer_due=0;
    
    int number_of_days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
   
    current_day = timenow.tm_mday;
    current_month = timenow.tm_mon;
    current_year = timenow.tm_year;
    
    
    next_transfer_day=startDay;
    next_transfer_month=startMonth;
    next_transfer_year=startYear;
    
    while (next_transfer_year<endYear ||
            (next_transfer_year==endYear)&&(next_transfer_month<endMonth) ||
            (next_transfer_year==endYear)&&(next_transfer_month==endMonth)&&(next_transfer_day<endDay)
            ){
        
        if ((next_transfer_day==current_day)&&(next_transfer_month==current_month)&&(next_transfer_year==current_year)){
            transfer_due=1;
        }

        switch(customer[custID].listTransfers[transferNO].frequency){
            case 1://daily
                next_transfer_day=startDay+1;
                if (next_transfer_day==number_of_days[next_transfer_month]){
                    next_transfer_day=1;
                    next_transfer_month++;
                    next_transfer_year=startYear;
                    if (next_transfer_month ==13){next_transfer_month=1; next_transfer_year=startYear+1;}         
                }
            break;
            case 2: //monthly
                next_transfer_day=startDay;
                next_transfer_month=startMonth + 1;
                next_transfer_year=startYear;
                if (next_transfer_month ==13){next_transfer_month=1; next_transfer_year=startYear+1;}
            break;
            case 3: //yearly
                next_transfer_day=startDay;
                next_transfer_month=startMonth;
                next_transfer_year=startYear + 1;
            break;
            default: //if none of them match
            break;


        }
    
    }
    
    return(transfer_due);
}



