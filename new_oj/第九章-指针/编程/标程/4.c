#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char str[100005], **num;
int count;

void get_num() {
	int all_num = 10, len = strlen(str), size_num = 10, now = 0, flag = 0;
	num = (char**)malloc(sizeof(char*)*all_num);
	num[count] = (char*)malloc(sizeof(char)*size_num);
	for (int i = 0; i < len + 1; i++) {
		if (str[i] >= '0'&&str[i] <= '9') {
			num[count][now++] = str[i];
			if (now + 1 == size_num) {
				size_num *= 2;
				num[count] = (char*)realloc(num[count], sizeof(char)*size_num);
			}
			flag = 1;
		}
		else if (flag) {
			flag = 0;
			num[count++][now] = 0;
			size_num = 10;
			now = 0;
			num[count] = (char*)malloc(sizeof(char)*size_num);
			if (count + 1 == all_num) {
				all_num *= 2;
				num = (char**)realloc(num, sizeof(char*)*all_num);
			}
		}
	}
}

int main() {
	int T;
	for (scanf("%d", &T); T; T--) {
		scanf("%s", str);
		count = 0;
		get_num();
		printf("%d\n", count);
		for (int i = 0; i < count; i++) {
			printf("%s\n", num[i]);
		}
	}
}