#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j;
	int sizeX, sizeY;
	int **hang1;
	int **hang2;
	int **hangSum;

	printf("행렬의 크기를 입력하시오. (x y): ");
	scanf("%d %d", &sizeX, &sizeY);
	
	// 입력한 크기만큼 메모리 할당
	hang1 = (int **)malloc(sizeX * sizeof(int *));
	hang2 = (int **)malloc(sizeX * sizeof(int *));
	hangSum = (int **)malloc(sizeX * sizeof(int *));

	for(i = 0; i < sizeX; i++) {
		hang1[i] = (int *)malloc(sizeY * sizeof(int *));
		hang2[i] = (int *)malloc(sizeY * sizeof(int *));
		hangSum[i] = (int *)malloc(sizeY * sizeof(int *));
		}
		
	if(hang1 == NULL || hang2 == NULL || hangSum == NULL) {
		printf("메모리를 할당하지 못했습니다.");
		exit(-1);
	}


	printf("행렬1의 값을 입력하시오.\n");
	for(i = 0; i < sizeX; i++) {
		for(j = 0; j < sizeY; j++)
			scanf("%d", &hang1[i][j]);
	} printf("\n");

	printf("행렬2의 값을 입력하시오.\n");
	for(i = 0; i < sizeX; i++) {
		for(j = 0; j < sizeY; j++)
			scanf("%d", &hang2[i][j]);
	} printf("\n");



	printf("행렬1\n");
	for(i = 0; i < sizeX; i++) {
		for(j = 0; j < sizeY; j++)
			printf("%d ", hang1[i][j]);
		printf("\n");
	} printf("\n");
	
	printf("행렬2\n");
	for(i = 0; i < sizeX; i++) {
		for(j = 0; j < sizeY; j++)
			printf("%d ", hang2[i][j]);
		printf("\n");
	} printf("\n");

	printf("두 행렬 더하기\n");
	for(i = 0; i < sizeX; i++) {
		for(j = 0; j < sizeY; j++) {
			hangSum[i][j] = hang1[i][j] + hang2[i][j];
			printf("%d ", hangSum[i][j]);
		}printf("\n");
	} printf("\n");
	
	// 메모리 할당 해제
	free(hang1);
	free(hang2);
	free(hangSum);
}
