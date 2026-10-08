#ifndef flood_fill.h
#define flood_fill.h
#include "imagem.h"

void floodFillStack(ImageBMP* img, int startX, int startY, Color newColor);
void floodFillQueue(ImageBMP* img, int startX, int startY, Color newColor);

#endif
