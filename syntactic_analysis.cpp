#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char FIRSTVT[10][20],LASTVT[10][20];
char st[10][10];									//文法规则表
char label[20];										//终结符号表
char TABLE[20][20];									//符号表
char input[100];									//输入的待规约串
int	 num;											//文法规则个数
int  num1;											//转换后的文法规则个数
int  a;												//终结符个数
bool fflag[10] = {false};							//标志第i个非终结符的FIRSTVT集是否已求出
bool lflag[10] = {false};							//标志第i个非终结符的LASTVT集是否已求出

void first(char c)									//求非终结符c的FIRSTVT集
{
	int n = 1,m,j,k,t,temp = 0;
	for(int i = 0;i < num; i++)
	{
		if(st[i][0] == c)
			break;
	}
	if(fflag[i] == false)
	{
		for(m = 0;st[i][m] != '\0';m ++)
		{
			if(st[i][m] == '|' || m == 0)
			{
				if(st[i][m + 1] < 'A' || st[i][m + 1] > 'Z')
				{
					FIRSTVT[i][n] = st[i][m + 1];
					n ++;
				}
				else
				{
					if((st[i][m + 2] < 'A' || st[i][m + 2] > 'Z') && (st[i][m + 2] != '\0'))
					{
						FIRSTVT[i][n] = st[i][m + 2];
						n ++;
					}
					if(st[i][m + 1] != c)
					{
						first(st[i][m + 1]);
						for(j = 0;j < num;j ++)
						{
							if(st[j][0] == st[i][m+1])
								break;
						}
						for(k=0;k < FIRSTVT[j][0];k ++)
						{
							for(t = 1;t < n;t ++)
							{
								if(FIRSTVT[i][t] == FIRSTVT[j][k+1])
								{
									temp = 1;
									break;
								}
							}
							if(!temp)
							{
								FIRSTVT[i][n] = FIRSTVT[j][k+1];
								n++;
							}
						}
					}
				}
			}
		}
		n --;
		FIRSTVT[i][0] = n;
		fflag[i] = true;
	}
}

void last(char c)									//求非终结符c的LASTVT集
{
	int n = 1,m,j,k,temp = 0;
	for(int i = 0;i < num; i++)
	{
		if(st[i][0] == c)
			break;
	}
	if(lflag[i] == false)
	{
		for(m = 0;st[i][m] != '\0';m ++)
		{
			if(st[i][m + 1] == '|' || st[i][m + 1] == '\0')
			{
				if(st[i][m] < 'A' || st[i][m] > 'Z')
				{
					LASTVT[i][n] = st[i][m];
					n ++;
				}
				else
				{
					if((st[i][m - 1] < 'A' || st[i][m - 1] > 'Z') && (st[i][m - 1] != '|') && ((m - 1) != 0)) 
					{
						LASTVT[i][n] = st[i][m - 1];
						n ++;
					}
					if(st[i][m] != c)
					{
						last(st[i][m]);
						for(j = 0;j < num;j ++)
						{
							if(st[j][0] == st[i][m])
								break;
						}
						for(k = 0;k < LASTVT[j][0];k ++)
						{
							int t;
							for(t = 1;t < n;t ++)
							{
								if(LASTVT[i][t] == LASTVT[j][k + 1])
								{
									temp = 1;
									break;
								}
							}
							if(!temp)
							{
								LASTVT[i][n] = LASTVT[j][k + 1];
								n ++;
							}
						}
					}
				}
			}
		}
		n --;
		LASTVT[i][0] = n;
		lflag[i] = true;
	}
}

int judge()											//判断文法是否是算符文法
{
	int i,j;
	for(i = 0;i < num;i ++) 
	{
		if(st[i][0] < 'A' || st[i][0] > 'Z')
		{
			cout<<"该文法不是算符文法"<<endl;
			return 0;
		}
		for(j = 1;st[i][j]!='\0';j++)
		{
			if(st[i][j] >= 'A' && st[i][j] <= 'Z')
			{
				if(st[i][j+1] >= 'A' && st[i][j+1] <= 'Z')
				{
					cout<<"该文法不是算符文法"<<endl;
					return 0;
				}
			}
		}
	}
	return 1;
}

void readG(string &str)						//读入文法规则
{
	char *t;
	int j = 1;
	st[num][0] = str[0];
	for(t = &str[1];*t != '\0';t ++)
	{
		if(*t == '-' && *(t + 1) == '>')
			t = t + 2;
		st[num][j] = *t;
		j ++;
	}
}


void Label()										//构造终结符号表
{
	int i,j,k,check,temp = 0;
	for(i = 0,k = 0;i < num;i ++)
		for(j = 0;st[i][j] != '\0';j ++)
		{
			if((st[i][j] <'A' || st[i][j]>'Z') && st[i][j] != '|')
			{
				for(check = 0;check <= k;check ++)
				{
					if(st[i][j] == label[check])
						temp = 1;
				}
				if(!temp)
				{
					label[k] = st[i][j];
					k ++;
				}
			}
		}
	label[k] = '#';
	a = k + 1;
}

int locate(char c)								//返回坐标
{
	int i;
	for(i = 0;i < a;i ++)
	{
		if(label[i] == c)
			return (i + 1);
	}
	return 0;
}

