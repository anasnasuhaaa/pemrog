#include <iostream>
using namespace std;

class Counter
{
private:
    int val;

public:
    void setVal(int n)
    {
        val = n;
    };
    void add()
    {
        val++;
    }
    void min()
    {
        val--;
    }
    int getVal()
    {
        return val;
    }
};

int main()
{
    int input;
    int init;
    Counter obj;
    while (cin >> input && input != -9)
    {
        if (input == 0)
        {
            cin >> init;
            obj.setVal(init);
        }
        else if (input == 1)
        {
            obj.add();
        }
        else if (input == -1)
        {
            if (obj.getVal() > 0)
            {
                obj.min();
            }
            else
            {
                continue;
            }
        }
        else if (input == 9)
        {
            cout << obj.getVal() << endl;
        }
    }
    return 0;
}