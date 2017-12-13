#include <stdio.h>
#include <stdlib.h>

struct steck
{
	int mass[1000];
	int p;
};

void Push(struct steck* s, int x)
{
	if (s->p < 1000)
	{
		s->mass[s->p] = x;
		s->p++;
	}
}

int Pop(struct steck* s)
{
	if (s->p > 0)
	{
		s->p--;
		return s->mass[s->p];
	}
	return 0;
}

int main(void)
{
	int m[10][10] = {{0,0,0,0,0,0,0,0,0,0},
			   		{0,2,0,0,0,0,0,0,0,0},
					{0,2,0,0,0,0,0,0,0,0},
					{0,2,2,0,0,2,0,0,0,0},
					{0,2,0,2,2,2,2,2,2,0},
					{0,0,0,2,0,0,0,0,0,0},
					{0,2,2,2,0,0,0,0,2,2},
					{0,2,0,0,0,0,0,0,0,0},
					{0,2,0,0,0,0,0,0,0,0},
					{0,2,0,0,0,0,0,0,0,0}};
	struct steck s;
	int i, j;
	s.p = 0;
	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 10; j++)
		printf("%d", m[i][j]);
		printf("\n");
	}
	printf("\n");
	i = 0;
	j = 0;
	m[0][0] = 1;
	while(i + j < 18)
	{
		if(i < 9 && m[i + 1][j] == 0)
		{
			m[i][j] = 1;
			Push(&s, i);
			Push(&s, j);
			i++;
		}
		else
		{
			if(j < 9 && m[i][j + 1] == 0)
			{
				m[i][j] = 1;
				Push(&s, i);
				Push(&s, j);
				j++;
			}
			else
			{
				if(i > 0 && m[i - 1][j] == 0)
				{
					m[i][j] = 1;
					Push(&s, i);
					Push(&s, j);
					i--;
				}
				else
				{
					if(j > 0 && m[i][j - 1] == 0)
					{
						m[i][j] = 1;
						Push(&s, i);
						Push(&s, j);
						j--;
					}
					else
					{
						m[i][j] = 3;
						j = Pop(&s);
						i = Pop(&s);
					}
				}
			}
		}

	}
	if((m[1][0] == 3 && m[0][1] == 1) || (m[1][0] == 1 && m[0][1] == 3))
		m[0][0] = 3;
	else m[0][0] = 1;
	m[9][9] = 1;
	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 10; j++)
		printf("%d", m[i][j]);
		printf("\n");
	}
	return 0;
}
