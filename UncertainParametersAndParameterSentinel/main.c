//
//  main.c
//  UncertainParametersAndParameterSentinel
//
//  Created by llc on 15/2/12.
//  Copyright (c) 2015年 llc. All rights reserved.
//

#include <stdio.h>
#include <stdarg.h>

int addemUp(int firstNum,...);
void printStrings(char * first,...) __attribute__((sentinel));


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int sumbody0 = addemUp(1,2,3,4,5,6,7,8,9,0);
    printf("sum of 1...9 is %d \n",sumbody0);
    int sumbody1 = addemUp(1,2,3,0);
    printf("sum of 1,2,3 is %d \n",sumbody1);
    int sumbody2 = addemUp(1,2,3,4,5,6,7,8,9,10,11,0);
    printf("sum of 1...11 is %d \n",sumbody2);
    
    printStrings(" spicy"," pony"," head",NULL);
    printStrings("machine ","tool", NULL);
    return 0;
}

/* In C and Objective-C , How to write a function with variable number of arguments  such as printf ,Can receive a plurality of input parameters。
A reliable solution is to use the functions provided by the stdarg.h. Examples are as follows:      */

int addemUp(int firstNum,...){
 va_list args;
 int sum = firstNum;
 int number;
 va_start(args, firstNum);
 while (1) {
 number = va_arg(args, int);
 sum += number;
 if (number == 0) {
 break;
 }
 }
 va_end(args);
 return sum;
 }

/*
 Among them, the key functions are va_start (), va_arg (), va_end (), you also need to declare a variable of type va_list to store all parameters. Program to 0 for the identity, said that it has no parameters.
 */


/*
So Sentinel arguments came out. In the example above, the last parameter 0 is a sentinel parameter, its role is to tell the function has no parameters. This is why ObjC in [NSArray arrayWithObjects: ..., nil] finally have reason to nil at the end of the parameter.
Use __attribute __ ((sentinel)) syntax can tell the compiler which is a function of a need for sentinel parameters, such as:
 */
void printStrings(char * first,...){
    va_list args;
    va_start(args, first);
    char * string = first;
    while (string != NULL) {
        printf("%s",string);
        string = va_arg(args, char *);
    }
    va_end(args);
    printf("\n");
}


/*NS_REQUIRES_NIL_TERMINATION Cocoa programmers can use to get the same effect:
 - (Void) functionName: (id) memb1, ... NS_REQUIRES_NIL_TERMINATION;
 Represents the last parameter to nil at the end.*/






