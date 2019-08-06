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
	cout<<"\t欢迎来到小缪的程序:)"<<endl; 
	cout<<"请输入矩形的4个相关参数 左上角点坐标 长 宽"<<endl;
	cout<<"或输入\"E\"退出程序。"<<endl;
	double sx,sy,w,h;
	while(cin>>sx>>sy>>w>>h)
	{
		PlainRect my_plain(sx,sy,w,h);
		cout<<"\t该矩形的面积是"<<my_plain.area()<<"。"<<endl;
    	cout<<"\t该矩形的周长是"<<my_plain.perimeter()<<"。"<<endl;
		cout<<"\t该矩形的对角线长是"<<my_plain.length()<<"。"<<endl; 
		double xx,yy;
		cout<<"是否需要判断点与该矩形的位置关系？\n\t1.是\t2.否"<<endl;
		int op;
		while(cin>>op&&op==1)
		{
			cout<<"请输入该点的平面坐标。"<<endl; 
			cin>>xx>>yy;
			if(my_plain.isInside(xx,yy)==1)
				cout<<"\t点("<<xx<<","<<yy<<")"<<"位于矩形内部（不包括边界）。"<<endl;
			else
			{ 
				if(my_plain.isInside(xx,yy)==0)
					cout<<"\t点("<<xx<<","<<yy<<")"<<"位于矩形的边界上。"<<endl;
				else 
					cout<<"\t点("<<xx<<","<<yy<<")"<<"位于矩形外。"<<endl;			
			}
			cout<<"是否需要继续判断点与该矩形的位置关系？\n\t1.是\t2.否"<<endl;
		}
		cout<<"请输入矩形的相关参数"<<endl;
		cout<<"或输入\"E\"退出程序。"<<endl;
	}
	cout<<"谢谢使用。"<<endl; 
    return 0;
}



