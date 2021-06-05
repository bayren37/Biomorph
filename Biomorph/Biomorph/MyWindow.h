#pragma once

#include <QtWidgets/QMainWindow>
#include <QButtonGroup>

namespace ui {

	class MyWindow : public QMainWindow
	{
		Q_OBJECT

	public:
		MyWindow(QWidget* parent = Q_NULLPTR);

	};

	class CentralWidget : public QWidget
	{
	public:
		CentralWidget(QWidget* parent = Q_NULLPTR);
		~CentralWidget() = default;

	private:
		void buttonClicked(int id);

	private:
		QButtonGroup* BiomorphWidgets_ = {};
	};
};
