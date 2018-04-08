#pragma execution_character_set("utf-8")

#ifndef LABELTOOL_H
#define LABELTOOL_H


#include <QtWidgets/QMainWindow>
#include "ui_labeltool.h"
#include<qlayout.h>
#include<iostream>
#include<qstring.h>
#include<string>
#include<qfiledialog.h>
#include<core.hpp>
#include<cv.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include<qmessagebox.h>
#include<vector>
#include<MyLabel.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>  
#include<qstringlist.h>
#include<cstdio>  
#include<map>
using namespace std;
using namespace cv;


class LabelTool : public QMainWindow
{
	Q_OBJECT

public:
	LabelTool(QWidget *parent = 0);
	~LabelTool();

	void setConnections();

public:
	QWidget *widget;
	QVBoxLayout *verticalLayout;
	QWidget* centralWidget;
 
	MyLabel* myLabel;

	QString fileName;
	int labeled_image ;
	vector<vector<int>> labels;
	Mat src ;
	double rate;

	double zoom_percent;

	void showLabel();
	void showLabel(QString label_path);
	void clearAll();
	void showImage(QString path);
	
	QString numbers;

	vector<QString> files;
	map<QString,QString> labeld_files;
	map<QString,QString>::iterator label_files_pointer;
	int current_index;
	void changeLabelsToPoints();
private:
	Ui::LabelToolClass ui;
public slots:
	bool openImgSlot();
	bool openDirSlot();
	void openLabelSlot();
	void labelSlot();
	void clearLabelSlot();
	void saveLabelSlot();
	bool getNextImageSlot();
	void rotateImageSlot();

	void imageZoomInSlot();
	void imageZoomOutSlot();
	void deleteImageSlot();

	bool openLabelDirSlot();
	void getNextLabeledImageSlot();
};

#endif // LABELTOOL_H
