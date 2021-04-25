#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct
{
    int E;
    int a[1000][1000];
} Orientat, Neorientat;


char orase[1000][30];
int noduri=0;
int grad[1000];

void citire()
{
    Orientat.E=0;
    Neorientat.E=0;
    for(int i=0; i<1000; i++)
        for(int j=0; j<1000; j++)
        {
            Orientat.a[i][j]=0;
            Neorientat.a[i][j]=0;
        }

    char cuv[30],top[30];
    FILE *f;
    f=fopen("_all_files.txt","r");

    while (!feof(f))
    {
        fscanf(f, "%s", cuv);
        if (!feof(f))
        {
            fgetc(f);

        }
        FILE *f1;
        f1=fopen(cuv,"r");
        int ant=-1;
        int cur;
        while (!feof(f1))
        {
            fgets(top,30,f1);
            if(top[strlen(top)-1]=='\n')
                top[strlen(top)-1]='\0';
            int ok=0;
            for(int i=0; i<noduri; i++)
                if(strcmp(top, orase[i])==0)
                {
                    ok++;
                    cur=i;
                }
            if (ok==0)
            {
                strcpy(orase[noduri],top);
                noduri++;
                cur=noduri-1;
            }
            grad[cur]++;
            if(ant!=-1)
            {
               if(Orientat.a[ant][cur]==0)
                {
                    Orientat.E++;
                    Orientat.a[ant][cur]=1;
                }
            }
            ant=cur;
        }
        fclose(f1);

    }

}
void verificare()
{
    int val_max=-1, Max;
    for(int i=0; i<noduri; i++)
    {
        if(grad[i]>=val_max)
        {
            val_max=grad[i];
            Max=i;
        }
    }
    printf("Gara cu cele mai multe vizite este:%s \n",orase[Max]);
}


int main()
{
    citire();
    printf("Numarul de noduri este: %d\n",noduri);
    verificare();
    return 0;
}
