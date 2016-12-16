#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include "../../lib/PBM/PBM.h"
#include "../../lib/conio/conio.h"

void placeNumbersInHourTable(int imageTable[80][24])//Permits to get the actual hour in a table.
{
    time_t seconds;//get the current time in seconds
    struct tm actualTime;//create a structure that will contain the actualtime. It's defined in <time.h>
    FILE* file = NULL;//create a pointer that will contain the opened file's adress
    char lineRead[71] = "";//table that will contain the line read by the program
    int frameValue;//interger that will represent the value of the read frame
    time(&seconds);
    actualTime=*localtime(&seconds);//Give the actual hour to the structure
    int hourArray[6] = {0}; //We create a table that will be filled with the hour
    imageTable[33][6] = 1; //Due to some problems, those 4 lines will create the separator (":") between the PBM numbers
    imageTable[33][8] = 1;
    imageTable[45][6] = 1;
    imageTable[45][8] = 1;
    hourArray[0]=actualTime.tm_hour/10;//The first frame will contain the first digit of the hour
    hourArray[1]=actualTime.tm_hour%10;//The second one will contain the second digit of the hour
    hourArray[2]=actualTime.tm_min/10;//The third one will contain the first digit of the minuts
    hourArray[3]=actualTime.tm_min%10;//And so go on...
    hourArray[4]=actualTime.tm_sec/10;
    hourArray[5]=actualTime.tm_sec%10;
    printf("\n");

    for(int i = 0; i < 6; i++)
    {
        switch(hourArray[i])//We will read the table to get the pbm files corresponding to the hour
        {
        case 0://We will explain only for the first case, it's the same thing with a different file
            file = fopen("/home/spadesjack/ProjetExiaSaver/eXiaSaver2/pbm/num0.pbm", "r");//We open the concerned PBM file in read only mode
            for(int a = 0; a < 2 ; a++)
            {
                fgets(lineRead, 71,file);//This line's purpose is that we don't want to print the magic number of the file and it's dimensions
            }
            for(int z = 0; z < 5; z++)
            {
                for(int k = 0; k < 3; k++)
                {
                    fscanf(file, "%d", &frameValue);//Then, we read the file
                    imageTable[(23+i*6)+k][5+z] = frameValue;//And we place it on the table
                }
            }
            fclose(file);//We close the file
            break;//The break is here to avoid problems with the different cases.

        case 1:
            file = fopen("/home/spadesjack/ProjetExiaSaver/eXiaSaver2/pbm/num1.pbm", "r");
            for(int b = 0; b < 2 ; b++)
            {
                fgets(lineRead, 71,file);
            }
            for(int z = 0; z < 5; z++)
            {
                for(int k = 0; k < 3; k++)
                {
                    fscanf(file, "%d", &frameValue);
                    imageTable[(23+i*6)+k][5+z] = frameValue;
                }
            }
            fclose(file);
            break;

        case 2:
            file = fopen("/home/spadesjack/ProjetExiaSaver/eXiaSaver2/pbm/num2.pbm", "r");
            for(int c =0; c< 2 ; c++)
            {
                fgets(lineRead, 71,file);
            }
            for(int z = 0; z < 5; z++)
            {
                for(int k = 0; k < 3; k++)
                {
                    fscanf(file, "%d", &frameValue);
                    imageTable[(23+i*6)+k][5+z] = frameValue;
                }
            }
            fclose(file);
            break;

        case 3:
            file = fopen("/home/spadesjack/ProjetExiaSaver/eXiaSaver2/pbm/num3.pbm", "r");
            for(int q =0; q< 2 ; q++)
            {
                fgets(lineRead, 71,file);
            }
            for(int z = 0; z < 5; z++)
            {
                for(int k = 0; k < 3; k++)
                {
                    fscanf(file, "%d", &frameValue);
                    imageTable[(23+i*6)+k][5+z] = frameValue;
                }
            }
            fclose(file);
            break;

        case 4:
            file = fopen("/home/spadesjack/ProjetExiaSaver/eXiaSaver2/pbm/num4.pbm", "r");
            for(int e =0; e< 2 ; e++)
            {
                fgets(lineRead, 71,file);
            }
            for(int z = 0; z < 5; z++)
            {
                for(int k = 0; k < 3; k++)
                {
                    fscanf(file, "%d", &frameValue);
                    imageTable[(23+i*6)+k][5+z] = frameValue;
                }
            }
            fclose(file);
            break;

        case 5:
            file = fopen("/home/spadesjack/ProjetExiaSaver/eXiaSaver2/pbm/num5.pbm", "r");
            for(int f =0; f< 2 ; f++)
            {
                fgets(lineRead, 71,file);
            }
            for(int z = 0; z < 5; z++)
            {
                for(int k = 0; k < 3; k++)
                {
                    fscanf(file, "%d", &frameValue);
                    imageTable[(23+i*6)+k][5+z] = frameValue;
                }
            }
            fclose(file);
            break;

        case 6:
            file = fopen("/home/spadesjack/ProjetExiaSaver/eXiaSaver2/pbm/num6.pbm", "r");
            for(int g =0; g< 2 ; g++)
            {
                fgets(lineRead, 71,file);
            }
            for(int z = 0; z < 5; z++)
            {
                for(int k = 0; k < 3; k++)
                {
                    fscanf(file, "%d", &frameValue);
                    imageTable[(23+i*6)+k][5+z] = frameValue;
                }
            }
            fclose(file);
            break;

        case 7:
            file = fopen("/home/spadesjack/ProjetExiaSaver/eXiaSaver2/pbm/num7.pbm", "r");
            for(int h =0; h< 2 ; h++)
            {
                fgets(lineRead, 71,file);
            }
            for(int z = 0; z < 5; z++)
            {
                for(int k = 0; k < 3; k++)
                {
                    fscanf(file, "%d", &frameValue);
                    imageTable[(23+i*6)+k][5+z] = frameValue;
                }
            }
            fclose(file);
            break;

        case 8:
            file = fopen("/home/spadesjack/ProjetExiaSaver/eXiaSaver2/pbm/num8.pbm", "r");
            for(int l =0; l< 2 ; l++)
            {
                fgets(lineRead, 71,file);
            }
            for(int z = 0; z < 5; z++)
            {
                for(int k = 0; k < 3; k++)
                {
                    fscanf(file, "%d", &frameValue);
                    imageTable[(23+i*6)+k][5+z] = frameValue;
                }
            }
            fclose(file);
            break;

        case 9:
            file = fopen("/home/spadesjack/ProjetExiaSaver/eXiaSaver2/pbm/num9.pbm", "r");
            for(int m =0; m< 2 ; m++)
            {
                fgets(lineRead, 71,file);
            }
            for(int z = 0; z < 5; z++)
            {
                for(int k = 0; k < 3; k++)
                {
                    fscanf(file, "%d", &frameValue);
                    imageTable[(23+i*6)+k][5+z] = frameValue;
                }
            }
            fclose(file);
            break;
        default:
            exit(2);
            break;
        }
    }
}

