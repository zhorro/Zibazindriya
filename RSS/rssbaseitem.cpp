#include <stdlib.h>
#include "rssbaseitem.h"

rssBaseItem::rssBaseItem(QObject *parent) :
    QObject(parent)
  ,m_dow(0)
  ,m_new(0)
{
    rescan();
}

int rssBaseItem::getDow (void)
{
    return m_dow;
}

int rssBaseItem::getNew (void)
{
    return m_new;
}

void rssBaseItem::rescan(void)
{
    updateNew(rand() % 20);
    updateDow(rand() % 20);
}

void rssBaseItem::updateNew(int newVal)
{
    if (getNew () == newVal)
        return;

    m_new = newVal;
    emit itemChanged();
}

void rssBaseItem::updateDow(int newVal)
{
    if (getDow() == newVal)
        return;

    m_dow = newVal;
    emit itemChanged();
}
