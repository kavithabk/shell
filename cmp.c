#include<stdio.h>
#include<fcntl.h>

#define BUFFER 45

int main(int argc,char *argv[])
{

    FILE *fp1,*fp2;
    /*lc-line count*/
    int i = 0, lc = 1;
    char p,q;
    char buf1[BUFFER], buf2[BUFFER];

    if (argc == 3) {
        /*Open both files in Read mode*/
        fp1 = fopen(argv[1], "r");

        if (fp1 == NULL) {
            printf("%s : File opening Error\n", argv[1]);
            return -1;
        }    

        fp2 = fopen(argv[2], "r");

        if(fp2 == NULL) {
            printf("%s : File opening Error\n", argv[2]);
            return -1;
        }    

        while(((p = getc(fp1)) != EOF) && ((q = getc(fp2)) != EOF)) {
            i++;
            if (p == '\n') ++lc;
            /*Traverse the 2 files until first mismatch occurs*/
            if (p != q) {
                printf("%s\t%s differ: char %d,line %d\n",argv[1],argv[2],i,lc);
                printf("two characters of mismatch are %c and %c\n",p,q);
                break;
            }
        }

        fclose(fp1);
        fclose(fp2);
    } else
        printf("Error : Usage cmp <fname1> <fname2>\n");

    return 0;
}
