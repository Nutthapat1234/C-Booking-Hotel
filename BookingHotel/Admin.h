//
// Created by NP-1999 on 11/14/2018.
//

#ifndef BOOKINGHOTEL_ADMIN_H
#define BOOKINGHOTEL_ADMIN_H


#include<stdio.h>
#include<string.h>
#include <stdlib.h>

typedef struct customer_buffer{
    char name[50];
    char phone[50];
    char date[50];
    char room[50];
    char price[50];
    struct customer_buffer* next;
}cus;

void seek_to_next_line( void )
{
    int c;
    while( (c = fgetc( stdin )) != EOF && c != '\n' );
}

void checkout(){
    char room[10],name[25];
    printf("Enter room to check out: ");
    scanf("%s",room);
    seek_to_next_line();

    printf("Enter customer name:");
    scanf("%s",name);
    seek_to_next_line();

    FILE *cuFile;
    cus *bufferFile;
    cus *b1;
    int check_first = 1;
    char buffer[255];
    cuFile = fopen("Customer.txt","r");
    char bname[10],bphone[10],bdate[10],broom[10],bprice[10];
    while(fscanf(cuFile,"%s : %s : %s : %s : %s",bname,bphone,bdate,broom,bprice) != EOF){
        cus * scan_buffer = (cus*)malloc(sizeof(cus));
        strcpy(scan_buffer->name,"");
        strcat(scan_buffer->name,bname);

        strcpy(scan_buffer->phone,"");
        strcat(scan_buffer->phone,bphone);

        strcpy(scan_buffer->date,"");
        strcat(scan_buffer->date,bdate);

        strcpy(scan_buffer->room,"");
        strcat(scan_buffer->room,broom);

        strcpy(scan_buffer->price,"");
        strcat(scan_buffer->price,bprice);

        scan_buffer->next = NULL;

        if(check_first){
            b1 = scan_buffer;
            bufferFile = scan_buffer;
            check_first = 0;
        }
        else{
            b1->next = scan_buffer;
            b1 = b1->next;
        }
    }

    fseek(cuFile,0,SEEK_SET);
    fclose(cuFile);
    cuFile = fopen("Customer.txt","w");

    while(bufferFile != NULL){
        strcmp(bufferFile->name,name);
        strcmp(bufferFile->room,room);
        if(strcmp(bufferFile->name,name) == 0 && strcmp(bufferFile->room,room) == 0){
            bufferFile = bufferFile->next;
            continue;
        }
        else{
            char sub[255] = "";
            strcat(sub,bufferFile->name);
            strcat(sub," : ");
            strcat(sub,bufferFile->phone);
            strcat(sub," : ");
            strcat(sub,bufferFile->date);
            strcat(sub," : ");
            strcat(sub,bufferFile->room);
            strcat(sub," : ");
            strcat(sub,bufferFile->price);
            strcat(sub,"\n");
            fputs(sub,cuFile);
        }

        bufferFile = bufferFile->next;
    }
    fclose(cuFile);
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
    scanf("%s", hotelname);
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

    char moreRoom;

    do{
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
            printf("You entered %c\n",more);

            if(more == 'y') {
                firstdes = 0;
                check = 1;
            }
            else {
                firstdes = 1;
                check = 0;
            }
        }while (check == 1);

        char people[] = "     People suggest: ";
        char detail[255];
        printf("Enter people suggest: ");
        scanf("%s",detail);
        seek_to_next_line();
        strcat(detail,"\n");
        strcat(people,detail);
        fputs(people,room);

        char price[] = "     Price: ";
        char p[10];
        printf("Enter the price :");
        scanf("%s",p);
        seek_to_next_line();

        strcat(p,"\n");
        strcat(price,p);
        fputs(price,room);

        char sroom[10];
        printf("Enter strating room number: ");
        scanf("%s",sroom);
        seek_to_next_line();


        printf("Do you want to add more room type(y to add): ");
        scanf("%c",&moreRoom);
        seek_to_next_line();
        printf("You entered %c\n",moreRoom);
    }while (moreRoom == 'y');

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
        else if(command == 2)
            checkout();
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
