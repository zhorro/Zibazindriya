// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Item {
    id: rssItem
    property int newItems: 0
    property int dowItems: 0

    width: 360
    height: 32

    Image {
        id: itemImage
        anchors {
            top: parent.top
            bottom: parent.bottom
            left: itemsAmounts.right

            topMargin: 0
            bottomMargin: 0
            leftMargin: 16
        }

        width: height
        source: "../Images/RSS.png"
    }

    function positiveIntToString(a){
        var result = "";
        if (a>0)
            result = a;
        return result;
    }

    Text {
        id: descLabel
        text: qsTr("Unnamed podcast")
        verticalAlignment: Text.AlignVCenter

        anchors{
            bottom: parent.bottom
            top: parent.top
            right: parent.right
            left: itemImage.right

            bottomMargin: 0
            topMargin: 0
            rightMargin: 0
            leftMargin: 16
        }
    }

    Rectangle {
        id: itemsAmounts
        width: height
        radius: 0
        visible: true

        anchors {
            left: parent.left
            bottom: parent.bottom
            top: parent.top

            leftMargin: 0
            bottomMargin: 0
            topMargin: 0
        }

        Text {
            id: newItemsLabel
            text: positiveIntToString(parent.parent.newItems)

            anchors{
                right: parent.right
                left: parent.left
                top: parent.top

                rightMargin: 0
                leftMargin: 0
                topMargin: 0
            }
            horizontalAlignment: Text.AlignRight
            verticalAlignment: Text.AlignVCenter

            height: width/2;
        }

        Text {
            id: dowItemsLabel
            text: positiveIntToString(parent.parent.dowItems)

            anchors {
                right: parent.right
                left: parent.left
                bottom: parent.bottom

                rightMargin: 0
                leftMargin: 0
                bottomMargin: 0
            }

            horizontalAlignment: Text.AlignRight
            verticalAlignment: Text.AlignVCenter

            height: width/2;
        }
    }
}
