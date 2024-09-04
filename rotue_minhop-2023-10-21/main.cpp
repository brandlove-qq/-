
#include "route_minhop.h"

/**************************************************************************************
//建立拓扑基本完成基本可以输出端口数据-------多链路信息储存完成
目前问题：
 负载平衡（轮询法）处理---多链路时候选择链路时候(输入/输出端口)--一个目标只能对应一个出（已解决）
 时间复杂度:(数组查找花销大)
 多数最短路径分到了144交换机---加权链路改进--局部均衡（板内也要HNRXX）
*************************************************************************************/

int main()
{
    //大拓扑按照文件结点编号生成---区别int编号相同方法：加string区分："switchxx","endnodexx"

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
    extractNumber(s1,endnodenum);
    extractNumber(s2,switchnum);
    //创建交换机相关结点---设置唯一区别id(string)----后期需要优化-----查找时间快的存储结构（支持后期查找修改）

    Node* switchnodes = new Node[switchnum]; // 动态分配内存空间给结构体数组
    Node* ptr = switchnodes;
    backNode* endnodes = new backNode[endnodenum]; // 动态分配内存空间给结构体数组
    backNode* ptr1 = endnodes;
    creatgraph_switchnodes(switchnum,ptr);
    //背板连接的计算结点
    creatgragph_endnodes(endnodenum,ptr1);

#if test

    //测试打印信息----打印数据列表
    //cout<<"\n";
    std::cout<<switchnum<<" endnode: "<<endnodenum;
    cout<<"\n";
    //    for (const std::string& str : strings)
    //    {
    //        std::cout << str << std::endl;
    //    }
 #endif

    //添加结点
    creatgraph_addvertex(g,ptr1,endnodenum,ptr,switchnum);
    //添加边-----(当前权值统一为1--后期权值可以从数据加入)
    creatgraph_addedge(g,ptr1,endnodenum,ptr,switchnum,strings);

#if test

    cout<<"g-num"<<g.num_vertices();
    cout<<"\n";
    //结点信息显示---测试
    cout<<"\n"<<"show data!"<<"\n";
    cout<<"switch data:";
    //switchnode_show(ptr,switchnum,2,144);
    // switchnode_show(ptr,switchnum,1);
    cout<<"\n";
    // endnode_show(ptr1,endnodenum,1);
    cout<<"\n";
    // switcnode_multilinkshow(ptr,switchnum,1);

    cout << "print tuopu vertex and adj map information as follow" << endl;
    //g.show();
    cout << endl;
#endif

#if  write
    //所有计算结点路由数据保存----每个交换机一个文件：测试完成在加
    int n=endnodenum;
    //int n= 32;
    moodycamel::ConcurrentQueue<forword_rule>    saverule_conqueque; //写入文件的测试检测接口
    // 使用一个哈希表来跟踪每个 switchname 对应的文件输出流
    std::unordered_map<std::string, std::ofstream> fileStreams;
    std::unordered_multimap<std::string,forword_handle> cache_forwardddata1;
    if(calculates_and_save_allendnode_shortpath(n,g,ptr,switchnum,ptr1,endnodenum,saverule_conqueque,fileStreams,cache_forwardddata1))
       std::cout << "data saved !!" << std::endl;

#endif

 // 单个源/目的测试--及所有计算节点打印输出
#if test

                moodycamel::ConcurrentQueue<string>    saveinformation_conqueque;
                std::string  outputinformation;
                outputinformation.clear();
                std::vector<string>  path;
                path.clear();
                int distance=0;
                string star="endnode736"; //endnode0
                string target="endnode0";
                cout<<"\n";
                //判断是否是路由到本身
                if(star==target)
                {
                    cout<<"sourece-----target:";
                    outputinformation.append("sourece-----target:");
                    cout<<star<<"-------"<<target;
                    outputinformation.append(star);
                    outputinformation.append("------");
                    outputinformation.append(target);
                    saveinformation_conqueque.enqueue(outputinformation); //
                    cout<<"\n";
                    //            string pathinfor;
                    //            pathinfor.append("path:");
                    //            pathinfor.append("-");
                    //            pathinfor.append(star);
                    //            saveinformation_conqueque.enqueue(pathinfor);
                }
                else
                {
                    path=dijkstra(g,star,target,distance);  //
                    //path=bfsShortestPath(g,star,target);
                    cout<<"sourece-----target:";
                    outputinformation.append("sourece-----target:");
                    cout<<star<<"-------"<<target;
                    outputinformation.append(star);
                    outputinformation.append("------");
                    outputinformation.append(target);
                    saveinformation_conqueque.enqueue(outputinformation); //
                    cout<<"\n";
                    string pathinfor=showpath_dijkstra(path,distance);
                    saveinformation_conqueque.enqueue(pathinfor);

                }
                cout<<"\n"<<" rule0: ";
               // cout<<"\n"<<"intput port:targetnode---outputport";
               // cout<<"\n"<<"path-port-data";
                rulseissued_from_dijkstra(path,ptr,switchnum,ptr1,endnodenum,star,target,saveinformation_conqueque);


                    //测试输出所有的计算节点下发的规则------------并写入文件

//                    int n = 32;  //----------------------计算节点数量
//                    // 打开一个文件以写入数据
//                    std::ofstream outputFile(outputfile_rule_test);

//                    if (!outputFile) {
//                        std::cerr << "无法打开文件" << std::endl;
//                        return 1;
//                    }
//                    moodycamel::ConcurrentQueue<string>    saveinformation_conqueque;
//                    for (int i = 0; i <= n; ++i)
//                    {
//                        for (int j = 0; j <= n; ++j)
//                        {

//                                std::string  outputinformation;
//                                outputinformation.clear();
//                                std::vector<string>  path;
//                                path.clear();
//                                int distance=0;
//                                string star="endnode"; //endnode
//                                star.append(std::to_string(i));
//                                string target="endnode";  //targetnode
//                                target.append(std::to_string(j));
//                                cout<<"\n";
//                                    if(star==target)
//                                    {

//                                        cout<<"sourece-----target:";
//                                        outputinformation.append("sourece-----target:");
//                                        cout<<star<<"-------"<<target;
//                                        outputinformation.append(star);
//                                        outputinformation.append("------");
//                                        outputinformation.append(target);
//                                        saveinformation_conqueque.enqueue(outputinformation); //
//                                        cout<<"\n";
//                                        //            string pathinfor;
//                                        //            pathinfor.append("path:");
//                                        //            pathinfor.append("-");
//                                        //            pathinfor.append(star);
//                                        //            saveinformation_conqueque.enqueue(pathinfor);
//                                    }
//                                    else
//                                    {
//                                        path=dijkstra(g,star,target,distance);  //
//                                        //path=bfsShortestPath(g,star,target);
//                                        cout<<"sourece-----target:";
//                                        outputinformation.append("sourece-----target:");
//                                        cout<<star<<"-------"<<target;
//                                        outputinformation.append(star);
//                                        outputinformation.append("------");
//                                        outputinformation.append(target);
//                                        saveinformation_conqueque.enqueue(outputinformation); //
//                                        cout<<"\n";
//                                        string pathinfor=showpath_dijkstra(path,distance);
//                                        saveinformation_conqueque.enqueue(pathinfor);

//                                    }

//                                    cout<<"\n"<<" rule0: ";
//                                    rulseissued_from_dijkstra(path,ptr,switchnum,ptr1,endnodenum,star,target,saveinformation_conqueque);

//                                // 从队列中依次取出数据并写入文件
////                                std::string item;
////                                while (saveinformation_conqueque.try_dequeue(item))
////                                {
////                                    outputFile << item << std::endl;
////                                }
//                                //std::cout << "(" << i << ", " << j << ") ";
//                               }
//                        }
////                    }

//                    // 关闭文件
//                    outputFile.close();



#endif

    delete[] switchnodes;
    delete [] endnodes;
    return 0;
}
