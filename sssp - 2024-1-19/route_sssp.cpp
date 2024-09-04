#include "route_sssp.h"


void switcnode_multilinkshow (std::unordered_map<std::string,switch_node> &ptr,int switchnodenum,int type,int num)
{
    cout<<"show multilink data!";
    if(type==0&&num==0)
    {
        auto it = ptr.begin();
        if (it != ptr.end())
        {
            cout<<"id:"<<it->second.id;
            cout<<"id1:"<<it->second.id1;
            // 遍历并打印 map 中的键值对---连接信息
            cout<<"\n";
            cout<<"num: "<<it->second.multilink.size();
            cout<<"\n";
            for (const auto& pair : it->second.multilink)
            {
                std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
            }
            cout<<"\n"<<"mutillink data---linkcount---portcount:";
            cout <<it->second.multilink_linknum;
            cout<<"\t"<<it->second.multilink_portnum;
            cout<<"\n"<<"blance:";

            for (const LoadBalancer &lb : it->second.p1)
            {
                std::cout <<" " <<lb.port_soure_target << std::endl;
                cout<<"---crructlink:--";
                for (const std::string& str : lb.servers_)
                {
                    std::cout << str << std::endl;
                }
            }
            cout<<"\n";

        }
        else {
            std::cout << "The unordered_map is empty." << std::endl;
        }
    }
       else if (type==1&&num==0)
       {
           for (const auto& pair : ptr)
           {
               const std::string& key = pair.first;
               const switch_node& value = pair.second;
           cout<<"id:"<<value.id;
           cout<<"id1:"<<value.id1;
           // 遍历并打印 map 中的键值对---连接信息
           cout<<"\n";
           cout<<"num: "<<value.multilink.size();
           cout<<"\n";
           for (const auto& pair : value.multilink)
           {
               std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
           }
           cout<<"\n";
           cout<<"\n"<<"mutillink data---linkcount---portcount:";
           cout <<value.multilink_linknum;
           cout<<"\t"<<value.multilink_portnum;
           cout<<"\n"<<"blance:";
   //         std::vector<LoadBalancer>& lbVector = *ptr[i].p;
           for (const LoadBalancer &lb : value.p1)
           {
              std::cout <<" " <<lb.port_soure_target << std::endl;
              cout<<"---crructlink:--";
              for (const std::string& str : lb.servers_)
              {
                 std::cout << str << std::endl;
              }
           }

           cout<<"\n";
           cout<<"\n";
          }
       }
       else if (type==2&&(num!=0&&num<=switchnodenum))
       {       //具体某个元素


//                   auto it = ptr.find("two");
//                   if (it != ptr.end())
//                   {
//                       cout<<"id:"<<it->second.id;
//                       cout<<"id1:"<<it->second.id1;
//                       // 遍历并打印 map 中的键值对---连接信息
//                       cout<<"\n";
//                       cout<<"num: "<<it->second.multilink.size();
//                       cout<<"\n";
//                       for (const auto& pair : it->second.multilink)
//                       {
//                           std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
//                       }
//                       cout<<"\n"<<"mutillink data---linkcount---portcount:";
//                       cout <<it->second.multilink_linknum;
//                       cout<<"\t"<<it->second.multilink_portnum;
//                       cout<<"\n"<<"blance:";
//                       //                std::vector<LoadBalancer>& lbVector = *ptr[i].p;
//                       for (const LoadBalancer &lb : it->second.p1)
//                       {
//                           std::cout <<" " <<lb.port_soure_target << std::endl;
//                           cout<<"---crructlink:--";
//                           for (const std::string& str : lb.servers_)
//                           {
//                               std::cout << str << std::endl;
//                           }
//                       }

//                       cout<<"\n";
//                       cout<<"\n";
//                   }
//                   else {

//                       std::cout << "Key not found." << std::endl;
//                   }

    }
    else
    {
        cout<<"type input have error,please input again!" ;
    }

}

void test_show_sssp_allshortespaths(std::unordered_map<string, std::pair<std::vector<string>, int>> & shortestPaths,std::string  source)
{
    // 输出结果
    for (const auto& entry : shortestPaths)
    {
        string destination = entry.first;
        std::vector<string> path = entry.second.first;
        int distance = entry.second.second;

        std::cout << "Shortest path from " << source << " to " << destination << ": ";
        for (const auto& node : path) {
            std::cout << node << " -> ";
        }
        std::cout << "Distance: " << distance << std::endl;
    }
 }

void test_show_switchnode_information(std::unordered_map<std::string,switch_node> & switchnodes,int type,int num)
{
    //测试输出
    //遍历并输出所有信息
    if(type==0)
    for (const auto& pair : switchnodes)
    {
        const std::string& key = pair.first;
        const switch_node& value = pair.second;

        std::cout << "Key: " << key << ", Value: "; // 输出键

        // 根据 switch_node 的具体结构输出对应的值
        std::cout << "id-"<<value.id ;//
        std::cout << "-nodetype-"<<value.nodetype ;

        std::cout<<"-linkdata:-"<<value.linkdatas.size();
         std::cout << std::endl;
        for (const auto& pair1 :value.linkdatas)
        {
            const int& key1 = pair1.first;
            const std::string& value1 = pair1.second;
            std::cout << "Key1- " << key << ", Value1: "; // 输出键
            std::cout << "port-"<<key1;//
            std::cout << "-linkdata-"<<value1;
            std::cout << std::endl;
        }

        std::cout << std::endl;
    }

}

void test_show_endnode_information(std::unordered_map<std::string,endnode_node> & endnodes,int type,int num)
{
    //测试输出
    //遍历并输出所有信息
    if(type==0)
    for (const auto& pair : endnodes)
    {
        const std::string& key = pair.first;
        const endnode_node& value = pair.second;

        std::cout << "Key: " << key << ", Value: "; // 输出键
        // 根据 switch_node 的具体结构输出对应的值
        std::cout << "-id"<<value.id ;//
        std::cout << "-nodetype-"<<value.nodetype ;//
        std::cout << "-link--"<<value.link ;//
        std::cout << std::endl;
    }
}

void  test_show_graph(Graph<string>  &g)
{
    cout<<"g-num"<<g.num_vertices();
    cout<<"\n";
    cout << "print tuopu vertex and adj map information as follow" << endl;
    g.show();
    cout << endl;

}

void test1(Graph<string>  &g,string  &source,string &target)
{
    //遍历
    auto dft = g.depth_first_rec( source );
    cout << " form 1 deep  rec: {";
    for (auto u : dft) cout << u << " ";
    cout << "}" << endl;

    vector<string> dft_itr = g.depth_first_itr(source);
    cout << " form 1 deep priori itr: {";
    for (auto u : dft_itr) cout << u << " ";
    cout << "}" << endl;

    auto bft = g.breadth_first(source);
    cout << "form  1  bfs: {";
    for (auto u : bft) cout << u << " ";
    cout << "}" << endl;


    //最短路径

    cout << " the shortest path as follows: " << endl;
    auto dis = g.dijkstra(source);
    vector<string> vertices = g.get_vertices();
    for(auto vertex: vertices)
        if (dis[vertex] >= 0)
            cout << vertex<< ": " << dis[vertex] << endl;



    //某个源-目的对-最短路径

    cout << " the shortest path as follows: " << endl;
    int dist=0;
    auto vertices1 = g.dijkstra_pair(g,source,target,dist);
    //   vector<int> vertices = g.get_vertices();
    for(auto vertex: vertices1)
        cout << vertex<< "- " ;

    cout<<"----------";
    cout<<dist;

    //int sourceNode = 1;  // SSSP实现---没有均衡情况下
    auto shortestPaths = g.sssp11(g, source);

    // 输出结果
    for (const auto& entry : shortestPaths)
    {
        string destination = entry.first;
        std::vector<string> path = entry.second.first;
        int distance = entry.second.second;

        std::cout << "Shortest path from " << source << " to " << destination << ": ";
        for (const auto& node : path) {
            std::cout << node << " -> ";
        }
        std::cout << "Distance: " << distance << std::endl;
    }
}

void  extractNumber_change(const std::string& str,int &num)
{
    std::string numberString;
    bool foundDigit = false;

    for (char c : str)
    {
        if (std::isdigit(c))
        {
            numberString += c;
            foundDigit = true;
        }
        else if (foundDigit)
        {
            break; // 如果之前已经找到数字，并且当前字符不是数字，则停止提取
        }
    }
   num= std::stoi(numberString); // 将提取到的数字字符串转换为整数并返回
}

void extractFirstTwoElements(std::list<std::string>& strings,string &c1,string &c2)
{
    if (strings.size() >= 2)
    {
        std::string element1 = strings.front(); // 获取第一个元素
        strings.pop_front(); // 删除第一个元素
        std::string element2 = strings.front(); // 获取第二个元素
        strings.pop_front(); // 删除第二个元素

        // 处理提取到的数据
        c1=element1;
        c2=element2;
        std::cout <<"fecth first num:" << element1 << std::endl;
        std::cout << "fecth second num: " << element2 << std::endl;
    }
    else
    {
        std::cout << "list have not two elemnt " << std::endl;
    }
}

void  readfilealldata(std::list<std::string>& s,std::ifstream &file)
{

    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            s.push_back(line); // 将每一行字符串添加到链表中
        }

        file.close(); // 关闭文件

//                std::cout << "fecth data: " << std::endl;
//                for (const auto& str : s) {
//                    std::cout << str << std::endl; // 打印链表中的每个字符串
//                }
    }
    else
    {
        std::cout << "open file error" << std::endl;
    }
}

void  extractNumber(std::vector<int> & str,linkdata &data1,linkdata &data2)
{
    //测试打印
    //       for (const int& num : str)
    //       {
    //        std::cout << num << " ";
    //        }
    int* ptr = str.data();
    // 获取 vector 的大小
    int size = str.size();
    //    cout<<"size---:  "<<size;
    //    cout<<"\n";

        for (int i = 0; i < size; ++i)
        {
            if(i==0)
            data1.type=ptr[i];
            else if (i==1)
            data1.serialnumber=ptr[i];
            else if (i==2)
            data1.port=ptr[i];
            else if (i==3)
                data2.type=ptr[i];
            else if (i==4)
                data2.serialnumber=ptr[i];
            else if(i==5)
                data2.port=ptr[i];
            else
            {
               cout<<"eorr data "  ;
            }
           //std::cout << ptr[i] << " ";
        }
}

