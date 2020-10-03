#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>

class QAction;
class QLabel;
class Plotter;
class PlotSettings;
class Signal;
class QSlider;
class QGridLayout;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();
	QGridLayout *qlayout;

protected:
    //void changeEvent(QEvent *e);

private slots:
    void open();
    void about();
    void updateStatusBar();
    void findWaves();
    void filterSignal();
	void set100Hz();

private:
	bool eventFilter(QObject *obj, QEvent *event);
    void createActions();
    void createMenus();
    void createToolbars();
	void createSlider();
	void createStatusBar();
    bool loadFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    QString strippedName(const QString &fullFileName);

    Plotter *plotter;
    Signal *signal;
    QLabel *sampleRateLabelData;
    QLabel *sampleRateLabelText;
    QLabel *sizeLabelData;
    QLabel *sizeLabelText;
    QString curFile;

    QMenu *fileMenu;
    QMenu *helpMenu;
    QMenu *operationsMenu;
    QToolBar *fileToolBar;

	QSlider *qslider;
	

    QAction *openAction;
    QAction *exitAction;
    //QAction *showGridAction;             //TODO
    QAction *aboutAction;
    QAction *aboutQtAction;
    QAction *findWavesAction;
    QAction *filterSignalAction;
	QAction *set100HzAction;

    QProgressBar *progressBar;

};

#endif // MAINWINDOW_H
