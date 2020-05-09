#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "bmp.h"
#include "ip_lib.h"

int main(){

    ip_mat * mat1 = ip_mat_create(2,2,3,4);
    ip_mat_show(ip_mat_subset(mat1,0,1,0,1));
    return 0;
}
