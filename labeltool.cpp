#include "labeltool.h"

#define ZOOM_RATE 0.2  //ÿ�ηŴ����С0.2

std::vector<std::string> mysplit(std::string str,std::string pattern);

LabelTool::LabelTool(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	ui.horizontalLayout->setStretchFactor(ui.widget, 4);
	ui.horizontalLayout->setStretchFactor(ui.verticalLayout,1);
	myLabel = ui.label;

	setConnections();

	zoom_percent = 0;//��Ϊ�Ŵ󣬸�Ϊ��С
}

void LabelTool::setConnections(){
	connect(this->ui.actionOpen, SIGNAL(triggered()), this, SLOT(openImgSlot()));
	connect(this->ui.actionOpen_Dir, SIGNAL(triggered()), this, SLOT(openDirSlot()));
	connect(this->ui.actionOpen_label, SIGNAL(triggered()), this, SLOT(openLabelSlot()));

	connect(this->ui.action_label_dir, SIGNAL(triggered()), this, SLOT(openLabelDirSlot()));
	

	connect(this->ui.actionLabel, SIGNAL(triggered()), this, SLOT(labelSlot()));
	connect(this->ui.pushButton_clear, SIGNAL(clicked()), this, SLOT(clearLabelSlot()));
	connect(this->ui.pushButton_save, SIGNAL(clicked()), this, SLOT(saveLabelSlot()));
	
	connect(this->ui.pushButton_next, SIGNAL(clicked()), this, SLOT(getNextImageSlot()));
	connect(this->ui.pushButton_next_labeled_image, SIGNAL(clicked()), this, SLOT(getNextLabeledImageSlot()));
	connect(this->ui.pushButton_rotate, SIGNAL(clicked()), this, SLOT(rotateImageSlot()));
	
	connect(this->ui.pushButton_larger, SIGNAL(clicked()), this, SLOT(imageZoomInSlot()));
	connect(this->ui.pushButton_smaller, SIGNAL(clicked()), this, SLOT(imageZoomOutSlot()));

	connect(this->ui.pushButton_delete, SIGNAL(clicked()), this, SLOT(deleteImageSlot()));
	
	ui.pushButton_larger->setHidden(true);
	ui.pushButton_smaller->setHidden(true);
}

LabelTool::~LabelTool()
{

}

void LabelTool::clearAll()
{
	myLabel->points.clear();
	labels.clear();

	clearLabelSlot();


	ui.statusBar->showMessage("");

	//�ָ�label�����С
	ui.label->setFixedWidth(800);
	ui.label->setFixedHeight(600);
}

void LabelTool::showImage(QString path)
{
	
	clearAll();

	fileName = path;

	string file_path = path.toLocal8Bit().data();
	src = imread(file_path);
	
	if(!src.data)
    {
        QMessageBox::warning(this, tr("Error"),tr("Cannot read file %1\n").arg(fileName));
        return ;
    }
   
    //�ı��ɫͨ��˳��
    cv::cvtColor(src, src, CV_RGB2BGR);

    //��ʼ��QImage����
    QImage img = QImage((const unsigned char*)(src.data), src.cols, src.rows, QImage::Format_RGB888);
		
		
	float width = img.width();
	float height = img.height();
	
	float label_width = myLabel->width();
	float label_height = myLabel->height();

	float scale_w = label_width /width;  //��ı���    
	float scale_h = label_height/ height;  //�ߵı���

	float new_width = width;
	float new_height = height;

	rate = 1;// rate<=1

	if(scale_w<1 || scale_h<1)
	{
		if(scale_h<scale_w)//�߶ȹ̶�
		{
			new_height = label_height;
			rate = scale_h;
			new_width = width*rate;
		}
		else{
			new_width = label_width;
			rate = scale_w;
			new_height = height*rate;
		}
	}

	ui.label->setFixedWidth(new_width);
	ui.label->setFixedHeight(new_height);

	/*
	if(width>height)//��ȹ̶�


	float label_width = myLabel->width();//�̶�800
	float label_height = label_width*height/width;
	ui.label->setFixedHeight(label_height);
	update();

	//float label_height = myLabel->height();
	rate = label_width /width;  //��ı���    

	float new_width = width*rate;
	float new_height = height*rate;
	*/
	img = img.scaled(new_width,new_height,Qt::KeepAspectRatio);
	update();

    //��ʾ��label��
	myLabel->setPixmap(QPixmap::fromImage(img));
        //�ı�label�Ĵ�С��������Ӧͼ���С
	//myLabel->resize(myLabel->pixmap()->size());
    
	float test = myLabel->height();

	ui.statusBar->showMessage(fileName);
}

