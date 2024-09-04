#include "common.h"

void test1(Graph<string>  g,string  source)
{
   cout << "the last path as follow:" << endl;
   auto dis = g.dijkstra(source);

   vector<string> vertices = g.get_vertices(); //所有结点
   for(auto vertex: vertices)
        if (dis[vertex] >= 0)
            cout << vertex<< ":" << dis[vertex] << endl;
}


void creatgragph_endnodes(const int endnodenum, endnode_node *ptr)
{
    for (int i = 0; i < endnodenum; ++i)
    {
        ptr[i].id1 = i ;
        string s;
        s.clear();
        s.append("endnode");
        s.append(std::to_string(i));
        ptr[i].id=s;
        ptr[i].is_terminalnode=true;
        ptr[i].nodetype=2;                //后期从边连接信息进行初始化整个数据---目前保留--后期优化
    }
}


void creatgraph_switchnodes(const int switchnodenum,switch_node *ptr)
{
        for (int i = 0; i < switchnodenum; ++i)
        {
            ptr[i].id1 = i ;
            string s;
            s.clear();
            s.append("switchnode");
            s.append(std::to_string(i));
            ptr[i].id=s;
            ptr[i].is_switchnode=true;
            ptr[i].nodetype=1;                         //后期从边连接信息进行初始化---优化
        }
}


void  extractNumber(const std::string& str,int &num)
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


void creatgraph_addvertex(Graph<string> &g,const endnode_node *ptr,const int endnodenum,
                          const switch_node *ptr1,const int swithnodenum)
{
    //计算结点
    for (int i=0;i<endnodenum;i++)
    {
         string  vertexname=ptr[i].id;
         g.add_vertex(vertexname);
    }

    //交换机结点
    for(int i=0;i<swithnodenum;i++)
    {
      string vertexname=ptr1[i].id;
      g.add_vertex(vertexname);
    }
}


void addedge_data(const linkdata &data1,const endnode_node *ptr,const int nodenum,string &endnodename)
{    //计算结点
     if(data1.type==2)
        {
         for (int i=0;i<nodenum;i++)
           {
             if(data1.serialnumber==ptr[i].id1)
                  endnodename=ptr[i].id;
          }
       }
     else
     {
           cout<<"edge have error! " ;
     }
}


void addedge_data1(const linkdata &data1,const switch_node *ptr,const int nodenum,string &switchnodename)
{    //交换机结点
     if(data1.type==1)
        {
         for (int i=0;i<nodenum;i++)
           {
             if(data1.serialnumber==ptr[i].id1)
                  switchnodename=ptr[i].id;
          }
       }
     else
     {
           cout<<"edge have error! " ;
     }
}


void  addedge(Graph<string> &g,const string node1name,const string node2name,int weight)
{
        g.add_edge(node1name, node2name, weight);
}


void  saveswitchnode_portdata(const linkdata &s, switch_node *ptr1,const int switchnodenum,\
                              const string nodename, const string it, bool is_limitport)
{
   if(s.type==1)
   {
    for(int i=0;i<switchnodenum;i++)
    {
      if(s.serialnumber==ptr1[i].id1&&nodename==ptr1[i].id)
      {  //保存端口信息
        ptr1[i].linkdatas.insert(std::make_pair(s.port,it));//insert(std::make_pair(s.port,it));
        //多链接端口负载均衡限制----用于判断是否需要限制输出端口
        ptr1[i].is_limitport_swit=is_limitport;
      }
    }
   }
   else
   {
       cout<<" switch data have error! ";
   }
}


void saveendnode_portdata(const linkdata &s, endnode_node *ptr,const int endnodenum,\
                          const string nodename, const string it)
{
 if(s.type==2)
 {
     for (int i=0;i<endnodenum;i++)
     {
         if(s.serialnumber==ptr[i].id1&&nodename==ptr[i].id)
         {
             ptr[i].link=it;
         }
     }
 }
 else
 {
    cout<<" endnode data have error !";
 }
}


void svaeswitchnode_multilinkdata1(const string nodename,std::map<string,string> &s,\
                                   switch_node *ptr1,const int switchnodenum)
{
    for (int i=0;i<switchnodenum;i++)
    {
        if(ptr1[i].id==nodename)
        {
            //s=ptr1[i].multilink;
            ptr1[i].multilink.insert(s.begin(), s.end()); //数据多的情况高效
            ptr1[i].is_multilink=true;
        }
    }
}


std::vector<std::string> extractFirstTwoDigits(const std::vector<std::string>& data)
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


void svaeswitchnode_multilinkdata2(const string nodename ,switch_node *ptr1,const int switchnodenum)
{
    //找出多链接相应的端口链接数量/每个端口链接链路数量
    //多链路信息统计
    int  mutilport_count=0;
    int  mutillink_count=0;
    std::vector<string>  data;  //存储的链接数据
    std::vector<string> data2;
    int i=0;
    while(i<switchnodenum)
    {
        if(ptr1[i].id==nodename)
        {
            data.clear();
            data2.clear();
            for (const auto& pair : ptr1[i].multilink)
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
            ptr1[i].multilink_portnum=counts.size();
            ptr1[i].multilink_linknum=link1;   //多链接链路数
            // cout<<"..............."<<mutillink_count<<"----"<<mutilport_count;
            //开辟多链接负载均衡对象
            //  ptr1[i].loadBalancers=new LoadBalancer[mutilport_count];  //记得释放
            ptr1[i].loadbalanceobject_size=mutilport_count;
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
                       ptr1[i].p1.push_back(LoadBalancer(temp_portlinkdata, temp));
                }
                //测试
                //                cout<<"\n"<<"---------------creatlinkdata:";
                //                for (const std::string& str : temp_portlinkdata)
                //                   {
                //                       std::cout << str << std::endl;
                //                   }
            }
        } //if
        i++;
    }
}


