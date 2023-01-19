#include "GalleryWidget.h"
#include "ui_GalleryWidget.h"

#include <QItemSelectionModel>

GalleryWidget::GalleryWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GalleryWidget)
{
    ui->setupUi(this);
    ui->albumsListWidget->setMaximumWidth(250);
    connect(ui->albumWidget, &AlbumWidget::pictureActivated, this, &GalleryWidget::pictureActivated);
}

GalleryWidget::~GalleryWidget()
{
    delete ui;
}

void GalleryWidget::setAlbumModel(AlbumModel* albumModel)
{
    ui->albumsListWidget->setModel(albumModel);
    ui->albumWidget->setAlbumModel(albumModel);
}

void GalleryWidget::setAlbumSelectionModel(QItemSelectionModel* albumSelectionModel)
{
    ui->albumsListWidget->setSelectionModel(albumSelectionModel);
    ui->albumWidget->setAlbumSelectionModel(albumSelectionModel);
}

void GalleryWidget::setPictureModel(ThumbnailProxyModel* pictureModel)
{
    ui->albumWidget->setPictureModel(pictureModel);
}

void GalleryWidget::setPictureSelectionModel(QItemSelectionModel* pictureSelectionModel)
{
    ui->albumWidget->setPictureSelectionModel(pictureSelectionModel);
}
