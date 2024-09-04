#include <iostream>
#include "directgraph.h"
#include "common.h "
#include "route_sssp.h"
using namespace std;


int main()
{
    //大拓扑按照文件结点编号生成---区别int编号相同方法：加string区分："switchxx","endnodexx"
    //有向图,区别之前minhop版本无向图
    Graph<string> g;
    // 从文件读取相应的字符串信息保存
    std::ifstream file(filepath);
    std::list<std::string> strings;
    readfilealldata(strings,file);
    //获取相应结点数量

    string s1;
    string  s2;
    extractFirstTwoElements(strings,s1,s2);
    int  switchnum=0,endnodenum=0;
    extractNumber_change(s1,endnodenum);
    extractNumber_change(s2,switchnum);
    //创建交换机相关结点---设置唯一区别id(string)----后期需要优化-----查找时间快的存储结构（支持后期查找修改--使用map）
    std::unordered_map<std::string,switch_node>  switchnodes;  //节点信息存储--节点名--节点信息
    std::unordered_map<std::string,endnode_node>  endnodes;  //节点信息存储--节点名--节点信息
    // creatgraph_switchnodes(switchnum,switchnodes);
    //背板连接的计算结点
    //creatgragph_endnodes(endnodenum,endnodes);

    //读取数据创建结点，并添加进图结构中
    //    creatgraph_addvertex(g,endnodes,endnodenum,switchnodes,switchnum);
    //添加边-----(当前权值统一为1--后期权值可以从数据加入)
    creatgraph_addedge(g,endnodes,endnodenum,switchnodes,switchnum,strings);
  #if test
    //test
    test_show_switchnode_information(switchnodes,0,0);
    test_show_endnode_information(endnodes,0,0);

    //    std::cout << std::endl;
    //        test_show_graph(g);
    //计算路径，改进sssp-只计算终端节点
    //    std::string  source="endnode0";
    //    auto shortestPaths = g.sssp11(g, source);
    //    std::cout << std::endl;
    //    switcnode_multilinkshow(switchnodes,switchnum,1);
    moodycamel::ConcurrentQueue<string>    saveinformation_conqueque;
    calculates_and_save_allendnode_shortpath_test(g,switchnodes,switchnum,endnodes,endnodenum,saveinformation_conqueque);
#endif

#if  write
    //所有计算结点路由数据保存----每个交换机一个文件：测试完成在加
    int n=endnodenum;
    //    int n= 32;
    moodycamel::ConcurrentQueue<forword_rule>    saverule_conqueque; //写入文件的测试检测接口
    // 使用一个哈希表来跟踪每个 switchname 对应的文件输出流
    std::unordered_map<std::string, std::ofstream> fileStreams;
    std::unordered_multimap<std::string,forword_handle> cache_forwardddata1;
    if(calculates_and_save_allendnode_shortpath(n,g,switchnodes,switchnum,endnodes,endnodenum,saverule_conqueque,fileStreams,cache_forwardddata1))
        std::cout << "data saved !!" << std::endl;

#endif

    return 0;
}
