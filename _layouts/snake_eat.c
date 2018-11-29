#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SNAKE_MAX_LENGTH 20
#define SNAKE_HEAD '@'
#define SNAKE_BODY '+'
#define BLANK_CELL ' '
#define SNAKE_FOOD '*'
#define WALL_CELL '#'

//snake stepping: dy=-1(up),1(down);dx=-1(left),1(right);0(no mopve);
void snakeMove(int dy,int dx);
//put a food randomized on a blank cell;
void put_food(void);
// out cells of the grid;
void output(void);
//outs when gameover;
void gameover(void);

char map[12][23]=
	{"######################",               //ֱ�Ӵ����ʼ״̬�ı�� 
	 "#++++@               #",
	 "#                    #",
	 "#                    #",
	 "#                    #",
	 "#                    #",
	 "#                    #",
	 "#                    #",
	 "#                    #",
	 "#                    #",
	 "#                    #",
	 "######################"};
int flag1=1,flag2=1;

// define vars for snake,notice name of vars in C
int snakeX[SNAKE_MAX_LENGTH]={1,2,3,4,5};       //�������ͷ���� 
int snakeY[SNAKE_MAX_LENGTH]={1,1,1,1,1};
int snakeLength = 5;

int main(){
	char ch;
	int dy,dx;
	put_food();      //����ʳ�� 
	output();        //���ɳ�ʼͼ 
	while(1){
		dy=0;
		dx=0;
		scanf("%c",&ch);
		if(ch=='a'||ch=='s'||ch=='d'||ch=='w'){
			switch(ch){              //�������ȥ��chת��Ϊ��Ӧ�ĺ�������仯 
				case 'w':
					dy=-1;
					break;
				case 's':
					dy=1;
					break;
				case 'a':
					dx=-1;
					break;
				case 'd':
					dx=1;
					break;
			}
			snakeMove(dy,dx);             //���ߵ�λ���������� 
			put_food();                   //����ʳ�� 
			output();                     //�����ǰ��ͼ�� 
			gameover();                   //�ж��Ƿ�ΪGame Over 
			if(!flag1){                   //flag1Ϊ��Ϸ�Ƿ���еı�׼  ��Ϊ�����ʾ�Ѿ�Game Over 
				return 0;
			}
			if(snakeLength==SNAKE_MAX_LENGTH){
				printf("You Win!!\n");           //��������ȴﵽ�  ��ȡ��ʤ�� 
				return 0;
			}
		}
	}
	return 0;
}

void snakeMove(int dy,int dx){
	int i,j;
	if(map[snakeY[snakeLength-1]+dy][snakeX[snakeLength-1]+dx]==SNAKE_FOOD){ 
		snakeLength++;                                                           //�����ͷ����ʳ��   �򳤶�+1 
		flag2=1;                                                                 //flag2Ϊ�Ƿ�����ʳ��ı�׼ 
		snakeX[snakeLength-1]=snakeX[snakeLength-2]+dx;                          //���ڳ��ȼӳ�  ��ֻ��Ҫ�ı���ͷλ�ü��� 
		snakeY[snakeLength-1]=snakeY[snakeLength-2]+dy;
		map[snakeY[snakeLength-2]][snakeX[snakeLength-2]]=SNAKE_BODY;
		map[snakeY[snakeLength-1]][snakeX[snakeLength-1]]=SNAKE_HEAD;
	}
	else{
		map[snakeY[0]][snakeX[0]]=BLANK_CELL;                                   //����βλ�û�Ϊ�ո� 
		for(i=0;i<snakeLength-1;i++){
			snakeX[i]=snakeX[i+1];                                              //�������ߵ�����������һλ 
			snakeY[i]=snakeY[i+1];
			map[snakeY[i]][snakeX[i]]=SNAKE_BODY;
		}
		snakeX[snakeLength-1]=snakeX[snakeLength-2]+dx;                         //��ͷλ��������Ӧ�仯 
		snakeY[snakeLength-1]=snakeY[snakeLength-2]+dy;
		map[snakeY[snakeLength-1]][snakeX[snakeLength-1]]=SNAKE_HEAD;	
	}
	
}

void put_food(void){
	int y,x;
	if(flag2){                                          //��flag2Ϊtrue  ����Ҫ����һ��ʳ�� 
		y=rand()%10+1;
		x=rand()%19+1;                                  //��֤ʳ������괦�ڷ����� 
		while(map[y][x]!=BLANK_CELL){                   //����ǰλ�ò�Ϊ��  ���������������ֱ��λ��Ϊ�� 
			y=rand()%10+1;
			x=rand()%19+1;
		}
		map[y][x]=SNAKE_FOOD;                           //�ڵ�ǰλ�÷�ʳ�� 
		flag2=0;	                                    //flag2Ϊ0  ��ʱ���÷�ʳ���� 
	}
}

void output(void){
	int i;
	for(i=0;i<12;i++){
		printf("%s\n",map[i]);                      //�ѱ��ÿ�д�ӡ���� 
	}
}

void gameover(void){
	int i;
	for(i=0;i<snakeLength-1;i++){
		if((snakeX[i]==snakeX[snakeLength-1]&&snakeY[i]==snakeY[snakeLength-1])||snakeX[snakeLength-1]==0||snakeX[snakeLength-1]==21||snakeY[snakeLength-1]==0||snakeY[snakeLength-1]==11){
			printf("Game Over!!\n");                      //�ж���ͷ�Ƿ���ײ�������������ǽ��   ����Game Over 
			flag1=0;                                      //flag1Ϊ0��ʾ���ü�����Ϸ�� 
			break;
		}
	}
}
