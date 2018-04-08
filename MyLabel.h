#ifndef MYLABEL_H
#define MYLABEL_H

#include<qwidget.h>
#include<qlabel.h>
#pragma execution_character_set("utf-8")
#include<qpainter.h>
#include<vector>
#include<iostream>
#include<qmouseeventtransition.h>
#include <QtWidgets/QMainWindow>
#include <QtWidgets\qwidget.h>
#include<qevent.h>
//#include<labeltool.h>
using namespace std;

class MyLabel:public QLabel{
	Q_OBJECT
public:
	MyLabel(QWidget *parent=0);
	//MyLabel(QWidget *parent,LabelTool* labelTool);
	~MyLabel();

	
protected:
	void mousePressEvent(QMouseEvent *event); 
    void mouseMoveEvent(QMouseEvent *event); 
    void mouseReleaseEvent(QMouseEvent *event); 
	void paintEvent(QPaintEvent *event);
public:
	void paintPoints();
	void paintLines();
	void showTruth();
	
public:
	vector<QPoint*> points;
	//LabelTool* labelTool;
};

#endif