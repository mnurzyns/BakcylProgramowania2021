#pragma once

#include <QAbstractListModel>

class ProductModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ProductModel(QObject *parent = nullptr);

    enum {
        IdRole,
        NameRole,
        DescriptionRole
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    bool hasChildren(const QModelIndex &parent = QModelIndex()) const override;

    bool canFetchMore(const QModelIndex &parent) const override;
    void fetchMore(const QModelIndex &parent) override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    virtual QHash<int, QByteArray> roleNames() const override;
};
