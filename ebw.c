/*
    <EasyBudgetWizard, a simple monthly budget maker>
    Copyright (C) <2021>  <Charles Harville>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

    If you wish to contact the author of this programme, I can be reached
    on Sourceforge or Github:
        sourceforge.com/charv
        github.com/charlesharville

*/

#include <stdio.h>
#include <stdlib.h>

#include "headers/title.h"
#include "headers/wizard.h"
#include "headers/handlers.h"

/********************************************************************************************************************************************************
/* TODO: NEED TO ADD MONTH SELECT FEATURE ... done ! */

/* TODO: NEED TO ORGANIZE PROGRAMME INTO SEVERAL DIFFERENT FUNCTIONS */
/* TODO: NEED TO ADD FILE OUTPUT FUNCTIONALITY, SO THAT BUDGETS CAN BE PRINTED IN HARDCOPY */
/* TODO: NEED TO ADD A SAVINGS PROMPT AFTER THE ONE FOR INCOME, SO THAT EXPENDITURES CANNOT EXCEED income - savings ... */
/* TODO: NEED TO ADD A CURRENCY SELECT FEATURE */
/* TODO: NEED TO ADD TOTAL SAVINGS CALCULATION FEATURE */
/* TODO: NEED TO FIX THE DEBT AND SAVINGS CALCS */


int main(void) {
    
    /* show title screen */
    displayTitle();
    
    /* get the currency
    getCurrency(currency_choice);
     */
    
    /* get month ... */
    getMonth();
    
    /* get income for this month ... */
    getIncome();
    
    /* get savings ... */
    getSavings();
    
    /* get debts ... */
    getDebt();
    
    /* get net income */
    
    /* get each expenditure item ... */
    getExpItem();
    
    /* handle the budget through a while loop ... */
    budgetHandler();
    
    /* calculate and print up the final balance for the month ... */
    getFinalBalance();
    
	return 0;
    
}

