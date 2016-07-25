#include "mainwindow.h"

#include <QDir>
#include <QMessageBox>
#include <QFileInfo>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setupUi(this);

    this->setWindowTitle("Gaussian filter");

    this->inputPath->setPlaceholderText("Enter your inputh path");
    this->outputPath->setPlaceholderText("Enter your outputh path");

    reader = ReaderType::New();
    filter=FilterType::New();
    writer = WriterType::New();
}


MainWindow::~MainWindow()
{

}



void MainWindow::on_inputBrowse_clicked()
{
    QString inputFileWay = QFileDialog::getOpenFileName(this, "Input file path", "../", "MHA files (*.mha) ;; MRML files (*.mrml)");

    this->inputPath->setText(inputFileWay);

}

void MainWindow::on_outputBrowse_clicked()
{
    QString outputFileWay = QFileDialog::getOpenFileName(this, "Output file path", "../");

    this->outputPath->setText(outputFileWay);
}

void MainWindow::on_submit_clicked()
{

    QString qinputPath = QString::fromStdString( this->inputPath->text().toStdString() );
    QString qoutputPath = QString::fromStdString( this->outputPath->text().toStdString() );

    // Verify the existence of the input file
    if ( !QDir(qinputPath).exists() )
    {
        // Verify the existence of the output directory
        if ( QDir( QFileInfo( qoutputPath ).path() ).exists() )
        {
            // If wrong output file extension (different as input file)
            if ( QFileInfo( qinputPath ).suffix() == QFileInfo( qoutputPath ).suffix() )
            {

                reader->SetFileName( this->inputPath->text().toStdString() );
                reader->Update();

                filter->SetInput(reader->GetOutput());
                filter->Update();

                writer->SetFileName( this->outputPath->text().toStdString() );
                writer->SetInput(filter->GetOutput());
                writer->Update();
            }
            else
            {
                QMessageBox::information( this, tr("Error"),tr("Wrong output file type") );
            }
        }
        else
        {
            QMessageBox::information( this, tr("Error"),tr("Wrong output directory") );
        }
    }
    else
    {
        QMessageBox::information( this, tr("Error"),tr("Wrong input path") );
    }

}

void MainWindow::on_quit_clicked()
{
    this->close();
}
