#include "ProductInstanceModel.hpp"

ProductInstanceModel::ProductInstanceModel(QObject *parent)
    : QAbstractListModel{parent}
{

}

int ProductInstanceModel::rowCount(const QModelIndex &parent) const
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

QVariant ProductInstanceModel::data(const QModelIndex &index, int role) const
{
    return QVariant();
}

QHash<int, QByteArray> ProductInstanceModel::roleNames() const
{
    QHash<int, QByteArray> names;

    return names;
}
