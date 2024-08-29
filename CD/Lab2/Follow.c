#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 10

int n;
char production[MAX][MAX], followSet[MAX][MAX], firstSet[MAX][MAX];
int m = 0, followIndex = 0, firstIndex = 0;

// Function to compute the FIRST of a non-terminal
void findFirst(char c, int q1, int q2) {
    if (!(isupper(c))) {
        firstSet[firstIndex][m++] = c;
    } else {
        for (int j = 0; j < n; j++) {
            if (production[j][0] == c) {
                int k = 2;
                while (production[j][k] != '\0') {
                    if (production[j][k] == '|') {
                        k++;
                        continue;
                    }
                    if (production[j][k] == '#') {
                        if (production[q1][q2] == '\0') {
                            firstSet[firstIndex][m++] = '#';
                        } else {
                            findFirst(production[q1][q2], q1, q2 + 1);
                        }
                    } else if (!isupper(production[j][k])) {
                        firstSet[firstIndex][m++] = production[j][k];
                        break;
                    } else {
                        findFirst(production[j][k], j, k + 1);
                        break;
                    }
                    k++;
                }
            }
        }
    }
}

// Function to compute the FOLLOW of a non-terminal
void follow(char c) {
    if (production[0][0] == c) {
        followSet[followIndex][m++] = '$';
    }
    for (int i = 0; i < n; i++) {
        for (int j = 2; j < strlen(production[i]); j++) {
            if (production[i][j] == c) {
                if (production[i][j + 1] != '\0' && production[i][j + 1] != '|') {
                    int tempM = m;
                    m = 0;
                    findFirst(production[i][j + 1], 0, 0);
                    for (int k = 0; k < m; k++) {
                        if (firstSet[firstIndex][k] != '#') {
                            followSet[followIndex][tempM++] = firstSet[firstIndex][k];
                        } else {
                            follow(production[i][0]);
                        }
                    }
                    m = tempM;
                }
                if (production[i][j + 1] == '\0' || production[i][j + 1] == '|') {
                    if (production[i][0] != c) {
                        follow(production[i][0]);
                    }
                }
            }
        }
    }
}

int main() {
    printf("Enter the number of productions: ");
    scanf("%d", &n);
    printf("Enter the productions (e.g., S->AB):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", production[i]);
    }

    int choice;
    do {
        m = 0;
        printf("Enter the element to find FOLLOW: ");
        char c;
        scanf(" %c", &c);
        followIndex++;
        follow(c);

        printf("FOLLOW(%c) = { ", c);
        for (int i = 0; i < m; i++) {
            printf("%c ", followSet[followIndex - 1][i]);
        }
        printf("}\n");

        printf("Do you want to find FOLLOW of another element? (1 for Yes / 0 for No): ");
        scanf("%d", &choice);
    } while (choice);

    return 0;
}
