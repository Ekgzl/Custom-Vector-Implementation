#include <iostream>
#include <vector>
using namespace std;

template<class T>
class Vector
        {
        private:
            T* data;
            int index;
            int length;

            void reset(int index = 0,int length = 1)
            {
                delete[] data;
                data = nullptr;
                this->index = index;
                this->length = length;
            }
        public:

            ~Vector()
            {
                reset();
            }

            Vector() : data(nullptr),index(0),length(1)
            {
                data = new T[length];
            }

            Vector(int n,const T& t = T()) : Vector<T>()
            {
                for (int i = 0; i < n; ++i)
                {
                    push_back(t);
                }
            }

            Vector(T* first,T* last) : Vector<T>()
            {
                while (first != last)
                {
                    push_back(*first);
                    cout << "*";
                    first++;
                }


            }

            Vector(Vector<T>& rhs)
            {
                *this = rhs;
            }

            int size()
            {
                return index;
            }

            int capacity()
            {
                return length;
            }



            void push_back(const T& value)
            {
                if(size()>=capacity())
                {
                    length *= 2;
                    T* tmp = new T[length];

                    for (int i = 0; i < index; ++i)
                    {
                        tmp[i] = data[i];
                    }
                    delete[] data;
                    data = tmp;
                    data[index++] = value;
                }
                else
                {
                    data[index++] = value;
                }
            }

            void pop_back()
            {
                index--;
                if(size()<= capacity()/2)
                {
                    length /= 2;
                    T* tmp = new T[length];
                    for (int i = 0; i < length; ++i)
                    {
                        tmp[i] = data[i];
                    }
                    delete[] data;
                    data = tmp;
                }
            }


            void insert(T* pos,T val)
            {
                if(pos>= begin() && pos <= end())
                {
                    int index = pos-begin();
                    push_back(val);
                    for (int i = size()-1; i > index; --i)
                    {
                        T temp;
                        temp = data[i];
                        data[i] = data[i-1];
                        data[i-1] = temp;
                    }
                }
                else
                    throw "Error!";

            }

            void clear()
            {
                reset();
                data = new T[length];
            }

            void insert(T* pos,int n, T val)
            {
                if(pos>=begin() && pos <= end())
                {
                    int index = pos - begin();
                    for (int i = 0; i < n; ++i)
                    {
                            insert(begin()+index+i,val);
                    }
                }
            }

            void insert(T* pos,T* first,T* last)
            {
             if(pos>=begin() && pos<= end())
             {
                 int index = pos-begin();
                 int i = 0;
                 while(first != last+1)
                 {
                     insert(begin()+index+i,*(first));
                     i++;
                     first++;
                 }
             }
            }

            void erase(T* pos)
            {
                if(begin()<=pos && end()>=pos)
                {
                    int index = pos-begin();
                    for (int i = index; i < size(); ++i)
                    {
                        data[i] = data[i+1];
                    }
                    pop_back();
                }
                else
                    throw "Error : Vectore erase.";
            }

            void erase(T* begin_,T* end_)
            {
                int f = begin_ - begin();
                int l = end_ - end();
                    while (begin_!=end_+1)
                    {
                        erase(f+begin());
                        begin_++;
                    }
            }


            T* begin()
            {
              return data;
            }

            T* end()
            {
                return data + size();
            }

            T back()
            {
                return data[index-1];
            }

            T front()
            {
                return data[0];
            }

            T& at(int indis)
            {
                return data[indis];
            }

            T& operator[](int indis)
            {
                return at(indis);
            }

            Vector<T>& assign(Vector<T>& rhs)
            {
                reset(rhs.size(),rhs.capacity());
                data = new T[capacity()];
                for (int i = 0; i < size(); ++i) {
                    data[i] = rhs.data[i];
                }
                return *this;
            }

            Vector<T>& operator=(Vector<T>& rhs)
                    {
                        return assign(rhs);
                    }
        };


int main()
{
    Vector<int> v1;
    v1.push_back(7);
    v1.push_back(100);
    v1.push_back(250);
    v1.push_back(230);
    Vector<int> v(v1.begin()+1,v1.begin()+4);
    cout << "size: " << v.size() << endl;
    cout <<"capacity:" << v.capacity() << endl;

    int *begin = v.begin();
    int *end = v.end();

    while (begin != end)
    {
        cout << *begin++ << " ";
    }



}