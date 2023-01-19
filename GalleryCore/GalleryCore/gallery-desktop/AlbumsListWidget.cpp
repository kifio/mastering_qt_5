#include "AlbumsListWidget.h"
#include "ui_AlbumsListWidget.h"
#include "AlbumModel.h"

#include <QInputDialog>

AlbumsListWidget::AlbumsListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AlbumsListWidget),
    mAlbumModel(nullptr)
{
    ui->setupUi(this);
    connect(ui->createAlbumButton, &QPushButton::clicked,
            this, &AlbumsListWidget::createAlbum);
}

AlbumsListWidget::~AlbumsListWidget()
{
    delete ui;
}

void AlbumsListWidget::setModel(AlbumModel* model) {
    mAlbumModel = model;
    ui->albumsList->setModel(mAlbumModel);
}

void AlbumsListWidget::setSelectionModel(QItemSelectionModel* selectionModel) {
    ui->albumsList->setSelectionModel(selectionModel);
}

void AlbumsListWidget::createAlbum()
{
    if(!mAlbumModel) {
        return;
    }
    bool ok;
    QString albumName = QInputDialog::getText(this,
                                              "Create a new Album",
                                              "Choose an name",
                                              QLineEdit::Normal,
                                              "New album",
                                              &ok);
    if (ok && !albumName.isEmpty()) {
        Album album(albumName);
        QModelIndex createdIndex = mAlbumModel->addAlbum(album);
        ui->albumsList->setCurrentIndex(createdIndex);
    } }
