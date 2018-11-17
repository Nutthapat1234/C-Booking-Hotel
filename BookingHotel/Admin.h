//
// Created by NP-1999 on 11/14/2018.
//

#ifndef BOOKINGHOTEL_ADMIN_H
#define BOOKINGHOTEL_ADMIN_H

#include<stdio.h>
#include<string.h>

void addHotel(){
    FILE *file;
    char hotelname[255];
    printf("Enter Hotelname :");
    scanf("%s",hotelname);
    strcat(hotelname,".txt");
    file = fopen(hotelname,"w");


    char roomtype[] = "Room Type : ";
    char buffer[255];
    printf("Enter Room Type : ");
    scanf("%s",buffer);
    strcat(roomtype,buffer);
    fputs(roomtype,file);
    char des[] = "     Description :  ";
    char more;

    printf("Enter Description(1 line per 1 option) : "); //for beautiful format
    scanf("%s",buffer);
    strcat(buffer,"\n");
    strcat(des,buffer);
    fputs(des,file);

    do {
        printf("Do you want to add more description? (y to add more):");
        scanf("%c",&more);
    }while(more == 'y');

    fclose(file);
}

void menuAdmin(){
    int command , check = 0;
    do {
        printf("1.Adding Hotel\n");
        printf("2.Check out\n");
        printf("3.Back\n");
        printf("Enter the number of command :");
        scanf("%d", &command);
        if(command == 1)
            addHotel();
        else if(command == 2);
//            checkout();
        else if(command == 3)
            check = 1;
        else
            printf("Invalid command!!!");
    }while(check == 0);

}

void login(char* user,char* pass){
    int check_user = strcmp(user,"Admin"),
            check_pass = strcmp(pass,"rootAdmin");
    if(check_user && check_pass){
        printf("Username or Password is invalid\n");
        return;
    }
    else
        menuAdmin();
}

#endif //BOOKINGHOTEL_ADMIN_H
