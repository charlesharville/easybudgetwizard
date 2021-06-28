#ifndef TITLE_H /* if TITLE_H is not defined, */
#define TITLE_H /* we define it here. This is to prevent the header from compiling more than once;
                we could also use the non-standard preprocessor directive #pragma once. */

#define TITLE_BUFFER 8192 /* Here, we define the constant BUFFER to a maximum of 8192 bytes.
                            This is more than enough to handle all the characters used in the
                            title screen text. */

/* NOT IMPLEMENTED YET, AND MIGHT NEVER BE(!): #include "titleprompt.h" for definition of int titlePrompt(void) */

void displayTitle(void);

void displayTitle(void) {
 
        FILE *p_title;
        FILE *perr;
        int r;
        // int err;
    
    p_title = fopen("displays/title.txt", "r");
    
    if (p_title == NULL) {
        printf("Cannot open file ... \n\n returning to system ... \n----------------------------\n");
        
        perr = fopen("errorlog.txt", "a+");
        fprintf(perr, "\nError! Could not find file. Make sure that it exists and is in the proper directory.\n");
        
        fclose(perr);
        
        exit(EXIT_FAILURE);
    }

        else if (p_title) {

        printf("Earth is third planet in a system orbiting Sol, or the Sun, a yellow dwarf* star.\n\n");
        
        while ((r = getc(p_title)) != EOF)
        putchar(r);
        
        fclose(p_title);
        }
        
}

#endif /* TITLE_H */