std::vector<int> extractNumbers(const std::string& str)
{
    std::regex regex("\\d+"); // 匹配一个或多个数字的正则表达式
    std::smatch match;
    std::vector<int> numbers;

    auto strBegin = str.cbegin();
    auto strEnd = str.cend();

    while (std::regex_search(strBegin, strEnd, match, regex))
    {
        for (auto& m : match) {
            numbers.push_back(std::stoi(m.str())); // 将提取到的数字字符串转换为整数并添加到 vector 中
        }
        strBegin = match[0].second; // 更新搜索范围的起始位置
    }
    return numbers;
}

/*
void creatgragph_endnodes(const int endnodenum, std::unordered_map<std::string,endnode_node> &ptr)
{


        for (int i = 0; i < endnodenum; ++i)
        {
            endnode_node temp;
            temp.id1 = i ;
            string s;
            s.clear();
            s.append("endnode");
            s.append(std::to_string(i));
            temp.id=s;
            temp.is_terminalnode=true;
            temp.nodetype=2;                //后期从边连接信息进行初始化整个数据---目前保留--后期优化
            ptr.emplace(s,temp); //插入map
        }
}


void creatgraph_switchnodes(const int switchnodenum,std::unordered_map<std::string,switch_node> &ptr)
{


        for (int i = 0; i < switchnodenum; ++i)
        {
            switch_node temp;
            temp.id1 = i ;
            string s;
            s.clear();
            s.append("switchnode");
            s.append(std::to_string(i));
            temp.id=s;
            temp.is_switchnode=true;
            temp.nodetype=1;                         //后期从边连接信息进行初始化---优化
            ptr.emplace(s,temp); //插入map
        }
}

void creatgraph_addvertex(Graph<string> &g,std::unordered_map<std::string,endnode_node> &ptr,const int endnodenum,
                          std::unordered_map<std::string,switch_node> &ptr1,const int swithnodenum)
{
    //计算结点
    for (const auto& pair : ptr1)
    {
        const std::string& key = pair.first;
        //        const switch_node& value = pair.second;
        g.add_vertex(key);
    }
     //交换机结点
    for (const auto& pair : ptr)
    {
        const std::string& key = pair.first;
        //        const switch_node& value = pair.second;
        g.add_vertex(key);
    }
}
*/

void addedge_data(const linkdata &data1,std::unordered_map<std::string,endnode_node> &ptr,const int nodenum,string &endnodename)
{
    //计算结点
         endnode_node temp;
         endnodename.clear();
        if(data1.type==2)
           {
            endnodename.append("endnode");
            endnodename.append(std::to_string(data1.serialnumber));
            temp.id1=data1.serialnumber;
            temp.nodetype=data1.type;
            temp.id=endnodename;
            temp.is_terminalnode=1;
            ptr.emplace(endnodename,temp); //插入map
          }
        else
        {
              cout<<"edge have error! " ;
        }
}

void addedge_data1(const linkdata &data1, std::unordered_map<std::string,switch_node> &ptr,const int nodenum,string &switchnodename)
{
    //交换机结点
    switch_node temp;
    switchnodename.clear();
        if(data1.type==1)
           {
            switchnodename.append("switchnode");
            switchnodename.append(std::to_string(data1.serialnumber));
            temp.id1=data1.serialnumber;
            temp.nodetype=data1.type;
            temp.id=switchnodename;
            temp.is_switchnode=1;
            ptr.emplace(switchnodename,temp); //插入map
          }
        else
        {
              cout<<"edge have error! " ;
        }
}

void  addedge(Graph<string> &g,const string node1name,const string node2name,int weight)
{
  //双向
  g.add_edge(node1name, node2name, weight);
  //反向边
  g.add_edge(node2name, node1name, weight);

}

std::string reverseString(const std::string& str)
{
    size_t delimiterPos = str.find("---");
    if (delimiterPos != std::string::npos) {
        std::string part1 = str.substr(0, delimiterPos);
        std::string part2 = str.substr(delimiterPos + 3); // 跳过 "---"

        return part2 + "---" + part1;
    }
    return str;
}

void  saveswitchnode_portdata(const linkdata &s, std::unordered_map<std::string,switch_node> &ptr1,const int switchnodenum,\
                              const string nodename, const string item, bool is_limitport)
{
    if(s.type==1)
    {
        // 查找键为 "two" 的元素
        auto it = ptr1.find(nodename);

        // 检查是否找到
        if (it != ptr1.end())
        {
            // //保存端口信息
            it->second.linkdatas.emplace(s.port,item);
            //             std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
            //多链接端口负载均衡限制----用于判断是否需要限制输出端口
                   it->second.is_limitport_swit=is_limitport;

        } else {
            // 未找到的情况
            std::cout << "Key not found. the data error!" << std::endl;
        }
    }
    else
    {
        cout<<" switch data have error! ";
    }
}

void saveendnode_portdata(const linkdata &s, std::unordered_map<std::string,endnode_node> &ptr,const int endnodenum,\
                          const string nodename, const string item)
{
    if(s.type==2)
    {

        // 查找键为 "two" 的元素
        auto it = ptr.find(nodename);

        // 检查是否找到
        if (it != ptr.end())
        {
            // //保存端口信息
            it->second.link=item;
        } else {
            // 未找到的情况
            std::cout << "Key not found. the data error!" << std::endl;
        }
    }
    else
    {
        cout<<" endnode data have error !";
    }
}

std::vector<std::string> findportlinkdata( std::vector<string> & data,string portname)
{

    std::vector<string> temp;
      std::vector<int>   temp1;
      temp.clear();
      string s;
      for (size_t i=0;i<data.size();i++)
      {
          s.clear();
          temp1.clear();
          linkdata data1,data2;
          temp1=extractNumbers(data[i]);
          extractNumber(temp1,data1,data2); //数据
          s.append(std::to_string(data1.serialnumber));
          s.append(std::to_string(data2.serialnumber));
          if(s==portname)
         {
              temp.push_back(data[i].data());

          }
      }

    return  temp;

}

static std::vector<std::string> extractFirstTwoDigits(const std::vector<std::string>& data)
{
    std::vector<std::string> result;
    linkdata data1,data2;
    std::vector<int> temp;
    string s;
    for(size_t i=0;i<data.size();i++)
    {
        temp.clear();
        s.clear();
        temp=extractNumbers(data[i]);
        extractNumber(temp,data1,data2); //数据
        s.append(std::to_string(data1.serialnumber));
        s.append(std::to_string(data2.serialnumber));
        result.push_back(s);
    }
    return result;
}

void svaeswitchnode_multilinkdata2(const string nodename ,std::unordered_map<std::string,switch_node> &ptr1,const int switchnodenum)
{
    //找出多链接相应的端口链接数量/每个端口链接链路数量
       //多链路信息统计
       int  mutilport_count=0;
       int  mutillink_count=0;
       std::vector<string>  data;  //存储的链接数据
       std::vector<string> data2;

          auto it = ptr1.find(nodename);
          if (it != ptr1.end())
          {
              data.clear();
              data2.clear();
              for (const auto& pair : it->second.multilink)
              {
                  data.push_back(pair.second); //插入数据
                  data2.push_back(pair.first);
              }
              //处理数据
              std::vector<std::string> extractedDigits = extractFirstTwoDigits(data);

              //统计相关信息
              std::unordered_map<std::string, int> counts;
              for (const std::string& item : extractedDigits)
              {
                  // 记录每个数据类型的出现次数
                  counts[item]++;
              }
              //
              mutilport_count=counts.size();
              //遍历map
              int link1=0;
              std::queue<string> portdata;
              for (const auto& pair:counts)
              {
                  portdata.push(pair.first);
                  link1=pair.second;
              }
              it->second.multilink_portnum=counts.size();
              it->second.multilink_linknum=link1;   //多链接链路数
              // cout<<"..............."<<mutillink_count<<"----"<<mutilport_count;
              //开辟多链接负载均衡对象
              //  ptr1[i].loadBalancers=new LoadBalancer[mutilport_count];  //记得释放
              it->second.loadbalanceobject_size=mutilport_count;
              //调用构造函数
                            for (int x=0 ;x<mutilport_count;x++)
                            {
                                std::vector<string> temp_portlinkdata;
                                if(!(portdata.empty()))
                                {
                                    temp_portlinkdata.clear();
                                    string temp=portdata.front();
                                    portdata.pop();
                                    temp_portlinkdata=findportlinkdata(data,temp);
                                    //                    ptr1[i].loadBalancers[x]=LoadBalancer(temp_portlinkdata,temp);
                                    it->second.p1.push_back(LoadBalancer(temp_portlinkdata, temp));
                                }



                                //测试
                                //                cout<<"\n"<<"---------------creatlinkdata:";
                                //                for (const std::string& str : temp_portlinkdata)
                                //                   {
                                //                       std::cout << str << std::endl;
                                //                   }
                            }
          }
          else
          {
              std::cout << "Key not found." << std::endl;
          }
}


void svaeswitchnode_multilinkdata1(const string nodename,std::map<string,string> &s,\
                                   std::unordered_map<std::string,switch_node> &ptr1 ,const int switchnodenum)
{
       auto it = ptr1.find(nodename);

       if (it != ptr1.end())
       {
           it->second.multilink.insert(s.begin(), s.end()); //数据多的情况高效
           it->second.is_multilink=true;
       }
       else
       {
           std::cout << "Key not found." << std::endl;
       }
}

