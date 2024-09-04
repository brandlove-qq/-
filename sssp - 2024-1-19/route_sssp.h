#ifndef ROUTE_SSSP_H
#define ROUTE_SSSP_H

#include "common.h"
#include "concurrentqueue.h"

/******************************************************************
 * SSSP负载均衡：每查找到一条路径，进行权值更新，这种形式负载均衡属于全局性均衡。
 * 板内的多链路均衡依然采用轮询法实现。
 * 区别minihop算法的局部负载均衡
 ******************************************************************/

/*!
  *@author:    wuxxxxx
 * @brief:    switchnode_multilinkshow-----打印交换机结点多链路信息--（NRM20p）
 * @date:     2023/07/12
 * @param:   ptr 交换机节点map ---type类型----num某个节点
 * @param:
 * @return:
 * 注：打印节点信息---默认打印0号节点----1打印全部节点（不要随便打印全部）---
 * type----0------打印开头元素的数据
 * type----1 ----打印全部元素的数据
 * type----2-----打印具体的元素的数据
*/

void switcnode_multilinkshow (std::unordered_map<std::string,switch_node> &ptr,int switchnodenum,int type=0,int num=0);

/*!
  *@author:    wuxxxxx
 * @brief:    test_show_sssp_allshortespaths  打印所有路径信息
 * @date:     2024/1/1
 * @param:     shortesetpaths 所有路径信息 ，某个源节点
 * @param:
 * @return:
 *
*/

void  test_show_sssp_allshortespaths(std::unordered_map<string, std::pair<std::vector<string>, int>> & shortestPaths,std::string  source);

/*!
  *@author:    wuxxxxx
 * @brief:    test_show_switchnode_information  打印所有交换机节点信息
 * @date:     2024/1/1
 * @param:     switchnodes 所有交换机节点信息(map)
 * @param:
 * @return:
 *
*/

void test_show_switchnode_information(std::unordered_map<std::string,switch_node> & switchnodes,int type=0,int num=0);

/*!
  *@author:    wuxxxxx
 * @brief:   test_show_endnode_information  打印所有计算节点（终端）信息
 * @date:     2024/1/1
 * @param:    endnodes 所有交换机节点信息(map)
 * @param:
 * @return:
 *
*/

void test_show_endnode_information(std::unordered_map<std::string,endnode_node> & endnodes,int type=0,int num=0);

/*!
  *@author:    wuxxxxx
 * @brief:    test_show_graph    测试打印图的节点信息-对比是否--可自行修改
 * @date:     2024/1/1
 * @param:    g  有向图
 * @param:
 * @return:
 *
*/

void  test_show_graph(Graph<string>  &g);


/*!
  *@author:    xxxxx
 * @brief:    test1---------测试所有最短路径算法，调用的时候输入源结点，对建立的模板类函数的功能测试
 * @date:     2023/12/27
 * @param:    g图数据结构----source源结点 target 目的节点
 * @param:
 * @return:
 * 注：打印整个图结构所有结点的最短路径距离
*/

void test1(Graph<string>  &g,string  &source,string &target);

/*!
  *@author:    xxxxx
 * @brief:    creatgragph_endnodes----------赋值终端结点id
 * @date:     2023/12/27
 * @param:    endnodenum 结点数目; 无序map键值表
 * @param:
 * @return:
 * 注：建立拓扑时为了唯一区分节点id号，使用一个string类型的来区分
*/

void creatgragph_endnodes(const int endnodenum,std::unordered_map<std::string,endnode_node> &);


/*!
  *@author:    xxxxx
 * @brief:    creatgragph_endnodes-----赋值交换机结点id
 * @date:     2023/12/27
 * @param:    switchnodenum 结点数目; 无序map键值表
 * @param:
 * @return:
*/

void creatgraph_switchnodes(const int switchnodenum, std::unordered_map<std::string,switch_node> &);

/*!
  *@author:    xxxxx
 * @brief:    extractNumbe---提取数字转int
 * @date:     2023/12/27
 * @param:    str 字符串;num数字
 * @param:
 * @return:----------
 *注： 建立拓扑时为了唯一区分节点id号，使用一个string类型的来区分
*/

void  extractNumber_change(const std::string& str,int &num);


/*!
  *@author:    xxxxx
 * @brief:    extractFirstTwoElements-------提取字符串链表前两个元素，保存删除
 * @date:     2023/12/27
 * @param:    strings 字符串链表;  c1/c2字符串（保存）
 * @param:
 * @return:
 * 注：函数提取前两行的节点（交换/计算）总数（拓扑图数据文件）
*/

