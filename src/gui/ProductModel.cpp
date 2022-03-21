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
    {
        return 0;
    }

    constexpr auto hardocedNumOfElements = 10u;
    return hardocedNumOfElements;
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

    // Return placeholder data
    if(role == IdRole)
    {
        return QVariant(index.row());
    }
    if(role == NameRole)
    {
        return QVariant(QStringLiteral("Test name"));
    }
    if(role == DescriptionRole)
    {
        return QVariant(QStringLiteral("Example description of product"));
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