void  multilink_handle(std::vector<string> &data,const string nodename,switch_node *ptr1,const int switchnodenum)
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


void judgment_multilinkdataform_nodemap(switch_node *ptr,const int nodenum,callback1 fun)
{
    //交换机数组
    std::vector<string>  data;
    for(int i=0;i<nodenum;i++)
    {
         data.clear();
        for (const auto& pair : ptr[i].linkdatas)
        {
            //std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
            data.push_back(pair.second); //插入数据
        }
         //多链接数据判断
        fun(data,ptr[i].id,ptr,nodenum);
    }
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


void creatgraph_addedge(Graph<string> &g,endnode_node *ptr,const int endnodenum, switch_node *ptr1,\
                        int switchnodenum,std::list<std::string>& s)
{
    for (std::list<std::string>::iterator it = s.begin(); it != s.end(); ++it)
        {
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
     judgment_multilinkdataform_nodemap(ptr1,switchnodenum,multilink_handle);
}


void  switchnode_show(const switch_node *ptr,int switchnodenum,int type=0,int num=0)
{
  if(type==0&&num==0)
  {
      cout<<"id:"<<ptr->id1;
      cout<<"id1:"<<ptr->id1;
      // 遍历并打印 map 中的键值对---连接信息
      cout<<"\n";
      for (const auto& pair : ptr->linkdatas)
      {
          std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
      }
  }
  else if (type==1&&num==0)
  {
      for (int i=0;i<switchnodenum;i++)
      {
      cout<<"id:"<<ptr[i].id;
      cout<<"id1:"<<ptr[i].id1;
      // 遍历并打印 map 中的键值对---连接信息
      cout<<"\n";
      for (const auto& pair : ptr[i].linkdatas)
      {
          std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
      }
      cout<<"is/no switchnode"<<ptr[i].is_switchnode;
      cout<<"\n";
     }
  }
  else if (type==2&&(num!=0&&num<=switchnodenum))
  {
      for (int i=0;i<switchnodenum;i++)
      {
          if(num==i)
          {
              cout<<"id:"<<ptr[i].id;
              cout<<"id1:"<<ptr[i].id1;
              // 遍历并打印 map 中的键值对---连接信息
              cout<<"\n";
              for (const auto& pair : ptr[i].linkdatas)
              {
                  std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
              }
              cout<<"is/no switchnode"<<ptr[i].is_switchnode;
             break;
          }
      }
  }
  else
  {
   cout<<"type input have error,please input again!" ;
  }
}


void switcnode_multilinkshow (switch_node *ptr,int switchnodenum,int type=0,int num=0)
{
   cout<<"show multilink data!";
    if(type==0&&num==0)
    {
        cout<<"id:"<<ptr->id1;
        cout<<"id1:"<<ptr->id1;
        // 遍历并打印 map 中的键值对---连接信息
        cout<<"\n";
        cout<<"num: "<<ptr->multilink.size();
        cout<<"\n";
        for (const auto& pair : ptr->multilink)
        {
            std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
        }
        cout<<"\n"<<"mutillink data---linkcount---portcount:";
        cout <<ptr->multilink_linknum;
        cout<<"\t"<<ptr->multilink_portnum;
        cout<<"\n"<<"blance:";

        for (const LoadBalancer &lb : ptr->p1)
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
    else if (type==1&&num==0)
    {
        for (int i=0;i<switchnodenum;i++)
        {
        cout<<"id:"<<ptr[i].id;
        cout<<"id1:"<<ptr[i].id1;
        // 遍历并打印 map 中的键值对---连接信息
        cout<<"\n";
        cout<<"num: "<<ptr[i].multilink.size();
        cout<<"\n";
        for (const auto& pair : ptr[i].multilink)
        {
            std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
        }
        cout<<"\n";
        cout<<"\n"<<"mutillink data---linkcount---portcount:";
        cout <<ptr->multilink_linknum;
        cout<<"\t"<<ptr->multilink_portnum;
        cout<<"\n"<<"blance:";
//         std::vector<LoadBalancer>& lbVector = *ptr[i].p;
        for (const LoadBalancer &lb : ptr[i].p1)
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
    {
        for (int i=0;i<switchnodenum;i++)
        {
            if(num==i)
            {
                cout<<"id:"<<ptr[i].id;
                cout<<"id1:"<<ptr[i].id1;
                // 遍历并打印 map 中的键值对---连接信息
                cout<<"\n";
                cout<<"num: "<<ptr[i].multilink.size();
                cout<<"\n";
                for (const auto& pair : ptr[i].multilink)
                {
                    std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
                }
                cout<<"\n"<<"mutillink data---linkcount---portcount:";
                cout <<ptr->multilink_linknum;
                cout<<"\t"<<ptr->multilink_portnum;
                cout<<"\n"<<"blance:";
//                std::vector<LoadBalancer>& lbVector = *ptr[i].p;
               for (const LoadBalancer &lb : ptr[i].p1)
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
               break;
            }
        }
    }
    else
    {
     cout<<"type input have error,please input again!" ;
    }
}


void endnode_show(const endnode_node *ptr,const int endnodenum,int type=0,int num=0)
{

    if(type==0&&num==0)
    {
        cout<<"id:"<<ptr->id1;
        cout<<"id1:"<<ptr->id1;
        cout<<"link:"<<ptr->link;
        cout<<"is/no endnode:"<<ptr->is_terminalnode;
    }
    else if (type==1&&num==0)
    {
        for (int i=0;i<endnodenum;i++)
        {
            cout<<"id:"<<ptr[i].id;
            cout<<"id1:"<<ptr[i].id1;
            cout<<"link:"<<ptr[i].link;
            cout<<"is/no endnode:"<<ptr[i].is_terminalnode;
            cout<<"\n";
        }
    }
    else if (type==2&&(num!=0&&num<=endnodenum))
    {
        for (int i=0;i<endnodenum;i++)
        {
            if(num==i)
            {
            cout<<"id:"<<ptr[i].id;
            cout<<"id1:"<<ptr[i].id1;
            cout<<"link:"<<ptr[i].link;
            cout<<"is/no endnode:"<<ptr[i].is_terminalnode;
             break;
            }
        }
    }
    else
    {
        cout<<"type input have error! please input again!" ;
    }
}


std::vector<string> dijkstra( Graph<string>& g, const string& start, const string& target, int& dis)
 {
     // 使用无穷大表示初始距离
     const int INF = std::numeric_limits<int>::max();

     // 存储节点到起点的最短距离
     std::unordered_map<string, int> distance;

     // 存储节点的前驱节点
     std::unordered_map<string, string> prev;

     // 优先队列，按照节点距离从小到大排序
     std::priority_queue<std::pair<int, string>, std::vector<std::pair<int, string>>, std::greater<std::pair<int, string>>> pq;

     // 初始化距离和前驱节点
     for (const auto& node : g.get_vertices())
     {
         distance[node] = INF;
         prev[node] = "";
     }
     // 设置起点的距离为 0
     distance[start] = 0;

     // 将起点入队
     pq.push(std::make_pair(0, start));

     // Dijkstra 算法的主循环
     while (!pq.empty())
     {
         auto curr = pq.top().second;
         pq.pop();

         // 如果已经到达目标节点，则结束算法
         if (curr == target) {
             break;
         }
         // 获取当前节点的邻居
         std::vector<string> neighbors = g.get_neighbours_anothertype(curr);
          // std::map<string ,int>   neighbors=g.get_neighbours(curr);
         // 更新邻居节点的距离和前驱节点
         for (const auto& neighbor : neighbors)
         {
             //int weight = g.getWeight(curr, neighbor);
             int weight = g.get_weight(curr, neighbor); //权重
             int newDistance = distance[curr] + weight; //新距离

             if (newDistance < distance[neighbor])
             {
                 distance[neighbor] = newDistance;
                 prev[neighbor] = curr;
                 pq.push(std::make_pair(newDistance, neighbor));
             } //找相等的路径----后期加--解决144过载
         }
     }

     // 根据前驱节点构建最短路径
     std::vector<string> shortestPath;
     string node = target;
     while (node != "")
     {
         shortestPath.insert(shortestPath.begin(), node);
         node = prev[node];
     }
     // 更新最短路径长度
     dis = distance[target];
     return shortestPath;
 }


vector<Path> dijkstra1( Graph<string>& g, const string& start, const string& target, int& dis)
{
    // 使用无穷大表示初始距离
    const int INF = numeric_limits<int>::max();

    // 存储节点到起点的最短距离
    unordered_map<string, int> distance;

    // 存储节点的前驱节点
    unordered_map<string, vector<string>> prev;

    // 优先队列，按照节点距离从小到大排序
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

    // 初始化距离和前驱节点
    //for (const auto& node : g.getNodes())
     for(const auto&node:g.get_vertices())
    {
        distance[node] = INF;
    }

    // 设置起点的距离为 0
    distance[start] = 0;

    // 将起点入队
    pq.push(make_pair(0, start));

    // Dijkstra 算法的主循环
    while (!pq.empty())
     {
        int currDistance = pq.top().first;
        string currNode = pq.top().second;
        pq.pop();

        // 如果当前距离已经超过已知的最短路径，停止搜索
        if (currDistance > distance[currNode])
        {
            continue;
        }

        // 获取当前节点的邻居
        // vector<string> neighbors = g.getNeighbors(currNode);
         std::vector<string> neighbors = g.get_neighbours_anothertype(currNode);
        // 更新邻居节点的距离和前驱节点
        for (const string& neighbor : neighbors)
        {
            //int weight = g.getWeight(currNode, neighbor);
            int weight = g.get_weight(currNode, neighbor); //权重
            int newDistance = currDistance + weight;

            if (newDistance < distance[neighbor])
            {
                distance[neighbor] = newDistance;
                prev[neighbor].clear();
                prev[neighbor].push_back(currNode);
                pq.push(make_pair(newDistance, neighbor));
            }
                else if (newDistance == distance[neighbor])
            {
                prev[neighbor].push_back(currNode);
            }
        }
    }

    // 根据前驱节点构建最短路径
    vector<Path> shortestPaths;
    vector<string> path;

    // 回溯函数，构建最短路径
    function<void(const string&)> backtrack = [&](const string& node)
    {
        if (node == start)
        {
            Path p;
            p.distance = distance[target];
            p.nodes = path;
            p.nodes.push_back(start);
            reverse(p.nodes.begin(), p.nodes.end());//反置
            shortestPaths.push_back(p);
            return;
        }

        for (const string& prevNode : prev[node])
        {
            path.push_back(node);
            backtrack(prevNode);
            path.pop_back();
        }
    };

    //path.push_back(target);
    backtrack(target);

    // 更新最短距离
    dis = distance[target];

    return shortestPaths;
}


std::vector<string> bfsShortestPath( Graph<string>& graph, const string& start, const string& target)
{
    // 创建队列用于BFS
    queue<pair<string, vector<string>>> q;
    q.push({start, {start}}); // 初始节点和路径

    // 创建集合用于跟踪已访问的节点
    std::unordered_set<string> visited;
    visited.insert(start);

    while (!q.empty())
    {
        auto currentNode = q.front().first;
        vector<string> currentPath = q.front().second;
        q.pop();

        // 如果找到目标节点，返回路径
        if (currentNode == target) {
            return currentPath;
        }

        // 探索邻居节点
       std::vector<string> neighbors = graph.get_neighbours_anothertype(currentNode);
        for (const string& neighbor : neighbors)
        {
            if (visited.find(neighbor) == visited.end())
            {
                // 未访问过的节点
                visited.insert(neighbor);
                vector<string> newPath = currentPath;
                newPath.push_back(neighbor);
                q.push({neighbor, newPath});
            }
        }
    }

    // 如果未找到路径，返回空向量
    return {};
}


bool  loadbalance_mutilport_limithandle(const string &port_targetname,mutilport_handle &curr_port_data ,mutilport_handle& output,\
                                          std::unordered_map  <std::string, mutilport_handle> &data,const int inputport,const string target)
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


string outputswitch_pathport(const switch_node &nodedata,const string target,const int output,const int outputtype,\
                             const int input,const int inputtype,int &inport,int &outport,int &targetnum1)
{
#if test
    cout<<"intput port:targetnode---outputport";
    cout<<"\n";
#endif
    string  outputdata;
    outputdata.clear();

    linkdata data1,data2;
    int inputport=0,outputport=0;
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
        if(data2.serialnumber==input&&data1.serialnumber==nodedata.id1&&data2.type==inputtype)
        {
            inputport=data1.port;
            inport=inputport;

        }
        if(data2.serialnumber==output&&data1.serialnumber==nodedata.id1&&data2.type==outputtype)
        {
            outputport=data1.port;
            outport=outputport;
        }

    }
    //以当前交换机结点名为文件名，输出文件
#if test
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
    extractNumber(target,targetnum);
    outputdata.append(std::to_string(targetnum)); //目标结点
    targetnum1=targetnum;
    outputdata.append("---");
    outputdata.append(std::to_string(outputport));  //outport
//    cout<<outputdata;
#endif

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
    extractNumber(target,targetnum);
    outputdata.append(std::to_string(targetnum)); //目标结点
    targetnum1=targetnum;
    outputdata.append("---");
    outputdata.append(std::to_string(outputport));  //outport
    outport=outputport;
  #endif
    return outputdata;
}

void  rule_download(const string star,const string target,endnode_node *ptr1,const int endnodenum,\
                    std::unordered_multimap<std::string,forword_handle> & map_data)
{
    string outputdata;
    outputdata.clear();
    int inputport=0;
    int outputport=0;
    string tempswitchname;
    tempswitchname.clear();
    //查找端口
    for(int i=0;i<endnodenum;i++)
    {
        if(ptr1[i].id==star)
        {
            linkdata data1,data2;
            string  temp;
            temp.clear();
            // std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
            temp.append(ptr1[i].link); //拿数据
            std::vector<int>  data;
            data.clear();
            data=extractNumbers(temp);
            extractNumber(data,data1,data2);  //处理的数据
            inputport=data2.port;
            outputport=data2.port;
            tempswitchname.append("switchnode");
            tempswitchname.append(std::to_string(data2.serialnumber));
            break;
        }

    }

    //forword_rule item;
    forword_handle  item;
    outputdata.append(std::to_string(inputport));  //inport
    outputdata.append(":");
    int targetnum=0;
    extractNumber(target,targetnum);
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


void  rule_download_localswitch(const std::vector<string> &path,switch_node *ptr,int switchnodenum,const string target,\
                                const int temp_star,const int temp_target,int input_nodetype,int output_nodetype,\
                                std::unordered_multimap<std::string,forword_handle> & map_data)
{
    for (size_t i = 0; i < path.size() - 1; i += 1)
    {
        if(i==1)
        {
            for(int x=0;x<switchnodenum;x++)
            {
                if (ptr[x].id==path[i])
                {
                    //数据处理，输出端口文件

                    input_nodetype=2;
                    output_nodetype=2;
                    int inputport=0,outputport=0,targetnum=0;
                    string information=outputswitch_pathport(ptr[x],target,temp_target,output_nodetype,temp_star,input_nodetype,inputport,outputport,targetnum);
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
                       map_data.emplace(ptr[x].id,item);
                     else
                     {
                        auto it = map_data.find(ptr[x].id);
                        bool similardata_flag=false;
                        if (it != map_data.end())
                        {
                            auto range = map_data.equal_range(ptr[x].id); // 查找键1
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
                               map_data.emplace(ptr[x].id,item);
                            }

                        }
                        else
                        {
                            map_data.emplace(ptr[x].id,item);
                        }
                    }
                    break;
                }
            }
        }
    }

}


void  rule_download_pathstarelment(switch_node *ptr,int switchnodenum, const std::string& secondElement,\
                            int &temp_input, int &temp_output,int &input_nodetype,int &output_nodetype,const string target,\
                            Loadbalance_data &nextportdata,bool &flag_next_inputport1,\
                             std::unordered_multimap<std::string,forword_handle> & map_data)
{
    for (int x=0;x<switchnodenum;x++)
    {
        //是否多链接确认--负载均衡 //端口输出处理计算结点和当前交换机结点没有多链接关系

        if(ptr[x].id==secondElement)
        {
         string  loardinformation;
         loardinformation.clear();
         int inputport=0,outputport=0,targetnum=0;
         string information=outputswitch_pathport_other(ptr[x],target,temp_output,output_nodetype,temp_input,\
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
             map_data.emplace(ptr[x].id,item);
         else
         {
             auto it = map_data.find(ptr[x].id);
             bool similardata_flag=false;
             if (it != map_data.end())
             {
                 auto range = map_data.equal_range(ptr[x].id); // 查找键1
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
                     map_data.emplace(ptr[x].id,item);
                 }
             }
             else
             {
                 map_data.emplace(ptr[x].id,item);
             }
         }
         break;
        }
    }

}



void rule_download_tailelment(switch_node *ptr,int switchnodenum,const std::string& firstElement, const std::string& secondElement,\
                              bool &new_loadbance_pre,Loadbalance_data &nextportdata1,bool &flag_next_inputport2,\
                              int &temp_input, int &temp_output,int input_nodetype,int output_nodetype,const string target,\
                              std::unordered_multimap<std::string,forword_handle> & map_data)
{
    for (int x=0;x<switchnodenum;x++)
    {
        //是否多链接确认--负载均衡  //端口输出处理---数据尾不需要判断多链接

        if(ptr[x].id==secondElement)
        {
            string  outputdata;
            outputdata.clear();
            linkdata data1,data2;
            int inputport=0,outputport=0;
            bool data1_f=0,data2_f=0;
            bool flag_w=0;   //如果多链接情况，不希望进入不是多链接的条件下
            for (auto& pair : ptr[x].linkdatas)
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
                    if(data2.type==input_nodetype&&data2.serialnumber==temp_input&&data1.serialnumber==ptr[x].id1)
                    {
                        inputport=data1.port;
                        data1_f=1;
                    }
                }

                if(data2.serialnumber==temp_output&&data1.serialnumber==ptr[x].id1&&data2.type==output_nodetype)
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
            extractNumber(target,targetnum);
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
              map_data.emplace(ptr[x].id,item);
             else
             {
                 auto it = map_data.find(ptr[x].id);
                 bool similardata_flag=false;
                 if (it != map_data.end())
                 {
                     auto range = map_data.equal_range(ptr[x].id); // 查找键1
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
                        map_data.emplace(ptr[x].id,item);
                     }

                 }
                 else
                 {
                     map_data.emplace(ptr[x].id,item);
                     // std::cout << "Key 1 not found." << std::endl;
                 }


//                            auto range = multimap_data.equal_range(ptr[x].id); // 查找键1
//                            if (range.first ==multimap_data.end() && range.second == multimap_data.end())
//                            {
//                              multimap_data.emplace(ptr[x].id,datamap);
//                            }
//                            else
//                            {
//                                for (auto it = range.first; it != range.second; ++it)
//                                {
//                                    // 查找特定键的所有元素
//                                    // int key_to_find = 1;
//                                    auto range1 = it->second.equal_range(targetnum);
//                                    if (range1.first ==it->second.end() && range1.second == it->second.end())
//                                    {
//                                         multimap_data.emplace(ptr[x].id,datamap);
//                                    }
//                                    else
//                                    {
//                                        for (auto it1 = range1.first; it1 != range1.second; ++it1)
//                                        {
//                                            // it1->first 是键，it1->second 是值（forward_handle）
//                                            auto item1=it1->second;
//                                            if(item1.inputport==inputport&&item1.outputport==outputport)
//                                            {
//                                                item1.sum++;
//                                            }
//                                            else
//                                            {
//                                                multimap_data.emplace(ptr[x].id,datamap);
//                                            }
//                                            //std::cout << "Key: " << it->first << ", Value: " << it->second.some_function() << std::endl;
//                                        }
//                                    }
//                                }
//                            }
             }

            break;
        }
    }
}

#if  write
void rulseissued_from_dijkstra(const std::vector<string> path,switch_node *ptr,int switchnodenum,endnode_node *ptr1,int endnodenum,\
                               const string star,const string target,\
                               std::unordered_multimap<std::string,forword_handle> & map_data
                              /* moodycamel::ConcurrentQueue<forword_rule> &rulequeue*/)
{
    if(star==target)
    {
       rule_download(star,target,ptr1,endnodenum,map_data);
    }
    else
   {
            if(path.empty())
            {
                cout<<"dijkstra have not compute data!";
            }
            //承接源--目的--转为int
            int temp_star=0;  //源
            int temp_target=0; //目的
            extractNumber(path.front(),temp_star);
            extractNumber(path.back(),temp_target);
            int temp_output=0,temp_input=0;
            int input_nodetype=0,output_nodetype=0;  //输入/输出结点类型---后期从数据判断

            //判断元素个数---在本地交换机通信的情况--一个交换机

   if(path.size()==3)
   {
     rule_download_localswitch(path,ptr,switchnodenum,target,temp_star,temp_target,input_nodetype,output_nodetype,map_data);
   }
   else
   {  //多个交换机情况------多连接下端口下发还有问题---负载均衡

       Loadbalance_data  nextportdata,nextportdata1;
       bool flag_next_inputport1=0,flag_next_inputport2=0;
       bool    new_loadbance_pre=false;  //有目标走了相同链路,数据使用之前分配的-标志

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
               extractNumber(firstElement,temp_input);
               temp_output=temp_target;
               input_nodetype=1; //后期优化
               output_nodetype=2;
               rule_download_tailelment(ptr,switchnodenum,firstElement,secondElement,new_loadbance_pre,nextportdata1,flag_next_inputport2,\
                                       temp_input,temp_output,input_nodetype, output_nodetype,target,map_data);
           }
           else
           {    //需要加入判断多链接的情况
               temp_output=0;
               temp_input=0;

               if(i<1)
               {  //计算结点和交换机结点情况
                   temp_input=temp_star;
                   extractNumber(threeElement,temp_output);
                   input_nodetype=2;
                   output_nodetype=1;
                   rule_download_pathstarelment(ptr,switchnodenum,secondElement,temp_input,temp_output,
                                       input_nodetype,output_nodetype,target,nextportdata,flag_next_inputport1,map_data);
               }
               else
               {      //中间部分拿端口
                   extractNumber(firstElement,temp_input);
                   extractNumber(threeElement,temp_output);
                   input_nodetype=1;  //后期改用数据赋值
                   output_nodetype=1;
                   for (int x=0;x<switchnodenum;x++)
                   {
                       //是否多链接确认--负载均衡  //端口输出处理------当前的结点和下一个结点--是否属于多链接结点

                       string  outputdata;
                       outputdata.clear();
                       linkdata data1,data2;
                       int inputport=0,outputport=0;
                       bool data1_f=0,data2_f=0;  //找到数据相应标志
                       bool  mutil1_f=0,mutil2_f=0;
                       string  temp_outputlinkdata;
                       //int       nextnode_input;
                       //Loadbalance_data  nextportdata;
                       //输出端口---负载均衡判断

                       if(ptr[x].id==secondElement)
                       {
                           if(ptr[x].is_multilink)
                           {
                            //输出端口确认:如：1-30：“13”
                              string outputlinknum;
                              outputlinknum.clear();
                              temp_outputlinkdata.clear();
                              outputlinknum.append(std::to_string(ptr[x].id1));
                              outputlinknum.append(std::to_string(temp_output));
                             //找到该输出端口-输出选择的链接

                              for ( LoadBalancer &lb : ptr[x].p1)
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
                           for (auto& pair : ptr[x].linkdatas)
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
                                  if(data2.type==input_nodetype&&data2.serialnumber==temp_input&&data1.serialnumber==ptr[x].id1)
                                  {
                                      inputport=data1.port;
                                     // cout<<" ------------inin1"<<inputport;
                                      data1_f=1;
                                  }

                               }
                                else
                               {
                                   if(!flag_havedinputport)  //已经在多链接获得端口--不希望遍历在此进入此判断
                                   if(data2.type==input_nodetype&&data2.serialnumber==temp_input&&data1.serialnumber==ptr[x].id1)
                                   {
                                       inputport=data1.port;
                                       data1_f=1;
                                   }
                               }

                                //输出
                               if((!mutil2_f)&&ptr[x].is_multilink&&(!temp_outputlinkdata.empty()))
                                 {

                                   std::vector<int>  tempdata;
                                   linkdata data3,data4;
                                   tempdata.clear();
                                   tempdata=extractNumbers(temp_outputlinkdata);
                                   extractNumber(tempdata,data3,data4);  //处理的数据
                                    if(data3.serialnumber==ptr[x].id1&&data4.serialnumber==temp_output&&data4.type==output_nodetype)
                                    {
                                      mutil2_f=1;
                                      flag_havedoutputport=1;
                                      outputport=data3.port;
                                      nextportdata1.nextnode_inputport=data4.port;
                                      nextportdata1.currctnode_name=ptr[x].id;
                                      flag_next_inputport2=1;
                                    }
                               }
                               else
                               {
                                   if(!flag_havedoutputport)
                                   if(data2.serialnumber==temp_output&&data1.serialnumber==ptr[x].id1&&data2.type==output_nodetype)
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

                           string  linkdata_new;  //保存返回的上一次分配的链路
                           if(ptr[x].is_multilink&&ptr[x].is_limitport_swit)
                           {
                               string  port_targetanme;
                               port_targetanme.clear();
                               port_targetanme.append(std::to_string(inputport));
                               port_targetanme.append("-");
                               port_targetanme.append(target);
                               mulitport_handle_limit  tempdata,output_data ;
                               tempdata.inport=inputport;
                               tempdata.switchname=ptr[x].id;
                               tempdata.targename=target;
                               bool flag=false;
                               if(!temp_outputlinkdata.empty())
                               {   tempdata.previous_outport_link=temp_outputlinkdata;
                                   //数据记录or数据对比(当前数据--决策输出规则)
                                   flag=loadbalance_mutilport_limithandle(port_targetanme,tempdata,output_data,ptr[x].getnextserver_record,inputport,target);
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
                                       nextportdata1.currctnode_name=ptr[x].id;
                                   }
                               }
                           }

                           flag_havedinputport=0;
                           flag_havedoutputport=0;
                           outputdata.append(std::to_string(inputport));  //inport
                           outputdata.append(":");
                           int targetnum=0;
                           extractNumber(target,targetnum);
                           outputdata.append(std::to_string(targetnum)); //目标结点
                           outputdata.append("---");
                           outputdata.append(std::to_string(outputport));  //outport

//                           forword_rule item;
//                           item.forword_rule=outputdata;
//                           item.switchname=ptr[x].id;
//                           rulequeue.enqueue(item);
                           forword_handle  item;
                           item.inputport=inputport;
                           item.outputport=outputport;
                           item.outputdata=outputdata;
                           item.target=targetnum;
                           if(map_data.empty())
                               map_data.emplace(ptr[x].id,item);
                           else
                           {
                               auto it = map_data.find(ptr[x].id);
                               bool similardata_flag=false;
                               if (it != map_data.end())
                               {
                                   auto range = map_data.equal_range(ptr[x].id); // 查找键1
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
                                       map_data.emplace(ptr[x].id,item);
                                   }
                               }
                               else
                               {
                                   map_data.emplace(ptr[x].id,item);
                               }
                            }
                           break;
                       } //if
                   } //for
               }
           }
           //    std::cout << "First: " << firstElement << ", Second: " << secondElement << std::endl;
      }
    }
  }
}
#endif

