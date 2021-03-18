#include <stdio.h>
#include <stdlib.h>

int main()
{
    char titles[1000][150];
    int songTotal=0;
    FILE *fp ; //file pointer

    if((fp=fopen("D:\\Programs\\SongList.txt","r"))==NULL)
    {
        printf("Unable to open file\n Ending program...");
        return 1;
    }


    while(fscanf(fp, " %[^\n]", titles[songTotal++])!=EOF);

    printf("%d\n", songTotal);

    fclose(fp);

    if((fp=fopen("D:\\Programs\\OrderList.txt","w"))==NULL)
    {
        printf("Unable to open file\nEnding program...");
        return 1;
    }

    for(int i=0;i<songTotal;i++)
    {
        fprintf(fp,"%03d %s\n", i%51, titles[i]);
        //printf("%s\n", titles[i]);
    }

    fclose(fp);

    return 0;
}
