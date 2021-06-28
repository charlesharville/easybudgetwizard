#ifndef WIZARD_H
#define WIZARD_H

#define BUFFER 64

/* #include "currency.h" TODO: NEED TO COMPLETE THE CURRENECY SELECT FEATURE, AS OF 05.04.2021 THERE IS AN ISSUE WITH GETTING SOME CURRENECY SYMBOLS TO DISPLAY CORRECTLY ... */

    float gross_income; /* this is income before savings and debts, etc. */
    float net_income; /* this is spendable income ... */
    float expenditure; /* stores single expenditure ... for each pass of the while loop below. */
    float total_exp; /* stores total expenditures ... */
    float balance; /* stores balance ... */
    float savings; /* stores savings, calculated from balance and total_exp ... */
    float total_savings; /* stores savings gathered from other months, or manually input by user ... */
    float debt; /* stores amount of debt already outstanding accumulated after  */
    float total_debt; /* stores amount of outstanding debt + that which accumulated during the course of the month ... */
    char month[BUFFER]; /* character array holding input for month name */
    char grs_incme[BUFFER]; /* character array holding input for float income passed to atof(see below) */
    char expnd[BUFFER]; /* character array holding input for float expenditure passed to atof(see below) */
    char svngs[BUFFER]; /* character array holding input for float savings passed to atof(see below) */
    char otsdt[BUFFER]; /* character array holding input for float debt (otsdt == outstanding debt) passed to atof(see below) */

void getMonth(void);
void getIncome(void);
void getSavings(void);
void getDebt(void);
void getNetIncome(void);
void getFinalBalance(void);

void getMonth() {
    
    printf("What is the month (for the budget you wish to make):_________\b\b\b\b\b\b\b\b\b");
    fgets(month, BUFFER, stdin);
    
}

void getIncome() {
    
    printf("what is your gross income:%c________\b\b\b\b\b\b\b\b" /* ,currsign */);
    fgets(grs_incme, BUFFER, stdin);
    gross_income = atof(grs_incme);
    printf("You are budgeting for the month of %s with a gross income of %c%.2f\n\n", &month /*, currsign */, gross_income);
    
}

void getSavings() {
    
    printf("How much do you want to save this %s(?):%c________\b\b\b\b\b\b\b\b", &month /*, currsign */);
    fgets(svngs, BUFFER, stdin);
    savings = atof(svngs);
    
}

void getDebt() {
    
    printf("How much outstanding debt do you have(?):$________\b\b\b\b\b\b\b\b");
    fgets(otsdt, BUFFER, stdin);
    debt = atof(otsdt);
    
}

void getNetIncome() {
    
    net_income = gross_income - savings+debt; /* now income is reduced by however much user sets aside for savings ... */
    
}

void getFinalBalance() {
    
    printf("\t\t ===== Your final balance: %.2f\n\n", balance);
    printf("\t\t ===== Your savings for the month: %.2f\n\n", savings);
    
    if (balance < 0.00) {
        
        printf("===== Your debt at the start of the month: %.2f\n\n", debt);
        printf("\t\t ===== Your total debt: %.2f\n\n", total_debt);
        printf("\t\t Shall I formulate a payment plan so you can pay this off? y\\n ..."); /* not implemented yet TODO: CREATE DEBT PAYMENT FORMULATION WIZARD ... */
        
    }
    
}
    
#endif
