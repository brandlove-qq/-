#ifndef ROUTE_MINHOP_H
#define ROUTE_MINHOP_H

#include "common.h"


/*!
  *@author:    xxxxx
 * @brief:    test---------测试所有最短路径算法，调用的时候输入源结点
 * @date:     2023/07/14
 * @param:    g图数据结构----source源结点
 * @param:
 * @return:
 * 注：打印整个图结构所有结点的最短路径距离
*/

void test1(Graph<string>  g,string  source);

/*!
  *@author:    xxxxx
 * @brief:    creatgragph_endnodes----------赋值终端结点id
 * @date:     2023/07/6
 * @param:    endnodenum 结点数目;p数组指针
 * @param:
 * @return:
 * 注：建立拓扑时为了唯一区分节点id号，使用一个string类型的来区分
*/

void creatgragph_endnodes(const int endnodenum, endnode_node *ptr);


/*!
  *@author:    xxxxx
 * @brief:    creatgragph_endnodes-----赋值交换机结点id
 * @date:     2023/07/6
 * @param:    switchnodenum 结点数目;p数组指针
 * @param:
 * @return:
*/

void creatgraph_switchnodes(const int switchnodenum,switch_node *ptr);

/*!
  *@author:    xxxxx
 * @brief:    extractNumbe---提取数字
 * @date:     2023/07/6
 * @param:    str 字符串;num数字
 * @param:
 * @return:----------
 *注： 建立拓扑时为了唯一区分节点id号，使用一个string类型的来区分
*/

void  extractNumber(const std::string& str,int &num);


/*!
  *@author:    xxxxx
 * @brief:    extractFirstTwoElements-------提取字符串链表前两个元素，保存删除
 * @date:     2023/07/6
 * @param:    strings 字符串链表;  c1/c2字符串（保存）
 * @param:
 * @return:
 * 注：函数提取前两行的节点（交换/计算）总数
*/

void extractFirstTwoElements(std::list<std::string>& strings,string &c1,string &c2);

/*!
  *@author:    xxxxx
 * @brief:    readfilealldata-------读取后台的拓扑文件
 * @date:     2023/07/6
 * @param:    s 字符串链表;  file 文件
 * @param:
 * @return:
*/

void  readfilealldata(std::list<std::string>& s,std::ifstream &file);

/*!
  *@author:    wuxxxxx
 * @brief:    extractNumber--------提取结点间连接关系并且保存
 * @date:     2023/07/6
 * @param:    str提取的数据;  linkdata保存数据
 * @param:
 * @return:
*/

void  extractNumber(std::vector<int> & str,linkdata &data1,linkdata &data2);

/*!
  *@author:    wuxxxxx
 * @brief:    extractNumbers ---提取字符串的数字，保存到数组（连接信息）
 * @date:     2023/07/6
 * @param:    str当前的字符串信息
 * @param:
 * @return: 返回一个数组--切分后的数据（转化为int）
*/

std::vector<int> extractNumbers(const std::string& str);

/*!
  *@author:    wuxxxxx
 * @brief:   creatgraph_addnode-----添加所有结点到图-----------------十几万级别？？？----map会比数组快--优化点
 * @date:     2023/07/6
 * @param:    g 拓扑图;  ptr计算结点数组指针,ptr1交换计结点数组指针
 * @param:
 * @return:
*/

void creatgraph_addvertex(Graph<string> &g,const endnode_node *ptr,const int endnodenum,
                          const switch_node *ptr1,const int swithnodenum);

/*!
  *@author:    wuxxxxx
 * @brief:   addedge_data-------添加边信息前信息处理-------（计算结点）
 * @date:     2023/07/10
 * @param:    data1 当前数据;  ptr计算结点数组指针,个数  /name返回当前结点的string类型的结点名
 * @param:
 * @return:
*/

void addedge_data(const linkdata &data1,const endnode_node *ptr,const int nodenum,string &endnodename);


/*!
  *@author:    wuxxxxx
 * @brief:   addedge_data-------添加边信息前信息处理----（交换机）
 * @date:     2023/07/10
 * @param:    data1 当前数据;  ptr交换机结点数组指针,个数  /name返回当前结点的string类型的结点名
 * @param:
 * @return:
*/

void addedge_data1(const linkdata &data1,const switch_node *ptr,const int nodenum,string &switchnodename);