void displayImageTable(int imageTable[80][24])
{
    char c[] = {226, 150, 136, 0};//Permits to print ASCII characters
    for (int i = 0 ; i < 20; i++)//We read hte table
    {
        for (int j = 0; j < 80; j++)
        {
            if(imageTable[j][i] == 0)//And if the frame contains a 0,
            {
                printf(" "); //We print a space
            }
            else //If it contains something else (that is to say a 1),
            {
                printf("%s", c);//We print the character, that will be a white square.
            }
        }
        printf("\n");
    }
    printf("\n");
}

int kbhit(void)//That function is here to kill the process, i took it on the internet and i can't really explain it
{
 struct termios oldt, newt;
 int ch;
 int oldf;

 tcgetattr(STDIN_FILENO, &oldt);
 newt = oldt;
 newt.c_lflag &= ~(ICANON | ECHO);
 tcsetattr(STDIN_FILENO, TCSANOW, &newt);
 oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
 fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

 ch = getchar();

 tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
 fcntl(STDIN_FILENO, F_SETFL, oldf);

 if(ch != EOF)
 {
   ungetc(ch, stdin);
   return 1;
 }

 return 0;
}

int main()
{
    int sleepTime = 10; //We initialize the time between the hour refresh;
    sleepTime = atoi(getenv("EXIASAVER2_SLEEP")); //If there is an env var, the refreshing time will take it's value
    int imageTable[80][24] = {0};//Then we initialize the table for the next function
    PBM image;//Then we create two PBM structs that will be used for the next functions
    PBM hour;
    image.length = 5;//We initialise some variables in those structures
    image.width = 39;
    hour.length = 5;
    hour.width = 3;

    while(1)//Infinite loop
    {
        system("clear");//We clear the console
        placeNumbersInHourTable(imageTable);//We place the hour in the table
        displayImageTable(imageTable);//We display that table
        printf("\n                       Refreshing in %d seconds ",sleepTime);//Then we print the refreshing message 
        fflush(stdout);//We use this to avoid that the sleep call stops everything
        for (int i = 0; i<sleepTime; i++)//Then, for the value of sleepTime in seconds,
        {
            sleep(1);//We wait 1 sec
            printf(". ");//We print a dot.
            fflush(stdout);
	    if(kbhit()){//And we use the function to kill the process if we press the spacebar.
            char ch;
    		ch = getch();
    		char kill = ' ';
    		if(ch == kill)
    		{
			system("clear");
        		exit(1);
    		}
	}
        }
    }
    return 0;//And our function will return nothing

}


