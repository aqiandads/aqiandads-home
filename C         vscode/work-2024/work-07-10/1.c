#include <stdio.h> 
#include <string.h> 
#include <math.h>

#define MAX_NODES 1005

struct Node {
    int x, y, z, step;
} queue[MAX_NODES], nodes[MAX_NODES];

int visited[MAX_NODES];

double calculatestep(struct Node a, struct Node b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double dz = a.z - b.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

int bfs(int startX, int startY, int startZ, int n, int h, int R) {
    int front = 0, rear = 0;

    struct Node startNode = { startX, startY, startZ, 1 };
    queue[rear++] = startNode;
    while (front < rear) { //队列不为空时进入循环
        struct Node currentNode = queue[front++];
        if (currentNode.z + R >= h) return currentNode.step;
        for (int i = 1; i <= n; i++) {
            if (calculatestep(currentNode, nodes[i]) <= 2 * R && !visited[i]) {
                struct Node nextNode = { nodes[i].x, nodes[i].y, nodes[i].z, currentNode.step + 1 };
                queue[rear++] = nextNode;
                visited[i] = 1; 
            }
        }
    }
return -1;
}

int main() {
    int testCases;
    scanf("%d", &testCases);
    while (testCases--) {
        int n, h, R;
        scanf("%d%d%d", &n, &h, &R);

        memset(nodes, 0, sizeof(nodes));
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d", &nodes[i].x, &nodes[i].y, &nodes[i].z);
            nodes[i].step = 0;
        }
        int minSteps = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++) {
            if (nodes[i].z - R <= 0) {

                memset(visited, 0, sizeof(visited));
                memset(queue, 0, sizeof(queue));
                visited[i] = 1;
                int steps = bfs(nodes[i].x, nodes[i].y, nodes[i].z, n, h, R);
                if (steps > 0 && steps < minSteps) minSteps = steps;
            }
        }
        if (minSteps != 0x3f3f3f3f)
            printf("%d\n", minSteps);
        else 
            printf("-1\n");
    }
return 0;
}