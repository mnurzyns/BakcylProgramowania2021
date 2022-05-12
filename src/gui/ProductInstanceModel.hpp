#pragma once

#include <QAbstractListModel>

#include <vector>

#include "core/Core.hpp"
#include "common/productInstance.hpp"

class ProductInstanceModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ProductInstanceModel(QObject *parent = nullptr);

    enum {
        IdRole,
        LocationRole
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

private:
    std::vector<bakcyl::common::ProductInstance> productInstances;

};
