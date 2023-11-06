#include<stdio.h>

int visit[100];

int a[100][100], n, edge;

int label;


void creategraph() {
    int i, j;

    for (i = 1; i <= n; i++) {

        for (j = 1; j <= n; j++) {
            a[i][j] = 0;
        }
    }

    for (int k = 0; k < edge; k++) {
        scanf("%d %d", &i, &j);

        a[i][j] = 1;
    }
}

void dfs(int v) {
    int u;
    visit[v] = label;


    for (u = 1; u <= n; u++) {
        if ((a[v][u] == 1) && (visit[u] == 0))
            dfs(u);
    }
}

int component() {
    int i;
    label = 0;

    for (i = 0; i < n; i++) {
        if (visit[i] == 0)
    {
            label++;
            dfs(i);
        }
    }


    return label;
}
int main() {


    scanf("%d %d", &n, &edge);
    creategraph();
    int result = component();
    if (result == 1 && edge == n-1)
        printf("true");
    else
        printf("false");

    return 0;
}

