#include <vector>
#include <string>

#ifndef __MDL_H__
#define __MDL_H__

#define MAX_TREE_HT 100
//--------------- Pogramação dinamica ------------------
/*
Retorna o maior entre dois inteiros.
Parametros: Numeros a serem comparados.
*/
int max(int, int);

int min(int, int, int);

/*
Aluno: Lucas Ferreira Lima - 11406537
Encontra a maior subsequência comum a duas sequências X e Y, i.e uma 
subsequência de uma sequência X de caracteres pode ser obtida removendo alguns 
caracteres dessa sequência.

Parametros: Subsequêcias a serem comparadas.
Retorno: Valor da maior subsequencia.
*/
int LCS(std::string, std::string);

/*
Aluno: Lucas Ferreira Lima - 11406537
Encotra em um dado conjunto de inteiros positivos se existe algum subconjunto 
cujo a soma é sum.

Parametros: Vector com conjunto de inteiros positivos e soma que deseja ser
			comparada.
Retorno: Numero de subconjuntos encontrados.
*/
bool SSP(std::vector<int> , int);

/*
Aluno: Lucas Ferreira Lima - 11406537
Encontra o número mínimo de operações necessárias para transformar um string no outro.
Sendo essas oeprações: adição, remoção e substituíção

Parametros: Strings a serem comparadas.
Retorno: Numero de operções nescessárias.
*/
int DDP(std::string, std::string);

//--------------- Algoritmos gulosos ------------------
/*
Aluno: Lucas Ferreira Lima - 11406537
Huffman Coding
*/

/*
Nó da MinHeap. 
Contém um campo para o dado (um dos caracteres de input),
frequênica do dado,
e aponta para os filhos da direita e esquerta.
*/
typedef struct MinHeapNode
{
    char data;
    unsigned freq;
    MinHeapNode *left, *right;
} MinHeapNode;

/*
Uma MinHeap. 
Contém o tamanho da MinHeap,
capacidade da mesma,
e um array de todos os filhos.
*/
typedef struct MinHeap
{
    unsigned size;
    unsigned capacity;
    MinHeapNode **array;
} MinHeap;

/*
Função que aloca um nova minHeap.
Parametro: Um caractere e sua frequencia.
Retorno: MinHeap com dado caractere e frequencia.
*/
MinHeapNode* newNode(char data, unsigned freq);

/*
Função que cria uma MinHeap de dada capacidade.
Parametro: Capacidade da MinHeap a ser craida.
Retorno: MinHeap com dada capacidade.
*/
MinHeap* createMinHeap(unsigned capacity);

/*
Troca dois nó de uma MinHeap.
Parametro: Dois nó de uma MinHeap.
Retorno: Não há.
*/
void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b);
/*
Função padrão de minHeapify
Parametro: MinHeap e index.
Retorno: Não há
*/
void minHeapify(MinHeap* minHeap, int idx);
/*
Checa se o tamanho da heap é 1 ou não.
Paramentro: Uma MinHeap.
Retorno: 0 se o tamnho for diferente de 1, diferente de 0 se o
	tamanho for 1.
*/
int isSizeOne(MinHeap* minHeap);
/*
Extrai o menor nó de menor valor da MinHeap.
Parametro: Uma MinHeap.
Retorno: O nó de menor valor da MinHeap.
*/
MinHeapNode* extractMin(MinHeap* minHeap);

/*
Insere um novo nó à uma MinHeap.
Parametro: Um nó a ser adcionado na MinHeap e respectiva MinHeap.
Retorno: Não há.
*/
void insertMinHeap(MinHeap* minHeap, MinHeapNode* minHeapNode);

/*
Função para construir MinHeap.
Parametro: MinHeap á qual será construida.
Retorno: Não há.
*/
void buildMinHeap(MinHeap* minHeap);

/*
Checa se o nó é folha
Paramentro: Uma MinHeap.
Retorno: 0 se o nó não for folha, diferente de 0 se o nó for folha.
*/
int isLeaf(MinHeapNode* root);

/*
Cria uma MinHeap de capacidade igual a o tamanho e insere todos os caracteres
do array data na MinHeap. Inicializa o tamanha da MinHeap com a capacidade.
Parametro: array de dados que serão inseridos na MinHeap, frequêcia dos dados,
e o tamanho.
Retorno: MinHeap criada dito as especificações da função.
*/
MinHeap* createAndBuildMinHeap(char data[], int freq[], int size);

/*
Constrói a árvore de Huffman 
Parametro: array de dados, frequencia dos dados e o tamanho.
Retorno: Huffman coding
*/
MinHeapNode* buildHuffmanTree(char data[], int freq[], int size);

/*
Função principal que constrói e imprime Huffman code.
Parametro: Array de dados, frequencia dos dados e tamanho.
Retorno: Não há.
*/ 
void HuffmanCodes(char data[], int freq[], int size);

/*
Imprime na tela o codigo de Huffman da raíz da Àrvore de Huffman. Usa o array
arr para aramazenar os códigos.
Parametro: MinHeap que é a Árvore de Huffman, array para o armazenamento dos
	códigos e o topo.
Retorno: Não há.
*/
void printCodes(MinHeapNode* root, int arr[], int top);

/*
Imprime uma array de tamnho n nao tela.
Parametro: array e tamanho.
Retorno: Não há.
*/
void printArr(int arr[], int n);
//----------------------------------------------------------------------------------------------
/*
Aluno: Lucas Ferreira Lima - 11406537
Kruskal MST
*/

/*
Estrutura para representar aresta de um grafos com peso.
Contém a fonte, o destino e o peso.
*/
// a structure to represent a weighted edge in graph
typedef struct Edge
{
    int src, dest, weight;
} Edge;
/*
Estrutura para representar um grafo conectado, indireto e com peso.
Contém numero de vertices (V), numero de arestas (E), e um array de arestas.
*/ 
typedef struct Graph
{
    int V, E;
    Edge* edge;
} Graph;

typedef struct subset
{
    int parent;
    int rank;
} subset;

/*
Cria grafo com V vertices e E arestas.
Parametro: Numero de vertices e de arestas.
Retorno: Grafo descrito na função.
*/
Graph* createGraph(int V, int E);

/*
Faz a união de dois dois sets. (Usa união por rank)
Parametro: Um subset, e dois set.
Retorno: Não há.
*/
void Union(subset subsets[], int x, int y);

/*
Compara duas arestas de acordo com seu peso. Usa qsort com algoritimo de 
ordenação.
Parametro: Duas arestas a serem comparada.
Retorno: 
*/
int myComp(const void* a, const void* b);

/*
Função principal para construir MST usando algoritmo de Kruskal.
Parametro: Grafo que se deseja construir a MST.
Retorno: Não há.
*/
// The main function to construct MST using Kruskal's algorithm
void KruskalMST(Graph* graph);

#endif //__MDL_H_