/*!
  *@author:    wuxxxxx
 * @brief:    addedge-----添加边的连接信息到图结构中
 * @date:     2023/07/6
 * @param:    g 拓扑图; 两个在此之前获取的结点的唯一区别名字(string 类型),weight边权信息
 * @param:
 * @return:
*/

void  addedge(Graph<string> &g,const string node1name,const string node2name,int weight);


/*!
  *@author:    wuxxxxx
 * @brief:     saveswitchnode_portdata-----保存交换机端口信息（交换机结点的端口连接信息）---24个端口
 * @date:     2023/07/6
 * @param:     当前的连接信息； ptr计算结点数组指针,ptr1交换计结点数组指针,name结点名，it 端口连接信息
 * @param:
 * @return:
*/

void  saveswitchnode_portdata(const linkdata &s, switch_node *ptr1,const int switchnodenum,\
                              const string nodename, const string it ,bool is_limitport);



/*!
  *@author:    wuxxxxx
 * @brief:     saveendnode_portdata-----保存计算结点端口信息（交换机结点的端口连接信息）---默认端口0
 * @date:     2023/07/11
 * @param:     当前的连接信息； ptr计算结点数组指针,ptr1交换计结点数组指针,name结点名，it 端口连接信息
 * @param:
 * @return:
 * 注：区别交换机结点的端口
*/

void saveendnode_portdata(const linkdata &s, endnode_node *ptr,const int endnodenum,\
                          const string nodename, const string it);



/*!
  *@author:    wuxxxxx
 * @brief:  svaeswitchnode_multilinkdata1-----找到multilink数据保存
 * @date:     2023/07/18
 * @param:    s当前结点的所有多连接端口连接数据，nodename当前结点名,ptr1交换计结点数组指针,
 * @param:
 * @return:
 *
*/

void svaeswitchnode_multilinkdata1(const string nodename,std::map<string,string> &s,\
                                   switch_node *ptr1,const int switchnodenum);


/*!
  *@author:    wuxxxxx
 * @brief:  extractFirstTwoDigits   提取数字字符串前两位数字
 * @date:     2023/08/11
 * @param:    data字符串数组
 * @param:
 * @return:   返回一个vector
 *
*/

std::vector<std::string> extractFirstTwoDigits(const std::vector<std::string>& data);


/*!
  *@author:    wuxxxxx
 * @brief:   findportlinkdata-----找到相应端口所有多链接链路数据如本系统：03的4路链路数据
 * @date:     2023/08/12
 * @param:    data当前结点的所有多链接数据，portname当前链接端口，如：03；04；05（hnr0-hnr3）
 * @param:
 * @return:   返回一个vector
 *
*/

std::vector<std::string> findportlinkdata( std::vector<string> & data,string portname);

/*!
  *@author:    wuxxxxx
 * @brief:  svaeswitchnode_multilinkdata2-----找到multilink数据数量保存,并初始化负载均衡类
 * @date:     2023/08/12
 * @param:    nodename当前结点名,ptr1交换计结点数组指针,
 * @param:
 * @return:   void
 *当前结点的所有多连接端口数量/多链接端口连接链路数量，
*/

void svaeswitchnode_multilinkdata2(const string nodename ,switch_node *ptr1,const int switchnodenum);


/*!
  *@author:    wuxxxxx
 * @brief:  multilink_handle-----处理每个交换结点的map数据,找到multilink数据
 * @date:     2023/07/18
 * @param:    data当前结点的所有端口连接数据，nodename当前结点名,ptr1交换计结点数组指针
 * @param:
 * @return:
 * 注：此函数同时保存结点的端口信息，以及判断多链路信息（连接到同一个节点的----multi links）
*/

void  multilink_handle(std::vector<string> &data,const string nodename,switch_node *ptr1,const int switchnodenum);

/*!
  *@author:    wuxxxxx
 * @brief:  judgment_multilinkdataform_nodemap1-----法2---判断多链接数据，数据插入完成,遍历找出多链接关系-------问题从新遍历了一次数据（额外开销）
 * @date:     2023/07/18
 * @param:     ptr1交换计结点数组指针，回调函数
 * @param:
 * @return:
 * 注：此函数同时保存结点的端口信息，以及判断多链路信息（连接到同一个节点的----multi links）
*/

