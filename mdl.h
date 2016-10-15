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
*/
int LCS(std::string, std::string);

/*
Aluno: Lucas Ferreira Lima - 11406537
Encotra em um dado conjunto de inteiros positivos se existe algum subconjunto 
cujo a soma é sum.

Parametros: Vector com conjunto de inteiros positivos e soma que deseja ser
			comparada.
*/
bool SSP(std::vector<int> , int);

/*
Encontra o número mínimo de operações necessárias para transformar um string no outro.
Sendo essas oeprações: adição, remoção e substituíção

Parametros: Strings a serem comparadas.
*/
int DDP(std::string, std::string);

//--------------- Algoritmos gulosos ------------------


typedef struct MinHeapNode
{
    char data;  // One of the input characters
    unsigned freq;  // Frequency of the character
    MinHeapNode *left, *right; // Left and right child of this node
} MinHeapNode;
 
// A Min Heap:  Collection of min heap (or Hufmman tree) nodes
typedef struct MinHeap
{
    unsigned size;    // Current size of min heap
    unsigned capacity;   // capacity of min heap
    MinHeapNode **array;  // Attay of minheap node pointers
} MinHeap;

// A utility function allocate a new min heap node with given character
// and frequency of the character
MinHeapNode* newNode(char data, unsigned freq);

// A utility function to create a min heap of given capacity
MinHeap* createMinHeap(unsigned capacity);

// A utility function to swap two min heap nodes
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b);

// The standard minHeapify function.
void minHeapify(struct MinHeap* minHeap, int idx);

// A utility function to check if size of heap is 1 or not
int isSizeOne(struct MinHeap* minHeap);

// A standard function to extract minimum value node from heap
MinHeapNode* extractMin(struct MinHeap* minHeap);

// A utility function to insert a new node to Min Heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode);

// A standard funvtion to build min heap
void buildMinHeap(struct MinHeap* minHeap);

// Utility function to check if this node is leaf
int isLeaf(struct MinHeapNode* root);

// Creates a min heap of capacity equal to size and inserts all character of 
// data[] in min heap. Initially size of min heap is equal to capacity
MinHeap* createAndBuildMinHeap(char data[], int freq[], int size);

// The main function that builds Huffman tree
MinHeapNode* buildHuffmanTree(char data[], int freq[], int size);

void HuffmanCodes(char data[], int freq[], int size);

#endif //__MDL_H_