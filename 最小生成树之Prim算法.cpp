#include<stdio.h>
#include<stdlib.h>
#define INF 10005

//Kruskal算法 --------->稀疏图------->选边
//Prim算法 ------------>稠密图------->选点
/*
	点x到生成树的最小距离dist[x];
	编号为x的点到生成树中的多个点相连，选权值最小的边权。
	思路：先随便选择一个节点作为起始点，然后根据与该点相连的所有点路径最短的点作为第二点，
	接着从第二个点相连的所有点中和起始点相连的所有点中选择路径最短的点作为第三个节点，依次这样循环，直至所有点都被选完
*/


//以邻接矩阵存图为例
int g[105][105]; //用来判断距离大小
int dist[105];  // 判断该点到树的最短距离，默认为INF
int flag[105]; // 判断顶点是否被访问,0没有访问，1为已经访问
int n, m;


//Prim算法
void Prim() 
{
	int start = 0; //可以自己声明一个起点
	dist[start] = 0; //该点到树的距离为0
	flag[start] = 1; //标记为已访问
	printf("把起点%d加入到最小生成树中\n", start);
	for (int i = 0; i < n; i++)  //从与该点相连且未被访问的点中选择路径最短的点
	{
		if (dist[i] > g[start][i] && flag[i] == 0)
		{
			dist[i] = g[start][i];
		}
	}
	int tmp; //dist最小值的点的编号
	int minn; //最小dist值
	for (int j = 1; j < n; j++)
	{
		minn = INF;
		tmp = -1;
		for (int i = 0; i < n; i++) //从第二个点开始，选择路径最短的点
		{
			if (flag[i] == 0 && dist[i] < minn)
			{
				tmp = i;
				minn = dist[i];
			}
		}
		printf("点%d 通过权值为%d边，加入到最小生成树中\n", tmp, minn);
		dist[tmp] = 0; //选中的点到树的距离为0
		flag[tmp] = 1; //标记为已经访问
		for (int i = 0; i < n; i++)  //对于刚刚选择的点，修正一下其他结点到树的最短距离，如果刚刚选择的点到其他点的距离小于其他点原来的距离，则修改
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
	//初始化
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