void table()									//构造优先表
{
	char temp[20][20];
	int i,j,x = 0,y = 0;
	for(i = 0;i < num;i ++)
	{
		first(st[i][0]);
		last(st[i][0]);
	}
	for(i = 1;i < 20;i ++)
		for(j = 1;j < 20;j ++)
			TABLE[i][j] = '0'; 
	for(i = 0;i < num;i ++)
	{
		temp[x][y]=st[i][0];
		y ++;
		for(j = 1;st[i][j] != '\0';j ++)
		{
			if(st[i][j] == '|')
			{
				temp[x][y] = '\0';
				x ++;
				y = 0;
				temp[x][y] = st[i][0];
				y++;
			}
			else
			{
				temp[x][y] = st[i][j];
				y ++;
			}
		}
		temp[x][y] = '\0';
		x ++;
		y = 0;
	}
	num1 = x;
	for(i = 1;i <= a;i ++)
		TABLE[i][0] = TABLE[0][i] = label[i - 1];
	for(i = 0;i < num1;i ++)
	{
		for(j = 1;temp[i][j + 1] != '\0';j ++)
		{
			if((temp[i][j] < 'A' || temp[i][j] > 'Z') && (temp[i][j + 1] < 'A' || temp[i][j + 1] > 'Z'))
			{
				TABLE[locate(temp[i][j])][locate(temp[i][j + 1])] = '=';
			}
			if((temp[i][j] < 'A' || temp[i][j] > 'Z') && (temp[i][j + 2] < 'A' || temp[i][j + 2] > 'Z'))
			{
				TABLE[locate(temp[i][j])][locate(temp[i][j + 2])] = '=';
			}
			if((temp[i][j] < 'A' || temp[i][j] > 'Z') && (temp[i][j + 1] >= 'A' && temp[i][j + 1] <= 'Z'))
			{
				for(int m = 0;m < num;m ++)
				{
					if(temp[i][j + 1] == st[m][0])
						break;
				}
				for(int n = 1;FIRSTVT[m][n] != '\0';n ++)
				{
					TABLE[locate(temp[i][j])][locate(FIRSTVT[m][n])] = '<';
				}
			}
			if((temp[i][j + 1] < 'A' || temp[i][j + 1] > 'Z') && (temp[i][j] >= 'A' && temp[i][j] <= 'Z'))
			{
				for(int m = 0;m < num;m ++)
				{
					if(temp[i][j] == st[m][0])
						break;
				}
				for(int n = 1;LASTVT[m][n] != '\0';n ++)
				{
					TABLE[locate(LASTVT[m][n])][locate(temp[i][j + 1])] = '>';
				}
			}
		}
	}
	for(i = 1;FIRSTVT[0][i] != '\0';i ++)
	{
		TABLE[a][locate(FIRSTVT[0][i])] = '<';
	}
	for(i = 1;LASTVT[0][i] != '\0';i ++)
	{
		TABLE[locate(LASTVT[0][i])][a] = '>';
	}
	TABLE[a][a] = '=';
}

int operate()									//进行规约操作
{
	char S[20],ch,Q;
	int k = 0,i,j,l;
	S[k] = '#';
	
	for(ch = input[0],i = 0;ch != '#';i ++)
	{
		for(l = 0;l <= k;l ++)
			cout<<S[l]<<" ";
		cout<<endl;
		ch = input[i];
		if(S[k] < 'A' || S[k] > 'Z')
			j = k;
		else
			j = k - 1;
		while(TABLE[locate(S[j])][locate(ch)] == '>')
		{
			do
			{
				Q = S[j];
				if(S[j - 1] < 'A' || S[j - 1] > 'Z')
					j = j - 1;
				else
					j = j - 2;
			}while(TABLE[locate(S[j])][locate(Q)] != '<');
			S[j + 1] = 'N';
			k = j + 1;
			for(l = 0;l <= k;l ++)
				cout<<S[l]<<" ";
			cout<<endl;
		}
		if(TABLE[locate(S[j])][locate(ch)] == '<' || TABLE[locate(S[j])][locate(ch)] == '=')
		{
			k ++;
			S[k] = ch;
		}
		else
		{
			cout<<"ERROR"<<endl;
			return 0;
		}
	}
	cout<<"规约成功！"<<endl;
	return 1;
}

int main()
{
	string str,s;
	bool jus = 0;
	int i,j;
	ifstream fin;
	fin.open("Source File.txt",ios::in);
	if(fin == NULL)
	{
		cout<<"打开文件失败！"<<endl;
		return -1;
	}
	for(num = 0;getline(fin,str);num ++)
		readG(str);
	cout<<"文法规则为：\n";
	for(i = 0;i < num;i ++)
	{
		cout<<st[i]<<endl;
		FIRSTVT[i][0] = 0;
		LASTVT[i][0] = 0;
	}
	cout<<endl;
	if(!judge())
	{
		system("pause");
		return 0;
	}
	Label();
	cout<<"终结符号表为："<<endl;
	cout<<label<<endl;
	cout<<endl;
	table();
	cout<<"FIRSTVT集为："<<endl;
	for(i = 0;i < num;i ++)
	{
		cout<<st[i][0]<<"->";
		for(j = 1;FIRSTVT[i][j] != '\0';j ++)
			cout<<FIRSTVT[i][j];
		cout<<endl;
	}
	cout<<endl;
	cout<<"LASTVT集为："<<endl;
	for(i = 0;i < num;i ++)
	{
		cout<<st[i][0]<<"->";
		for(j = 1;LASTVT[i][j] != '\0';j ++)
			cout<<LASTVT[i][j];
		cout<<endl;
	}
	cout<<endl;
	cout<<"符号表为："<<endl;
	for(i = 0;i <= a;i ++)
	{
		for(j = 0;j <= a;j ++)
			cout<<TABLE[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	cout<<"请输入待规约串（以#结尾）："<<endl;
	cin>>input;
	cout<<endl;
	cout<<"规约过程如下："<<endl;
	if(!operate())
	{
		system("pause");
		return 0;
	}
	fin.close(); //关闭文件
	system("pause");
	return 0;
}