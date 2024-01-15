#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct program{
    char tip_consultatie[50];
}program[100];

struct istoric{
    char istoric_data[50];
}istoric[100];

int verificareData(int zi, int luna, int an){
    if(an != 2023 || luna < 1 || luna > 12 || (luna%2 == 0 && zi > 30 && luna != 2) || (luna%2 == 1 && zi > 31) || zi < 1 || (luna == 2 && zi > 28))
        return 0;
    else
        return 1;
}

void citireProgram(){
    int nr_program;
    FILE* fi = fopen("program.txt", "r");
    fscanf(fi, "%d", &nr_program);
    fgetc(fi);
    for (int i = 1; i <= nr_program; i++){
        fgets(program[i].tip_consultatie, 50, fi);
    }
    for (int i = 1; i <= nr_program; i++) {
        printf("%d. %s\n", i,program[i].tip_consultatie);
    }
    fclose(fi);
}

void citireIstoric(){
    int nr_istoric;
    FILE* fp = fopen("istoric.txt", "r");
    fscanf(fp, "%d", &nr_istoric);
    printf("-= ISTORIC =- \n");
    fgetc(fp);
    for (int i = 1; i <= nr_istoric; ++i){
        fgets(istoric[i].istoric_data, 50, fp);
    }
    for (int i = 1; i <= nr_istoric; ++i) {
        printf("%d. %s", i, istoric[i].istoric_data);
    }
    fclose(fp);
}

