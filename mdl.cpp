#include "mdl.h"
#include <iostream>
#include <cstdlib>

//---------------------------------- Pogramação dinamica --------------------------------------
int max(int a, int b)
{
	return a>b? a:b;
}

int min(int a, int b, int c)
{
	return a < b ? (a < c ? a:c): (b < c ? b:c);
}

/*
Seguindo a definição da função:
LCS(Xi,Yj) = 0, se i = 0 ou j = 0;
LCS(Xi,Yj) = LCS(X(i-1), Y(j-1)) + 1, se Xi = Yj;
LCS(Xi,Yj) = max(LCS(Xi, Y(j-1), LCS(X(i-1),Yj)), se Xi != Yj.
*/
int LCS(std::string s1, std::string s2)
{
	int x = s1.length(), y = s2.length();
	int L[x+1][y+1];
	for(int i = 0; i<=x; i++){
		for(int j = 0; j<=y; j++){
			if(!j || !i) L[i][j] = 0;
			else if(s1[i-1] == s2[j-1]) L[i][j] = L[i-1][j-1] + 1;
			else L[i][j] = max(L[i][j-1], L[i-1][j]);
		}
	}
	return L[x][y];
}

/*
Seguindo a definição da função:
SSP(set, n, sum) = false, se sum > 0 e n = 0;
SSP(set, n, sum) = true, se sum = 0;
SSP(set, n, sum) = SSP(set, n-1, sum) || SSP(set, n-1, sum-set[n-1]), caso contrario.
*/
bool SSP(std::vector<int> set, int sum)
{
	int n = set.size();
	bool subset[sum+1][n+1];

	for(int i = 0; i <= n; ++i) subset[0][i] = true;

	for(int i = 0; i <= sum; ++i) subset[i][0] = false;

	for(int i = 1; i <= sum; ++i)
		for(int j = 1; j <= n; ++j){
			subset[i][j] = subset[i][j-1];
			if(i >= set[j-1]) subset[i][j] = subset[i][j] || subset[i - set[j-1]][j-1];
		}

	return subset[sum][n];
}
/*

*/
int DDP(std::string str1, std::string str2)
{
	int m = str1.size();
	int n = str2.size();
    int dp[m+1][n+1];    
    for (int i=0; i<=m; i++)
        for (int j=0; j<=n; j++)      
            if (i==0) dp[i][j] = j;    
            else if (j==0) dp[i][j] = i;            
            else if (str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1];
			else dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]); 

    return dp[m][n];
}

//-------------------------------- Algoritmos gulosos ---------------------------------------------
MinHeapNode* newNode(char data, unsigned freq)
{
    MinHeapNode* temp = new MinHeapNode();
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}
 
// A utility function to create a min heap of given capacity
MinHeap* createMinHeap(unsigned capacity)
{
    MinHeap* minHeap = new MinHeap();
    minHeap->size = 0;  // current size is 0
    minHeap->capacity = capacity;
    minHeap->array = new MinHeapNode*[minHeap->capacity];
    return minHeap;
}
 
// A utility function to swap two min heap nodes
void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b)
{
    MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}
 
// The standard minHeapify function.
void minHeapify(MinHeap* minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
 
    if (left < minHeap->size &&
        minHeap->array[left]->freq < minHeap->array[smallest]->freq)
      smallest = left;
 
    if (right < minHeap->size &&
        minHeap->array[right]->freq < minHeap->array[smallest]->freq)
      smallest = right;
 
    if (smallest != idx)
    {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}
 
// A utility function to check if size of heap is 1 or not
int isSizeOne(MinHeap* minHeap)
{
    return (minHeap->size == 1);
}
 
// A standard function to extract minimum value node from heap
MinHeapNode* extractMin(MinHeap* minHeap)
{
    MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}
 
// A utility function to insert a new node to Min Heap
void insertMinHeap(MinHeap* minHeap, MinHeapNode* minHeapNode)
{
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1)/2]->freq)
    {
        minHeap->array[i] = minHeap->array[(i - 1)/2];
        i = (i - 1)/2;
    }
    minHeap->array[i] = minHeapNode;
}
 