void  multilink_handle(std::vector<string> &data,const string nodename,std::unordered_map<std::string,switch_node> &ptr1,const int switchnodenum)
{

    linkdata data1,data2;
    std::vector<int> temp;
    string* ptr = data.data();
    size_t size=data.size();
    std::map<string,string> tempsave;
    string   s_key;

       int sum=0;

       for (size_t i=0;i<size;i++)
       {
           temp.clear();
           sum=1;
           temp=extractNumbers(ptr[i]);
           extractNumber(temp,data1,data2); //数据
           if(data1.type==1&&data2.type==1)
           {
               linkdata data11,data22;
               std::vector<int> temp1;
               for (size_t y=0;y<size;y++)
               {
                   temp1.clear();
                   s_key.clear();
                   tempsave.clear();
                   temp1=extractNumbers(ptr[y]);
                   extractNumber(temp1,data11,data22); //数据
                   if(data1.serialnumber==data11.serialnumber&&data2.serialnumber==data22.serialnumber&&\
                           (data1.port!=data11.port)&&(data2.port!=data22.port))
                   {  //待改进
                       sum++;
                       //                    s_key.append(std::to_string(data11.serialnumber));
                       //                    s_key.append(std::to_string(data22.serialnumber));
                       //                    s_key.append(std::to_string(data11.port));
                       //                    s_key.append(std::to_string(data22.port));
                       //                    tempsave.insert(make_pair(s_key,ptr[y]));  //有点问题(前边插入的数据不见了)

                   }
               }
               //多链接接口的数量   /链接数量sum记录（后期保存其他的接口确认下）
               //保存多连接数据

               if(sum>2)
               { //记录进来的次数---可以找到几个接口
                   s_key.clear();
                   //当前的数据
                   s_key.append(std::to_string(data1.serialnumber));
                   s_key.append(std::to_string(data2.serialnumber));
                   s_key.append(std::to_string(data1.port));
                   s_key.append(std::to_string(data2.port));
                   tempsave.insert(make_pair(s_key,ptr[i]));
                   svaeswitchnode_multilinkdata1(nodename,tempsave,ptr1,switchnodenum);
               }
           }//if
       }
       //处理多链接数据数量信息保存---初始化当前结点负载均衡数据
    svaeswitchnode_multilinkdata2(nodename,ptr1,switchnodenum);
}


static void judgment_multilinkdatafrom_nodemap(std::unordered_map<std::string,switch_node> & ptr,const int nodenum,callback1 fun)
{

    //交换机数组
        std::vector<string>  data;

        for (const auto& pair : ptr)
        {
               const std::string& key = pair.first;
               const switch_node& value = pair.second;
               data.clear();
               for (const auto& pair1 : value.linkdatas)
               {
                   //std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
                   data.push_back(pair1.second); //插入数据
               }

               fun(data,key,ptr,nodenum);
        }
}


void creatgraph_addedge(Graph<string> &g,std::unordered_map<std::string,endnode_node> &ptr,const int endnodenum, std::unordered_map<std::string,switch_node> &ptr1,\
                        int switchnodenum,std::list<std::string>& s)
{

    for (std::list<std::string>::iterator it = s.begin(); it != s.end(); ++it)
       {
             if(it->empty())
             {
                 break;
             }
            std::vector<int> data;
            data.clear(); // 清空所有元素
            string name1,name2;
            name1.clear();
            name2.clear();
            data=extractNumbers(it->data());  //获取当前字符串的转化信息（连接信息）
            linkdata data1,data2;
            extractNumber(data,data1,data2);
            //需要负载端口设置的交换机
            bool  is_limitport=false;

            //区分结点类型，添加边时
            if(data1.type==2&&data2.type==1)
            {
                  addedge_data(data1,ptr,endnodenum,name1); //计算
                  addedge_data1(data2,ptr1,switchnodenum,name2); //交换机

                //添加端口信息
                 if(data2.type==1)
                 {   //调转数据：
                     string temp;
                     temp.clear();
                     temp=reverseString(it->data());
                    saveswitchnode_portdata(data2,ptr1,switchnodenum,name2,temp,is_limitport);
                 }
                 if (data1.type==2)
                 {
                   saveendnode_portdata(data1,ptr,endnodenum,name1,it->data());
                 }
                addedge(g,name1,name2,1);  //权值为1

            }
            else if(data1.type==1&&data2.type==1)
            {
                is_limitport=true;
                addedge_data1(data1,ptr1,switchnodenum,name1);
                addedge_data1(data2,ptr1,switchnodenum,name2);
                if(data1.type==1&&data2.type==1)
                {
                    saveswitchnode_portdata(data1,ptr1,switchnodenum,name1,it->data(),is_limitport);
                   //调转数据
                    string temp;
                    temp.clear();
                    temp=reverseString(it->data());
                    saveswitchnode_portdata(data2,ptr1,switchnodenum,name2,temp,is_limitport);
                }
                //添加端口信息-------------权值为1
                addedge(g,name1,name2,1);
                //记录多端口的数据辨别--保存多端口连接数据(交换机类型
            }
            else
            {
                cout<<"file data have error! type error";
            }
            //std::cout << *it << std::endl;  //测试输出
    }

         //法2：所有端口数据处理完再遍历所有交换机结点---获取多端口信息-------尽量减少遍历数据操作---遍历数据开销过大
        judgment_multilinkdatafrom_nodemap(ptr1,switchnodenum,multilink_handle);

}

bool containsSwitch(const std::string& str)
{
    // 在字符串中查找 "switch"
    size_t found = str.find("switch");

    // 如果找到了，返回 true；否则返回 false
    return found != std::string::npos;
}


void   route_sssp_Global_load_balance_set_edge_weight_value(Graph<string> &g,std::vector<string> path)
{
      if(path.size()>=2)
        for (size_t i = 0; i < path.size() - 1; ++i)
        {
            // 获取当前索引和下一个索引的元素
            std::string first = path[i];
            std::string second = path[i + 1];

            //获取链路当前权重
            int current_weight=g.get_weight(first,second);
            current_weight+=1;
            //更改权重---负载均衡
            g.change_weight(first,second,current_weight);
            // 处理这两个元素，这里使用输出为例
//            std::cout << "first: " << first << ", second: " << second << std::endl;
        }
}


std::unordered_map<string, std::pair<std::vector<string>, int>> route_sssp(Graph<string> &g,string &source)
{
    std::unordered_map<string, std::pair<std::vector<string>, int>> shortestPaths;

    for (const auto& vertex : g.get_vertices())
    {
        if (vertex == source||(containsSwitch(vertex)))
        {
            continue;  // 跳过源节点自身和交换机节点
        }

        int distance;
        std::vector<string> path = g.dijkstra_pair(g, source, vertex, distance);
        //均衡操作---待加
        route_sssp_Global_load_balance_set_edge_weight_value(g,path);
        //原始操作下发流表-该获取所有的在统一处理
        shortestPaths[vertex] = std::make_pair(path, distance);
    }
    return shortestPaths;

}


string outputswitch_pathport(std::unordered_map<std::string,switch_node> &ptr,const string target,const int output,const int outputtype,\
                             const int input,const int inputtype,int &inport,int &outport,const string &currentelment,int &targetnum1)
{
    string  outputdata;
    outputdata.clear();

    linkdata data1,data2;
    int inputport=0,outputport=0;
    auto it = ptr.find(currentelment);
    // 检查是否找到
    if (it != ptr.end())
    {
        for (auto& pair : it->second.linkdatas)
        {
            string  temp;
            temp.clear();
            // std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
            temp.append(pair.second); //拿数据
            std::vector<int>  data;
            data.clear();
            data=extractNumbers(temp);
            extractNumber(data,data1,data2);  //处理的数据
            //查找输入端口--以及输出端口
            if(data2.serialnumber==input&&data1.serialnumber==it->second.id1&&data2.type==inputtype)
            {
                inputport=data1.port;
                inport=inputport;

            }
            if(data2.serialnumber==output&&data1.serialnumber==it->second.id1&&data2.type==outputtype)
            {
                outputport=data1.port;
                outport=outputport;
            }

        }
#if test
        //以当前交换机结点名为文件名，输出文件
        cout<<"path-port-data";
        outputdata.append(std::to_string(inputport));  //inport
        outputdata.append(":");
        outputdata.append(target); //目标结点
        outputdata.append("---------");
        outputdata.append(std::to_string(outputport));  //outport
        cout<<"\n";
        cout<<outputdata;
#endif
#if write
    outputdata.append(std::to_string(inputport));  //inport
    outputdata.append(":");
    int targetnum=0;
    extractNumber_change(target,targetnum);
    outputdata.append(std::to_string(targetnum)); //目标结点
    targetnum1=targetnum;
    outputdata.append("---");
    outputdata.append(std::to_string(outputport));  //outport
//    cout<<outputdata;
#endif
    }
    else
    {
        // 未找到的情况
        std::cout << "Key not found. the data error!" << std::endl;
    }

  return outputdata;
}



