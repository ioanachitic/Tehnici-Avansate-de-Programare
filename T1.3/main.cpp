#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int main()
{
    ifstream f("date.txt");
    ofstream g("output.txt");
    int nr, i, b, p, ok;
    f>>nr;

    vector<vector<int>> lista;

    for(i = 0; i < nr; i++)
    {
        if(lista.size()==0)
            {f>>b;
            vector<int> a;
            a.push_back(b);
            lista.push_back(a);}
        else
        {
            p = 0;
            ok = 0;
            while(p<lista.size())
            {
                vector<int> c = lista[p];
                if (c.back() > b)
                {
                    c.push_back(b); ok = 1; break;
                }
                p++;
            }
        if (ok == 0)
        {
            vector<int> a;
            a.push_back(b);
            lista.push_back(a);
        }
        }
    }

    while(lista.size()!=0)
    {
        vector<int> c = lista.front();
        while (c.size()!=0)
        {
            g<<c.front()<<" ";
            c.pop_back();
        }
    }



    return 0;
}
