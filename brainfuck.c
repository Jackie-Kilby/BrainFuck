#include <stdio.h>

char bfcode[500] = "++++++++[>+++++++++<-]>.";
char result[500];
int p = 0, q=0;
static void interpret(int s);

int main(int argc, char **argv)
{
	while ('\0' != *(bfcode+q) ) {
		interpret(q);
		++q;
	}
	return 0;
}

static void interpret(int s)
{
	int i = 0;

	//printf("%c", bfcode[s]);
	switch (bfcode[s]) {
		case '+':
			result[p] ++;
			break;

		case '-':
			result[p] --;
			break;

		case '.':
			putchar(result[p]);
			//printf("ASCII = %d\r\n", result[p]);
			break;

		case ',':
			scanf("%c", result+p);
			//printf("Input a %d, in result[%d]", result[p], p);
			break;

		case '>':
			++ p;
			break;

		case '<':
			-- p;
			break;

		case '[':
			if (result[p] == 0) {
				//跳转到bf_]
				while(bfcode[q] != '\0') {
					while(bfcode[q] != ']') {
						++q;
					}
					break;
				}
			}
			break;

		case ']':
			if (result[p] != 0) {
				//跳转到bf_[
				while(bfcode[q] != '[') {
					--q;
				}
				break;
			}
			break;

		default:
			printf("Unknown\n");
			break;
	}
}

