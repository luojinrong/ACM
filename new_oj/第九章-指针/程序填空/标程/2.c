#include<stdio.h>
#include<string.h>
#include<stdlib.h>//①
int main(){
	char *s;
	int ch = 0, num = 0, blank = 0, oth = 0, i;
	s = (char*)malloc(sizeof(char) * 105);//②
	gets(s);//③
	for (i = 0; *(s + i) != 0; i++) {//④
		if ((*(s + i) >= 'a'&&*(s + i) <= 'z') || (*(s + i) >= 'A'&&*(s + i) <= 'Z')) {//⑤
			ch++;
		}
		else if (*(s + i) >= '0'&&*(s + i) <= '9') {
			num++;
		}
		else if (*(s + i) == ' ') {
			blank++;//⑥
		}
		else {
			oth++;
		}
	}
	printf("character : %d\nnumber : %d\nblank : %d\nother : %d\n", ch, num, blank, oth);
}