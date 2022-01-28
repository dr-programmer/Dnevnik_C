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
void myDelete(char *choice, char *filename);
void myEdit(char *choice, char *filename);
void mySort(char *choice, char *filename);
void myLogin();
void mySL();
void myExit(char *choice);
void myAbout(char *choice);

int main()
{
    int option, i, ooption;
    char menu1[1000] = {" Create file < \n Read file \n Search students for popravka \n Otlichnici \n Add Students \n Change file \n File name \n Delete student \n Edit student \n Sort \n About \n Exit "};
    char menu2[1000] = {" Create file \n Read file < \n Search students for popravka \n Otlichnici \n Add Students \n Change file \n File name \n Delete student \n Edit student \n Sort \n About \n Exit "};
    char menu3[1000] = {" Create file \n Read file \n Search students for popravka < \n Otlichnici \n Add Students \n Change file \n File name \n Delete student \n Edit student \n Sort \n About \n Exit "};
    char menu4[1000] = {" Create file \n Read file \n Search students for popravka \n Otlichnici < \n Add Students \n Change file \n File name \n Delete student \n Edit student \n Sort \n About \n Exit "};
    char menu5[1000] = {" Create file \n Read file \n Search students for popravka \n Otlichnici \n Add Students < \n Change file \n File name \n Delete student \n Edit student \n Sort \n About \n Exit "};
    char menu6[1000] = {" Create file \n Read file \n Search students for popravka \n Otlichnici \n Add Students \n Change file < \n File name \n Delete student \n Edit student \n Sort \n About \n Exit "};
    char menu7[1000] = {" Create file \n Read file \n Search students for popravka \n Otlichnici \n Add Students \n Change file \n File name < \n Delete student \n Edit student \n Sort \n About \n Exit "};
    char menu8[1000] = {" Create file \n Read file \n Search students for popravka \n Otlichnici \n Add Students \n Change file \n File name \n Delete student < \n Edit student \n Sort \n About \n Exit "};
    char menu9[1000] = {" Create file \n Read file \n Search students for popravka \n Otlichnici \n Add Students \n Change file \n File name \n Delete student \n Edit student < \n Sort \n About \n Exit "};
    char menu10[1000] = {" Create file \n Read file \n Search students for popravka \n Otlichnici \n Add Students \n Change file \n File name \n Delete student \n Edit student \n Sort < \n About \n Exit "};
    char menu11[1000] = {" Create file \n Read file \n Search students for popravka \n Otlichnici \n Add Students \n Change file \n File name \n Delete student \n Edit student \n Sort \n About < \n Exit "};
    char menu12[1000] = {" Create file \n Read file \n Search students for popravka \n Otlichnici \n Add Students \n Change file \n File name \n Delete student \n Edit student \n Sort \n About \n Exit < "};
    char *p;
    char choice[1000], filename[100];
    Tstudent s;
    FILE *f;

    myLogin();
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
                    else if(strstr(choice, menu9)){puts(menu8); strcpy(choice, menu8);}
                    else if(strstr(choice, menu10)){puts(menu9); strcpy(choice, menu9);}
                    else if(strstr(choice, menu11)){puts(menu10); strcpy(choice, menu10);}
                    else if(strstr(choice, menu12)){puts(menu11); strcpy(choice, menu11);}
                    else if(strstr(choice, menu1)){puts(menu12); strcpy(choice, menu12);}
                    break;
                case 80: system("cls");
                    if(strstr(choice, menu1)){puts(menu2); strcpy(choice, menu2);}
                    else if(strstr(choice, menu2)){puts(menu3); strcpy(choice, menu3);}
                    else if(strstr(choice, menu3)){puts(menu4); strcpy(choice, menu4);}
                    else if(strstr(choice, menu4)){puts(menu5); strcpy(choice, menu5);}
                    else if(strstr(choice, menu5)){puts(menu6); strcpy(choice, menu6);}
                    else if(strstr(choice, menu6)){puts(menu7); strcpy(choice, menu7);}
                    else if(strstr(choice, menu7)){puts(menu8); strcpy(choice, menu8);}
                    else if(strstr(choice, menu8)){puts(menu9); strcpy(choice, menu9);}
                    else if(strstr(choice, menu9)){puts(menu10); strcpy(choice, menu10);}
                    else if(strstr(choice, menu10)){puts(menu11); strcpy(choice, menu11);}
                    else if(strstr(choice, menu11)){puts(menu12); strcpy(choice, menu12);}
                    else if(strstr(choice, menu12)){puts(menu1); strcpy(choice, menu1);}
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
            else if(strstr(choice, menu8))myDelete(choice, filename);
            else if(strstr(choice, menu9))myEdit(choice, filename);
            else if(strstr(choice, menu10))mySort(choice, filename);
            else if(strstr(choice, menu11))myAbout(choice);
            else if(strstr(choice, menu12))myExit(choice);
        }
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
    else {
        printf("Error opening the file! \n Press enter to close");
        while(getch() != '\r');
    }
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
void myDelete(char *choice, char *filename)
{
    FILE *f, *f1;
    Tstudent s;
    int i, number, flag = 0;
    printf("\n Type the number of the student you want to delete: ");
    scanf("%d", &number);
    if(!(f = fopen(filename, "r"))){printf("\n Error opening the file!"); return;}
    if(!(f1 = fopen("pom.dat", "w"))){fclose(f); printf("\n Error opening the file!"); return;}
    while(!feof(f)){
        if(fread(&s, sizeof(s), 1, f)){
            if(s.number == number){flag = 1; continue;}
            fwrite(&s, sizeof(s), 1, f1);
        }
    }
    fclose(f);
    fclose(f1);
    if(!(f = fopen(filename, "w"))){printf("\n Error opening the file!"); return;}
    if(!(f1 = fopen("pom.dat", "r"))){fclose(f); printf("\n Error opening the file!"); return;}
    while(!feof(f1)){
        if(fread(&s, sizeof(s), 1, f1)){
            fwrite(&s, sizeof(s), 1, f);
        }
    }
    fclose(f);
    fclose(f1);
    if(flag)printf(" Student deleted successfully! \n Press enter to close");
    else printf(" No student to be deleted! \n Press enter to close");
    while(getch() != '\r');
    system("cls"); puts(choice);
}
void myEdit(char *choice, char *filename)
{
    FILE *f, *f1;
    Tstudent s;
    int i, number, flag = 0;
    char *p;
    printf("\n Type the number of the student you want to edit: ");
    scanf("%d", &number);
    if(!(f = fopen(filename, "r"))){printf("\n Error opening the file!"); return;}
    if(!(f1 = fopen("pom.dat", "w"))){fclose(f); printf("\n Error opening the file!"); return;}
    while(!feof(f)){
        if(fread(&s, sizeof(s), 1, f)){
            if(s.number == number){flag = 1; continue;}
            fwrite(&s, sizeof(s), 1, f1);
        }
    }
    fclose(f);
    fclose(f1);
    if(!(f = fopen(filename, "w"))){printf("\n Error opening the file!"); return;}
    if(!(f1 = fopen("pom.dat", "r"))){fclose(f); printf("\n Error opening the file!"); return;}
    while(!feof(f1)){
        if(fread(&s, sizeof(s), 1, f1)){
            fwrite(&s, sizeof(s), 1, f);
        }
    }
    fclose(f);
    fclose(f1);
    if(flag){
        if(f = fopen(filename, "r+")){
            while(!feof(f)){
                fread(&s, sizeof(s), 1, f);
            }
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
            fclose(f);
        }
        else printf("Error opening the file!");
        printf(" Student edited successfully! \n Press enter to close");
        while(getch() != '\r');
    }
    else {
        printf(" No student to be edited! \n Press enter to close");
        while(getch() != '\r');
    }
    system("cls"); puts(choice);
}
void mySort(char *choice, char *filename)
{
    FILE *f;
    Tstudent s, ss[100], r;
    char sortName[100] = {" Choose how to sort: \n Sort by name < \n Sort by average mark "};
    char sortMark[100] = {" Choose how to sort: \n Sort by name \n Sort by average mark < "};
    char sortChoice[100];
    int i, n = 0, sorted = 0, k, soption;
    system("cls");
    puts(sortName);
    strcpy(sortChoice, sortName);
    while(1){
        soption = getch();
        if(soption == 224){
            switch(getch()){
                case 72: system("cls");
                    if(strstr(sortChoice, sortName)){puts(sortMark); strcpy(sortChoice, sortMark);}
                    else if(strstr(sortChoice, sortMark)){puts(sortName); strcpy(sortChoice, sortName);}
                    break;
                case 80: system("cls");
                    if(strstr(sortChoice, sortName)){puts(sortMark); strcpy(sortChoice, sortMark);}
                    else if(strstr(sortChoice, sortMark)){puts(sortName); strcpy(sortChoice, sortName);}
                    break;
            }
        }
        else if(soption == '\r'){
            if(strstr(sortChoice, sortName)){
                if(f = fopen(filename, "r")){
                    while(!feof(f)){
                        if(fread(&s, sizeof(s), 1, f)){
                            ss[n] = s;
                            n++;
                        }
                    }
                    for(i = 0; i < n-1; i++){
                        sorted = 1;
                        for(k = 0; k < n-1; k++){
                            if(strcmp(ss[k].name, ss[k+1].name) > 0){
                                r = ss[k];
                                ss[k] = ss[k+1];
                                ss[k+1] = r;
                                sorted = 0;
                            }
                        }
                        if(sorted)break;
                    }
                    fclose(f);
                }
                else {
                    printf("Error opening the file!");
                    break;
                }
                if(f = fopen(filename, "w")){
                    for(i = 0; i < n; i++){
                        fwrite(&ss[i], sizeof(ss[i]), 1, f);
                    }
                    fclose(f);
                }
                else {
                    printf("Error opening the file!");
                    break;
                }
                printf("\n Sorted!");
                break;
            }
            else if(strstr(sortChoice, sortMark)){
                if(f = fopen(filename, "r")){
                    while(!feof(f)){
                        if(fread(&s, sizeof(s), 1, f)){
                            ss[n] = s;
                            n++;
                        }
                    }
                    for(i = 0; i < n-1; i++){
                        sorted = 1;
                        for(k = 0; k < n-1; k++){
                            if(ss[k].avr < ss[k+1].avr){
                                r = ss[k];
                                ss[k] = ss[k+1];
                                ss[k+1] = r;
                                sorted = 0;
                            }
                        }
                        if(sorted)break;
                    }
                    fclose(f);
                }
                else {
                    printf("Error opening the file!");
                    break;
                }
                if(f = fopen(filename, "w")){
                    for(i = 0; i < n; i++){
                        fwrite(&ss[i], sizeof(ss[i]), 1, f);
                    }
                    fclose(f);
                }
                else {
                    printf("Error opening the file!");
                    break;
                }
                printf("\n Sorted!");
                break;
            }
        }
    }
    printf("\n Press enter to close");
    while(getch() != '\r');
    system("cls"); puts(choice);
}
void myLogin()
{
    FILE *fpass;
    Tstudent s;
    char lte[100] = {" Choose your user type: \n Teacher < \n Student \n Exit "};
    char lst[100] = {" Choose your user type: \n Teacher \n Student < \n Exit "};
    char lex[100] = {" Choose your user type: \n Teacher \n Student \n Exit < "};
    char lchoice[100];
    char lypass[100];
    char lpass[100];
    char *p;
    int loption, i;
    system("cls");
    puts(lte);
    strcpy(lchoice, lte);
    while(1){
        system("cls"); puts(lchoice);
        loption = getch();
        if(loption == 224){
            switch(getch()){
                case 72: system("cls");
                    if(strstr(lchoice, lte)){puts(lex); strcpy(lchoice, lex);}
                    else if(strstr(lchoice, lst)){puts(lte); strcpy(lchoice, lte);}
                    else if(strstr(lchoice, lex)){puts(lst); strcpy(lchoice, lst);}
                    break;
                case 80: system("cls");
                    if(strstr(lchoice, lte)){puts(lst); strcpy(lchoice, lst);}
                    else if(strstr(lchoice, lst)){puts(lex); strcpy(lchoice, lex);}
                    else if(strstr(lchoice, lex)){puts(lte); strcpy(lchoice, lte);}
                    break;
            }
        }
        else if(loption == '\r'){
            while(strstr(lchoice, lte)){
                printf("\n Please enter your password: ");
                for(i = 0;; i++){
                    lypass[i] = getch();
                    if(lypass[i] == '\r')break;
                    printf("*");
                }
                if(p = strchr(lypass, '\r')){
                    *p = '\0';
                }
                if(fpass = fopen("PC", "r")){
                    if(fread(&lpass, sizeof(lpass), 1, fpass)){
                        if(!strcmp(lpass, lypass)){
                            system("cls");
                            fclose(fpass);
                            return;
                        }
                        else {
                            printf("\n Wrong password!");
                            fclose(fpass);
                            continue;
                        }
                    }
                    fclose(fpass);
                }
            }
            if(strstr(lchoice, lst))mySL();
            else if(strstr(lchoice, lex))exit(0);
        }
    }
}
void mySL()
{
    FILE *f;
    Tstudent s;
    char sfilename[100];
    char *p;
    int number, i, flag = 0;
    printf("\n Please write the name of the file you want to use: ");
    scanf("%s", &sfilename);
    if(f = fopen(sfilename, "r")){
        printf("\n Please enter your number: ");
        scanf("%d", &number);
        while(!feof(f)){
            if(fread(&s, sizeof(s), 1, f)){
                if(number == s.number){
                    printf("\n %2d %-30s", s.number, s.name);
                    for(i = 0; i < maxbr; i++){
                        if(s.marks[i] == 0){
                            for(;i < maxbr; i++)printf("  ");
                            break;
                        }
                        printf("%2d", s.marks[i]);
                    }
                    printf("%6.2f", s.avr);
                    flag = 1;
                }
            }
        }
        fclose(f);
        if(!flag){
            printf("\n No student with this number!");
        }
    }
    else printf("Error opening the file!");
    printf("\n Press enter to close");
    while(getch() != '\r');
    return;
}
void myExit(char *choice)
{
    char mm[100] = {" Are you sure? \n Go to main menu < \n Go back \n Quit "};
    char gb[100] = {" Are you sure? \n Go to main menu \n Go back < \n Quit "};
    char quit[100] = {" Are you sure? \n Go to main menu \n Go back \n Quit < "};
    char echoice[100];
    int eoption;
    system("cls");
    puts(mm);
    strcpy(echoice, mm);
    while(1){
        eoption = getch();
        if(eoption == 224){
            switch(getch()){
                case 72: system("cls");
                    if(strstr(echoice, mm)){puts(quit); strcpy(echoice, quit);}
                    else if(strstr(echoice, gb)){puts(mm); strcpy(echoice, mm);}
                    else if(strstr(echoice, quit)){puts(gb); strcpy(echoice, gb);}
                    break;
                case 80: system("cls");
                    if(strstr(echoice, mm)){puts(gb); strcpy(echoice, gb);}
                    else if(strstr(echoice, gb)){puts(quit); strcpy(echoice, quit);}
                    else if(strstr(echoice, quit)){puts(mm); strcpy(echoice, mm);}
                    break;
            }
        }
        else if(eoption == '\r'){
            if(strstr(echoice, mm)){
                main();
            }
            else if(strstr(echoice, gb)){
                system("cls");
                puts(choice);
                return;
            }
            else if(strstr(echoice, quit))exit(0);
        }
    }
}
void myAbout(char *choice)
{
    FILE *fpass;
    char about[100] = {" Choose an option: \n About D-Dnevnik < \n Change password \n Back "};
    char chpass[100] = {" Choose an option: \n About D-Dnevnik \n Change password < \n Back "};
    char back[100] = {" Choose an option: \n About D-Dnevnik \n Change password \n Back < "};
    char achoice[100];
    char lpass[100];
    char *p;
    int aoption;
    system("cls");
    puts(about);
    strcpy(achoice, about);
    while(1){
        aoption = getch();
        if(aoption == 224){
            switch(getch()){
                case 72: system("cls");
                    if(strstr(achoice, about)){puts(back); strcpy(achoice, back);}
                    else if(strstr(achoice, chpass)){puts(about); strcpy(achoice, about);}
                    else if(strstr(achoice, back)){puts(chpass); strcpy(achoice, chpass);}
                    break;
                case 80: system("cls");
                    if(strstr(achoice, about)){puts(chpass); strcpy(achoice, chpass);}
                    else if(strstr(achoice, chpass)){puts(back); strcpy(achoice, back);}
                    else if(strstr(achoice, back)){puts(about); strcpy(achoice, about);}
                    break;
            }
        }
        else if(aoption == '\r'){
            if(strstr(achoice, about)){
                printf("\n D-Dnevnik Version 1.0.0");
                printf("\n \n Press enter to close");
                while(getch() != '\r');
                system("cls");
                puts(achoice);
            }
            else if(strstr(achoice, chpass)){
                printf("\n Please type your new password: ");
                getchar();
                fgets(lpass, 99, stdin);
                if(p = strchr(lpass, '\n')){
                    *p = '\0';
                }
                printf(" Your new password is: %s \n", lpass);
                if(fpass = fopen("PC", "w")){
                    if(fwrite(&lpass, sizeof(lpass), 1, fpass));
                    else {
                        printf("Error opening the file!");
                    }
                    fclose(fpass);
                }
                printf("\n Press enter to close");
                while(getch() != '\r');
                system("cls"); puts(achoice);
            }
            else if(strstr(achoice, back)){
                system("cls");
                puts(choice);
                return;
            }
        }
    }
}
