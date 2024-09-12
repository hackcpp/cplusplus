#include <iostream>
#include <string>
/*
装饰器模式：
解决的问题： 在基础类上存在多维度功能的扩展，通过继承的方式会导致子类的‘组合爆炸’
 */

class Stream {
    public:
    virtual std::string read() = 0;
};

class FileStream: public Stream {
    public:
    std::string read() {
        std::cout << "FileStream::read" << std::endl;
        return "";
    }
};

class NetworkStream: public Stream {
    public:
    std::string read() {
        std::cout << "NetworkStream::read" << std::endl;
        return "";
    }
};

class MemoryStream: public Stream {
    public:
    std::string read() {
        std::cout << "MemoryStream::read" << std::endl;
        return "";
     }
};

class BufferedStream: public Stream {
    public:
    BufferedStream(Stream* s): mSteam(s) {}
    virtual std::string read() {
        //..buffer
        return DoBuffer(mSteam->read());
    }
    private:
    std::string DoBuffer(const std::string&) {
        std::cout << "DoBuffer" << std::endl;
        return "";
    }
    private:
    Stream* mSteam = nullptr;
};

class CryptoStream: public Stream {
    public:
    CryptoStream(Stream* s): mSteam(s) {}
    virtual std::string read() {
        //..Crypto
        return DoCrypto(mSteam->read());
    }
    private:
    std::string DoCrypto(const std::string&) {
        std::cout << "DoCrypto" << std::endl;
        return "";
    }
    private:
    Stream* mSteam = nullptr;
};

int main() {
    FileStream* fs = new FileStream();
    BufferedStream* bfs = new BufferedStream(fs);
    bfs->read();
    CryptoStream* cfs = new CryptoStream(fs);
    cfs->read();

    CryptoStream* cbfs = new CryptoStream(bfs);
    cbfs->read();
}