void judgment_multilinkdataform_nodemap(switch_node *ptr,const int nodenum,callback1 fun);


/*!
  *@author:    wuxxxxx
 * @brief:    reverseString-----// 函数用于调转字符串头尾数据
 * @date:     2023/07/22
 * @param:     str 字符串
 * @param:
 * @return:
 * 注： 保存边信息，对于另外一头，需调转数据------确保数据的形式为中间有：“---”
 * 同时，连接关系两种类型---（2---1）------（1---1）
*/

std::string reverseString(const std::string& str);


/*!
  *@author:    wuxxxxx
 * @brief:   creatgraph_addnode-----添加所有结点边的关系到图（从获取连接关系）
 * @date:     2023/07/6
 * @param:    g 拓扑图;  ptr计算结点数组指针,ptr1交换计结点数组指针,s字符串链表
 * @param:
 * @return:
 * 注：此函数同时保存结点的端口信息，以及判断多链路信息（连接到同一个节点的----multi links）
 * 同时，连接关系两种类型---（2---1）------（1---1）
*/

void creatgraph_addedge(Graph<string> &g,endnode_node *ptr,const int endnodenum, switch_node *ptr1,\
                        int switchnodenum,std::list<std::string>& s);



/*!
  *@author:    wuxxxxx
 * @brief:    switchnode_show-----打印交换机结点信息
 * @date:     2023/07/11
 * @param:   ptr 交换机节点数组指针 ---type类型----num某个节点
 * @param:
 * @return:
 * 注：打印节点信息---默认打印0号节点----1打印全部节点（不要随便打印全部）---
 * type----0------打印开头元素的数据
 * type----1 ----打印全部元素的数据
 * type----2-----打印具体的元素的数据
*/

void  switchnode_show(const switch_node *ptr,int switchnodenum,int type=0,int num=0);


/*!
  *@author:    wuxxxxx
 * @brief:    switchnode_multilinkshow-----打印交换机结点多链路信息--（NRM20p）
 * @date:     2023/07/12
 * @param:   ptr 交换机节点数组指针 ---type类型----num某个节点
 * @param:
 * @return:
 * 注：打印节点信息---默认打印0号节点----1打印全部节点（不要随便打印全部）---
 * type----0------打印开头元素的数据
 * type----1 ----打印全部元素的数据
 * type----2-----打印具体的元素的数据
*/

void switcnode_multilinkshow (switch_node *ptr,int switchnodenum,int type=0,int num=0);

/*!
  *@author:    wuxxxxx
 * @brief:    endnode_show-----打印交换机结点信息
 * @date:     2023/07/11
 * @param:
 * @param:  ptr 交换机节点数组指针 ---type类型----num某个节点
 * @return:
 * 注：打印节点信息---默认打印0号节点----1打印全部节点（不要随便打印全部）---
 * type----0------打印开头元素的数据（0,0）
 * type----1 ----打印全部元素的数据（1,0）
 * type----2-----打印具体的元素的数据（2,x）
*/

void endnode_show(const endnode_node *ptr,const int endnodenum,int type=0,int num=0);


/*!
  *@author:    wuxxxxx
 * @brief:    dijkstra
 * 一个查找源点到某个目的结点的dijkstra最短路径算法---输出经过的路径结点和距离
 * @date:     2023/07/14
 * @param:    g表示拓扑结构，start表示某个源结点,target目的结点,dis距离
 * @param:
 * @return:返回一个vector表：保存的是从源结点到每个结点的最短路径结点
 * 注：关键代码
*/

std::vector<string> dijkstra( Graph<string>& g, const string& start, const string& target, int& dis);


/*!
  *@author:    wuxxxxx
 * @brief:    dijkstra1---扩展版本
 * 一个查找源点到某个目的结点的dijkstra最短路径算法---输出经过的路径结点和距离
 * @date:     2023/07/14
 * @param:    g表示拓扑结构，start表示某个源结点,target目的结点,dis距离
 * @param:
 * @return:返回一个vector表：保存的是源/目的在图中所有最短路径
 * 注：关键代码
*/

vector<Path> dijkstra1( Graph<string>& g, const string& start, const string& target, int& dis);


/*使用BFS查找最短路径-----------权值相同情况的求法*/

std::vector<string> bfsShortestPath( Graph<string>& graph, const string& start, const string& target);



