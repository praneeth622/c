// #include<stdio.h>

// #define V 4


// void init(int arr[][V]) {
//   int i, j;
//   for (i = 0; i < V; i++)
//     for (j = 0; j < V; j++)
//       arr[i][j] = 0;
// }

// //add edge
// void addedge(int i, int j, int arr[][V]){
//     arr[i][j] = 1;
//     arr[j][i] = 1;
// }

// //Printing Matrix 
// void Print(int arr[][V]){
//     for(int i = 0;i < V;i++){
//         for(int j = 0;j < V; j++){
//             printf("%d",arr[i][j]);
//         }
//     }
//     printf("\n");
// }

// int main(){
//     int i,j;

//     int arr[V][V];
//     init(arr);

//     addedge(arr,2,1);
//     addedge(arr,1,4);
//     Print(arr);
//     return 0;
// }
#include <stdio.h>

#define V 4

void init(int arr[][V]) {
  int i, j;
  for (i = 0; i < V; i++)
    for (j = 0; j < V; j++)
      arr[i][j] = 0;
}

// add edge
void addedge(int i, int j, int arr[][V]){
  arr[i][j] = 1;
  arr[j][i] = 1;
}

// Printing Matrix 
void Print(int arr[][V]) {
  int i, j;

  for (i = 0; i < V; i++) {
    printf("%d: ", i);
    for (j = 0; j < V; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

int main(){
    int i, j;

    int arr[V][V];
    init(arr);

    addedge(2,3,arr);
    addedge(2,4,arr);
    Print(arr);
    return 0;
}