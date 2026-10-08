#include "flood_fill.h"
#include "estruturas.h"

void floodFillStack(ImagemBMP* img, int startX, int startY, Cor NovaCor) {
    if (startX < 0 || startX >= img->largura || startY < 0 || startY >= img->altura) return;
    
    Cor CorOriginal = GetPixel(img, startX, startY);
    if (VerifCores(CorOriginal, NovaCor)) return;

    Stack s;
    initStack(&s);
    
    Position p = {startX, startY};
    push(&s, p);
    
    int contador = 0;

    while (!isStackEmpty(&s)) {
        Position atual = pop(&s);

        if (atual.x < 0 || atual.x >= img->largura || atual.y < 0 || atual.y >= img->altura) continue;
        if (!VerifCores(GetPixel(img, atual.x, atual.y), CorOriginal)) continue;

        SetPixel(img, atual.x, atual.y, NovaCor);
        contador++;
        
        if (contador % 500 == 0) SalvarPasso(img, contador, "pilha");
        Position p1 = {atual.x, atual.y - 1}; push(&s, p1);
        Position p2 = {atual.x, atual.y + 1}; push(&s, p2);
        Position p3 = {atual.x - 1, atual.y}; push(&s, p3);
        Position p4 = {atual.x + 1, atual.y}; push(&s, p4);
    }
    SalvarPasso(img, contador, "PilhaFinal");
}

void floodFillQueue(ImagemBMP* img, int startX, int startY, Cor NovaCor) {
    if (startX < 0 || startX >= img->largura || startY < 0 || startY >= img->altura) return;
    
    Cor CorOriginal = GetPixel(img, startX, startY);
    if (VerifCores(CorOriginal, NovaCor)) return;

    Queue q;
    initQueue(&q);
    
    Position p = {startX, startY};
    enqueue(&q, p);
    int contador = 0;

    while (!isQueueEmpty(&q)) {
        Position atual = dequeue(&q);

        if (atual.x < 0 || atual.x >= img->largura || atual.y < 0 || atual.y >= img->altura) continue;
        if (!VerifCores(GetPixel(img, atual.x, atual.y), CorOriginal)) continue;

        SetPixel(img, atual.x, atual.y, NovaCor);
        contador++;
        
        if (contador % 500 == 0) SalvarPasso(img, contador, "fila");

        Position p1 = {atual.x, atual.y - 1}; enqueue(&q, p1);
        Position p2 = {atual.x, atual.y + 1}; enqueue(&q, p2);
        Position p3 = {atual.x - 1, atual.y}; enqueue(&q, p3);
        Position p4 = {atual.x + 1, atual.y}; enqueue(&q, p4);
    }
    SalvarPasso(img, contador, "FilaFinal");
}
