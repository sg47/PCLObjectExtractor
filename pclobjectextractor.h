#ifndef PCLOBJECTEXTRACTOR_H
#define PCLOBJECTEXTRACTOR_H

#include <QMainWindow>
#include <iostream>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <vtkRenderWindow.h>
#include <vtkEventQtSlotConnect.h>
#include <pcl/filters/filter.h>
#include <pcl/io/pcd_io.h>
#include <algorithm>
#include <QFileDialog>
#include <QMessageBox>
#include <QIcon>

namespace Ui
{
    class PCLObjectExtractor;
}

class PCLObjectExtractor : public QMainWindow
{
    Q_OBJECT

public:
    explicit PCLObjectExtractor(QWidget *parent = 0);
    ~PCLObjectExtractor();

signals:
    void PointHighlightSignal(int pointIndex);
    void AreaHighlightSignal(std::vector<int> pointIndecies);

private slots:
    void PointHighlightSlot(int pointIndex);
    void AreaHighlightSlot(std::vector<int> pointIndecies);
    void on_helpAction_triggered();
    void on_loadButton_clicked();
    void on_saveButton_clicked();

private:
    static void PointSelectionCallback(
                            const pcl::visualization::PointPickingEvent& event,
                            void* args);
    static void AreaSelectionCallback(
                            const pcl::visualization::AreaPickingEvent& event,
                            void* args);
    Ui::PCLObjectExtractor *mUi;
    boost::shared_ptr<pcl::visualization::PCLVisualizer> mpPointCloudViewer;
    boost::shared_ptr<pcl::visualization::PCLVisualizer> mpSelectionViewer;
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr mpLoadedPointCloud;
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr mpSelectedPointCloud;
    QFileDialog mFileDialog;
    int mNumPointsSelected;
};

#endif // PCLOBJECTEXTRACTOR_H
