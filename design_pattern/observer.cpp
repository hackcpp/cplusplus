
/*
观察者模式： 用于对象之间的“消息通知”
*/

#include <iostream>

class IProgress {
    public:
    virtual void DoProgress(float value) = 0;
};

class FileSpliter {
public:
    void splitFile() {
        for (int i = 0; i < 100; i++) {
            //....
            if (mIProgress) mIProgress->DoProgress((i+1)*100/100);
        }
    }
    void setProgress(IProgress* progress) {mIProgress = progress;}
private:
    IProgress* mIProgress = nullptr;
};

class MainForm: public IProgress{
    public:
    void DoProgress(float value) override {
        std::cout << value << std::endl;
    }
};

int main() {
    FileSpliter spliter;
    MainForm form;
    spliter.setProgress(&form);
    spliter.splitFile();
}

