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
/*
Aluno: Lucas Ferreira Lima - 11406537
Huffman Coding
*/

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

void printCodes(MinHeapNode* root, int arr[], int top);

void printArr(int arr[], int n);
//----------------------------------------------------------------------------------------------
/*
Aluno: Lucas Ferreira Lima - 11406537
Kruskal MST
*/

// a structure to represent a weighted edge in graph
typedef struct Edge
{
    int src, dest, weight;
} Edge;
 
// a structure to represent a connected, undirected and weighted graph
typedef struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    int V, E;
 
    // graph is represented as an array of edges. Since the graph is
    // undirected, the edge from src to dest is also edge from dest
    // to src. Both are counted as 1 edge here.
    Edge* edge;
} Graph;

typedef struct subset
{
    int parent;
    int rank;
} subset;

// Creates a graph with V vertices and E edges
Graph* createGraph(int V, int E);

// A function that does union of two sets of x and y
// (uses union by rank)
void Union(subset subsets[], int x, int y);

// Compare two edges according to their weights.
// Used in qsort() for sorting an array of edges
int myComp(const void* a, const void* b);

// The main function to construct MST using Kruskal's algorithm
void KruskalMST(Graph* graph);

#endif //__MDL_H_