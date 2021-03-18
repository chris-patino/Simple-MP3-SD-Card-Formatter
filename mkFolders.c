#include <stdio.h>
#include <stdlib.h>

int main()

{
    char mkdir[10][3000];

    for(int i=0; i<11;i++)
    {
        int j=0;
        mkdir[i][j++]='m';
        mkdir[i][j++]='k';
        mkdir[i][j++]='d';
        mkdir[i][j++]='i';
        mkdir[i][j++]='r';
        mkdir[i][j++]=' ';
        mkdir[i][j++]='E';
        mkdir[i][j++]=':';
        mkdir[i][j++]='\\';
        mkdir[i][j++]=i+'0';

        for (int k=0; k<50; k++)
        {
            if(k<10)
            {
                mkdir[i][j++]='\\';
                mkdir[i][j++]='0';
                mkdir[i][j++]='0';
                mkdir[i][j++]=k+'0';
                //printf("%s\n", mkdir);
            }
            else if(k<100)
            {
                mkdir[i][j++]='\\';
                mkdir[i][j++]='0';
                mkdir[i][j++]=k/10+'0';
                mkdir[i][j++]=k%10+'0';
                //printf("%s\n", mkdir);
            }
            else if (k<1000)
            {
                mkdir[i][j++]='\\';
                mkdir[i][j++]=k/100+'0';
                mkdir[i][j++]=(k%100)/10+'0';
                mkdir[i][j++]=k%10+'0';
                //printf("%s\n", mkdir);
            }
            //printf("%s\n", mkdir[i]);
            system(mkdir[i]);

        }
    }
}