void extractFirstTwoElements(std::list<std::string>& strings,string &c1,string &c2);

/*!
  *@author:    xxxxx
 * @brief:    readfilealldata-------读取后台的拓扑文件
 * @date:     2023/12/27
 * @param:    s 字符串链表;  file 文件
 * @param:
 * @return:
*/

void  readfilealldata(std::list<std::string>& s,std::ifstream &file);

/*!
  *@author:    wuxxxxx
 * @brief:    extractNumber--------提取结点间连接关系并且保存（）
 * @date:     2023/12/27
 * @param:    str提取的数据（一个拓扑链接关系数据）;  linkdata保存数据
 * @param:
 * @return:
*/

void  extractNumber(std::vector<int> & str,linkdata &data1,linkdata &data2);

/*!
  *@author:    wuxxxxx
 * @brief:    extractNumbers ---提取字符串的数字，保存到数组（连接信息）
 * @date:     2023/12/27
 * @param:    str当前的字符串信息（一条文件信息如:2.10.0---1.2.4）
 * @param:
 * @return: 返回一个数组--切分后的数据（转化为int）
*/

std::vector<int> extractNumbers(const std::string& str);

/*!
  *@author:    wuxxxxx
 * @brief:   creatgraph_addnode-----添加所有结点到图--------------------map会--优化点
 * @date:     2023/12/28
 * @param:    g 拓扑图;  计算结点存储的map, endnodenum数量， 交换计结点存储的map, swithnodenum数量
 * @param:
 * @return:
 * 注：建立图也可以直接添加边数据形式建立
*/

void creatgraph_addvertex(Graph<string> &g,std::unordered_map<std::string,endnode_node> &,const int endnodenum,
                          std::unordered_map<std::string,switch_node> &,const int swithnodenum);

/*!
  *@author:    wuxxxxx
 * @brief:   addedge_data-------添加边信息前信息处理-------（计算结点）
 * @date:     2023/12/28
 * @param:    data1 当前数据;  map计算结点存储,个数  /name返回当前结点的string类型的结点名
 * @param:
 * @return:
*/

void addedge_data(const linkdata &data1,std::unordered_map<std::string,endnode_node> &,const int nodenum,string &endnodename);


/*!
  *@author:    wuxxxxx
 * @brief:   addedge_data-------添加边信息前信息处理----（交换机）
 * @date:     2023/12/28
 * @param:    data1 当前数据;  map交换机结点存储,nodenum个数  switchname返回当前结点的string类型的结点名
 * @param:
 * @return:
*/

void addedge_data1(const linkdata &data1, std::unordered_map<std::string,switch_node> &,const int nodenum,string &switchnodename);


/*!
  *@author:    wuxxxxx
 * @brief:    addedge-----添加边的连接信息到图结构中
 * @date:     2023/12/28
 * @param:    g 拓扑图; 两个在此之前获取的结点的唯一区别名字(string 类型),weight边权信息
 * @param:
 * @return:
*/

void  addedge(Graph<string> &g,const string node1name,const string node2name,int weight);

/*!
  *@author:    wuxxxxx
 * @brief:    reverseString-----// 函数用于调转字符串头尾数据
 * @date:     2023/12/28
 * @param:     str 字符串
 * @param:
 * @return:
 * 注： 保存边信息，对于另外一头，需调转数据------确保数据的形式为中间有：“---”
 * 同时，连接关系两种类型---（2---1）------（1---1）
*/

std::string reverseString(const std::string& str);

/*!
  *@author:    wuxxxxx
 * @brief:     saveswitchnode_portdata-----保存交换机端口信息（交换机结点的端口连接信息）---24个端口
 * @date:     2023/12/28
 * @param:     s当前的连接信息； 交换机结点map/switchnum个数,nodename当前交换机结点名，item 端口连接信息
 * @param:
 * @return:
*/

void  saveswitchnode_portdata(const linkdata &s, std::unordered_map<std::string,switch_node> &,const int switchnodenum,\
                              const string nodename, const string item ,bool is_limitport);

/*!
  *@author:    wuxxxxx
 * @brief:     saveendnode_portdata-----保存计算结点端口信息（交换机结点的端口连接信息）---默认端口0
 * @date:     2023/12/28
 * @param:     s当前的连接信息； 计算结点map/endnodenum个数 ,nodename当前结点名，item 端口连接信息
 * @param:
 * @return:
 * 注：区别交换机结点的端口
*/