string outputswitch_pathport_other( switch_node &nodedata,const string target,const int output,\
                           const int output_nodetype,const int input,const int input_nodetype,\
                                  string &load,Loadbalance_data &nextnode_portdata,bool &flag,\
                                     int &inport,int &outport,int &targetnum1)
{

#if test
    cout<<"\n";
#endif
    string  outputdata;
    outputdata.clear();
    //
    string  temp_outputlinkdata;
    //输出端口---负载均衡判断
    if(nodedata.is_multilink)
    {
     //输出端口确认:如：1-30：“13”
       string outputlinknum;
       outputlinknum.clear();
       temp_outputlinkdata.clear();
       outputlinknum.append(std::to_string(nodedata.id1));
       outputlinknum.append(std::to_string(output));
      //找到该输出端口-输出选择的链接
       for ( LoadBalancer &lb : nodedata.p1)
       {
           if(lb.port_soure_target==outputlinknum)
           {
               flag=1;
               temp_outputlinkdata=lb.getNextServer();

           }
       }
#if test
       //测试
       cout<<"\n"<<"loadbalance: "<<temp_outputlinkdata;
#endif
       load=temp_outputlinkdata;
    }

    linkdata data1,data2;
    int inputport=0,outputport=0;
     bool data1_f=0,data2_f=0;
    for (auto& pair : nodedata.linkdatas)
    {
        string  temp;
        temp.clear();

        // std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
        temp.append(pair.second); //拿数据
        std::vector<int>  data;
        data.clear();
        data=extractNumbers(temp);
        extractNumber(data,data1,data2);  //处理的数据
        //查找输入端口--以及输出端口
        if(data2.type==input_nodetype&&data2.serialnumber==input&&data1.serialnumber==nodedata.id1)
        {
            inputport=data1.port;
            data1_f=1;
        }

        //输出需要判断多链接
         //输出端口
        if(nodedata.is_multilink)
        {
            data2_f=1;
            std::vector<int>  tempdata;
            linkdata data3,data4;
            tempdata.clear();
            tempdata=extractNumbers(temp_outputlinkdata);
            extractNumber(tempdata,data3,data4);  //处理的数据
             if(data3.serialnumber==nodedata.id1&&data4.serialnumber==output&&data4.type==output_nodetype)
             {
                 outputport=data3.port;
                 nextnode_portdata.nextnode_inputport=data4.port;
                 nextnode_portdata.currctnode_name=nodedata.id;
             }

        }
        else
        {
            if(data1.serialnumber==nodedata.id1&&data2.serialnumber==output&&data2.type==output_nodetype)
            {
                outputport=data1.port;
                data2_f=1;
            }
        }

        if(data1_f&&data2_f)
        {
            data1_f=0;
            data2_f=0;
            break;
        }

    }
    //以当前交换机结点名为文件名，输出文件
#if test
    //cout<<"path-port-data";
    outputdata.append(std::to_string(inputport));  //inport
    outputdata.append(":");
    outputdata.append(target); //目标结点
    outputdata.append("---------");
    outputdata.append(std::to_string(outputport));  //outport
    cout<<"\n";
    cout<<outputdata;
#endif

#if write
    outputdata.append(std::to_string(inputport));  //inport
    inport=inputport;
    outputdata.append(":");
    int targetnum=0;
    extractNumber_change(target,targetnum);
    outputdata.append(std::to_string(targetnum)); //目标结点
    targetnum1=targetnum;
    outputdata.append("---");
    outputdata.append(std::to_string(outputport));  //outport
    outport=outputport;
  #endif
    return outputdata;
}


bool  loadbalance_mutilport_limithandle(const string &port_targetname,mutilport_handle &curr_port_data ,mutilport_handle& output,std::unordered_map  <std::string, mutilport_handle> &data,\
                                        const int inputport,const string target)

{
    if(!data.empty())
    {
        //查找当前是否有已经分配过的链路数据(如果在某个目标走了相同的某条链路)
        auto it = data.find(port_targetname);
        //bool similardata_flag=false;
        if (it != data.end())
        { //找到
            output=it->second;
#if test
            //测试
            std::cout << "Found " << it->first << " " << it->second.previous_outport_link    << '\n';
#endif
            return true;
        }
        else
        { //没有该数据,插入记录
            data.emplace(port_targetname,curr_port_data);
        }
    }
    else
    { //空-直接记录
        data.emplace(port_targetname,curr_port_data);
        return false;
    }
    return false;
}

