#pragma once

#include <QAbstractListModel>

class ProductInstanceModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ProductInstanceModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    virtual QHash<int, QByteArray> roleNames() const override;
};
