#include <stdio.h>

int main(void){
    FILE *gp;
    gp = popen(" gnuplot -persist ","w");

    fprintf(gp,"plot sin(x)\n");
    pclose(gp);
    return 0;
}