#pragma once

#include <QObject>

class SearchboxController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString searchboxText READ getSearchboxText WRITE setSearchboxText NOTIFY searchboxTextChanged)
public:
    explicit SearchboxController(QObject *parent = nullptr);
    QString getSearchboxText();

signals:
    void searchboxTextChanged();

public slots:
    void setSearchboxText( QString );
    void seachButtonPressed();

private:
    QString m_searchboxText;
};
