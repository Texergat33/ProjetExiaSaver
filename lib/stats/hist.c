#include "hist.h"

void printStats()                                                 //Fonction permettant l'affichage des statistiques
{
    int choice, level;
    char* loginfo = "";
    char* date = "";
    char* hour = "";
    char* launcher = "";
    FILE* file = fopen("history.txt", "r");
    if(file != NULL){
        do{
            printf("Stats\n\nDo you want to display sorted history :\n1.In chronological order ?\n2.By screen saver type ?\nYour choice : ");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                    while(fscanf(file, "%s %s;%d;%s", date, hour, &level, loginfo) != EOF){
                        switch(level){
                            case 1:
                                launcher = "static";
                                break;
                            case 2:
                                launcher = "dynamic";
                                break;
                            case 3:
                                launcher = "interactive";
                                break;
                        }
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

    /*file = fopen("history.txt", "a+" );
    time_t now = time (NULL);
    struct tm tm_now = *localtime (&now);
    char s_now[sizeof "JJ/MM/AAAA HH:MM:SS"];
    strftime (s_now, sizeof s_now, "%d/%m/%Y %H:%M:%S", &tm_now);
    if (file!=NULL)
    {
        fprintf(file,"%s",s_now);
        fputs(";", file);
        fputs(insertion, file);
        fputs(";", file);
        fputs(loginfo, file);
        fputs("\n ", file);
        fclose(file);
    }*/
}
