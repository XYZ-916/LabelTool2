#include<MyLabel.h>

MyLabel::MyLabel(QWidget* parent):QLabel(parent)
{
	
}

/*
MyLabel::MyLabel(QWidget *parent,LabelTool* labelTool):QLabel(parent)
{
	this->labelTool = labelTool;
}
*/

MyLabel::~MyLabel()
{

}


void MyLabel::paintEvent(QPaintEvent *event)
{
	QLabel::paintEvent(event);//先调用父类的paintEvent为了显示'背景'!!!  

	paintPoints();
	paintLines();
}


void MyLabel::paintPoints()
{
	QPainter painter(this);
	QBrush brush(QColor(0,0,255));
	painter.setBrush(brush);

	double width = this->width();
	double height = this->height();

	for(int i=0;i<points.size();i++)
	{
		QPoint* p = points[i];
		
		painter.drawEllipse(*p,6,6);
	}
}

void MyLabel::paintLines(){
	if(points.size()<=1)
		return;


	QPainter painter(this);
    QBrush brush(QColor(255,0,0));
	painter.setBrush(brush);

	for(int i=0;i<points.size()-1;i++)
	{
		QPoint* p1 = points[i];
		QPoint* p2 = points[i+1];
		painter.drawLine(*p1,*p2);
	}

	if(points.size()==4)
	{
		QPoint* p1 = points[3];
		QPoint* p2 = points[0];
		painter.drawLine(*p1,*p2);
	}
}


//点的点可能不在图像上
void MyLabel::mousePressEvent(QMouseEvent *event)
{
	//以左上角为原点
	if (event->button() == Qt::LeftButton){
		QPoint p = event->pos();
		QPoint *pp = new QPoint(p.x(),p.y());

		if(points.size()>4)
			points.clear();
			
		points.push_back(pp);
	}

	update();

	//labelTool->showLabel();
}

void MyLabel::mouseMoveEvent(QMouseEvent *event) 
{ 
  //  QPoint p = event->pos();  
}

void MyLabel::mouseReleaseEvent(QMouseEvent *event) 
{ 
       // QPoint p = event->pos(); 
} 

void MyLabel::showTruth()
{
	//ui.lineEdit
}