////修改拓扑某个链路权重--实现局部负载均衡(板内：HNR0-5)/跨板都分配144问题（没均衡导致） --加权轮询法
//bool loaderbanlance_change_weight()
//{
//  return true;
//}



/*!
  *@author:    wuxxxxx
 * @brief:   loadbalance_mutilport_limithandle
 * @description 板内多个链路轮询负载均衡-----解决某个交换机节点(入-出:1---多个出口);交换机只能识别1个入端口对应一个出端口，对于轮询法不限制会出现一个入端口对应多个出口现象
 * @date:     2023/10/16
 * @param:     port_targetname 入端口-目标；mutilport_handle待处理的端口数据;data 数据记录--<入端-目标,结构体数据> target目的结点名 ；入端口
 * @param:
 * @return:  返回 string
 * 注：  当前问题解决不影响链路轮询,在同个目标使用了原来分配过的同个链路,对链路进行限制--查找原来分配使用的,使输出保持一个输出端口
*/

bool  loadbalance_mutilport_limithandle(const string &port_targetname,mutilport_handle &curr_port_data ,mutilport_handle& output,std::unordered_map  <std::string, mutilport_handle> &data,\
                                        const int inputport,const string target);



/*!
  *@author:    wuxxxxx
 * @brief:   outputswitch_pathport
 * @description 交换机路径端口输出---交换机数据---目的结点----输出--输入--当前交换机名字---在本地就换机通信的情况
 * @date:     2023/08/15
 * @param:     当前交换机数据  ； target目的结点名 ；当前交换机的输入/输出 端口
 * @param:
 * @return:
 * 注：  本地交换机通信情况
*/

string outputswitch_pathport(const switch_node &nodedata,const string target,\
                           const int output,const int outputtype,const int input,\
                             const int inputtype,int &inport,int &outport,int &targetnum1);

/*!
  *@author:    wuxxxxx
 * @brief:   outputswitch_pathport
 * @description   交换机端口输出-----------在有多个交换机端口输出的情况，如果是交换机数据是最开始情况
 * @date:     2023/08/15
 * @param:     -交换机数据---目的结点----输出--输入--当前交换机名字-- 负载平衡数据 --是否有负载标志
 * @param:
 * @return:
 * 注：  当前输出交换机端口数据为最开始的情况
*/

string outputswitch_pathport_other( switch_node &nodedata,const string target,const int output,\
                           const int output_nodetype,const int input,const int input_nodetype,\
                                  string &load,Loadbalance_data &nextnode_portdata,bool &flag,\
                                     int &inport,int &outport,int &targetnum1);


/*!
  *@author:    wuxxxxx
 * @brief:  rule_download
 * @description   交换机端口输出-----------源和目标相等的情况-直接从计算节点输出数据
 * @date:     2023/10/20
 * @param:     -star源---target目的----ptr1计算节点数据-  endnodenum 数量--map_data---下发的规则存储
 * @param:
 * @return:
 *
*/

void  rule_download(const string star,const string target,endnode_node *ptr1,const int endnodenum,\
                    std::unordered_multimap<std::string,forword_handle> & map_data);

/*!
  *@author:    wuxxxxx
 * @brief:  rule_download_localswitch
 * @description   交换机端口输出-----------本地交换机端口输出
 * @date:     2023/10/20
 * @param:    path路径信息--ptr交换机信息--swithchnodenum数量 -----target目的--temp——star源-temp_target目的-
 * @param:     节点输入类型-----节点输出类型------------map_data---下发的规则存储
 * @return:
 *
*/

void  rule_download_localswitch(const std::vector<string> &path,switch_node *ptr,int switchnodenum,const string target,\
                                const int temp_star,const int temp_target,int input_nodetype,int output_nodetype,\
                                std::unordered_multimap<std::string,forword_handle> & map_data);


/*!
  *@author:    wuxxxxx
 * @brief:  rule_download_pathstarelment
 * @description   交换机端口输出-----------路径开始的时刻
 * @date:     2023/10/20
 * @param:   ptr交换机信息--swithchnodenum数量---secondElement/threeElement当前的路径信息元素（第x个）
 * @param:        --temp——star源-temp_target目的-----temp_input/temp_output-input_nodetype/output_nodetype--前后输入/输出（int）以及类型
 * @param:         ------target目的--nextportdata 多端口下一个输入端口暂存---下一个输入端口（有）标志------map_data--下发规则保存
 * @param:     节点输入类型-----节点输出类型------------map_data---下发的规则存储
 * @return:
 *
*/

