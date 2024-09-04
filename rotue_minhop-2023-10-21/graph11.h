#ifndef GRAPH_H
#define GRAPH_H

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<limits.h>
#include "newfunction.h"
#include <limits>
#include <unordered_map>


#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

/*!
  *@author:    wuxxxxx
 * @brief:    GRAPH
 * @date:     2023/05/10
 * @param:
 * @param:   图的定义--------------这里利用模板实现
 * @return:
*/

using namespace std;

/************************************************************************************************************
 *拓扑图的相关信息：
 *  此类结点需区分层级区别注意所带信息：
 * 1.LSW-24P--系列交换机20个----编号0-19----如果是这系列的交换机结点连接的信息（20个节点）
 * 主要是NRM的连接关系区分
 *
 * 2.NRM-20p系列一共6个机柜-----一个机柜4个此类型的交换机编号0-3：（4x6=24个节点）
 * 每片NRM-20P上带有6片芯片---HNR(编号0-5)---一个机柜HNR芯片数目：6*4=24
 *  每一片NRM连接32个节点（终端节点-背板的结点--计算结点）
 *
 * 3.在每个HNR结点直接有连接关系区分：---HNR之间的连接关系(多连接关系)
 * 注意：区分连接关系主要有：与LSW-24上一层的节点的连接关系区分主要连接的LSW-24P为HNR-3-5：
 * HNR0-6节点之间的区分：HNR节点是有连接关系的：后期路由时还要进一步区分：目前只它当一个节点使用（多链接关系）
 * 计算节点(32个节点)主要连接在：HNR0-2:
 * 所以当前层级关系：LSW-24P为最上层，NRM-20P为下一层（分两层：HNR3-5;HNR0-2）； 计算机节点（背板结点）为最底层
 * 1.LSW-24P(20)
 * 2.NRM-20P(4*6)----HNR3-5---连接LSW-24P
 * 3.HNR0-2---连接计算结点
 * 4.计算节点--背板结点（32）
**************************************************************************************************************/

/***********************************************************************************************************
 * 模板类
 * map：存储键值对(key-value)的容器，提供一对一（其中第一个可以称为关键字，每个关键字只能在map中出现一次，
 * 第二个可以称为该关键字所对应的值）的数据处理能力。这里把顶点设置为键，其对应的邻接点和边的权重的集合设置为值。
 * set：不会有相同元素，并且存进去的元素会自动进行升序排序（默认情况下），set就是每一个顶点的邻接表
 * 考虑使用有相同元素情况：multiset<>----目前觉得多链接和显示一个没有任何区别--最后还要查询当前结点拿端口信息--模拟底层硬件链路
 * **********************************************************************************************************/

template <typename T>
class Graph
{
public:
    map<T, set<Edge<T>>> adj;  /* 邻接表 */

    bool contains(const T& u); /* 判断顶点u是否在图中 */
    bool adjacent(const T& u, const T& v); /* 判断顶点u和v是否相邻 */

    void add_vertex(const T& u); /* 添加顶点 */
    void add_edge(const T& u, const T& v, int weight); /* 添加边和权重 */

    void change_weight(const T& u, const T& v, int weight); /* 修改权重 */

    void remove_weight(const T& u, const T& v); /* 移除权重 */
    void remove_vertex(const T& u); /* 移除顶点 */
    void remove_edge(const T& u, const T& v); /* 移除边 */

    int degree(const T& u); /* 求顶点的度数 */
    int num_vertices(); /* 求图中顶点的总数 */
    int num_edges(); /* 求图中边的总数*/
    int largest_degree(); /* 求图中的最大度数 */

    int get_weight(const T& u, const T& v); /* 得到某两个顶点之间边的权重 */
    vector<T> get_vertices(); /* 得到图中所有顶点 */
    /*返回邻居的两种形式---返回邻居边----返回邻居结点*/

    map<T, int> get_neighbours(const T& u); /* 得到顶点u的所有边------名和权值*/

    vector<T> get_neighbours_anothertype(const T& u);  /*返回邻居结点------T名*/

    void show();

    /*!
      *@author:    wuxxxxx
     * @brief:     图的遍历算法----深度----广度
     * @date:     2023/05/10
     * @param:    T表示数据类型
     * @param:
     * @return:  返回vector数组
    */

    void dft_recursion(const T& u, set<T>& visited, vector<T>& result); /* 深度优先遍历递归辅助函数 */
    vector<T> depth_first_rec(const T& u); /* 深度优先遍历递归法 */
    vector<T> depth_first_itr(const T& u); /* 深度优先遍历迭代法*/
    vector<T> breadth_first(const T& u); /* 广度优先遍历迭代法 */

    /*!
      *@author:    wuxxxxx
     * @brief:    prim（）
     * @date:     2023/05/10
     * @param:    T表示数据类型，start表示某个源结点
     * @param:
     * @return:返回一个类对象
    */

    Graph<T> prim(T v); /* prim最小生成树算法 */



