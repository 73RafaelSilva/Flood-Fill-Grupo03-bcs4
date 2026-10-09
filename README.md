# Flood-Fill-Grupo03-bcs4

Projeto desenvolvido para a disciplina de Resolução de Problemas Estruturados em Computação, focado na implementação e análise comparativa do algoritmo de preenchimento por inundação (*Flood Fill*) sobre imagens digitais no formato Bitmap (BMP 24 bits), empregando estruturas de dados dinâmicas lineares: Pilha (*Stack* / DFS) e Fila (*Queue* / BFS).

---

## Escopo do Projeto

O sistema reproduz o funcionamento do algoritmo *Flood Fill* (conhecido popularmente como a ferramenta "balde de tinta" em editores gráficos). Dado um pixel de coordenadas iniciais (X, Y) e uma nova cor de substituição, o algoritmo identifica a cor do pixel original e propaga a nova cor para todos os pixels adjacentes e conectados que possuam essa mesma tonalidade.

O projeto implementa e permite comparar duas abordagens de percurso sobre a matriz de pixels:
- **Abordagem com Pilha (DFS - Busca em Profundidade):** Utiliza uma pilha dinâmica encadeada (`Stack`), priorizando a expansão profunda e linear ao longo de um ramo até encontrar os limites antes de retroceder.
- **Abordagem com Fila (BFS - Busca em Largura):** Utiliza uma fila dinâmica encadeada (`Queue`), propagando o preenchimento de maneira uniforme em camadas concêntricas a partir do ponto de partida.

Para evidenciar a diferença de comportamento e evolução entre as duas estruturas, o sistema salva automaticamente arquivos intermediários no disco a cada 500 pixels processados, além de gerar a imagem com o resultado final.

---

## Funções dos Arquivos

- **`estruturas.h` / `estruturas.c`**: Define e gerencia as estruturas lineares dinâmicas encadeadas de Pilha e Fila com alocação em memória via ponteiros.
- **`imagem.h` / `imagem.c`**: Responsável pela leitura, manipulação de pixels, cálculo de padding, verificação de cores e gravação de arquivos no formato BMP de 24 bits.
- **`flood_fill.h` / `flood_fill.c`**: Implementa as lógicas centrais de preenchimento por inundação (Pilha e Fila), controlando as iterações e a exportação periódica de passos.
- **`main.c`**: Concentra o fluxo interativo com o usuário, menus de navegação, configuração de parâmetros e disparo dos algoritmos.

---

## Listagem das Funções

### `estruturas.c`
- `initStack(Stack* s)`: Inicializa a pilha atribuindo o ponteiro do topo como nulo.
- `push(Stack* s, Position p)`: Aloca um novo nó dinamicamente e insere a coordenada no topo da pilha.
- `pop(Stack* s)`: Remove o nó do topo da pilha, desaloca sua memória e retorna a coordenada armazenada.
- `isStackEmpty(Stack* s)`: Verifica se a pilha está vazia conferindo se o topo aponta para nulo.
- `initQueue(Queue* q)`: Inicializa a fila definindo os ponteiros de início e fim como nulos.
- `enqueue(Queue* q, Position p)`: Aloca um novo nó dinamicamente e insere a coordenada no final da fila.
- `dequeue(Queue* q)`: Remove o primeiro nó da fila, atualiza os ponteiros de encadeamento, desaloca a memória e retorna a coordenada.
- `isQueueEmpty(Queue* q)`: Verifica se a fila está vazia conferindo se o ponteiro de início é nulo.

### `imagem.c`
- `LoadBMP(ImagemBMP* img, const char* nomeArquivo)`: Lê o cabeçalho e a matriz de pixels de um arquivo BMP de 24 bits tratando o alinhamento de bytes (padding).
- `SaveBMP(ImagemBMP* img, const char* nomeArquivo)`: Escreve a estrutura de pixels e cabeçalhos em disco criando um novo arquivo BMP válido de 24 bits com padding.
- `GetPixel(ImagemBMP* img, int x, int y)`: Retorna a estrutura de cor do pixel posicionado na coordenada informada.
- `SetPixel(ImagemBMP* img, int x, int y, Cor c)`: Atribui uma nova cor ao pixel localizado na coordenada especificada da imagem.
- `VerifCores(Cor c1, Cor c2)`: Compara os canais de cor Vermelho, Verde e Azul de duas cores e retorna se são idênticas.
- `SalvarPasso(ImagemBMP* img, int passo, const char* prefixo)`: Gera e salva em disco um arquivo BMP com nome formatado registrando o estado parcial do preenchimento.
- `Limpeza(ImagemBMP* img)`: Desaloca a memória dinâmica alocada para o buffer de pixels da imagem.

### `flood_fill.c`
- `floodFillStack(ImagemBMP* img, int startX, int startY, Cor NovaCor)`: Executa o preenchimento por inundação utilizando Pilha dinâmica (DFS), salvando imagens parciais a cada 500 pixels e o resultado final.
- `floodFillQueue(ImagemBMP* img, int startX, int startY, Cor NovaCor)`: Executa o preenchimento por inundação utilizando Fila dinâmica (BFS), salvando imagens parciais a cada 500 pixels e o resultado final.

### `main.c`
- `clearBuffer()`: Esvazia o buffer de entrada do teclado para evitar resíduos na leitura de opções numéricas.
- `main()`: Loop principal do sistema que gerencia o menu, valida os parâmetros de imagem/coordenadas e dispara as rotinas de execução.

---

## Como Compilar

Para compilar o projeto completo com todas as diretivas e avisos ativados via GCC, execute no terminal:

```bash
gcc -Wall -Wextra main.c estruturas.c imagem.c flood_fill.c -o programa_flood_fill
```

Para executar o binário gerado:

```bash
./programa_flood_fill
```

---

## Formatação dos Arquivos

Para a correta execução do algoritmo:
- O arquivo de entrada deve ser obrigatoriamente uma imagem no formato **BMP de 24 bits não comprimido**.
- Já existe um arquivo de testes na raiz do projeto denominado **`teste.bmp`**, que pode ser informado diretamente ao selecionar a opção `3` do menu.
- As coordenadas inseridas na opção `4` do menu devem corresponder a posições válidas dentro dos limites da imagem:
  - 0 <= X < largura
  - 0 <= Y < altura
- Ao executar a pintura (opções `1` ou `2`), o programa gerará automaticamente arquivos na mesma pasta seguindo o padrão de nomenclatura:
  - Execução com Pilha: `pilha_passo_XXXX.bmp` e `PilhaFinal_passo_XXXX.bmp`
  - Execução com Fila: `fila_passo_XXXX.bmp` e `FilaFinal_passo_XXXX.bmp`

---

## Responsáveis pelo projeto

### Instituição
- Pontifícia Universidade Católica do Paraná (PUCPR)

### Turma
- Bacharelado em CiberSegurança (BCS04) - Escola Politécnica - Campus Curitiba

### Responsável Docente 
- Aramis Hornung Moraes

### Acadêmicos
- Arthur de Mattos Colodel
- Erick Portes Damasceno Santos
- Lucas Lauxen Motta
- Rafael Luiz da Silva
