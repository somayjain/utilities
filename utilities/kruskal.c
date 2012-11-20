#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxVertices 2010
#define maxEdges 1999010
int mst[maxEdges];
/* Input graph must be undirected,weighted and connected*/
typedef struct Edge
{
        int from,to,weight;
}Edge;
int compare(const void * x,const void * y)
{
        return (*(Edge *)x).weight - (*(Edge *)y).weight;
}
Edge E[maxEdges];
int parent[maxVertices];
int ct, sets;
void init(int vertices)
{
        int iter=0;
        for(iter=0;iter<vertices;iter++)
        {
                parent[iter]=-1;
        }

}
int Find(int vertex)
{
        if(parent[vertex]==-1)return vertex;
        return parent[vertex] = Find(parent[vertex]); /* Finding its parent as well as updating the parent 
                                                         of all vertices along this path */
}
int Union(int parent1,int parent2)
{
        /* This can be implemented in many other ways. This is one of them */
        parent[parent1] = parent2;
}
void quicksort(Edge a[], int start, int end)
{
	if(start>end)
		return;
	int i, pivot=end, ptr=-1;
	Edge temp;
	for(i=start; i<end; i++)
	{
		if(a[i].weight<a[pivot].weight && ptr!=-1)
		{
			temp=a[i];
			a[i]=a[ptr];
			a[ptr]=temp;
			ptr++;
		}
		if(ptr==-1 && a[i].weight>a[pivot].weight)
			ptr=i;
	}
	if(ptr!=-1)
	{	
		temp=a[pivot];
		a[pivot]=a[ptr];
		a[ptr]=temp;
		quicksort(a, start, ptr-1);
		quicksort(a, ptr+1, end);
	}
	if(ptr==-1)
		quicksort(a, start, end-1);
}

void Kruskal(int vertices,int edges)
{
	int i;
        /* Sort the edges according to the weight */
        // qsort(E,edges,sizeof(Edge),compare);
	quicksort(E, 0, edges-1);
        /* Initialize parents of all vertices to be -1.*/
        init(vertices);
        int totalEdges = 0,edgePos=0,from,to,weight;
        Edge now;
	ct=0;
        while(totalEdges < vertices -1)
        {
                if(edgePos==edges)
                {
                        /* Input Graph is not connected*/
                        return;
                }
                now = E[edgePos++];
                from = now.from;
                to = now.to;
                weight=now.weight;
                /* See If vetices from,to are connected. If they are connected do not add this edge. */
                int parent1 = Find(from);
                int parent2 = Find(to);
                if(parent1!=parent2)
                {
                        Union(parent1,parent2);
			sets--;
                        totalEdges++;
			mst[ct++]=edgePos-1;
                }
        }

}
int main()
{
	int hash[maxVertices];
	int t, i;
	int vertices,edges;
	int iter,jter;
	int from,to,weight, max, extra, count;
	long long int ans;
	scanf("%d", &t);
	while(t--)
	{
		count=0;ct=0, ans=0;
		scanf("%d%d%d",&vertices,&edges, &max);
		sets=vertices;
		for(iter=0; iter <vertices; iter++)
			hash[iter]=0;
		for(iter=0;iter<edges;iter++)
		{
			scanf("%d%d%d",&from,&to,&weight);
			E[iter].from = from; 
			E[iter].to = to; 
			E[iter].weight = weight;
			if(hash[from]==0)
			{
				count++;
				hash[from]=1;
			}
			if(hash[to]==0)
			{
				count++;
				hash[to]=1;
			}

		}
		Kruskal(vertices,edges);
		if(max<sets)
		{
			printf("Impossible!\n");
		}
		else
		{
			extra = max-sets;
			for(i=0; i<ct-extra; i++)
			{
				ans += E[mst[i]].weight;
			}
			printf("%lld\n", ans);
		}





	}
	return 0;
}
