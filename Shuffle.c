//TODO:
//Make the move out compatible with the new
//folder structure

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int songTotal = 133;
    int songIndex[1000], mixUp[songTotal];
    char titles[1000][1000], cd[songTotal][200];
    int counter=39;

    FILE *fp ; //file pointer


    if((fp=fopen("D:\\Programs\\OrderList.txt","r"))==NULL)
    {
        printf("Unable to open file\n Ending program...");
        return 1;
    }

    for(int i=0;i<songTotal;i++)
    {
        fscanf(fp,"%d", &songIndex[i]);
        fscanf(fp, " %[^\n]", titles[i]);
    }

    fclose(fp);

    //move files out before shuffle
    for(int i=0;i<songTotal;i++)
    {
        int j=0;
        cd[i][j++]='c';
        cd[i][j++]='d';
        cd[i][j++]=' ';
        cd[i][j++]='D';
        cd[i][j++]=':';
        cd[i][j++]='\\';

        if(i<10)
        {

            cd[i][j++]='0';
            cd[i][j++]='0';
            cd[i][j++]=i+'0';
            //printf("%s\n", mkdir);
        }
        else if(i<100)
        {
            cd[i][j++]='0';
            cd[i][j++]=i/10+'0';
            cd[i][j++]=i%10+'0';
            //printf("%s\n", mkdir);
        }
        else if (i<1000)
        {
            cd[i][j++]=i/100+'0';
            cd[i][j++]=(i%100)/10+'0';
            cd[i][j++]=i%10+'0';
            //printf("%s\n", mkdir);
        }
        //printf("%s\n", cd[i]);


        cd[i][j++]=' ';
        cd[i][j++]='&';
        cd[i][j++]='&';
        cd[i][j++]=' ';
        cd[i][j++]='m';
        cd[i][j++]='o';
        cd[i][j++]='v';
        cd[i][j++]='e';
        cd[i][j++]=' ';
        cd[i][j++]='\"';

        while(!(titles[i][j-19]=='.' && titles[i][j+1-19]=='m' &&  titles[i][j+2-19]=='p' &&  titles[i][j+3-19]=='3'))
        {
            cd[i][j++]=titles[i][-19+j];
            //printf("%c\n", cd[i][j-1]);
        }

        cd[i][j++]='.';
        cd[i][j++]='m';
        cd[i][j++]='p';
        cd[i][j++]='3';
        cd[i][j++]='\"';
        cd[i][j++]=' ';
        cd[i][j++]='D';
        cd[i][j++]=':';
        cd[i][j++]='\\';
        cd[i][j++]='P';
        cd[i][j++]='r';
        cd[i][j++]='o';
        cd[i][j++]='g';
        cd[i][j++]='r';
        cd[i][j++]='a';
        cd[i][j++]='m';
        cd[i][j++]='s';
        //printf("%s\n", cd[i]);
        system(cd[i]);
    }

    //general area of shuffle part of the program.
    for(int i=0;i<songTotal;i++)
        printf("%03d %s\n", songIndex[i], titles[i]);

        if((fp=fopen("D:\\Programs\\OrderList.txt","w"))==NULL)
        {
            printf("Unable to open file\n Ending program...");
            return 1;
        }

        //creation of mixing vector.
        for(int i=0; i<songTotal;i++)
        {
            mixUp[i]=i;
        }
        for(int i =0; i<songTotal/2;i++)
        {
            mixUp[2*i]=i+songTotal/2;
            mixUp[2*i+1]=i;
        }

        for(int i=0; i<songTotal;i++)
        {
            mixUp[i]=songTotal-1-mixUp[i];
            mixUp[i]+=11;
            mixUp[i]%=songTotal;
        }
        //end creation of mixing vector

        for(int i=0;i<songTotal;i++)
        {
            fprintf(fp,"%03d %s\n", songIndex[i], titles[mixUp[mixUp[i]]]);
            //printf("%d\n",mixUp[mixUp[i]]);
        }

        fclose(fp);
        //end shuffle

    return 0;
}