void  rule_download_pathstarelment(switch_node *ptr,int switchnodenum, const std::string& secondElement,\
                            int &temp_input, int &temp_output,int input_nodetype,int output_nodetype,const string target,\
                            Loadbalance_data &nextportdata,bool &flag_next_inputport1,\
                             std::unordered_multimap<std::string,forword_handle> & map_data);

/*!
  *@author:    wuxxxxx
 * @brief:  rule_download_tailelment
 * @description   交换机端口输出-----------路径尾部的时刻
 * @date:     2023/10/20
 * @param:   ptr交换机信息--swithchnodenum数量---firstElement/secondElement当前的路径信息元素（第x个）
 * @param:        -nextportdata1 多端口下一个输入端口暂存---flag_next_inputport2下一个输入端口（有）标志-----
 * @param:       temp_input/temp_output-input_nodetype/output_nodetype--前后输入/输出（int）以及类型
 * @param:         ------target目的--map_data--下发规则保存
 * @param:     节点输入类型-----节点输出类型------------map_data---下发的规则存储
 * @return:
 *
*/

void rule_download_tailelment(switch_node *ptr,int switchnodenum,const std::string& firstElement, const std::string& secondElement,\
                              bool &new_loadbance_pre,Loadbalance_data &nextportdata1,bool &flag_next_inputport2,\
                              int &temp_input, int &temp_output,int &input_nodetype,int &output_nodetype,const string target,\
                              std::unordered_multimap<std::string,forword_handle> & map_data);

/*!
  *@author:    wuxxxxx
 * @brief:    rulseissued_from_dijkstra
 * @description 从最短路径算法获取路径--下发规则---输出端口文件
 * @date:     2023/07/14-----------------2023/09/24--修改
 * @param:    path表示路径数据，ptr交换机数组指针
 * @param:
 * @return:
 * 注：关键代码---一般计算计算结点的最短路径----考虑负载平衡----多连接端口--考虑负载平衡---静态负载平衡-----轮询法
 * 队列接口保留
*/

void rulseissued_from_dijkstra(const std::vector<string> path,switch_node *ptr,int switchnodenum,endnode_node *ptr1,int endnodenu,\
                              const string star,const string target,\
                              std::unordered_multimap<std::string,forword_handle> &
                               /* moodycamel::ConcurrentQueue<forword_rule> &rulequeue*/);

//测试打印版本

void rulseissued_from_dijkstra(const std::vector<string> path,switch_node *ptr,int switchnodenum,endnode_node *ptr1,int endnodenum,\
                               const string star,const string target,moodycamel::ConcurrentQueue<string> &queue);


/*!
  *@author:    wuxxxxx
 * @brief:    showpath_dijkstra
 * desription:  显示源点到某个目的结点的最短路径---输出经过的路径结点和距离
 * @date:     2023/07/14
 * @param:    vector表示路径数据，distance距离
 * @param:
 * @return:
*/

string  showpath_dijkstra (const std::vector<string> path,const int distance);


/*!
  *@author:    wuxxxxx
 * @brief:   calculates_and_save_allendnode_shortpath
 * desription:  计算转发规则写入文件---文件保存每个交换机的路由数据-----每个交换机一个文件---写入所有源/目的结点对的最短路径
 *              求所有计算节点到除了本身之外的计算节点的最短路径,并保存下信息
 * @date:     2023/09/18----------2023/09/24---修改
 * @param:   endnodenum计算节点数量-g拓扑结构-ptr交换机信息存储指针-saverule_conqueue转发规则队列-filedtaream哈希表记录文件
 * @param:
 * @return: ture/false
*/

bool  calculates_and_save_allendnode_shortpath(int n, Graph<string> &g,switch_node *ptr,int switchnodenum,endnode_node *ptr1,int endnodenum,\
                                              moodycamel::ConcurrentQueue<forword> &saverule_conqueque\
                                     ,std::unordered_map<std::string, std::ofstream> &fileStreams,\
                                               std::unordered_multimap<std::string,forword_handle> &);


#endif // ROUTE_MINHOP_H
