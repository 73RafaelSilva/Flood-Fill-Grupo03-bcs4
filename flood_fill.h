#ifndef flood_fill.h
#define flood_fill.h
#include "imagem.h"

void floodFillStack(ImagemBMP* img, int startX, int startY, Color newColor);
void floodFillQueue(ImagemBMP* img, int startX, int startY, Color newColor);

#endif
