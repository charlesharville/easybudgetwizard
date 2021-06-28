#ifndef HANDLERS_H
#define HANDLERS_H

/* these variables are used in the handler while loop */
int exp_item = 1; /* this is used to represent the current expenditure item in the console, during the loop */
int ctr = 0; /* I plan to use this to count the number of expenditure items user inputs */


void getExpItem(void);
void expItemCounter(void);
void budgetHandler(void);

void getExpItem() {
    
    printf("expenditure item[%d]:$__________\b\b\b\b\b\b\b\b\b\b", exp_item);

}
    
void expItemCounter() {
    
    
    
}
    
void budgetHandler() {
    
    
      while(fgets(expnd, BUFFER, stdin) && total_exp <= net_income) {
        
        expenditure = atof(expnd);
        
        /* handling the budget items ... */
        if (expenditure > 0.00 && total_exp <= net_income && ctr >= 0) {
            
            exp_item++;
            
            total_exp += expenditure; /* accumluates expenditure and stores the sum ... */
            balance = net_income - total_exp; /* here, we subtract total expenditures from user's net income ... */
            total_debt = debt + total_exp - net_income;
            printf("\n\t\t\tyou just spent\\accounted for $%.2f\n", expenditure);
            printf("\t\t\tfor a total monthly expenditure of %.2f [%s]\n", total_exp, &month);
            printf("\t\t\t... your balance is $%.2f.\n\n", balance);
            
            if (balance <= 0.00) {
                printf("###################################################################\n");
                /* TODO: NEED TO IMPLEMENT A PORTABLE METHOD TO SOUND BELL (LINE 57, ...) */
                printf("Summary budget\n");
                printf("\t\a\aTotal expenditures: you spent $%.2f out of a $%.2f budget \nfor the month of %s =====\n",
                       total_exp, net_income, &month);
                printf("\tThat means you're broke, out of dough, strapped for cash, and \npossibly even in amount of debt that follows(!): %.2f\n",
                       debt+total_exp-net_income);
                printf("###################################################################\n");
                ctr++;
                
                break;
            }
            
            /* warn user if they are about to exceed their spending limit */
            
            else if (balance <= savings+5.00) { /* TODO: NEED TO FIX THIS! (continue statement seems ineffective) ... */
                printf("Careful, you're about to dip into your monthly savings [%.2f]!\n", savings);
                getExpItem();
                ctr++;
                
                continue;
            }
            
            else if (balance > savings+0.01) { /* TODO: NEED TO FIX THIS! (continue statement seems ineffective) ... */
                printf("Oh no, you're breaking the piggy bank!\n\n");
                savings-expenditure;
                printf("Your savings are reduced to $%.2f ...\n", savings - expenditure);
                getExpItem();
                ctr++;
                
                continue;
            }
            
        else {
            printf("expenditure item[%d]:$__________\b\b\b\b\b\b\b\b\b\b", exp_item); /* TODO: NEED TO REMOVE THE '\n' PRODUCED BY fgets() */
            ctr++;
            
            continue;
        }
            
        }
            
        else {
            printf("\n\n--------------------------------------------------------------------------------------------------------\n");
            printf("aborting programme with an unknown result!)\n\n");
            break;
        }
    }
}


#endif
