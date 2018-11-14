#include <stdio.h>
#include <string.h>
#include "Hotel.h"
#include "Admin.h"

int validateNumber(char* noRoom){
    int check = 0;
    char * pch;
    pch =  strchr(noRoom,'-');
    while (pch!=NULL)
    {
        check += 1;
        pch=strchr(pch+1,'-');
    }
    return check;
}

int main(int argc, char* argv[]) {
//    char *type_room;
//    char noRoom[100];
//    int rangeRoom[2] , index = 0;
////    printf("Enter Type of Room:");
////    scanf("%s",type_room);
//    printf("Enter Room number(e.g 101-109)");
//    scanf("%s",noRoom);
//
//
//    char *token = strtok(noRoom, "-");
//    while (token != NULL)
//    {
//        char buffer[100];
//
//        printf("%s\n",token);
//        token = strtok(NULL, "-");
//        index++;
//    }
//    printf("%d %d",rangeRoom[0],rangeRoom[1]);
    hotel();

}

