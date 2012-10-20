
#ifndef WRITEBMP
#define WRITEBMP

//define pixelformat of windows bitmap, notice the unusual ordering of colors
typedef struct _pixel{
    unsigned char B;
    unsigned char G;
    unsigned char R;
} pixel;

//supply an array of pixels[height][width] <- notice that height comes first
int writeBMP(const char* filename, unsigned int width, unsigned int height, pixel pixels[][32]);


#endif