// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import ".//"

Rectangle {
    id: podcastFolder
    height: 48
    width: 480

    property int newCasts: 0
    property int downCasts: 0
    property string icon: "qrc:/qtquickplugin/images/template_image.png"
    property string description: "no description avaible"

    Item {
        id: stat
        x: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        width: height

        function positiveIntToString(a){
            var result = "";
            if (a>0)
                result = a;
            return result;
        }

        Text{
            id: _downCasts;
            width: 32
            height: 16
            anchors.top: parent.top
            anchors.topMargin: 0
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignRight
            text: positiveIntToString(downCasts)
            anchors.right: parent.right
            anchors.rightMargin: 0
        }
        Text{
            id: _newCasts;
            width: 32
            height: 16
            anchors.top: downCasts.bottom
            anchors.topMargin: 0
            text: positiveIntToString(newCasts)
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
        }
    }

    Image {
        id: _icon
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.left: stat.right
        anchors.leftMargin: 8
        source: icon
        width: height
    }

    Text {
        id: _description
        text: description
        verticalAlignment: Text.AlignVCenter
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.left: _icon.right
        anchors.leftMargin: 8
        font.pixelSize: 12
    }
}