bool LabelTool::openImgSlot()
{
	clearAll();

	QString filePath = QFileDialog::getOpenFileName(this, tr("Open File"),NULL,
                                                    tr("Images(*.png *.jpg *.jpeg *.bmp)"));
	if(filePath.size()==0)
		return false;

	showImage(filePath);

	return true;
}

bool LabelTool::openDirSlot()
{
	clearAll();

	QString dir_path = QFileDialog::getExistingDirectory (this, tr("Open Directory"));

	if(dir_path.size()==0)
		return false;

	QDir dir(dir_path);
    if(!dir.exists())
    {
       return false;
    }

	QStringList file_list;
    file_list<<QString("*.jpeg")<<QString("*.jpg")<<QString("*.png")<<QString("*.tiff")<<QString("*.gif")<<QString("*.bmp");
    dir.setFilter(QDir::Files );//�������͹�������ֻΪ�ļ���ʽ | QDir::NoSymLinks
    dir.setNameFilters(file_list); //�����ļ����ƹ�������ֻΪfilters��ʽ����׺Ϊ.jpeg��ͼƬ��ʽ��

    int dir_count =dir.count();
    if(dir_count <=0)
    {
       return false;
    }
    
    QChar separator =QChar('/');
    if(!dir_path.contains(separator))
    {
       separator = QChar('\\');
    }

	current_index = 0;//��ǰͼ���index
    
	
	

	for(uint i=0; i<dir_count;i++)
    {
       QString file_name = dir[i]; //�ļ�����
       QString file_path = dir_path + separator +file_name;   //�ļ�ȫ·��
       
	   vector<std::string> split_name = mysplit(file_name.toStdString(),".");
	   string only_file_name = split_name[0];

	   QString label_path = dir_path+separator+ QString::fromStdString(only_file_name)+".txt";
	   string  str_label = label_path.toLocal8Bit().data();
	   fstream f1;
	   f1.open(str_label);
	   if(!f1)
		files.push_back(file_path);
	   f1.close();
    }

	if(files.size()==0){
		QMessageBox box ;
		QString message= QString::fromLocal8Bit("��ǰĿ¼��û�пɱ��ͼƬ��");
		box.about(this,"Failed",message);
		return false;
	}
		
	showImage(files[0]);

	ui.label_dirPath->setText(dir_path);
	ui.label_imgNum->setText(QString::number(dir_count));
	labeled_image = dir_count - files.size();   
	ui.label_labelNum->setText(QString::number(labeled_image));
	ui.label_leftImgNum->setText(QString::number(files.size()));
	return true;
}

void LabelTool::labelSlot()
{

}

//���ñ��
void LabelTool::clearLabelSlot()
{
	ui.label->points.clear();
	ui.label->update();
	
	ui.lineEdit_x1->setText("");
	ui.lineEdit_y1->setText("");
	ui.lineEdit_x2->setText("");
	ui.lineEdit_y2->setText("");
	ui.lineEdit_x3->setText("");
	ui.lineEdit_y3->setText("");
	ui.lineEdit_x4->setText("");
	ui.lineEdit_y4->setText("");

	ui.lineEdit_numbers->setText("");

}