#if  test
void  rulseissued_from_sssp_test(const std::unordered_map<string, std::pair<std::vector<string>, int>> & shortestPaths,std::unordered_map<std::string,switch_node> &ptr,\
                                std::unordered_map<std::string,endnode_node> &ptr1,const string source ,moodycamel::ConcurrentQueue<string> &queue)
{

        if(!source.empty())
        {//节点自身的规则下发
            string outputdata;
            outputdata.clear();
            int inputport=0;
            int outputport=0;
            //查找端口
             string  target;
             target.clear();
            auto it = ptr1.find(source);
            if (it != ptr1.end())
            {
                linkdata data1,data2;
                string  temp;
                temp.clear();
                target=it->second.id;
                temp.append( it->second.link); //拿数据
                std::vector<int>  data;
                data.clear();
                data=extractNumbers(temp);
                extractNumber(data,data1,data2);  //处理的数据
                inputport=data2.port;
                outputport=data2.port;
            }
            else
            {
                // 未找到的情况
                std::cout << "Key not found. the data error!" << std::endl;
            }

            outputdata.append(std::to_string(inputport));  //inport
            outputdata.append(":");
            outputdata.append(target); //目标结点
            outputdata.append("---------");
            outputdata.append(std::to_string(outputport));  //outport
            cout<<"\n";
            cout<<outputdata;
            queue.enqueue(outputdata);
        }


    //其他情况
    for (const auto& entry : shortestPaths)
    {
        string target = entry.first;
        std::vector<string> path = entry.second.first;

        if(path.empty())
        {
            cout<<"dijkstra have not compute data!";
        }
        //承接源--目的--转为int
        int temp_star=0;  //源
        int temp_target=0; //目的
        extractNumber_change(source,temp_star);
        extractNumber_change(target,temp_target);
        int temp_output=0,temp_input=0;
        int input_nodetype=0,output_nodetype=0; //输入/输出结点类型---后期从数据判断
        if(path.size()==3)
        { //本地通信情况
            for (size_t i = 0; i < path.size() - 1; i += 1)
            {
                if(i==1)
                {
                    //数据处理，输出端口文件
                    input_nodetype=2;
                    output_nodetype=2;
                    int inport=0,outport=0;
                    string information=outputswitch_pathport(ptr,target,temp_target,output_nodetype,temp_star,input_nodetype,inport,outport,path[i]);
                    queue.enqueue(information);
                }
            }
        }
       else
        {   //多个交换机情况------多连接下端口下发还有问题---负载均衡
            Loadbalance_data  nextportdata,nextportdata1;        //下一个端口数据（区分两个变量用处位置）
            bool flag_next_inputport1=0,flag_next_inputport2=0;
            bool    new_loadbance_pre=false;  //有目标走了相同链路,数据使用之前分配的.标志
            for (size_t i = 0; i < path.size() - 2; i += 1)
            {
                const std::string& firstElement = path[i];
                const std::string& secondElement = path[i + 1];
                const std::string & threeElement  = path[i+2] ;
                //是否到数据尾
                if(firstElement.compare(path.back())==0)
                {
                    break;
                }
                if((secondElement.compare(path.back())==0)||(threeElement.compare(path.back())==0))
                {//是
                    //               temp_output=0;
                    temp_input=0;
                    //               input_nodetype=0;
                    //               output_nodetype=0;
                    extractNumber_change(firstElement,temp_input);
                    temp_output=temp_target;
                    input_nodetype=1; //后期优化
                    output_nodetype=2;

                    auto it = ptr.find(secondElement);

                    if (it != ptr.end())
                    {
                        string  outputdata;
                        outputdata.clear();
                        linkdata data1,data2;
                        int inputport=0,outputport=0;
                        bool data1_f=0,data2_f=0;
                        bool flag_w=0;   //如果多链接情况，不希望进入不是多链接的条件下
                        for (auto& pair : it->second.linkdatas)
                        {
                            string  temp;
                            temp.clear();

                            // std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
                            temp.append(pair.second); //拿数据
                            std::vector<int>  data;
                            data.clear();
                            data=extractNumbers(temp);
                            extractNumber(data,data1,data2);  //处理的数据
                            //查找输入端口--以及输出端口
                            //输入端口需要确认一下多链接____________________________________

                            if( new_loadbance_pre)    //多链路负载均衡限制的路径，到了与终端链接的交换机节点输出数据
                            { //上一次链路平衡分配了入端口---这个是多链路限制行为的
                                new_loadbance_pre=0;

                                if(nextportdata1.currctnode_name==firstElement)
                                {
                                    inputport=nextportdata1.nextnode_inputport;
                                    ///cout <<" ------in"<<inputport;
                                    flag_w=1;
                                    data1_f=1;
                                }
                            }

                            // cout <<" flag_next_inputport2 "<<flag_next_inputport2;
                            if( flag_next_inputport2)
                            { //上一次链路平衡分配了入端口
                                flag_next_inputport2=0;

                                if(nextportdata1.currctnode_name==firstElement)
                                {
                                    inputport=nextportdata1.nextnode_inputport;
                                    /// cout <<" ------in"<<inputport;
                                    flag_w=1;
                                    data1_f=1;
                                }
                            }

                            if((!flag_w)&&((!flag_next_inputport2)||(!new_loadbance_pre)))
                            { //循环找端口不希望再次进入;入端口以及分配过了.

                                if(data2.type==input_nodetype&&data2.serialnumber==temp_input&&data1.serialnumber==it->second.id1)
                                {
                                    inputport=data1.port;
                                    //  cout <<" ------in"<<inputport;
                                    data1_f=1;
                                }
                            }

                            if(data2.serialnumber==temp_output&&data1.serialnumber==it->second.id1&&data2.type==output_nodetype)
                            { //链接了终端节点的交换机输出最后一个输出端口----对应计算节点的端口
                                outputport=data1.port;
                                data2_f=1;
                            }
                            if(data1_f&&data2_f)
                            {  data1_f=0;data2_f=0;
                                break;
                            }

                        }
                        //以当前交换机结点名为文件名，输出文件
                        //cout<<"path-port-data";
                        flag_w=0;
                        outputdata.append(std::to_string(inputport));  //inport
                        outputdata.append(":");
                        outputdata.append(target); //目标结点
                        outputdata.append("---------");
                        outputdata.append(std::to_string(outputport));  //outport
                        cout<<"\n";
                        cout<<outputdata;
                        queue.enqueue(outputdata);

                        //                           std::cout << "First element: Key = " << it->first << ", Value = " << it->second << std::endl;
                    } else {
                        std::cout << "The unordered_map is empty." << std::endl;
                    }
                }
                else
                {
                    //需要加入判断多链接的情况
                    temp_output=0;
                    temp_input=0;
                    //               output_nodetype=0;
                    //               input_nodetype=0;
                    if(i<1)
                    {  //计算结点和交换机结点情况
                        temp_input=temp_star;
                        extractNumber_change(threeElement,temp_output);
                        input_nodetype=2;
                        output_nodetype=1;
                        auto it = ptr.find(secondElement);

                        if (it != ptr.end())
                        {
                            //是否多链接确认--负载均衡  //端口输出处理---不需要判断多链接--（计算结点和当前交换机结点没有多链接关系）



                            string  loardinformation;
                            loardinformation.clear();
                            int inport=0,outport=0,targetnum=0;
                            string information=outputswitch_pathport_other(it->second,target,temp_output,output_nodetype,temp_input,\
                                                                           input_nodetype,loardinformation,nextportdata,flag_next_inputport1,inport,outport,targetnum);

                            //                            if(flag_next_inputport1)
                            //                            {   string  temp;
                            //                                temp.clear();
                            //                                 temp.append("loadbalance: ");
                            //                                temp.append(loardinformation);
                            //                                queue.enqueue(temp);
                            //                            }
                            queue.enqueue(information);

                        }
                        else {
                            std::cout << "Key not found." << std::endl;
                        }
                    }
                    else
                    {
                        //中间部分拿端口
                        extractNumber_change(firstElement,temp_input);
                        extractNumber_change(threeElement,temp_output);
                        input_nodetype=1;  //后期改用数据赋值
                        output_nodetype=1;



                                        //是否多链接确认--负载均衡  //端口输出处理------当前的结点和下一个结点--是否属于多链接结点
                                        string  outputdata;
                                        outputdata.clear();
                                        linkdata data1,data2;
                                        int inputport=0,outputport=0;
                                        bool data1_f=0,data2_f=0;  //找到数据相应标志
                                        bool  mutil1_f=0,mutil2_f=0;
                                        string  temp_outputlinkdata;
                                        //int       nextnode_input;
                                       // Loadbalance_data  nextportdata;

                                        //输出端口---负载均衡判断

                                        auto it = ptr.find(secondElement);


                                          if (it != ptr.end())
                                          {
                                              if(it->second.is_multilink)
                                              {
                                                  //输出端口确认:如：1-30：“13”

                                                  string outputlinknum;
                                                  outputlinknum.clear();
                                                  temp_outputlinkdata.clear();
                                                  outputlinknum.append(std::to_string(it->second.id1));
                                                  outputlinknum.append(std::to_string(temp_output));
                                                  //找到该输出端口-输出选择的链接
                                                  for ( LoadBalancer &lb : it->second.p1)
                                                  {
                                                      if(lb.port_soure_target==outputlinknum)
                                                      {
                                                          //   temp_outputlinkdata=ptr[x].loadBalancers[i].getNextServer();
                                                          //   temp_outputlinkdata=ptr[x].p[i].getNextServer();
                                                          temp_outputlinkdata=lb.getNextServer();
                                                      }
                                                  }

                                                  //测试
                                                  cout<<"\n"<<"loadbalance: "<<temp_outputlinkdata;
                                                  //                              if(!temp_outputlinkdata.empty())
                                                  //                              {
                                                  //                                  string temp;
                                                  //                                  temp.clear();
                                                  //                               cout<<"\n"<<"loadbalance: "<<temp_outputlinkdata;
                                                  //                               temp.append("loadbalance: ");
                                                  //                               temp.append(temp_outputlinkdata);
                                                  //                               queue.enqueue(temp);
                                                  //                              }
                                              } //if

                                              //遍历找端口
                                              bool flag_havedinputport=0,flag_havedinputport_used=0;   //找到端口，不希望进入其他条件标志
                                              bool flag_havedoutputport=0;
                                              for (auto& pair : it->second.linkdatas)
                                              {
                                                  string  temp;
                                                  temp.clear();

                                                  // std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
                                                  temp.append(pair.second); //拿数据
                                                  std::vector<int>  data;
                                                  data.clear();
                                                  data=extractNumbers(temp);
                                                  extractNumber(data,data1,data2);  //处理的数据

                                                  //查找输入端口--以及输出端口

                                                  if(mutil1_f&&mutil2_f)
                                                  {
                                                      mutil1_f=0;mutil2_f=0;
                                                      break;
                                                  }
                                                  if(mutil1_f&&data2_f)
                                                  {
                                                      mutil1_f=0;
                                                      data2_f=0;
                                                      break;

                                                  }
                                                  if(data1_f&&mutil2_f)
                                                  {
                                                      data1_f=0;
                                                      mutil2_f=0;
                                                      break;
                                                  }

                                                  if(data1_f&&data2_f)
                                                  {  data1_f=0;data2_f=0;
                                                      break;
                                                  }
                                                  //输入端口
                                                  bool flag_111=0;  //进入之后的标志，找过程不希望在进入
                                                  if((!mutil1_f)&&(flag_next_inputport1||flag_next_inputport2))
                                                  {   //多链接
                                                        //cout<<" ------------inin2";
                                                      if(flag_next_inputport1)
                                                      {  //在有终端节点情况下的交换机有多个链路情况
                                                          flag_next_inputport1=0;
                                                          if(nextportdata.currctnode_name==firstElement)
                                                          {
                                                              inputport=nextportdata.nextnode_inputport;
                                                              flag_havedinputport=1;
                                                              mutil1_f=1;
                                                              //记录输入端口信息
                                                          }
                                                          flag_111=1;
                                                      }

                                                      if((!flag_111)&&flag_next_inputport2)
                                                      {   //链路平衡已经给了输入端口---------有(也就是中间部分遇到多链接节点)
                                                          //如：sw:1-4-151-10-7 (0-32) 会进来导致到尾数据出错----在加一个标志使用情况
                                                           flag_next_inputport2=0;
                                                          if(nextportdata1.currctnode_name==firstElement)
                                                          {
                                                              inputport=nextportdata1.nextnode_inputport;
                                                              flag_havedinputport=1;
                                                              flag_havedinputport_used=true;
                                                              mutil1_f=1;
                                                          }
                                                      }

                                                      //cout<<" ------------inin1";--------------------------
                                                     if(!flag_havedinputport)  //已经在多链接获得端口--不希望遍历在此进入此判断
                                                     if(data2.type==input_nodetype&&data2.serialnumber==temp_input&&data1.serialnumber==it->second.id1)
                                                     {
                                                         inputport=data1.port;
                                                        // cout<<" ------------inin1"<<inputport;
                                                         data1_f=1;
                                                     }

                                                  }
                                                   else
                                                  {  //其他情况
                                                       //cout<<" ------------inin1";
                                                      if(!flag_havedinputport)  //已经在多链接获得端口--不希望遍历在此进入此判断
                                                      if(data2.type==input_nodetype&&data2.serialnumber==temp_input&&data1.serialnumber==it->second.id1)
                                                      {
                                                          inputport=data1.port;
                                                         // cout<<" ------------inin1"<<inputport;
                                                          data1_f=1;
                                                      }
                                                  }

                                                   //输出端口
                                                  if((!mutil2_f)&&it->second.is_multilink&&(!temp_outputlinkdata.empty()))
                                                    { //多链接
                                                      std::vector<int>  tempdata;
                                                      linkdata data3,data4;
                                                      tempdata.clear();
                                                      tempdata=extractNumbers(temp_outputlinkdata);
                                                      extractNumber(tempdata,data3,data4);  //处理的数据
                                                       if(data3.serialnumber==it->second.id1&&data4.serialnumber==temp_output&&data4.type==output_nodetype)
                                                       {
                                                         mutil2_f=1;
                                                         flag_havedoutputport=1;
                                                         outputport=data3.port;
                                                         nextportdata1.nextnode_inputport=data4.port;  //下一个输入端口缓存
                                                         nextportdata1.currctnode_name=it->second.id;
                                                         flag_next_inputport2=1;
                                                       }
                                                  }
                                                  else
                                                  {
                                                      if(!flag_havedoutputport)
                                                      if(data2.serialnumber==temp_output&&data1.serialnumber==it->second.id1&&data2.type==output_nodetype)
                                                      {
                                                          outputport=data1.port;
                                                          data2_f=1;
                                                      }
                                                  }

                                              } //for

                                              //下一个端口是否有使用过了-这个情况参考
                                              if(!flag_havedinputport_used)
                                              {
                                                  flag_havedinputport_used=0;
                                                  flag_next_inputport2=true;
                                              }

                                              //记录信息---当前输入端口--对应的输出端口信息---提供负载限制使用以及判断处理----改变本次均衡的输出规则---解决一对多个出口问题
                                               string  linkdata_new;  //保存返回的上一次分配的链路
                                              if(it->second.is_multilink&&it->second.is_limitport_swit)
                                               {
                                                 string  port_targetanme;
                                                 port_targetanme.clear();
                                                 port_targetanme.append(std::to_string(inputport));
                                                 port_targetanme.append("-");
                                                 port_targetanme.append(target);
                                                 mulitport_handle_limit  tempdata,output_data ;
                                                 tempdata.inport=inputport;
                                                 tempdata.switchname=it->second.id;
                                                 tempdata.targename=target;
                                                 //如某路径：sw：1-4-151-10-7 ：4 的输出没有多链接了，只有一个端口到151，直接输出端口，不需要记录
                                                   bool flag=false;
                                                   if(!temp_outputlinkdata.empty())
                                                   {   tempdata.previous_outport_link=temp_outputlinkdata;
                                                       //数据记录or数据对比(当前数据--决策输出规则)
                                                       flag=loadbalance_mutilport_limithandle(port_targetanme,tempdata,output_data,it->second.getnextserver_record,inputport,target);
                                                       cout<<" flag"<<flag;
                                                   }
                                                  if(flag)
                                                  {  //是否有记录过这个链路的行走路径---有使用以前分配的
                                                      cout<<"new data:"<< output_data.previous_outport_link;
                                                      if(output_data.inport==inputport&&output_data.targename==target)
                                                     {
                                                      new_loadbance_pre=true;
                                                      linkdata_new=output_data.previous_outport_link;
                                                      cout<<"\n"<<"loadbalance----new_pre: "<<linkdata_new;
                                                      //重配_输出端口
                                                      std::vector<int>  newtempdata;
                                                      linkdata data3,data4;
                                                      newtempdata.clear();
                                                      newtempdata=extractNumbers(linkdata_new);
                                                      extractNumber(newtempdata,data3,data4);  //处理的数据
                                                      //输出
                                                      outputport=data3.port;
                                                       //下一个
                                                      nextportdata1.nextnode_inputport=data4.port;  //下一个输入端口缓存
                                                      nextportdata1.currctnode_name=it->second.id;

                                                     }
                                                 }
                                               }

                                              //以当前交换机结点名为文件名，输出文件

                                              flag_havedinputport=0;
                                              flag_havedoutputport=0;
                                              outputdata.append(std::to_string(inputport));  //inport
                                              outputdata.append(":");
                                              outputdata.append(target); //目标结点
                                              outputdata.append("---------");
                                              outputdata.append(std::to_string(outputport));  //outport
                                              cout<<"\n";
                                              cout<<outputdata;
                                              queue.enqueue(outputdata);

                                          }
                                          else {

                                              std::cout << "Key not found." << std::endl;
                                          }
                    }
                }
            }
        }

   }

}

