#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main()
{
	void *handle;
	int (*add)(int, int);
	int (*subtract)(int, int);
	int (*multiply)(int, int);
	int (*divide)(int, int);
	int n1, n2;
	char *error;
	
	handle = dlopen("./lib/libshare.so", RTLD_LAZY);
	if (!handle)
	{
		fputs(dlerror(), stderr);
		exit(1);
	}
	add = dlsym(handle, "add");
	if ((error = dlerror()) != NULL){
		fprintf(stderr, "%s", error);
		exit(1);
	}
	subtract = dlsym(handle, "add");
	if ((error = dlerror()) != NULL){
		fprintf(stderr, "%s", error);
		exit(1);
	}
	multiply = dlsym(handle, "add");
	if ((error = dlerror()) != NULL){
		fprintf(stderr, "%s", error);
		exit(1);
	}
	divide = dlsym(handle, "add");
	if ((error = dlerror()) != NULL){
		fprintf(stderr, "%s", error);
		exit(1);
	}
	
	printf("first num : ");
	scanf("%d",&n1);
	printf("second num : ");
	scanf("%d",&n2);
	
	printf("%d + %d = %d\n", n1, n2,(*add)(n1, n2));
	divide = dlsym(handle, "divide");
	if ((error = dlerror()) !=NULL){
		fprintf(stderr, "%s", error);
		exit(1);
	}
	
	printf("%d + %d = %d \n", n1, n2,(*add)(n1, n2));
	printf("%d - %d = %d \n", n1, n2,(*subtract)(n1, n2));
	printf("%d * %d = %d \n", n1, n2,(*multiply)(n1, n2));
	printf("%d / %d = %d \n\n", n1, n2,(*divide)(n1, n2));
	printf("finish.\n");
	dlclose(handle);
	return 0;
	
	
}
