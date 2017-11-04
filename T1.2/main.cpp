#include <iostream>
#include <fstream>
#include <vector>
#include<algorithm>
using namespace std;

class Activitate{
  private:
      int m_t, m_d, m_ord; //m_d durata, m_t termen limita
  public:
    Activitate()
    {
        m_t = 0; m_d = 0; m_ord = 0;
    }
    Activitate(int t, int d, int ord)
    {
        m_t = t; m_d = d; m_ord = ord;
    }

    int getOrd() {return m_ord;}
    int getT() {return m_t;}
    int getD() {return m_d;}
  bool operator < (const Activitate& act) const
    {
        return (m_t < act.m_t);

    }
};

int main()
{
    ifstream f("date.txt");
    ofstream g("output.txt");

    int x, y, nr, i, t = 0, j, max = 0;
    vector<Activitate> s;
    f>>nr;

    for (i = 0; i < nr; i++)
    {
        f>>x>>y;
        s.push_back(Activitate(x,y,i));
    }
    sort(s.begin(), s.end());

    for (j = 0; j < nr; j++)
    {
        g<<"Activitatea: "<<s[j].getOrd()<<endl;
        g<<"Intervalul: "<<t<<" "<<t + s[j].getD()<<endl;
        g<<"Intarziere: "<<t + s[j].getD() - s[j].getT()<<endl;

    if ( max < t+s[j].getD() - s[j].getT() )
			 max = t+s[j].getD() - s[j].getT();
     t = t + s[j].getD();
    }

    g<<"Intarzierea maxima: "<<max;

    return 0;
}
