#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QFileDialog>
#include <QDir>

#include <stdio.h>
#include <iostream>

#include "myfilter.h"
#include "ui_mainwindow.h"

#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow , public Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    // Setup types
    typedef itk::Image<unsigned char, 3>        ImageType;
    typedef itk::MyFilter<ImageType>            FilterType;
    typedef itk::ImageFileReader< ImageType >   ReaderType;
    typedef itk::ImageFileWriter< ImageType >   WriterType;


private slots:
    /** Action functions when pushbutton are clicked */
    void on_inputBrowse_clicked();
    void on_outputBrowse_clicked();
    void on_submit_clicked();
    void on_quit_clicked();

private:
    ReaderType::Pointer reader;
    FilterType::Pointer filter;
    WriterType::Pointer writer;


};

#endif // MAINWINDOW_H
