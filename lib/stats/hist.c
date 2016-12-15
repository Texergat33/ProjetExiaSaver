#include "hist.h"

void printStats()                                                 //Fonction permettant l'affichage des statistiques
{
    int choice;
    char* level = "";
    char* loginfo = "";
    char* date = "";
    char* hour = "";
    char* launcher = "";
    FILE* file = NULL;
    file = fopen("history.txt", "r");
    char* item;
    int i=0;
    char line[TAILLE_MAX];
    if(file != NULL){
        do{
            printf("Stats\n\nDo you want to display sorted history :\n1.In chronological order ?\n2.By screen saver type ?\nYour choice : ");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                        while(fgets(line, TAILLE_MAX, file) != NULL){
                            for (item = strtok(line, ";"); item != NULL; item = strtok(NULL, ";")){
                                if(i==0) date = item;
                                else if(i==2) level = item;
                                else if(i==3) loginfo = item;
                                i++;
                            }
                            printf("\n%s\n", level);
                            if(strcmp(level, "1")==0) launcher = "static";
                            else if(strcmp(level, "2")==0) launcher = "dynamic";
                            else if(strcmp(level, "3")==0) launcher = "interactive";
                            printf("%s, the %s saver has been launched with the %s parameter\n", date, launcher, loginfo);
                        }
                    break;
                case 2:
                    //system("sort -d historique.txt"
                    break;
                default:
                    printf("Error. Not a good choice.\n\n");
                    break;
            }
        }while(choice != 1 && choice != 2);
        fclose(file);
    }else{
        printf("Error opening history file.\n\n");
    }
}
void logger(int level, char *loginfo) /*Fonction pour ecrire dans le fichier historique en fonction du type de SS et les infos émises*/
{
    FILE* file = NULL;
    char text[100];
    char insertion[5];
    char tolog[255];
    sprintf(insertion,"%d",level);
    time_t timestamp;
    struct tm * t;
    timestamp = time(NULL);
    t = localtime(&timestamp);
    file = fopen("history.txt", "a+" );
    sprintf(text, "%02u/%02u/%04u %02u:%02u:%02u;%d;%s;\n", t->tm_mday, t->tm_mon,1900 + t->tm_year, t->tm_hour, t->tm_min, t->tm_sec, level, loginfo);
    fputs(text, file);
    fclose(file);
}