    /*!
      *@author:    wuxxxxx
     * @brief:    dijkstra1---返回图所有结点的最短路径---建图测试使用不公开
     * @date:     2023/05/10
     * @param:    T表示数据类型，start表示某个源结点
     * @param:
     * @return:返回一个map键值表：保存的是从源结点到每个结点的最短路径信息
    */



    map<T, int> dijkstra(T start); /*  dijkstra最短路径算法 */


};

template <typename T> void Graph<T>::show()
{
    for (const auto& u : adj)
    {
        cout <<""<< u.first << ": ";
        for (const auto& v : adj[u.first])
            cout << "(adjacent ver: " << v.vertex << ", edge weight:" << v.weight << ") ";
        cout <<endl;
    }
}

template <typename T> bool Graph<T>::contains(const T& u)
{
    return adj.find(u) != adj.end();
}

template <typename T> bool Graph<T>::adjacent(const T& u, const T& v)
{
    if (contains(u) && contains(v) && u != v)
    {
        for (auto edge : adj[u])
            if (edge.vertex == v)
                return true;
    }
    return false;
}



template <typename T> void Graph<T>::add_vertex(const T& u)
{
    if (!contains(u))
    {
        set<Edge<T>> edge_list;
        adj[u] = edge_list;
    }
}



template <typename T> void Graph<T>::add_edge(const T& u, const T& v, int weight)
{
    if (!adjacent(u, v))
    {
        adj[u].insert(Edge<T>(v, weight));
        adj[v].insert(Edge<T>(u, weight));
    }
}

template <typename T> void Graph<T>::change_weight(const T& u, const T& v, int weight)
{
    if (contains(u) && contains(v))
    {
        if (adj[u].find(Edge<T>(v)) != adj[u].end())
        {
            adj[u].erase(Edge<T>(v));
            adj[u].insert(Edge<T>(v, weight));
        }

        if (adj[v].find(Edge<T>(u)) != adj[v].end()) {
            adj[v].erase(Edge<T>(u));
            adj[v].insert(Edge<T>(u, weight));
        }
    }
}

template <typename T> void Graph<T>::remove_weight(const T& u, const T& v)
{
    if (contains(u) && contains(v))
    {
        if (adj[u].find(Edge<T>(v)) != adj[u].end())
        {
            adj[u].erase(Edge<T>(v));
            adj[u].insert(Edge<T>(v, 0));
        }

        if (adj[v].find(Edge<T>(u)) != adj[v].end())
        {
            adj[v].erase(Edge<T>(u));
            adj[v].insert(Edge<T>(u, 0));
        }
    }
}

template <typename T> void Graph<T>::remove_vertex(const T& u)
{
    if (contains(u))
    {
        for (auto& vertex : adj)
        {
            if (vertex.second.find(Edge<T>(u)) != vertex.second.end())
                vertex.second.erase(Edge<T>(u));
        }
        adj.erase(u);
    }
}

template <typename T> void Graph<T>::remove_edge(const T& u, const T& v)
{
    if (u == v || !contains(u) || !contains(v)) return;

    if (adj[u].find(Edge<T>(v)) != adj[u].end())
    {
        adj[u].erase(Edge<T>(v));
        adj[v].erase(Edge<T>(u));
    }
}

template <typename T> int Graph<T>::degree(const T& u)
{
    if (contains(u)) return adj[u].size();

    return -1; // 度数为-1说明图中没有该顶点
}

template <typename T> int Graph<T>::num_vertices()
{
    return adj.size();
}

template <typename T> int Graph<T>::num_edges()
{
    int count = 0;
    set<Edge<T>> vertex_set;

    for (auto vertex : adj)
    {
        vertex_set.insert(Edge<T>(vertex.first, 0));
        for (auto edge : vertex.second) {
            if (vertex_set.find(edge) != vertex_set.end()) continue;
            count++;
        }
    }
    return count;
}

template <typename T> int Graph<T>::largest_degree()
{
    if (num_vertices() == 0) return 0;

    unsigned max_degree = 0;
    for (auto vertex : adj)
    {
        if (vertex.second.size() > max_degree)
            max_degree = vertex.second.size();
    }
    return max_degree;
}

template <typename T> int  Graph<T>::get_weight(const T& u, const T& v)
{
    if (contains(u) && contains(v))
    {
        for (Edge<T> edge : adj[u])
            if (edge.vertex == v) return edge.weight;
    }
    return -1;
}

template <typename T> vector<T> Graph<T>::get_vertices()
{
    vector<T> vertices;
    for (auto vertex : adj)
        vertices.push_back(vertex.first);

    return vertices;
}

template <typename T> map<T, int> Graph<T>::get_neighbours(const T& u)
{
    map<T, int> neighbours;

    if (contains(u))
    {
        for (Edge<T> edge : adj[u])
            neighbours[edge.vertex] = edge.weight;
    }

    return neighbours;
}

template <typename T> vector<T> Graph<T>::get_neighbours_anothertype(const T& u)
{
    vector<T> neighbours;

    if (contains(u))
    {
        for (Edge<T> edge : adj[u])
            neighbours.push_back(edge.vertex);
    }

    return neighbours;
}