void saveendnode_portdata(const linkdata &s, std::unordered_map<std::string,endnode_node> &,const int endnodenum,\
                          const string nodename, const string item);

/*!
  *@author:    wuxxxxx
 * @brief:   creatgraph_addnode-----添加所有结点边的关系到图（从获取连接关系）
 * @date:     2023/12/28
 * @param:    g 拓扑图,计算结点map,endnodenum数量，交换计结点map,switchnum数量,s字符串链表(链接信息)
 * @param:
 * @return:
 * 注：此函数同时保存结点的端口信息，以及判断多链路信息（连接到同一个节点的----multi links）
 * 同时，连接关系两种类型---（2---1）------（1---1）----------------初始化的图权值统一为1
*/

void creatgraph_addedge(Graph<string> &g,std::unordered_map<std::string,endnode_node> &,const int endnodenum, std::unordered_map<std::string,switch_node> &,\
                        int switchnodenum,std::list<std::string>& s);

/*!
  *@author:    wuxxxxx
 * @brief:                      route_sssp 全局负载均衡设计
 * @date:     2023/12/31
 * @param:
 * @param:           g有向图， path当前返回的最短路径信息
 * @return:
 *
*/

void   route_sssp_Global_load_balance_set_edge_weight_value(Graph<string> &g,std::vector<string> path);

/*!
  *@author:    wuxxxxx
 * @brief:    containsSwitch-----判断字符串是否含有（“switch”）
 * @date:     2023/12/29
 * @param:    str  当前节点的名
 * @param:
 * @return:  ture/false
 * 注：找出交换机节点
*/


bool containsSwitch(const std::string& str) ;

/*!
  *@author:    wuxxxxx
 * @brief:     route_sssp-----单源最短路径算法：计算某个计算源节点到其他的计算节点的最短路径（改进版--交换机节点不参与计算）
 * @date:     2023/12/29
 * @param:   g 图,source 源节点
 * @param:
 * @return: 返回所有最短路径
 * 注：区别交换机结点的端口
*/

std::unordered_map<string, std::pair<std::vector<string>, int>> route_sssp(Graph<string> &g,string &source);


/*!
  *@author:    wuxxxxx
 * @brief:    outputswitch_pathport    交换机路径端口输出-
 * @date:     2024/1/1
 * @param:    --ptr交换机数据(map)---目的结点----输出/输出类型--输入/输入类型---得到的入/出端口-当前交换机名字---在本地就换机通信的情况
 * @param:
 * @return:
 *
*/

string outputswitch_pathport(std::unordered_map<std::string,endnode_node> &ptr1,const string target,const int output,const int outputtype,\
                             const int input,const int inputtype,int &inport,int &outport,const string &currentelment,int &targetnum1);


/*!
  *@author:    wuxxxxx
 * @brief:     outputswitch_pathport_other
 * @description   交换机端口输出-----------在有多个交换机端口输出的情况，如果是交换机数据是最开始情况
 * @date:     2024/1/1
 * @param:     -当前交换机节点数据---目的结点----输出--输入--当前交换机名字-- 负载平衡数据 --是否有负载标志
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
 * @brief:   loadbalance_mutilport_limithandle
 * @description 板内多个链路轮询负载均衡-----解决某个交换机节点(入-出:1---多个出口);交换机只能识别1个入端口对应一个出端口，对于轮询法不限制会出现一个入端口对应多个出口现象
 * @date:     2024/1/1
 * @param:     port_targetname 入端口-目标；mutilport_handle待处理的端口数据;data 数据记录--<入端-目标,结构体数据> target目的结点名 ；入端口
 * @param:
 * @return:  返回 string
 * 注：  当前问题解决不影响链路轮询,在同个目标使用了原来分配过的同个链路,对链路进行限制--查找原来分配使用的,使输出保持一个输出端口
*/

bool  loadbalance_mutilport_limithandle(const string &port_targetname,mutilport_handle &curr_port_data ,mutilport_handle& output,std::unordered_map  <std::string, mutilport_handle> &data,\
                                        const int inputport,const string target);


/*!
  *@author:    wuxxxxx
 * @brief:    rulseissued_from_sssp_test     路由规则输出显示--测试版
 * @date:     2024/1/1
 * @param:    paths 得到的sssp的所有最短路径信息-----交换机数据（map）---计算节点数据信息（map）---当前源节点------队列
 * @param:
 * @return:
 *
*/

