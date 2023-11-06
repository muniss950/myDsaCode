#include<stdio.h>


int visit[100];
int a[100][100], n, edge;
int label;


void creategraph() {
    int i, j;

    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++) {
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
        if (visit[i] == 0) {

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

    printf("%d",result);

    return 0;
}

