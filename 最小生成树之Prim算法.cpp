#include<stdio.h>
#include<stdlib.h>
#define INF 10005

//Kruskal�㷨 --------->ϡ��ͼ------->ѡ��
//Prim�㷨 ------------>����ͼ------->ѡ��
/*
	��x������������С����dist[x];
	���Ϊx�ĵ㵽�������еĶ����������ѡȨֵ��С�ı�Ȩ��
	˼·�������ѡ��һ���ڵ���Ϊ��ʼ�㣬Ȼ�������õ����������е�·����̵ĵ���Ϊ�ڶ��㣬
	���Ŵӵڶ��������������е��к���ʼ�����������е���ѡ��·����̵ĵ���Ϊ�������ڵ㣬��������ѭ����ֱ�����е㶼��ѡ��
*/


//���ڽӾ����ͼΪ��
int g[105][105]; //�����жϾ����С
int dist[105];  // �жϸõ㵽������̾��룬Ĭ��ΪINF
int flag[105]; // �ж϶����Ƿ񱻷���,0û�з��ʣ�1Ϊ�Ѿ�����
int n, m;


//Prim�㷨
void Prim() 
{
	int start = 0; //�����Լ�����һ�����
	dist[start] = 0; //�õ㵽���ľ���Ϊ0
	flag[start] = 1; //���Ϊ�ѷ���
	printf("�����%d���뵽��С��������\n", start);
	for (int i = 0; i < n; i++)  //����õ�������δ�����ʵĵ���ѡ��·����̵ĵ�
	{
		if (dist[i] > g[start][i] && flag[i] == 0)
		{
			dist[i] = g[start][i];
		}
	}
	int tmp; //dist��Сֵ�ĵ�ı��
	int minn; //��Сdistֵ
	for (int j = 1; j < n; j++)
	{
		minn = INF;
		tmp = -1;
		for (int i = 0; i < n; i++) //�ӵڶ����㿪ʼ��ѡ��·����̵ĵ�
		{
			if (flag[i] == 0 && dist[i] < minn)
			{
				tmp = i;
				minn = dist[i];
			}
		}
		printf("��%d ͨ��ȨֵΪ%d�ߣ����뵽��С��������\n", tmp, minn);
		dist[tmp] = 0; //ѡ�еĵ㵽���ľ���Ϊ0
		flag[tmp] = 1; //���Ϊ�Ѿ�����
		for (int i = 0; i < n; i++)  //���ڸո�ѡ��ĵ㣬����һ��������㵽������̾��룬����ո�ѡ��ĵ㵽������ľ���С��������ԭ���ľ��룬���޸�
		{
			if (flag[i] == 0 && dist[i] > g[tmp][i])
			{
				dist[i] = g[tmp][i];
			}
		}
	}
}


int main() {
	scanf("%d %d", &n, &m);
	//��ʼ��
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				g[i][j] = g[j][i] = INF;
			}
		}
		dist[i] = INF;
	}

	int x, y, w;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &x, &y, &w);
		g[x][y] = g[y][x] = w;
	}
	Prim();
	return 0;
}