int main()
{

    while (1 == 1) {
        system("cls");
        printf("-= MENIU =-\n");
        printf("1. Oferte\n");
        printf("2. Programare\n");
        printf("3. Istoric\n");
        printf("4. Exit\n");

        int choice;
        do {
            printf("Introdu varianta dorita: ");
            scanf("%d", &choice);
        } while (choice < 1 || choice > 4);

        system("cls");

        if (choice == 1) {

            printf("-= OFERTE =-\n");
            printf("1. Consultatie primara - 60 RON - 40 min.\n");
            printf("2. Plan tratament - 250 RON - 20 min.\n");
            printf("3. Igienizare - 280 RON - 45 min.\n");
            printf("4. Albire profesionala - 180 RON -  35 min.\n");
            printf("5. Extractie dinte temporar - 120 RON - 20 min.\n");
            system("pause");

        } else if (choice == 2) {

            int i = 0;

            while (i == 0) {

                int zi, luna, an;
                system("cls");
                printf("Introduceti data(zi.luna.an): ");
                scanf("%d.%d.%d", &zi, &luna, &an);
                if(verificareData(zi, luna, an) == 0)
                do{
                    int choice;
                    system("cls");
                    printf("Data introdusa este incorecta. \nIntroduceti data(zi.luna.an): ");
                    scanf("%d.%d.%d", &zi, &luna, &an);
                    printf("\n");

                } while(verificareData(zi, luna, an) == 0);

                if(verificareData(zi, luna, an) == 1)
                {
                    system("cls");
                    printf("-=Program=- \n");
                    citireProgram();

                    printf("0. Back\n");

                    printf("Introdu varianta dorita:");
                    int alegere;

                    scanf("%d", &alegere);
                    if (alegere == 0)
                        i = 1;
                    else
                    {
                        int aux;
                        aux=i;
                        printf("La ce ora ati dori sa va programati?\n");
                        printf("1. 12:00\n");
                        printf("2. 13:00\n");
                        printf("3. 14:00\n");
                        printf("4. 15:00\n");
                        printf("5. 16:00\n");
                        int oraaleasa;
                        scanf("%d",&oraaleasa);
                        FILE* fp = fopen("istoric.txt", "a");
                        int ok=0;
                        if(alegere==1)
                        {
                            if(oraaleasa==1)
                            {
                                ok=1;
                                fputs("Consultatie primara ", fp);
                                 fprintf(fp, "%d/%d/%d ora 12:00\n", zi, luna, an);
                            }
                            if(oraaleasa==2)
                            {
                                ok=1;
                                fputs("Consultatie primara ", fp);
                                 fprintf(fp, "%d/%d/%d ora 13:00\n", zi, luna, an);
                                 ok=1;
                            }
                                if(oraaleasa==3)
                            {
                                fputs("Consultatie primara ", fp);
                                 fprintf(fp, "%d/%d/%d ora 14:00\n", zi, luna, an);
                                 ok=1;
                            }
                                if(oraaleasa==4)
                            {
                                ok=1;
                                fputs("Consultatie primara ", fp);
                                 fprintf(fp, "%d/%d/%d ora 15:00\n", zi, luna, an);
                            }
                                if(oraaleasa==5)
                            {
                                ok=1;
                                fputs("Consultatie primara ", fp);
                                 fprintf(fp, "%d/%d/%d ora 16:00\n", zi, luna, an);
                            }
                        }
                        if(alegere==2)
                        {
                            if(oraaleasa==1)
                            {
                                ok=1;
                                fputs("Plan tratament ", fp);
                                 fprintf(fp, "%d/%d/%d ora 12:00\n", zi, luna, an);
                            }
                            if(oraaleasa==2)
                            {
                                ok=1;
                                fputs("Plan tratament ", fp);
                                 fprintf(fp, "%d/%d/%d ora 13:00\n", zi, luna, an);
                            }
                                if(oraaleasa==3)
                            {
                                ok=1;
                                fputs("Plan tratament ", fp);
                                 fprintf(fp, "%d/%d/%d ora 14:00\n", zi, luna, an);
                            }
                                if(oraaleasa==4)
                            {
                                ok=1;
                                fputs("Plan tratament ", fp);
                                 fprintf(fp, "%d/%d/%d ora 15:00\n", zi, luna, an);
                            }
                                if(oraaleasa==5)
                            {
                                ok=1;
                                fputs("Plan tratament ", fp);
                                 fprintf(fp, "%d/%d/%d ora 16:00\n", zi, luna, an);
                            }
                        }
                        if(alegere==3)
                        {
                            if(oraaleasa==1)
                            {
                                ok=1;
                                fputs("Igienizare ", fp);
                                 fprintf(fp, "%d/%d/%d ora 12:00\n", zi, luna, an);
                            }
                            if(oraaleasa==2)
                            {
                                ok=1;
                                fputs("Igienizare", fp);
                                 fprintf(fp, "%d/%d/%d ora 13:00\n", zi, luna, an);
                            }
                                if(oraaleasa==3)
                            {
                                ok=1;
                                fputs("Igienizare ", fp);
                                 fprintf(fp, "%d/%d/%d ora 14:00\n", zi, luna, an);
                            }
                                if(oraaleasa==4)
                            {
                                ok=1;
                                fputs("Igienizare ", fp);
                                 fprintf(fp, "%d/%d/%d ora 15:00\n", zi, luna, an);
                            }
                                if(oraaleasa==5)
                            {
                                ok=1;
                                fputs("Igienizare ", fp);
                                 fprintf(fp, "%d/%d/%d ora 16:00\n", zi, luna, an);
                            }
                        }
                        if(alegere==4)
                        {
                            if(oraaleasa==1)
                            {
                                ok=1;
                                fputs("Albire profesionala ", fp);
                                 fprintf(fp, "%d/%d/%d ora 12:00\n", zi, luna, an);
                            }
                            if(oraaleasa==2)
                            {
                                ok=1;
                                fputs("Albire profesionala ", fp);
                                 fprintf(fp, "%d/%d/%d ora 13:00\n", zi, luna, an);
                            }
                                if(oraaleasa==3)
                            {
                                ok=1;
                                fputs("Albire profesionala ", fp);
                                 fprintf(fp, "%d/%d/%d ora 14:00\n", zi, luna, an);
                            }
                                if(oraaleasa==4)
                            {
                                ok=1;
                                fputs("Albire profesionala ", fp);
                                 fprintf(fp, "%d/%d/%d ora 15:00\n", zi, luna, an);
                            }
                                if(oraaleasa==5)
                            {
                                ok=1;
                                fputs("Albire profesionala ", fp);
                                 fprintf(fp, "%d/%d/%d ora 16:00\n", zi, luna, an);
                            }
                        }
                        if(alegere==5)
                        {
                            if(oraaleasa==1)
                            {
                                ok=1;
                                fputs("Extractie dinte temporar ", fp);
                                 fprintf(fp, "%d/%d/%d ora 12:00\n", zi, luna, an);
                            }
                            if(oraaleasa==2)
                            {
                                ok=1;
                                fputs("Extractie dinte temporar ", fp);
                                 fprintf(fp, "%d/%d/%d ora 13:00\n", zi, luna, an);
                            }
                                if(oraaleasa==3)
                            {
                                ok=1;
                                fputs("Extractie dinte temporar ", fp);
                                 fprintf(fp, "%d/%d/%d ora 14:00\n", zi, luna, an);
                            }
                                if(oraaleasa==4)
                            {
                                ok=1;
                                fputs("Extractie dinte temporar ", fp);
                                 fprintf(fp, "%d/%d/%d ora 15:00\n", zi, luna, an);
                            }
                                if(oraaleasa==5)
                            {
                                ok=1;
                                fputs("Extractie dinte temporar ", fp);
                                 fprintf(fp, "%d/%d/%d ora 16:00\n", zi, luna, an);
                            }
                        }
                        if(alegere==6)
                        {
                            if(oraaleasa==1)
                            {
                                ok=1;
                                fputs("Periaj profesional ", fp);
                                 fprintf(fp, "%d/%d/%d ora 12:00\n", zi, luna, an);
                            }
                            if(oraaleasa==2)
                            {
                                ok=1;
                                fputs("Periaj profesional ", fp);
                                 fprintf(fp, "%d/%d/%d ora 13:00\n", zi, luna, an);
                            }
                                if(oraaleasa==3)
                            {
                                ok=1;
                                fputs("Periaj profesional ", fp);
                                 fprintf(fp, "%d/%d/%d ora 14:00\n", zi, luna, an);
                            }
                                if(oraaleasa==4)
                            {
                                ok=1;
                                fputs("Periaj profesional ", fp);
                                 fprintf(fp, "%d/%d/%d ora 15:00\n", zi, luna, an);
                            }
                                if(oraaleasa==5)
                            {
                                ok=1;
                                fputs("Periaj profesional ", fp);
                                 fprintf(fp, "%d/%d/%d ora 16:00\n", zi, luna, an);
                            }
                        }
                        if(ok==0){
                            printf("Datele sunt invalide.\n Va rugam sa incercati cu date valide\n");
                            system("pause");
                        }

                    fclose(fp);
                    }

                }

                i = 1;
            }

        } else if (choice == 3){
            citireIstoric();
            system("pause");

        } else if(choice == 4)
            return 0;
}
    return 0;
}
