#include<iostream>
using namespace std;

template<class t>
class list
{
protected:
    t* arr;
    int maxsize;
    int currentsize;
public:
    list(int s) :maxsize(s)
    {
        arr = new t[s];
        currentsize = 0;
    }
    list(list& c)
    {
        if (this != &c)
        {
            maxsize = c.maxsize;
            currentsize = c.currentsize;
            arr = new t[maxsize];
            for (int i = 0; i < currentsize; i++)
            {
                arr[i] = c.arr[i];
            }
        }
    }
    virtual void addElement(t s) = 0;
    virtual t removeElement() = 0;
    virtual ~list() 
    {
        delete[] arr;
        cout << "~list()" << endl;
    }

};

template<class t>

class Mylist :public list<t>
{
public:
    Mylist(int s) :list<t>(s)
    {}
    void addElement(t s)
    {
        if (!full())
        {
            list<t>::arr[list<t>::currentsize] = s;
            list<t>::currentsize++;
        }
        else
        {
            cout << "List is full" << endl;
        }
    }
    t removeElement()
    {
        if (!empty())
        {
            list<t>::currentsize--;
            return list<t>::arr[list<t>::currentsize];
        }
        else
            cout << "List is empty" << endl;
        return 0;
       
        
    }
    bool empty()
    {
        if (list<t>::currentsize == 0)
        {
            return true;
        }
        return false;
    }
    bool full()
    {
        if (list<t>::maxsize == list<t>::currentsize)
        {
            return true;
        }
        return false;
    }
    int size()
    {
        return list<t>::currentsize;
    }
    t last()const
    {
        if (this->currentsize == 0)
        {
            cout << "Array is empty" << endl;
            return 0;
        }
        return list<t>::arr[list<t>::currentsize - 1];
    }
    t& operator[](int index)
    {
        if (index < 0 || index >= list<t>::currentsize)
        {
            cout << "Index out of range" << endl;
            return list<t>::arr[0];
        }
        return list<t>::arr[index];
    }
    bool operator =(const Mylist& c)
    {
        return(list<t>::arr = c.arr);
        return(list<t>::maxsize = c.maxsize);
        return(list<t>::currentsize = c.currentsize);
    }
    ~Mylist()
    {
        cout << "~Mylist()" << endl;
    }
};


template<typename t>
void showlist(Mylist<t>& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;

    }
}

int main()
{
    Mylist<int> intarr(10);
    cout << intarr.size() << endl;
    cout << intarr.removeElement() << endl;
    intarr.addElement(45);
    intarr.addElement(-9);
    intarr.addElement(3);
    intarr.addElement(0);
    intarr.addElement(1);
    intarr.removeElement();
    intarr.empty();
    intarr.last();
    showlist(intarr);
    cout << endl;

    Mylist<char> chararr(2);
    chararr.addElement('H');
    chararr.addElement('A');
    showlist(chararr);
    cout << endl;

    Mylist<string> stringarr(20);
    stringarr.addElement("UCP");
    stringarr.addElement("Hassan");
    stringarr.addElement("Jamshaid");
    showlist(stringarr);
    cout << endl;

    return 0;
}
