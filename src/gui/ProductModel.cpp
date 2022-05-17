#include "ProductModel.hpp"

ProductModel::ProductModel(QObject *parent)
    : QAbstractListModel(parent)
{
    // TODO: Get products from core through getAllProducts [currently not available]
    products = bakcyl::core::Core().getAllProducts();
}

int ProductModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
    {
        return 0;
    }

    return products.size();
}

QVariant ProductModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if(role == IdRole)
    {
        return QVariant(QString::number(products[index.row()].getId()));
    }
    if(role == NameRole)
    {
        return QVariant(QString::fromStdString(products[index.row()].getName()));
    }
    if(role == DescriptionRole)
    {
        return QVariant(QString::fromStdString(products[index.row()].getDescription()));
    }

    return QVariant();
}

QHash<int, QByteArray> ProductModel::roleNames() const
{
    QHash<int, QByteArray> names;

    names[IdRole] = "ID";
    names[NameRole] = "Name";
    names[DescriptionRole] = "Description";

    return names;
}
