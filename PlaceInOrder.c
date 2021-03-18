//TODO:
//Make the move out compatible with th enew folder structure

#include <stdio.h>
#include <stdlib.h>

int main()
{
    //IMPORTANT
    int songTotal=133, j; //Make sure this number is correct before running!!!
    //IMPORTANT

    wchar_t songIndex[songTotal][4], titles[songTotal][200],
    moveCmd[songTotal][200], cd[songTotal][10];
    //moveCmd[0][3000] = "move D:\\9", moveCmd[1][3000] = "move D:\\9",
    //moveCmd[2][3000] = "move D:\\9", moveCmd[3][3000] = "move D:\\9";

    FILE *fp ; //file pointer

    if((fp=fopen("D:\\Programs\\OrderList.txt","r"))==NULL)
    {
        printf("Unable to open file\nEnding program...");
        return 1;
    }

    for(int i=0;i<songTotal;i++)
    {
        fscanf(fp,"%s", songIndex[i]);
        fscanf(fp, " %[^\n]", titles[i]);
    }

    fclose(fp);

    /* This part seems to have once been used to make folders
    Not sure why I made it, but I'll keep it until I know -1/10/21
    int j;
    for (int i=0; i<4; i++)
    {
    j=6;
        for (int k=50*i; i<50*i+50; i++)
        {
            if(i<10)
            {
                mkdira[j++]='\\';
                mkdira[j++]='0';
                mkdira[j++]='0';
                mkdira[j++]=i+'0';
                //printf("%s\n", mkdir);
            }
            else if(i<100)
            {
                mkdira[j++]='\\';
                mkdira[j++]='0';
                mkdira[j++]=i/10+'0';
                mkdira[j++]=i%10+'0';
                //printf("%s\n", mkdir);
            }
            else if (i<1000)
            {
                mkdira[j++]='\\';
                mkdira[j++]=i/100+'0';
                mkdira[j++]=(i%100)/10+'0';
                mkdira[j++]=i%10+'0';
                //printf("%s\n", mkdir);
            }
            //printf("%s\n", mkdira);
            system(mkdira);

        }
    }
    */

    //move in
    for(int i=0;i<songTotal-1;i++)
    {
        j=0;
        moveCmd[i][j++]='m';
        moveCmd[i][j++]='o';
        moveCmd[i][j++]='v';
        moveCmd[i][j++]='e';
        moveCmd[i][j++]=' ';

        moveCmd[i][j++]='\"';
        moveCmd[i][j++]='D';
        moveCmd[i][j++]=':';
        moveCmd[i][j++]='\\';
        moveCmd[i][j++]='9';

        while(!(titles[i][j-6]=='.' && titles[i][j+1-6]=='m' &&  titles[i][j+2-6]=='p' &&  titles[i][j+3-6]=='3'))
        {
            moveCmd[i][j++]=titles[i][-6+j];
            //printf("%c\n", moveCmd[i][j-1]);
        }

        moveCmd[i][j++]='.';
        moveCmd[i][j++]='m';
        moveCmd[i][j++]='p';
        moveCmd[i][j++]='3';
        moveCmd[i][j++]='\"';
        moveCmd[i][j++]=' ';

        moveCmd[i][j++]='D';
        moveCmd[i][j++]=':';
        moveCmd[i][j++]='\\';
        moveCmd[i][j++]=i/51 + '0';
        moveCmd[i][j++]='\\';

        for(int k=0;k<3;k++)
            moveCmd[i][j++]=songIndex[i][k];
        printf("%ls\n", moveCmd[i]);
        //system(moveCmd[i]);
    }
    //printf("曇天   宇多田ヒカル\n");
}
