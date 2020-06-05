#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define V 4

bool NotUsed(bool graph[V][V], int Color[], int color, int vertex);
bool AssignColors1(bool graph[V][V], int Color[], int m, int vertex);
void ShowFinalColors(int Color[]);

bool AssignColors2(bool graph[V][V], int m)
{
    int Color[V];
    for (int i = 0; i<V; i++)
        Color[i] = 0;

    if (AssignColors1(graph, Color, m, 0) == 0)
        {
        return 0;
        }
    ShowFinalColors(Color);
    return 1;
}

bool AssignColors1(bool graph[V][V], int Color[], int m, int vertex )
{
    if (vertex == V)
        return 1;

    for(int color=1; color<=m; color++)
     {
         if (NotUsed(graph, Color, color, vertex)) {
            Color[vertex] = color;

            if (AssignColors1(graph, Color, m, vertex+1)== 1)
                return 1;

            Color[vertex] = 0;
        }
     }

    return 0;
}

bool NotUsed(bool graph[V][V], int Color[], int color, int vertex)
{
    for (int i=0; i<V; i++)
        if (graph[vertex][i] && color == Color[i])
            return 0;
    return 1;
}

void ShowFinalColors(int Color[])
{
    printf("The assigned colors is:");
    printf("\n");
    for (int i = 0; i < V; i++)
        printf(" %d ", Color[i]);
    printf("\t");
}

int main()
{
    bool graph[V][V] = {
        { 1, 1, 0, 1 },
        { 1, 1, 1, 1 },
        { 0, 1, 1, 1 },
        { 1, 1, 1, 1 },
    };
    int m = 3;
    AssignColors2(graph, m);
    return 0;
}

