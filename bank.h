//#define NOF_DEPS 10
//#define NOF_WITHS 10
//#define NOF_LOANS 10
//#define NOF_TRANS 10
#define NOF_CUSTS 100
#define NOF_DEPS 100
#define NOF_WITHS 100
#define NOF_LOANS 100
#define NOF_TRANS 100
#define LOAN_INTEREST 0.05
#define NONBLOCKEDACTIVE 1
#define NONBLOCKEDINACTIVE 2
#define BLOCKEDACTIVE 3
#define BLOCKEDINACTIVE 4
#define TRANSACTION_TRANSFER 3
struct loan{
	double originalAmount;
	double interest;
	double repaymentAmount;
	int length;
	int startDay;
	int startMonth;
	int startYear;
	int endDay;
	int endMonth;
	int endYear;
};

struct deposit{
	double amount;
	int day;
	int month;
	int year;
	int type;
	//1 - Cash
	//2 - Cheque
	//3 - Transfer
};

struct withdrawal{
	double amount;
	int day;
	int month;
	int year;
	int type;
	//1 - Cash
	//2 - Cheque
	//3 - Transfer
};

struct transfer{
	double amount;
	int type;
	//1 - Single
	//2 - Recurrent
        int frequency;
        //1 - daily
        //2 - weekly
        //3 - monthly
        //4 - annually 
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
};

struct customer{
	double amount;
	char firstName[25];
	char lastName[25];
	int addressNumber;
	char addressRoadName[50];
	char addressPostCode[10];
	int idType;
	//1 - Passport
	//2 - Drivers Licence
	//3 - Birth Certificate
	//4 - Utility Bill
	//5 - Other
	int status;
	//1 - Unblocked and Active
	//2 - Unblocked and Inactive
	//3 - Blocked and Active
	//4 - Blocked and Inactive
	struct loan listLoans[NOF_DEPS];
	struct deposit listDeposits[NOF_WITHS];
	struct withdrawal listWithdrawals[NOF_LOANS];
	struct transfer listTransfers[NOF_TRANS];
};
