#include <stdio.h>
#include <stdlib.h>

struct river
{
    char name[40];
    int length;
    int drainage_area;
};

int compareRivers(const void *a,const void *b)
{
    const struct river *a1 = (const struct river *)a;
    const struct river *b1 = (const struct river *)b;

    if (a1->length < b1->length)
    {
        return 1;
    }
    if (a1->length < b1->length)
    {
        return -1;
    }
    else{
        return 0;
    }
}


int main()
{
    FILE *fptr1 = fopen("data.txt","r");
    FILE *fptr2 = fopen("output.txt","w");
    if (fptr1 == NULL)
    {
        perror("error opening file");
        fclose(fptr1);
        exit(1);
    }
    if (fptr2 == NULL)
    {
        perror("error opening file");
        fclose(fptr2);
        exit(1);
    }
    struct river arr[30];
    int num = 0;

    while (fscanf(fptr1,"%s %d %d",&arr[num].name,&arr[num].length,&arr[num].drainage_area) == 3)
    {
        num++;
    }
    
    fclose(fptr1);

    qsort(arr,num,sizeof(struct river),compareRivers);

    for (int i = 0; i < num; i++)
    {
        fprintf(fptr2,"%s %d %d\n",arr[i].name,arr[i].length,arr[i].drainage_area);
    }

    fclose(fptr2);
    
    return 0;
}