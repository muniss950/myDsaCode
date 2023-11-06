#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int n, edge;
int a[100][100];

int nquery, length;

int visit[100], p[100];

int findpath(int s, int d) {
    int i;
    visit[s] = 1;

    for (i = 0; i < n; i++) {
        if ((a[s][i] == 1) && (visit[i] == 0)) {
            if ((i == d) || findpath(i, d)) {

                ++length;
                p[length] = i;

                return 1;
            }
        }
    }
    length--;
    return 0;
}

bool path(int s, int d) {
    int i, result;
    length = 0;
    p[length] = s;
    for (i = 0; i < n; i++)
        visit[i] = 0;
    result = findpath(s, d);
    if (result) {

        return true;
    } else
        return false;
}

void creategraph() {
    int i, j;


    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }


    for (int k = 0; k < edge; k++) {
        scanf("%d %d", &i, &j);
        if ((i < 0 || i >= n) || (j < 0 || j >= n))

            break;

        a[i][j] = 1;
    }
}


int main() {
    scanf("%d %d", &n, &edge);

    creategraph();
    scanf("%d", &nquery);


    for (int f = 0; f < nquery; f++) {
        int i, j;
        scanf("%d %d", &i, &j);
        
        if(path(i, j))
            printf("yes\n");
        else
            printf("no\n");
    }


    return 0;
}
