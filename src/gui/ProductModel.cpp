#include "ProductModel.hpp"

ProductModel::ProductModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int ProductModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
}

bool ProductModel::hasChildren(const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

bool ProductModel::canFetchMore(const QModelIndex &parent) const
{
    // FIXME: Implement me!
    return false;
}

void ProductModel::fetchMore(const QModelIndex &parent)
{
    // FIXME: Implement me!
}

QVariant ProductModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
