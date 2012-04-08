// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Item {
        id: rssItem
        property int newItems;
        property int dowItems;

        Image {
            id: itemImage
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: itemsAmounts.right

            anchors.topMargin: 0
            anchors.bottomMargin: 0
            anchors.leftMargin: 16

            width: height
            source: "../Images/RSS.png"
        }

        Text {
            id: descLabel
            text: qsTr("Unnamed podcast")
            verticalAlignment: Text.AlignVCenter

            anchors.bottom: parent.bottom
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.left: itemImage.right

            anchors.bottomMargin: 0
            anchors.topMargin: 0
            anchors.rightMargin: 0
            anchors.leftMargin: 16
        }

        Rectangle {
            id: itemsAmounts
            width: height
            radius: 0
            visible: true

            anchors.left: parent.left
            anchors.bottom: parent.bottom
            anchors.top: parent.top

            anchors.leftMargin: 0
            anchors.bottomMargin: 0
            anchors.topMargin: 0

            Text {
                id: newItemsLabel

                anchors.right: parent.right
                anchors.left: parent.left
                anchors.top: parent.top

                anchors.rightMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 0

                horizontalAlignment: Text.AlignRight
                verticalAlignment: Text.AlignVCenter

                height: width/2;
            }

            Text {
                id: dowItemsLabel

                anchors.right: parent.right
                anchors.left: parent.left
                anchors.bottom: parent.bottom

                anchors.rightMargin: 0
                anchors.leftMargin: 0
                anchors.bottomMargin: 0

                horizontalAlignment: Text.AlignRight
                verticalAlignment: Text.AlignVCenter

                height: width/2;
            }
        }
}