void  rulseissued_from_sssp_test(const std::unordered_map<string, std::pair<std::vector<string>, int>> & paths,std::unordered_map<std::string,switch_node> &,\
                                std::unordered_map<std::string,endnode_node> &, const string source, moodycamel::ConcurrentQueue<string> &queue);

/*!
  *@author:    wuxxxxx
 * @brief:   findportlinkdata-----找到相应端口所有多链接链路数据如本系统：03的4路链路数据
 * @date:     2023/12/30
 * @param:    data当前结点的所有多链接数据，portname当前链接端口，如：03；04；05（hnr0-hnr3）
 * @param:
 * @return:   返回一个vector
 *
*/

std::vector<std::string> findportlinkdata( std::vector<string> & data,string portname);


/*!
  *@author:    wuxxxxx
 * @brief:  extractFirstTwoDigits   提取数字字符串前两位数字
 * @date:     2023/12/31
 * @param:    data字符串数组
 * @param:
 * @return:   返回一个vector
 *
*/

static std::vector<std::string> extractFirstTwoDigits(const std::vector<std::string>& data);


/*!
  *@author:    wuxxxxx
 * @brief:  svaeswitchnode_multilinkdata2-----找到multilink数据数量保存,并初始化负载均衡类
 * @date:     2023/12/30
 * @param:    nodename当前结点名, 交换计结点map /数量
 * @param:
 * @return:   void
 *当前结点的所有多连接端口数量/多链接端口连接链路数量，
*/

void svaeswitchnode_multilinkdata2(const string nodename ,std::unordered_map<std::string,switch_node> &,const int switchnodenum);


/*!
  *@author:    wuxxxxx
 * @brief:  svaeswitchnode_multilinkdata1-----找到multilink数据保存
 * @date:     2023/12/31
 * @param:    s当前结点的所有多连接端口连接数据，nodename当前结点名, 交换计结点map,switchnodenum 交换机节点数量
 * @param:
 * @return:
 *
*/

void svaeswitchnode_multilinkdata1(const string nodename,std::map<string,string> &s,\
                                   std::unordered_map<std::string,switch_node> & ,const int switchnodenum);

/*!
  *@author:    wuxxxxx
 * @brief:    multilink_handle-----处理每个交换结点的map数据,找到multilink数据
 * @date:     2023/12/30
 * @param:    data当前结点的所有端口连接数据，nodename当前结点名,p 交换计结点map
 * @param:
 * @return:
 * 注：此函数同时保存结点的端口信息，以及判断多链路信息（连接到同一个节点的----multi links）
*/

void  multilink_handle(std::vector<string> &data,const string nodename,std::unordered_map<std::string,switch_node> &,const int switchnodenum);

/*!
  *@author:    wuxxxxx
 * @brief:  judgment_multilinkdataform_nodemap1-----法2---判断多链接数据，数据插入完成,遍历找出多链接关系-------问题从新遍历了一次数据（额外开销）
 * @date:     2023/12/30
 * @param:     交换计结点map， 回调函数
 * @param:
 * @return:
 * 注：此函数同时保存结点的端口信息，以及判断多链路信息（连接到同一个节点的----multi links）
*/

static void judgment_multilinkdatafrom_nodemap(std::unordered_map<std::string,switch_node> & ,const int nodenum,callback1 fun);

/*!
  *@author:    wuxxxxx
 * @brief:    rule_download
 * @description   交换机端口输出-----------源和目标相等的情况-直接从计算节点输出数据
 * @date:     2024/1/1
 * @param:     -star源---target目的----ptr1计算节点数据(map)-  endnodenum 数量--map_data---下发的规则存储
 * @param:
 * @return:
 *
*/

void  rule_download(const string star,std::unordered_map<std::string,endnode_node> &ptr1,const int endnodenum,\
                    std::unordered_multimap<std::string,forword_handle> & map_data);


/*!
  *@author:    wuxxxxx
 * @brief:  rule_download_localswitch
 * @description   交换机端口输出-----------本地交换机端口输出
 * @date:     2024/1/4
 * @param:    path路径信息--ptr交换机信息(map)--swithchnodenum数量 -----target目的--temp——star源-temp_target目的-
 * @param:     节点输入类型-----节点输出类型------------map_data---下发的规则存储
 * @return:
 *
*/

