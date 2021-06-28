#ifndef CURRENCY_H
#define CURRENCY_H

int currency_choice; /* holds choice of currency */
char currsign; /* stores a single character currency sign */
char euro[] = { 0xE2, 0x82, 0xAC, 0x00 }


int getCurrency(int currency);

int getCurrency(int currency) {

    do {
        printf("What is your currency?\n");
        printf("1) USD [$] 2) CAD [$] 3) AUD [$] 4) GBP [£] 5) EUR [€]\n");
        printf("_\b");
        
        char curr_chc[BUFFER];
    
        fgets(curr_chc, BUFFER, stdin);
        currency_choice = atoi(curr_chc);
    
        switch (currency_choice)
        { 
            case (0) : currsign = '$'; /* default currency sign */
            break;

            case (1) : currsign = '$';
            break;
            
            case (2) : currsign = '$';
            break;
            
            case (3) : currsign = u8"£"; /* TODO: NEED TO RESVOLVE THE -Wint-conversion warning ... */
            break;
            
            case (4) : /* (wchar_t)*/ currsign = 0xAC; /* TODO: NEED TO RESVOLVE THE -Wmultichar warning ... */
            break;
        
            /* TODO: NEED TO RESVOLVE THE -Woverflow warning ... */
        }
    }
    while ((currency_choice != 0) && (currency_choice != 1)
                                  && (currency_choice != 2)
                                  && (currency_choice != 3)
                                  && (currency_choice != 4)
                                  && (currency_choice != 5));
    
    return currency_choice;
    
}

#endif
