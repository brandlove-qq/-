#ifndef LOADBALANCE_H
#define LOADBALANCE_H
#include <iostream>
#include <vector>
/**********************************************************************************************!
  *@author:    wuxxxxx
 * @brief:     板内多链接端口负载均衡类算法------------------------轮询法
 * @date:     2023/08/07
 * @param:
 *  注：提供给后期多链接接口规则下发使用，多连接考虑端口口均衡
 *    本系统使用在nrm20p（hnr）交换机多连接：四个端口均衡
*/

class LoadBalancer
{

public:
    LoadBalancer() {}
    LoadBalancer(const std::vector<std::string>& servers,const std::string port) :\
        port_soure_target(port),servers_(servers),currentIdx_(0)
    {}

    ~LoadBalancer()
    {

    }
    // 返回一个链路
    std::string getNextServer()
    {
        if (servers_.empty())
        {
            std::cout<<"link empty!";
            return ""; // 链路列表为空，返回空字符串表示没有可用链路
        }

        // 获取当前索引对应的链路名，并将索引循环更新
        std::string serverName = servers_[currentIdx_];
        currentIdx_ = (currentIdx_ + 1) % servers_.size();

        return serverName;
    }


  std::string  port_soure_target;  //多链接端口
  std::vector<std::string> servers_; //链路列表
private:

    size_t currentIdx_; // 当前索引
};

/*----测试
 int main()
{
    std::vector<std::string> servers = {"n0", "n1", "n2", "n3"};
    LoadBalancer loadBalancer(servers);

    // 模拟调度过程，连续调用 getNextServer() 函数来获取链路名
    for (int i = 0; i < 10; ++i)
    {
        std::string server = loadBalancer.getNextServer();
        std::cout << "Request " << i + 1 << " is routed to server: " << server << std::endl;
       // std::cout<<loadBalancer.currentIdx_;
    }

    return 0;
}
*/

#endif // LOADBALANCE_H
