//
//  main.c
//  Created by 123Phil on 10/14/12.
//
//  You can change the height, I wanted 960 to make an iphone screen
//  This will write out to a file, "Prime.bmp" - can be changed @ line 63


//including .c's cuz blah
#include "writeBMP.c"
#include "primer.c"

#define HEIGHT 960
#define WIDTH 32


int main(void)
{
    auto int* primes  = arrayOfPrimes(HEIGHT);
    
/* show bits of first 32 primes for debug...
    int ctr;
    int ctr2;
    char a;
    for (ctr = 0; ctr < 32; ctr++)
        {
        for (ctr2 = 31; ctr2 >=0; ctr2--)
            {
            a = ((primes[ctr] >> ctr2) & 0x1) ? '1' : '0';
            printf("%c", a);
            }
        printf("\n");
        }
*/
    
    pixel pix[HEIGHT][WIDTH];
    pixel *pp;
    
    int row;
    int bit;
    for (row = 0; row < HEIGHT; row++)
        {
        pp = pix[(HEIGHT-1)-row];
        
        for (bit = 0; bit < WIDTH; bit++)
            {
            if((primes[row] >> ((WIDTH-1)-bit)) & 0x1)
                {
                pp->B = 255;
                pp->G = 255;
                pp->R = 255;
                }
            else{
                pp->B = 0;
                pp->G = 0;
                pp->R = 0;
                }
            pp++;
            }
        
        }
    
    writeBMP("Prime.bmp", WIDTH, HEIGHT, pix);
    free(primes);
    
    return 0;
}
