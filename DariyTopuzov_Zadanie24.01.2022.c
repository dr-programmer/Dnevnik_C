#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#define maxbr 30

typedef struct
{
    char name[maxbr];
    int number;
    int marks[maxbr];
    float avr;
}Tstudent;

void mySearchPopravka(char *choice, char *filename);
void mySearchOtlichnici(char *choice, char *filename);
void myAdd(char *choice, char *filename);
void myCreator(char *choice, char *filename);
void myReader(char *choice, char *filename);
void myEdit(char *choice, char *filename);

int main()
{
    int option, i, ooption;
    char menu1[1000] = {" Create file < \n Read file \n Search students for popravka \n Otlichnici \n Add Students \n Change file \n File name \n Exit "};
    char menu2[1000] = {" Create file \n Read file < \n Search students for popravka \n Otlichnici \n Add Students \n Change file \n File name \n Exit "};
    char menu3[1000] = {" Create file \n Read file \n Search students for popravka < \n Otlichnici \n Add Students \n Change file \n File name \n Exit "};
    char menu4[1000] = {" Create file \n Read file \n Search students for popravka \n Otlichnici < \n Add Students \n Change file \n File name \n Exit "};
    char menu5[1000] = {" Create file \n Read file \n Search students for popravka \n Otlichnici \n Add Students < \n Change file \n File name \n Exit "};
    char menu6[1000] = {" Create file \n Read file \n Search students for popravka \n Otlichnici \n Add Students \n Change file < \n File name \n Exit "};
    char menu7[1000] = {" Create file \n Read file \n Search students for popravka \n Otlichnici \n Add Students \n Change file \n File name < \n Exit "};
    char menu8[1000] = {" Create file \n Read file \n Search students for popravka \n Otlichnici \n Add Students \n Change file \n File name \n Exit < "};
    char *p;
    char choice[1000], filename[100];
    Tstudent s;
    FILE *f;

    printf("Type the name of the file: ");
    scanf("%s", &filename);
    system("cls");
    puts(menu1);
    strcpy(choice, menu1);
    while(1){
        option = getch();
        if (option == 224) {
            switch(getch()) {
                case 72: system("cls");
                    if(strstr(choice, menu2)){puts(menu1); strcpy(choice, menu1);}
                    else if(strstr(choice, menu3)){puts(menu2); strcpy(choice, menu2);}
                    else if(strstr(choice, menu4)){puts(menu3); strcpy(choice, menu3);}
                    else if(strstr(choice, menu5)){puts(menu4); strcpy(choice, menu4);}
                    else if(strstr(choice, menu6)){puts(menu5); strcpy(choice, menu5);}
                    else if(strstr(choice, menu7)){puts(menu6); strcpy(choice, menu6);}
                    else if(strstr(choice, menu8)){puts(menu7); strcpy(choice, menu7);}
                    else if(strstr(choice, menu1)){puts(menu8); strcpy(choice, menu8);}
                    break;
                case 80: system("cls");
                    if(strstr(choice, menu1)){puts(menu2); strcpy(choice, menu2);}
                    else if(strstr(choice, menu2)){puts(menu3); strcpy(choice, menu3);}
                    else if(strstr(choice, menu3)){puts(menu4); strcpy(choice, menu4);}
                    else if(strstr(choice, menu4)){puts(menu5); strcpy(choice, menu5);}
                    else if(strstr(choice, menu5)){puts(menu6); strcpy(choice, menu6);}
                    else if(strstr(choice, menu6)){puts(menu7); strcpy(choice, menu7);}
                    else if(strstr(choice, menu7)){puts(menu8); strcpy(choice, menu8);}
                    else if(strstr(choice, menu8)){puts(menu1); strcpy(choice, menu1);}
                    break;
            }
        }
        else if(option == '\r'){
            if(strstr(choice, menu1)){myCreator(choice, filename); system("cls"); puts(choice);}
            else if(strstr(choice, menu2))myReader(choice, filename);
            else if(strstr(choice, menu3))mySearchPopravka(choice, filename);
            else if(strstr(choice, menu4))mySearchOtlichnici(choice, filename);
            else if(strstr(choice, menu5))myAdd(choice, filename);
            else if(strstr(choice, menu6)){
                system("cls");
                printf("Type the name of the file: ");
                scanf("%s", &filename);
                system("cls"); puts(choice);
            }
            else if(strstr(choice, menu7)){
                printf("\n The file name is %s", filename);
                printf("\n Press enter to close");
                while(getch() != '\r');
                system("cls"); puts(choice);
            }
            else if(strstr(choice, menu8))break;
        }
        else if(option == 'e')myEdit(choice, filename);
    }
    return 0;
}
void mySearchPopravka(char *choice, char *filename)
{
    FILE *f;
    Tstudent s;
    int i, flag = 0;
    if(f = fopen(filename, "r")){
        while(!feof(f)){
            if(fread(&s, sizeof(s), 1, f)){
                for(i = 0; i < maxbr; i++){
                    if(s.marks[i] == 2){printf("\n %s", s.name); flag = 1; break;}
                    else if(s.marks[i] == 0)break;
                }
            }
        }
        if(flag == 0)printf("\n No students for popravka.");
        fclose(f);
    }
    else printf("Error opening the file!");
    printf("\n Press enter to close");
    while(getch() != '\r');
    system("cls"); puts(choice);
}
void mySearchOtlichnici(char *choice, char *filename)
{
    FILE *f;
    Tstudent s;
    int flag = 0;
    if(f = fopen(filename, "r")){
        while(!feof(f)){
            if(fread(&s, sizeof(s), 1, f)){
                if(s.avr >= 5.50){
                    printf("\n %s", s.name);
                    flag = 1;
                }
            }
        }
        if(!flag)printf("\n No otlichnici.");
        fclose(f);
    }
    else printf("Error opening the file!");
    printf("\n Press enter to close");
    while(getch() != '\r');
    system("cls"); puts(choice);
}
void myAdd(char *choice, char *filename)
{
    FILE *f;
    Tstudent s;
    char *p;
    int i;
    if(f = fopen(filename, "r+")){
        while(!feof(f)){
            fread(&s, sizeof(s), 1, f);
        }
        do{
            printf("Number(0 = end): ");
            scanf("%d", &s.number);
            if(s.number == 0)break;
            getchar();
            printf("Name: ");
            fgets(s.name, 29, stdin);
            p = strchr(s.name, '\n');
            *p = '\0';
            s.avr = 0;
            for(i = 0; i < maxbr; i++){
                printf("Mark(0 = end): ");
                scanf("%d", &s.marks[i]);
                if(s.marks[i] == 0)break;
                s.avr += s.marks[i];
            }
            if(i)s.avr = s.avr/i;
            fwrite(&s, sizeof(s), 1, f);
        }while(1);
        fclose(f);
    }
    else printf("Error opening the file!");
    system("cls"); puts(choice);
}
void myCreator(char *choice, char *filename)
{
    FILE *f;
    Tstudent s;
    int ooption;
    char overwriteY[100] = {" The file already exists! \n Overwrite it? \n Yes < \n No "};
    char overwriteN[100] = {" The file already exists! \n Overwrite it? \n Yes \n No < "};
    char overchoice[100];
    char *p;
    int i;
    if(f = fopen(filename, "r")){
        fclose(f);
        system("cls");
        puts(overwriteY);
        strcpy(overchoice, overwriteY);
        while(1){
            ooption = getch();
            if(ooption == 224){
                switch(getch()){
                    case 72: system("cls");
                        if(strstr(overchoice, overwriteY)){puts(overwriteN); strcpy(overchoice, overwriteN);}
                        else if(strstr(overchoice, overwriteN)){puts(overwriteY); strcpy(overchoice, overwriteY);}
                        break;
                    case 80: system("cls");
                        if(strstr(overchoice, overwriteY)){puts(overwriteN); strcpy(overchoice, overwriteN);}
                        else if(strstr(overchoice, overwriteN)){puts(overwriteY); strcpy(overchoice, overwriteY);}
                        break;
                }
            }
            else if(ooption == '\r'){
                if(strstr(overchoice, overwriteN))return;
                else break;
            }
        }
    }
    if(f = fopen(filename, "w")){
        do{
            printf("Number(0 = end): ");
            scanf("%d", &s.number);
            if(s.number == 0)break;
            getchar();
            printf("Name: ");
            fgets(s.name, 29, stdin);
            p = strchr(s.name, '\n');
            *p = '\0';
            s.avr = 0;
            for(i = 0; i < maxbr; i++){
                printf("Mark(0 = end): ");
                scanf("%d", &s.marks[i]);
                if(s.marks[i] == 0)break;
                s.avr += s.marks[i];
            }
            if(i)s.avr = s.avr/i;
            fwrite(&s, sizeof(s), 1, f);
        }while(1);
        fclose(f);
    }
    else printf("\n Error opening the file!");
    system("cls"); puts(choice);
}
void myReader(char *choice, char *filename)
{
    FILE *f;
    Tstudent s;
    int i;
    if(f = fopen(filename, "r")){
        while(!feof(f)){
            if(fread(&s, sizeof(s), 1, f)){
                printf("\n %2d %-30s", s.number, s.name);
                for(i = 0; i < maxbr; i++){
                    if(s.marks[i] == 0){
                        for(;i < maxbr; i++)printf("  ");
                        break;
                    }
                    printf("%2d", s.marks[i]);
                }
                printf("%6.2f", s.avr);
            }
        }
        fclose(f);
    }
    else printf("Error opening the file!");
    printf("\n Press enter to close");
    while(getch() != '\r');
    system("cls"); puts(choice);
}
void myEdit(char *choice, char *filename)
{
    FILE *f;
    Tstudent s;
    int i, found = 0;
    char name[100];
    char *p;
    printf("\n Type the name of the student you want to edit: ");
    scanf("%s", &name);
    if(f = fopen(filename, "r+")){
        while(!feof(f)){
            fread(&s, sizeof(s), 1, f);
        }
        if(!found){
            printf("Number(0 = end): ");
            scanf("%d", &s.number);
            if(s.number == 0)return;
            getchar();
            printf("Name: ");
            fgets(s.name, 29, stdin);
            p = strchr(s.name, '\n');
            *p = '\0';
            s.avr = 0;
            for(i = 0; i < maxbr; i++){
                printf("Mark(0 = end): ");
                scanf("%d", &s.marks[i]);
                if(s.marks[i] == 0)break;
                s.avr += s.marks[i];
            }
            if(i)s.avr = s.avr/i;
            fwrite(&s, sizeof(s), 1, f);
        }
        else printf("\n The student %s isn't found!", name);
        printf("\n Press enter to close");
        while(getch() != '\r');
        system("cls"); puts(choice);
        fclose(f);
    }
    else printf("Error opening the file!");
}
