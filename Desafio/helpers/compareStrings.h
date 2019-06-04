#ifndef COMPARE_STRINGS_H_INCLUDED
#define COMPARE_STRINGS_H_INCLUDED

int areEqual(char *firstString, char *secondString){
    int result = 0;
    int i = 0;
    for(i; firstString[i] != '\0' ||secondString[i] != '\0'; i++){
        if(firstString[i] != secondString[i]){
            result = 0; // The strings are different
            break;
        }
        else{
            result = 1; // The strings are equal
        }
    }
    return result;
}
#endif // COMPARE_STRINGS_H_INCLUDED
