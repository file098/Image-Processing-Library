#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "bmp.h"
#include "ip_lib.h"

int main(){

    ip_mat * mat1 = ip_mat_create(2,2,3,4);
    ip_mat * mat2 = ip_mat_create(2,2,3,2);
    ip_mat * sum = ip_mat_sum(mat1,mat2);
    printf("somma\n");
    ip_mat_show(sum);
    ip_mat * sottr = ip_mat_sub(mat1,mat2);
    printf("sottr\n");
    ip_mat_show(sottr);
    ip_mat * mean = ip_mat_mean(mat1,mat2);
    printf("mean\n");
    ip_mat_show(mean);
    ip_mat * scal = ip_mat_add_scalar(mat1,1);
    printf("scal\n");
    ip_mat_show(scal);
    ip_mat * mul = ip_mat_mul_scalar(mat1,2);
    printf("mult\n");
    ip_mat_show(mul);

    return 0;
}
