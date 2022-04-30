#include "ProductInstanceModel.hpp"

ProductInstanceModel::ProductInstanceModel(QObject *parent)
    : QAbstractListModel{parent}
{
    // TODO: Get productInstances from core throug getProductInstanceByProductId [not available now]
}

int ProductInstanceModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
    {
        return 0;
    }

    return productInstances.size();
}

QVariant ProductInstanceModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    if(role == IdRole)
    {
        return QVariant(productInstances[index.row()].getId());
    }
    if(role == LocationRole)
    {
        return QVariant(QString::fromStdString(productInstances[index.row()].getLocationId()));
    }

    return QVariant();
}

QHash<int, QByteArray> ProductInstanceModel::roleNames() const
{
    QHash<int, QByteArray> names;

    names[IdRole] = "ID";
    names[LocationRole] = "Location";

    return names;
}
