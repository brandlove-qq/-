#ifndef NEWFUNCTION_H
#define NEWFUNCTION_H

/*!
  *@author:    wuxxxxx
 * @brief:    边类的声明
 * @date:     2023/05/7
 * @param:    vertex表示相邻顶点，weight表示权重
 * @param:
 * @function： 重载了"<“和”=="运算符，这样Edge的对象就可以在集合中进行排序和查找
 * @return:
*/

template <typename T>
class Edge
{
public:
    T vertex;   //端点
    int weight;  //权重

    Edge(T neighbour_vertex)
    {
        this->vertex = neighbour_vertex;
        this->weight = 0;
    }

    Edge(T neighbour_vertex, int weight)
    {
        this->vertex = neighbour_vertex;
        this->weight = weight;
    }

    bool operator<(const Edge& obj) const
    {
        return obj.vertex > vertex;
    }

    bool operator==(const Edge& obj) const
    {
        return obj.vertex == vertex;
    }
};

#endif // NEWFUNCTION_H
