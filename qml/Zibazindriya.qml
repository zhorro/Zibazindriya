// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    width: 360
    height: 360

    ListView {
        anchors.fill: parent
        model: feedsModel
        delegate: RssItem {
            width: parent.width;
            newItems: updatedItems;
            dowItems: dowloadedItems;
            description: descr;
        }
    }
}