#endif

void  rule_download(const string star,std::unordered_map<std::string,endnode_node> &ptr1,const int endnodenum,\
                    std::unordered_multimap<std::string,forword_handle> & map_data)
{
    string outputdata;
       outputdata.clear();
       int inputport=0;
       int outputport=0;
       string tempswitchname;
       tempswitchname.clear();
       //查找端口
       auto it = ptr1.find(star);
       if (it != ptr1.end())
       {
           linkdata data1,data2;
           string  temp;
           temp.clear();
           // std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
           temp.append(it->second.link); //拿数据
           std::vector<int>  data;
           data.clear();
           data=extractNumbers(temp);
           extractNumber(data,data1,data2);  //处理的数据
           inputport=data2.port;
           outputport=data2.port;
           tempswitchname.append("switchnode");
           tempswitchname.append(std::to_string(data2.serialnumber));
       }
       else
       {
           // 未找到的情况
           std::cout << "Key not found. the data error!" << std::endl;
       }


       //forword_rule item;
       forword_handle  item;
       outputdata.append(std::to_string(inputport));  //inport
       outputdata.append(":");
       int targetnum=0;
       extractNumber_change(star,targetnum);
       outputdata.append(std::to_string(targetnum)); //目标结点
       outputdata.append("---");
       outputdata.append(std::to_string(outputport));  //outport
       item.inputport=inputport;
       item.outputport=outputport;
       item.outputdata=outputdata;
       item.target=targetnum;
       if(map_data.empty())
           map_data.emplace(tempswitchname,item);
       else
       {

           auto it = map_data.find(tempswitchname);
           bool similardata_flag=false;
           if (it != map_data.end())
           {
               auto range = map_data.equal_range(tempswitchname); // 查找键1
               for (auto it1 = range.first; it1 != range.second; ++it1)
               {

                   auto item1=it1->second;
                   if((item1.inputport==inputport)&&(item1.outputport==outputport)&&(item1.target==targetnum))
                   {
                       similardata_flag=true;
                       item1.sum++;
                       break;
                   }
               }

               if(similardata_flag)
                   similardata_flag=false;
               else
               {
                   map_data.emplace(tempswitchname,item);
               }
           }
           else
           {
               map_data.emplace(tempswitchname,item);
           }

           //保留
           //item.forword_rule=outputdata;
           //item.switchname=tempswitchname;
           //rulequeue.enqueue(item);
       }


}


void  rule_download_localswitch(const std::vector<string> &path,std::unordered_map<std::string,switch_node> & ptr,int switchnodenum,const string target,\
                                const int temp_star,const int temp_target,int input_nodetype,int output_nodetype,\
                                std::unordered_multimap<std::string,forword_handle> & map_data)
{

    for (size_t i = 0; i < path.size() - 1; i += 1)
       {
           if(i==1)
           {
               auto it = ptr.find(path[i]);


                 if (it != ptr.end())
                 {
                     //数据处理，输出端口文件
                     input_nodetype=2;
                     output_nodetype=2;
                     int inputport=0,outputport=0,targetnum=0;
//                     string information=outputswitch_pathport(ptr,target,temp_target,output_nodetype,temp_star,input_nodetype,inputport,outputport,targetnum);
                     string information=outputswitch_pathport(ptr,target,temp_target,output_nodetype,temp_star,input_nodetype,inputport,outputport,path[i],targetnum);
                     //forword_rule item;
                     //item.switchname=ptr[x].id;
                     //item.forword_rule=information;
                     //rulequeue.enqueue(item);
                     forword_handle  item;
                     item.inputport=inputport;
                     item.outputport=outputport;
                     item.outputdata=information;
                     item.target=targetnum;

                     if(map_data.empty())
                        map_data.emplace(it->second.id,item);
                      else
                      {
                         auto it3 = map_data.find(it->second.id);
                         bool similardata_flag=false;
                         if (it3 != map_data.end())
                         {
                             auto range = map_data.equal_range(it->second.id); // 查找键1
                             for (auto it1 = range.first; it1 != range.second; ++it1)
                             {

                                 auto item1=it1->second;
                                 if(item1.inputport==inputport&&item1.outputport==outputport&&item1.target==targetnum)
                                 {
                                     similardata_flag=true;
                                     item1.sum++;
                                     break;
                                 }
                             }
                             if(similardata_flag)
                                 similardata_flag=false;
                             else
                             {
                                map_data.emplace(it->second.id,item);
                             }

                         }
                         else
                         {
                             map_data.emplace(it->second.id,item);
                         }
                     }
                 }
                 else {

                     std::cout << "Key not found." << std::endl;
                 }

           }
       }
}


void rule_download_tailelment(std::unordered_map<std::string,switch_node> & ptr,int switchnodenum,const std::string& firstElement, const std::string& secondElement,\
                              bool &new_loadbance_pre,Loadbalance_data &nextportdata1,bool &flag_next_inputport2,\
                              int &temp_input, int &temp_output,int &input_nodetype,int &output_nodetype,const string target,\
                              std::unordered_multimap<std::string,forword_handle> & map_data)
{
    auto it = ptr.find(secondElement);

    if (it != ptr.end())
    {
        string  outputdata;
        outputdata.clear();
        linkdata data1,data2;
        int inputport=0,outputport=0;
        bool data1_f=0,data2_f=0;
        bool flag_w=0;   //如果多链接情况，不希望进入不是多链接的条件下
        for (auto& pair : it->second.linkdatas)
        {
            string  temp;
            temp.clear();

            // std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
            temp.append(pair.second); //拿数据
            std::vector<int>  data;
            data.clear();
            data=extractNumbers(temp);
            extractNumber(data,data1,data2);  //处理的数据
            //查找输入端口--以及输出端口
            //输入端口需要确认一下多链接
            if( new_loadbance_pre)    //多链路负载均衡限制的路径，到了与终端链接的交换机节点输出数据
            { //上一次链路平衡分配了入端口---这个是多链路限制行为的
                new_loadbance_pre=0;

              if(nextportdata1.currctnode_name==firstElement)
              {
               inputport=nextportdata1.nextnode_inputport;
               ///cout <<" ------in"<<inputport;
                flag_w=1;
                data1_f=1;
              }
            }

            if(flag_next_inputport2)
            {
                flag_next_inputport2=0;
              if(nextportdata1.currctnode_name==firstElement)
              {
                inputport=nextportdata1.nextnode_inputport;
                flag_w=1;
                data1_f=1;
              }
            }

            if((!flag_w)&&((!flag_next_inputport2)||(!new_loadbance_pre)))
            {
                if(data2.type==input_nodetype&&data2.serialnumber==temp_input&&data1.serialnumber==it->second.id1)
                {
                    inputport=data1.port;
                    data1_f=1;
                }
            }

            if(data2.serialnumber==temp_output&&data1.serialnumber==it->second.id1&&data2.type==output_nodetype)
            {
                outputport=data1.port;
                data2_f=1;
            }

            if(data1_f&&data2_f)
            {  data1_f=0;data2_f=0;
                break;
            }

        }
        //以当前交换机结点名为文件名，输出文件
        //cout<<"path-port-data";
        flag_w=0;

        outputdata.append(std::to_string(inputport));  //inport
        outputdata.append(":");
        int targetnum=0;
        extractNumber_change(target,targetnum);
        outputdata.append(std::to_string(targetnum)); //目标结点
        outputdata.append("---");
        outputdata.append(std::to_string(outputport));  //outport
//                       cout<<"\n";
//                       cout<<outputdata;
//                       forword_rule item;
//                       item.forword_rule=outputdata;
//                       item.switchname=ptr[x].id;
//                       rulequeue.enqueue(item);
        forword_handle  item;
//                       std::unordered_multimap<int,forword_handle> datamap;
        item.inputport=inputport;
        item.outputport=outputport;
        item.outputdata=outputdata;
        item.target=targetnum;
        //datamap.emplace(targetnum,item);
         if(map_data.empty())
          map_data.emplace(it->second.id,item);
         else
         {
             auto it3 = map_data.find(it->second.id);
             bool similardata_flag=false;
             if (it3 != map_data.end())
             {
                 auto range = map_data.equal_range(it->second.id); // 查找键1
                 for (auto it1 = range.first; it1 != range.second; ++it1)
                 {

                     auto item1=it1->second;
                     if(item1.inputport==inputport&&item1.outputport==outputport&&item1.target==targetnum)
                     {
                         similardata_flag=true;
                         item1.sum++;
                         break;
                     }
                 }
                 if(similardata_flag)
                     similardata_flag=false;
                 else
                 {
                    map_data.emplace(it->second.id,item);
                 }

             }
             else
             {
                 map_data.emplace(it->second.id,item);
                 // std::cout << "Key 1 not found." << std::endl;
             }
         }

    }
    else {

        std::cout << "Key not found." << std::endl;
    }
}


