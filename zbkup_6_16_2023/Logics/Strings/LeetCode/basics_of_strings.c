#include <stdio.h>
#include <string.h>
#include <malloc.h>

int get_name(char **name)
{
	char buffer[30] = "hello"; // data read fromsocket
	size_t len = 5; // size of data read from socket
	*name = malloc(len+1);
	memcpy(*name, buffer, len);
	//TODO: *name[len] = '\0';
	printf("get_name: %s\n", *name);
	return 1;
}
#if 0
int get_name_x(char *name[])
{

	printf("array pointer: %s\n", name[0]);
	printf("array pointer: %c\n", name[0][1]);
	printf("array pointer: %c\n", name[0][2]);
	printf("array pointer: %c\n", name[0][3]);
	printf("array pointer: %c\n", name[0][4]);
	printf("array pointer: %c\n", name[0][5]);
	
	printf("array pointer: %s\n", name[1]);
	printf("array pointer: %c\n", name[1][1]);
	printf("array pointer: %c\n", name[1][2]);
	printf("array pointer: %c\n", name[1][3]);
	printf("array pointer: %c\n", name[1][4]);
	printf("array pointer: %c\n", name[1][5]);
	return 1;
}

int get_name_y(char **name)
{

	printf("double: %s\n", name[0]);
	printf("double: %c\n", name[0][1]);
	printf("double: %c\n", name[0][2]);
	printf("double: %c\n", name[0][3]);
	printf("double: %c\n", name[0][4]);
	printf("double: %c\n", name[0][5]);
	
	printf("double: %s\n", name[1]);
	printf("double: %c\n", name[1][1]);
	printf("double: %c\n", name[1][2]);
	printf("double: %c\n", name[1][3]);
	printf("double: %c\n", name[1][4]);
	printf("double: %c\n", name[1][5]);
	return 1;

}
#if 0
	printf("function: %s\n", *name);
	printf("function: %s\n", name[0]);
	printf("function: %s\n", name[1]);
	
	printf("function: %c\n", *name[1]);
	printf("XZ; function: %c\n", *(*((name+1)))+1);
	printf("XZ; function: %c\n", *(*((name+1)))+2);


	printf("function: %c\n", name[1][0]);
	printf("function: %c\n", name[1][1]);
	printf("function: %c\n", name[1][2]);

	printf("function: %c\n", name[0][0]);
	printf("function: %c\n", name[0][1]);
	printf("function: %c\n", name[0][2]);
	printf("function: %c\n", name[0][3]);
#endif
int get_name_t(char ***name)
{
	printf("tripple: %s\n", name[0]);
	printf("tripple: %c\n", name[0][1]);
	printf("tripple: %c\n", name[0][2]);
	printf("tripple: %c\n", name[0][3]);
	printf("tripple: %c\n", name[0][4]);
	printf("tripple: %c\n", name[0][5]);
	
	printf("tripple: %s\n", name[1]);
	printf("tripple: %c\n", name[1][1]);
	printf("tripple: %c\n", name[1][2]);
	printf("tripple: %c\n", name[1][3]);
	printf("tripple: %c\n", name[1][4]);
	printf("tripple: %c\n", name[1][5]);
	return 1;
}
#endif 
int get_name_2d(char name[][10])
{
#if 1
	printf("2d: %s\n", name[0]);
	printf("2d: %c\n", name[0][1]);
	printf("2d: %c\n", name[0][2]);
	printf("2d: %c\n", name[0][3]);
	printf("2d: %c\n", name[0][4]);
	printf("2d: %c\n", name[0][5]);
	
	printf("2d: %s\n", name[1]);
	printf("2d: %c\n", name[1][1]);
	printf("2d: %c\n", name[1][2]);
	printf("2d: %c\n", name[1][3]);
	printf("2d: %c\n", name[1][4]);
	printf("2d: %c\n", name[1][5]);
#endif
	return 0;
}

//int get_name_2d_x(char **name) - Not working
//int get_name_2d_x(char *name[10]) - not working
int get_name_2d_x(char **name)
{
	printf("2d: %c \n", name[0]);
	printf("2d: %s \n", name);
	printf("2d: %c \n", name[1]);
#if 0
	printf("2d: %c\n", name[0][1]);
	printf("2d: %c\n", name[0][2]);
	printf("2d: %c\n", name[0][3]);
	printf("2d: %c\n", name[0][4]);
	printf("2d: %c\n", name[0][5]);
	
	//printf("2d: %s\n", name[1]);
	printf("2d: %c\n", name[1][1]);
	printf("2d: %c\n", name[1][2]);
	printf("2d: %c\n", name[1][3]);
	printf("2d: %c\n", name[1][4]);
	printf("2d: %c\n", name[1][5]);
#endif
	return 0;
}
int main()
{
	char *name_ptr;// = {"Praveen", "yitq"};

	int ret = get_name(&name_ptr);
	if(ret == 1)
		printf("main: %s\n", name_ptr);

	char *ptr[2] = {"Praveen", "yzxitq"};
	char ptr_check[2][10] = {"Praveen", "yzxitq"};
#if 0
	ret = get_name_t(&ptr);
	ret = get_name_x(&ptr);
	ret = get_name_y(&ptr);
	if(ret == 1)
		printf("main: %s, %s\n", *(ptr+0), ptr[1]);
#endif
	//ret = get_name_2d(&ptr_check); //Working
	ret = get_name_2d(ptr_check); //Working
	//ret = get_name_2d_x(&ptr_check); //TODO: to remove  compilation error
	printf("checking with double pointer:\n");
	ret = get_name_2d_x((char **)ptr_check);

}
