#ifndef RSSBASEITEM_H
#define RSSBASEITEM_H

#include <QObject>

class rssBaseItem : public QObject
{
    Q_OBJECT

    Q_PROPERTY (int dowItems READ getDow WRITE updateDow NOTIFY itemChanged)
    Q_PROPERTY (int newItems READ getNew WRITE updateNew NOTIFY itemChanged)

private:
    int m_dow, m_new;
public:
    explicit rssBaseItem(QObject *parent = 0);

    int getDow (void);
    int getNew (void);
    
signals:
    void itemChanged (void);

public slots:
    void updateNew(int);
    void updateDow(int);
    void rescan(void);
};

#endif // RSSBASEITEM_H
