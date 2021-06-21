/*
 * @Author: Ken Kaneki
 * @Date: 2021-05-01 16:54:59
 * @LastEditTime: 2021-05-01 19:09:45
 * @Description: README
 * @FilePath: \C-Cpp_SimpleFile_Example\test.cpp
 */
#define MAX 32767       //定义一个很大的数当作是不存在直接路径的标志
#define N 6             //图的顶点数量
typedef struct AM_Graph //图的邻接矩阵类型
{
    int AdjMatrix[N][N]; //邻接矩阵存放各点之间的距离
    int VexNum, ArcNum;  //存放顶点数量和弧的数量
    char VexName[N];     //顶点名称
} AM_VexName[N];         //顶点名称
int main()
{
    int i, j;
    int dis[N][N];
    int EC[N];
    AM_Graph g;
    printf("请输入各个顶点的名称(中间没有空格,请以回车键结束):");
    for (i = 0; i < N; i++)
        scanf("%c", &g.VexName[i]); //为顶点名称赋值，实际上在顶点个数不是5的情况可以顺延到下一位ASCII码对应的字符，也可作一定改进让用户自行输入
    //  char VexName[N]={'a','b','c','d','e','f'};
    for (i = 0; i < N; i++)
    { //为各个顶点的直接距离赋值
        for (j = 0; j < N; j++)
        {
            if (i == j)
                continue;
            printf("请输入第%d点到第%d点的距离(如果没有直接路径请输入-1):", i + 1, j + 1);
            scanf("%d", &dist[i][j]);
        }
    }
    for (i = 0; i < N; i++)
    { //没有直接距离的时候赋值为MAX
        dist[i][i] = 0;
        for (j = 0; j < N; j++)
        {
            if (dist[i][j] < 0)
                dist[i][j] = MAX;
        }
    }
}
//计算函数
void Floyd(AM_Graph g, int Dist[N][N])
{
    //Floyd算法求解各顶点之间的最短路径，传递的参数为存放有直接路径长度的矩阵
    printf("==============图的赋值准备==============\n");
    int i, j, k;
    int count = 0;
    //记录边的数量，方法是初始的矩阵所有不是0也不是MAX的元素个数可视为一条边
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if ((Dist[i][j] != 0) && (Dist[i][j] != MAX))
                count++;                    //记录边的个数
            g.AdjMatrix[i][j] = Dist[i][j]; //用传递的二维数组为图的邻接矩阵赋值
        }
    }
    g.VexName = N; //为图的各项元素赋值
    g.ArcNum = count;
    printGraph(g); //输出图的各项信息，以检验是否赋值成功
    printf("==============Floyd算法求解==============\n");
    for (k = 0; k < N; k++)
    { //用图中的每一点作为中间遍历dist矩阵
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                if (Dist[i][j] > (Dist[i][k] + Dist[k][j]))
                {                                         //如果把k作为中间点会让距离变小
                    Dist[i][j] = Dist[i][k] + Dist[k][j]; //修改顶点之间的距离
                }
            }
        }
    }
}
