#include <iostream>

/*
策略模式： 
- 用于处理算法层面的变化(代码上存在很多if else)

计算不同水果价格的系统：
if apple:
   ...
else if balala:
  ...
  ...   
*/

struct context
{
    /* data */
    double num;   //数量
    double price; // 单价
    //...
};

class FruitStrategy {
    public:
    virtual double caculate(const context& ctx) = 0;
};

class AppleStrategy: public FruitStrategy {
public:
    double caculate(const context& ctx) override {return ctx.num * ctx.price;}
};

class FruitPriceCa {
public:
    void SetStrategy(FruitStrategy* s) {mStrategy = s;}
    double Sumprice(const context& ctx) {return mStrategy->caculate(ctx);}
private :
    FruitStrategy* mStrategy = nullptr;
};

int main() {
    context ctx;
    FruitPriceCa fruitPriceCa;
    auto straegy = new AppleStrategy();
    fruitPriceCa.SetStrategy(straegy);
    std::cout << fruitPriceCa.Sumprice(ctx);
    delete straegy;
}