void LabelTool::showLabel()
{
	int test_width = ui.label->width();//wrong size
	
	int width = src.cols;//ԭͼ��
	int height = src.rows;//ԭͼ��

	vector<QPoint*> points = myLabel->points;

	for(int i=0;i<points.size();i++)
	{
		QPoint* point  = points[i];
		int x = (int)(point->x()/rate);
		int y = (int)(point->y()/rate);

		vector<int> p;
		p.push_back(x);
		p.push_back(y);

		labels.push_back(p);
	}

	if(points.size()>0)
	{
		ui.lineEdit_x1->setText(QString::number(labels[0][0]));
		ui.lineEdit_y1->setText(QString::number(labels[0][1]));
	}
	if(points.size()>1){
		ui.lineEdit_x2->setText(QString::number(labels[1][0]));
		ui.lineEdit_y2->setText(QString::number(labels[1][1]));
	}
	if(points.size()>2)
	{
		ui.lineEdit_x3->setText(QString::number(labels[2][0]));
		ui.lineEdit_y3->setText(QString::number(labels[2][1]));
	}
	if(points.size()>3){
		ui.lineEdit_x4->setText(QString::number(labels[3][0]));
	    ui.lineEdit_y4->setText(QString::number(labels[3][1]));
	}
	
}

void LabelTool::showLabel(QString label_path)
{
	ifstream fin(label_path.toLocal8Bit().data());  
    string line;  
    if( fin >> line ) 
    {    
		vector<string> truth = mysplit(line,",");

		vector<int> p1;
		p1.push_back(stoi(truth[0]));
		p1.push_back(stoi(truth[1]));
		labels.push_back(p1);

		vector<int> p2;
		p2.push_back(stoi(truth[2]));
		p2.push_back(stoi(truth[3]));
		labels.push_back(p2);

		vector<int> p3;
		p3.push_back(stoi(truth[4]));
		p3.push_back(stoi(truth[5]));
		labels.push_back(p3);

		vector<int> p4;
		p4.push_back(stoi(truth[6]));
		p4.push_back(stoi(truth[7]));
		labels.push_back(p4);

		numbers =  QString::fromStdString(truth[8]);

		changeLabelsToPoints();

		
		showLabel();
		ui.lineEdit_numbers->setText(numbers);
    }
	fin.close();

	ui.label->update();
}

std::string& trim(std::string &s) 
{
    if (s.empty()) 
     {
         return s;
     }
 
     s.erase(0,s.find_first_not_of(" "));
     s.erase(s.find_last_not_of(" ") + 1);
     return s;
}

void LabelTool::saveLabelSlot()
{
	labels.clear();
	//myLabel->points.clear();

	if(src.empty())
		return;

	showLabel();
	
	numbers = ui.lineEdit_numbers->text();

	if(numbers.size()==0)
	{
		QMessageBox box ;
		QString message= QString::fromLocal8Bit("�����������");
		box.about(this,"Failed",message);
			return;
	}

	string file_name_str = fileName.toLocal8Bit().data();

	const char *str=file_name_str.c_str();


	const char *path = fileName.toStdString().c_str();
	char drive[_MAX_DRIVE];
    char dir[_MAX_DIR];
    char fname[_MAX_FNAME];
    char ext[_MAX_EXT];

    _splitpath( str, drive, dir, fname, ext );

	char* txtPath =(char*)malloc(500);
	strcpy(txtPath,drive);
	strcat(txtPath,dir);
	strcat(txtPath,fname);
	strcat(txtPath,".txt");

	QString txtPathQ;
	txtPathQ.sprintf("%s",txtPath);

	fstream f1;
	f1.open(txtPath);

	if(f1)
    {
		f1.close();
        if(remove(txtPath)==0)  
		{  
			cout<<"ɾ���ɹ�"<<endl;       
		}  
		else  
		{  
			cout<<"ɾ��ʧ��"<<endl;       
		}  
    }

	//f.open(txtPath);
   
	ofstream f(txtPath);  
	if(!f)
	{
		QMessageBox box ;
		QString m1= QString::fromLocal8Bit("���ļ�");
		QString m2= QString::fromLocal8Bit("ʧ�ܣ�");

		QString message= m1+txtPathQ+m2;

		box.about(this,"Failed",message);
			return;
	}

	QString label_str("");

	//char* label_str = (char*)malloc(100);
	for(int i=0;i<labels.size();i++)
	{
		label_str = label_str+QString::number(labels[i][0]);
		label_str = label_str+",";
		label_str = label_str+QString::number(labels[i][1]);
		label_str = label_str+",";

	}

	label_str += numbers;
	string str_my = label_str.toStdString();
	str_my=trim(str_my);

	const char *c_str = str_my.c_str();

	//QByteArray ba_num = label_str.toLatin1();
	//const char *c_str = ba_num.data(); 
	
	f<<c_str<<endl;
    f.close(); //�ر��ļ�

	//�����ͼ�����ļ����У���ɾ��
	vector<QString>::iterator it = std::find(files.begin(),files.end(),fileName);
	if(it!=files.end())
	{
		files.erase(it);
	}

	labeled_image++;
	ui.label_labelNum->setText(QString::number(labeled_image));
	ui.label_leftImgNum->setText(QString::number(files.size()));
	QMessageBox::information(NULL, QString("Information"),  QString::fromLocal8Bit("����ɹ���"));

	this->ui.label->setFocus();
}