// A standard funvtion to build min heap
void buildMinHeap(MinHeap* minHeap)
{
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}
 

// Utility function to check if this node is leaf
int isLeaf(MinHeapNode* root)
{
    return !(root->left) && !(root->right) ;
}
 
// Creates a min heap of capacity equal to size and inserts all character of 
// data[] in min heap. Initially size of min heap is equal to capacity
MinHeap* createAndBuildMinHeap(char data[], int freq[], int size)
{
    MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}
 
// The main function that builds Huffman tree
MinHeapNode* buildHuffmanTree(char data[], int freq[], int size)
{
    MinHeapNode *left, *right, *top;
 
    // Step 1: Create a min heap of capacity equal to size.  Initially, there are
    // modes equal to size.
    MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);
 
    // Iterate while size of heap doesn't become 1
    while (!isSizeOne(minHeap))
    {
        // Step 2: Extract the two minimum freq items from min heap
        left = extractMin(minHeap);
        right = extractMin(minHeap);
 
        // Step 3:  Create a new internal node with frequency equal to the
        // sum of the two nodes frequencies. Make the two extracted node as
        // left and right children of this new node. Add this node to the min heap
        // '$' is a special value for internal nodes, not used
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
 
    // Step 4: The remaining node is the root node and the tree is complete.
    return extractMin(minHeap);
}
// A utility function to print an array of size n
void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        std::cout << arr[i];
    std::cout << std::endl;
}
 
void printCodes(MinHeapNode* root, int arr[], int top)
{
    // Assign 0 to left edge and recur
    if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
 
    // Assign 1 to right edge and recur
    if (root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
 
    // If this is a leaf node, then it contains one of the input
    // characters, print the character and its code from arr[]
    if (isLeaf(root))
    {
    	std::cout << root->data << ": ";
        printArr(arr, top);
    }
}
 
// The main function that builds a Huffman Tree and print codes by traversing
// the built Huffman Tree
void HuffmanCodes(char data[], int freq[], int size)
{
   //  ConHuffman Tree
   MinHeapNode* root = buildHuffmanTree(data, freq, size);
 
   // Print Huffman codes using the Huffman tree built above
   int arr[MAX_TREE_HT], top = 0;
   printCodes(root, arr, top);
}
  
//--------------------------------------------------------------------------
Graph* createGraph(int V, int E)
{
    Graph* graph = new Graph();
    graph->V = V;
    graph->E = E;
 
    graph->edge = new Edge[graph->E];
 
    return graph;
}
 
// A utility function to find set of an element i
// (uses path compression technique)
int find(subset subsets[], int i)
{
    // find root and make root as parent of i (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
}
 
// A function that does union of two sets of x and y
// (uses union by rank)
void Union(subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
 
    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
 
    // If ranks are same, then make one as root and increment
    // its rank by one
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
 
// Compare two edges according to their weights.
// Used in qsort() for sorting an array of edges
int myComp(const void* a, const void* b)
{
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}
 
// The main function to conMST using Kruskal's algorithm
void KruskalMST(Graph* graph)
{
    int V = graph->V;
    Edge result[V];  // Tnis will store the resultant MST
    int e = 0;  // An index variable, used for result[]
    int i = 0;  // An index variable, used for sorted edges
 
    // Step 1:  Sort all the edges in non-decreasing order of their weight
    // If we are not allowed to change the given graph, we can create a copy of
    // array of edges
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
 
    // Allocate memory for creating V ssubsets
    subset *subsets = new subset[V];
 
    // Create V subsets with single elements
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
 
    // Number of edges to be taken is equal to V-1
    while (e < V - 1)
    {
        // Step 2: Pick the smallest edge. And increment the index
        // for next iteration
        Edge next_edge = graph->edge[i++];
 
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
 
        // If including this edge does't cause cycle, include it
        // in result and increment the index of result for next edge
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
        // Else discard the next_edge
    }
 
    // print the contents of result[] to display the built MST
    std::cout << "Following are the edges in the cond MST\n";
    for (i = 0; i < e; ++i)
    	std::cout << result[i].src << " -- " << result[i].dest << " == " << result[i].weight << std::endl;
    return;
}