void  rule_download_localswitch(const std::vector<string> &path,std::unordered_map<std::string,switch_node> & ptr,int switchnodenum,const string target,\
                                const int temp_star,const int temp_target,int input_nodetype,int output_nodetype,\
                                std::unordered_multimap<std::string,forword_handle> & map_data);

/*!
  *@author:    wuxxxxx
 * @brief:  rule_download_tailelment
 * @description   交换机端口输出-----------路径尾部的时刻
 * @date:     2024/1/1
 * @param:   ptr交换机信息--swithchnodenum数量---firstElement/secondElement当前的路径信息元素（第x个）
 * @param:        -nextportdata1 多端口下一个输入端口暂存---flag_next_inputport2下一个输入端口（有）标志-----
 * @param:       temp_input/temp_output-input_nodetype/output_nodetype--前后输入/输出（int）以及类型
 * @param:         ------target目的--map_data--下发规则保存
 * @param:     节点输入类型-----节点输出类型------------map_data---下发的规则存储
 * @return:
 *
*/

void rule_download_tailelment(std::unordered_map<std::string,switch_node> & ptr,int switchnodenum,const std::string& firstElement, const std::string& secondElement,\
                              bool &new_loadbance_pre,Loadbalance_data &nextportdata1,bool &flag_next_inputport2,\
                              int &temp_input, int &temp_output,int &input_nodetype,int &output_nodetype,const string target,\
                              std::unordered_multimap<std::string,forword_handle> & map_data);

/*!
  *@author:    wuxxxxx
 * @brief:  rule_download_pathstarelment
 * @description   交换机端口输出-----------路径开始的时刻
 * @date:     2024/1/1
 * @param:   ptr交换机信息--swithchnodenum数量---secondElement/threeElement当前的路径信息元素（第x个）
 * @param:        --temp——star源-temp_target目的-----temp_input/temp_output-input_nodetype/output_nodetype--前后输入/输出（int）以及类型
 * @param:         ------target目的--nextportdata 多端口下一个输入端口暂存---下一个输入端口（有）标志------map_data--下发规则保存
 * @param:     节点输入类型-----节点输出类型------------map_data---下发的规则存储
 * @return:
 *
*/

void  rule_download_pathstarelment(std::unordered_map<std::string,switch_node> & ptr,int switchnodenum, const std::string& secondElement,\
                            int &temp_input, int &temp_output,int input_nodetype,int output_nodetype,const string target,\
                            Loadbalance_data &nextportdata,bool &flag_next_inputport1,\
                             std::unordered_multimap<std::string,forword_handle> & map_data);

/*!
  *@author:    wuxxxxx
 * @brief:    across_board_handle_limit
 * @description 板间一个端口对应多个输出端口的问题限制（板内多链路的出端口限制）
 * @date:     2024/1/18-----------------
 * @param:    it当前节点的数据信息，target目标节点,inputport 待输出的入端口，outputport待输出的出端口，temp_outputlinkdata临时保存的输出的链接(多链接轮询返回的)，nextportdata1下一个端口数据（区分两个变量用处位置）
 * @param:     new_loadbance_pre 有目标走了相同链路,数据使用之前分配的.标志（多链接一个入端口对多个输出端口限制）
 * @return:
 * 注：限制方式：板内的端口限制，在第一次轮询期间，一个链路4个入端口，后期肯定会有走了同一个入端口的情况；如：HNR1-HNR3-HNR0 路径 ，0-30：21：30---x1,16:30--x2,17:30---x3,13:30---x4;同个目的只能有对应4个x1-4出端口进入
 * HNR0,如果有21：30----x5出现要进行限制（采用记录数据形式，后期查找对比），使用之前21：30---x1的出端口。
 *
*/

void   board_inside_mulitport_handle_limit(switch_node&it,const string &target,int &inputport,int &outputport, const string  &temp_outputlinkdata,\
                                           Loadbalance_data &nextportdata1,bool &new_loadbance_pre);


/*!
  *@author:    wuxxxxx
 * @brief:    across_board_handle_limit
 * @description  跨板交互出现一个端口对应多个输出端口的问题限制
 * @date:     2024/1/18-----------------
 * @param:    it当前节点的数据信息，path表示路径数据，target目标节点,inputport 待输出的入端口，outputport待输出的出端口，secondElement/threeElement当前路径元素信息
 * @param:
 * @return:
 * 注：限制方式：如果该节点是多链接节点以及是需要限制的节点，以及当前的路径是属于跨板的路径；
 * 从板可以看到每个节点跨越板到达跨越的节点都是同一个节点如：3号-9号（跨越节点：144-150）；因此判断是这个类型的节点，记录消息
 * 如果有到达同一个目的的入端口对应了一个不同的出端口，重配输出端口，使用原来的到达目的的那个出端口 如hnr3：目的-入端口-出端口：33-1-7;33-4-6;33-5-10;33-9-14;
 * 假如下次出现33-1-18 ，限制（不下发）重配：33-1-18 （出端接换由18换7）
*/

