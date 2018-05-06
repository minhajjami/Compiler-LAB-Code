#include <stdio.h>
int main(void)
{
    FILE *p1,*p2; char c;
    int count=1;
    p1 = fopen("input.c", "r");
    p2 = fopen("test.txt","w");

    if(!p1) printf("\nFile can't be opened!");
    else{
            fprintf(p2,"%d",count);
            fputc(':',p2);
            count++;
            while((c=fgetc(p1))!=EOF){
                if(c=='\n'){
                    c=fgetc(p1);
                    fputc('\n',p2);
                    fprintf(p2,"%d",count);
                     fputc(':',p2);
                     count++;
                }
                fputc(c,p2);
            }
    }
    fclose(p1);
    fclose(p2);
    p2 = fopen("test.txt","r");
    while((c=fgetc(p2))!=EOF)
		printf("%c",c);
    fclose(p2);
    return 0;
}

