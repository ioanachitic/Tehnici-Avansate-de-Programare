#include <iostream>
#include <fstream>
#include <vector>
#include<algorithm>
using namespace std;

class Segment
{   private:
    int m_x, m_y;

    public:
    Segment()
    {
        m_x=0;
        m_y=0;
    }
    Segment(int x, int y)
    {
        m_x=x;
        m_y=y;
    }

    int getX() {return m_x;}
    int getY() {return m_y;}
    bool operator < (const Segment& seg) const
    {
        return (m_x < seg.m_x);
    }
};

int main()
{
    ifstream f("date.txt");
    ofstream g("output.txt");

    int x, y, nr, i;
    f>>x>>y;

    Segment seg(x,y);
    f>>nr;

    vector<Segment> s;
    for (i=0; i<nr; i++)
    {
        f>>x>>y;
        s.push_back(Segment(x,y));
    }
    sort(s.begin(), s.end());

    int aux1, aux2, j = 0;
    aux1 = s[0].getX();
    aux2 = s[0].getY();

    for(int i=1;i<nr;i++)
    if(s[i].getX()<=seg.getX())
        {  if(s[i].getX()>=aux1 && (s[i].getY()>=aux2 || s[i].getY()<=seg.getY()) )
        {aux1=s[i].getX(); j=i;
        aux2=s[i].getY();}
        }
    g<<s[j].getX()<<" "<<s[j].getY()<<endl;

    for(int i=j+1;i<nr;i++)
        {if(s[i].getX()>aux1 && s[i].getY()>aux2 && aux2>=s[i].getX())
        {  if( !(s[i].getX()==s[i+1].getX() && s[i+1].getY()>s[i].getY())){
            aux1=s[i].getX();

            aux2=s[i].getY();
             g<<s[i].getX()<<" "<<s[i].getY()<<endl;
                }}}

    return 0;
}

