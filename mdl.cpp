#include "mdl.h"
#include <iostream>
#include <cstdlib>


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


MinHeapNode* newNode(char data, unsigned freq)
{
    MinHeapNode* temp = new MinHeapNode();
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}
 

MinHeap* createMinHeap(unsigned capacity)
{
    MinHeap* minHeap = new MinHeap();
    minHeap->size = 0;  
    minHeap->capacity = capacity;
    minHeap->array = new MinHeapNode*[minHeap->capacity];
    return minHeap;
}
 

void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b)
{
    MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}
 

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
 

int isSizeOne(MinHeap* minHeap)
{
    return (minHeap->size == 1);
}
 

MinHeapNode* extractMin(MinHeap* minHeap)
{
    MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}
 

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
 

void buildMinHeap(MinHeap* minHeap)
{
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}
 


int isLeaf(MinHeapNode* root)
{
    return !(root->left) && !(root->right) ;
}
 


MinHeap* createAndBuildMinHeap(char data[], int freq[], int size)
{
    MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}
 

MinHeapNode* buildHuffmanTree(char data[], int freq[], int size)
{
    MinHeapNode *left, *right, *top;
 
    
    
    MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);
 
    
    while (!isSizeOne(minHeap))
    {
        
        left = extractMin(minHeap);
        right = extractMin(minHeap);
 
        
        
        
        
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
 
    
    return extractMin(minHeap);
}

void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        std::cout << arr[i];
    std::cout << std::endl;
}


void printCodes(MinHeapNode* root, int arr[], int top)
{
    
    if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
 
    
    if (root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
 
    
    
    if (isLeaf(root))
    {
    	std::cout << root->data << ": ";
        printArr(arr, top);
    }
}



void HuffmanCodes(char data[], int freq[], int size)
{
   
   MinHeapNode* root = buildHuffmanTree(data, freq, size);
 
   
   int arr[MAX_TREE_HT], top = 0;
   printCodes(root, arr, top);
}
  

Graph* createGraph(int V, int E)
{
    Graph* graph = new Graph();
    graph->V = V;
    graph->E = E;
 
    graph->edge = new Edge[graph->E];
 
    return graph;
}
 


int find(subset subsets[], int i)
{
    
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
}
 


void Union(subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
 
    
    
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
 
    
    
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
 


int myComp(const void* a, const void* b)
{
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}
 

void KruskalMST(Graph* graph)
{
    int V = graph->V;
    Edge result[V];  
    int e = 0;  
    int i = 0;  
 
   
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
 
    
    subset *subsets = new subset[V];
 
    
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
 
    
    while (e < V - 1)
    {
        
        
        Edge next_edge = graph->edge[i++];
 
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
 
        
        
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
        
    }
 
    
    std::cout << "Following are the edges in the cond MST\n";
    for (i = 0; i < e; ++i)
    	std::cout << result[i].src << " -- " << result[i].dest << " == " << result[i].weight << std::endl;
    return;
}