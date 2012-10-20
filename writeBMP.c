//
//  writeBMP.c
//
//  Created by 123Phil on 10/14/12.
//  Code borrowed from: http://pastebin.com/qCRHiPEZ
//  Original author is: http://www.reddit.com/user/Hellsheep
//  edited a bit so that it runs with my main
//  It's not perfect, but I'm really greatful for it

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "writeBMP.h"



//supply an array of pixels[height][width] <- notice that height comes first
int writeBMP(const char* filename, unsigned int width, unsigned int height, pixel pixels[][32]) {
    int fd = open(filename, O_WRONLY|O_CREAT|O_TRUNC,S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);  
    static unsigned char header[54] = {66,77,0,0,0,0,0,0,0,0,54,0,0,0,40,0,0,0,0,0,0,0,0,0,0,0,1,0,24}; //rest is zeroes
    unsigned int pixelBytesPerRow = width*sizeof(pixel);
    unsigned int paddingBytesPerRow = (4-(pixelBytesPerRow%4))%4;
    unsigned int* sizeOfFileEntry = (unsigned int*) &header[2];
    *sizeOfFileEntry = 54 + (pixelBytesPerRow+paddingBytesPerRow)*height;  
    unsigned int* widthEntry = (unsigned int*) &header[18];    
    *widthEntry = width;
    unsigned int* heightEntry = (unsigned int*) &header[22];    
    *heightEntry = height;    
    write(fd, header, 54);
    static unsigned char zeroes[3] = {0,0,0}; //for padding    
    int row;
    for (row = 0; row < height; row++) {
        write(fd,&(pixels[row]),pixelBytesPerRow);
        write(fd,zeroes,paddingBytesPerRow);
    }
    close(fd);
    return 0;
}
