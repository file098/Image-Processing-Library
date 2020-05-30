#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "bmp.h"
#include "ip_lib.h"

int main(){

    Bitmap * new;
    ip_mat * out;

    Bitmap * pica = bm_load("mongolfiere.bmp");
    ip_mat * pic2 = bitmap_to_ip_mat(pica);
    Bitmap * picb = bm_load("flower2.bmp");
    ip_mat * pic = bitmap_to_ip_mat(picb);
    ip_mat * controllo = ip_mat_create(5,5,3,1.0);
    ip_mat_show(controllo);

    printf("SUBSET\n");
    ip_mat_show(ip_mat_subset(controllo,1,2,1,5));
    /*
    printf("SUM\n");
    ip_mat_show(ip_mat_sum(controllo,controllo));
    printf("SUB\n");
    ip_mat_show(ip_mat_sub(controllo,controllo));
    printf("MULT SCALAR\n");
    ip_mat_show(ip_mat_mul_scalar(controllo, 5));
    printf("ADD SCALAR\n");
    ip_mat_show(ip_mat_add_scalar(controllo, 5));
    printf("MEAN\n");
    ip_mat_show(ip_mat_mean(controllo, controllo));
    

    out = ip_mat_to_gray_scale(pic);
    new = ip_mat_to_bitmap(out);
    bm_save(new,"grey.bmp");

    out = ip_mat_blend(pic,pic2,0.5);
    new = ip_mat_to_bitmap(out);
    bm_save(new,"blend.bmp");

    out = ip_mat_brighten(pic,50.0);
    new = ip_mat_to_bitmap(out);
    bm_save(new,"brigthen.bmp");

    out = ip_mat_corrupt(pic,100.0);
    clamp(out,0,255);
    new = ip_mat_to_bitmap(out);
    bm_save(new,"corrupt.bmp");

    /*Filter testing */

    /*
    ip_mat * sharp = create_sharpen_filter();
    ip_mat * edge = create_edge_filter();
    ip_mat * emboss = create_emboss_filter();
    ip_mat * average = create_average_filter(5,5,3);
    ip_mat * gauss = create_gaussian_filter(9,9,3,5);

    out = ip_mat_convolve(pic,sharp);
    clamp(out,0.0,255.0); 
    rescale(out,255.0);
    new = ip_mat_to_bitmap(out);
    bm_save(new,"sharp.bmp");

    out = ip_mat_convolve(pic,edge);
    clamp(out,0.0,255.0);
    rescale(out,255.0);
    new = ip_mat_to_bitmap(out);
    bm_save(new,"edge.bmp");

    out = ip_mat_convolve(pic,emboss);
    clamp(out,0.0,255.0);
    rescale(out,255.0);
    new = ip_mat_to_bitmap(out);
    bm_save(new,"emboss.bmp");

    out = ip_mat_convolve(pic,average);
    clamp(out,0.0,255.0);
    rescale(out,255.0);
    new = ip_mat_to_bitmap(out);
    bm_save(new,"average.bmp");

    out = ip_mat_convolve(pic,gauss);
    clamp(out,0.0,255.0);
    rescale(out,255.0);
    new = ip_mat_to_bitmap(out);
    bm_save(new,"gauss.bmp");
    */

    return 0;
}
