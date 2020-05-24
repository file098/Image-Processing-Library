#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "bmp.h"
#include "ip_lib.h"

int main(){
    /* HACK: Testa le dimensioni dell'output */
    Bitmap * new;
    ip_mat * out;

    Bitmap * picb = bm_load("flower2.bmp");
    ip_mat * pic = bitmap_to_ip_mat(picb);

    /*
    Filter testing

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
    
    out = ip_mat_corrupt(pic,255);
    new = ip_mat_to_bitmap(out);
    bm_save(new,"new.bmp");

    return 0;
}