bool  LabelTool::getNextImageSlot()
{
	if(files.size()==0)
	{
		QString message= QString::fromLocal8Bit("û����һ��ͼ��");

		QMessageBox box;
		box.about(this,"warning",message);

		return false;
	}

	QString file = files[0];

	showImage(file);
	return true;
}

Mat Rotate(Mat image,  int angle)
{
	cv::Point2f center = cv::Point2f(image.cols / 2, image.rows / 2);  // ��ת����
	double scale = 1; // ���ų߶�

	cv::Mat rotateMat; 
	 rotateMat = cv::getRotationMatrix2D(center, angle, scale);

	cv::Mat rotateImg;
	cv::warpAffine(image, rotateImg, rotateMat, image.size());
	return rotateImg;
}

void LabelTool::rotateImageSlot()
{
	cv::Mat dst;

	if(src.empty())
		return ;

    double rot_angle = 90.0;
	cv::cvtColor(src, src, CV_BGR2RGB);

    dst = Rotate(src, rot_angle);

	string save_name = fileName.toLocal8Bit().data();

	cv::imwrite(save_name,dst);

	showImage(fileName);
	
}

//�ַ����ָ��
std::vector<std::string> mysplit(std::string str,std::string pattern)
{
    std::string::size_type pos;
    std::vector<std::string> result;
    str+=pattern;//��չ�ַ����Է������
    int size=str.size();

    for(int i=0; i<size; i++)
    {
        pos=str.find(pattern,i);
        if(pos<size)
        {
            std::string s=str.substr(i,pos-i);
            result.push_back(s);
            i=pos+pattern.size()-1;
        }
    }
    return result;
}

void LabelTool::changeLabelsToPoints()
{
	myLabel->points.clear();
	for(int i=0;i<labels.size();i++)
	{
		vector<int> p = labels[i];
		QPoint* qp = new QPoint(p[0]*rate,p[1]*rate);
		myLabel->points.push_back(qp);
	}
}

void LabelTool::openLabelSlot()
{
	//clearAll();
	QString filePath = QFileDialog::getOpenFileName(this, tr("Open label File"),NULL,tr("label(*.txt)"));
	if(filePath.size()==0)
		return;

	showLabel(filePath);
}

//�Ŵ�
void LabelTool::imageZoomInSlot()
{
	if(src.empty())
		return ;

	pyrUp(src,src,Size(src.cols*2,src.rows*2));
	QImage img = QImage((const unsigned char*)(src.data), src.cols, src.rows, QImage::Format_RGB888);
	myLabel->setPixmap(QPixmap::fromImage(img));
}

void LabelTool::imageZoomOutSlot()
{
	if(src.empty())
		return ;

	pyrDown(src,src,Size(src.cols/2,src.rows/2));
	QImage img = QImage((const unsigned char*)(src.data), src.cols, src.rows, QImage::Format_RGB888);
	myLabel->setPixmap(QPixmap::fromImage(img));
}

