#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define ROW  3
#define COL  3

int is_prime(int n)       
{
	int j = 0;
	for(j=2; j<=sqrt(n); j++)
	{
		if (n%j == 0)
			return 0;
	}
	return 1;
}	
int binary_search(int arr[], int k, int sz)
{
	int left = 0;
//	int right = sizeof(arr)/sizeof(arr[0]) - 1;      这里arr是首元素地址，对于64位电脑，是8个字节，长度位2
	int	right = sz - 1;
	while(left <= right)
	{	
		int mid = (left+right)/2;
		if(k == arr[mid]) 
		{
			return mid;
		}
		else if (k < mid)
		{
			right = mid -1;

		}
		else
		{
			left = mid + 1;
		}
	}
	return -1;
}

void Add(int* p)
{
	(*p)++;
}

int my_strlen0(char* str)
{	
	int count = 0;
	while(*str != '\0')        //千万注意这里要用单引号表示
	{
		count++;
		str++;                 //指针变量++是将指针变量指向下一个元素的运算。
	}
	return count;
}

// int my_strlen(char* str)           //递归的方法   ，这里报错了，为什么？
// {
// 	if(*str != '\0')
// 		return 1 + my_strlen(str++);
// 	else
// 		return 0;

// }

//------递归求n的阶乘---------
int fac1(int n)      
{
	if(n<=1)
		return 1;
	else
		return n*fac1(n-1);
}

//------递归求第n个斐波那契数---------
int Fib(int n)       
{
	if(n<=2)
		return 1;
	else
		return Fib(n-2)+Fib(n-1);      //递归计算斐波那契数会造成大量重复工作，并不适合用递归。
}

//------循环求斐波那契数---------
int Fib1(int n)
{	
	int a = 1;
	int b = 1;
	int c = 1;
	int temp = 0;
	while(n>2) 
	{	
		c = a+b;
		a = b;
		b = c;
		n--;
	}
	return c;
	
}
//------冒泡排序----------
void bubble_sort(int arr[], int sz)
{
	int i = 0;
	for(i=0; i<sz-1; i++)
	{
		int flag = 1;
		int j = 0;

		for(j=0; j<sz-1-i; j++)
		{
			if(arr[j] > arr[j+1])
			{
				int temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
				flag = 0;
			} 
		}
		if(flag == 1)
		{
			break;
		}
		
	}
} 
//----菜单----
void menu()
{
	printf("********************\n");
	printf("**1.play   0.exit***\n");
	printf("********************\n");
}
//----初始化棋盘----
void InitBoard(char board[ROW][COL], int row, int col)
{	
	int i = 0;
	int j = 0;
	for(i=0; i<row; i++)
	{	for(j=0; j<col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
//----打印棋盘----
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			printf(" %c ",board[i][j]);
			if(j<col-1)
				printf("|");
		
		}
		printf("\n");

		if (i<row-1)
		{
			for(j=0; j<col; j++)
			{
				printf("---");
				if (j<col-1)
					printf("|");
			}
		}
		printf("\n");
	}

	
	// 	//1.打印一行的数据
	// 	for(j=0; j<col; j++)
	// 	{
	// 		if(j<col-1)
	// 			printf(" %c |", board[i][j]);
	// 		else
	// 			printf(" %c \n",board[j][j]);
	// 	}
	// 	//2.打印分行符
	// 	if(i<row -1)
	// 		for (j=0; j<col; j++)
	// 		{
	// 			if(j<col-1)
	// 				printf("---|");
	// 			else
	// 				printf("---\n");
	// 		}	
			
	// }
}
//----玩家移动----
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家移动：\n");
	while(1)
	{
		printf("请输入要下的x坐标+空格+y坐标+回车:");
		scanf("%d%d",&x, &y);        //注意%d%d这种连续输入数字时中间用空格隔开
		//判断输入坐标的合法性
		if(x>=1 && x<=col && y>=1 &&y<<row)
		{
			if(board[x-1][y-1] == ' ')
			{
				board[x-1][y-1] = '*';
				break;
			}
			else
				printf("该坐标已被占用");
		}

	}
	
}

//----电脑移动----
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑移动：\n");
	while(1)
	{
		x = rand() % col;  //取模之后得出的整型 <= col-1
		y = rand() % row; 

		if(board[x-1][y-1] == ' ')
		{
			board[x-1][y-1] = '#';
			break;
		}
	}
}

//----判断棋盘是否满了,满了返回1----
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i=0; i<row; i++)
	{
		for (j=0; j<col; j++) 
		{
			if(board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
//----判断游戏状态（目前只能判断3*3的棋盘）----
char IsWin(char board[ROW][COL], int row, int col)
{	
	int i = 0;
	int j = 0;
	//横三行
	for(i=0; i<row; i++)
	{
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != ' ')
			return board[i][2];
	}
	//竖三列
	for(j=0; j<col; j++)
	{
		if(board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[2][j] != ' ')
			return board[2][j];
	}
	//两个对角线
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != ' ' )
		return board[2][2];

	if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] != ' ')
		return board[2][0];
	//判断是否平局
	if(1 == IsFull(board, ROW, COL))
		return 'Q';
	
	return 'C';

}

//----游戏程序----
void game()
{
	//给出一个数组储存玩家走出的棋盘信息
	char board[ROW][COL] = {0};

	InitBoard(board, ROW, COL);

	DisplayBoard(board, ROW, COL);
	int ret = 0;
	while(1)
	{	
		
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢
		ret = IsWin(board, ROW, COL);
		if(ret != 'C')
			break;

		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断电脑是否赢
		ret = IsWin(board, ROW, COL);
		if(ret != 'C')
			break;	

	}
    if(ret == '*')
		printf("玩家赢！\n");
	else if(ret == '#')
		printf("电脑赢了！\n");
	else
		printf("平局！\n");
}	
void test()
{	
	int input = 0;
	srand((unsigned int)time(NULL));  //随机数常用的一种方式
	//只需在主程序开始处调用srand((unsigned)time(NULL)); 后面直接用rand就可以了
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			printf("三子棋\n");
			game();

		case 0:
			printf("退出游戏\n");
			break;
		default:
		printf("选择错误，请重新选择！\n");
		break;

		}

	}while(input);
}
// int main()
// {	
 
// 	short s = 0;
// 	int a = 10;
// 	printf("%d\n",sizeof(s = a + 5));
// 	printf("%d\n", s);

// }
void test1(int arr[])
{
	printf("%d\n", sizeof(arr));
}
void test2(char ch[])
{
	printf("%d\n", sizeof(ch));
}
int main()
{
	char a = 3;
	char b = 127;
	char c = a + b;
	printf("%d\n",c);
	return 0;
}