void   across_board_handle_limit(switch_node &it,const std::vector<string> &path, const string &target,int &inputport,int &outputport, const std::string& secondElement,\
                                 const std::string & threeElement);

/*!
  *@author:    wuxxxxx
 * @brief:    save_forword_handle
 * @description 路由数据存储（待相同端口数据处理）
 * @date:     2024/1/18-----------------
 * @param:    it当前节点的数据信息，inputport 待输出的入端口，outputport待输出的出端口, outputdata待输出的转发规则， targetnum目的节点，  map_data--路由数据存储（待相同端口数据处理）
 * @param:
 * @return:
 *注：保存转发规则数据，一个键值对应多个值的方式，处理写入文件有相同项，保存数据如果查找到相同的不要保存；数据写入在所有数据插入完成后，在统一遍历写入:后期可以优化
*/

void   save_forword_handle(switch_node&it,const int &inputport,const int &outputport,const string & outputdata,const int &targetnum,\
                           std::unordered_multimap<std::string,forword_handle> &map_data);


/*!
  *@author:    wuxxxxx
 * @brief:    rulseissued_from_dijkstra
 * @description 从最短路径算法获取路径--下发规则---输出端口文件
 * @date:     2024/1/1-----------------
 * @param:    paths表示路径数据，ptr交换机map,     ptr1计算节点map -源-目的----路由数据存储（待相同端口数据处理）
 * @param:
 * @return:
 * 注：关键代码---一般计算计算结点的最短路径----考虑负载平衡----多连接端口--考虑负载平衡---静态负载平衡-----轮询法
 * 队列接口保留
*/


void rulseissued_from_dijkstra(const std::unordered_map<string, std::pair<std::vector<string>, int>> & paths,std::unordered_map<std::string,switch_node> &ptr,int switchnodenum,\
                               std::unordered_map<std::string,endnode_node> &ptr1,int endnodenu,\
                              const string star,const string target,\
                              std::unordered_multimap<std::string,forword_handle> &);

/*!
  *@author:    wuxxxxx
 * @brief:   calculates_and_save_allendnode_shortpath_test
 * desription:  计算转发规则写入文件---文件保存每个交换机的路由数据-----每个交换机一个文件---写入所有源/目的结点对的最短路径
 *              求所有计算节点到除了本身之外的计算节点的最短路径,并保存下信息
 * @date:     2024/01/2----------
 * @param:   endnodenum计算节点数量-g拓扑结构-ptr交换机信息存储指针-saverule_conqueue转发规则队列-switchnodenum交换机节点数量
 * @return: ture/false
*/

bool  calculates_and_save_allendnode_shortpath_test(Graph<string> &g, std::unordered_map<std::string,switch_node> &,int switchnodenum,\
                                std::unordered_map<std::string,endnode_node> &,int endnodenum ,moodycamel::ConcurrentQueue<string> &queue);


/*!
  *@author:    wuxxxxx
 * @brief:   calculates_and_save_allendnode_shortpath
 * desription:  计算转发规则写入文件---文件保存每个交换机的路由数据-----每个交换机一个文件---写入所有源/目的结点对的最短路径
 *              求所有计算节点到除了本身之外的计算节点的最短路径,并保存下信息
 * @date:     2024/01/2----------
 * @param:   endnodenum计算节点数量-g拓扑结构-ptr交换机信息存储指针-saverule_conqueue转发规则队列-filedtaream哈希表记录文件,multimap--这个时写入处理相同项
 * @param:
 * @return: ture/false
*/

bool  calculates_and_save_allendnode_shortpath(int n, Graph<string> &g,std::unordered_map<std::string,switch_node> &ptr,int switchnodenum,std::unordered_map<std::string,endnode_node> &ptr1,int endnodenum,\
                                              moodycamel::ConcurrentQueue<forword> &saverule_conqueque\
                                     ,std::unordered_map<std::string, std::ofstream> &fileStreams,\
                                               std::unordered_multimap<std::string,forword_handle> &);

#endif // ROUTE_SSSP_H
