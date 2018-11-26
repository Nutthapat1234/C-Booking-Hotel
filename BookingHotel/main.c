#include <stdio.h>
#include <string.h>
#include "Hotel.h"
#include "Admin.h"
#include "User.h"

void home(){
    char* name;
    char c[2];
    int check = 0;
    do{
        int command = 0 ;
        printf("1. Select By Hotel\n");
        printf("2. Check Booking detail by name\n");
        printf("3. Check Booking detail by phone number\n");
        printf("4. Admin menu\n");
        printf("5. Exit\n");
        printf("Enter your Command :");
        scanf("%s",&c);
        seek_to_next_line();
        command = atoi(c);
        if(command > 5 || command < 0 || strlen(c) > 1){
            command = 0 ;
        }
        switch (command){
            case 1:
                hotel();
                break;
            case 2:
                search(0);
                break;
            case 3:
                search(1);
                break;
            case 4:
                menuAdmin();
                break;
            case 5:
                check = 1;
                break;
            default:
                printf("Invalid command, please input again\n");
        }
    }while(check == 0 );
    printf("Thank you for using program\n");
}

int main(int argc, char* argv[]) {
    home();
//    addHotel();
//    char b[100];
//    scanf("%s",b);
//    seek_to_next_line();
//    printf("%s",b);

}


