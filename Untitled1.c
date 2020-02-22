#include <stdio.h>//for input output functions like printf and scanf
#include <stdlib.h>//4 variable types like sizeof,wide,div(structure return),ldiv(structure return)
#include <windows.h>//describing co-ordinates like axis
#include <string.h>//string operations


    //global variable/built in function
    COORD coord = {0,0};//top-left corner of window
    void gotoxy(int x,int y){
    coord.X = x; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int main(){
    FILE *fp, *ft;//file pointers
    char another, choice;


    struct emp{
        char name[40], bss[100];
        char rt[20],date[30];
        char dat[30];
        int age,bs;
};

    struct emp e;//structure variable creation

    char empname[40];//string to store name of the customer
    long int recsize;//size of each record of customer

        fp=fopen("EMP.DAT","rb+");//if the file already exists then open file and read it
        if(fp==NULL){
        fp = fopen("EMP.DAT","wb+");//for write it
        if(fp == NULL){
            printf("Connot open file");
            exit(1);
        }
        }

    //size of each record i.e size of structure variable e
    recsize = sizeof(e);

    while(1){

        gotoxy(0,0);
        printf("\n                       :::::::::::::::::::::::::::::::::::::");
        printf("\n                       ::                                 ::");
        printf("\n                       ::     ***********************     ::");
        printf("\n                       ::     @                     @     ::");
        printf("\n                       ::     @      WELCOME TO     @     ::");
        printf("\n                       ::     @                     @     ::");
        printf("\n                       ::     @     D  I  U  Hotel  @     ::");
        printf("\n                       ::     @                     @     ::");
        printf("\n                       ::     ***********************     ::");
        printf("\n                       ::                                 ::");
        printf("\n                       :::::::::::::::::::::::::::::::::::::\n\n");
        gotoxy(30,16);
        printf("1. View Categories");
        gotoxy(30,18);
        printf("2. Get Availability And Features Of Room");
        gotoxy(30,20);
        printf("3. Check-in");
        gotoxy(30,22);
        printf("4. Show Customer Details");
        gotoxy(30,24);
        printf("5. Check-Out");
        gotoxy(30,26);
        printf("6. Restaurant");
        gotoxy(30,28);
        printf("7. Exit");
        gotoxy(30,30);
        printf("Your Choice: ");

        choice  = getche();//get the input from keyboard
        switch(choice){
            case '1':

            printf("\n\n\n1.General \n\n\n2.Couple\n\n\n3.VIP");

            break;

            case '2':

                printf("\n\n\n1.General 5 Rooms Available(Per Night Costs Per Room 2000 Taka\nFeature Of The Room: Non-AC, TV, One Bathroom, Double Bed)");
                printf("\n\n2.Couple 2 Rooms Available(Per Night Costs Per Room 3000 Taka\n Feature Of The Room: One bed,TV,Non-AC,Classified Bathroom)");
                printf("\n\n3.VIP 1 Room Available(Per Night Costs Per Room 5000 Taka\nFeature Of The Room: AC, LED TV,,South Side Balcony,High Classified Balcony)\n");

                break;



            case '3':
                system("cls");//Library function.for clearing screen.
                fseek(fp,0,SEEK_END);//search the file and move cursor to end of the file
                                     //here 0 indicates moving 0 distance from the end of the file

                another = 'y';
                while(another == 'y'){
                    printf("\nEnter name: ");
                    scanf("%s",e.name);
                    printf("\nEnter age: ");
                    scanf("%d", &e.age);
                    printf("\nEnter Contact Number: ");
                    scanf("%d", &e.bs);
                    printf("\nEnter Address: ");
                    scanf("%s", e.bss);
                    printf("\nEnter Your Desired Room Type: ");
                    scanf("%s", e.rt);
                    printf("\nCheck-In Date: ");
                    scanf("%s", e.date);
                    printf("\nCheck-Out Date: ");
                    scanf("%s", e.dat);
                    fwrite(&e,recsize,1,fp);

                    printf("\nAdd another record(y/n) ");
                    fflush(stdin); //Library function.This is the pointer to a FILE object that specifies a buffered stream.
                    another = getche();
                }
                break;
            case '4':
                system("cls");
                rewind(fp);
                while(fread(&e,recsize ,1,fp)==1){// fetch all record from file
                    printf("\nName:%s\nAge:%d\nContact Number:%d\nAddress:%s\nRoom Type:%s\nCheck-In:%s\nCheck-Out:%s\n",e.name,e.age,e.bs,e.bss,e.rt,e.date,e.dat); /// print the name, age contact number and address
                }
                getch();
                break;


            case '5':
                system("cls");
                another = 'y';
                while(another == 'y'){
                    printf("\nSure About Check-Out?Enter Your Name Please-");
                    scanf("%s",empname);
                    ft = fopen("Temp.dat","wb");
                    rewind(fp);
                    while(fread(&e,recsize,1,fp) == 1){// fetch all record from file
                        if(strcmp(e.name,empname) != 0){//if entered name matches with that in file
                            fwrite(&e,recsize,1,ft);
                        }
                    }
                    fclose(fp);
                    fclose(ft);
                    remove("EMP.DAT"); // remove the orginal file
                    rename("Temp.dat","EMP.DAT");// rename the temp file to original file name
                    fp = fopen("EMP.DAT", "rb+");
                    printf("\n                       :::::::::::::::::::::::::::::::::::::");
                    printf("\n                       ::                                 ::");
                    printf("\n                       ::     @@@@@@@@@@@@@@@@@@@@@@@     ::");
                    printf("\n                       ::     @                     @     ::");
                    printf("\n                       ::     @      THANK  YOU     @     ::");
                    printf("\n                       ::     @                     @     ::");
                    printf("\n                       ::     @     COME AGAIN :)   @     ::");
                    printf("\n                       ::     @                     @     ::");
                    printf("\n                       ::     @@@@@@@@@@@@@@@@@@@@@@@     ::");
                    printf("\n                       ::                                 ::");
                    printf("\n                       :::::::::::::::::::::::::::::::::::::\n\n");
                    printf("Delete another record(y/n)");
                    fflush(stdin);
                    another = getche();
                }
                break;
            case '6':
            printf("\nAvailable foods,drinks and dishes are:");
            printf("\n1.Orange Juice  Price :20taka");
            printf("\n2.Paratha       Price :20taka");
            printf("\n3.Dal           Price :15taka");
            printf("\n4.Chicken curry Price :80taka");
            printf("\n5.Koliza bhuna  Price :60taka");
            printf("\n6.Grill(Full)   Price :360taka");
            printf("\n7.Nan           Price :10taka");
            printf("\n8.Soup          Price :50taka");
            printf("\n**************VAT INCLUDED***************");
            printf("\nOnline Food Orders Are Now Under Maintenance.Try Again Later.Thank You!!");
            break;

            case '7':
                system("cls");
                fclose(fp);//file close
                exit(0);//exit the program
        }
    }
    return 0;
}

