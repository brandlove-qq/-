#ifndef COMMON_H
#define COMMON_H
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include "graph11.h"
#include <fstream>
#include <list>
#include <unordered_map>
#include <regex>
#include <algorithm>
#include <functional>
#include "loadbalance.h"
#include "concurrentqueue.h"
#include <unordered_set>

using namespace std;

#define  filepath      "E:/newworkcode/dj/fattree768nodes.topo"
#define  filepath1     "E:/newworkcode/dj/test_tuopu.txt"
#define  outputfile_rule_test "E:/newworkcode/dj/topo_output.txt"
#define  outputfile_write_infile "E:/newworkcode/result/"
//测试打印
#define  test            0
//交换机文件写入
#define  write           1

//板内多端口负载均衡（轮询法）---多端口限制记录--
typedef struct  mutilport_handle
{
    string switchname;  //当前交换机名

    string  targename; //源-目的对----目的名

    int inport;    //当前交换机入端口

    string   previous_outport_link;   //记录上一次以相同端口进来，分发的出端口链路

}mulitport_handle_limit;


// 节点的结构体--------交换机结点
typedef struct Node
{
    int  id1;   //规则下发编号
    string id; //拓扑构建标明结点编号
    int nodetype=0;  //结点类型
    //节点的其他信息---每个结点的端口映射:map记录各个端口（map存储端口信息）---0-23
    //map<int,std::string>  linkdatas; //结点24个端口---连接关系
    std::unordered_multimap<int,std::string>  linkdatas;    //相同端口也会记录
    //HNR多链接关系表示-----12个端口---3组多链路信息（map储存一个NRM之间信息）
    map<string,string> multilink;   //---源-目的编号/端口---连接关系--12
    //flag-----标记各个结点类型
    bool  is_multilink=false;     //是否多链接结点
    bool  is_switchnode=false;

    //负载均衡参数
    int    multilink_portnum=0;        //多链接-接口的总数：本系统3个
    int    multilink_linknum=0;    //多连接接口的链路数：本系统4条
    //对象数组（管理负载平衡）--每个对象负责自己的接口轮询--用智能指针管理资源
    std::vector<LoadBalancer> p1;
    //     LoadBalancer  *loadBalancers;
    int  loadbalanceobject_size;     //对象个数

    // 对负载平衡:多个端口经行限制
    bool  is_limitport_swit;              //链接了终端节点/没有多链接端口的交换机不需记录出端口数据
    string  inport_targetname;            //入端口-目的
    std::unordered_map  <std::string, mutilport_handle>   getnextserver_record; //已分配的出端口链路

}switch_linkendnode_node,LSW_24P_node,switch_node; //后边确认是那种结点利用标记


//背板结点：不需要储存其他信息-----计算结点
typedef struct backNode
{
    int id1;    //规则下发的编号
    int nodetype=0; //结点类型
    string id;  //拓扑标明结点唯一编号
    string  link;  //连接信息
    bool is_terminalnode=false;
}endnode_node;

//data---连接数据
typedef struct  linkdata
{
    //类型
    int type;
    //编号
    int serialnumber;
    //端口--只有交换机结点有端口
    int port;
}switch_data,endnode_data;

//负载均衡：返回的结点标号/下一个结点的输入端口
typedef  struct  Loadbalance_data
{
    string  currctnode_name;
    int   nextnode_inputport;
}nextdataport;

// 用于保存路径的结构体
struct Path
{
    vector<string> nodes;
    int distance;

    Path() : distance(0) {}
};

//-------------------------------------------待加----从文件获取信息(?????)
//结点芯片型号-----本系统：endnode:2  ;switchnide:1
typedef struct system_nodetype
{
    int switchnode_type;
    int endnode_type;
}node_type;

//转发规则--写入结构体
typedef  struct  forword
{
  string   switchname;
  string   forword_rule;
}forword_rule;

//转发规则-缓存,处理写入相同项
typedef struct  forword_cache
{
    int target;
    int  inputport;
    int outputport;
    int  sum=0; // 可不用
    string  outputdata;
}forword_handle;


//统一配置数据结构体--封装------待加
typedef  struct configure
{



}configure_system;


typedef std::function<void(std::vector<string> &,\
                                 switch_node *,\
                                          const int)>  callback;

typedef std::function<void(std::vector<string> &,\
                                    const string ,\
                                     switch_node *,\
                                              const int )>  callback1;


#endif // COMMON_H