template <typename T> void Graph<T>::dft_recursion(const T& u, set<T>& visited, vector<T>& result)
{
    result.push_back(u);
    visited.insert(u);

    for (Edge<T> edge : adj[u])
        if (visited.find(edge.vertex) == visited.end())
            dft_recursion(edge.vertex, visited, result);
}



template <typename T> vector<T> Graph<T>::depth_first_rec(const T& u)
{
    vector<T> result;
    set<T> visited;
    if (contains(u))  dft_recursion(u, visited, result);
    return  result;
}



template <typename T> vector<T> Graph<T>::depth_first_itr(const T& u)
{
    vector<T> result;
    set<T> visited;
    stack<T> s;

    s.push(u);
    while (!s.empty())
    {
        T v = s.top();
        s.pop();

        if (visited.find(v) != visited.end()) {
            continue;
        }
        visited.insert(v);
        result.push_back(v);

        for (auto w : adj[v])
        {
            if (visited.find(w.vertex) == visited.end())
            {
                s.push(w.vertex);
            }
        }
    }
    return  result;
}


template <typename T> vector<T> Graph<T>::breadth_first(const T& u)
{
    vector<T>result;
    set<T> visited;
    queue<T> q;

    q.push(u);//a
    while (!q.empty())
    {
        T v = q.front();
        q.pop();

        if (visited.find(v) != visited.end())
        {
            continue;
        }

        visited.insert(v);
        result.push_back(v);

        for (Edge<T> edge : adj[v]) {
            if (visited.find(edge.vertex) == visited.end())
            {
                q.push(edge.vertex);
            }
        }
    }
    return result;
}


template <typename T> Graph<T> Graph<T>::prim(T v)
{
    // 最小生成树的创建
    Graph<T> min_spanning_tree;

    // 在生成树中添加顶点v
    min_spanning_tree.add_vertex(v);

    // 设置带权重的队列，按第一个元素（权值）进行从小到大的排列
    priority_queue<pair<int, pair<T, T>>, vector<pair<int, pair<T, T>>>, greater<pair<int, pair<T, T>>>> q;

    // 设置集合visited来存放已经访问过的顶点
    set<T> visited;

    // 入队：入队的元素是一个pair类型，第一个值是权重，第二个值也是pair
    // 第二个值的pair里面第一个值是u（只在生成树中存在的顶点）, 第二个值是v（只在在原图中存在的点）
    for (auto neighbour : adj[v])
    {
        q.push(make_pair(neighbour.weight, make_pair(v, neighbour.vertex)));
    }

    while (!q.empty())
    {
        // 队首元素出队
        auto front = q.top();
        q.pop();

        // 获得已在生成树中的顶点u
        T u = front.second.first;

        // 获得在原图中, 但不在生成树中的顶点v
        T v = front.second.second;

        // 如果顶点v已经访问过则跳过本此循环
        if (visited.find(v) != visited.end()) continue;
        else visited.insert(v);

        // 在生成树中添加新的顶点v以及v和u之间的边
        min_spanning_tree.add_vertex(v);
        min_spanning_tree.add_edge(u, v, front.first);

        // 依次将顶点v尚未访问过的邻居放入优先队列中
        for (auto neighbour : adj[v]) {
            if (visited.find(neighbour.vertex) == visited.end()) {
                q.push(make_pair(neighbour.weight, make_pair(v, neighbour.vertex)));
            }
        }
    }//while
    return min_spanning_tree;
}


template <typename T> map<T,int> Graph<T>::dijkstra(T start)
{
    // 设置dis用来存放初始点到图中任何一个顶点的距离
    map<T, int> dis;

    // 设置带权重的队列，按每个pair的第一个元素进行从小到大的排列
    priority_queue<pair<int, T>, vector<pair<int, T>>, greater<pair<int, T>>> q;

    for (T vertex: get_vertices())
    {
        // 设置初始顶点到自己的距离为0
        if(vertex == start) dis[start] = 0;
        // 设置初始顶点到其他顶点的距离为无穷大
        else dis[vertex] = INT_MAX;
    }

    // 设置集合visited来存放已经访问过的顶点
    set<T> visited;

    // 入队：入队的元素是一个pair类型，第一个值是权重，第二个值是顶点
    q.push(make_pair(0,start));

    while (!q.empty())
    {
        // 队首元素出队
        auto front = q.top();
        q.pop();

        // 获得当前顶点
        T u = front.second;

        // 如果该顶点已经访问过则跳过本此循环，否则存入到集合visited中表示已经访问过
        if (visited.find(u) != visited.end()) continue;
        else visited.insert(u);

        // 获得到顶点u的最短路径"shortest_distance_to_u"，将此路径存入到dis结果中
        int shortest_distance_to_u = front.first;
        dis[u] = shortest_distance_to_u;

        // 依次访问顶点u尚未访问过的邻居
        for (auto v : adj[u])
        {
            if (visited.find(v.vertex) == visited.end()) {
                // 从顶点u到邻居v的路径记为“distance_to_v”
                int distance_to_v = v.weight;
                q.push(make_pair(shortest_distance_to_u + distance_to_v,  v.vertex));
            }
        }
    } //while
    return dis;
}


#endif // GRAPH_H
