#include <stdio.h>
#include <conio.h>
int main(void)
{
    FILE *p1,*p2; char c;

    p1 = fopen("input.c", "r");
    p2 = fopen("output.txt","w");

    if(!p1) printf("\nFile can't be opened!");
    else{
        while((c=fgetc(p1))!=EOF){
                if(c=='#'){
                    while(c !='<'){
                        c=fgetc(p1);
                    }
                    if(c=='<'){
                        while(c!='>'){
                            c=fgetc(p1);
                            if(c=='>') break;
                            fputc(c,p2);
                        }
                        fputc('\n',p2);

                    }

                }

        }
    }
    fclose(p1);
    fclose(p2);

    p2 = fopen("output.txt","r");
    while((c=fgetc(p2))!=EOF)
		printf("%c",c);
    fclose(p2);

    return 0;


}
