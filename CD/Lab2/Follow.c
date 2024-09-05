#include <stdio.h>
#include <string.h>
#include <ctype.h>

void add_to_result(char result[], char symbol) {
    if (strchr(result, symbol) == NULL) {
        int len = strlen(result);
        result[len] = symbol;
        result[len + 1] = '\0';
    }
}

void first(char rules[10][10], char var, char result[], int ruleCount, char nonTerminals[], int nonTerminalCount);
void follow(char rules[10][10], char var, char result[], int ruleCount, char nonTerminals[], int nonTerminalCount);

int is_non_terminal(char symbol, char nonTerminals[], int nonTerminalCount) {
    for (int i = 0; i < nonTerminalCount; i++) {
        if (symbol == nonTerminals[i]) {
            return 1;
        }
    }
    return 0;
}

void first(char rules[10][10], char var, char result[], int ruleCount, char nonTerminals[], int nonTerminalCount) {
    int i, j;

    for (i = 0; i < ruleCount; i++) {
        if (rules[i][0] == var) {
            if (!is_non_terminal(rules[i][2], nonTerminals, nonTerminalCount)) {
                add_to_result(result, rules[i][2]);
            } else if (rules[i][2] == '*') {
                add_to_result(result, '*');
            } else {
                char temp[10] = "";
                first(rules, rules[i][2], temp, ruleCount, nonTerminals, nonTerminalCount);
                for (j = 0; temp[j] != '\0'; j++) {
                    if (temp[j] != '*') {
                        add_to_result(result, temp[j]);
                    }
                }
                if (strchr(temp, '*') != NULL && rules[i][3] != '\0') {
                    first(rules, rules[i][3], result, ruleCount, nonTerminals, nonTerminalCount);
                }
            }
        }
    }
}

void follow(char rules[10][10], char var, char result[], int ruleCount, char nonTerminals[], int nonTerminalCount) {
    int i, j;
    if (var == rules[0][0]) {
        add_to_result(result, '$'); 
    }

    for (i = 0; i < ruleCount; i++) {
        for (j = 2; j < strlen(rules[i]); j++) {
            if (rules[i][j] == var) {
                if (rules[i][j + 1] != '\0') {
                    if (!is_non_terminal(rules[i][j + 1], nonTerminals, nonTerminalCount)) {
                        add_to_result(result, rules[i][j + 1]);
                    } else {
                        char temp[10] = "";
                        first(rules, rules[i][j + 1], temp, ruleCount, nonTerminals, nonTerminalCount);
                        for (int k = 0; temp[k] != '\0'; k++) {
                            if (temp[k] != '*') {
                                add_to_result(result, temp[k]);
                            }
                        }
                        if (strchr(temp, '*') != NULL && rules[i][j + 2] == '\0') {
                            follow(rules, rules[i][0], result, ruleCount, nonTerminals, nonTerminalCount);
                        }
                    }
                } else {
                    if (rules[i][0] != var) {
                        follow(rules, rules[i][0], result, ruleCount, nonTerminals, nonTerminalCount);
                    }
                }
            }
        }
    }
}

int main() {
    int i, j, n;
    char rules[10][10], nonTerminals[10], variable;
    char result[10];
    int nonTerminalCount = 0;

    printf("Enter the number of rules: ");
    scanf("%d", &n);
    printf("Enter the grammar rules (format: A=xyz):\n");
    for (i = 0; i < n; i++) {
        scanf("%s", rules[i]);
        if (!strchr(nonTerminals, rules[i][0])) {
            nonTerminals[nonTerminalCount++] = rules[i][0];
        }
    }

    while (1) {
        printf("\nEnter variable to find FIRST and FOLLOW (0 to exit): ");
        scanf(" %c", &variable);

        if (variable == '0') {
            break;
        }

        strcpy(result, "");
        first(rules, variable, result, n, nonTerminals, nonTerminalCount);
        printf("FIRST(%c) = { %s }\n", variable, result);

        strcpy(result, "");
        follow(rules, variable, result, n, nonTerminals, nonTerminalCount);
        printf("FOLLOW(%c) = { %s }\n", variable, result);
    }

    return 0;
}