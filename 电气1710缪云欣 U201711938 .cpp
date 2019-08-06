#include<cstdio>
#include<iostream>
#include<cmath> 
#include<algorithm>

using namespace std;

class Rect{
    public:
        double width;
        double height;
        Rect(double w,double h);
        Rect();
        double area()
        {
            return width*height;
        }
        double perimeter()
        {
            return (width+height)*2;
        }
        double length()
        {
        	return sqrt(width*width+height*height);
		}
};

Rect::Rect(double w,double h) 
{
    width=w;
    height=h;
}

Rect::Rect()
{
    width=10;
    height=10;
}

class PlainRect: public Rect{
    public:
        double startX;
        double startY;
        PlainRect(double s_X,double s_Y,double w,double h);
        PlainRect();
        int isInside(double x,double y)
        {
            if((x>startX)&&(x<=(startX+width))&&(y<=startY)&&(y>=startY-height)) 
				return 1;
			if((x<startX)||(x>(startX+width))||(y>startY)||(y<startY-height))
				return -1;
			return 0;
        }
};

PlainRect::PlainRect(double s_X,double s_Y,double w,double h)
{
    startX=s_X;
    startY=s_Y;
    width=w;
    height=h;
}

PlainRect::PlainRect()
{
    startX=0;
    startY=0;
    width=0;
    height=0;
}

int main()
{
	cout<<"\t��ӭ����С�ѵĳ���:)"<<endl; 
	cout<<"��������ε�4����ز��� ���Ͻǵ����� �� ��"<<endl;
	cout<<"������\"E\"�˳�����"<<endl;
	double sx,sy,w,h;
	while(cin>>sx>>sy>>w>>h)
	{
		PlainRect my_plain(sx,sy,w,h);
		cout<<"\t�þ��ε������"<<my_plain.area()<<"��"<<endl;
    	cout<<"\t�þ��ε��ܳ���"<<my_plain.perimeter()<<"��"<<endl;
		cout<<"\t�þ��εĶԽ��߳���"<<my_plain.length()<<"��"<<endl; 
		double xx,yy;
		cout<<"�Ƿ���Ҫ�жϵ���þ��ε�λ�ù�ϵ��\n\t1.��\t2.��"<<endl;
		int op;
		while(cin>>op&&op==1)
		{
			cout<<"������õ��ƽ�����ꡣ"<<endl; 
			cin>>xx>>yy;
			if(my_plain.isInside(xx,yy)==1)
				cout<<"\t��("<<xx<<","<<yy<<")"<<"λ�ھ����ڲ����������߽磩��"<<endl;
			else
			{ 
				if(my_plain.isInside(xx,yy)==0)
					cout<<"\t��("<<xx<<","<<yy<<")"<<"λ�ھ��εı߽��ϡ�"<<endl;
				else 
					cout<<"\t��("<<xx<<","<<yy<<")"<<"λ�ھ����⡣"<<endl;			
			}
			cout<<"�Ƿ���Ҫ�����жϵ���þ��ε�λ�ù�ϵ��\n\t1.��\t2.��"<<endl;
		}
		cout<<"��������ε���ز���"<<endl;
		cout<<"������\"E\"�˳�����"<<endl;
	}
	cout<<"ллʹ�á�"<<endl; 
    return 0;
}