#if test
void  rulseissued_from_dijkstra(const std::vector<string> path,switch_node *ptr,int switchnodenum,endnode_node *ptr1,int endnodenum,\
                               const string star,const string target,moodycamel::ConcurrentQueue<string> &queue)
{

    if(star==target)
    {
        string outputdata;
        outputdata.clear();
        int inputport=0;
        int outputport=0;
        //查找端口
        for(int i=0;i<endnodenum;i++)
        {
            if(ptr1[i].id==star)
            {
                linkdata data1,data2;
                string  temp;
                temp.clear();
                // std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
                temp.append(ptr1[i].link); //拿数据
                std::vector<int>  data;
                data.clear();
                data=extractNumbers(temp);
                extractNumber(data,data1,data2);  //处理的数据
                inputport=data2.port;
                outputport=data2.port;
                break;
            }

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
    else

  {
        if(path.empty())
        {
            cout<<"dijkstra have not compute data!";
        }
        //承接源--目的--转为int
        int temp_star=0;  //源
        int temp_target=0; //目的
        extractNumber(path.front(),temp_star);
        extractNumber(path.back(),temp_target);
        int temp_output=0,temp_input=0;
        int input_nodetype=0,output_nodetype=0; //输入/输出结点类型---后期从数据判断

   //判断元素个数---在本地交换机通信的情况--一个交换机
   if(path.size()==3)
   {
       for (size_t i = 0; i < path.size() - 1; i += 1)
       {
           if(i==1)
           {
               for(int x=0;x<switchnodenum;x++)
               {
                   if (ptr[x].id==path[i])
                   {
                       //数据处理，输出端口文件
                       input_nodetype=2;
                       output_nodetype=2;
                       int inport=0,outport=0,targetnum=0;
                       string information=outputswitch_pathport(ptr[x],target,temp_target,output_nodetype,temp_star,input_nodetype,inport,outport,targetnum);
                       queue.enqueue(information);
                       break;
                   }
               }
           }
       }
   }
   else
   {  //多个交换机情况------多连接下端口下发还有问题---负载均衡
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
               extractNumber(firstElement,temp_input);
               temp_output=temp_target;
               input_nodetype=1; //后期优化
               output_nodetype=2;
               for (int x=0;x<switchnodenum;x++)
               {
                   //是否多链接确认--负载均衡  //端口输出处理---数据尾不需要判断多链接

                   if(ptr[x].id==secondElement)
                   {

                       string  outputdata;
                       outputdata.clear();
                       linkdata data1,data2;
                       int inputport=0,outputport=0;
                       bool data1_f=0,data2_f=0;
                       bool flag_w=0;   //如果多链接情况，不希望进入不是多链接的条件下
                       for (auto& pair : ptr[x].linkdatas)
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

                               if(data2.type==input_nodetype&&data2.serialnumber==temp_input&&data1.serialnumber==ptr[x].id1)
                               {
                                   inputport=data1.port;
                                  //  cout <<" ------in"<<inputport;
                                   data1_f=1;
                               }
                           }

                           if(data2.serialnumber==temp_output&&data1.serialnumber==ptr[x].id1&&data2.type==output_nodetype)
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
                       break;
                   }
               }
           }
           else
           {    //需要加入判断多链接的情况
               temp_output=0;
               temp_input=0;
//               output_nodetype=0;
//               input_nodetype=0;

               if(i<1)
               {  //计算结点和交换机结点情况
                   temp_input=temp_star;
                   extractNumber(threeElement,temp_output);
                   input_nodetype=2;
                   output_nodetype=1;
                   for (int x=0;x<switchnodenum;x++)
                   {
                       //是否多链接确认--负载均衡  //端口输出处理---不需要判断多链接--（计算结点和当前交换机结点没有多链接关系）

                       if(ptr[x].id==secondElement)
                       {
                           string  loardinformation;
                           loardinformation.clear();
                           int inport=0,outport=0,targetnum=0;
                           string information=outputswitch_pathport_other(ptr[x],target,temp_output,output_nodetype,temp_input,\
                                                                          input_nodetype,loardinformation,nextportdata,flag_next_inputport1,inport,outport,targetnum);

                           //                            if(flag_next_inputport1)
                           //                            {   string  temp;
                           //                                temp.clear();
                           //                                 temp.append("loadbalance: ");
                           //                                temp.append(loardinformation);
                           //                                queue.enqueue(temp);
                           //                            }
                           queue.enqueue(information);
                        break;
                       }
                   }
               }
               else
               {      //中间部分拿端口
                   extractNumber(firstElement,temp_input);
                   extractNumber(threeElement,temp_output);
                   input_nodetype=1;  //后期改用数据赋值
                   output_nodetype=1;
                   for (int x=0;x<switchnodenum;x++)
                   {
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
                       if(ptr[x].id==secondElement)
                       {
                           if(ptr[x].is_multilink)
                           {
                               //输出端口确认:如：1-30：“13”

                               string outputlinknum;
                               outputlinknum.clear();
                               temp_outputlinkdata.clear();
                               outputlinknum.append(std::to_string(ptr[x].id1));
                               outputlinknum.append(std::to_string(temp_output));
                               //找到该输出端口-输出选择的链接
                               for ( LoadBalancer &lb : ptr[x].p1)
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
                           for (auto& pair : ptr[x].linkdatas)
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
                                  if(data2.type==input_nodetype&&data2.serialnumber==temp_input&&data1.serialnumber==ptr[x].id1)
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
                                   if(data2.type==input_nodetype&&data2.serialnumber==temp_input&&data1.serialnumber==ptr[x].id1)
                                   {
                                       inputport=data1.port;
                                      // cout<<" ------------inin1"<<inputport;
                                       data1_f=1;
                                   }
                               }

                                //输出端口
                               if((!mutil2_f)&&ptr[x].is_multilink&&(!temp_outputlinkdata.empty()))
                                 { //多链接
                                   std::vector<int>  tempdata;
                                   linkdata data3,data4;
                                   tempdata.clear();
                                   tempdata=extractNumbers(temp_outputlinkdata);
                                   extractNumber(tempdata,data3,data4);  //处理的数据
                                    if(data3.serialnumber==ptr[x].id1&&data4.serialnumber==temp_output&&data4.type==output_nodetype)
                                    {
                                      mutil2_f=1;
                                      flag_havedoutputport=1;
                                      outputport=data3.port;
                                      nextportdata1.nextnode_inputport=data4.port;  //下一个输入端口缓存
                                      nextportdata1.currctnode_name=ptr[x].id;
                                      flag_next_inputport2=1;
                                    }
                               }
                               else
                               {
                                   if(!flag_havedoutputport)
                                   if(data2.serialnumber==temp_output&&data1.serialnumber==ptr[x].id1&&data2.type==output_nodetype)
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
                           if(ptr[x].is_multilink&&ptr[x].is_limitport_swit)
                            {
                              string  port_targetanme;
                              port_targetanme.clear();
                              port_targetanme.append(std::to_string(inputport));
                              port_targetanme.append("-");
                              port_targetanme.append(target);
                              mulitport_handle_limit  tempdata,output_data ;
                              tempdata.inport=inputport;
                              tempdata.switchname=ptr[x].id;
                              tempdata.targename=target;
                              //如某路径：sw：1-4-151-10-7 ：4 的输出没有多链接了，只有一个端口到151，直接输出端口，不需要记录
                                bool flag=false;
                                if(!temp_outputlinkdata.empty())
                                {   tempdata.previous_outport_link=temp_outputlinkdata;
                                    //数据记录or数据对比(当前数据--决策输出规则)
                                    flag=loadbalance_mutilport_limithandle(port_targetanme,tempdata,output_data,ptr[x].getnextserver_record,inputport,target);
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
                                   nextportdata1.currctnode_name=ptr[x].id;

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
                           break;
                       } //if
                   } //for
               }
           }
           //    std::cout << "First: " << firstElement << ", Second: " << secondElement << std::endl;
       }
   }
  }

}
#endif


string  showpath_dijkstra (const std::vector<string> path,const int distance)
{
    string pathinformation;
    pathinformation.clear();

    cout<<"path:";
    pathinformation.append("path:");
    cout<<"size"<<path.size();

    for (const auto& neighbor : path)
    {
        cout<<"-"<<neighbor;
        pathinformation.append("-");
        pathinformation.append(neighbor);
    }
    cout<<"\n";
    cout<<"distance:"<<distance;
    return pathinformation;
}

#if write
bool  calculates_and_save_allendnode_shortpath(int endnodenum,Graph<string> &g,switch_node *ptr,int switchnodenum,endnode_node *ptr1,int endnodenum1,\
                                               moodycamel::ConcurrentQueue<forword> &saverule_conqueque\
                                     ,std::unordered_map<std::string, std::ofstream> &fileStreams,\
                                      std::unordered_multimap<std::string,forword_handle> &mulmap)
{

    for (int i = 0; i <= endnodenum; ++i)
    {
        for (int j = 0; j <= endnodenum; ++j)
        {
            std::string  outputinformation;
            outputinformation.clear();
            std::vector<string>  path;
            path.clear();
            int distance=0;
            string star="endnode"; //endnode
            star.append(std::to_string(i));
            string target="endnode";  //targetnode
            target.append(std::to_string(j));
            if(star!=target)
            {
                path=dijkstra(g,star,target,distance);
                //path=bfsShortestPath(g,star,target);
            }

             rulseissued_from_dijkstra(path,ptr,switchnodenum,ptr1,endnodenum1,star,target,mulmap);

             //把队列数据写入每个文件
//             forword_rule items;
//             while (saverule_conqueque.try_dequeue(items))
//             {
//                 // 获取当前数据的 switchname 和 forword_rule
//                 std::string switchname = items.switchname;
//                 std::string forword_rule = items.forword_rule;
//                 // 检查是否已经为当前 switchname 打开了文件流
//                 if (fileStreams.find(switchname) == fileStreams.end()) {
//                     // 如果没有打开文件流，则打开一个新文件以追加数据
//                     std::string filePath = outputfile_write_infile + switchname + ".txt";
//                     fileStreams[switchname].open(filePath, std::ios::app);
//                 }
//                 // 将数据写入相应的文件
//                 fileStreams[switchname] << forword_rule << std::endl;
//            }

        }
    }
    //遍历哈希map
    for (auto it = mulmap.begin(); it != mulmap.end(); ++it)
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





