#include <stdio.h>
#include <stdlib.h>
#include "launcher.h"

void Time_Display (FILE* logfile)
{
    time_t now = time (NULL);
    struct tm tm_now = *localtime (&now);
    char s_now[sizeof "JJ/MM/AAAA HH:MM:SS"];
    strftime (s_now, sizeof s_now, "%d/%m/%Y %H:%M:%S", &tm_now);
    fprintf(logfile,"%s;",s_now);
}

void Hist_ScreenSaver (FILE* logfile, int selected_saver)
{
    if (selected_saver ==1)
    {
        fprintf(logfile,"Statique;");
    }
        if (selected_saver==2)
    {
        fprintf(logfile,"Dynamique;");
    }
        if (selected_saver ==3)
    {
        fprintf(logfile,"Interactif;");
    }
}

int main(int argc, char* argv[])
{
    system("clear");
    FILE* logfile = NULL;
    logfile = fopen("historique.txt","a+");
    if (argc == 2 && strcmp(argv[1],"-stats") == 0)
	{
	    int choice_logfile;
		printf("Statistiques\n\nVoulez vous afficher l'historique trié :\n1.Par ordre chronologique ?\n2.Par type d'écran de veille ?");
        scanf("%d",&choice_logfile);
        switch(choice_logfile)
        {
        case 1:
            //open "historique.txt"
            break;
        case 2:
            //system("sort -d historique.txt"
            break;
        default:
            //Ce n'est pas un choix valide.
            break;
        }

	}
	else
    {
        char current_directory[1024];
        char exiasaver_home[1024];
        getcwd(current_directory, 1024);
        int rnum = rand_a_b(1, 3);
        char* str = getenv("EXIASAVER_HOME");
        if(str != NULL) strcpy(exiasaver_home, str);
        else strcpy(exiasaver_home, current_directory);
        if (logfile != NULL)
        {
            Hist_ScreenSaver(logfile, rnum);
            Time_Display(logfile);
            fclose(logfile);
        }
        switch(rnum)
        {
            case 1:
                launchExiaSaver1(current_directory, exiasaver_home);
                break;
            case 2:
                launchExiaSaver2(current_directory, exiasaver_home);
                break;
            case 3:
                launchExiaSaver3(current_directory, exiasaver_home);
                break;
        }
	}
    return 0;
}