void  rule_download_pathstarelment(std::unordered_map<std::string,switch_node> & ptr,int switchnodenum, const std::string& secondElement,\
                            int &temp_input, int &temp_output,int input_nodetype,int output_nodetype,const string target,\
                            Loadbalance_data &nextportdata,bool &flag_next_inputport1,\
                             std::unordered_multimap<std::string,forword_handle> & map_data)
{
    auto it = ptr.find(secondElement);

      if (it != ptr.end())
      {
          string  loardinformation;
          loardinformation.clear();
          int inputport=0,outputport=0,targetnum=0;
          string information=outputswitch_pathport_other(it->second,target,temp_output,output_nodetype,temp_input,\
                                       input_nodetype,loardinformation,nextportdata,flag_next_inputport1,\
                                                         inputport,outputport,targetnum);
 //                            if(flag_next_inputport1)
 //                            {   string  temp;
 //                                temp.clear();
 //                                temp.append("loadbalance: ");
 //                                temp.append(loardinformation);
 //                                queue.enqueue(temp);
 //                            }

 //                        forword_rule item;
 //                        item.forword_rule=information;
 //                        item.switchname=ptr[x].id;
 //                        rulequeue.enqueue(item);
          forword_handle  item;
          item.inputport=inputport;
          item.outputport=outputport;
          item.outputdata=information;
          item.target=targetnum;
          if(map_data.empty())
              map_data.emplace(it->second.id,item);
          else
          {
              auto it3 = map_data.find(it->second.id);
              bool similardata_flag=false;
              if (it3 != map_data.end())
              {
                  auto range = map_data.equal_range(it->second.id); // 查找键1
                  for (auto it1 = range.first; it1 != range.second; ++it1)
                  {
                      auto item1=it1->second;
                      if(item1.inputport==inputport&&item1.outputport==outputport&&item1.target==targetnum)
                      {
                          similardata_flag=true;
                          item1.sum++;
                          break;
                      }
                  }
                  if(similardata_flag)
                      similardata_flag=false;
                  else
                  {
                      map_data.emplace(it->second.id,item);
                  }
              }
              else
              {
                  map_data.emplace(it->second.id,item);
              }
          }

      }
      else {

          std::cout << "Key not found." << std::endl;
      }
}



 void across_board_handle_limit(switch_node&it, const std::vector<string> &path, const string &target,int &inputport,int &outputport, const std::string& secondElement,\
                                 const std::string & threeElement)
 {

     if(it.is_multilink&&it.is_limitport_swit&&(path.size()>5))
     {
          string  target_port_name;  //first
          target_port_name.clear();
          target_port_name.append(target);
          target_port_name.append("-");
          target_port_name.append(std::to_string(inputport));
          across_board_handle tempdata_across;   //保存的数据
          tempdata_across.target=target;
          tempdata_across.current_switch_name=secondElement;
          tempdata_across.across_switch_name=threeElement;
          tempdata_across.input_port=inputport;
          tempdata_across.output_port=outputport;

          if(it.across_record.empty())
          { //直接记录
              it.across_record.emplace(target_port_name,tempdata_across);
          }
          else
          { //查找是否有
              auto it3 = it.across_record.find(target_port_name);
              if (it3 !=it.across_record.end())
              {  //找到---对比数据
                  auto  item3=it3->second;
                  //如果入端口相同，出端口不同-限制（使用原来分配的端口）
                  if((outputport!=item3.output_port)&&inputport==item3.input_port&&target==item3.target&&item3.current_switch_name==secondElement)
                  {
                    //输出端口重配
                    outputport=item3.output_port;
                  }

              }
              else
              { //没有-记录
                 it.across_record.emplace(target_port_name,tempdata_across);
              }
          }
     }
 }


 void   board_inside_mulitport_handle_limit(switch_node&it,const string &target,int &inputport,int &outputport, const string  &temp_outputlinkdata,\
                                            Loadbalance_data &nextportdata1,bool &new_loadbance_pre)
 {
     string  linkdata_new;  //保存返回的上一次分配的链路
     if(it.is_multilink&&it.is_limitport_swit) //有多链接，且有限制端口
     {
         string  port_targetanme;
         port_targetanme.clear();
         port_targetanme.append(std::to_string(inputport));
         port_targetanme.append("-");
         port_targetanme.append(target);
         mulitport_handle_limit  tempdata,output_data ;
         tempdata.inport=inputport;
         tempdata.switchname=it.id;
         tempdata.targename=target;
         bool flag=false;
         if(!temp_outputlinkdata.empty())
         {   tempdata.previous_outport_link=temp_outputlinkdata;
             //数据记录or数据对比(当前数据--决策输出规则)
             flag=loadbalance_mutilport_limithandle(port_targetanme,tempdata,output_data,it.getnextserver_record,inputport,target);
         }
         if(flag)
         {
             if(output_data.inport==inputport&&output_data.targename==target)
             {
                 new_loadbance_pre=true;
                 linkdata_new=output_data.previous_outport_link;
                 //cout<<"\n"<<"loadbalance----new_pre: "<<linkdata_new;
                 //重配_输出端口
                 std::vector<int>  newtempdata;
                 linkdata data3,data4;
                 newtempdata.clear();
                 newtempdata=extractNumbers(linkdata_new);
                 extractNumber(newtempdata,data3,data4);  //处理的数据
                 outputport=data3.port;
                 nextportdata1.nextnode_inputport=data4.port;  //下一个输入端口缓存
                 nextportdata1.currctnode_name=it.id;
             }
         }
     }
 }


void   save_forword_handle(switch_node&it,const int &inputport,const int &outputport,const string & outputdata,const int &targetnum,\
                           std::unordered_multimap<std::string,forword_handle> &map_data)
{

    forword_handle  item;    //保存信息-处理相同项
    item.inputport=inputport;
    item.outputport=outputport;
    item.outputdata=outputdata;
    item.target=targetnum;
    if(map_data.empty())
        map_data.emplace(it.id,item);
    else
    {
        auto it3 = map_data.find(it.id);
        bool similardata_flag=false;
        if (it3 != map_data.end())
        {
            auto range = map_data.equal_range(it.id); // 查找键1
            for (auto it1 = range.first; it1 != range.second; ++it1)
            {
                auto item1=it1->second;
                if(item1.inputport==inputport&&item1.outputport==outputport&&item1.target==targetnum)
                {
                    similardata_flag=true;
                    item1.sum++;
                    break;
                }
            }
            if(similardata_flag)
                similardata_flag=false;
            else
            {
                map_data.emplace(it.id,item);
            }
        }
        else
        {
            map_data.emplace(it.id,item);
        }
     }
}



