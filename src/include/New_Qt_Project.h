#pragma once

#include <QWidget>
#include "ui_New_Qt_Project.h"

class New_Qt_Project : public QWidget
{
	Q_OBJECT

public:
	New_Qt_Project(QWidget *parent = nullptr);
	~New_Qt_Project();

private:
	Ui::New_Qt_ProjectClass ui;
};

