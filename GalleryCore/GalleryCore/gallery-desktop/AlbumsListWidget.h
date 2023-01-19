#ifndef ALBUMSLISTWIDGET_H
#define ALBUMSLISTWIDGET_H

#include <QWidget>
#include <QItemSelectionModel>

namespace Ui {
    class AlbumsListWidget;
}

class AlbumModel;

class AlbumsListWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AlbumsListWidget(QWidget *parent = nullptr);
    ~AlbumsListWidget();

    void setModel(AlbumModel* model);
    void setSelectionModel(QItemSelectionModel* selectionModel);

private slots:
    void createAlbum();

private:
    Ui::AlbumsListWidget* ui;
    AlbumModel* mAlbumModel;
};

#endif // ALBUMSLISTWIDGET_H
