//
// Created by NP-1999 on 11/14/2018.
//

#ifndef BOOKINGHOTEL_ADMIN_H
#define BOOKINGHOTEL_ADMIN_H


#include<stdio.h>
#include<string.h>
#include <stdlib.h>

void seek_to_next_line( void )
{
    int c;
    while( (c = fgetc( stdin )) != EOF && c != '\n' );
}

int check_duplicate(char* filename){
    FILE *file;
    file = fopen("Hotelname.txt","r");
    char buffer[strlen(filename)+1];
    while (fgets(buffer, sizeof(buffer),file)){
        if(strcmp(filename,buffer) == 0)
            return 0;
    }
    return 1;
}

void addHotel(){
    int firstdes =1;
    FILE *hotelfile,*room,*hotel;
    hotelfile = fopen("Hotelname.txt","a");

    char hotelname[255];
    printf("Enter Hotelname :");
    scanf("%[^\n]", hotelname);
    seek_to_next_line();
    if(check_duplicate(hotelname)) {
        strcat(hotelname, "\n");
        fputs(hotelname, hotelfile);
        strtok(hotelname, "\n");
    }
    fclose(hotelfile);

    char *hotel_room = (char*)malloc(sizeof(hotelname));
    hotel_room = hotelname;
    strcat(hotel_room,"_room.txt");
    room = fopen(hotel_room,"a");
    strtok(hotel_room,"_");

    char roomtype[] = "Room Type : ";
    char buffer[255];
    printf("Enter Room Type : ");
    scanf("%s",buffer);
    seek_to_next_line();

    strcat(buffer,".txt\n");
    fputs(buffer,room);
    strtok(buffer,".");
    fclose(room);

    strcat(hotelname,".txt");
    hotel = fopen(hotelname,"a");
    strcat(roomtype,buffer);
    strcat(roomtype,"\n");
    fputs(roomtype,hotel);

    int check = 0;
    do {
        char des[50];
        if(firstdes)
            strcpy(des,"     Description :  ");
        else
            strcpy(des,"                 :  ");
        printf("Enter Description(1 line per 1 option) : ");
        scanf("%[^\n]", buffer);
        seek_to_next_line();

        strcat(buffer, "\n");
        strcat(des, buffer);
        fputs(des, hotel);

        char more;
        printf("Do you want to add more description? (y to add more):");
        scanf("%c",&more);
        seek_to_next_line();

        if(more == 'y') {
            firstdes = 0;
            check = 1;
        }
        else {
            firstdes = 1;
            check = 0;
        }
    }while (check == 1);

    fclose(hotelfile);
    fclose(room);
    fclose(hotel);
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

void login(){
    char user[10],pass[10];
    int check = 0;
    do {
        printf("Enter Username (b to back): ");
        scanf("%s", user);
        if (strcmp(user, "b") == 0)
            return;
        printf("Enter Password: ");
        scanf("%s", pass);
        int check_user = strcmp(user, "Admin"),
                check_pass = strcmp(pass, "rootAdmin");
        if (check_user && check_pass) {
            printf("Username or Password is invalid\n");

        } else {
            menuAdmin();
            check = 1;
        }
    }while(check == 0);
}

#endif //BOOKINGHOTEL_ADMIN_H
