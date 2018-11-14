//
// Created by NP-1999 on 11/14/2018.
//
#ifndef BOOKINGHOTEL_ADMIN_H
#define BOOKINGHOTEL_ADMIN_H

#include<stdio.h>
#include<string.h>

void login(char* user,char* pass){
    int check_user = strcmp(user,"Admin"),
        check_pass = strcmp(pass,"rootAdmin");
    if(!(check_user && check_pass)){
        printf("Username or Password is invalid");
        return;
    }
}

#endif //BOOKINGHOTEL_ADMIN_H
