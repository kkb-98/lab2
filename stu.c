#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>

struct stuTable { // 학생 구조체
	char name[10];
	int midScore;
	int endScore;
};

struct stuTable *root = NULL;

int compare(const void *cp1, const void*cp2) { // 탐색중인 노드의 위치비교
	return strcmp(((struct stuTable *)cp1)->name,((struct stuTable*)cp2)->name);
}

void print_node(const void *nodeptr, VISIT order, int level) { // twalk가 처음 노드를 만나면 출력
	if (order == preorder || order == leaf)
		printf("이름: %s	중간 점수 = %d, 기말 점수 = %d \n",(*(struct stuTable **)nodeptr)->name,
		(*(struct stuTable **)nodeptr)->midScore,(*(struct stuTable **)nodeptr)->endScore);
}


int main() {
	int i, num; 
	struct stuTable **ret;
    
	printf("학생 수를 입력하시오: ");
	scanf("%d",&num);

	if(num <=0 || num == '\0') 
		abort();
    
	struct stuTable *tree[num];

	for(i = 0; i < sizeof(tree) / sizeof(struct stuTable *); i++) {
		tree[i] = malloc(sizeof(struct stuTable));
		printf("\n");
		printf("추가할 학생 정보를 입력하시오. (이름, 중간점수, 기말점수)  \n");
		scanf("%s %d %d", tree[i]->name, &tree[i]->midScore, &tree[i]->endScore); 

		ret = (struct stuTable **) tsearch((void *) tree[i],(void **) &root, compare);
		printf("\'%s\' ", (*ret)->name);
		
		if (*ret == tree[i])
			printf("학생의 정보가 추가되었습니다.\n");
		else
			printf("학생의 정보가 이미 존재합니다.\n");
	} printf("\n");
	
	twalk((void *) root, print_node);

	for (int i = 0; i < sizeof(tree) / sizeof(struct stuTable *); i++) // 메모리 할당 해제
		free(tree[i]); 
}
