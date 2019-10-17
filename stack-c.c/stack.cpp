//מחםנית 17.10.2019 ידן


#include <iostream>

using namespace std;

bool StackFull(char S[], int top, int len)
{
	return (top == len - 1);
}

bool StackEmpty(char S[], int top)
{
	return (top == -1);
}

void Push(char S[], int& top, int len, char in_chr)
{
	if (StackFull(S, top, len))
		return; //error - overflow
	top++;
	S[top] = in_chr;
}

char Pop(char S[], int& top)
{
	if (StackEmpty(S, top))
		return ' '; //error - underflow
	char result = S[top];
	top--;
	return result;
}
//q2
void Enqueue(char I[], int& i_top, int i_len, char in_chr) {
	Push(I, i_top,i_len, in_chr);
}
char Dequeue(char I[], int& i_top, int i_len, char O[], int& o_top, int o_len) {
	while (!StackEmpty(I, i_top))
		Push(O, o_top, o_len,Pop(I, i_top));
	char result = Pop(O, o_top);
	while (!StackEmpty(O, o_top))
		Push(I, i_top, o_len, Pop(O, o_top));

		return result;
}
/*
//q1
int main()
{
	//use const

	//Define Stack
	char S[10];
	int top = -1;
	int len = 10;


	bool res1 = StackEmpty(S, top);

	Push(S, top, len, 'a');
	char chr = Pop(S, top);
	printf("%c", chr);

	bool res2 = StackEmpty(S, top);

	if (res1 && !res2)
		printf("all is good");
}*/
//q2
int main()
{
	//use const
	//Define const
	char I[10];
	int i_top = -1;
	int i_len = 10;
	char O[10];
	int o_top = -1;
	int o_len = 10;

	Enqueue(I, i_top, i_len, 'a');
	Enqueue(I, i_top, i_len, 'b');
	Enqueue(I, i_top, i_len, 'c');

	char c = Dequeue(I, i_top, i_len, O, o_top, o_len);
	printf("%c", c);

	Enqueue(I, i_top, i_len, 'd');

    c = Dequeue(I, i_top, i_len, O, o_top, o_len);
	printf("%c", c);
	c = Dequeue(I, i_top, i_len, O, o_top, o_len);
	printf("%c", c);
	c = Dequeue(I, i_top, i_len, O, o_top, o_len);
	printf("%c", c);


}