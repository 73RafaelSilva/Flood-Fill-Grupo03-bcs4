#ifndef flood_fill_h
#define flood_fill_h
#include "imagem.h"

void floodFillStack(ImagemBMP* img, int startX, int startY, Cor NovaCor);
void floodFillQueue(ImagemBMP* img, int startX, int startY, Cor NovaCor);

#endif