void LabelTool::deleteImageSlot()
{
	QString title = QString::fromLocal8Bit("ɾ��ͼƬ");
	QMessageBox::StandardButton rb = QMessageBox::question(NULL, title, QString::fromLocal8Bit("ȷ��Ҫɾ����ǰͼƬ?"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes); 
	if(rb == QMessageBox::Yes) 
	{ 
		QFile f;
		f.remove(fileName.toLocal8Bit().data());

		//vector��ɾ����ǰͼƬ
		vector<QString>::iterator it = std::find(files.begin(),files.end(),fileName);
		files.erase(it);

		//��ʾ��һ��ͼƬ
		bool status = getNextImageSlot();
		if(!status)
		{
			clearAll();
			ui.label->clear();
			fileName="";
			src.release();
		}
	}
}

//�鿴�Ѿ���ע������
bool LabelTool::openLabelDirSlot()
{
	clearAll();

	QString dir_path = QFileDialog::getExistingDirectory (this, tr("Open Directory"));

	if(dir_path.size()==0)
		return false;

	QDir dir(dir_path);
    if(!dir.exists())
    {
       return false;
    }

	QStringList file_list;
    file_list<<QString("*.jpeg")<<QString("*.jpg")<<QString("*.png")<<QString("*.tiff")<<QString("*.gif")<<QString("*.bmp");
    
	dir.setFilter(QDir::Files );//�������͹�������ֻΪ�ļ���ʽ | QDir::NoSymLinks
    dir.setNameFilters(file_list); //�����ļ����ƹ�������ֻΪfilters��ʽ����׺Ϊ.jpeg��ͼƬ��ʽ��

    int dir_count =dir.count();
    if(dir_count <=0)
    {
		QMessageBox box ;
		QString message= QString::fromLocal8Bit("��ǰĿ¼��û��ͼƬ��");
		box.about(this,"Failed",message);
		return false;
    }
    
    QChar separator =QChar('/');
    if(!dir_path.contains(separator))
    {
       separator = QChar('\\');
    }

	current_index = 0;//��ǰͼ���index
    
	for(uint i=0; i<dir_count;i++)
    {
       QString file_name = dir[i]; //�ļ�����
       QString file_path = dir_path + separator +file_name;   //ͼƬ�ļ�ȫ·��
       
	   vector<std::string> split_name = mysplit(file_name.toStdString(),".");
	   string only_file_name = split_name[0];

	   QString label_path = dir_path+separator+ QString::fromStdString(only_file_name)+".txt";//����ļ�ȫ·��
	   string  str_label = label_path.toLocal8Bit().data();
	   fstream f1;
	   f1.open(str_label);
	   if(f1)
	   {
		   labeld_files[file_path] = label_path;
	   }
	   f1.close();
    }

	if(labeld_files.size()==0){
		QMessageBox box ;
		QString message= QString::fromLocal8Bit("��ǰĿ¼��û���ѱ�ǵ�ͼƬ��");
		box.about(this,"Failed",message);
		return false;
	}
	
	label_files_pointer=labeld_files.begin();

	showImage(label_files_pointer->first);
	showLabel(label_files_pointer->second);

	ui.label_dirPath->setText(dir_path);
	ui.label_imgNum->setText(QString::number(dir_count));
	labeled_image = labeld_files.size();   
	ui.label_labelNum->setText(QString::number(labeled_image));
	int left = dir_count-labeled_image;
	ui.label_leftImgNum->setText(QString::number(left));
	return true;
}

void LabelTool::getNextLabeledImageSlot()
{
	if(labeld_files.size()!=0 && label_files_pointer!=labeld_files.end()){
		label_files_pointer++;
		
		if(label_files_pointer!=labeld_files.end()){
			showImage(label_files_pointer->first);
			showLabel(label_files_pointer->second);
		}
		
	}
		
}