#if write
void rulseissued_from_dijkstra(const std::unordered_map<string, std::pair<std::vector<string>, int>> & paths,std::unordered_map<std::string,switch_node> &ptr,int switchnodenum,\
                               std::unordered_map<std::string,endnode_node> &ptr1,int endnodenum,\
                              const string star,std::unordered_multimap<std::string,forword_handle> &map_data)
{
    if(!star.empty())
    {//节点自身的规则下发
       rule_download(star,ptr1,endnodenum,map_data);
   }

    for (const auto& entry : paths)
    {
        string target = entry.first;
        std::vector<string> path = entry.second.first;

        if(path.empty())
        {
            cout<<"dijkstra have not compute data!";
        }
        //承接源--目的--转为int
        int temp_star=0;  //源
        int temp_target=0; //目的
        extractNumber_change(star,temp_star);
        extractNumber_change(target,temp_target);
        int temp_output=0,temp_input=0;
        int input_nodetype=0,output_nodetype=0; //输入/输出结点类型---后期从数据判断
        if(path.size()==3)
        { //本地通信情况

             rule_download_localswitch(path,ptr,switchnodenum,target,temp_star,temp_target,input_nodetype,output_nodetype,map_data);
        }
        else
        {
            //多个交换机情况------多连接下端口下发还有问题---负载均衡
            Loadbalance_data  nextportdata,nextportdata1;        //下一个端口数据（区分两个变量用处位置）
            bool flag_next_inputport1=0,flag_next_inputport2=0;
            bool    new_loadbance_pre=false;  //有目标走了相同链路,数据使用之前分配的.标志
            for (size_t i = 0; i < path.size() - 2; i += 1)
                {
                    const std::string& firstElement = path[i];
                    const std::string& secondElement = path[i + 1];
                    const std::string & threeElement  = path[i+2] ;
                    //是否到数据尾
                    if(firstElement.compare(path.back())==0)
                    {
                        break;
                    }
                    if((secondElement.compare(path.back())==0)||(threeElement.compare(path.back())==0))
                    {//是
                        temp_output=0;
                        temp_input=0;
                        input_nodetype=0;
                        output_nodetype=0;
                        extractNumber_change(firstElement,temp_input);
                        temp_output=temp_target;
                        input_nodetype=1; //后期优化
                        output_nodetype=2;
                        rule_download_tailelment(ptr,switchnodenum,firstElement,secondElement,new_loadbance_pre,nextportdata1,flag_next_inputport2,\
                                                 temp_input,temp_output,input_nodetype, output_nodetype,target,map_data);
                    }
                    else
                    {
                        //需要加入判断多链接的情况
                        temp_output=0;
                        temp_input=0;
                        if(i<1)
                        {  //计算结点和交换机结点情况
                            temp_input=temp_star;
                            extractNumber_change(threeElement,temp_output);
                            input_nodetype=2;
                            output_nodetype=1;
                            rule_download_pathstarelment(ptr,switchnodenum,secondElement,temp_input,temp_output,
                                                         input_nodetype,output_nodetype,target,nextportdata,flag_next_inputport1,map_data);
                        }
                        else
                        {
                                             //中间部分拿端口
                                             extractNumber_change(firstElement,temp_input);
                                             extractNumber_change(threeElement,temp_output);
                                             input_nodetype=1;  //后期改用数据赋值
                                             output_nodetype=1;
                                             //是否多链接确认--负载均衡  //端口输出处理------当前的结点和下一个结点--是否属于多链接结点

                                             string  outputdata;
                                             outputdata.clear();
                                             linkdata data1,data2;   //临时保存数据
                                             int inputport=0,outputport=0;
                                             bool data1_f=0,data2_f=0;  //找到数据相应标志
                                             bool  mutil1_f=0,mutil2_f=0;
                                             string  temp_outputlinkdata;   //临时保存的输出的链接
                                             //int       nextnode_input;
                                             //Loadbalance_data  nextportdata;
                                             //输出端口---负载均衡判断

                                              auto it = ptr.find(secondElement);

                                               if (it != ptr.end())
                                               {
                                                   if(it->second.is_multilink)
                                                   {
                                                    //输出端口确认:如：1-30：“13”
                                                      string outputlinknum;
                                                      outputlinknum.clear();
                                                      temp_outputlinkdata.clear();
                                                      outputlinknum.append(std::to_string(it->second.id1));
                                                      outputlinknum.append(std::to_string(temp_output));
                                                     //找到该输出端口-输出选择的链接

                                                      for ( LoadBalancer &lb : it->second.p1)
                                                      {
                                                          if(lb.port_soure_target==outputlinknum)
                                                          {
                                                              temp_outputlinkdata=lb.getNextServer();
                                                          }
                                                      }
                                                      //测试
                        //                              cout<<"\n"<<"loadbalance: "<<temp_outputlinkdata;
                        //                              if(!temp_outputlinkdata.empty())
                        //                              {
                        //                               string temp;
                        //                               temp.clear();
                        //                               cout<<"\n"<<"loadbalance: "<<temp_outputlinkdata;
                        //                               temp.append("loadbalance: ");
                        //                               temp.append(temp_outputlinkdata);
                        //                               queue.enqueue(temp);
                        //                              }
                                                   }

                                                   //遍历找端口
                                                   bool flag_havedinputport=0,flag_havedinputport_used=0;   //找到端口，不希望进入其他条件标志
                                                   bool flag_havedoutputport=0;
                                                   for (auto& pair : it->second.linkdatas)
                                                   {
                                                       string  temp;
                                                       temp.clear();
                                                       // std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
                                                       temp.append(pair.second); //拿数据
                                                       std::vector<int>  data;
                                                       data.clear();
                                                       data=extractNumbers(temp);
                                                       extractNumber(data,data1,data2);  //处理的数据

                                                       if(mutil1_f&&mutil2_f)
                                                       {
                                                           mutil1_f=0;mutil2_f=0;
                                                           break;
                                                       }
                                                       if(mutil1_f&&data2_f)
                                                       {
                                                           mutil1_f=0;
                                                           data2_f=0;
                                                           break;

                                                       }
                                                       if(data1_f&&mutil2_f)
                                                       {
                                                           data1_f=0;
                                                           mutil2_f=0;
                                                           break;
                                                       }

                                                       if(data1_f&&data2_f)
                                                       {  data1_f=0;data2_f=0;
                                                           break;
                                                       }
                                                       //输入
                                                       bool flag_111=0;  //进入之后的标志，找过程不希望在进入
                                                       if((!mutil1_f)&&(flag_next_inputport1||flag_next_inputport2))
                                                       {

                                                           if(flag_next_inputport1)
                                                           {
                                                               flag_next_inputport1=0;
                                                               if(nextportdata.currctnode_name==firstElement)
                                                               {
                                                                   inputport=nextportdata.nextnode_inputport;
                                                                   flag_havedinputport=1;
                                                                   mutil1_f=1;
                                                               }
                                                               flag_111=1;
                                                           }

                                                           if((!flag_111)&&flag_next_inputport2)
                                                           {
                                                               flag_next_inputport2=0;
                                                               if(nextportdata1.currctnode_name==firstElement)
                                                               {
                                                                   inputport=nextportdata1.nextnode_inputport;
                                                                   flag_havedinputport=1;
                                                                   flag_havedinputport_used=true;
                                                                   mutil1_f=1;
                                                               }
                                                           }

                                                           // 解决736-0 的情况（两头没有多链接）
                                                          if(!flag_havedinputport)  //已经在多链接获得端口--不希望遍历在此进入此判断
                                                          if(data2.type==input_nodetype&&data2.serialnumber==temp_input&&data1.serialnumber==it->second.id1)
                                                          {
                                                              inputport=data1.port;
                                                             // cout<<" ------------inin1"<<inputport;
                                                              data1_f=1;
                                                          }

                                                       }
                                                        else
                                                       {
                                                           if(!flag_havedinputport)  //已经在多链接获得端口--不希望遍历在此进入此判断
                                                           if(data2.type==input_nodetype&&data2.serialnumber==temp_input&&data1.serialnumber==it->second.id1)
                                                           {
                                                               inputport=data1.port;
                                                               data1_f=1;
                                                           }
                                                       }

                                                        //输出
                                                       if((!mutil2_f)&&it->second.is_multilink&&(!temp_outputlinkdata.empty()))
                                                         {

                                                           std::vector<int>  tempdata;
                                                           linkdata data3,data4;
                                                           tempdata.clear();
                                                           tempdata=extractNumbers(temp_outputlinkdata);
                                                           extractNumber(tempdata,data3,data4);  //处理的数据
                                                            if(data3.serialnumber==it->second.id1&&data4.serialnumber==temp_output&&data4.type==output_nodetype)
                                                            {
                                                              mutil2_f=1;
                                                              flag_havedoutputport=1;
                                                              outputport=data3.port;
                                                              nextportdata1.nextnode_inputport=data4.port;
                                                              nextportdata1.currctnode_name=it->second.id;
                                                              flag_next_inputport2=1;
                                                            }
                                                       }
                                                       else
                                                       {
                                                           if(!flag_havedoutputport)
                                                           if(data2.serialnumber==temp_output&&data1.serialnumber==it->second.id1&&data2.type==output_nodetype)
                                                           {
                                                               outputport=data1.port;
                                                               data2_f=1;
                                                           }

                                                       }

                                                   } //for

                                                   //下一个端口是否有使用过了-这个情况参考
                                                   if(!flag_havedinputport_used)
                                                   {
                                                       flag_havedinputport_used=0;
                                                       flag_next_inputport2=true;
                                                   }
                                                    //板间多端口限制
                                                   board_inside_mulitport_handle_limit(it->second,target,inputport,outputport,temp_outputlinkdata,nextportdata1,new_loadbance_pre);
                                                   //跨板信息收集记录以及限制 -----跨板情况路径元素超5
                                                   across_board_handle_limit(it->second,path,target,inputport,outputport,secondElement,threeElement);
                                                   //信息封装
                                                   flag_havedinputport=0;
                                                   flag_havedoutputport=0;
                                                   outputdata.append(std::to_string(inputport));  //inport
                                                   outputdata.append(":");
                                                   int targetnum=0;
                                                   extractNumber_change(target,targetnum);
                                                   outputdata.append(std::to_string(targetnum)); //目标结点
                                                   outputdata.append("---");
                                                   outputdata.append(std::to_string(outputport));  //outport

                        //                           forword_rule item;
                        //                           item.forword_rule=outputdata;
                        //                           item.switchname=ptr[x].id;
                        //                           rulequeue.enqueue(item);
                                                   //保存信息-处理相同项
                                                   save_forword_handle(it->second,inputport,outputport,outputdata,targetnum,map_data);

                                               } else {
                                                   // 未找到的情况
                                                   std::cout << "Key not found." << std::endl;
                                               }

                        }
                }
            }
        }
    }
}
#endif


#if test
bool  calculates_and_save_allendnode_shortpath_test(Graph<string>  &g, std::unordered_map<std::string,switch_node> &ptr, int switchnodenum,std::unordered_map<std::string,endnode_node> &ptr1,\
                                               int endnodenum ,moodycamel::ConcurrentQueue<string> &queue)
{
        //计算所有计算节点最短路径
        for (int j = 0; j <= endnodenum-1; ++j)
        {
            std::string  outputinformation;
            outputinformation.clear();
            string source="endnode"; //endnode
            source.append(std::to_string(j));
            auto shortestPaths = route_sssp(g, source);
            test_show_sssp_allshortespaths(shortestPaths,source);
            cout<<endl;
            //规则输出保存
            rulseissued_from_sssp_test(shortestPaths,ptr,ptr1,source,queue);
        }


    //单个源测试
//    std::string  outputinformation;
//    outputinformation.clear();
//    string source="endnode0"; //endnode
//    //    source.append(std::to_string(j));
//    auto shortestPaths = route_sssp(g, source);
//    test_show_sssp_allshortespaths(shortestPaths,source);
//    rulseissued_from_sssp_test(shortestPaths,ptr,ptr1,source,queue);

    return true;
}

#endif


#if write
bool  calculates_and_save_allendnode_shortpath(int n, Graph<string> &g,std::unordered_map<std::string,switch_node> &ptr,int switchnodenum,std::unordered_map<std::string,endnode_node> &ptr1,int endnodenum,\
                                              moodycamel::ConcurrentQueue<forword> &saverule_conqueque\
                                     ,std::unordered_map<std::string, std::ofstream> &fileStreams,\
                                               std::unordered_multimap<std::string,forword_handle> &map_data)
{

        for (int j = 0; j <= n-1; ++j)
        {
            std::string  outputinformation;
            outputinformation.clear();
            string source="endnode"; //endnode
            source.append(std::to_string(j));
            auto shortestPaths = route_sssp(g, source);
            //            test_show_sssp_allshortespaths(shortestPaths,source);

            //规则输出保存
            rulseissued_from_dijkstra(shortestPaths,ptr,switchnodenum,ptr1,endnodenum,source,map_data);
        }

        //遍历哈希map--写入文件
          for (auto it = map_data.begin(); it != map_data.end(); ++it)
          {
                   std::string switchname =it->first;
                   std::string forword_rule =it->second.outputdata;
                   if (fileStreams.find(switchname) == fileStreams.end())
                   {
                       std::string filePath = outputfile_write_infile + switchname + ".txt";
                       fileStreams[switchname].open(filePath, std::ios::app);
                   }
                   fileStreams[switchname] << forword_rule << std::endl;
               //std::cout << "Key: " << it->first << ", Value: " << it->second.outputdata << "sum-"<<it->second.sum<<std::endl;
          }
              // 关闭所有文件流
              for (auto& pair : fileStreams) {
                  pair.second.close();
              }
          return true;
}
#endif
