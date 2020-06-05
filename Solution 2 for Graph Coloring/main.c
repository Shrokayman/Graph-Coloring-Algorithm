#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define V 4

void ShowFinalResult(int Color[])
{
    for (int i = 0; i < V; i++)
        printf(" %d ", Color[i]);
    printf("\n");
}

bool NotUsed(int vertex, int color, bool graph[V][V], int Color[V])
{
    for(int i=0; i<=V; i++)
    {
        if(graph[vertex][i] == 1 && color == Color[i])
        {
            return false;
        }
    }
    return true;
}

bool AssignColor(int vertex, int m, int Color[V], bool graph[V][V])
{
    for(int color=1; color<=m; color++)
    {
        if(NotUsed(vertex, color, graph , Color))
        {
            Color[vertex] = color;
            if((vertex+1)<V)
                AssignColor(vertex+1 , m, Color, graph);
            else
               ShowFinalResult(Color);
        }
    }
     return true;
}


int main()
{
    bool graph[V][V] = {
        { 1, 1, 0, 1 },
        { 1, 1, 1, 0 },
        { 0, 1, 1, 1 },
        { 1, 1, 1, 1 },
    };
    int m = 3; // Number of colors

    int Color[V];
    for (int i = 0; i < V; i++)
        Color[i] = 0;

    AssignColor(0, m, Color, graph);
    return 0;
}
